#include <iostream>
#include <stdlib.h>
using namespace std;
extern “C” void init(int* var, int* varEnd, int step);

int main()
{
int step = 7;
int varSize = 20;
cin >> step;
cin >> varSize;
int* var = new int[varSize];
init(&(var[0]),&(var[varSize-1]),step);
for (int i=0;i<varSize;i++)
{
cout<<”[“<<i<<”]”<<” = “<<var[i]<<endl;
}
delete[] var;
return 0;
}
