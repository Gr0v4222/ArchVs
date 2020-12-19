.data
printf_format:
    .string "f = %d\n"
x:
    .int 1
y:
    .int 2
.globl _main
_main:
    movl x, %eax
    add y,%eax
    add $-4,%eax
    cmpl $0, %eax
    jg _s2
    movl x, %eax
    jmp _end
_s2:
    movl y, %eax
    add $2,%eax
_end:
    pushl %eax
    pushl $printf_format
    call _printf
    addl $8, %esp
    movl $0, %eax
ret
