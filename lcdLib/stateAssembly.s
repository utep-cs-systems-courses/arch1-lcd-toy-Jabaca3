#include "lcddraw.h"	
	
	.file "stateAssembly.c"
.text
	.global update_state
	.word default
	.word Case1
	.word Case2
	.word Case3

Case1:
	call
	jmp n
Case2:
	call
	jmp n
Case3:
	call
	jmp n
	
default:
	call
	
n:
	ret
