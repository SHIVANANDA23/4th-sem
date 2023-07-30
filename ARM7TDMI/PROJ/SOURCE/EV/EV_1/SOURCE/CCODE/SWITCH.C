#include <lpc21xx.h>
#include <stdio.h>

#define UART_BAUD_RATE 9600
__irq void UART0_Interrupt(void);
void uart0_init();
void uart0_send_string(const char* str) ;

void uart0_init() {
    PINSEL0 =0x05; // Select UART0 Rx and Tx pins
    U0LCR = 0x83; // Enable DLAB (Divisor Latch Access Bit)
    U0DLL = 0x61;
    U0DLM = 0x00;
    U0LCR = 0x03; // 8-bit data, 1 stop bit, no parity
    U0IER = 0x02; // Enable RDA (Receive Data Available) interrupt
    VICVectAddr0 = (unsigned)UART0_Interrupt; // UART0 ISR Address
    VICVectCntl0 = (1 << 5) | 6; // UART0 Interrupt Slot and Enable
    VICIntEnable = (1 << 6); // Enable UART0 Interrupt
    U0IER |= (1 << 1); // Enable THRE (Transmit Holding Register Empty) interrupt
}

__irq void UART0_Interrupt(void){
    unsigned char received_data;
    
    if (U0IIR & (0x02)) {
			 uart0_send_string("transmistting\r\n");
        U0IIR=0X02;
    }
    VICVectAddr = 0; // Acknowledge interrupt
}

void uart0_send_char(char c) {
    while (!(U0LSR & (1 << 5))); // Wait until THR is empty
    U0THR = c; // Send character
}

void uart0_send_string(const char* str) {
    while (*str) {
        uart0_send_char(*str++);
    }
}

int main() {
    uart0_init(); // Initialize UART0
    uart0_send_string("Serial Interrupt\r\n");
    while (1) {
        
    }
}