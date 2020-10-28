.global _fun1
_fun1:
    mov %ecx, %eax
    shr $2, %eax
    shl $2, %eax
    imul $-1, %eax
ret
