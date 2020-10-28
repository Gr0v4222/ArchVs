.data
    msg: .string "x=%d, y=%d\n"

.global _main
_main:
    call _fun4
    push %ebx
    push %eax
    push $msg
    call _printf
    addl $4*4, %esp
ret
