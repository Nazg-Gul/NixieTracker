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

#include "app_nixie_status.h"

#include <stdint.h>
#include <system.h>
#include <usb/usb_device.h>

static unsigned char digit_0 = 0,
                     digit_1 = 0,
                     digit_2 = 0;
static unsigned char current_digit = 0;

void APP_NixieUpdateStatus(void) {
#define FALL_TIME 50
#define RAISE_AND_DUTY_TIME 10
    if (current_digit == 0) {
      DIG_GATE_CLOSE(2);
      __delay_us(FALL_TIME);
      BIN_CODE_SEND_DIGIT(digit_0);
      DIG_GATE_OPEN(0);
      current_digit = 1;
    } else if (current_digit == 1) {
      DIG_GATE_CLOSE(0);
      __delay_us(FALL_TIME);
      BIN_CODE_SEND_DIGIT(digit_1);
      DIG_GATE_OPEN(1);
      current_digit = 2;
    } else if (current_digit == 2) {
      /* We do check here to balance the ticks counter. */
      DIG_GATE_CLOSE(1);
      __delay_us(FALL_TIME);
      BIN_CODE_SEND_DIGIT(digit_2);
      DIG_GATE_OPEN(2);
      current_digit = 0;
    }
  __delay_us(RAISE_AND_DUTY_TIME);
#undef FALL_TIME
#undef RAISE_AND_DUTY_TIME
}

void APP_NixieSetDigits(unsigned char a,
                        unsigned char b,
                        unsigned char c) {
  digit_0 = a;
  digit_1 = b;
  digit_2 = c;
}