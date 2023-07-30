area xyz,code,readonly
		entry
	ldr r2,=0x40000000 ; To take user input from this location
	ldr
	LDR R0,[r2]     ; user input is stored in r0
	CMP R0, #10     ; Compare with 10
	BLT freezing    ; Branch if less than 10
	CMP R0, #25     ; Compare with 25
	BLT cold        ; Branch if less than 25
	CMP R0, #35     ; Compare with 35
	BLT normal      ; Branch if less than 35
	B hot           ; Branch if greater than or equal to 35
freezing ldr


done BL 0x0007FFFF
stop B stop 
   end