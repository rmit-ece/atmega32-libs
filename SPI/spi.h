/**
 *  ATMega32 SPI Library header. 
 *
 *  Provides a C interface to manipulate, read from and write to the SPI bus on an ATMega32
 *  microcontroller as found on the Open USB Platform (OUSB). For more information, see page
 *  132 of the datasheet from Atmel.
 *
 *  Copyright (c) 2019 Jesse Buhagiar and The RMIT ECE Club
 */
#ifndef _SPI_H_INCLUDED_
#define _SPI_H_INCLUDED_

#include <avr/io.h>
#include <stdint.h>
#include <stddef.h>

/**
 *  General I/O Definitions
 */
#define SPI_PORT        PORTB
#define SPI_DIR_PORT    DDRB
#define SPI_SS_PIN      4
#define SPI_MOSI_PIN    5
#define SPI_MISO_PIN    6
#define SPI_SCK_PIN     7

/**
 *  SPCR Defines
 */
#define SPI_INT_ENABLE      (1 << 7)    /**< Enable interrupts for SPI */
#define SPI_ENABLE          (1 << 6)    /**< SPI Enable Bit. Set to 1 to enable SPI on PORTB */
#define DATA_ORDER          (1 << 5)    /**< Data Order Bit. 1 = LSB first, 0 = MSB first */
#define MSTR_SELECT         (1 << 4)    /**< 1 to set this device to a master device */
#define CLOCK_POL           (1 << 3)    /**< Clock polarity pin */
#define CLOCK_PHA           (1 << 2)    /**< Clock phase */

/**
 *  Clock divs
 */
#define FOSC_4      0x00
#define FOSC_16     0x01
#define FOSC_64a    0x02
#define FOSC_128    0x03
#define FOSC_2      0x04
#define FOSC_8      0x05
#define FOSC_32     0x06
#define FOSC_64b    0x07

/**
 *  SPSR Defines
 */
#define TRANSFER_COMPLETE   (1 << 7)
#define WRITE_COL_FLAG      (1 << 6)
#define SCK_2X              (1 << 0)


/**
 *  Initialise the SPI Bus by setting the appropriate ports
 */
void    spi_init(uint8_t clock_div);

/**
 *  Receive a byte from the slave device
 */
uint8_t spi_receive_byte(void);

/**
 *  Send a byte on the SPI Bus
 */
void    spi_send_byte(uint8_t val);

/**
 *  Receive `num` amount of bytes from the slave
 */
void    spi_receive_buff(size_t num, uint8_t* buff);

/**
 *  Send `num` amount of bytes to the slave from the master
 */
void    spi_send_buff(size_t num, uint8_t* buff);


#endif
