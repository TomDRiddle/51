#include<reg51.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit wela = P2 ^ 7;
sbit dula = P2 ^ 6;
uint t_50ms = 0;
uchar hour = 0;
uchar min = 0;
uchar sec = 0;
uchar buf[] = {0, 0, 0, 0, 0, 0};
uint DU[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
uchar code POS[] = {0xfd, 0xfe, 0xdf, 0xef, 0xf7, 0xfb};

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

void init_timer0(void)
{
	TMOD = 0x01;
	TL0 = -(50000 % 256);
	TH0 = -(50000 / 256);
	TR0 = 1;
	ET0 = 1;
}

void int_timer0()interrupt 1
{
	TL0 = -(50000 % 256);
	TH0 = -(50000 / 256);
	t_50ms++;

	if (t_50ms >= 20)
	{
		t_50ms = 0;
		sec++;

		if (sec >= 0)
		{
			sec = 0;
			min++;

			if (min >= 60)
			{
				min = 0;
				hour++;

				if (hour >= 24)
				{
					hour = 0;
				}
			}
		}
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

void disp(void)
{
	uchar i, j;
	for (i = 0; i < 6; i++)
	{
		j=buf[i];
		shuma(POS[i],DU[j]);
	}
}

void main()
{
	init_timer0();
	EA = 1;
	while (1)
	{
		buf[0] = sec % 10;
		buf[1] = sec / 10;
		buf[2] = min % 10;
		buf[3] = min / 10;
		buf[4] = hour % 10;
		buf[5] = hour / 10;
		disp();
	}
}