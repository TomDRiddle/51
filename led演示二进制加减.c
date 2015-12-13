#include<reg51.h>
void delay(unsigned int ms)
{
	unsigned int j;
	unsigned char i;
	for(j=0;j<ms;j++)
	{
		for(i=0;i<125;i++)
		{;}
	}
}

void main(void)
{
    while(1)
	{
	   unsigned int i;
	   for(i=0x00;i<0xff;i++)
	   {
	       P1=i;
		   delay(1000);
		   }
		P1=0xff;
		delay(2000);
	   		
	} 
}