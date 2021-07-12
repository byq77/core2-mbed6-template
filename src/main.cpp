#include "mbed.h"
#include <Foo.h>

int main()
{
    Foo foo; // test class

    while(1)
    {
        printf("Hello, Mbed!\n");
        printf("NWD(%d, %d) = %d", foo.getA(), foo.getB(), foo.nwd());
        ThisThread::sleep_for(1s);
    }
    return 0;
}