#include<lpc214x.h>
#include<stdio.h>

//Function prototypes
void lcd_init(void);
void wr_cn(void);
void clr_disp(void);
void delay(unsigned int);
void lcd_com(void);						   
void wr_dn(void);
void lcd_data(void);
unsigned char temp1;
unsigned long int temp,r=0;
unsigned char *ptr,disp[] = "TEAM 14",disp1[] = "LCD INTERFACING";
int main()
{	
	IO0DIR = 0x000000FC;		//configure o/p lines for lcd 
  lcd_init();            //lcd intialisation
	delay(3200);	
    clr_disp();					//clear display
	delay(3200);            
  temp1 = 0x81;				//Display starting address	of first line 2nd pos
	lcd_com();
	ptr = disp;
    while(*ptr!='\0')
    {
   		temp1 = *ptr;
     	lcd_data();
	 	ptr ++;
    }
temp1 = 0xC0;			// Display starting address of second line 1st pos
	lcd_com();
  	ptr = disp1;   
	while(*ptr!='\0')
    {            temp1 = *ptr;
    	lcd_data();
		ptr ++;
    }while(1);
}  //end of main()	
// lcd initialisation routine.
void lcd_init(void)
{
	int a[]={0x30, 0x30, 0x30, 0x20, 0x28, 0x0C, 0X06, 0X80 };
	unsigned int i;
	for(i=0 ; i<8 ; i++)
	{
	temp = a[i];		   
	wr_cn();
	delay(3200);
	}  
}	
void lcd_com(void)
{  temp = temp1 & 0xf0;
    wr_cn();
    temp = temp1 & 0x0f;
    temp = temp << 4; 
    wr_cn();
    delay(500);
}
// command nibble o/p routine
void wr_cn(void)                //write command reg
{ 	 
  IO0CLR  = 0x000000FC;		// clear the port lines.
	IO0SET 	= temp;				// Assign the value to the PORT lines    
	IO0CLR  = 0x00000004;		// clear bit  RS = 0
	IO0SET 	= 0x00000008;   	// E=1
	delay(100);
	IO0CLR  = 0x00000008;
}
// data nibble o/p routine
void wr_dn(void)			////write data reg
{  	  
	IO0CLR = 0x000000FC;	// clear the port lines.
	IO0SET = temp;			// Assign the value to the PORT lines 
	IO0SET = 0x00000004;   	// set bit  RS = 1 	
	IO0SET = 0x00000008;   	// E=1
	delay(10);
	IO0CLR = 0x00000008;
}
void lcd_data(void)
{   	         
	temp = temp1 & 0xf0;
    temp = temp ;//<< 6;
    wr_dn();
    temp= temp1 & 0x0f;	
    temp= temp << 4;
    wr_dn();
    delay(1000);					
} 
void clr_disp(void)
{
    temp1 = 0x01;
    lcd_com();
    delay(5000);					
}  

void delay(unsigned int r1)
{
	for(r=0;r<r1;r++);
}