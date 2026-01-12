#include "defs.h"
// vars for general
extern char UartDebugInfoRequired = 0;

// vars for kwikpay 
extern char SNdateTime[100];
extern char SNuserName[100];
extern char URLdateTime[100];
extern char URLuserName[100];

extern char SSdateTime[100];
extern char SSuserName[100];

extern char PWdateTime[100];
extern char PWuserName[100];

extern char SS1dateTime[100];
extern char SS1userName[100];

extern char PW1dateTime[100];
extern char PW1userName[100];

extern char SS2dateTime[100];
extern char SS2userName[100];

extern char PW2dateTime[100];
extern char PW2userName[100];

extern char SIPdateTime[100];
extern char SIPuserName[100];
extern char MIPdateTime[100];
extern char MIPuserName[100];
extern char SerialNumber[100];
extern char ERASEdateTime[100];
extern char ERASEuserName[100];
extern char FWVersion[100];
extern char FOTA_URL[200];
extern char WIFI_SSID_1[64];
extern char WIFI_PASS_1[64];
extern char WIFI_SSID_2[64];
extern char WIFI_PASS_2[64];
extern char WIFI_SSID_3[64];
extern char WIFI_PASS_3[64];
extern int WiFiNumber;
extern int RSSI;
extern int SipNumber;
extern int MipNumber;
extern char ErasedSerialNumber[100];
extern int sp_port;
extern char server_ip_addr[100];
extern char mqtt_uri[100];
extern char mqtt_user[100];
extern char mqtt_pass[100];
extern char TCP1_ip_addr[100];
extern char TCP2_ip_addr[100];
extern char TCP3_ip_addr[100];
extern int TCP1_server_port;
extern int TCP2_server_port;
extern int TCP3_server_port;

extern char mqtt_uri1[100];
extern char mqtt_user1[100];
extern char mqtt_pass1[100];
extern char mqtt_uri2[100];
extern char mqtt_user2[100];
extern char mqtt_pass2[100];
extern char mqtt_uri3[100];
extern char mqtt_user3[100];
extern char mqtt_pass3[100];

    // vars for kwikpay
    // kwikpay
    // edges , AckPulseReceived, TID, LastTID, pin, pulses, tx_event_pending, Totals[]
extern int edges; // number of edges (pulses * 2) for generating pulses on output pin
extern int AckPulseReceived;
extern char LastTID[100];
extern char TID[100];
extern int pin; // output pin for Generating Pulses
extern int pulses; // number of pulses for generating pulses on output pin
extern int Totals[7];
extern int CashTotals[7];
extern char UniqueTimeStamp[100];
extern int sock;
extern char INHuserName[100];
extern char INHdateTime[100];
extern int INHOutputValue;
extern char PTuserName[100];
extern char PTdateTime[100];   
extern char PassThruValue[2];
extern char CAuserName[100];
extern char CAdateTime[100];
extern char CCdateTime[100];
extern char CCuserName[100];
extern char RSTdateTime[100];
extern char RSTuserName[100];
extern int pulseWidth;
extern int SignalPolarity;
extern int EnabledChannel[NUM_CHANNELS];
extern int16_t chValue;



// vars for AAC
extern int track_id,Total_Tracks,CurrentTrack;  


// vars for traffic

// vars for WAM
extern int LightTime;
extern int PlayTime;
extern int NumberOfLights;
extern int Ticks;
extern unsigned int BlinlLEDTime;
extern unsigned int OKSwitchPressedCount,NoSwitchPressedCount,WrongSwitchPressedCount;
extern unsigned int PinPressed;
extern bool GameOn,GameOnTimeOn;
extern unsigned int MissedCount; 
extern unsigned int GapBeforeNextLight;
extern unsigned int SelectedLEDNumber;
extern uint32_t LightOnTime,SwitchPressedTime;
extern unsigned int TimeToRespond,TotalTimeToRespond,AverageTimeToRespond,KeysPressed;
extern unsigned int TimeToStop,RemainingTime,Wait4NextGame;
extern bool Mode4094;
extern bool LeadingZeroBlank;
extern int NumericSerialNumnber;
extern int LocalGameEnable;
extern int GameNegativeMarking;
extern int GameMode;
extern int max_count;
extern int current_count;
extern int life_count;
extern int fileToBeRun;
extern uint64_t current_time_us; 
extern uint32_t elapsed_ms,last_elapsed_ms,last_audio_ms;
extern int SoundMode;  // 0 - off, 1 - on, 2 - on with sound, 3 - on with sound and vibration                        
extern bool NODEBUG;

extern int  BTconnected;
extern int MemorySequence[8];
extern int GameMode2Index;
extern int Mode2LightTime;
extern int SettingButtonPressed;


extern bool GameModeChanged;
extern bool SoundModeChanged;
extern bool PlayTimeModeChanged;
extern bool LightTimeModeChanged;
extern bool LightSettingModeChanged;

extern int OTPValue;

// vars for vending
extern unsigned char DisplayMode; 
extern char QrString[500];