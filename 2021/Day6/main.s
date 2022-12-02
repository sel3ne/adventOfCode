	.file	"main.cpp"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1517:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1517:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.text
	.p2align 4
	.type	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, @function
_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0:
.LFB5766:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	240(%rdi,%rax), %r12
	testq	%r12, %r12
	je	.L9
	cmpb	$0, 56(%r12)
	movq	%rdi, %rbp
	je	.L5
	movsbl	67(%r12), %esi
.L6:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rax, %rdi
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	_ZNSo5flushEv@PLT
.L5:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	movl	$10, %esi
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L6
	movl	$10, %esi
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L6
.L9:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE5766:
	.size	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, .-_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	" "
	.text
	.p2align 4
	.globl	_Z11printVectorSt6vectorIiSaIiEE
	.type	_Z11printVectorSt6vectorIiSaIiEE, @function
_Z11printVectorSt6vectorIiSaIiEE:
.LFB4642:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	leaq	.LC0(%rip), %r13
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	leaq	_ZSt4cout(%rip), %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	movq	(%rdi), %rbx
	movq	8(%rdi), %r12
	cmpq	%rbx, %r12
	je	.L15
	.p2align 4,,10
	.p2align 3
.L14:
	movl	(%rbx), %esi
	movq	%rbp, %rdi
	addq	$4, %rbx
	call	_ZNSolsEi@PLT
	movl	$1, %edx
	movq	%r13, %rsi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	cmpq	%rbx, %r12
	jne	.L14
.L15:
	movq	_ZSt4cout(%rip), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %r12
	testq	%r12, %r12
	je	.L24
	cmpb	$0, 56(%r12)
	je	.L16
	movsbl	67(%r12), %esi
.L17:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rax, %rdi
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	jmp	_ZNSo5flushEv@PLT
	.p2align 4,,10
	.p2align 3
.L16:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	movl	$10, %esi
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L17
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L17
.L24:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE4642:
	.size	_Z11printVectorSt6vectorIiSaIiEE, .-_Z11printVectorSt6vectorIiSaIiEE
	.section	.text._ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev,"axG",@progbits,_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev
	.type	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev, @function
_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev:
.LFB5041:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	8(%rdi), %rbx
	movq	(%rdi), %rbp
	cmpq	%rbp, %rbx
	je	.L26
	.p2align 4,,10
	.p2align 3
.L30:
	movq	0(%rbp), %rdi
	leaq	16(%rbp), %rax
	cmpq	%rax, %rdi
	je	.L27
	movq	16(%rbp), %rax
	addq	$32, %rbp
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
	cmpq	%rbp, %rbx
	jne	.L30
.L29:
	movq	(%r12), %rbp
.L26:
	testq	%rbp, %rbp
	je	.L25
	movq	16(%r12), %rsi
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbp, %rdi
	subq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	_ZdlPvm@PLT
	.p2align 4,,10
	.p2align 3
.L27:
	.cfi_restore_state
	addq	$32, %rbp
	cmpq	%rbp, %rbx
	jne	.L30
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L25:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE5041:
	.size	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev, .-_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev
	.weak	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev
	.set	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev,_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev
	.section	.rodata._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_.str1.1,"aMS",@progbits,1
.LC1:
	.string	"vector::_M_realloc_insert"
	.section	.text._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.type	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, @function
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB5383:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movq	%rdx, %r15
	movabsq	$2305843009213693951, %rdx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	8(%rdi), %r12
	movq	(%rdi), %r14
	movq	%r12, %rax
	subq	%r14, %rax
	sarq	$2, %rax
	cmpq	%rdx, %rax
	je	.L48
	testq	%rax, %rax
	movl	$1, %edx
	movq	%rdi, %rbp
	movq	%rsi, %r13
	cmovne	%rax, %rdx
	xorl	%ecx, %ecx
	addq	%rdx, %rax
	movq	%rsi, %rdx
	setc	%cl
	subq	%r14, %rdx
	testq	%rcx, %rcx
	jne	.L45
	testq	%rax, %rax
	jne	.L38
	xorl	%ebx, %ebx
	xorl	%edi, %edi
.L44:
	movl	(%r15), %eax
	leaq	4(%rdi,%rdx), %r8
	subq	%r13, %r12
	movq	%rdi, %xmm0
	movq	16(%rbp), %r15
	movl	%eax, (%rdi,%rdx)
	leaq	(%r8,%r12), %rax
	movq	%rax, %xmm1
	punpcklqdq	%xmm1, %xmm0
	movaps	%xmm0, (%rsp)
	testq	%rdx, %rdx
	jg	.L49
	testq	%r12, %r12
	jg	.L40
	testq	%r14, %r14
	jne	.L43
.L41:
	movdqa	(%rsp), %xmm2
	movq	%rbx, 16(%rbp)
	movups	%xmm2, 0(%rbp)
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L49:
	.cfi_restore_state
	movq	%r14, %rsi
	movq	%r8, 24(%rsp)
	call	memmove@PLT
	testq	%r12, %r12
	movq	24(%rsp), %r8
	jg	.L40
.L43:
	movq	%r15, %rsi
	movq	%r14, %rdi
	subq	%r14, %rsi
	call	_ZdlPvm@PLT
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L40:
	movq	%r12, %rdx
	movq	%r13, %rsi
	movq	%r8, %rdi
	call	memcpy@PLT
	testq	%r14, %r14
	je	.L41
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L45:
	movabsq	$9223372036854775804, %rbx
.L37:
	movq	%rbx, %rdi
	movq	%rdx, (%rsp)
	call	_Znwm@PLT
	movq	(%rsp), %rdx
	movq	%rax, %rdi
	addq	%rax, %rbx
	jmp	.L44
	.p2align 4,,10
	.p2align 3
.L38:
	movabsq	$2305843009213693951, %rcx
	cmpq	%rcx, %rax
	cmova	%rcx, %rax
	leaq	0(,%rax,4), %rbx
	jmp	.L37
.L48:
	leaq	.LC1(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
	.cfi_endproc
.LFE5383:
	.size	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, .-_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.section	.text._ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_,"axG",@progbits,_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_,comdat
	.p2align 4
	.weak	_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_
	.type	_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_, @function
_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_:
.LFB5452:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	cmpq	%rsi, %rdi
	je	.L50
	.p2align 4,,10
	.p2align 3
.L54:
	movq	(%rbx), %rdi
	leaq	16(%rbx), %rax
	cmpq	%rax, %rdi
	je	.L52
	movq	16(%rbx), %rax
	addq	$32, %rbx
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
	cmpq	%rbx, %rbp
	jne	.L54
.L50:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L52:
	.cfi_restore_state
	addq	$32, %rbx
	cmpq	%rbx, %rbp
	jne	.L54
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE5452:
	.size	_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_, .-_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_
	.section	.rodata._ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"basic_string::_M_construct null not valid"
	.section	.text._ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_,"axG",@progbits,_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_
	.type	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_, @function
_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_:
.LFB5238:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA5238
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movq	%rdx, %rcx
	movabsq	$288230376151711743, %rdx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	8(%rdi), %r12
	movq	(%rdi), %r13
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movq	%r12, %rax
	subq	%r13, %rax
	sarq	$5, %rax
	cmpq	%rdx, %rax
	je	.L103
	testq	%rax, %rax
	movl	$1, %edx
	movq	%rsi, %r15
	movq	%rdi, %r14
	cmovne	%rax, %rdx
	movq	%rsi, %rbp
	movq	%rsi, %rbx
	addq	%rdx, %rax
	setc	%dl
	movq	%rax, 24(%rsp)
	subq	%r13, %r15
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L85
	testq	%rax, %rax
	jne	.L61
	movq	$0, 16(%rsp)
.L83:
	addq	16(%rsp), %r15
	movq	(%rcx), %rax
	leaq	16(%r15), %rdi
	movq	%r15, (%rsp)
	movq	%rdi, (%r15)
	movq	8(%rcx), %r15
	movq	%rdi, 32(%rsp)
	movq	%rax, %rdi
	addq	%r15, %rdi
	movq	%rax, 40(%rsp)
	je	.L62
	testq	%rax, %rax
	je	.L104
.L62:
	movq	%r15, 48(%rsp)
	cmpq	$15, %r15
	ja	.L105
	cmpq	$1, %r15
	jne	.L65
	movq	40(%rsp), %rax
	movq	(%rsp), %rdi
	movzbl	(%rax), %eax
	movb	%al, 16(%rdi)
.L66:
	movq	(%rsp), %rax
	movq	%r15, 8(%rax)
	movq	32(%rsp), %rax
	movb	$0, (%rax,%r15)
	cmpq	%r13, %rbp
	je	.L86
	movq	%rbp, %rdi
	movq	16(%rsp), %rdx
	movq	%r13, %rax
	subq	%r13, %rdi
	.p2align 4,,10
	.p2align 3
.L71:
	leaq	16(%rdx), %rcx
	leaq	16(%rax), %rsi
	movq	%rcx, (%rdx)
	movq	(%rax), %rcx
	cmpq	%rsi, %rcx
	je	.L106
	movq	%rcx, (%rdx)
	movq	16(%rax), %rcx
	addq	$32, %rax
	addq	$32, %rdx
	movq	%rcx, -16(%rdx)
	movq	-24(%rax), %rcx
	movq	%rcx, -24(%rdx)
	cmpq	%rbp, %rax
	jne	.L71
.L70:
	movq	16(%rsp), %rax
	leaq	(%rax,%rdi), %rsi
.L67:
	addq	$32, %rsi
	cmpq	%r12, %rbp
	je	.L72
	movq	%r12, %rdi
	movq	%rsi, %rax
	subq	%rbp, %rdi
	.p2align 4,,10
	.p2align 3
.L76:
	leaq	16(%rax), %rdx
	leaq	16(%rbx), %rcx
	movq	%rdx, (%rax)
	movq	(%rbx), %rdx
	cmpq	%rcx, %rdx
	je	.L107
	movq	%rdx, (%rax)
	movq	16(%rbx), %rdx
	addq	$32, %rbx
	addq	$32, %rax
	movq	%rdx, -16(%rax)
	movq	-24(%rbx), %rdx
	movq	%rdx, -24(%rax)
	cmpq	%r12, %rbx
	jne	.L76
.L75:
	addq	%rdi, %rsi
.L72:
	movq	16(%rsp), %xmm0
	movq	%rsi, %xmm3
	punpcklqdq	%xmm3, %xmm0
	testq	%r13, %r13
	je	.L77
	movq	16(%r14), %rsi
	movq	%r13, %rdi
	movaps	%xmm0, (%rsp)
	subq	%r13, %rsi
	call	_ZdlPvm@PLT
	movdqa	(%rsp), %xmm0
.L77:
	movq	16(%rsp), %rax
	addq	24(%rsp), %rax
	movups	%xmm0, (%r14)
	movq	%rax, 16(%r14)
	movq	56(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L108
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L65:
	.cfi_restore_state
	testq	%r15, %r15
	je	.L66
	movq	32(%rsp), %rdi
	jmp	.L64
	.p2align 4,,10
	.p2align 3
.L107:
	movdqu	16(%rbx), %xmm2
	movq	8(%rbx), %rdx
	addq	$32, %rbx
	addq	$32, %rax
	movups	%xmm2, -16(%rax)
	movq	%rdx, -24(%rax)
	cmpq	%rbx, %r12
	jne	.L76
	jmp	.L75
	.p2align 4,,10
	.p2align 3
.L106:
	movdqu	16(%rax), %xmm1
	movq	8(%rax), %rcx
	addq	$32, %rax
	addq	$32, %rdx
	movups	%xmm1, -16(%rdx)
	movq	%rcx, -24(%rdx)
	cmpq	%rax, %rbp
	jne	.L71
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L85:
	movabsq	$9223372036854775776, %rax
	movq	%rax, 24(%rsp)
	movq	%rax, %rdi
.L60:
	movq	%rcx, (%rsp)
.LEHB0:
	call	_Znwm@PLT
.LEHE0:
	movq	(%rsp), %rcx
	movq	%rax, 16(%rsp)
	jmp	.L83
	.p2align 4,,10
	.p2align 3
.L105:
	movq	(%rsp), %rdi
	leaq	48(%rsp), %rsi
	xorl	%edx, %edx
.LEHB1:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.LEHE1:
	movq	(%rsp), %rsi
	movq	%rax, %rdi
	movq	%rax, (%rsi)
	movq	48(%rsp), %rax
	movq	%rax, 16(%rsi)
.L64:
	movq	40(%rsp), %rsi
	movq	%r15, %rdx
	call	memcpy@PLT
	movq	(%rsp), %rax
	movq	48(%rsp), %r15
	movq	(%rax), %rax
	movq	%rax, 32(%rsp)
	jmp	.L66
	.p2align 4,,10
	.p2align 3
.L86:
	movq	16(%rsp), %rsi
	jmp	.L67
.L61:
	movq	%rax, %rdi
	movabsq	$288230376151711743, %rax
	cmpq	%rax, %rdi
	cmovbe	%rdi, %rax
	salq	$5, %rax
	movq	%rax, 24(%rsp)
	movq	%rax, %rdi
	jmp	.L60
.L108:
	call	__stack_chk_fail@PLT
.L103:
	leaq	.LC1(%rip), %rdi
.LEHB2:
	call	_ZSt20__throw_length_errorPKc@PLT
.LEHE2:
.L104:
	leaq	.LC2(%rip), %rdi
.LEHB3:
	call	_ZSt19__throw_logic_errorPKc@PLT
.LEHE3:
.L87:
	movq	%rax, %rdi
.L78:
	call	__cxa_begin_catch@PLT
	cmpq	$0, 16(%rsp)
	je	.L109
	movq	16(%rsp), %rbx
	movq	%rbx, %rsi
	movq	%rbx, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_
	movq	24(%rsp), %rsi
	movq	%rbx, %rdi
	call	_ZdlPvm@PLT
.L81:
.LEHB4:
	call	__cxa_rethrow@PLT
.LEHE4:
.L109:
	movq	(%rsp), %rax
	movq	(%rax), %rdi
	cmpq	%rdi, 32(%rsp)
	je	.L81
	movq	16(%rax), %rsi
	addq	$1, %rsi
	call	_ZdlPvm@PLT
	jmp	.L81
.L88:
	movq	%rax, %rbp
.L82:
	call	__cxa_end_catch@PLT
	movq	%rbp, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
	.cfi_endproc
.LFE5238:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_,"aG",@progbits,_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_,comdat
	.align 4
.LLSDA5238:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT5238-.LLSDATTD5238
.LLSDATTD5238:
	.byte	0x1
	.uleb128 .LLSDACSE5238-.LLSDACSB5238
.LLSDACSB5238:
	.uleb128 .LEHB0-.LFB5238
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB5238
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L87-.LFB5238
	.uleb128 0x1
	.uleb128 .LEHB2-.LFB5238
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB5238
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L87-.LFB5238
	.uleb128 0x1
	.uleb128 .LEHB4-.LFB5238
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L88-.LFB5238
	.uleb128 0
	.uleb128 .LEHB5-.LFB5238
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE5238:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT5238:
	.section	.text._ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_,"axG",@progbits,_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_,comdat
	.size	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_, .-_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_
	.section	.rodata.str1.1
.LC3:
	.string	"input.txt"
.LC4:
	.string	"Unable to open file"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB5:
	.text
.LHOTB5:
	.p2align 4
	.globl	_Z9readInputB5cxx11v
	.type	_Z9readInputB5cxx11v, @function
_Z9readInputB5cxx11v:
.LFB4624:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA4624
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$616, %rsp
	.cfi_def_cfa_offset 672
	movq	%fs:40, %rax
	movq	%rax, 600(%rsp)
	xorl	%eax, %eax
	leaq	336(%rsp), %r14
	leaq	64(%rsp), %rax
	movq	$0, 56(%rsp)
	movq	%r14, %rdi
	movq	%rax, 8(%rsp)
	leaq	80(%rsp), %r15
	movq	%rax, 48(%rsp)
	movb	$0, 64(%rsp)
	movq	%r14, 16(%rsp)
	call	_ZNSt8ios_baseC2Ev@PLT
	leaq	16+_ZTVSt9basic_iosIcSt11char_traitsIcEE(%rip), %rax
	pxor	%xmm0, %xmm0
	xorl	%esi, %esi
	movq	%rax, 336(%rsp)
	xorl	%eax, %eax
	movq	16+_ZTTSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rbx
	movw	%ax, 560(%rsp)
	movq	8+_ZTTSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rax
	movups	%xmm0, 568(%rsp)
	movups	%xmm0, 584(%rsp)
	movq	%rax, 80(%rsp)
	movq	-24(%rax), %rax
	movq	$0, 552(%rsp)
	movq	%rbx, 80(%rsp,%rax)
	movq	8+_ZTTSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rax
	movq	$0, 88(%rsp)
	movq	-24(%rax), %rdi
	addq	%r15, %rdi
.LEHB6:
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE4initEPSt15basic_streambufIcS1_E@PLT
.LEHE6:
	leaq	24+_ZTVSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rax
	leaq	96(%rsp), %rbx
	movq	%rax, 80(%rsp)
	movq	%rbx, %rdi
	addq	$40, %rax
	movq	%rax, 336(%rsp)
.LEHB7:
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEEC1Ev@PLT
.LEHE7:
	movq	%rbx, %rsi
	movq	%r14, %rdi
.LEHB8:
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE4initEPSt15basic_streambufIcS1_E@PLT
	movl	$8, %edx
	leaq	.LC3(%rip), %rsi
	movq	%rbx, %rdi
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode@PLT
	movq	80(%rsp), %rdx
	movq	-24(%rdx), %rdi
	addq	%r15, %rdi
	testq	%rax, %rax
	je	.L159
	xorl	%esi, %esi
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.LEHE8:
.L112:
	movq	$0, 16(%r13)
	leaq	200(%rsp), %rax
	pxor	%xmm0, %xmm0
	movups	%xmm0, 0(%r13)
	movq	%rax, %rdi
	movq	%rax, 24(%rsp)
	call	_ZNKSt12__basic_fileIcE7is_openEv@PLT
	testb	%al, %al
	je	.L113
	.p2align 4,,10
	.p2align 3
.L158:
	movq	80(%rsp), %rax
	movq	-24(%rax), %rax
	movq	320(%rsp,%rax), %rbp
	testq	%rbp, %rbp
	je	.L160
	cmpb	$0, 56(%rbp)
	je	.L127
	movsbl	67(%rbp), %edx
.L128:
	leaq	48(%rsp), %r12
	movq	%r15, %rdi
	movq	%r12, %rsi
.LEHB9:
	call	_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EES4_@PLT
	movq	(%rax), %rdx
	movq	-24(%rdx), %rdx
	testb	$5, 32(%rax,%rdx)
	jne	.L161
	movq	8(%r13), %rbp
	cmpq	16(%r13), %rbp
	je	.L119
	leaq	16(%rbp), %rdi
	movq	56(%rsp), %r12
	movq	%rdi, 0(%rbp)
	movq	48(%rsp), %r14
	movq	%r14, %rax
	addq	%r12, %rax
	je	.L120
	testq	%r14, %r14
	je	.L162
.L120:
	movq	%r12, 40(%rsp)
	cmpq	$15, %r12
	ja	.L163
	cmpq	$1, %r12
	jne	.L123
	movzbl	(%r14), %eax
	movb	%al, 16(%rbp)
.L124:
	movq	%r12, 8(%rbp)
	movb	$0, (%rdi,%r12)
	addq	$32, 8(%r13)
	jmp	.L158
	.p2align 4,,10
	.p2align 3
.L127:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movl	$10, %edx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L128
	movl	$10, %esi
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %edx
	jmp	.L128
	.p2align 4,,10
	.p2align 3
.L119:
	movq	%r12, %rdx
	movq	%rbp, %rsi
	movq	%r13, %rdi
	call	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_
	jmp	.L158
	.p2align 4,,10
	.p2align 3
.L123:
	testq	%r12, %r12
	je	.L124
	jmp	.L122
	.p2align 4,,10
	.p2align 3
.L163:
	leaq	40(%rsp), %rsi
	xorl	%edx, %edx
	movq	%rbp, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
	movq	%rax, 0(%rbp)
	movq	%rax, %rdi
	movq	40(%rsp), %rax
	movq	%rax, 16(%rbp)
.L122:
	movq	%r12, %rdx
	movq	%r14, %rsi
	call	memcpy@PLT
	movq	40(%rsp), %r12
	movq	0(%rbp), %rdi
	jmp	.L124
	.p2align 4,,10
	.p2align 3
.L161:
	movq	%rbx, %rdi
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT
.LEHE9:
	testq	%rax, %rax
	je	.L164
.L130:
	leaq	24+_ZTVSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rax
	movq	%rbx, %rdi
	movq	%rax, 80(%rsp)
	addq	$40, %rax
	movq	%rax, 336(%rsp)
	leaq	16+_ZTVSt13basic_filebufIcSt11char_traitsIcEE(%rip), %rax
	movq	%rax, 96(%rsp)
.LEHB10:
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT
.LEHE10:
.L134:
	movq	24(%rsp), %rdi
	call	_ZNSt12__basic_fileIcED1Ev@PLT
	leaq	16+_ZTVSt15basic_streambufIcSt11char_traitsIcEE(%rip), %rax
	leaq	152(%rsp), %rdi
	movq	%rax, 96(%rsp)
	call	_ZNSt6localeD1Ev@PLT
	movq	8+_ZTTSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rax
	movq	16(%rsp), %rdi
	movq	16+_ZTTSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rcx
	movq	%rax, 80(%rsp)
	movq	-24(%rax), %rax
	movq	%rcx, 80(%rsp,%rax)
	leaq	16+_ZTVSt9basic_iosIcSt11char_traitsIcEE(%rip), %rax
	movq	$0, 88(%rsp)
	movq	%rax, 336(%rsp)
	call	_ZNSt8ios_baseD2Ev@PLT
	movq	48(%rsp), %rdi
	cmpq	8(%rsp), %rdi
	je	.L110
	movq	64(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L110:
	movq	600(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L165
	addq	$616, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r13, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L113:
	.cfi_restore_state
	movl	$19, %edx
	leaq	.LC4(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB11:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.LEHE11:
	jmp	.L130
	.p2align 4,,10
	.p2align 3
.L159:
	movl	32(%rdi), %esi
	orl	$4, %esi
.LEHB12:
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.LEHE12:
	jmp	.L112
	.p2align 4,,10
	.p2align 3
.L164:
	movq	80(%rsp), %rax
	movq	-24(%rax), %rdi
	addq	%r15, %rdi
	movl	32(%rdi), %esi
	orl	$4, %esi
.LEHB13:
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
	jmp	.L130
.L160:
	call	_ZSt16__throw_bad_castv@PLT
.L165:
	call	__stack_chk_fail@PLT
.L162:
	leaq	.LC2(%rip), %rdi
	call	_ZSt19__throw_logic_errorPKc@PLT
.LEHE13:
.L139:
	movq	%rax, %rbp
	jmp	.L135
.L142:
	movq	%rax, %rbp
	jmp	.L115
.L140:
	movq	%rax, %rbp
	jmp	.L117
.L141:
	movq	%rax, %rbp
	jmp	.L116
.L143:
	movq	%rax, %rdi
	jmp	.L133
	.section	.gcc_except_table,"a",@progbits
	.align 4
.LLSDA4624:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT4624-.LLSDATTD4624
.LLSDATTD4624:
	.byte	0x1
	.uleb128 .LLSDACSE4624-.LLSDACSB4624
.LLSDACSB4624:
	.uleb128 .LEHB6-.LFB4624
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L140-.LFB4624
	.uleb128 0
	.uleb128 .LEHB7-.LFB4624
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L141-.LFB4624
	.uleb128 0
	.uleb128 .LEHB8-.LFB4624
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L142-.LFB4624
	.uleb128 0
	.uleb128 .LEHB9-.LFB4624
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L139-.LFB4624
	.uleb128 0
	.uleb128 .LEHB10-.LFB4624
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L143-.LFB4624
	.uleb128 0x1
	.uleb128 .LEHB11-.LFB4624
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L139-.LFB4624
	.uleb128 0
	.uleb128 .LEHB12-.LFB4624
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L142-.LFB4624
	.uleb128 0
	.uleb128 .LEHB13-.LFB4624
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L139-.LFB4624
	.uleb128 0
.LLSDACSE4624:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT4624:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC4624
	.type	_Z9readInputB5cxx11v.cold, @function
_Z9readInputB5cxx11v.cold:
.LFSB4624:
.L135:
	.cfi_def_cfa_offset 672
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movq	%r13, %rdi
	call	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev
	movq	%r15, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@PLT
.L118:
	movq	48(%rsp), %rdi
	cmpq	8(%rsp), %rdi
	je	.L136
	movq	64(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L136:
	movq	%rbp, %rdi
.LEHB14:
	call	_Unwind_Resume@PLT
.LEHE14:
.L115:
	movq	%rbx, %rdi
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEED1Ev@PLT
.L116:
	movq	8+_ZTTSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rax
	movq	16+_ZTTSt14basic_ifstreamIcSt11char_traitsIcEE(%rip), %rbx
	movq	%rax, 80(%rsp)
	movq	-24(%rax), %rax
	movq	%rbx, 80(%rsp,%rax)
	movq	$0, 88(%rsp)
.L117:
	movq	16(%rsp), %rdi
	leaq	16+_ZTVSt9basic_iosIcSt11char_traitsIcEE(%rip), %rax
	movq	%rax, 336(%rsp)
	call	_ZNSt8ios_baseD2Ev@PLT
	jmp	.L118
.L133:
	call	__cxa_begin_catch@PLT
	call	__cxa_end_catch@PLT
	jmp	.L134
	.cfi_endproc
.LFE4624:
	.section	.gcc_except_table
	.align 4
.LLSDAC4624:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATTC4624-.LLSDATTDC4624
.LLSDATTDC4624:
	.byte	0x1
	.uleb128 .LLSDACSEC4624-.LLSDACSBC4624
.LLSDACSBC4624:
	.uleb128 .LEHB14-.LCOLDB5
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
.LLSDACSEC4624:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATTC4624:
	.section	.text.unlikely
	.text
	.size	_Z9readInputB5cxx11v, .-_Z9readInputB5cxx11v
	.section	.text.unlikely
	.size	_Z9readInputB5cxx11v.cold, .-_Z9readInputB5cxx11v.cold
.LCOLDE5:
	.text
.LHOTE5:
	.section	.rodata.str1.1
.LC6:
	.string	","
.LC7:
	.string	"basic_string_view::substr"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC8:
	.string	"%s: __pos (which is %zu) > __size (which is %zu)"
	.section	.rodata.str1.1
.LC9:
	.string	"vector::_M_range_insert"
	.section	.rodata.str1.8
	.align 8
.LC10:
	.string	"cannot create std::vector larger than max_size()"
	.section	.rodata.str1.1
.LC11:
	.string	"stoi"
	.section	.text.unlikely
.LCOLDB12:
	.section	.text.startup,"ax",@progbits
.LHOTB12:
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB4648:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA4648
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$632, %rsp
	.cfi_def_cfa_offset 688
	movq	%fs:40, %rax
	movq	%rax, 616(%rsp)
	xorl	%eax, %eax
	leaq	80(%rsp), %rax
	movq	%rax, %rdi
	movq	%rax, 56(%rsp)
.LEHB15:
	call	_Z9readInputB5cxx11v
.LEHE15:
	leaq	176(%rsp), %rdi
	movl	$1, %esi
	leaq	.LC6(%rip), %rdx
.LEHB16:
	call	_ZN4absl12lts_202103249ByAnyCharC1ESt17basic_string_viewIcSt11char_traitsIcEE@PLT
.LEHE16:
	movq	80(%rsp), %rax
	movq	176(%rsp), %rbp
	movq	184(%rsp), %r12
	movq	8(%rax), %r13
	movq	(%rax), %rbx
	leaq	368(%rsp), %rax
	movq	%rax, 8(%rsp)
	movq	%rax, 352(%rsp)
	movq	%rbp, %rax
	addq	%r12, %rax
	je	.L167
	testq	%rbp, %rbp
	je	.L396
.L167:
	movq	%r12, 144(%rsp)
	cmpq	$15, %r12
	ja	.L397
	cmpq	$1, %r12
	jne	.L170
	movzbl	0(%rbp), %eax
	movb	%al, 368(%rsp)
.L171:
	movq	144(%rsp), %rax
	movq	352(%rsp), %rdx
	movq	%rax, 360(%rsp)
	movb	$0, (%rdx,%rax)
	movq	352(%rsp), %rbp
	leaq	240(%rsp), %rax
	movq	360(%rsp), %r12
	movq	%rax, 48(%rsp)
	movq	%rax, 224(%rsp)
	movq	%rbp, %rax
	addq	%r12, %rax
	movq	%r13, 208(%rsp)
	movq	%rbx, 216(%rsp)
	je	.L172
	testq	%rbp, %rbp
	je	.L398
.L172:
	movq	%r12, 144(%rsp)
	cmpq	$15, %r12
	ja	.L399
	cmpq	$1, %r12
	jne	.L175
	movzbl	0(%rbp), %eax
	movb	%al, 240(%rsp)
.L176:
	movq	144(%rsp), %rax
	movq	224(%rsp), %rdx
	movq	%rax, 232(%rsp)
	movb	$0, (%rdx,%rax)
	movq	352(%rsp), %rdi
	cmpq	8(%rsp), %rdi
	je	.L177
	movq	368(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L177:
	leaq	208(%rsp), %rax
	movq	224(%rsp), %rbp
	movq	232(%rsp), %r12
	movq	$0, 272(%rsp)
	movq	%rax, 304(%rsp)
	leaq	328(%rsp), %rax
	movq	%rax, 40(%rsp)
	movq	%rax, 312(%rsp)
	movq	%rbp, %rax
	movl	$0, 280(%rsp)
	addq	%r12, %rax
	movq	$0, 288(%rsp)
	movq	$0, 296(%rsp)
	je	.L180
	testq	%rbp, %rbp
	je	.L400
.L180:
	movq	%r12, 144(%rsp)
	cmpq	$15, %r12
	ja	.L401
	cmpq	$1, %r12
	jne	.L186
	movzbl	0(%rbp), %eax
	movb	%al, 328(%rsp)
.L187:
	movq	144(%rsp), %rax
	movq	312(%rsp), %rdx
	movq	%rax, 320(%rsp)
	movb	$0, (%rdx,%rax)
	movq	304(%rsp), %rax
	movq	8(%rax), %rbx
	movq	(%rax), %r12
	testq	%rbx, %rbx
	je	.L402
	movl	280(%rsp), %eax
	cmpl	$2, %eax
	je	.L403
	subl	$1, %eax
	je	.L404
	leaq	312(%rsp), %r14
	movq	272(%rsp), %rcx
	movq	%r12, %rsi
	movq	%rbx, %rdx
	movq	%r14, %rdi
.LEHB17:
	call	_ZNK4absl12lts_202103249ByAnyChar4FindESt17basic_string_viewIcSt11char_traitsIcEEm@PLT
.LEHE17:
	movq	%rax, %rcx
	movq	%rdx, %rax
	leaq	(%rbx,%r12), %rdx
	cmpq	%rdx, %rax
	je	.L405
.L192:
	movq	272(%rsp), %rdx
	addq	%rdx, %rbx
	subq	%rbx, %rax
	cmpq	%rdx, %r12
	jb	.L406
	subq	%rdx, %r12
	movq	%rbx, 296(%rsp)
	cmpq	%rax, %r12
	cmova	%rax, %r12
	leaq	(%rdx,%rcx), %rax
	addq	%r12, %rax
	movq	%r12, 288(%rsp)
	movq	%rax, 272(%rsp)
	movl	280(%rsp), %eax
	cmpl	$2, %eax
	je	.L189
	leaq	352(%rsp), %rdi
	movq	$0, (%rsp)
	xorl	%r15d, %r15d
	movq	$0, 24(%rsp)
	movq	%rdi, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L194:
	movq	16(%rsp), %rbp
	xorl	%r13d, %r13d
	jmp	.L203
	.p2align 4,,10
	.p2align 3
.L198:
	movq	304(%rsp), %rax
	movq	272(%rsp), %rcx
	movq	%r14, %rdi
	movq	(%rax), %r12
	movq	8(%rax), %rbx
	movq	%r12, %rsi
	movq	%rbx, %rdx
.LEHB18:
	call	_ZNK4absl12lts_202103249ByAnyChar4FindESt17basic_string_viewIcSt11char_traitsIcEEm@PLT
.LEHE18:
	leaq	(%rbx,%r12), %rcx
	cmpq	%rcx, %rdx
	je	.L407
.L201:
	movq	272(%rsp), %r8
	addq	%r8, %rbx
	subq	%rbx, %rdx
	cmpq	%r8, %r12
	jb	.L408
	subq	%r8, %r12
	movq	%rbx, 296(%rsp)
	cmpq	%rdx, %r12
	cmova	%rdx, %r12
	addq	%rax, %r8
	addq	$1, %r13
	addq	%r12, %r8
	movq	%r12, 288(%rsp)
	movq	%r8, 272(%rsp)
	cmpq	$16, %r13
	je	.L200
	movl	280(%rsp), %eax
	addq	$16, %rbp
	cmpl	$2, %eax
	je	.L199
.L203:
	movq	%rbx, 0(%rbp)
	movq	%r12, 8(%rbp)
	cmpl	$1, %eax
	jne	.L198
	movl	$2, 280(%rsp)
	addq	$1, %r13
	cmpq	$16, %r13
	jne	.L199
.L200:
	movq	24(%rsp), %rax
	subq	(%rsp), %rax
	cmpq	$255, %rax
	jbe	.L306
	movl	280(%rsp), %eax
	leaq	608(%rsp), %rbx
	movl	$256, %r13d
.L291:
	movq	(%rsp), %rcx
	movq	16(%rsp), %rdx
.L205:
	movq	(%rdx), %rsi
	movq	8(%rdx), %rdi
	addq	$16, %rdx
	addq	$16, %rcx
	movq	%rdi, -16(%rcx)
	movq	%rsi, -8(%rcx)
	cmpq	%rbx, %rdx
	jne	.L205
	movq	24(%rsp), %rdi
	addq	%r13, (%rsp)
	subq	%r15, %rdi
	movq	%rdi, 32(%rsp)
	cmpl	$2, %eax
	je	.L219
.L411:
	movq	296(%rsp), %rbx
	movq	288(%rsp), %r12
	jmp	.L194
.L170:
	testq	%r12, %r12
	je	.L171
	movq	8(%rsp), %rdi
	jmp	.L169
	.p2align 4,,10
	.p2align 3
.L407:
	movl	$1, 280(%rsp)
	jmp	.L201
	.p2align 4,,10
	.p2align 3
.L199:
	movq	16(%rsp), %rax
	salq	$4, %r13
	leaq	(%rax,%r13), %rbx
	movq	24(%rsp), %rax
	subq	(%rsp), %rax
	cmpq	%rax, %r13
	ja	.L204
	movl	$2, %eax
	jmp	.L291
	.p2align 4,,10
	.p2align 3
.L306:
	movl	$16, %r13d
	leaq	608(%rsp), %rbx
.L290:
	movabsq	$576460752303423487, %rdx
	movq	(%rsp), %rax
	subq	%r15, %rax
	sarq	$4, %rax
	subq	%rax, %rdx
	cmpq	%r13, %rdx
	jb	.L409
	cmpq	%r13, %rax
	cmovnb	%rax, %r13
	addq	%r13, %rax
	jc	.L209
	testq	%rax, %rax
	jne	.L410
	movq	$0, 32(%rsp)
	xorl	%r13d, %r13d
	xorl	%r12d, %r12d
.L211:
	movq	(%rsp), %rax
	cmpq	%rax, %r15
	je	.L212
	subq	%r15, %rax
	movq	%rax, %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L213:
	movdqu	(%r15,%rax), %xmm1
	movups	%xmm1, (%r12,%rax)
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L213
	leaq	(%r12,%rdx), %rax
	movq	%rax, (%rsp)
	cmpq	16(%rsp), %rbx
	je	.L215
.L214:
	movq	(%rsp), %rdx
	movq	16(%rsp), %rax
	.p2align 4,,10
	.p2align 3
.L217:
	movq	(%rax), %rcx
	movq	8(%rax), %rsi
	addq	$16, %rax
	addq	$16, %rdx
	movq	%rsi, -16(%rdx)
	movq	%rcx, -8(%rdx)
	cmpq	%rbx, %rax
	jne	.L217
	subq	16(%rsp), %rax
	addq	%rax, (%rsp)
.L216:
	testq	%r15, %r15
	je	.L218
.L215:
	movq	24(%rsp), %rsi
	movq	%r15, %rdi
	subq	%r15, %rsi
	call	_ZdlPvm@PLT
	.p2align 4,,10
	.p2align 3
.L218:
	movl	280(%rsp), %eax
	movq	%r13, 24(%rsp)
	movq	%r12, %r15
	cmpl	$2, %eax
	jne	.L411
.L219:
	movq	312(%rsp), %rdi
	cmpq	40(%rsp), %rdi
	je	.L220
	movq	328(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L220:
	movq	(%rsp), %rdx
	pxor	%xmm0, %xmm0
	movabsq	$4611686018427387888, %rcx
	movq	$0, 128(%rsp)
	movaps	%xmm0, 112(%rsp)
	subq	%r15, %rdx
	movq	%rdx, %rax
	sarq	$4, %rax
	cmpq	%rcx, %rdx
	ja	.L412
	movq	%rax, %rbx
	salq	$5, %rbx
	testq	%rax, %rax
	je	.L300
	movq	%rbx, %rdi
.LEHB19:
	call	_Znwm@PLT
.LEHE19:
	movq	%rax, %r12
.L227:
	addq	%r12, %rbx
	movq	%r12, 112(%rsp)
	movq	%rbx, 128(%rsp)
	cmpq	(%rsp), %r15
	je	.L301
	leaq	144(%rsp), %rax
	movq	%r15, %rbx
	movq	%r12, %rbp
	movq	%rax, 16(%rsp)
	jmp	.L234
	.p2align 4,,10
	.p2align 3
.L415:
	movzbl	(%r14), %eax
	movb	%al, 16(%rbp)
.L233:
	movq	%r13, 8(%rbp)
	addq	$16, %rbx
	addq	$32, %rbp
	movb	$0, (%rdi,%r13)
	cmpq	%rbx, (%rsp)
	je	.L228
.L234:
	movq	8(%rbx), %r14
	movq	(%rbx), %r13
	leaq	16(%rbp), %rdi
	movq	%rdi, 0(%rbp)
	movq	%r14, %rax
	addq	%r13, %rax
	je	.L229
	testq	%r14, %r14
	je	.L413
.L229:
	movq	%r13, 144(%rsp)
	cmpq	$15, %r13
	ja	.L414
	cmpq	$1, %r13
	je	.L415
	testq	%r13, %r13
	je	.L233
	jmp	.L231
	.p2align 4,,10
	.p2align 3
.L204:
	sarq	$4, %r13
	jmp	.L290
	.p2align 4,,10
	.p2align 3
.L414:
	movq	16(%rsp), %rsi
	xorl	%edx, %edx
	movq	%rbp, %rdi
.LEHB20:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.LEHE20:
	movq	%rax, 0(%rbp)
	movq	%rax, %rdi
	movq	144(%rsp), %rax
	movq	%rax, 16(%rbp)
.L231:
	movq	%r13, %rdx
	movq	%r14, %rsi
	call	memcpy@PLT
	movq	144(%rsp), %r13
	movq	0(%rbp), %rdi
	jmp	.L233
.L301:
	movq	%r12, %rbp
	.p2align 4,,10
	.p2align 3
.L228:
	movq	%rbp, 120(%rsp)
	testq	%r15, %r15
	je	.L236
	movq	32(%rsp), %rsi
	movq	%r15, %rdi
	call	_ZdlPvm@PLT
.L236:
	movq	224(%rsp), %rdi
	cmpq	48(%rsp), %rdi
	je	.L244
	movq	240(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L244:
	movq	176(%rsp), %rdi
	leaq	192(%rsp), %rax
	cmpq	%rax, %rdi
	je	.L245
	movq	192(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L245:
	pxor	%xmm0, %xmm0
	movq	$0, (%rsp)
	movq	$0, 160(%rsp)
	movaps	%xmm0, 144(%rsp)
	cmpq	%rbp, %r12
	je	.L246
	leaq	352(%rsp), %rax
	leaq	72(%rsp), %r14
	movq	%rax, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L264:
	movq	8(%rsp), %rax
	movq	(%r12), %r15
	movq	8(%r12), %r13
	movq	%rax, 352(%rsp)
	movq	%r15, %rax
	addq	%r13, %rax
	je	.L247
	testq	%r15, %r15
	je	.L416
.L247:
	movq	%r13, 72(%rsp)
	cmpq	$15, %r13
	ja	.L417
	cmpq	$1, %r13
	jne	.L250
	movzbl	(%r15), %eax
	movb	%al, 368(%rsp)
	movq	8(%rsp), %rax
.L251:
	movq	%r13, 360(%rsp)
	movb	$0, (%rax,%r13)
	movq	352(%rsp), %r13
	call	__errno_location@PLT
	movl	$10, %edx
	movq	%r14, %rsi
	movq	%r13, %rdi
	movl	(%rax), %r15d
	movl	$0, (%rax)
	movq	%rax, %rbx
	call	strtol@PLT
	cmpq	72(%rsp), %r13
	je	.L418
	movl	(%rbx), %edx
	cmpl	$34, %edx
	je	.L253
	movl	$2147483648, %edi
	leaq	(%rax,%rdi), %rcx
	addq	$2147483647, %rdi
	cmpq	%rdi, %rcx
	ja	.L253
	testl	%edx, %edx
	jne	.L255
	movl	%r15d, (%rbx)
.L255:
	movl	%eax, 72(%rsp)
	movq	152(%rsp), %rdx
	cmpq	(%rsp), %rdx
	je	.L419
	movl	%eax, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 152(%rsp)
.L261:
	movq	352(%rsp), %rdi
	cmpq	8(%rsp), %rdi
	je	.L262
	movq	368(%rsp), %rax
	addq	$32, %r12
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
	cmpq	%r12, %rbp
	jne	.L264
.L246:
	movq	152(%rsp), %rbx
	movq	144(%rsp), %rax
	movq	%rbx, %r12
	movq	%rax, 8(%rsp)
	subq	%rax, %r12
	movq	%r12, 16(%rsp)
	je	.L265
	movabsq	$9223372036854775804, %rax
	cmpq	%rax, %r12
	ja	.L420
	movq	%r12, %rdi
.LEHB21:
	call	_Znwm@PLT
	movq	%rax, %r10
	leaq	(%rax,%r12), %r9
	cmpq	8(%rsp), %rbx
	jne	.L293
.L268:
	cmpq	%r10, %r9
	je	.L304
	movq	%r10, %rax
	xorl	%r14d, %r14d
	xorl	%r12d, %r12d
	xorl	%r13d, %r13d
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	xorl	%r15d, %r15d
	xorl	%r8d, %r8d
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	leaq	.L273(%rip), %rdi
	jmp	.L281
	.p2align 4,,10
	.p2align 3
.L421:
	addq	$1, %rbx
.L271:
	addq	$4, %rax
	cmpq	%r9, %rax
	je	.L269
.L281:
	movl	(%rax), %esi
	testl	%esi, %esi
	je	.L421
	cmpl	$8, %esi
	ja	.L271
	movslq	(%rdi,%rsi,4), %rsi
	addq	%rdi, %rsi
	jmp	*%rsi
	.section	.rodata
	.align 4
	.align 4
.L273:
	.long	.L271-.L273
	.long	.L280-.L273
	.long	.L279-.L273
	.long	.L278-.L273
	.long	.L277-.L273
	.long	.L276-.L273
	.long	.L275-.L273
	.long	.L274-.L273
	.long	.L272-.L273
	.section	.text.startup
.L272:
	addq	$1, %r14
	jmp	.L271
.L274:
	addq	$1, %r12
	jmp	.L271
.L275:
	addq	$1, %r13
	jmp	.L271
.L276:
	addq	$1, %rdx
	jmp	.L271
.L277:
	addq	$1, %rcx
	jmp	.L271
.L278:
	addq	$1, %r15
	jmp	.L271
.L279:
	addq	$1, %r8
	jmp	.L271
.L280:
	addq	$1, %rbp
	jmp	.L271
	.p2align 4,,10
	.p2align 3
.L262:
	addq	$32, %r12
	cmpq	%r12, %rbp
	jne	.L264
	jmp	.L246
	.p2align 4,,10
	.p2align 3
.L250:
	testq	%r13, %r13
	jne	.L422
	movq	8(%rsp), %rax
	jmp	.L251
	.p2align 4,,10
	.p2align 3
.L417:
	movq	16(%rsp), %rdi
	xorl	%edx, %edx
	movq	%r14, %rsi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.LEHE21:
	movq	%rax, 352(%rsp)
	movq	%rax, %rdi
	movq	72(%rsp), %rax
	movq	%rax, 368(%rsp)
.L249:
	movq	%r13, %rdx
	movq	%r15, %rsi
	call	memcpy@PLT
	movq	72(%rsp), %r13
	movq	352(%rsp), %rax
	jmp	.L251
	.p2align 4,,10
	.p2align 3
.L419:
	movq	(%rsp), %rsi
	leaq	144(%rsp), %rdi
	movq	%r14, %rdx
.LEHB22:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE22:
	movq	160(%rsp), %rax
	movq	%rax, (%rsp)
	jmp	.L261
.L304:
	xorl	%r14d, %r14d
	xorl	%r12d, %r12d
	xorl	%r13d, %r13d
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	xorl	%r15d, %r15d
	xorl	%r8d, %r8d
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
.L269:
	movq	16(%rsp), %rsi
	movq	%r10, %rdi
	movq	%r8, 40(%rsp)
	movq	%rcx, 32(%rsp)
	movq	%rdx, 24(%rsp)
	call	_ZdlPvm@PLT
	movq	24(%rsp), %rdx
	movq	32(%rsp), %rcx
	movq	40(%rsp), %r8
.L292:
	movq	%r8, 32(%rsp)
	movq	%rcx, 24(%rsp)
	movq	%rdx, 16(%rsp)
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	16(%rsp), %rdx
	movq	24(%rsp), %rcx
	movq	%rax, %rdi
	movq	32(%rsp), %r8
	movl	$256, %eax
	jmp	.L282
	.p2align 4,,10
	.p2align 3
.L305:
	movq	%rbx, %r14
	movq	%rbp, %rbx
	movq	%r8, %rbp
	movq	%r15, %r8
	movq	%rcx, %r15
	movq	%rdx, %rcx
	movq	%rsi, %rdx
.L282:
	movq	%r13, %rsi
	leaq	(%r12,%rbx), %r13
	movq	%r14, %r12
	subl	$1, %eax
	jne	.L305
	movq	%rsi, 48(%rsp)
	movq	%rdx, 40(%rsp)
	movq	%rcx, 32(%rsp)
	movq	%r8, 24(%rsp)
	movq	%rdi, 16(%rsp)
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	16(%rsp), %rdi
	movq	24(%rsp), %r8
	movq	32(%rsp), %rcx
	movq	40(%rsp), %rdx
	subq	%rdi, %rax
	movq	48(%rsp), %rsi
	movq	%rax, %r12
	leaq	(%r8,%rbp), %rax
	leaq	_ZSt4cout(%rip), %rbp
	addq	%r15, %rax
	movq	%rbp, %rdi
	addq	%rcx, %rax
	addq	%rdx, %rax
	addq	%rax, %rsi
	addq	%r13, %rsi
	addq	%r14, %rsi
	addq	%rbx, %rsi
.LEHB23:
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
.LEHE23:
	movq	8(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L283
	movq	(%rsp), %rsi
	subq	%rdi, %rsi
	call	_ZdlPvm@PLT
.L283:
	leaq	112(%rsp), %rdi
	call	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev
	movq	56(%rsp), %rdi
	call	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev
	movq	616(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L423
	addq	$632, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L265:
	.cfi_restore_state
	cmpq	8(%rsp), %rbx
	je	.L424
	xorl	%r9d, %r9d
	xorl	%r10d, %r10d
.L293:
	movq	8(%rsp), %rsi
	movq	%r10, %rdi
	movq	%r12, %rdx
	movq	%r9, 24(%rsp)
	call	memmove@PLT
	movq	24(%rsp), %r9
	movq	%rax, %r10
	jmp	.L268
.L300:
	xorl	%r12d, %r12d
	jmp	.L227
.L175:
	testq	%r12, %r12
	je	.L176
	movq	48(%rsp), %rdi
	jmp	.L174
.L186:
	testq	%r12, %r12
	je	.L187
	movq	40(%rsp), %rdi
	jmp	.L185
.L399:
	leaq	144(%rsp), %rsi
	leaq	224(%rsp), %rdi
	xorl	%edx, %edx
.LEHB24:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.LEHE24:
	movq	%rax, 224(%rsp)
	movq	%rax, %rdi
	movq	144(%rsp), %rax
	movq	%rax, 240(%rsp)
.L174:
	movq	%r12, %rdx
	movq	%rbp, %rsi
	call	memcpy@PLT
	jmp	.L176
.L401:
	leaq	144(%rsp), %rsi
	leaq	312(%rsp), %rdi
	xorl	%edx, %edx
.LEHB25:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.LEHE25:
	movq	%rax, 312(%rsp)
	movq	%rax, %rdi
	movq	144(%rsp), %rax
	movq	%rax, 328(%rsp)
.L185:
	movq	%r12, %rdx
	movq	%rbp, %rsi
	call	memcpy@PLT
	jmp	.L187
.L397:
	leaq	352(%rsp), %rax
	leaq	144(%rsp), %rsi
	xorl	%edx, %edx
	movq	%rax, %rdi
.LEHB26:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.LEHE26:
	movq	%rax, 352(%rsp)
	movq	%rax, %rdi
	movq	144(%rsp), %rax
	movq	%rax, 368(%rsp)
.L169:
	movq	%r12, %rdx
	movq	%rbp, %rsi
	call	memcpy@PLT
	jmp	.L171
.L403:
	movq	%r12, 272(%rsp)
.L189:
	movq	$0, 32(%rsp)
	xorl	%r15d, %r15d
	movq	$0, (%rsp)
	jmp	.L219
.L404:
	movl	$2, 280(%rsp)
	jmp	.L189
.L402:
	movl	$2, 280(%rsp)
	movq	%r12, 272(%rsp)
	jmp	.L189
.L212:
	cmpq	16(%rsp), %rbx
	movq	%r12, (%rsp)
	jne	.L214
	jmp	.L216
.L405:
	movl	$1, 280(%rsp)
	jmp	.L192
.L424:
	xorl	%r14d, %r14d
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
	xorl	%r13d, %r13d
	xorl	%r8d, %r8d
	xorl	%edx, %edx
	xorl	%r15d, %r15d
	xorl	%ecx, %ecx
	jmp	.L292
.L420:
	testq	%r12, %r12
	jns	.L267
.LEHB27:
	call	_ZSt28__throw_bad_array_new_lengthv@PLT
.L267:
	call	_ZSt17__throw_bad_allocv@PLT
.LEHE27:
.L408:
	movq	%r12, %rcx
	movq	%r8, %rdx
	leaq	.LC7(%rip), %rsi
	xorl	%eax, %eax
	leaq	.LC8(%rip), %rdi
.LEHB28:
	call	_ZSt24__throw_out_of_range_fmtPKcz@PLT
.L410:
	movabsq	$576460752303423487, %rdx
	cmpq	%rdx, %rax
	cmovbe	%rax, %rdx
	movq	%rdx, %rbp
.L210:
	salq	$4, %rbp
	movq	%rbp, %rdi
	call	_Znwm@PLT
.LEHE28:
	movq	%rbp, 32(%rsp)
	movq	%rax, %r12
	leaq	(%rax,%rbp), %r13
	jmp	.L211
.L253:
	leaq	.LC11(%rip), %rdi
.LEHB29:
	call	_ZSt20__throw_out_of_rangePKc@PLT
.LEHE29:
.L409:
	leaq	.LC9(%rip), %rdi
.LEHB30:
	call	_ZSt20__throw_length_errorPKc@PLT
.LEHE30:
.L398:
	leaq	.LC2(%rip), %rdi
.LEHB31:
	call	_ZSt19__throw_logic_errorPKc@PLT
.LEHE31:
.L396:
	leaq	.LC2(%rip), %rdi
.LEHB32:
	call	_ZSt19__throw_logic_errorPKc@PLT
.LEHE32:
.L400:
	leaq	.LC2(%rip), %rdi
.LEHB33:
	call	_ZSt19__throw_logic_errorPKc@PLT
.LEHE33:
.L406:
	movq	%r12, %rcx
	leaq	.LC7(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	xorl	%eax, %eax
.LEHB34:
	call	_ZSt24__throw_out_of_range_fmtPKcz@PLT
.LEHE34:
.L412:
	leaq	.LC10(%rip), %rdi
.LEHB35:
	call	_ZSt20__throw_length_errorPKc@PLT
.LEHE35:
.L209:
	movabsq	$576460752303423487, %rbp
	jmp	.L210
.L422:
	movq	8(%rsp), %rdi
	jmp	.L249
.L423:
	call	__stack_chk_fail@PLT
.L416:
	leaq	.LC2(%rip), %rdi
.LEHB36:
	call	_ZSt19__throw_logic_errorPKc@PLT
.LEHE36:
.L418:
	leaq	.LC11(%rip), %rdi
.LEHB37:
	call	_ZSt24__throw_invalid_argumentPKc@PLT
.LEHE37:
.L413:
	leaq	.LC2(%rip), %rdi
.LEHB38:
	call	_ZSt19__throw_logic_errorPKc@PLT
.LEHE38:
.L311:
	movq	%rax, %rbx
	jmp	.L288
.L310:
	movq	%rax, %rbx
	jmp	.L260
.L318:
	jmp	.L258
.L319:
	movq	%rax, %rbx
	jmp	.L226
.L308:
	movq	%rax, %rbx
	jmp	.L183
.L309:
	movq	%rax, %rbx
	jmp	.L286
.L314:
	movq	%rax, %rbx
	jmp	.L195
.L315:
	movq	%rax, %rbx
	jmp	.L239
.L313:
	movq	%rax, %rbx
	jmp	.L223
.L317:
	movq	%rax, %rdi
	jmp	.L237
.L312:
	movq	%rax, %rbx
	jmp	.L181
	.section	.gcc_except_table
	.align 4
.LLSDA4648:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT4648-.LLSDATTD4648
.LLSDATTD4648:
	.byte	0x1
	.uleb128 .LLSDACSE4648-.LLSDACSB4648
.LLSDACSB4648:
	.uleb128 .LEHB15-.LFB4648
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB16-.LFB4648
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L309-.LFB4648
	.uleb128 0
	.uleb128 .LEHB17-.LFB4648
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L314-.LFB4648
	.uleb128 0
	.uleb128 .LEHB18-.LFB4648
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L313-.LFB4648
	.uleb128 0
	.uleb128 .LEHB19-.LFB4648
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L315-.LFB4648
	.uleb128 0
	.uleb128 .LEHB20-.LFB4648
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L317-.LFB4648
	.uleb128 0x1
	.uleb128 .LEHB21-.LFB4648
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L311-.LFB4648
	.uleb128 0
	.uleb128 .LEHB22-.LFB4648
	.uleb128 .LEHE22-.LEHB22
	.uleb128 .L310-.LFB4648
	.uleb128 0
	.uleb128 .LEHB23-.LFB4648
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L311-.LFB4648
	.uleb128 0
	.uleb128 .LEHB24-.LFB4648
	.uleb128 .LEHE24-.LEHB24
	.uleb128 .L312-.LFB4648
	.uleb128 0
	.uleb128 .LEHB25-.LFB4648
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L319-.LFB4648
	.uleb128 0
	.uleb128 .LEHB26-.LFB4648
	.uleb128 .LEHE26-.LEHB26
	.uleb128 .L308-.LFB4648
	.uleb128 0
	.uleb128 .LEHB27-.LFB4648
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L311-.LFB4648
	.uleb128 0
	.uleb128 .LEHB28-.LFB4648
	.uleb128 .LEHE28-.LEHB28
	.uleb128 .L313-.LFB4648
	.uleb128 0
	.uleb128 .LEHB29-.LFB4648
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L318-.LFB4648
	.uleb128 0
	.uleb128 .LEHB30-.LFB4648
	.uleb128 .LEHE30-.LEHB30
	.uleb128 .L313-.LFB4648
	.uleb128 0
	.uleb128 .LEHB31-.LFB4648
	.uleb128 .LEHE31-.LEHB31
	.uleb128 .L312-.LFB4648
	.uleb128 0
	.uleb128 .LEHB32-.LFB4648
	.uleb128 .LEHE32-.LEHB32
	.uleb128 .L308-.LFB4648
	.uleb128 0
	.uleb128 .LEHB33-.LFB4648
	.uleb128 .LEHE33-.LEHB33
	.uleb128 .L319-.LFB4648
	.uleb128 0
	.uleb128 .LEHB34-.LFB4648
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L314-.LFB4648
	.uleb128 0
	.uleb128 .LEHB35-.LFB4648
	.uleb128 .LEHE35-.LEHB35
	.uleb128 .L315-.LFB4648
	.uleb128 0
	.uleb128 .LEHB36-.LFB4648
	.uleb128 .LEHE36-.LEHB36
	.uleb128 .L311-.LFB4648
	.uleb128 0
	.uleb128 .LEHB37-.LFB4648
	.uleb128 .LEHE37-.LEHB37
	.uleb128 .L318-.LFB4648
	.uleb128 0
	.uleb128 .LEHB38-.LFB4648
	.uleb128 .LEHE38-.LEHB38
	.uleb128 .L317-.LFB4648
	.uleb128 0x1
.LLSDACSE4648:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT4648:
	.section	.text.startup
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC4648
	.type	main.cold, @function
main.cold:
.LFSB4648:
.L258:
	.cfi_def_cfa_offset 688
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	cmpl	$0, (%rbx)
	je	.L425
.L259:
	movq	%rax, %rbx
.L260:
	movq	352(%rsp), %rdi
	cmpq	8(%rsp), %rdi
	je	.L288
	movq	368(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L288:
	movq	144(%rsp), %rdi
	movq	160(%rsp), %rsi
	subq	%rdi, %rsi
	testq	%rdi, %rdi
	jne	.L426
.L289:
	leaq	112(%rsp), %rdi
	call	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev
.L286:
	movq	56(%rsp), %rdi
	call	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev
	movq	%rbx, %rdi
.LEHB39:
	call	_Unwind_Resume@PLT
.LEHE39:
.L425:
	movl	%r15d, (%rbx)
	jmp	.L259
.L426:
	call	_ZdlPvm@PLT
	jmp	.L289
.L316:
	movq	%rax, %rbx
	call	__cxa_end_catch@PLT
.L239:
	movq	112(%rsp), %rdi
	movq	128(%rsp), %rsi
	subq	%rdi, %rsi
	testq	%rdi, %rdi
	jne	.L427
.L240:
	testq	%r15, %r15
	je	.L226
	movq	32(%rsp), %rsi
.L395:
	movq	%r15, %rdi
	call	_ZdlPvm@PLT
.L226:
	movq	224(%rsp), %rdi
	cmpq	48(%rsp), %rdi
	je	.L183
	movq	240(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L183:
	movq	176(%rsp), %rdi
	leaq	192(%rsp), %rax
	cmpq	%rax, %rdi
	je	.L286
	movq	192(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
	jmp	.L286
.L195:
	movq	312(%rsp), %rdi
	cmpq	40(%rsp), %rdi
	je	.L226
	movq	328(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
	jmp	.L226
.L223:
	movq	312(%rsp), %rdi
	cmpq	40(%rsp), %rdi
	je	.L224
	movq	328(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L224:
	movq	24(%rsp), %rsi
	subq	%r15, %rsi
	testq	%r15, %r15
	jne	.L395
	jmp	.L226
.L181:
	movq	352(%rsp), %rdi
	cmpq	8(%rsp), %rdi
	je	.L183
	movq	368(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
	jmp	.L183
.L237:
	call	__cxa_begin_catch@PLT
	movq	%rbp, %rsi
	movq	%r12, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEvT_S9_
.LEHB40:
	call	__cxa_rethrow@PLT
.LEHE40:
.L427:
	call	_ZdlPvm@PLT
	jmp	.L240
	.cfi_endproc
.LFE4648:
	.section	.gcc_except_table
	.align 4
.LLSDAC4648:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATTC4648-.LLSDATTDC4648
.LLSDATTDC4648:
	.byte	0x1
	.uleb128 .LLSDACSEC4648-.LLSDACSBC4648
.LLSDACSBC4648:
	.uleb128 .LEHB39-.LCOLDB12
	.uleb128 .LEHE39-.LEHB39
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB40-.LCOLDB12
	.uleb128 .LEHE40-.LEHB40
	.uleb128 .L316-.LCOLDB12
	.uleb128 0
.LLSDACSEC4648:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATTC4648:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold, .-main.cold
.LCOLDE12:
	.section	.text.startup
.LHOTE12:
	.p2align 4
	.type	_GLOBAL__sub_I__Z9readInputB5cxx11v, @function
_GLOBAL__sub_I__Z9readInputB5cxx11v:
.LFB5758:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE5758:
	.size	_GLOBAL__sub_I__Z9readInputB5cxx11v, .-_GLOBAL__sub_I__Z9readInputB5cxx11v
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z9readInputB5cxx11v
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
