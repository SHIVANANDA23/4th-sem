#include<lpc21xx.h>

#define delay(x) for(i=0;i<x;i++);
#define DC 0x00000C00
int i;


  int keypad()
	{
		unsigned int row0[4]={0x00ee0000,0x00ed0000,0x00eb0000,0x00e70000};
	 unsigned int value,i;
	 IO1PIN=0x00EF0000;
	 value=IO1PIN;
	 delay(10000);
	 delay(10000);
	 value=value&0x00FF0000;
while(1)
{
	 for(i=0;i<4;i++)
		{
			if(value==row0[i])
			{
		       return i;
			}
		}
}
}
int main()
{
unsigned int value;
	PINSEL2=0x00;
	PINSEL0=0x00;
	IODIR0=DC;
	IODIR1=0x00F00000;
	
}