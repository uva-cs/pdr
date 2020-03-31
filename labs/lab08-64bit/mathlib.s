; mathlib
;
; Purpose : This file contains the implementation of the function
;           product, which multiplies two numbers iteratively.
;
; Parameter 1 (in rdi) is the first number
; Parameter 2 (in rsi) is the second number
; Return value is a long that is the product of the inputs
;

	global product

	section .text

product:
	; Standard prologue
	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
start:	
	cmp	r10, rsi	 ; does i == b?
	je	done		 ; if so, we are done with the loop
	add	rax, rdi   ; add a to rax
	inc	r10		     ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
done:	
	; Standard epilogue
	ret
