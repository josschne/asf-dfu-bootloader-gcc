/**
 * \file
 *
 * \brief Autogenerated API include file for the Atmel Software Framework (ASF)
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
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

#ifndef ASF_H
#define ASF_H

/*
 * This file includes all API header files for the selected drivers from ASF.
 * Note: There might be duplicate includes required by more than one driver.
 *
 * The file is automatically generated and will be re-written when
 * running the ASF driver selector tool. Any changes will be discarded.
 */

// From module: ADC - Analog-to-digital Converter
#include <adc.h>

// From module: Atmel QTouch Library 5.0 for Atmel SAM4S devices
#include <touch_api.h>

// From module: Atmel QTouch Library for QTouch Method in SAM devices
#include <touch_qt_config.h>

// From module: Common SAM compiler driver
#include <compiler.h>
#include <status_codes.h>

// From module: Delay routines
#include <delay.h>

// From module: Display - AAT31XX Backlight Controller
#include <aat31xx.h>

// From module: Display - ADS7843 Touch Controller
#include <ads7843.h>

// From module: Display - Generic Resistive Touch Service
#include <rtouch.h>
#include <rtouch_ads7843.h>

// From module: Display - ILI93xx LCD Controller
#include <ili9325_regs.h>
#include <ili9341_regs.h>
#include <ili93xx.h>

// From module: EEFC - Enhanced Embedded Flash Controller
#include <efc.h>

// From module: FatFS file system
#include <diskio.h>
#include <ff.h>
#include <ffconf.h>
#include <integer.h>

// From module: Flash - SAM Flash Service API
#include <flash_efc.h>

// From module: FreeRTOS mini Real-Time Kernel
#include <FreeRTOS.h>
#include <StackMacros.h>
#include <croutine.h>
#include <list.h>
#include <mpu_wrappers.h>
#include <portable.h>
#include <projdefs.h>
#include <queue.h>
#include <semphr.h>
#include <task.h>
#include <timers.h>

// From module: GFX Color - Color Graphic Library
#include <gfx.h>

// From module: GFX Color - System Font
#include <sysfont.h>

// From module: GPIO - General purpose Input/Output
#include <gpio.h>

// From module: Generic board support
#include <board.h>

// From module: Graphical Widget Library Toolkit
#include <win.h>
#include <wtk.h>

// From module: IOPORT - General purpose I/O service
#include <ioport.h>

// From module: Interrupt management - SAM implementation
#include <interrupt.h>

// From module: MATRIX - Bus Matrix
#include <matrix.h>

// From module: MEMBAG Memory Bag Allocator
#include <membag.h>

// From module: Memory Control Access Interface
#include <ctrl_access.h>

// From module: NAND Flash on EBI
#include <nand_flash_common.h>
#include <nand_flash_ecc.h>
#include <nand_flash_management.h>
#include <nand_flash_mem.h>
#include <nand_flash_model.h>
#include <nand_flash_raw.h>
#include <nand_flash_spare_scheme.h>
#include <nand_flash_translation.h>

// From module: PDC - Peripheral DMA Controller Example
#include <pdc.h>

// From module: PIO - Parallel Input/Output Controller
#include <pio.h>

// From module: PMC - Power Management Controller
#include <pmc.h>
#include <sleep.h>

// From module: Part identification macros
#include <parts.h>

// From module: QT600 QDebug enabled
#include <BitBangSPI_Master.h>
#include <QDebug.h>
#include <QDebugTransport.h>

// From module: RTC - Real Time Clock
#include <rtc.h>

// From module: SAM4S EK LED support enabled
#include <led.h>

// From module: SMC - Static Memory Controller
#include <smc.h>

// From module: SPI - SAM Implementation
#include <spi_master.h>
#include <spi_master.h>

// From module: SPI - Serial Peripheral Interface
#include <spi.h>

// From module: SUPC - Supply Controller
#include <supc.h>

// From module: Sleep manager - SAM implementation
#include <sam/sleepmgr.h>
#include <sleepmgr.h>

// From module: Standard serial I/O (stdio) - SAM implementation
#include <stdio_serial.h>

// From module: Supported ports of FatFS
#include <diskio.h>

// From module: System Clock Control - SAM4S implementation
#include <sysclk.h>

// From module: TC - Timer Counter
#include <tc.h>

// From module: UART - Univ. Async Rec/Trans
#include <uart.h>

// From module: USART - Serial interface - SAM implementation for devices with both UART and USART
#include <serial.h>

// From module: USART - Univ. Syn Async Rec/Trans
#include <usart.h>

// From module: USB Device MSC (Single Interface Device)
#include <udi_msc.h>

// From module: USB Device Stack Core (Common API)
#include <udc.h>
#include <udd.h>

// From module: USB MSC Protocol
#include <usb_protocol_msc.h>

// From module: WDT - Watchdog Timer
#include <wdt.h>

// From module: pio_handler support enabled
#include <pio_handler.h>

#endif // ASF_H
