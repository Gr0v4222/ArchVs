#include <stdio.h>

extern "C" void fun3(int a, int b)
{
    printf("Function\'s params:\na:: %d \nb:: %d",a,b);
}
