.data
	str: .space 100
	chdelim: .asciz " "
	formatscanf: .asciz "%[^\n]s"
	formatprintf: .asciz "%d\n"
	res: .space 5
	x: .long 0
	var: .space 5
	dict: .long 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
.text
.global main
main:
	pushl $str
	pushl $formatscanf
	call scanf
	popl %ebx
	popl %ebx

	pushl $chdelim
	pushl $str
	call strtok
	popl %ebx
	popl %ebx

	movl $dict, %esi

	movl %eax, res
	pushl %eax
	call atoi
	popl %ebx
comparare:
	cmp $0, %eax
	je variabila
	pushl %eax

et_for:
	pushl $chdelim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx

	cmp $0, %eax
	je afis

	movl %eax, res
	pushl %eax
	call atoi
	popl %ebx

	cmp $0, %eax
	je operatie
	pushl %eax
	
	jmp et_for
operatie:
	pushl res
	call strlen
	popl %ebx
operatie1:
	cmp $1, %eax
	je variabila

	movl res, %edi
	xorl %ecx, %ecx
	movb (%edi, %ecx, 1), %dl
	cmp $97, %dl
	je instradd
	cmp $115, %dl
	je instrsub
	cmp $109, %dl
	je instrmul
	cmp $100, %dl
	je instrdiv
	cmp $108, %dl
	je instrlet
variabila:
	movl res, %edi
	xorl %ecx, %ecx
	xorl %edx, %edx
	movb (%edi, %ecx, 1), %dl
	sub $97, %edx
	movl (%esi, %edx, 4), %eax
	cmp $0, %eax
	jg inlocuire
	pushl %edx
	jmp et_for
inlocuire:
	pushl (%esi, %edx, 4)
	jmp et_for
instrlet:
	popl %ebx
	popl %edx
	movl %ebx, (%esi, %edx, 4)
	jmp et_for
instradd:
	popl x
	popl %ebx
	addl x, %ebx
	pushl %ebx
	jmp et_for
instrsub:
	popl x
	popl %ebx
	subl x, %ebx
	pushl %ebx
	jmp et_for
instrmul:
	popl x
	popl %ebx
	movl x, %eax
	xorl %edx, %edx
	mull %ebx
	pushl %eax
	jmp et_for
instrdiv:
	popl %ebx
	popl x
	movl x, %eax
	xorl %edx, %edx
	divl %ebx
	pushl %eax
	jmp et_for
afis:
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx
exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
