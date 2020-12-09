#include <iostream>
#include <cmath>
#define float double

using namespace std;

void fun(float a,float b)
{
float fl = ((a+b)*(a+b)-(a*a+2*a*b))/(b*b);
double db = 0.3333333333333333333333333333;
cout <<sizeof(db) <<" "<<sizeof(((a+b)*(a+b)-(a*a+2*a*b))/(b*b))<<" "<<fl;
}

int main()
{
float a = 95,b = 0.1;
fun(a,b);
return 0;
}
