#include <lpc21xx.h>
#include <stdio.h>

#define MAX_OCCUPANCY 4

void delay(unsigned int count) {
  unsigned int i;
  for (i = 0; i < count; i++);
}

void initGPIO() {
	PINSEL1 = 0x00;
	PINSEL2 = 0x00;
  // output for LEDs
	IODIR0=0x000f0000;

  // input for switches
  IODIR1= 0x00000000;
}

int countOccupancy() {
  int count = 0;
	int x;
	x = IO1PIN;
	x=x&0x00F00000;
  // Check each switch status
  if (!(IO1PIN & (1 << 16)))
    count++;
  if (!(IO1PIN & (1 << 17)))
    count++;
  if (!(IO1PIN & (1 << 18)))
    count++;
  if (!(IO1PIN & (1 << 19)))
    count++;

  return count;
}

void displayOccupancy(int count) {
  // Display the occupancy using LEDs
  IO0PIN &= ~(0x0000000F); // Clear previous LED status
  IO0PIN |= (count & 0x0F); // Set LEDs based on occupancy count
}

void initUART() {
  PINSEL0 = 0x00000005;  
  U0LCR = 0x83;
  U0DLL = 0x61;
  U0LCR = 0x03;
}

void sendUART(char data) {
  // Wait until the transmit holding register is empty
  while (!(U0LSR & 0x20));
  
  // Send the data
  U0THR = data;
}

void sendStringUART(const char* str) {
  while (*str) {
    sendUART(*str);
    str++;
  }
}
void startDCMotor(){
	PINSEL0=0x00000000;
	IODIR0=0x00000C00;
	IOCLR0=0x00000800;
	IOSET0=0x00000400;
	delay(20000);
}

void stopDCMotor(){
	PINSEL0=0x00000000;
	IODIR0=0x00000C00;
	IOSET0=0x00000000;
	delay(20000);
}

int main() {
  int occupancy = 0;
  int previousOccupancy = 0;
  int temperature = 25; // Initial temperature
  char buffer[50];
  int ac = 0;
  initGPIO();
  initUART();
  sendStringUART("TEMPERATURE MAINTANENCE SYSTEM.\n\n");

  while (1) {
    occupancy = countOccupancy();
    displayOccupancy(occupancy);
    
    if (occupancy > previousOccupancy) {
      // Person entered the room
			temperature++;
      sprintf(buffer, "Person entered the room. Total members: %d. Temperature: %d degrees.\r\n", occupancy, temperature);
      sendStringUART(buffer);
      
      if (occupancy > 0) {
				// start cooling
				if(ac==0){
						// if ac was off, start AC
						ac = 1;
						startDCMotor();
				}
        sendStringUART("AC turned on.\r\n");
      }
    } else if (occupancy < previousOccupancy) {
      // Person left the room
			temperature--;
      sprintf(buffer, "Person left the room. Total members: %d. Temperature: %d degrees.\r\n", occupancy, temperature);
      sendStringUART(buffer);
      
      if (occupancy == 0) {
        // Stop the cooling
				ac = 0;
				stopDCMotor();
        sendStringUART("AC turned off.\r\n");
      }
    }
    
    previousOccupancy = occupancy;
        
    delay(500); // Delay for 500 milliseconds
  }
  
  return 0;
}