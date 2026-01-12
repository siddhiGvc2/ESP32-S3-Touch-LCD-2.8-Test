#include "app.h"

void display_images(const lv_img_dsc_t *ig) {
   
  
}


// static lv_obj_t * img6 = NULL;
void showLogo(void)
{
    

}


void DisplayBootingUp(void)
{
    Image2BDisplayed = ImageBootingUp;


}

void DisplayNoWiFi(void)
{

    Image2BDisplayed = ImageNoWifi;

}

void DisplayCashReceived(void)
{
    Image2BDisplayed = ImageCashReceived;

}

void DisplaySelectItem(void)
{
    Image2BDisplayed = ImageSelectItem;
   
}

void DisplayItemVend(void)
{
    Image2BDisplayed = ImageItemVend;
    
}


//added on 120525

void DisplayCashlessDevice(void)
{
    Image2BDisplayed = ImageCashlessDevice;
    
}

void DisplayNoStock(void)
{
    Image2BDisplayed = ImageNoStock;
    //DisplayMode = ModeNoStock;
}

void DisplayStatusText(void)
{
    DisplayMode = ModeNone;
    Image2BDisplayed = StatusText;
    
}

void DisplayCoinInserted(void)
{
    Image2BDisplayed = ImageCoinInserted;

}

// changed on 140525
// all code shifted to display_image_task/main.c
void dispayQR(void){
   
}


