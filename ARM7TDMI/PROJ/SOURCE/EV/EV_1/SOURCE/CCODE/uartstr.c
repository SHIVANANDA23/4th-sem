#include<lpc21xx.h>
void cmd(unsigned int);
void data(unsigned int);
void delay(unsigned int);
int main()
{
unsigned  char msg[]={"welcome KLETECH"};
unsigned  int c[]={0x30,0x30,0x20,0x20,0x28,0x01,0x06,0x0e,0x80};
unsigned int i,j;
PINSEL0=0x00000000;
IODIR0=0x000000fc;
	for(i=0;i<9;i++)
	{
		cmd(c[i]);
		delay(100000);
	}
while(1)
	{ 
		cmd(0x81);
		delay(100000);
		for(j=0;j<15;j++)
		{		
			data(msg[j]);
			delay(500);
		}  
		delay(65000);
		delay(65000);
		delay(65000);
		cmd(0x01);
		delay(65000);
		delay(65000);
		delay(65000);
		delay(65000);
	}  
}

void cmd(unsigned int value)
{
	unsigned int y;
	y=value;
	y=y & 0xf0;
	IOCLR0=0x000000fc;
	IOCLR0=0X00000004;   //rs=0
	IOSET0=y;
	IOSET0=0x00000008;  //en=1
	delay(10);
	IOCLR0=0x00000008;   //en=0
	y=value;
	y=y & 0x0f;
	y=y<<4;
	IOCLR0=0x000000fc;
	IOCLR0=0X00000004; //rs=0
	IOSET0=y; 
	IOSET0=0x00000008;
	delay(100);
	IOCLR0=0x00000008;
}

void data(unsigned int dat)
{
	unsigned int y;
	y=dat;
	y=y & 0xf0;
	IOCLR0=0x000000fc;
  IOSET0=0X00000004;  //rs=1
	IOSET0=y; 
	IOSET0=0x00000008; //en=1
	delay(10);
	IOCLR0=0x00000008; //en=0
	y=dat;
	y=y & 0x0f;
	y=y<<4;
	IOCLR0=0x000000fc;	 
	IOSET0=0X00000004;
	IOSET0=y;
	IOSET0=0x00000008;
	delay(100);
	IOCLR0=0x00000008;
}
void delay(unsigned int x)
{
	unsigned int del;
  for(del=0;del<x;del++);
}