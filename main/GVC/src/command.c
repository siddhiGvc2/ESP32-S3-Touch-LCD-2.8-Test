#include "defs.h"

static const char *TAG = "COMMAND";





void SendReply(char* InputVia, char* data)
{
   sendData(data);
}




void AnalyseGeneralCommands (char* InputVia,char* pkt) {
    char payload[800];
    int track_id;
     if(strncmp(pkt, "*SN?#", 5) == 0){
        sprintf(payload, "*SN,%s,%s,%s#",SNuserName,SNdateTime,SerialNumber); //actual when in production
        ESP_LOGI(TAG,"%s",payload);
        SendReply(InputVia,payload);
    }
    else if(strncmp(pkt, "*URL?#", 6) == 0){
        sprintf(payload,"*URL,%s,%s,%s#",URLuserName,URLdateTime,FOTA_URL);
        ESP_LOGI(TAG,"%s",payload);
        SendReply(InputVia,payload);
    }
    else if(strncmp(pkt,"*RSSI?#",7)==0)
    {
    sprintf(payload,"*RSSI,%d",RSSI);
    ESP_LOGI(TAG,"%s",payload);
    SendReply(InputVia,payload);
    }
    else if(strncmp(pkt, "*SSID?#", 7) == 0){
        sprintf(payload, "*SSID,%s,%s,%d,%s,%s,%s#",SSuserName,SSdateTime,WiFiNumber,WIFI_SSID_1,WIFI_SSID_2,WIFI_SSID_3); 
        ESP_LOGI(TAG,"%s",payload);
        SendReply(InputVia,payload);
       
    }
     else if(strncmp(pkt, "*FW?#", 5) == 0){
        ESP_LOGI(TAG,"*%s#",FWVersion);
        sprintf(payload, "*FW:%s#",FWVersion);
        SendReply(InputVia,payload);
     }
     else if(strncmp(pkt, "*SIP?#", 6) == 0){
        sprintf(payload,"*SIP,%s,%s,%s,%d#",SIPuserName,SIPdateTime,server_ip_addr,
                                         sp_port );
        SendReply(InputVia,payload);
       
    }
      else if(strncmp(pkt, "*MIP?#", 6) == 0){
        sprintf(payload,"*MIP,%s,%s,%s,%d#",MIPuserName,MIPdateTime,mqtt_uri,MipNumber);
        SendReply(InputVia,payload);
       
    }
    else if (strncmp(pkt, "*ERASE?", 7) == 0){
        sprintf(payload,"*ERASE,%s,%s,%s#",ERASEuserName,ERASEdateTime,ErasedSerialNumber); 
        SendReply(InputVia, payload);
    }
}

void AnalyseCommands (char* InputVia,char* pkt) {
    AnalyseGeneralCommands(InputVia,pkt);
    AnalyseKwikpayCommands(InputVia,pkt);
    AnalyseAACCommands(InputVia,pkt);
    AnalyseVendingCommands(InputVia,pkt);
    AnalyseWAMCommands(InputVia,pkt);
}



