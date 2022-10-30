; nasm -f elf64 self-contained-hello-world-program.s
; ld -m elf_x86_64 self-contained-hello-world-program.o -o self-contained-hello-world-program

; I want a program that outputs "hello world" on console on my x86_64 based Linux computer. Yes, a complete program, not something silly that needs an interpreter or a compiler to work.
;
; You may:
;
; use all glibc functionality
; submit a static executable
; submit a dynamic executable with dependencies if you outline them
; compile an ELF file
; dig into the ELF format and remove all unneeded stuff
; be creative and work around the ELF format
; Describe here how you create and execute the program.
;
; The shortest program wins.

%define SYS_WRITE 1
%define SYS_EXIT 60

section .data
	msg db "Hello, World!", 0xa
	msglen equ $ -msg

section .text
	global _start

_start:
	mov rax, SYS_WRITE
	mov rdi, 1
	mov rsi, msg
	mov rdx, msglen
	syscall

	mov rax, SYS_EXIT
	mov rdi, 0
	syscall

