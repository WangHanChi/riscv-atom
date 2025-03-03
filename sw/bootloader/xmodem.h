#ifndef __XMODEM_H__
#define __XMODEM_H__
#include <stdint.h>

#define DELAY_PRESCALAR_MSEC 250  // sim

#define CLK_FREQ 12000000
// #define DELAY_PRESCALAR_USEC CLK_FREQ/1000000
// #define DELAY_PRESCALAR_MSEC CLK_FREQ/1000
// #define DELAY_PRESCALAR_SEC  CLK_FREQ

#define SOH  0x01
#define STX  0x02
#define EOT  0x04
#define ACK  0x06
#define NAK  0x15
#define CAN  0x18
#define CTRLZ 0x1A

typedef enum {
    OK      = 0,
    NOK     = 1,
    S_EOT   = 2,
    S_TERM  = 3,
    R_TERM  = 4,
    UNKCHAR = 5,
    TIMEOUT = 6,
    SUCCESS = 7,
    FAILURE = 8
} xmod_status;

xmod_status xmodemReceive(uint8_t * bf, unsigned len);


#endif // __XMODEM_H__