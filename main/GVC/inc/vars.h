#include "defs.h"
// vars for general
char UartDebugInfoRequired = 0;
char SNdateTime[100];
char SNuserName[100];
char URLdateTime[100];
char URLuserName[100];
char SSdateTime[100];
char SSuserName[100];
char PWdateTime[100];
char PWuserName[100];

char SS1dateTime[100];
char SS1userName[100];

char PW1dateTime[100];
char PW1userName[100];

char SS2dateTime[100];
char SS2userName[100];

char PW2dateTime[100];
char PW2userName[100];

char SIPdateTime[100];
char SIPuserName[100];
char MIPdateTime[100];
char MIPuserName[100];
char SerialNumber[100] = "GVC/WS/0000";
char ERASEdateTime[100];
char ERASEuserName[100];
char FWVersion[100] = "FW GVC 09JAN25";
char FOTA_URL[200] = "http://gvcsystems.com/WS/firmware.bin";
char WIFI_SSID_1[64];
char WIFI_PASS_1[64];
char WIFI_SSID_2[64];
char WIFI_PASS_2[64];
char WIFI_SSID_3[64];
char WIFI_PASS_3[64];
int WiFiNumber;
int RSSI;
int SipNumber;
int MipNumber;
char ErasedSerialNumber[100];
int sp_port;
char server_ip_addr[100];
char mqtt_uri[100];
char mqtt_user[100];
char mqtt_pass[100];
char TCP1_ip_addr[100];
char TCP2_ip_addr[100];
char TCP3_ip_addr[100];
int TCP1_server_port;
int TCP2_server_port;
int TCP3_server_port;

char mqtt_uri1[100];
char mqtt_user1[100];
char mqtt_pass1[100];
char mqtt_uri2[100];
char mqtt_user2[100];
char mqtt_pass2[100];
char mqtt_uri3[100];
char mqtt_user3[100];
char mqtt_pass3[100];


// kwikpay
// edges , AckPulseReceived, TID, LastTID, pin, pulses, tx_event_pending, Totals[]
int edges = 0; // number of edges (pulses * 2) for generating pulses on output pin
int AckPulseReceived = 0;
char LastTID[100];
char TID[100];
int pin = 0; // output pin for Generating Pulses
int pulses = 0; // number of pulses for generating pulses on output pin
int Totals[7];
int CashTotals[7];
char UniqueTimeStamp[100];
int sock = -1;

    //  INHUserName:INHdateTime:INHOutputValue 
char INHuserName[100];
char INHdateTime[100];
int INHOutputValue;

char PTuserName[100];
char PTdateTime[100];   
char PassThruValue[2];


char CAuserName[100];
char CAdateTime[100];   
int pulseWidth = 0;
int SignalPolarity = 0;

char CCdateTime[100];
char CCuserName[100];

char RSTdateTime[100];
char RSTuserName[100];

int EnabledChannel[NUM_CHANNELS] = {1,1,1,1,1,1,1};
int16_t chValue;




// vars for AAC
// extern int track_id,Total_Tracks,CurrentTrack;  


// vars for traffic

// vars for WAM

int LightTime;
int PlayTime;
int NumberOfLights;
int Ticks = 0;
unsigned int BlinlLEDTime;
unsigned int OKSwitchPressedCount,NoSwitchPressedCount,WrongSwitchPressedCount;
unsigned int PinPressed = 0;
bool GameOn,GameOnTimeOn;
unsigned int MissedCount = 0; 
unsigned int GapBeforeNextLight = 7;
unsigned int SelectedLEDNumber;
uint32_t LightOnTime,SwitchPressedTime;
unsigned int TimeToRespond,TotalTimeToRespond,AverageTimeToRespond,KeysPressed;
unsigned int TimeToStop,RemainingTime,Wait4NextGame;
bool Mode4094 = 0;
bool LeadingZeroBlank = true;
int NumericSerialNumnber;
int LocalGameEnable;
int GameNegativeMarking;
int GameMode;
int max_count;
int current_count;
int life_count;
int fileToBeRun=0;
uint64_t current_time_us; 
uint32_t elapsed_ms,last_elapsed_ms,last_audio_ms;
int SoundMode;  // 0 - off, 1 - on, 2 - on with sound, 3 - on with sound and vibration                        
bool NODEBUG;

int  BTconnected=0;
int MemorySequence[8];
int GameMode2Index;
int Mode2LightTime;
int SettingButtonPressed;


bool GameModeChanged;
bool SoundModeChanged;
bool PlayTimeModeChanged;
bool LightTimeModeChanged;
bool LightSettingModeChanged;

int OTPValue;


//Vending
unsigned char DisplayMode; 
char QrString[500];
int Image2BDisplayed;
int IsMobivendApi=0;
char val1[20], val2[20], val4[20], rawPrice[20], itemCode[10];

//mobivend
char API[100]={0};
char price[100]={0};
char refId[100]={0};

//mqtt
int MQTTRequired;
