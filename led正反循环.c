#include<reg51.h>
unsigned int LED[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
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
void xunhuan(unsigned int ms,unsigned int t)
{
    unsigned int a;
	unsigned int k; 
    for(a=0;a<t;a++)
	{
	    for(k=0;k<8;k++)
		{
		    P1=LED[k];
			delay(ms);
		}
		for(k=8;k>0;k--)
		{
			P1=LED[k];
			delay(ms);
		}
	}
	P1=0xff;
	delay(1000);
}
void main(void)
{
    while(1)
	{
	   xunhuan(200,2);
	   xunhuan(300,5);		
	} 
}