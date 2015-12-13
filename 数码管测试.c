#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit wela = P2 ^ 7;
sbit dula = P2 ^ 6;
uint DU[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
uchar code POS[6]={0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
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
void shuma(unsigned int we, unsigned int du)
{
	dula = 1;
	P0 = du;
	dula = 0;
	wela = 1;
	P0 = we;
	wela = 0;
	delay(5);
	wela = 1;
	P0 = 0xff;
	wela = 0;
}
void main()
{
	while(1)
	{
		uint i;
		for(i=0;i<6;i++)
		{
			shuma(POS[i],DU[i]);
		}
	}
}