/*
  Copyright (c) 2015 Atmel Corp./Thibaut VIARD. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ATMEL_SAMR21_XPRO_
#define _VARIANT_ATMEL_SAMR21_XPRO_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"
#include <stdbool.h>

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (30u)
#define NUM_DIGITAL_PINS     (8u)
#define NUM_ANALOG_INPUTS    (1u)
#define NUM_ANALOG_OUTPUTS   (0u)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Interrupts
#define digitalPinToInterrupt(P)   ( g_APinDescription[P].ulExtInt )

// LED(s)
#define PIN_LED_13           (2ul)
#define PIN_LED              PIN_LED_13
#define LED_BUILTIN          PIN_LED_13

// Button(s)
#define PIN_BUTTON           (3ul)
#define PIN_SW0              PIN_BUTTON

/*
 * Analog pins
 */
#define PIN_A0               (12ul)
#define PIN_A1               (13ul)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
#define ADC_RESOLUTION		12

/*
 * Serial interfaces
 */
// Serial
#define PIN_SERIAL_RX        (0ul)
#define PIN_SERIAL_TX        (1ul)
#define PAD_SERIAL_RX        (SERCOM_RX_PAD_1)
#define PAD_SERIAL_TX        (UART_TX_PAD_0)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MOSI         (16ul)
#define PIN_SPI_MISO         (17ul)
#define PIN_SPI_SCK          (18ul)
#define PIN_SPI_SS           (19ul)
#define PERIPH_SPI           sercom5
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0

static const uint8_t SS	  = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SCL         (14ul)
#define PIN_WIRE_SDA         (15ul)
#define PERIPH_WIRE          sercom1
#define WIRE_IT_HANDLER      SERCOM1_Handler

/*
 * USB
 */
#define PIN_USB_DP           (28ul)
#define PIN_USB_DM           (29ul)
#define PIN_USB_HOST_ENABLE  (30ul)
#define PIN_USB_VBUS         PIN_USB_HOST_ENABLE

/*
 * 802.15.4/ATRF233
 */
#define PIN_ATRF233_MOSI    (21ul)
#define PIN_ATRF233_MISO    (22ul)
#define PIN_ATRF233_SCK     (23ul)
#define PIN_ATRF233_SS      (24ul)
#define PERIPH_ATRF233      sercom4
#define PAD_ATRF233_TX      SPI_PAD_2_SCK_3
#define PAD_ATRF233_RX      SERCOM_RX_PAD_0

#define PIN_SPI1_MOSI        PIN_ATRF233_MOSI
#define PIN_SPI1_MISO        PIN_ATRF233_MISO
#define PIN_SPI1_SCK         PIN_ATRF233_SCK
#define PIN_SPI1_SS          PIN_ATRF233_SS
#define PERIPH_SPI1          PERIPH_ATRF233
#define PAD_SPI1_TX          PAD_ATRF233_TX
#define PAD_SPI1_RX          PAD_ATRF233_RX

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
 */
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial

#endif /* _VARIANT_ATMEL_SAMR21_XPRO_ */
