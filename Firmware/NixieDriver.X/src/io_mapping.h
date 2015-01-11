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

#ifndef __IO_MAPPING_H__
#define __IO_MAPPING_H__

/* We've optimized the routes on PCB, so now we suffer in the firmware by
 * writing to the individual bits
 */

/* Decimal code which is passed to the digital decoder. */
// RIP one of the IO pins...
#define BIN_CODE_0 PORTBbits.RB1
//#define BIN_CODE_0 PORTAbits.RA5
#define BIN_CODE_1 PORTCbits.RC7
#define BIN_CODE_2 PORTCbits.RC6
#define BIN_CODE_3 PORTBbits.RB0

#define BIN_CODE_SEND_CODE(a, b, c, d) { \
    BIN_CODE_0 = a; \
    BIN_CODE_1 = b; \
    BIN_CODE_2 = c; \
    BIN_CODE_3 = d; \
  } (void) 0

#define BIN_CODE_SEND_DIGIT(digit) { \
    BIN_CODE_SEND_CODE(digit & 1, \
                       (digit >> 1) & 1, \
                       (digit >> 2) & 1, \
                       (digit >> 3) & 1);\
  } (void) 0

#define BIN_CODE_SEND_CLOSE() \
  BIN_CODE_SEND_CODE(1, 1, 1, 1)

/* Digit number, for multiplexing, defines which transistor gate is open. */
// RIP one more of the IO pins...
#define DIG_GATE_0 PORTBbits.RB2
//#define DIG_GATE_0 PORTBbits.RB5
#define DIG_GATE_1 PORTBbits.RB3
#define DIG_GATE_2 PORTBbits.RB4

#define DIG_GATE_OPEN(gate) DIG_GATE_ ## gate = 1
#define DIG_GATE_CLOSE(gate) DIG_GATE_ ## gate = 0

#endif  /* __IO_MAPPING_H__ */
