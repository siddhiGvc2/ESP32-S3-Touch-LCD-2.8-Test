#include "app.h"

#define HIGH 1
#define LOW 0

#define SegC 0x78
#define SegP 0x638 // c d off
#define SegDash 0x200
// N is c,e,g
#define SegN 0x320
// T is seg d,e,f,g
#define SegT 0x268
// L is seg d,e,f
#define SegL 0x68
// same as 5
#define SegS 0x358
// same as 8 except d
#define SegA 0x738
#define SegO 0x578
#define SegU 0x568
#define SegG 0x178
static const char *TAG = "PT6961";

#define SegT 0x268

#define SegBlank 0x0
//Din : MOSI
//Dout : MISO

// P105
//unsigned char SegTable[10] = {0x77, 0x24, 0xb3, 0xb6, 0xe4, 0xd6, 0xd7, 0x34, 0xf7, 0xf6};
// P318
//unsigned int SegTable[10] = {0x678,0x048,0x6A8,0x2E8,0x0D8,0x2F0,0x6F0,0x068,0x6F8,0x2F8};
// P319
unsigned int SegTable[10] = {0x578,0x500,0x670,0x750,0x708,0x358,0x378,0x510,0x778,0x758};

//unsigned char DotTable[8] = {0x10, 0x20, 0x04, 0x02, 0x80, 0x40, 0x8, 0x01};
//unsigned int DotTable[8] = {0x20,0x08,0x40,0x0200,0x400,0x10,0x80,0x0100};
//P319
unsigned int DotTable[8] = {0x10,0x400,0x100,0x40,0x20,0x08,0x200,0x80};
//unsigned char DigitMapTable[7] = {0,1,2,3,4,5,6,7}; //P105
unsigned char DigitMapTable[7] = {6,3,4,5,2,0,1}; // P319
//unsigned char DigitMapTable[7] = {0,1,2,3,4,5,6}; // Simple
//unsigned char DigitMapTable[7] = {5,4,3,6,0,1,2}; // TRY
unsigned int DotValue[14];
unsigned char Mode;
#define MaxModule 1
#define DigitPerModule 7


#define SevenDigit 0
#define ThreeDigit 1
#define FourDigit 2

void delay (unsigned char value)
{
    // ets_delay_us(20);
}

void digitalWrite (unsigned char pin, unsigned char value)
{
    
}

// as per data sheet CLK remain high
// set output LSB.
// pulse clock high - low - high

void SPItransfer (unsigned char value)
{
   
}

void ClearSTRBModule (unsigned char module)
{
    

}

void SetSTRBModule (unsigned char module)
{
 

}
void WriteSPICommand(unsigned char val, unsigned char module)
{
  
}

void WriteSPIAddress(unsigned char val, unsigned char module)
{
  
}


unsigned char WriteSPIByte(unsigned char val, unsigned char module)
{
  return 0
}

void Init6961 (void)
{
 
}


void DisplayDigit1 (unsigned char digit, unsigned char module , unsigned char val)
{
  

}

void DisplayDigit3 (unsigned char digit, unsigned char module, unsigned int val)
{
 
  
}


void DisplayDigit2 (unsigned char digit, unsigned char module, unsigned char val)
{
  
}



void DisplayDigit4 (unsigned char digit, unsigned char module, unsigned int val)
{
  
  
}


void DisplaySegment1 (unsigned char digit, unsigned char module,unsigned int val)
{
 
}

void SetSegment1 (unsigned char digit, unsigned char val)
{
 
}

void OnSegment1 (unsigned char digit,unsigned char module, unsigned char val)
{
  
}


void OffSegment1 (unsigned char digit, unsigned char module, unsigned char val)
{
 
}

void Blank_digits (unsigned char digit,unsigned char module,unsigned char count)
{

}

void DisplayRemainingTime (void)
{
   
}

void DisplayAverageTime (void)
{
    
}

// display Cxx where xx is code
void DisplayCode (unsigned int code)
{

}

void DisplayDash (unsigned char digit,unsigned char module,unsigned char count)
{
   

}


void DisplayRemainingCount (void)
{
 
}

void DisplayWiFiStatus (void)
{
  
}

// display game and sound mode
void DisplayGameMode (void)
{
    

}

void DisplaySoundMode (void)
{
   
}

// display game and time
void DisplayTMode (void)
{
   
    
}


void DisplayMaxLights(void){
   
}

void DisplayLightTime(void){
   
}


void DisplayOTP (void)
{
}

void DisplayNormal (void)
{
 
}

void DisplayStatus (void)
{
  
 
}

void DisplayGameOverValues (void)
{
 
}  