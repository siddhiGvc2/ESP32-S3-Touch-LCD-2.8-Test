#include "app.h"


void UnpackGameMode (void)
{
    LocalGameEnable = 1;
    GameNegativeMarking = 0;
}



void AnalyseWAMCommands (char* InputVia,char* rx_buffer) {
    char payload[200];
    int track_id;
    if(strncmp(rx_buffer,"*LTime:",7)==0)
    {

        sscanf(rx_buffer, "*LTime:%d#",&LightTime);
        SaveInteger(NVS_LIGHT_TIME,LightTime);
        sprintf(payload, "*LTime-OK,%d#",LightTime);
        BlinlLEDTime = 10 * LightTime;
        SendReply(InputVia,payload); 
    }
       else if(strncmp(rx_buffer,"*PTime:",7)==0)
    {
        sscanf(rx_buffer, "*PTime:%d#",&PlayTime);
        SaveInteger(NVS_PLAY_TIME,PlayTime);
        sprintf(payload, "*PTime-OK,%d#",PlayTime);
        SendReply(InputVia,payload); 
    }
       else if(strncmp(rx_buffer,"*GTime:",7)==0)
    {
        sscanf(rx_buffer, "*GTime:%d#",&GapBeforeNextLight);
        SaveInteger(NVS_GAP_TIME,GapBeforeNextLight);
        sprintf(payload, "*GTime-OK,%d#",GapBeforeNextLight);
        SendReply(InputVia,payload); 
    }
         else if(strncmp(rx_buffer,"*NL:",4)==0)
    {
        int lights;
        sscanf(rx_buffer, "*NL:%d#",&lights);
        if(lights<=MAX_NUMBER_OF_LIGHTS)
        {
            NumberOfLights=lights;
            SaveInteger(NVS_TOTAL_LIGHTS,NumberOfLights);
            sprintf(payload, "*NL-OK,%d#",NumberOfLights);
        }
        else{
            sprintf(payload, "*NL-ERR,MAX#");
        }

        SendReply(InputVia,payload); 
    }
     else if(strncmp(rx_buffer,"*GTime?#",8)==0)
    {
       
        sprintf(payload, "*GTime,%d#",GapBeforeNextLight );
        SendReply(InputVia,payload); 
    }
      else if(strncmp(rx_buffer,"*PTime?#",8)==0)
    {
       
        sprintf(payload, "*PTime,%d#",PlayTime );
        SendReply(InputVia,payload); 
    }
      else if(strncmp(rx_buffer,"*LTime?#",8)==0)
    {
       
        sprintf(payload, "*LTime,%d#",LightTime );
        SendReply(InputVia,payload); 
    }
      else if(strncmp(rx_buffer,"*NL?#",5)==0)
    {

        sprintf(payload, "*NL,%d#", NumberOfLights);
        SendReply(InputVia, payload); 
    }
    else if(strncmp(rx_buffer,"*LedErrCount?#",14)==0)
    {
         sprintf(payload, "*LedErrorCount,%d,%d,%d#",OKSwitchPressedCount,WrongSwitchPressedCount,NoSwitchPressedCount);
        SendReply(InputVia,payload); 
    }
    else if(strncmp(rx_buffer,"*GameMode:",10)==0)
    {
        sscanf(rx_buffer, "*GameMode:%d#",&GameMode);
        SaveInteger(NVS_GAME_MODE,GameMode);
        sprintf(payload, "*GameMode,%d#",GameMode);
        SendReply(InputVia,payload); 
        UnpackGameMode();
    }
     else if(strncmp(rx_buffer,"*GameMode?#",11)==0)
    {
       
        sprintf(payload, "*GameMode,%d#",GameMode);
        SendReply(InputVia,payload); 
    }
     else if(strncmp(rx_buffer,"*MAXGAMES:",10)==0)
    {
        if(strcmp(InputVia,"BT")!=0)
        {
        sscanf(rx_buffer,"*MAXGAMES:%d#",&max_count);

        SaveInteger(NVS_MAXGAMES,max_count);
        sprintf(payload, "*MAXGAMES-OK,%d#",max_count);
        
        SendReply(InputVia,payload); 
        }
        
    }
     else if(strncmp(rx_buffer,"*COUNT-RESET#",16)==0)
    {
        current_count=0;
        life_count=max_count;
        SaveInteger(NVS_CURRENTCOUNT,current_count);
        SaveInteger(NVS_LIFECOUNT,life_count);
        sprintf(payload, "*RESET-COUNT-OK#");
        SendReply(InputVia,payload); 
      

    }
      else if(strncmp(rx_buffer,"*MAXGAMES?#",11)==0)
    {
        
        sprintf(payload, "*MAXGAMES:%d#",max_count);
        SendReply(InputVia,payload);
      
    }
      else if(strncmp(rx_buffer,"*CURRENTCOUNT?#",15)==0)
    {
        
        sprintf(payload, "*CURRENTCOUNT:%d#",current_count);
        SendReply(InputVia,payload); 
    }  
     else if(strncmp(rx_buffer,"*LIFECOUNT?#",15)==0)
    {
        life_count=max_count-current_count;
       
        sprintf(payload, "*LIFECOUNT:%d#",life_count);
        SendReply(InputVia,payload); 
        SaveInteger(NVS_LIFECOUNT,life_count);
    }
    else if(strncmp(rx_buffer,"*GMode?#",8)==0)
    {
        sprintf(payload, "*GMode:%d#",GameMode);
        SendReply(InputVia,payload); 
        
    }
    else if(strncmp(rx_buffer,"*SMode?#",8)==0)
    {
        sprintf(payload, "*SMode:%d#",SoundMode);
        SendReply(InputVia,payload); 
        
    }
    else if(strncmp(rx_buffer,"*GMode:",7)==0)
    {
        sscanf(rx_buffer, "*GMode:%d#",&GameMode);
        SaveInteger(NVS_GAME_MODE,GameMode);
        sprintf(payload, "*GMode-OK,%d#",GameMode);
        SendReply(InputVia,payload); 
    }       
    else if(strncmp(rx_buffer,"*SMode:",7)==0)
    {
        sscanf(rx_buffer, "*SMode:%d#",&SoundMode);
        SaveInteger(NVS_SOUND_MODE,SoundMode);
        sprintf(payload, "*SMode-OK,%d#",SoundMode);
        SendReply(InputVia,payload); 
    }
    else if(strncmp(rx_buffer,"*Mode2LT:",9)==0)
    {
         sscanf(rx_buffer,"*Mode2LT:%d#",&Mode2LightTime);
        SaveInteger(NVS_MODE2_TIME,Mode2LightTime);
        sprintf(payload, "*Mode2LT-OK,%d#",Mode2LightTime);
        SendReply(InputVia,payload); 
    }
    else if(strncmp(rx_buffer,"*OTP:",5)==0)
    {
        sscanf(rx_buffer,"*OTP:%d#",&OTPValue);
        sprintf(payload, "*OTP-OK,%d#",OTPValue);
        SendReply(InputVia,payload); 
        DisplayOTP();
    }
    else if(strncmp(rx_buffer,"*NORMAL#",8)==0)
    {
        sprintf(payload, "*NORMAL-OK#");
        SendReply(InputVia,payload); 
        DisplayNormal();
    }


    else if(strncmp(rx_buffer,"*Mode2LT?#",10)==0)
    {
          sprintf(payload, "*Mode2LT:%d#",Mode2LightTime);
        SendReply(InputVia,payload); 
    }
    else{
        int l = strlen(rx_buffer);
        char buf[l+1];
        if(strcmp(InputVia, "TCP") == 0)
        {
        if(extractSubstring(rx_buffer, buf) == true){
           sprintf(payload, "*%s#", buf);
           SendReply(InputVia,payload);
            // tx_event_pending = 1;
        }
       }
       else if(strcmp(InputVia, "UART") == 0){
        if(extractSubstring(rx_buffer, buf) == true){
            int l2 = strlen(buf);
            char b[l2+3];
            sprintf(b, "*%s#", buf);
            // tcp_ip_client_send_str(b);
            // tx_event_pending = 1;
        }
       }
       else{
        if(extractSubstring(rx_buffer, buf) == true){
            sprintf(payload, "*%s#", buf);
           SendReply(InputVia,payload);
            // tx_event_pending = 1;
        }
       }

    }



}