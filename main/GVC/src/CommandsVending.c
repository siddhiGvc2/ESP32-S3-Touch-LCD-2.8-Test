#include "app.h"

#define MAX_PACKETS 10    // maximum number of packets
#define MAX_LEN    150     // maximum length of each packet
static const char *TAG = "VENDING";
int split_uart_packets(char *uartpkt, char packets[MAX_PACKETS][MAX_LEN])
{
    char *start = uartpkt;
    char *end;
    int count = 0;

    while ((end = strchr(start, '#')) != NULL && count < MAX_PACKETS) {
        int len = end - start + 1;   // include '#'

        if (len < MAX_LEN) {
            strncpy(packets[count], start, len);
            packets[count][len] = '\0';  // null terminate
            count++;
        }

        start = end + 1;   // move to next after '#'
    }

    return count;  // return number of packets found
}


void AnalyseVendingCommands (char* InputVia,char* pkt) {
   
    char buf[200];
    char buffer[1400]; 
    char payload[940]; 
    int track_id;
    ESP_LOGI(TAG,"UART PACKET - %s",pkt);
    char packets[MAX_PACKETS][MAX_LEN];
    int total = split_uart_packets(pkt, packets);
    for (int i = 0; i < total; i++) {
        ESP_LOGI(TAG,"Packet[%d] = %s\n", i, packets[i]);
    }
     for (int i = 0 ; i < total ; i++)
    {
    if(strstr(packets[i], "AmountReceived") && strcmp(InputVia, "UART") == 0)
    {
        ESP_LOGI(TAG,"AmountReceived pkt accepeted");
        mqtt_publish_msg(packets[i]);
        // uart_write_string_ln("*SUCCESS#"); // 140525 removed and sent by Server
    }
    else if(strncmp(packets[i],"*VEND,",6)==0 && strcmp(InputVia, "MQTT") == 0)
    {
        uart_write_string_ln(packets[i]);
        gsm_write_string_ln(packets[i]);
        DisplayCashReceived();
        vTaskDelay(3000/portTICK_PERIOD_MS);
        DisplayItemVend();
        vTaskDelay(3000/portTICK_PERIOD_MS);
        dispayQR();
        
    }
     else if (strncmp(packets[i], "*SELL,", 6) == 0) {
        ESP_LOGI("UART", "Received SELL command!");

        // Extract Price, RefId, and extra value (e.g., 0x20)
        char uartPrice[10], spring[10];
        if (sscanf(packets[i], "*SELL,%19[^,],%19[^,#]#", uartPrice, spring) == 2) {
            ESP_LOGI("UART", "Price: %s, RefId: %s", price, refId);
            sprintf(payload,"*SELL-OK,%s,%s#", uartPrice, spring);
            if (UartDebugInfoRequired){
            uart_write_string_ln(payload);
            }
            // Process the SELL command as needed...
            if(IsMobivendApi)
            {
            char formatted_url[376];  // Adjust size if needed
            sprintf(formatted_url, 
             URL_CASHLESSVEND,
             SerialNumber,spring, price, refId);
            strcpy(API,"CashLessVend");
            start_http_get_task(formatted_url);
            }
        } else {
            ESP_LOGW("UART", "Invalid SELL command format!");
        }
    }
    else if (strncmp(packets[i], "*VEND,", 6) == 0) {
        ESP_LOGI("UART", "Received VEND command!");

        // Extract Price, RefId, and extra value (e.g., 0x20)
        char uartPrice[10], spring[10];
        if (sscanf(packets[i], "*VEND,%19[^,],%19[^,#]#", uartPrice, spring) == 2) {
            // ESP_LOGI("UART", "Price: %s, RefId: %s", price, refId);
            sprintf(payload,"*VEND-OK,%s,%s#", uartPrice, spring);
            if (UartDebugInfoRequired){
            uart_write_string_ln(payload);
            }
            // Process the SELL command as needed...
            if(IsMobivendApi)
            {
            char formatted_url[376];  // Adjust size if needed
            sprintf(formatted_url, 
            URL_CASHLESSSALE,
            SerialNumber,refId,price,spring);
            strcpy(API,"CashLessSale");
            start_http_get_task(formatted_url);
            }
        } else {
            ESP_LOGW("UART", "Invalid VEND command format!");
        }
    }

     // added on 070525
    else if (strncmp(packets[i], "*TRXN,", 6) == 0) {
        ESP_LOGI("UART", "Received TRXN command!");
        if (UartDebugInfoRequired)
             uart_write_string_ln("Received TRXN command!");
        // Declare buffers for all 7 fields
      
    
        // Parse 7 fields
        int matched = sscanf(packets[i], "*TRXN,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,#]#", 
                             val1, val2, refId, val4, rawPrice, itemCode);
    
        if (matched == 6) {
            // Convert price from paise to rupees
            int priceInt = atoi(rawPrice);
            int p=priceInt/100;
    
            // Format spring (e.g., A01 → AX01)
            char spring[10];
            if (strlen(itemCode) >= 3) {
                snprintf(spring, sizeof(spring), "%cX%c%c", itemCode[0], itemCode[1], itemCode[2]);
            } else {
                ESP_LOGW("UART", "Invalid itemCode length");
                uart_write_string_ln("Invalid itemCode length");
                return;
            }
            // uart_write_string_ln("*SUCCESS#"); // 140525 removed and sent by Server
            DisplayItemVend();
            ESP_LOGI(TAG,"DISPLAYED ITEME VEND");
            if(MQTT_CONNEECTED && MQTTRequired)
            {
            mqtt_publish_msg(packets[i]);
            }

            // Send acknowledgment over UART
            char payload[204];
            // snprintf(payload, sizeof(payload), "*VEND-OK,%s,%s#", price, spring);
            // uart_write_string_ln(payload);
            if(IsMobivendApi)
            {
                sprintf(price,"%d", p);
            char formatted_url[476];  // Adjust size if needed
            snprintf(formatted_url, sizeof(formatted_url),
            URL_CASHLESSSALE,
            SerialNumber, refId, price , spring);  // price is int here
            strcpy(API,"CashLessSale");
            start_http_get_task(formatted_url);
            }

            vTaskDelay(10000/portTICK_PERIOD_MS);
            DisplayMode=ModeNone;
            dispayQR();
    
        } else {
            ESP_LOGW("UART", "Invalid TRXN format: expected 7 values.");
        }
    }

    // added on 080525
    else if(strncmp(packets[i],"*REFUND,",8)==0)
    {
        // uart_write_string_ln("*SUCCESS#"); // 140525 removed and sent by Server
        mqtt_publish_msg(packets[i]);
    }
     // added on 080525
    else if(strncmp(packets[i],"*SCANQR#",8)==0)
    {
        DisplayMode=ModeNone;
        dispayQR();
    }
     else if(strstr(packets[i], "*SENDID#"))
    {
       char response[6];   // 5 digits + null terminator
        int num = atoi(SerialNumber);   // Convert string to integer

        // Format into 5-digit, zero-padded number
        sprintf(response, "%05d", num);
        gsm_write_string(response);
        ESP_LOGI(TAG,"%s",response);
        MQTTRequired=0;
    }
      else if(strncmp(packets[i],"*REQUEST:",9)==0)
    {
        if (UartDebugInfoRequired)
            uart_write_string_ln("Display dummy QR Code");
        strcpy(QrString,"Waiting For QrCode");
        DisplayMode=ModeNone;
        dispayQR();
        if (UartDebugInfoRequired)
            uart_write_string_ln("Send Request to server");
        mqtt_publish_msg(packets[i]);
    }
    
    else if(strncmp(packets[i],"*TSI#",5)==0)
    {
        DisplayStatusText();
    }
  
     else if(strncmp(packets[i], "*QR:",4) == 0){
            char tempBuf[500];
            sscanf(packets[i], "*QR:%[^#]#",tempBuf);
            strcpy(QrString,tempBuf);
            sprintf(buffer, "*QR-OK,%s#",QrString);
            SendReply(InputVia,buffer);
            SaveString(NVS_QR_STRING,QrString);
            DisplayMode=ModeNone;
            dispayQR();
            if (UartDebugInfoRequired){
             uart_write_string_ln(payload);
            }
        }
        else if(strncmp(packets[i], "*QR?#",5) == 0){
            
            sprintf(buffer, "*QR-OK,%s#",QrString);
            SendReply(InputVia,buffer); 
            gsm_write_string_ln(buffer);
        }
    }
}
