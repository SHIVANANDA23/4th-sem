#include<lpc214x.h>

#define bitset(x) (1<<x)
#define bitckr(x) (0<<x)

#define delay() for(i=0;i<6000;i++);
#define on 0x00000400
#define off 0x00000c00

int main()
{int i;
	PINSEL0=0X05;
	IODIR0|=bitset(10)|bitset(11);
	IOSET0=on;
	delay();
}
