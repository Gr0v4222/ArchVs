.data
    a: .int 4
    b: .int 4
    c: .int 5
.global _fun4
_fun4:
    mov b, %eax
    imul c, %eax
    mov %eax, %ebp #bc
    add a, %eax
    mov %ebp, %ebx
    neg %ebx
    add a, %ebx
ret
