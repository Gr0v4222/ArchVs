#include <iostream>
using namespace std;
int main()
{
int x = 3, y = 23;
int R;
asm (
"xor %%eax,%%eax\n"
"mov $0x10,%%ecx \n" //;����� ��������
"a0: \n"
"cmp $0,%[X] \n" //;X ���������� �� ��� ���, ���� � ���
"jz a3 \n" //;���� �������
"shr $1,%[X] \n" //;//�������� X ������ � ���������
"jnc a2 \n" //;���� �� � ��������� ������� �������
"add %[Y],%%eax \n" //;���� ���� -- ����������
"a2: \n"
"add %[Y],%[Y] \n" //;����������� Y � ��� ����
"loop a0 \n" //;���� �� ���������� ��� 16 ������
"a3:\n"
"movl %%eax, %[R]\n"
: [R]"=m" (R),[X]"+r" (x),[Y]"+r"(y)
:
: "cc","%ecx","%eax"
);
cout << R <<endl;
return 0;
}
