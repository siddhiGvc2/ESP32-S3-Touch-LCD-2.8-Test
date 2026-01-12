//uart
extern void uart_write_string(const char *);
extern void uart_write_string_ln(const char *);
extern void uart_write_number(uint8_t);


//GSM
extern void gsm_write_string(const char *);
extern void gsm_write_string_ln(const char *);


extern void sendData(char*);
extern void AnalyseCommands(char*,char*);
extern void AnalyseGeneralCommands(char*,char*);
extern void AnalyseKwikpayCommands(char*,char*);
extern void AnalyseAACCommands(char*,char*);
extern void AnalyseVendingCommands(char*,char*);
extern void AnalyseWAMCommands(char*,char*);
extern void PlayCurrentTrack();
extern void SendReply(char*, char*);
extern void SaveString(const char*, char*);
extern void SaveInteger(const char*, int );
extern void SetINHLow(void);
extern void SetINHHigh(void);
extern void RestartDevice(void);
extern void sendSocketData(void* sock, const char* data, size_t len, int flags);


// PT6961
extern void Init6961 (void);
extern void DisplayDigit4 (unsigned char, unsigned char, unsigned int);
extern void DisplayDigit3 (unsigned char, unsigned char, unsigned int);
extern void DisplayDigit2 (unsigned char, unsigned char, unsigned char);
extern void DisplayDigit1 (unsigned char, unsigned char, unsigned char);
extern void Blank_digits (unsigned char ,unsigned char ,unsigned char);
extern void DisplayDash (unsigned char ,unsigned char ,unsigned char);
extern void WriteSPICommand(unsigned char , unsigned char);
extern void DisplayRemainingTime (void);
extern void DisplayAverageTime(void);
extern void BuzzerGameOver (void);
extern void DisplayCode (unsigned int);

// game
extern void StartGameRoutine (void);
extern void GameOverRoutine (void);
extern void UnpackGameMode (void);
extern void DisplayRemainingCount (void);
extern void DisplayWiFiStatus (void);
extern void DisplayGameOverValues (void);

extern void StartPlaySoundRoutine(void);
extern void  IncrementParameterValue(void);

extern void BLE_main(void);
extern void SendBTData (const char *);


extern void DisplayGameMode(void);
extern void DisplaySoundMode(void);
extern void  DisplayTMode(void);
extern void DisplayLightTime(void);
extern void DisplayMaxLights(void);

extern void DisplayOTP (void);
extern void DisplayNormal (void);
extern bool extractSubstring(const char* , char* );


//mqtt
extern void mqtt_publish_msg(char* );

//TFT
extern void display_images(const lv_img_dsc_t *);
extern void showLogo(void);
extern void DisplayBootingUp(void);
extern void DisplayNoWiFi(void);
extern void dispayQR(void);
extern void DisplayCashReceived(void);
extern void DisplaySelectItem(void);
extern void DisplayItemVend(void);
extern void DisplayCashlessDevice(void);
extern void DisplayNoStock(void);
extern void DisplayStatusText(void);
extern void DisplayCoinInserted(void);

//mobivend
extern void start_http_get_task(const char *);