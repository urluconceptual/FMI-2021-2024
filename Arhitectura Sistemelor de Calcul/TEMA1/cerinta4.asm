.data
	str: .space 2000
	matrice: .space 2000
	matrice1: .space 2000
	chdelim: .asciz " "
	formatscanf: .asciz "%[^\n]s"
	formatprintf: .asciz "%d "
	final: .asciz "\n"
	res: .space 4
	x: .long 0
	n: .long 0
	cn: .long 0
	m: .long 0
	cod: .long 0
	var: .space 5
	op: .long 0
	letok: .long 0
	i: .long 1
	minus: .long -1
	rotire: .long 0
.text
.global main
main:
	movl $matrice, %esi

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

	pushl $chdelim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx

	pushl %eax
	call atoi
	popl %ebx
	movl %eax, n
	
	pushl $chdelim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx

	pushl %eax
	call atoi
	popl %ebx
	movl %eax, m
	
	xorl %edx, %edx
	movl n, %ebx
	mull %ebx
	movl %eax, x
	
	xorl %ebx, %ebx
et_for:
	pushl %ebx

	pushl $chdelim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
bfor:
	popl %ebx

	cmp $0, %eax
	je main1

	pushl %ebx
	
	movl %eax, res
	pushl %eax
	call atoi
	popl %ebx
bfor1:
	popl %ebx

	cmp $0, %eax
	je decizie
	
	cmp $1, letok
	je letop
adaugmatrice:
	movl %eax, (%esi, %ebx, 4)
	incl %ebx
	
	jmp et_for
decizie:
	cmp x, %ebx
	jl adaugmatrice
	jmp operatie
operatie:
	movl res, %edi
	xorl %ecx, %ecx
	xorl %edx, %edx
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
	cmp $114, %dl
	je instrrot
	jmp et_for
instrlet:
	movl $1, letok
	jmp et_for
letop:
	movl %eax, op
	jmp et_for
instradd:
	movl $1, cod
	jmp et_for
instrsub:
	movl $2, cod
	jmp et_for
instrmul:
	movl $3, cod
	jmp et_for
instrdiv:
	movl $4, cod
	jmp et_for
instrrot:
	movl $5, cod
	jmp et_for
main1:
	xorl %ecx, %ecx
	movl $matrice1, %edi
	pushl n
	popl cn
	decl n
	movl n, %eax
	movl %eax, rotire
et_for1:
	cmp x, %ecx
	je afis
	
	cmp $1, cod
	je foradd
	cmp $2, cod
	je forsub
	cmp $3, cod
	je formul
	cmp $4, cod
	je fordiv
	cmp $5, cod
	je forrot
foradd:
	movl op, %eax
	addl %eax, (%esi, %ecx, 4)
	jmp cont
forsub:
	movl op, %eax
	subl %eax, (%esi, %ecx, 4)
	jmp cont
formul:
	movl (%esi, %ecx, 4), %eax
	xorl %edx, %edx
	mull op
	movl %eax, (%esi, %ecx, 4)
	jmp cont
fordiv:
	movl (%esi, %ecx, 4), %eax
	
	cmp $0, op
	jl negative
	
	xorl %edx, %edx
	divl op
	movl %eax, (%esi, %ecx, 4)
	jmp cont
negative:
	cmp $0, %eax
	jl negative1
	
	pushl op
	pushl %eax
	movl op, %eax
	mull minus
	movl %eax, op
	popl %eax
	
	xorl %edx, %edx
	divl op
	mull minus
	movl %eax, (%esi, %ecx, 4)
	popl op
	jmp cont
negative1:
	mull minus
	
	pushl op
	pushl %eax
	movl op, %eax
	mull minus
	movl %eax, op
	popl %eax
	
	xorl %edx, %edx
	divl op
	movl %eax, (%esi, %ecx, 4)
	popl op
	jmp cont
forrot:
	pushl %ecx
	movl (%esi, %ecx, 4), %ebx
	xorl %edx, %edx
	movl rotire, %ecx
	movl %ebx, (%edi, %ecx, 4)
	popl %ecx

	movl m, %ebx
	cmp i, %ebx
	je resetare
	jmp cont
resetare:
	incl %ecx
	movl $1, i
	decl n
	movl n, %eax
	movl %eax, rotire
	jmp et_for1	
cont:
	incl %ecx
	incl i
	movl cn, %eax
	addl %eax, rotire
	jmp et_for1	
afis:
	cmp $5, cod
	je afis2
	jmp afis1
afis1:
	pushl cn
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx

	pushl m
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx

	xorl %ecx, %ecx

	jmp forafis1
afis2:
	pushl m
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx

	pushl cn
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx

	pushl $0
	call fflush
	popl %ebx

	xorl %ecx, %ecx

	jmp forafis2
forafis1:
	pushl %ecx

	cmp x, %ecx
	je exit
	
	pushl (%esi, %ecx, 4)
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx
		
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx

	incl %ecx
	jmp forafis1
forafis2:
	pushl %ecx
	
	cmp x, %ecx
	je exit
	
	pushl (%edi, %ecx, 4)
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx

	incl %ecx
	jmp forafis2
exit:
	movl $4, %eax
	movl $1, %ebx
	movl $final, %ecx
	movl $2, %edx
	int $0x80
	
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
