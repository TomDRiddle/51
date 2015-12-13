#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
sbit rs=P2^0;
sbit lcden=P2^2;
uchar code table[]="  Hello world!";
uchar num;
void delay(uint ms)
{
	uint i;
	uchar j;
	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 125; j++)
		{;}
	}
}


void write_com(uchar com)
{
	rs=0;
	lcden=0;
	P0=com;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;	
}

void write_date(uchar date)
{
	rs=1;
	lcden=0;
	P0=date;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
	
}

void init()
{

	dula=0;
	wela=0;
	lcden=0;

	write_com(0x38);
	write_com(0x0c);
	write_com(0x06);
	write_com(0x01);


}
void main()
{
	init();
	write_com(0x80);
	for(num=0;num<15;num++)
	{
		write_date(table[num]);
		delay(5);
	}
	while(1);
}