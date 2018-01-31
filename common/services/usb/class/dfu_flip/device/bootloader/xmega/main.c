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
#include <util/delay.h>
#include <usart.h>
#include <stdio_serial.h>
#include "conf_usb.h"

#define BLINK_DELAY_MS 500 //delay of blink (in milliseconds)
#define LED_OFF PORTF_OUTCLR //turn off led
#define LED_ON PORTF_OUTSET // turn on led
#define USART_SERIAL &USARTE0

/*! \brief Main function. Execution starts here.
 */
int main(void)
{
    PORTF_DIRSET = 0b01110000; //sets PORT F LEDs to output
    LED_ON =  0b00010000; //Red

	// Map interrupt vectors table in bootloader section
	ccp_write_io((uint8_t*)&PMIC.CTRL, PMIC_IVSEL_bm | PMIC_LOLVLEN_bm
			| PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm);

	sysclk_init();
	cpu_irq_enable();
    
    PORTE_DIRSET = 0b00001000; //Set PortE TX direction out
    static usart_rs232_options_t USART_SERIAL_OPTIONS = {
       .baudrate = 115200,
       .charlength = USART_CHSIZE_8BIT_gc,
       .paritytype = USART_PMODE_DISABLED_gc,
       .stopbits = false,  //false == 1 stop bit
    };
    sysclk_enable_module(SYSCLK_PORT_E, PR_USART0_bm);
    stdio_serial_init(USART_SERIAL, &USART_SERIAL_OPTIONS);
    printf("\r\nBooting...\r\n");

    LED_OFF = 0b00010000; //Off
    LED_ON =  0b00100000; //turns on LED 0

	// Start USB stack to authorize VBus monitoring
	udc_start();

	while (true) {
        printf("L");
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
