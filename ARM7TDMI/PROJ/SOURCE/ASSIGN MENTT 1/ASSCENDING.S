   AREA SORT, CODE, READONLY

    ENTRY

    ; initialize array
    LDR R0, =array      ; load address of array into R0
    LDR R1, =len        ; load array length into R1
    LDR R2, =temp       ; load temporary storage into R2
    LDR R3, =1          ; set flag to true (1) in R3

sort_loop
    MOV R4, #0          ; reset flag to false (0)
    MOV R5, #0          ; initialize index to 0

    cmp R5, R1          ; compare index with array length
    beq sort_done       ; exit loop if index equals array length

inner_loop
    ADD R6, R0, R5, LSL #2  ; calculate address of current element
    LDR R7, [R6]        ; load current element into R7
    ADD R8, R0, R5, LSL #2  ; calculate address of next element
    ADD R8, R8, #4      ; increment address to next element
    LDR R9, [R8]        ; load next element into R9
    CMP R7, R9          ; compare current element with next element
    BLS next            ; branch if less than or equal to next element
    STR R9, [R6]        ; swap current and next elements
    STR R7, [R8]
    MOV R4, #1          ; set flag to true (1)
next
    ADD R5, R5, #1      ; increment index
    B inner_loop        ; repeat inner loop until index equals array length

    CMP R4, #1          ; compare flag with true (1)
    BNE sort_done       ; exit sort loop if flag equals false (0)

    SUB R1, R1, #1      ; decrement array length
    B sort_loop         ; repeat sort loop until flag equals false (0)

sort_done
    B stop

    ; data section
array   DCW 9, 2, 6, 3, 8, 1, 5, 7, 4
len     DCW 9             ; length of array
temp    DCW 0             ; temporary storage for swapping

    ; stop program execution
stop b stop

   END