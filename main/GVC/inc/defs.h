#include "ST7789.h"
#include "PCF85063.h"
#include "QMI8658.h"
#include "SD_MMC.h"
#include "Wireless.h"
#include "LVGL_Example.h"
#include "BAT_Driver.h"
#include "PWR_Key.h"
#include "LVGL_Music.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "externVars.h"
#include "calls.h"



#define EX_UART_NUM UART_NUM_2
#define BUF_SIZE (1024)
#define RD_BUF_SIZE (BUF_SIZE)

#define MKM_IC_UART UART_NUM_2
#define MKM_IC_UART_TX 43
#define MKM_IC_UART_RX 44


// kwikpay Defs
#define NVS_INH_USERNAME "inh_username"
#define NVS_INH_DATETIME "inh_datetime"
#define NVS_INH_KEY "inh_key"
#define NVS_PT_USERNAME "pt_username"
#define NVS_PT_DATETIME "pt_datetime"   
#define NVS_PASS_THRU "pass_thru"
#define NVS_CA_USERNAME "ca_username"
#define NVS_CA_DATETIME "ca_datetime"       
#define NVS_CA_KEY "ca_key"
     
