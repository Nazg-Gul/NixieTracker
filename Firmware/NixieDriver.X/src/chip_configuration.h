/* Copyright (C) 2014 Sergey Sharybin <sergey@blender.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef __CHIP_CONFIGURATION__
#define __CHIP_CONFIGURATION__

/* Ensure we have the correct target PIC device family */
#if !defined(__18F5550) && !defined(__18F2550)
#  error "This firmware only was tested on PIC18F2550 microcontrollers and should work on PIC18F4550."
#endif

/* PIC18F4550/PIC18F2550 configuration for the WFF Generic HID test device */
#pragma config PLLDIV   = 5         /* 20Mhz external oscillator */
#pragma config CPUDIV   = OSC1_PLL2
#pragma config USBDIV   = 2         /* Clock source from 96MHz PLL/2 */
#pragma config FOSC     = HSPLL_HS
#pragma config FCMEN    = OFF
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BOR      = ON
#pragma config BORV     = 3
#pragma config VREGEN   = ON
#pragma config WDT      = OFF
#pragma config WDTPS    = 32768
#pragma config MCLRE    = ON
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF
/* #pragma config CCP2MX   = ON */
#pragma config STVREN   = ON
#pragma config LVP      = OFF
/* #pragma config ICPRT    = OFF */
#pragma config XINST    = OFF
#pragma config CP0      = OFF
#pragma config CP1      = OFF
/* #pragma config CP2      = OFF */
/* #pragma config CP3      = OFF */
#pragma config CPB      = OFF
/* #pragma config CPD      = OFF */
#pragma config WRT0     = OFF
#pragma config WRT1     = OFF
/* #pragma config WRT2     = OFF */
/* #pragma config WRT3     = OFF */
#pragma config WRTB     = OFF
#pragma config WRTC     = OFF
/* #pragma config WRTD     = OFF */
#pragma config EBTR0    = OFF
#pragma config EBTR1    = OFF
/* #pragma config EBTR2    = OFF */
/* #pragma config EBTR3    = OFF */
#pragma config EBTRB    = OFF

#endif  /* __CHIP_CONFIGURATION__ */
