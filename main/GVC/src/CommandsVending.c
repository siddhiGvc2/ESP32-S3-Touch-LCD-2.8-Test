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
    char payload[440]; 
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
        uart_write_string_ln(data);
        gsm_write_string_ln(data);
        DisplayCashReceived();
        vTaskDelay(3000/portTICK_PERIOD_MS);
        DisplayItemVend();
        vTaskDelay(3000/portTICK_PERIOD_MS);
        dispayQR();
        
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
