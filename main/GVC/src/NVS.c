#include "app.h"

static const char *TAG = "NVS_UTILS";

void SaveInteger(const char* key, int value)
{
  if(utils_nvs_handle){
        nvs_set_i16(utils_nvs_handle, key, value);
    }

}

void SaveString(const char* key, char* value)
{
    if(utils_nvs_handle){
        nvs_set_str(utils_nvs_handle, key, value);
        nvs_commit(utils_nvs_handle);
    }
}

esp_err_t GetStrings(const char * key , char * val, size_t max_length){
    esp_err_t ret = ESP_FAIL;
    if(utils_nvs_handle){
        ret = nvs_get_str(utils_nvs_handle, key, val, &max_length);
    }
    return ret;
}

esp_err_t GetInteger(const char * key , int16_t * val){
    esp_err_t ret = ESP_FAIL;
    if(utils_nvs_handle){
        ret = nvs_get_i16(utils_nvs_handle, key, val);
    }
    return ret;
}


void NVS_ERASE_ALL(){
    if(utils_nvs_handle){
        nvs_erase_all(utils_nvs_handle);
    }
}

void NVS_ERASE_KEY(const char * key){
    if(utils_nvs_handle){
        nvs_erase_key(utils_nvs_handle, key);
    }
}


void nvs_init(){
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    esp_err_t err = nvs_open("storage", NVS_READWRITE, &utils_nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGI(TAG, "Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
        ESP_LOGI(TAG, "NVS Open Done\n");
    }
}


void load_general_settings(){

    ESP_LOGI(TAG, "Loading General Settings from NVS");
  
    if(GetStrings(NVS_TCP1_IP_ADDR , TCP1_ip_addr, sizeof(TCP1_ip_addr)) != ESP_OK){
        strcpy(TCP1_ip_addr, TCP_URL1);
    }

    if(GetInteger(NVS_TCP1_SERVER_PORT, &TCP1_server_port) != ESP_OK){
        TCP1_server_port = TCP_PORT1;
    }

    if(GetStrings(NVS_TCP2_IP_ADDR , TCP2_ip_addr, sizeof(TCP2_ip_addr)) != ESP_OK){
        strcpy(TCP2_ip_addr, TCP_URL2);
    }

    if(GetInteger(NVS_TCP2_SERVER_PORT, &TCP2_server_port) != ESP_OK){
        TCP2_server_port = TCP_PORT2;
    }

    if(GetStrings(NVS_TCP3_IP_ADDR , TCP3_ip_addr, sizeof(TCP3_ip_addr)) != ESP_OK){
        strcpy(TCP3_ip_addr, TCP_URL3);
    }

    if(GetInteger(NVS_TCP3_SERVER_PORT, &TCP3_server_port) != ESP_OK){
        TCP3_server_port = TCP_PORT3;
    }

    if(GetStrings(NVS_MQTT1_URI , mqtt_uri1, sizeof(mqtt_uri1)) != ESP_OK){ 
        strcpy(mqtt_uri1, MQTT_BROKER1);
    }

    if(GetStrings(NVS_MQTT1_USER , mqtt_user1, sizeof(mqtt_user1)) != ESP_OK){
        strcpy(mqtt_user1, MQTT_USER1);
    }
    if(GetStrings(NVS_MQTT1_PASS , mqtt_pass1, sizeof(mqtt_pass1)) != ESP_OK){
        strcpy(mqtt_pass1, MQTT_PASS1);
    }
    if(GetStrings(NVS_MQTT2_URI , mqtt_uri2, sizeof(mqtt_uri2)) != ESP_OK){
        strcpy(mqtt_uri2, MQTT_BROKER2);
    }
    if(GetStrings(NVS_MQTT2_USER , mqtt_user2, sizeof(mqtt_user2)) != ESP_OK){
        strcpy(mqtt_user2, MQTT_USER2);
    }
    if(GetStrings(NVS_MQTT2_PASS , mqtt_pass2, sizeof(mqtt_pass2)) != ESP_OK){
        strcpy(mqtt_pass2, MQTT_PASS2);
    }
    if (GetInteger(NVS_MIP_NUMBER, &MipNumber) != ESP_OK) {
        MipNumber = 1;
    }

    if (MipNumber == 0 || MipNumber > MAXMIPNUMBER) {
        MipNumber = 1;
    }


    if (MipNumber == 1)
    {
        
        // added on 090525
        strcpy(mqtt_uri, mqtt_uri1);
        strcpy(mqtt_user,mqtt_user1);
        strcpy(mqtt_pass,mqtt_pass1);

    }
    if (MipNumber == 2)
    {
      
        // added on 090525
        strcpy(mqtt_uri, mqtt_uri2);
        strcpy(mqtt_user,mqtt_user2);
        strcpy(mqtt_pass,mqtt_pass2);

    }
    if (MipNumber == 3)
    {
       
        // added on 090525
        strcpy(mqtt_uri, mqtt_uri3);
         strcpy(mqtt_user,mqtt_user3);
        strcpy(mqtt_pass,mqtt_pass3);
       
    }
    
    if(GetInteger(NVS_SIP_NUMBER,&SipNumber) != ESP_OK){
       SipNumber = 1;
    }
   

     if ((SipNumber == 0) || (SipNumber > MAXSIPNUMBER))
        SipNumber = 1;

    if (SipNumber == 1)
    {
        strcpy(server_ip_addr, TCP1_ip_addr);
        server_port = TCP1_server_port;
      

    }
    if (SipNumber == 2)
    {
        strcpy(server_ip_addr, TCP2_ip_addr);
        server_port = TCP2_server_port;
      
    }
    if (SipNumber == 3)
    {
        strcpy(server_ip_addr, TCP3_ip_addr);
        server_port = TCP3_server_port;
      
    }
 

    if(GetStrings(NVS_SSID_1_KEY , WIFI_SSID_1, sizeof(WIFI_SSID_1)) != ESP_OK){
        strcpy(WIFI_SSID_1, DEFAULT_SSID1);
    }
    if(GetStrings(NVS_PASS_1_KEY , WIFI_PASS_1, sizeof(WIFI_PASS_1)) != ESP_OK){
        strcpy(WIFI_PASS_1, DEFAULT_PASS2);
    }
    if(GetStrings(NVS_SSID_2_KEY , WIFI_SSID_2, sizeof(WIFI_SSID_2)) != ESP_OK){
        strcpy(WIFI_SSID_2, DEFAULT_SSID2);
    }
    if(GetStrings(NVS_PASS_2_KEY , WIFI_PASS_2, sizeof(WIFI_PASS_2)) != ESP_OK){
        strcpy(WIFI_PASS_2, DEFAULT_PASS2);
    }
    if(GetStrings(NVS_SSID_3_KEY , WIFI_SSID_3, sizeof(WIFI_SSID_3)) != ESP_OK){
        strcpy(WIFI_SSID_3, DEFAULT_SSID3);
    }
    if(GetStrings(NVS_PASS_3_KEY , WIFI_PASS_3, sizeof(WIFI_PASS_3)) != ESP_OK){
        strcpy(WIFI_PASS_3, DEFAULT_PASS3);
    }


    GetStrings(NVS_SERIAL_NUMBER , SerialNumber, sizeof(SerialNumber));
    GetStrings(NVS_ERASED_SERIAL_NUMBER , ErasedSerialNumber, sizeof(ErasedSerialNumber));  

    GetStrings(NVS_PW_USERNAME , PWuserName, sizeof(PWuserName));
    GetStrings(NVS_PW_DATETIME , PWdateTime, sizeof(PWdateTime));
    GetStrings(NVS_SS_USERNAME , SSuserName, sizeof(SSuserName));       
    GetStrings(NVS_SS_DATETIME , SSdateTime, sizeof(SSdateTime));
    GetStrings(NVS_PW1_USERNAME , PW1userName, sizeof(PW1userName));
    GetStrings(NVS_PW1_DATETIME , PW1dateTime, sizeof(PW1dateTime));
    GetStrings(NVS_SS1_USERNAME , SS1userName, sizeof(SS1userName));
    GetStrings(NVS_SS1_DATETIME , SS1dateTime, sizeof(SS1dateTime));
    GetStrings(NVS_PW2_USERNAME , PW2userName, sizeof(PW2userName));
    GetStrings(NVS_PW2_DATETIME , PW2dateTime, sizeof(PW2dateTime));
    GetStrings(NVS_SS2_USERNAME , SS2userName, sizeof(SS2userName));
    GetStrings(NVS_SS2_DATETIME , SS2dateTime, sizeof(SS2dateTime));        
    GetStrings(NVS_URL_USERNAME , URLuserName, sizeof(URLuserName));
    GetStrings(NVS_URL_DATETIME , URLdateTime, sizeof(URLdateTime));    
    GetStrings(NVS_SN_USERNAME , SNuserName, sizeof(SNuserName));
    GetStrings(NVS_SN_DATETIME , SNdateTime, sizeof(SNdateTime));


}


void load_settings()
{
    ESP_LOGI(TAG, "Loading Settings from NVS");
  load_general_settings();
}