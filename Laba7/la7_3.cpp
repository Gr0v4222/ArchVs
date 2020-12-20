#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct strc
{
	int key;
	double value;
};
int main()
{
	srand(10);
	int N;
	cin >> N;
	struct strc * Array = new struct strc[N];
	for (int i = 0; i < N; i++)
	{
		Array[i].key = rand() % (N / 2);
		Array[i].value = (rand() % 1000) / (double)100;
		printf("Key = %d, Val = %.3f\n", Array[i].key, Array[i].value);
	}
	printf("\nSizeOf: \n struct: %d\n key (int): %d\n val (double): %d\n",sizeof(Array[0]),sizeof(Array[0].key),sizeof(Array[0].value));
		delete[] Array;
	return 0;
}
