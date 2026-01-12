


#define EX_UART_NUM UART_NUM_2
#define BUF_SIZE (1024)
#define RD_BUF_SIZE (BUF_SIZE)
#define MKM_IC_UART UART_NUM_2
#define MKM_IC_UART_TX 43
#define MKM_IC_UART_RX 44


//generaal
#define NVS_UNIX_TS   "UNIX_TS"
#define NVS_URL_USERNAME     "USERNAME_URL"
#define NVS_URL_DATETIME   "DATETIME_URL"
#define NVS_ERASED_SERIAL_NUMBER   "ERASED_SERIAL_NUMBER"
#define NVS_SERIAL_NUMBER   "SERIAL_NUMBER"
#define NVS_MIP_NUMBER   "MIP_NUMBER"
#define NVS_SIP_NUMBER   "SIP_NUMBER"
#define NVS_OTA_URL_KEY   "OTA_URL"
#define NVS_SIP_USERNAME     "USERNAME_SIP"
#define NVS_SIP_DATETIME   "DATETIME_SIP"
#define NVS_MIP_USERNAME     "USERNAME_MIP"
#define NVS_MIP_DATETIME   "DATETIME_MIP"
#define NVS_SS_USERNAME     "USERNAME_SS"
#define NVS_SS_DATETIME   "DATETIME_SS"
#define NVS_PW_USERNAME     "USERNAME_PW"
#define NVS_PW_DATETIME   "DATETIME_PW"
#define NVS_SN_USERNAME     "USERNAME_SN"
#define NVS_SN_DATETIME   "DATETIME_SN"
#define NVS_SS1_USERNAME     "USERNAME_SS1"
#define NVS_SS1_DATETIME   "DATETIME_SS1"
#define NVS_PW1_USERNAME     "USERNAME_PW1"
#define NVS_PW1_DATETIME   "DATETIME_PW1"
#define NVS_SS2_USERNAME     "USERNAME_SS2"
#define NVS_SS2_DATETIME   "DATETIME_SS2"
#define NVS_PW2_USERNAME     "USERNAME_PW2"
#define NVS_PW2_DATETIME   "DATETIME_PW2"
#define NVS_SSID_1_KEY        "SSID1"
#define NVS_PASS_1_KEY        "PASS1"
#define NVS_SSID_2_KEY        "SSID2"
#define NVS_PASS_2_KEY        "PASS2"
#define NVS_SSID_3_KEY        "SSID3"
#define NVS_PASS_3_KEY        "PASS3"
#define NVS_TCP1_IP_ADDR    "TCP1_IP_ADDR"
#define NVS_TCP1_SERVER_PORT  "TCP1_SERVER_PORT"
#define NVS_TCP2_IP_ADDR    "TCP2_IP_ADDR"
#define NVS_TCP2_SERVER_PORT  "TCP2_SERVER_PORT"
#define NVS_TCP3_IP_ADDR    "TCP3_IP_ADDR"
#define NVS_TCP3_SERVER_PORT  "TCP3_SERVER_PORT"
#define NVS_MQTT1_URI      "MQTT1_URI"
#define NVS_MQTT1_USER     "MQTT1_USER"
#define NVS_MQTT1_PASS     "MQTT1_PASS"
#define NVS_MQTT2_URI      "MQTT2_URI"
#define NVS_MQTT2_USER     "MQTT2_USER"
#define NVS_MQTT2_PASS     "MQTT2_PASS"
#define NVS_MQTT3_URI      "MQTT3_URI"
#define NVS_MQTT3_USER     "MQTT3_USER"
#define NVS_MQTT3_PASS     "MQTT3_PASS"



// kwikpay Defs
#define NUM_CHANNELS 7
#define MAXSIPNUMBER 3
#define MAXMIPNUMBER 3
#define NVS_CASH1_KEY   "CASH1"
#define NVS_CASH2_KEY   "CASH2"
#define NVS_CASH3_KEY   "CASH3"
#define NVS_CASH4_KEY   "CASH4"
#define NVS_CASH5_KEY   "CASH5"
#define NVS_CASH6_KEY   "CASH6"
#define NVS_CASH7_KEY   "CASH7"
#define NVS_INH_USERNAME "inh_username"
#define NVS_INH_DATETIME "inh_datetime"
#define NVS_INH_KEY "inh_key"
#define NVS_PT_USERNAME "pt_username"
#define NVS_PT_DATETIME "pt_datetime"   
#define NVS_PASS_THRU "pass_thru"
#define NVS_CA_USERNAME "ca_username"
#define NVS_CA_DATETIME "ca_datetime" 
#define NVS_RST_USERNAME     "USERNAME_RST"
#define NVS_RST_DATETIME   "DATETIME_RST"  
#define NVS_SIP_USERNAME     "USERNAME_SIP"
#define NVS_SIP_DATETIME   "DATETIME_SIP"
#define NVS_CC_USERNAME     "USERNAME_CC"
#define NVS_CC_DATETIME   "DATETIME_CC"
#define NVS_CA_KEY "ca_key"
#define NVS_CHNL1_KEY   "CHNL1"
#define NVS_CHNL2_KEY   "CHNL2"
#define NVS_CHNL3_KEY   "CHNL3"
#define NVS_CHNL4_KEY   "CHNL4"
#define NVS_CHNL5_KEY   "CHNL5"
#define NVS_CHNL6_KEY   "CHNL6"
#define NVS_CHNL7_KEY   "CHNL7"
     

//WAM
#define MAX_NUMBER_OF_LIGHTS 8
#define NVS_GAME_MODE "GAMEMODE"
#define NVS_SOUND_MODE "SOUNDMODE"
#define NVS_MODE2_TIME "LIGHT_TIME"
#define NVS_LIGHT_TIME "LIGHT_TIME"
#define NVS_PLAY_TIME "PLAY_TIME"
#define NVS_GAP_TIME "GAP_TIME"
#define NVS_TOTAL_LIGHTS "TOTAL_LIGHTS"
#define NVS_MAXGAMES "MAXGAMES"
#define NVS_CURRENTCOUNT "CURRENTCOUNT"
#define NVS_LIFECOUNT "LIFECOUNT"
#define SettingGameMode 3
#define MaximumGameMode 3

#define SettingSoundMode 4
#define MaximumSoundMode 2

#define SettingPlayTime 5
#define MaximumPlayTime 4

#define SettingLightTime 6
#define MaximumLightTime 5

#define SettingNumberOfLights 7
#define MaximumNumberOfLights 8

#define MaximumSettingNumber 8


//Vending
#define NVS_QR_STRING   "QR_STRING"
#define ModeNone   0
#define ModeQR   1
#define ModeNoWifi 2
#define ModeBootingUp 3
#define ModeServerBad 4
#define ModeFOTA 5
#define ModeCashReceived 6
#define ModeSelectItem 7
#define ModeItemVend 8
#define ModeCashlessDevice 9
#define ModeNoStock 10
#define ModeStatusText 11
#define ModeCoinInserted 12
#define ImageBootingUp 1
#define ImageNoWifi 2
#define ImageCashReceived 3
#define ImageSelectItem 4
#define ImageItemVend 5
#define ImageCashlessDevice 6
#define ImageQRCode 7 
#define ImageNoStock 8
#define StatusText 9
#define ImageCoinInserted 10

#define QR_CODE_SIZE  198
#define URL_HEARTBEAT    "http://snaxsmart.mobivend.in/heartbeat/%s" // SerialNumber
#define URL_CASHLESSVEND "http://snaxsmart.mobivend.in/cashlessvend/%s?spring=%s&price=%s&request=%s" // SerialNumber,spring,price,refId
#define URL_CASHLESSSALE "http://snaxsmart.mobivend.in/CashlessSale/%s?request=%s&items=%s,%s" // SerialNumber,refId,items,spring

#define MQTT_CONNEECTED 0
