.data
input: .string "%d"
output: .string "a[%d]=%d\n"
inputN: .string "Введите N: "
inputX: .string "Введите X: "
x:
.int 0
n:
.int 0
i:
.int -1
a:
.int 0
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $40, %esp
movl $inputX, (%esp)
call printf
leal 36(%esp), %eax
movl %eax, 4(%esp)
movl $input, (%esp)
call scanf
movl -4(%ebp), %eax
movl %eax, x
movl %ebp, %esp
popl %ebp
pushl %ebp
movl %esp, %ebp
subl $40, %esp
movl $inputN, (%esp)
call printf
leal 36(%esp), %eax
movl %eax, 4(%esp)
movl $input, (%esp)
call scanf
movl -4(%ebp), %eax
movl %eax, n
movl %ebp, %esp
popl %ebp
begin_iteration:
cmpl $0,n
je end_loop
addl $-1, n
addl $1, i
end_iteration:
push a
push a
push i
push $output
call printf
addl $16, %esp
movl x, %eax
addl %eax, a
jmp begin_iteration
end_loop:
ret
