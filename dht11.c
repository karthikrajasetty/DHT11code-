// DHT11 Driver
// Karthik Raja Setty

//-----------------------------------------------------------------------------
// Hardware Target
//-----------------------------------------------------------------------------

// Target uC:       TM4C123GH6PM
// System Clock:    40 MHz

//-----------------------------------------------------------------------------
// Device includes, defines, and assembler directives
//-----------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "tm4c123gh6pm.h"
#include "dht11.h"
#include "wait.h"

//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------

unsigned short Read()
{
    uint8_t bit_cnt;
    uint8_t hum_int=0;
    for (bit_cnt=0;bit_cnt<8;bit_cnt++)
    {
        while(DHT==0);  //50us of low signal for every data bit
        if (DHT==1)
        {
            waitMicrosecond(29); //29us of high means'0' else '1'
            hum_int |= (0x01*DHT);
            if (bit_cnt!=7)
            {
            hum_int <<=1;
           }
        }
        while(DHT==1);
    }
    return (hum_int);
}
