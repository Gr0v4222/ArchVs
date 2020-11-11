
#include <iostream>
using namespace std;
int main()
{
// задание 1
int p1;
int p2;
cout<<"a+b=?\n";
cout<<"Enter a:\n";
cin>>p1;
cout<<"Enter b:\n";
cin>>p2;

asm (
"addl %[Src],%[Dest]\n\t"
: [Dest]"+r" (p1)
: [Src]"r" (p2)
: "cc"
);
asm goto (
"jo %l2"
:: [Dest]"r" (p1), [Src]"r" (p2)
: "cc"
: carry
);

cout << "\nTrue " <<p1<< endl;
if(0)
{
carry:
cout << "\nFalse " <<p1<< endl;
}
return 0;
}
