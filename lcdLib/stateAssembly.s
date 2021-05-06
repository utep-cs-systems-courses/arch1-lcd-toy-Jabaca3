#include "lcddraw.h"	
#include "switches.h"
#include "lcdutils.h"
#include "stateAssembly.h"


jt:
	.word case1
	.word case2
	.word case3
	.word case4
	.text	
	.global state_advance
	.global buzzer_state_advance
	
state_advance:
	mov 0x001f, r12		;moving COLOR_RED into r12
	Call #my_shape		;testing making shape with r12
	
buzzer_state_advance:
	jmp end
	
case1:
	jmp end
case2:
	jmp end
case3:
	jmp end
case4:
	jmp end
end:
	ret
