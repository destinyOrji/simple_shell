	.file	"prompt.c"
	.text
	.section	.rodata
.LC0:
	.string	"$ "
	.text
	.globl	display_prompt
	.type	display_prompt, @function
display_prompt:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %edi
	call	isatty@PLT
	testl	%eax, %eax
	je	.L3
	movl	$2, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	call	write@PLT
.L3:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	display_prompt, .-display_prompt
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
