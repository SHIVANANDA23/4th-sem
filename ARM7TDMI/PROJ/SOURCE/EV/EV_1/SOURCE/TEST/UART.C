#include<lpc21xx.h>
void uart();
void send(char *sp);
void DEL();

void DEL()
{int i;
   for(i=0;i<1000000;i++);
}
void send(char *sp)
{
	while(*sp!='\0')
	{
		while(!(U0LSR&0x20));
     U0THR=*sp;
     sp++;
	}
    
}
void uart()
{
    U0LCR=0x83;
    U0DLL=0x61;
    U0LCR=0x03;
}
int main()
{	
	int x;
char a[]={"HI I AM In"};
char B[]={"HI I AM not In"};
	char *sptr;
	PINSEL0=0x00000005;
  PINSEL2=0X00000000;
	IODIR0=0X00000Cfc;
  IODIR1=0X00000000;
  uart();
	x = IO1PIN;
	x=x&0x00010000;
  // Check each switch status
  if (!(IO1PIN & x)==x)
	{
		sptr=a;
    send(sptr);
		IOSET0=0X00000C00;
	}
	else
	{
		sptr=B;
    send(sptr);
			IOSET0=0X00000400;
		
	}
}
	