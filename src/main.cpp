/* mbed Microcontroller Library
 * Copyright (c) 2021 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalOut led(LED1);

int main()
{
    while(1)
    {
        printf("Hello, Mbed!\n");
        led = !led;
        ThisThread::sleep_for(1s);
    }
    return 0;
}