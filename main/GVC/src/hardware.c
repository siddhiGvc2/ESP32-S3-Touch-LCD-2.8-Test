#include "app.h"

static const char *TAG = "HARDWARE";
void SetINHLow(void)
{

}
void SetINHHigh(void)
{

}

void sendSocketData(void* sock, const char* data, size_t len, int flags)
{

}


void RestartDevice(void)
{
   ESP_LOGI(TAG, "**************Restarting after 3 second******#");
     sendSocketData(sock, "*RST-OK#", strlen("*RST-OK#"), 0);
     ESP_LOGI(TAG, "*RST-OK#");
     uart_write_string_ln("*Resetting device#");
    //  led_state = WAITING_FOR_RESTART;
     vTaskDelay(4000/portTICK_PERIOD_MS);
    //  while ((edges !=0) || (PulseStoppedDelay!=0))
    //     vTaskDelay(1000/portTICK_PERIOD_MS);
     esp_restart();
}


bool extractSubstring(const char* str, char* result) {
    const char* start = strchr(str, '*');
    const char* end = strchr(str, '#');

    if (start != NULL && end != NULL && end > start + 1) {
        strncpy(result, start + 1, end - start - 1);
        result[end - start - 1] = '\0';
        return true;
    }

    return false;
}