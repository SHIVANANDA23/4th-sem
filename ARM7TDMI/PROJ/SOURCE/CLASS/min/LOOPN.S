  AREA SHIVA,CODE,READONLY
	  ENTRY
	  LDR R0,=100
	  MOV R1,#20
	  LDR R5,=10
	  LDR R6,=200
	  MOV R2,#20
LOOP  CMP R0,#0
	  BEQ EN
	  SUB R0,R0,#1
	  CMP R5,R6
	  BNE MULTI
	  MOV R10,#11	  
	  B LOOP  
MULTI 
      ADD R5,R5,R2
      SUB R1,R1,#1
      CMP R1,#0
      BEQ LOOP
      B MULTI	
EN    NOP
      END