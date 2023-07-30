#include<lpc21xx.h>

#define delay() for(j=0;j<65000;j++);
#define sw1 0x00800000
int j;

#define bitset(x) (1<<x)
#define bitclr(x) (0<<x)

#define on 0x00000400
#define off 0x00000c00

//PROTOTYPES
void uart();
void send(char* a);
void send_char(char a);
void recieve();
int keypad();

 int keypad()
	{
		int value,i;
unsigned int row0[4]={0x006e0000,0x006d0000,0x006b0000,0x00670000};


  while(1)
  {
   IO1PIN=0x006F0000;  //01101111
   value=IO1PIN;
   delay();
   delay();
   value=value&0x007F0000;
   for(i=0;i<4;i++)
    {
      if(value==row0[ i])
      {
      return (i);
      
      }
    }
  }

}

void uart()
{
  PINSEL0=0x05;//PO.0 01-TXD   PO.1 01-RXD    
	U0LCR=0X83;  //7TH BIT IS DL ENABLE
	U0DLL=0X61;
	U0LCR=0X03;  //8BIT WITH A START AND A STOP BIT
}

void send(char* sptr)
{
	while(*sptr!='\0')
	{
		send_char(*sptr);
		sptr++;
	}	
}

void send_char(char a)
{
	while(!(U0LSR&0X20));
	U0THR=a;
}
 void recieve()
 { int x=sw1;
	 int I;
	 if((x&IOPIN1)!=x)//READ THE SWITCH
	 {
		 send("WATER SUPPLAY IS THERE\r\n");		
     I=keypad();
		 if(I==1)
		 {
			 IOSET0=on;
		    delay();
		 }
		 else if(I==0)
			 IOCLR0=off;
	 }
	 else
	 {
		 if((IOPIN0&on)==on)
		 {
			 send("Water supply unavialable\r\n Please turn off The Motor\r\n");
			 I=keypad();
			 if(I==1)
			 {
			   send("Instruction Override: Motor is turning off\r\n ");				 
				 IOCLR0=off;
			 }
			 else
			 {
				 IOCLR0=off;
			 }
		 }
		 else 
		 {
			 send ("e Water supply unavialable\r\n");
		 }
	 }
 }

	 
int main()
{
	PINSEL0=0X0;
  IODIR0|=bitset(10)|bitset(11);
	PINSEL2=0X0;//P1.16-31 AS GPIO
	IODIR1=0x00700000;//MAKING SWITCH AS INPUT P1.20-23
	uart();    //INITIALIZE THE UART
	while(1)
  recieve();
}
