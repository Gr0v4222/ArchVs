#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
unsigned int ASCIINumber = 0x31;
unsigned int result;

asm (
    "and $0x0F, %0"
    : "=r" (result)
    : "0" (ASCIINumber)
    );

cout<<"'"<<result<<"'"<<endl;

unsigned int number = 0x09;
asm (
    "xor $0x21, %0"
    : "=r" (ASCIINumber)
    : "0" (number) );
cout<<"'"<<ASCIINumber<<"'"<<endl;
return 0;
}

