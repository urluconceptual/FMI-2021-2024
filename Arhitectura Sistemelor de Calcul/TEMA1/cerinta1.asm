.data
	instr: .space 100
	sirb16: .space 100
	sirb2: .space 400
	formatscanf: .asciz "%s"
	formatprintf: .asciz "%s\n"
	index: .long 0
	i: .long 0
	id: .long 0
	suma: .long 0
	zece: .long 10
	suta: .long 100
.text
.global main
main:
	pushl $sirb16
	pushl $formatscanf
	call scanf
	popl %ebx
	popl %ebx

	movl $sirb16, %edi
	movl $sirb2, %esi
	xorl %ecx, %ecx
et_for:
	movb (%edi, %ecx, 1), %al
	cmp $0, %al
	je main2

	cmp $48, %al
	je cif0
	cmp $49, %al
	je cif1
	cmp $50, %al
	je cif2
	cmp $51, %al
	je cif3
	cmp $52, %al
	je cif4
	cmp $53, %al
	je cif5
	cmp $54, %al
	je cif6
	cmp $55, %al
	je cif7
	cmp $56, %al
	je cif8
	cmp $57, %al
	je cif9
	cmp $65, %al
	je litA
	cmp $66, %al
	je litB
	cmp $67, %al
	je litC
	cmp $68, %al
	je litD
	cmp $69, %al
	je litE
	cmp $70, %al
	je litF
cont:
	incl %ecx
	jmp et_for
cif0:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif1:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif2:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif3:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif4:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif5:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif6:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif7:
	pushl %ecx
	movl index, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif8:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
cif9:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
litA:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
litB:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
litC:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
litD:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
litE:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
litF:
	pushl %ecx
	movl index, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx
	jmp cont
main2:
	movl $sirb2, %edi
	movl $instr, %esi
	xorl %ecx, %ecx
	movl $0, index
et_for1:
	cmp $12, i
	je codare

	movb (%edi, %ecx, 1), %al
	cmp $0, %al
	je exit

	cmp $0, i
	je cont1
	cmp $1, i
	je b1
	cmp $2, i
	je b2
	cmp $3, i
	je b3
	cmp $4, i
	je b4
	cmp $5, i
	je b5
	cmp $6, i
	je b6
	cmp $7, i
	je b7
	cmp $8, i
	je b8
	cmp $9, i
	je b9
	cmp $10, i
	je b10
	cmp $11, i
	je b11
cont1:
	incl %ecx
	incl i
	jmp et_for1
et_i:
	movl $0, i
	movl $0, suma
	movl $0, id
	jmp et_for1
b1:
	cmp $49, %al
	je operatie
	jmp cont1
operatie:
	movl $2, id
	jmp cont1
b2:
	cmp $2, id
	je cont1
	cmp $49, %al
	je variabila
	movl $0, id
	jmp cont1
variabila:
	movl $1, id
	jmp cont1
b3:
	cmp $49, %al
	je negativ
	jmp cont1
negativ:
	pushl %ecx
	movl index, %ecx
	movl $45, (%esi, %ecx, 1)
	incl %ecx
	addl $1, index
	popl %ecx
	jmp cont1
b4:
	cmp $49, %al
	je sapte
	jmp cont1
sapte:
	addl $128, suma
	jmp cont1
b5:
	cmp $49, %al
	je sase
	jmp cont1
sase:
	addl $64, suma
	jmp cont1
b6:
	cmp $49, %al
	je cinci
	jmp cont1
cinci:
	addl $32, suma
	jmp cont1
b7:
	cmp $49, %al
	je patru
	jmp cont1
patru:
	addl $16, suma
	jmp cont1
b8:
	cmp $49, %al
	je trei
	jmp cont1
trei:
	addl $8, suma
	jmp cont1
b9:
	cmp $49, %al
	je doi
	jmp cont1
doi:
	addl $4, suma
	jmp cont1
b10:
	cmp $49, %al
	je unu
	jmp cont1
unu:
	addl $2, suma
	jmp cont1
b11:
	cmp $49, %al
	je zero
	jmp cont1
zero:
	addl $1, suma
	jmp cont1
codare:
	cmp $0, id
	je cod_numar
	cmp $1, id
	je cod_variabila
	cmp $2, id
	je cod_operatie

cod_numar:
	cmp $9, suma
	jg cod_numar1

	movl $48, %ebx
	addl suma, %ebx

	pushl %ecx
	movl index, %ecx
	movl %ebx, (%esi, %ecx, 1)
	incl %ecx
	movl $32, (%esi, %ecx, 1)
	incl %ecx
	addl $2, index
	popl %ecx

	jmp et_i
cod_numar1:
	cmp $99, suma
	jg cod_numar2

	movl $48, %ebx
	movl suma, %eax
	xorl %edx, %edx
	divl zece
	addl %eax, %ebx
	movl %edx, suma
	
	pushl %ecx
	movl index, %ecx
	movl %ebx, (%esi, %ecx, 1)
	incl %ecx
	addl $1, index
	popl %ecx

	jmp cod_numar
cod_numar2:
	movl $48, %ebx
	movl suma, %eax
	xorl %edx, %edx
	divl suta
	addl %eax, %ebx
	movl %edx, suma

	pushl %ecx
	movl index, %ecx
	movl %ebx, (%esi, %ecx, 1)
	incl %ecx
	addl $1, index
	popl %ecx

	jmp cod_numar1
cod_variabila:
	movl suma, %ebx

	pushl %ecx
	movl index, %ecx
	movl %ebx, (%esi, %ecx, 1)
	incl %ecx
	movl $32, (%esi, %ecx, 1)
	incl %ecx
	addl $2, index
	popl %ecx

	jmp et_i
cod_operatie:
	cmp $0, suma
	je instrlet
	cmp $1, suma
	je instradd
	cmp $2, suma
	je instrsub
	cmp $3, suma
	je instrmul
	cmp $4, suma
	je instrdiv
instrlet:
	pushl %ecx
	movl index, %ecx
	movl $108, (%esi, %ecx, 1)
	incl %ecx
	movl $101, (%esi, %ecx, 1)
	incl %ecx
	movl $116, (%esi, %ecx, 1)
	incl %ecx
	movl $32, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx

	jmp et_i
instradd:
	pushl %ecx
	movl index, %ecx
	movl $97, (%esi, %ecx, 1)
	incl %ecx
	movl $100, (%esi, %ecx, 1)
	incl %ecx
	movl $100, (%esi, %ecx, 1)
	incl %ecx
	movl $32, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx

	jmp et_i
instrsub:
	pushl %ecx
	movl index, %ecx
	movl $115, (%esi, %ecx, 1)
	incl %ecx
	movl $117, (%esi, %ecx, 1)
	incl %ecx
	movl $98, (%esi, %ecx, 1)
	incl %ecx
	movl $32, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx

	jmp et_i
instrmul:
	pushl %ecx
	movl index, %ecx
	movl $109, (%esi, %ecx, 1)
	incl %ecx
	movl $117, (%esi, %ecx, 1)
	incl %ecx
	movl $108, (%esi, %ecx, 1)
	incl %ecx
	movl $32, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx

	jmp et_i
instrdiv:
	pushl %ecx
	movl index, %ecx
	movl $100, (%esi, %ecx, 1)
	incl %ecx
	movl $105, (%esi, %ecx, 1)
	incl %ecx
	movl $118, (%esi, %ecx, 1)
	incl %ecx
	movl $32, (%esi, %ecx, 1)
	incl %ecx
	addl $4, index
	popl %ecx

	jmp et_i	
exit:
	pushl $instr
	pushl $formatprintf
	call printf
	pop %ebx
	pop %ebx

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
