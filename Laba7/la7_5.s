.global _init
_init:
    movl 4(%esp), %esi 
    movl $0, %ebx 
    movl $0, %ecx 
_re:
    movl 4(%esp), 
    addl %ecx, %eax
    movl %ebx, (%eax)
    cmpl 8(%esp),%eax
    jz _end
    addl 12(%esp),%ebx
    addl $4, %ecx
    jmp _re
_end:
    ret
