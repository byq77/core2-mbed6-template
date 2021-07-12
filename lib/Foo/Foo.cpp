#include "Foo.h"

int Foo::nwd()
{
    int a = _a, b = _b, c = 0;
    while(b > 0)
    {
        c  = a % b;
        a = b;
        b = c;
    }
    return a;
}

void Foo::blinker()
{
    _led = !_led;
}