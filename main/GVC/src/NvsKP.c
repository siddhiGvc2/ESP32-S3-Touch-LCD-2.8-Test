#include "app.h"

static const char *TAG = "NVS_KP";

void load_kwikpay_settings(){

    ESP_LOGI(TAG, "Loading Kwikpay Settings from NVS");

    GetStrings( NVS_INH_USERNAME , INHuserName, sizeof(INHuserName));
    GetStrings( NVS_INH_DATETIME , INHdateTime, sizeof(INHdateTime));
    GetInteger( NVS_INH_KEY , &INHOutputValue);

    GetStrings( NVS_PT_USERNAME , PTuserName, sizeof(PTuserName));
    GetStrings( NVS_PT_DATETIME , PTdateTime, sizeof(PTdateTime));   
    GetStrings( NVS_PASS_THRU , PassThruValue, sizeof(PassThruValue));  
    if (strlen(PassThruValue) == 0) {
        strcpy(PassThruValue, PASS_THRU);
    }
    GetStrings( NVS_CA_USERNAME , CAuserName, sizeof(CAuserName));
    GetStrings( NVS_CA_DATETIME , CAdateTime, sizeof(CAdateTime));
    GetInteger( NVS_CA_KEY , &pulseWidth);
    GetStrings( NVS_CC_USERNAME , CCuserName, sizeof(CCuserName));
    GetStrings( NVS_CC_DATETIME , CCdateTime, sizeof(CCdateTime));
    GetStrings( NVS_UNIX_TS , UniqueTimeStamp, sizeof(UniqueTimeStamp));
    GetInteger( NVS_CHNL1_KEY , &EnabledChannel[0]);
    GetInteger( NVS_CHNL2_KEY , &EnabledChannel[1]);
    GetInteger( NVS_CHNL3_KEY , &EnabledChannel[2]);
    GetInteger( NVS_CHNL4_KEY , &EnabledChannel[3]);
    GetInteger( NVS_CHNL5_KEY , &EnabledChannel[4]);
    GetInteger( NVS_CHNL6_KEY , &EnabledChannel[5]);
    GetInteger( NVS_CHNL7_KEY , &EnabledChannel[6]);

   
}