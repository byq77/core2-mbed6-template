#pragma once
#define BLINK_INTERVAL 500ms

#include "mbed.h"

class Foo final
{
public:
    Foo(int a, int b) : _a(a), _b(b), _led(LED1)
    {
        _ticker.attach(callback(this, &Foo::blinker), BLINK_INTERVAL);
    }

    Foo() : Foo(100, 20) {}

    int getA() { return _a; }
    int getB() { return _b; }
    int nwd();

private:
    void blinker();
    int _a;
    int _b;
    DigitalOut _led;
    Ticker _ticker;
};