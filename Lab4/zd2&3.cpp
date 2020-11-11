#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main ()
{
    for(int i = 0; i < 30; i++){
        int f1=i;
        asm (
                "shr $2, %[f1]\n\t"
                "shl $2, %[f1]\n\t"
                "imul $-1, %[f1]\n\t"
                //:[f1]"+r"(f1)
            );
        cout << "x: " << i << "\tC++: " << (i%4-i) << "\tAsm: " << f1 << endl;
    }
    return 0;
}
