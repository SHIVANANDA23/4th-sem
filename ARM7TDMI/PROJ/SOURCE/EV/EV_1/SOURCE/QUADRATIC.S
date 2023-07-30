  area equation_1,code,readonly
	 entry
	 ldr r4,=0x4; x value stored in r4 register
	 ldr r0,=0x6
	 mul r1,r4,r4
	 mul r1,r0,r1
	 ldr r2,=0x3
	 mul r5,r4,r2
	 sub r3,r1,r5
	 add r3,r3,#5
	 end 