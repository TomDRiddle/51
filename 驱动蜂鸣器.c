#include<reg51.h>
sbit BUZ1=P3^7;
void delay(unsigned int ms)
{
	unsigned int i;
	unsigned char j;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<125;j++)
		{;}
	}
}
void main(void)
{
	while(1)
	{
		BUZ1=~BUZ1;
		delay(1000);
	}
}