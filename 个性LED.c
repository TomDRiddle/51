#include<reg51.h>
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
unsigned int both[]={0x7e,0xbd,0xdb,0xe7};
unsigned int LED[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void main(void)
{
unsigned int i;
unsigned int t;
	for(t=0;t<3;t++)
	{
		for(i=0;i<4;i++)
		{
			P1=LED[2*i];
			delay(300);
		}
		i=0;
		for(i=0;i<4;i++)
		{
			P1=LED[2*i+1];
			delay(300);
		}
	}
	for(t=0;t<3;t++)
	{	
		for(i=0;i<7;i++)
		{
		P1=LED[i];
		delay(300);
		}
		P1=LED[7];
		for(i=7;i>0;i--)
		{
		P1=LED[i];
		delay(300);
		}
	}
	P1=0xff;
	for(t=0;t<3;t++)
	{
			P1=both[0];
			delay(300);
			P1=both[1];
			delay(300);
			P1=both[2];
			delay(300);
			P1=both[3];
			delay(300);
			P1=both[2];
			delay(300);
			P1=both[1];
			delay(300);
			P1=both[0];
			delay(300);	
	}
	for(t=0;t<3;t++)
	{
		P1=0x00;
		delay(300);
		P1=0xff;
		delay(300);
	}
	while(1)
	{
		P1=0xff;
	}
}