#include "app.h"

void SetINHLow(void)
{

}
void SetINHHigh(void)
{

}

void RestartDevice(void)
{

}

void sendSocketData(void* sock, const char* data, size_t len, int flags)
{

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