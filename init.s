.global _init
_init:
    movl 4(%esp), %esi //Адрес начального элемента
    movl $0, %ebx //Счетчик для шагов
    movl $0, %ecx //Счетчик для ячеек
_re:
    movl 4(%esp), %eax //Текущий адрес
    addl %ecx, %eax
    movl %ebx, (%eax)
    cmpl 8(%esp),%eax
    jz _end
    addl 12(%esp),%ebx
    addl $4, %ecx
    jmp _re
_end:
    ret
