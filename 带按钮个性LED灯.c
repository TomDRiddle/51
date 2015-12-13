#include<reg51.h>
sbit wela = P2 ^ 7;
sbit dula = P2 ^ 6;
unsigned int both[] = {0x7e, 0xbd, 0xdb, 0xe7};
unsigned int LED[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
unsigned int LED2[] = {0x0, 0x1, 0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff};
unsigned int DU[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned int letter[] = {0x79, 0x37, 0x5e};
unsigned int loc[] = {0x7f, 0xbf, 0xdf};
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
void end()
{
	unsigned int i;

	while (1)
	{
		dula = 1;
		P0 = letter[0];
		dula = 0;
		wela = 1;
		P0 = loc[0];
		wela = 0;
		delay(10);
		wela = 1;
		P0 = 0xff;
		wela = 0;

		dula = 1;
		P0 = letter[1];
		dula = 0;
		wela = 1;
		P0 = loc[1];
		wela = 0;
		delay(10);
		wela = 1;
		P0 = 0xff;
		wela = 0;

		dula = 1;
		P0 = letter[2];
		dula = 0;
		wela = 1;
		P0 = loc[2];
		wela = 0;
		delay(10);
		wela = 1;
		P0 = 0xff;
		wela = 0;
	}
}
void S_1(void)
{
	unsigned int t;
	shuma(0xdf, DU[1]);
	for (t = 0; t < 3; t++)
	{
		P1 = 0x00;
		delay(500);
		P1 = 0xff;
		delay(500);
	}
	end();
}
void S_2(void)
{
	unsigned int t;
	unsigned int i;
	shuma(0xdf, DU[2]);
	for (t = 0; t < 3; t++)
	{
		P1 = 0xff;
		for (i = 0; i < 7; i++)
		{
			P1 = LED[i];
			delay(300);
		}
		P1 = LED[7];
		for (i = 7; i > 0; i--)
		{
			P1 = LED[i];
			delay(300);
		}
		P1 = 0xff;
	}
}
void S_3(void)
{
	unsigned int t;
	unsigned int i;
	shuma(0xdf, DU[3]);
	for (t = 0; t < 3; t++)
	{
		P1 = 0x00;
		for (i = 0; i < 8; i++)
		{
			P1 = LED2[i];
			delay(500);
		}
		P1 = 0x00;
		for (i = 0; i < 8; i++)
		{
			P1 = LED2[8 - i];
			delay(500);
		}
		P1 = 0xff;
	}
}
void S_4(void)
{
	unsigned int t;
	unsigned int i;
	shuma(0xdf, DU[4]);
	for (t = 0; t < 3; t++)
	{
		P1 = 0xff;
		for (i = 0; i < 3; i++)
		{
			P1 = both[i];
			delay(300);
		}
		for (i = 3; i > 0; i--)
		{
			P1 = both[i];
			delay(300);
		}
	}
	P1 = 0xff;
}
void main(void)
{
	while (1)
	{

		if (P3 == 0xfb)
		{
			delay(10);
			if (P3 == 0xfb)
			{
				S_1();
			}
		}
		else if (P3 == 0xf7)
		{
			delay(10);
			if (P3 == 0xf7)
			{
				S_2();
			}
		}
		else if (P3 == 0xef)
		{
			delay(10);
			if (P3 == 0xef)
			{
				S_3();
			}
		}
		else if (P3 == 0xdf)
		{
			delay(10);
			if (P3 == 0xdf)
			{
				S_4();
			}
		}
	}
}
