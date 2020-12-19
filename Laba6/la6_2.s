.data
printf_format:
    .string "f = %f\n"
x:
    .double 1
y:
    .double 0
a:
    .double -1.28
.globl _main
_main:
    fldl x //Загружаем x
    ftst //Сравниваем x с нулем
    fstsw %ax //Сохраняем текущее значение регистра SR в приемник
    sahf //Загружаем флаги для сравнения
    jbe _s2
    fldl a
    faddp
    jmp _end
_s2:
    fldz
_end:
    fstpl (y)
    pushl (y+4)
    pushl (y)
    push $printf_format
    call _printf
    add $12, %esp
ret
