#include<lpc214x.h>
#include<stdio.h>
#define trig (1<<5)   //P0.8
#define echo (IO0PIN&(1<<9))         //P0.9 as EINT3
#define SOUND_SPEED 34300        // Speed of sound in cm/s
#define DANGER_ZONE_DISTANCE 40  // Danger zone distance in cm

void ultrasonic_init();
void send_pulse();
unsigned int get_range();

void timer1delay(unsigned int b)   //1us
{
    T1CTCR=0X0000;
    T1PR=11;
    T1MR0=b;
    T1MCR=0x00000004;
    T1TCR=0X02;
    T1TCR=0X01;
    while(T1TC!=T1MR0);
    T1TC=0;
}

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 10000; j++) ;
    }
}


void ultrasonic_init()
{
    IO0DIR|=(1<<5);
    T0CTCR=0;
    T0PR=59;
}

void send_pulse()
{
    T0TC=T0PC=0;
    IO0SET=trig;                            //trig=1
    timer1delay(10);                        //10us delay
    IO0CLR=trig;                            //trig=0
}

unsigned int get_range()
{
    unsigned int get=0;
    send_pulse();
    while(!echo);
    T0TCR=0x01;
    while(echo);
    T0TCR=0;
    get=T0TC;

    if(get<38000)
        get=get/59;
    else
        get=0;

    return get;
}

void uart_init(void) {
    PINSEL0 |= 0x00000005;  // Enable UART0 Rx and Tx pins
    U0LCR = 0x83;           // 8-bit data, 1-stop bit, DLAB = 1
    U0DLM = 0x00;           // Set baud rate to 9600
    U0DLL = 0x61;           //   (PCLK = 15MHz)
    U0LCR = 0x03;           // 8-bit data, 1-stop bit, DLAB = 0
}

void uart_send_char(char c) {
    while (!(U0LSR & 0x20));  // Wait until the Transmit Holding Register is empty
    U0THR = c;                // Transmit the character
}

void uart_send_string(const char *str) {
    while (*str!='\0') {
        uart_send_char(*str++);
    }
}

	int main(void) 
		{
    unsigned int distance;
    char buffer[16];
    uart_init();                        // Initialize UART
    uart_send_string("Distance (cm): "); // Print text

    while (1) {
			  ultrasonic_init();
        distance = get_range();          // Measure distance
        sprintf(buffer, "%d\r\n", distance);     // Convert distance to string
        uart_send_string(buffer);                // Send distance over UART

        if (distance < DANGER_ZONE_DISTANCE) {
            uart_send_string("Danger zone\r\n"); // Display "Danger zone"
        }

        delay_ms(1000);                   // Delay for 1 second
    }
}
