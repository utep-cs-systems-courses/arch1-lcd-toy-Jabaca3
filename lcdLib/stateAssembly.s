#include "lcddraw.h"	
#include "switches.h"
#include "lcdutils.h"
#include "stateAssembly.h"
	
	.arch msp430g2553
	.p2align 1,0
	.text
	
	.data
s:	
	.word 1

jt:
	.word case1
	.word case2
	.word case3
	.word case4
	.text	
	.global state_advance
	
	
state_advance:
	mov 0x001f, r12		;moving COLOR_RED into r12
	Call #my_shape		;making shape
	cmp #4, &s
	jhs default		;jump if s>4

	mov &s, r12
	add r12, r12
	mov jt(r12), r0		; jumps to jt[s]

case1:
	add #1, &s
	mov #10, r12
	Call #move_shape_Left
	
case2:
	add #1, &s
	mov #10, r12
	Call #move_shape_Down
	jmp end
case3:
	add #1, &s
	mov #10, r12
	Call #move_shape_Right
	jmp end
case4:
	add #1, &s
	mov #10, r12
	Call #move_shape_Up
	jmp default
	
default:
	mov #0, &s
end:
	pop r0
