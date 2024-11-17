#include "uop_msb.h"
using namespace uop_msb;
#include <string.h>


DigitalOut yellowLED(PC_3);



void split(char *str, const char *sep, const char *res[], size_t n)
{
    for (size_t i = 0; i < n; i++) {
        size_t len = strcspn(str, sep);
        
        res[i] = str;
        
        str += len;
        if (*str) *str++ = '\0';
        
    }
}

int main()
{   
    char data[18];
    scanf("%s", data);
    size_t n = 6;
    const char *token[n];
    int year, month, day, hour, minute, second;
    
    split(data, "/", token, n);

    year = atoi(token[0]);
    month = atoi(token[1]);
    day = atoi(token[2]);
    hour = atoi(token[3]);
    minute = atoi(token[4]);
    second = atoi(token[5]);
    
    printf("year is \"%d\"\n", year);
    printf("month is \"%d\"\n", month);
    printf("day is \"%d\"\n", day);
    printf("hour is \"%d\"\n", hour);
    printf("minute is \"%d\"\n", minute);
    printf("second is \"%d\"\n", second);


    while(1)
    {
        yellowLED = !yellowLED;
        wait_us(500000);
    }
}