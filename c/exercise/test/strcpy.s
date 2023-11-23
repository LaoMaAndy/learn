   1              		.file	"strcpy-asm.c"
   2              		.text
   3              	.Ltext0:
   4              		.globl	Strcpy
   6              	Strcpy:
   7              	.LFB0:
   8              		.file 1 "strcpy-asm.c"
   1:strcpy-asm.c  **** void Strcpy(char *dest, char *src)
   2:strcpy-asm.c  **** {
   9              		.loc 1 2 0
  10              		.cfi_startproc
  11 0000 55       		pushq	%rbp
  12              		.cfi_def_cfa_offset 16
  13              		.cfi_offset 6, -16
  14 0001 4889E5   		movq	%rsp, %rbp
  15              		.cfi_def_cfa_register 6
  16 0004 48897DF8 		movq	%rdi, -8(%rbp)
  17 0008 488975F0 		movq	%rsi, -16(%rbp)
   3:strcpy-asm.c  **** 	while (*dest++ = *src++)
  18              		.loc 1 3 0
  19 000c 90       		nop
  20              	.L2:
  21              		.loc 1 3 0 is_stmt 0 discriminator 1
  22 000d 488B45F8 		movq	-8(%rbp), %rax
  23 0011 488D5001 		leaq	1(%rax), %rdx
  24 0015 488955F8 		movq	%rdx, -8(%rbp)
  25 0019 488B55F0 		movq	-16(%rbp), %rdx
  26 001d 488D4A01 		leaq	1(%rdx), %rcx
  27 0021 48894DF0 		movq	%rcx, -16(%rbp)
  28 0025 0FB612   		movzbl	(%rdx), %edx
  29 0028 8810     		movb	%dl, (%rax)
  30 002a 0FB600   		movzbl	(%rax), %eax
  31 002d 84C0     		testb	%al, %al
  32 002f 75DC     		jne	.L2
   4:strcpy-asm.c  **** 		;
   5:strcpy-asm.c  **** }
  33              		.loc 1 5 0 is_stmt 1
  34 0031 90       		nop
  35 0032 5D       		popq	%rbp
  36              		.cfi_def_cfa 7, 8
  37 0033 C3       		ret
  38              		.cfi_endproc
  39              	.LFE0:
  41              		.globl	Strcpy_1
  43              	Strcpy_1:
  44              	.LFB1:
   6:strcpy-asm.c  **** 
   7:strcpy-asm.c  **** void Strcpy_1(char *dest, char *src)
   8:strcpy-asm.c  **** {
  45              		.loc 1 8 0
  46              		.cfi_startproc
  47 0034 55       		pushq	%rbp
  48              		.cfi_def_cfa_offset 16
  49              		.cfi_offset 6, -16
  50 0035 4889E5   		movq	%rsp, %rbp
  51              		.cfi_def_cfa_register 6
  52 0038 48897DE8 		movq	%rdi, -24(%rbp)
  53 003c 488975E0 		movq	%rsi, -32(%rbp)
   9:strcpy-asm.c  **** 	char *d = dest;
  54              		.loc 1 9 0
  55 0040 488B45E8 		movq	-24(%rbp), %rax
  56 0044 488945F0 		movq	%rax, -16(%rbp)
  10:strcpy-asm.c  **** 	char *s = src;
  57              		.loc 1 10 0
  58 0048 488B45E0 		movq	-32(%rbp), %rax
  59 004c 488945F8 		movq	%rax, -8(%rbp)
  11:strcpy-asm.c  **** 
  12:strcpy-asm.c  **** 	while (*d++ = *s++)
  60              		.loc 1 12 0
  61 0050 90       		nop
  62              	.L4:
  63              		.loc 1 12 0 is_stmt 0 discriminator 1
  64 0051 488B45F0 		movq	-16(%rbp), %rax
  65 0055 488D5001 		leaq	1(%rax), %rdx
  66 0059 488955F0 		movq	%rdx, -16(%rbp)
  67 005d 488B55F8 		movq	-8(%rbp), %rdx
  68 0061 488D4A01 		leaq	1(%rdx), %rcx
  69 0065 48894DF8 		movq	%rcx, -8(%rbp)
  70 0069 0FB612   		movzbl	(%rdx), %edx
  71 006c 8810     		movb	%dl, (%rax)
  72 006e 0FB600   		movzbl	(%rax), %eax
  73 0071 84C0     		testb	%al, %al
  74 0073 75DC     		jne	.L4
  13:strcpy-asm.c  **** 		;
  14:strcpy-asm.c  **** }
  75              		.loc 1 14 0 is_stmt 1
  76 0075 90       		nop
  77 0076 5D       		popq	%rbp
  78              		.cfi_def_cfa 7, 8
  79 0077 C3       		ret
  80              		.cfi_endproc
  81              	.LFE1:
  83              		.globl	strcpy_STD
  85              	strcpy_STD:
  86              	.LFB2:
  15:strcpy-asm.c  **** #include <stddef.h>
  16:strcpy-asm.c  **** #include <string.h>
  17:strcpy-asm.c  **** 
  18:strcpy-asm.c  **** #undef strcpy
  19:strcpy-asm.c  **** char *strcpy_STD (dest, src)
  20:strcpy-asm.c  ****      char *dest;
  21:strcpy-asm.c  ****      const char *src;
  22:strcpy-asm.c  **** {
  87              		.loc 1 22 0
  88              		.cfi_startproc
  89 0078 55       		pushq	%rbp
  90              		.cfi_def_cfa_offset 16
  91              		.cfi_offset 6, -16
  92 0079 4889E5   		movq	%rsp, %rbp
  93              		.cfi_def_cfa_register 6
  94 007c 48897DD8 		movq	%rdi, -40(%rbp)
  95 0080 488975D0 		movq	%rsi, -48(%rbp)
  23:strcpy-asm.c  ****   char c;
  24:strcpy-asm.c  ****   char *s = (char *) src;
  96              		.loc 1 24 0
  97 0084 488B45D0 		movq	-48(%rbp), %rax
  98 0088 488945F0 		movq	%rax, -16(%rbp)
  25:strcpy-asm.c  ****   const ptrdiff_t off = dest - s - 1;
  99              		.loc 1 25 0
 100 008c 488B55D8 		movq	-40(%rbp), %rdx
 101 0090 488B45F0 		movq	-16(%rbp), %rax
 102 0094 4829C2   		subq	%rax, %rdx
 103 0097 4889D0   		movq	%rdx, %rax
 104 009a 4883E801 		subq	$1, %rax
 105 009e 488945F8 		movq	%rax, -8(%rbp)
 106              	.L6:
  26:strcpy-asm.c  **** 
  27:strcpy-asm.c  ****   do
  28:strcpy-asm.c  ****     {
  29:strcpy-asm.c  ****       c = *s++;
 107              		.loc 1 29 0 discriminator 1
 108 00a2 488B45F0 		movq	-16(%rbp), %rax
 109 00a6 488D5001 		leaq	1(%rax), %rdx
 110 00aa 488955F0 		movq	%rdx, -16(%rbp)
 111 00ae 0FB600   		movzbl	(%rax), %eax
 112 00b1 8845EF   		movb	%al, -17(%rbp)
  30:strcpy-asm.c  ****       s[off] = c;
 113              		.loc 1 30 0 discriminator 1
 114 00b4 488B55F8 		movq	-8(%rbp), %rdx
 115 00b8 488B45F0 		movq	-16(%rbp), %rax
 116 00bc 4801C2   		addq	%rax, %rdx
 117 00bf 0FB645EF 		movzbl	-17(%rbp), %eax
 118 00c3 8802     		movb	%al, (%rdx)
  31:strcpy-asm.c  ****     }
  32:strcpy-asm.c  ****   while (c != '\0');
 119              		.loc 1 32 0 discriminator 1
 120 00c5 807DEF00 		cmpb	$0, -17(%rbp)
 121 00c9 75D7     		jne	.L6
  33:strcpy-asm.c  **** 
  34:strcpy-asm.c  ****   return dest;
 122              		.loc 1 34 0
 123 00cb 488B45D8 		movq	-40(%rbp), %rax
  35:strcpy-asm.c  **** }
 124              		.loc 1 35 0
 125 00cf 5D       		popq	%rbp
 126              		.cfi_def_cfa 7, 8
 127 00d0 C3       		ret
 128              		.cfi_endproc
 129              	.LFE2:
 131              	.Letext0:
 132              		.file 2 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
