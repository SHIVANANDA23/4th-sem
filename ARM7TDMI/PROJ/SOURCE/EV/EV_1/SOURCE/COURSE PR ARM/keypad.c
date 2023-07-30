#include<lpc21xx.h>
void delay()
{
unsigned int y;
for(y=0;y<90000;y++);
}

void disp(unsigned int x)
{
	int a[16]={0x003F0000,0x00060000,0x005B0000,0x004F0000,0x00660000,0x006D0000,0x007D0000,0x00070000,0x007F0000,0x006F0000,0x00770000,0x007C0000,
0x00390000,0x005E0000,0x00790000,0x00710000};
	IOCLR0=0x00FF0000;
	delay();
  IOSET0=0x10000000;
	IOSET0=a[x];
	delay();
}
	
int main()
{
unsigned int value,i;
unsigned int row0[4]={0x00ee0000,0x00ed0000,0x00eb0000,0x00e70000};
unsigned int row1[4]={0x00de0000,0x00dd0000,0x00db0000,0x00d70000};
unsigned int row2[4]={0x00de0000,0x00bd0000,0x00bb0000,0x00b70000};
unsigned int row3[4]={0x007e0000,0x007d0000,0x007b0000,0x00770000};

	PINSEL2=0x00;
	PINSEL1=0x00;
	IODIR0=0x10FF0000;
	IODIR1=0x00F00000;
	while(1)
	{
	 IO1PIN=0x00EF0000;
	 value=IO1PIN;
	 delay();
	 delay();
	 value=value&0x00FF0000;
	 for(i=0;i<4;i++)
		{
			if(value==row0[i])
			{
			disp(i);
			delay();
			}
		}
	 IO1PIN=0x00DF0000;
	 value=IO1PIN;
	 delay();
	 delay();
	 value=value&0x00FF0000;
	 for(i=0;i<4;i++)
		{
			if(value==row1[i])
			{
			disp(i+4);
			delay();
			}
		}
	 IO1PIN=0x00BF0000;
	 value=IO1PIN;
	 delay();
	 delay();
	 value=value&0x00FF0000;
	 for(i=0;i<4;i++)
		{
			if(value==row2[i])
			{
			disp(i+8);
			delay();
			}
		}
	 IO1PIN=0x007F0000;
	 value=IO1PIN;
	 delay();
	 delay();
	 value=value&0x00FF0000;
	 for(i=0;i<4;i++)
		{
			if(value==row3[i])
			{
			disp(i+12);
			delay();
			}
		}
	}
}