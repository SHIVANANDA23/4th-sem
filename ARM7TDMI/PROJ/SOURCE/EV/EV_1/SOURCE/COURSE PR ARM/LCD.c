#include<lpc214x.h>
#include<stdio.h>
#include<string.h>

#define bit(x) (1<<x)
#define delay for(i=0;i<65000;i++);
#define trig (1<<8)             //P0.8
#define echo (IO0PIN&(1<<9))         //P0.9 as EINT3
void ultrasonic_init();
void send_pulse();
unsigned int get_range();

void timer0delay(unsigned int a);
void timer1delay(unsigned int b);

void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void lcd_delay();

void timer0delay(unsigned int a)    //1ms
{
    T0CTCR=0X0000;
    T0PR=59999;
    T0MR0=a;
    T0MCR=0x00000004;
    T0TCR=0X02;
    T0TCR=0X01;
    while(T0TC!=T0MR0);
    T0TC=0;
}

void timer1delay(unsigned int b)   //1us
{
    T1CTCR=0X0000;
    T1PR=59;
    T1MR0=b;
    T1MCR=0x00000004;
    T1TCR=0X02;
    T1TCR=0X01;
    while(T1TC!=T1MR0);
    T1TC=0;
}




void ultrasonic_init()
{
    IO0DIR|=(1<<8);
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

void lcd_init()
{
    cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x0c);
    cmd(0x80);
	
}

void cmd(unsigned char a)
{
    IO1PIN&=0x00;
    IO1PIN|=(a<<24);
    IO1CLR|=bit(16);                   //rs=0
    IO1CLR|=bit(17);                   //rw=0
    IO1SET|=bit(18);                    //en=1
    lcd_delay();
    IO1CLR|=bit(18);                    //en=0
}

void dat(unsigned char b)
{
    IO1PIN&=0x00;
    IO1PIN|=(b<<24);
    IO1SET|=bit(16);                   //rs=1
    IO1CLR|=bit(17);                   //rw=0
    IO1SET|=bit(18);               //en=1
    lcd_delay();
    IO1CLR|=bit(18);               //en=0
}

void show(unsigned char *s)
{
    while(*s) {
        dat(*s++);
    }
}

void lcd_delay()
    {
    unsigned int i;
    for(i=0;i<=1000;i++);
}


unsigned int range=0,i;

int main()
{	char str[5];
    VPBDIV=0x01;                 // PCLK = 60MHz
    IO1DIR=0xffffffff;
    ultrasonic_init();
    lcd_init();
    show("Distance : ");
			
    while(1) 
		{
        cmd(0x8b);
        range=get_range();
        dat((range/100)+48);
        dat(((range/10)%10)+48);
        dat((range%10)+48);
		//	sprintf(str,"%d",get_range());
		//	show(str);
			if(range<30){
				 show("Alert");
				cmd(0x18);	
			}
			else{
       show("Safe Zone");
			}
        delay;
        delay;
    }
		delay;
}