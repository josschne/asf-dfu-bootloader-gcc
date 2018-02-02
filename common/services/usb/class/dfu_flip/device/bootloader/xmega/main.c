/**
 * \file
 *
 * \brief Main functions
 *
 * Copyright (c) 2011-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <stdio.h>
#include <util/delay.h>
#include <usart.h>
#include <serial.h>
#include "conf_usb.h"

#define BLINK_DELAY_MS 500 //delay of blink (in milliseconds)
#define LED_OFF PORTF_OUTCLR //turn off led
#define LED_ON PORTF_OUTSET // turn on led
#define USART_SERIAL &USARTE0

int stdout_putchar(char c, FILE* f);

extern volatile void *volatile stdio_base;
extern int (*ptr_put)(void volatile*, char);
static FILE debug_console = FDEV_SETUP_STREAM((int(*)(char, FILE*))stdout_putchar, NULL, _FDEV_SETUP_WRITE);

#define PRINT_ISR(x) \
    ISR(x, ISR_NAKED) { puts(#x); while(1); }

// PRINT_ISR(OSC_OSCF_vect);
// PRINT_ISR(PORTC_INT0_vect);
// PRINT_ISR(PORTC_INT1_vect);
// PRINT_ISR(PORTR_INT0_vect);
// PRINT_ISR(PORTR_INT1_vect);
// PRINT_ISR(DMA_CH0_vect);
// PRINT_ISR(DMA_CH1_vect);
// PRINT_ISR(RTC_OVF_vect);
// PRINT_ISR(TWIC_TWIS_vect);
// PRINT_ISR(TWIC_TWIM_vect);
// PRINT_ISR(TCC0_OVF_vect);
// PRINT_ISR(TCC0_ERR_vect);
// PRINT_ISR(TCC0_CCA_vect);
// PRINT_ISR(TCC0_CCB_vect);
// PRINT_ISR(TCC0_CCC_vect);
// PRINT_ISR(TCC0_CCD_vect);
// PRINT_ISR(TCC1_OVF_vect);
// PRINT_ISR(TCC1_ERR_vect);
// PRINT_ISR(TCC1_CCA_vect);
// PRINT_ISR(TCC1_CCB_vect);
// PRINT_ISR(SPIC_INT_vect);
// PRINT_ISR(USARTC0_RXC_vect);
// PRINT_ISR(USARTC0_DRE_vect);
// PRINT_ISR(USARTC0_TXC_vect);
// PRINT_ISR(USARTC1_RXC_vect);
// PRINT_ISR(USARTC1_DRE_vect);
// PRINT_ISR(USARTC1_TXC_vect);
// PRINT_ISR(AES_INT_vect);
// PRINT_ISR(NVM_EE_vect);
// PRINT_ISR(NVM_SPM_vect);
// PRINT_ISR(PORTB_INT0_vect);
// PRINT_ISR(PORTB_INT1_vect);
// PRINT_ISR(PORTE_INT0_vect);
// PRINT_ISR(PORTE_INT1_vect);
// PRINT_ISR(TWIE_TWIS_vect);
// PRINT_ISR(TWIE_TWIM_vect);
// PRINT_ISR(TCE0_OVF_vect);
// PRINT_ISR(TCE0_ERR_vect);
// PRINT_ISR(TCE0_CCA_vect);
// PRINT_ISR(TCE0_CCB_vect);
// PRINT_ISR(TCE0_CCC_vect);
// PRINT_ISR(TCE0_CCD_vect);
// PRINT_ISR(USARTE0_RXC_vect);
// PRINT_ISR(USARTE0_DRE_vect);
// PRINT_ISR(USARTE0_TXC_vect);
// PRINT_ISR(PORTD_INT0_vect);
// PRINT_ISR(PORTD_INT1_vect);
// PRINT_ISR(PORTA_INT0_vect);
// PRINT_ISR(PORTA_INT1_vect);
// PRINT_ISR(ACA_AC0_vect);
// PRINT_ISR(ACA_AC1_vect);
// PRINT_ISR(ACA_ACW_vect);
// PRINT_ISR(ADCA_CH0_vect);
// PRINT_ISR(TCD0_ERR_vect);
// PRINT_ISR(TCD0_CCA_vect);
// PRINT_ISR(TCD0_CCB_vect);
// PRINT_ISR(TCD0_CCC_vect);
// PRINT_ISR(TCD0_CCD_vect);
// PRINT_ISR(TCD0_OVF_vect);
// PRINT_ISR(SPID_INT_vect);
// PRINT_ISR(USARTD0_RXC_vect);
// PRINT_ISR(USARTD0_DRE_vect);
// PRINT_ISR(USARTD0_TXC_vect);
// PRINT_ISR(PORTF_INT0_vect);
// PRINT_ISR(PORTF_INT1_vect);
// PRINT_ISR(TCF0_OVF_vect);
// PRINT_ISR(TCF0_ERR_vect);
// PRINT_ISR(TCF0_CCA_vect);
// PRINT_ISR(TCF0_CCB_vect);
// PRINT_ISR(TCF0_CCC_vect);
// PRINT_ISR(TCF0_CCD_vect);


int stdout_putchar(char c, FILE* f)
{
    while (usart_data_register_is_empty(USART_SERIAL) == false) {
    }
    
    (USART_SERIAL)->DATA = c;
    return STATUS_OK;
}

void stdout_put8(uint8_t val)
{
    static uint8_t hex_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    putc(hex_chars[(val >> 4)], stdout);
    putc(hex_chars[(val & 0x0F)], stdout);
}

ISR(BADISR_vect)
{
    puts("BI:");
    stdout_put8(PMIC.STATUS);
}

int usart_init() {
    PORTE_OUTSET = 0b00001000; //Set PortE TX pin high
    PORTE_DIRSET = 0b00001000; //Set PortE TX direction out
    static usart_rs232_options_t USART_SERIAL_OPTIONS = {
       .baudrate = 115200,
       .charlength = USART_CHSIZE_8BIT_gc,
       .paritytype = USART_PMODE_DISABLED_gc,
       .stopbits = false,  //false == 1 stop bit
    };
    sysclk_enable_module(SYSCLK_PORT_E, PR_USART0_bm);
    usart_serial_init(USART_SERIAL,&USART_SERIAL_OPTIONS);
    stdout = &debug_console; 
}


/*! \brief Main function. Execution starts here.
 */
int main(void)
{
    PORTF_DIRSET = 0b01110000; //sets PORT F LEDs to output
    LED_ON =  0b00010000; //Red

    // Map interrupt vectors table in bootloader section
#ifdef PLACE_IN_BOOTLOADER_MEM
    ccp_write_io((uint8_t*)&PMIC.CTRL, PMIC_IVSEL_bm | PMIC_LOLVLEN_bm
            | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm);
#else
    pmic_init();
#endif

    sysclk_init();
    cpu_irq_enable();
    usart_init();

    puts("\r\nBooting... \r\n");
    stdout_put8(RST.STATUS);
    RST.STATUS = RST.STATUS; //Clear reset bits

    _delay_ms(1000);
    LED_OFF = 0b00010000; //Off

	// Start USB stack to authorize VBus monitoring
	udc_start();

	while (true) {
        puts("L");
        LED_ON =  0b01000000; //turns on LED 0
        _delay_ms (BLINK_DELAY_MS);
        LED_OFF = 0b01000000; //turns off LED 0
        _delay_ms (BLINK_DELAY_MS);
	}
}


/**
 * \mainpage ASF USB Device DFU
 *
 * \section intro Introduction
 * This application is the official Atmel USB DFU bootloader for XMEGA.
 *
 * A USB DFU bootloader guide is proposed for all AVR XMEGA parts with USB interface:
 *
 * \section files Application Files
 * The specific files of application are:
 * - main.c: the main file to start clock and USB DFU Device.
 * - specific linker script
 * - specific optimized codes to fit with boot section size
 */
