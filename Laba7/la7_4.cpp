#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct strc
{
	int key;
	int value;
};
int main()
{
	srand(13);
	int N = 0;
	cin >> N;
	struct strc * Array = new struct strc[N];
	for (int i = 0; i < N; i++)
	{
		Array[i].key = rand() % 10 + 1;
		Array[i].value = rand() % (40) + 1;
		printf("Key = %d, Val = %d\n", Array[i].key, Array[i].value);
	}
	int key = 4;
	int Max = 0;
	asm(
		"movl $1, %%eax\n\t"
		"movl $0, %%ebx\n\t"
		"movl $0, %%eax\n\t"
		"Start:\n\t"
		"cmpl %[N], %%eax\n\t"
		"je Exit\n\t"
		"movl %[intArray], %%ecx\n\t"
		"leal (%%ecx, %%eax, 8), %%ecx\n\t"
		"movl (%%ecx),%%ecx\n\t"
		"cmpl %[key],%%ecx\n\t"
		"jne notkey\n\t"
		"movl %[intArray], %%ecx\n\t"
		"leal 4(%%ecx, %%eax, 8), %%ecx\n\t"
		"movl (%%ecx),%%ecx\n\t"
		"cmpl %%ebx, %%ecx\n\t"
		"jc lable\n\t"
		"movl %%ecx, %%ebx\n\t"
		"lable:\n\t"
		"notkey: \n\t"
		"incl %%eax\n\t"
		"jmp Start\n\t"
		"Exit:\n\t"
		"movl %%ebx, %[Max]\n\t"
		: [Max]"+m" (Max)
		: [intArray]"m" (Array), [N]"m"(N), [key]"m"(key)
		: "cc", "%eax", "%ebx", "%ecx"
	);
	cout << endl;
	if (Max == 0)
		cout << "Array not have elemts for key: " << key;
	else
		cout << "max: " << Max;
	cout << endl;
	delete[] Array;
	return 0;
}
