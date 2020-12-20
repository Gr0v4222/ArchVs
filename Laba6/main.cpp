#include <iostream>
using namespace std;
int main()
{
int i=4;
float sum;
float x = 2, y;
asm(
"fld1 \n"
"fld1 \n"
"begin: \n"
"sub $1,%[i] \n"
"jz end\n"
"fld %[X]\n"
"fdivrp %%st(1) \n"
"fadd %%st(0),%%st(1)\n"
"jmp begin\n"
"end: \n"
"fstp %[sum]\n"
"fstp %[sum]\n"
"ffree %%st(0)\n"
"ffree %%st(0)\n"
:[sum]"=m"(y),[i]"+r"(i)
:[X]"m"(x)
:"cc"
);
cout << y;
return 0; }
