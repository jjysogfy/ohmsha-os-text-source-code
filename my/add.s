	.file	"add.c"
	.intel_syntax noprefix
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	endbr64
	lea	eax, [rdi+rsi]
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	mov	eax, DWORD PTR x[rip]
	add	eax, DWORD PTR y[rip]
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.globl	msg
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"hello"
	.section	.data.rel.local,"aw"
	.align 8
	.type	msg, @object
	.size	msg, 8
msg:
	.quad	.LC0
	.globl	y
	.bss
	.align 4
	.type	y, @object
	.size	y, 4
y:
	.zero	4
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	10
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
