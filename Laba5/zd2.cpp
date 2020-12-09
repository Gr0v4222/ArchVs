#include <iostream>
#include <cmath>

using namespace std;

extern "C" double calc(double x);
int main()
{
double x = 3;
cout << calc(x) << endl;
cout << (x*x-1)*3.88+1.5<<endl;
return 0;
}
