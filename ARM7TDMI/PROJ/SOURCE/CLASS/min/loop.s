  AREA SHIVA CODE READONLY
	  ENTRY
	  LDR R0,=100
	  LDR R5,=10
	  LDR R6,=200
LOOP  CMP R0,0
	  BEQ EN
	  CMP R5,R6
	  SUB R0,R0,#1
	  MOV R10,#0
	  B LOOP  
MULTI MOV R1,#20
	  LDR R2,R5
      ADD R5,R5,R2
      SUB R1,R1,#1
      CMP R1,#0
      BEQ LOOP
      B MULTI	
EN    NOP
      END