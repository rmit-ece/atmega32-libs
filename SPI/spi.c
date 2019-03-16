/**
 *  Implementation of spi.h
 *
 *  Copyright (c) 2019 Jesse Buhagiar and The RMIT ECE Club
 */
#include "spi.h"



void spi_init(uint8_t clock_div)
{
   if(clock_div > FOSC_64b)
       return;

   SPI_DIR_PORT = (1 << SPI_MOSI_PIN) | (1 << SPI_SCK_PIN); // Set up the OSUB as the master device
   SPCR = SPI_ENABLE | MSTR_SELECT;
}

uint8_t spi_receive_byte(void)
{
    /**
     *  This code looks like it never returns, HOWEVER, the hardware
     *  will modifiy SPSR for us, meaning this will complete when
     *  a transfer complete signal is done by the Hardware itself.
     */
    while(!(SPSR & TRANSFER_COMPLETE));

    return SPDR;
}

void spi_send_byte(uint8_t val)
{
    SPDR = val;

    while(!(SPSR & TRANSFER_COMPLETE));
}

void spi_receive_buff(size_t num, uint8_t* buff)
{
    for(size_t i = 0; i < num; i++)
        *(buff + i) = spi_receive_byte();
}

void spi_send_buff(size_t num, uint8_t* buff)
{
    for(size_t i = 0; i < num; i++)
        spi_send_byte(*(buff + i));
}
