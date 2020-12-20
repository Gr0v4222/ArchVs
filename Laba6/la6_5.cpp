#include <iostream>
using namespace std;
int main()
{
int x = 3, y = 23;
int R;
asm (
"xor %%eax,%%eax\n"
"mov $0x10,%%ecx \n" //;число разрядов
"a0: \n"
"cmp $0,%[X] \n" //;X сдвигается до тех пор, пока в нем
"jz a3 \n" //;есть единицы
"shr $1,%[X] \n" //;//сдвигаем X вправо и проверяем
"jnc a2 \n" //;есть ли в очередном разряде единица
"add %[Y],%%eax \n" //;если есть -- складываем
"a2: \n"
"add %[Y],%[Y] \n" //;увеличиваем Y в два раза
"loop a0 \n" //;пока не обработаем все 16 разряд
"a3:\n"
"movl %%eax, %[R]\n"
: [R]"=m" (R),[X]"+r" (x),[Y]"+r"(y)
:
: "cc","%ecx","%eax"
);
cout << R <<endl;
return 0;
}
