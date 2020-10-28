.data
    a: .int 13
    b: .int 21
.global _main
_main:
    push a
    push b
    call _fun3

    addl $2*4, %esp
    xorl %eax, %eax
ret
