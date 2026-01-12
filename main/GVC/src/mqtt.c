#include "app.h"

static const char *TAG = "MQTT";



void mqtt_publish_msg(char* msg)
{
    ESP_LOGI(TAG, "Publishing MQTT message: %s", msg);
    // Implementation for publishing the MQTT message goes here
}