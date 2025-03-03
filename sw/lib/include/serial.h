#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdint.h>
#include <stdbool.h>

// Register Offsets
#define UART_REG_RBR 0x00
#define UART_REG_THR 0x00
#define UART_REG_LCR 0x04
#define UART_REG_LSR 0x08
#define UART_REG_DIV 0x0c

// THR
#define UART_REG_THR_TXDA 0xff
#define UART_REG_RBR_RXDA 0xff

// LCR
#define UART_REG_LCR_RXEN 0b00000001
#define UART_REG_LCR_TXEN 0b00000010
#define UART_REG_LCR_STPB 0b00000100
#define UART_REG_LCR_PARB 0b00001000
#define UART_REG_LCR_EPAR 0b00010000
#define UART_REG_LCR_LPBK 0b10000000

// LSR
#define UART_REG_LCR_RVAL 0b00000001
#define UART_REG_LCR_TEMT 0b00000010
#define UART_REG_LCR_FERR 0b00000100
#define UART_REG_LCR_PERR 0b00001000


// Baud Rates
#define UART_BAUD_4800      4800
#define UART_BAUD_9600      9600
#define UART_BAUD_14400     14400
#define UART_BAUD_19200     19200
#define UART_BAUD_28800     28800
#define UART_BAUD_38400     38400
#define UART_BAUD_57600     57600
#define UART_BAUD_115200    115200
#define UART_BAUD_DEFAULT   115200

/**
 * @brief Serial configuration struct
 */
typedef struct {
    unsigned baud;
    bool rx_enable;
    bool tx_enable;
    bool dual_stop_bits;
    bool enable_parity_bit;
    bool even_parity;
    bool loopback_enable;
}  Serial_Config;


// Default settings
#define Serial_Config_default  {  \
    .baud = UART_BAUD_DEFAULT,  \
    .rx_enable = true,          \
    .tx_enable = true,          \
    .dual_stop_bits = false,    \
    .enable_parity_bit = false, \
    .even_parity = false,       \
    .loopback_enable = false    \
}                               \


/**
 * @brief Initializes uart with default settings 
 * and provided baud rate
 * 
 * @param baud_rate baud rate
 */
void serial_init(uint32_t baud_rate);


/**
 * @brief Initializes serial port with given configuration
 * @param cfg pointer to config struct
 */
void serial_set_config(Serial_Config * cfg);


/**
 * @brief Get current serial configuration
 * 
 * @return UART_Config cfg
 */
Serial_Config serial_get_config();


/**
 * @brief Write a chracter to serial port
 * 
 * @param c chaaracter
 * @return int 
 */
void serial_write(char c);


/**
 * @brief Read character from serial port
 * 
 * @return char 
 */
char serial_read();


#endif //__SERIAL_H__