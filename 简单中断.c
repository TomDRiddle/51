#include<reg52.h>
void delay(unsigned int ms)
{
	unsigned int i;
	unsigned char j;
	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 125; j++)
		{;}
	}
}
void init()
{
	EX0=1;
	IT0=0;
	EA=1;
}
void main(void)
{
	init();
	while(1)
	{
		P1=0;
	}
}
void int0() interrupt 0
{
	P1=0xff;
	delay(5000);
}