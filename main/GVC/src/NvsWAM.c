#include "app.h"



void load_wam_settings()
{
 
    if(GetInteger(NVS_LIGHT_TIME , &LightTime)!=ESP_OK)
    {
        LightTime = 10;
        
    }
    BlinlLEDTime = 10 * LightTime;
    if(GetInteger(NVS_PLAY_TIME, &PlayTime)!=ESP_OK)
    {
        PlayTime=1;
    }
    if(PlayTime==0 || PlayTime > MaximumPlayTime) 
    {
        PlayTime=1;
      
    }
    if(GetInteger(NVS_GAP_TIME, &GapBeforeNextLight)!=ESP_OK)
    {
         GapBeforeNextLight = 5;
    }
     TimeToStop = GapBeforeNextLight * 1000;

    GetInteger(NVS_TOTAL_LIGHTS, &NumberOfLights);
    if(GetInteger(NVS_GAME_MODE, &GameMode)!=ESP_OK)
    {
        GameMode=3;
    }
    GetInteger(NVS_MAXGAMES, &max_count);
    GetInteger(NVS_CURRENTCOUNT,&current_count);
    GetInteger(NVS_LIFECOUNT, &life_count);
    if(GetInteger(NVS_SOUND_MODE, &SoundMode)!=ESP_OK)
    {
        SoundMode=0;
    }
    GetInteger(NVS_MODE2_TIME, &Mode2LightTime);
    if(Mode2LightTime==0 || Mode2LightTime > MaximumLightTime)
    {
        Mode2LightTime=1;
    }

    UnpackGameMode();
}