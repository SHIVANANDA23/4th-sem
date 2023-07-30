#include<lpc21xx.h>

#define sw0 0x00100000
#define delay() for(i=0;i<10000;i=i+1);
int main()
{   int x,i;
	PINSEL2=0X00000000;//P1.16-31
	PINSEL1=0X00000000;//P0.16-31
	IODIR1=0X00000000;
	IODIR0=0X000f0000;
	while(1)
	{
	x=IOPIN1&sw0;
	if(x==sw0)
	{
		IOSET0=0X000F0000;
		  delay();
	}
	else
	{
				IOCLR0=0X000F0000;
		    delay();
	}
}
}
