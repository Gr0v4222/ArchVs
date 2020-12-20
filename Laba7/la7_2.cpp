#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	srand(87);
	int N = 0;
	cin >> N;
	int * intArray = new int[N];
	cout << "Sizeof int = " << sizeof(intArray[0]) << endl;
	cout << "Arr: ";
	intArray[0] = rand() % N;
	cout << intArray[0];
	for (int i = 1; i < N; i++)
	{
		intArray[i] = rand() % N;
		cout << "," << intArray[i];
	}
	cout << "\n";
	int Max = 0;
	asm(
		"movl $1, %%eax\n\t"
		"movl %[intArray], %%ebx\n\t"
		"movl (%%ebx), %%ebx\n\t"
		"Start:\n\t"
		"cmpl %[N], %%eax\n\t"
		"je Exit\n\t"
		"movl %[intArray], %%ecx\n\t"
		"leal (%%ecx, %%eax, 4), %%ecx\n\t"
		"movl (%%ecx),%%ecx\n\t"
		"cmpl %%ebx, %%ecx\n\t"
		"jc lable\n\t"
		"movl %%ecx, %%ebx\n\t"
		"lable:\n\t"
		"incl %%eax\n\t"
		"jmp Start\n\t"
		"Exit:\n\t"
		"movl %%ebx, %[Max]\n\t"
		: [Max]"+m" (Max)
		: [intArray]"m" (intArray), [N]"m"(N)
		: "cc", "%eax", "%ebx", "%ecx"
	);
	cout << "max: " << Max;
	delete[] intArray;
	return 0;
}
