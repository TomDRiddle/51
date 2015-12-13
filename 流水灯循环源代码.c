#include<reg51.h>
void delay(unsigned int ms)
{
	unsigned int j;
	unsigned char i;
	for(j=0;j<ms;j++){
	    for(i=0;i<125;i++)
		{;}
	}
}
unsigned int LED[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void main(void)
{	
while(1)
{
    unsigned int i;
    for(i=0;i<8;i++)
	{
	    P1=LED[i];	 
		delay(2000);
	}
}
}