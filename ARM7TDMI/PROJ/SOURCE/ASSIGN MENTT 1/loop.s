  AREA AA,CODE,readonly
     ENTRY
     mov r1,#0x00  ;b
     mov r0,#0x100  ;a
     cmp r0,#0x10  ;compare
     MOVGE r1,#0X10  
     MOVLT r3,r0  ;r3==>c
STOP B STOP
 end