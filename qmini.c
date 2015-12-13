#include<reg51.h>
sbit wela = P2 ^ 7;
sbit dula = P2 ^ 6;
unsigned int both[] = {0x7e, 0xbd, 0xdb, 0xe7};
unsigned int LED[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
unsigned int DU[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
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
	delay(5);
	wela = 1;
	P2 = we;
	wela = 0;
	delay(5);
}
/*void end()
{
	unsigned int i;
	unsigned int letter[] = {0xf9, 0xb7, 0xde};
	unsigned int loc[] = {0xdf,0xbf,0x7f};
	for (i = 0; i < 100; i++)
	{
		dula = 1;
		P0 = letter[i];
		dula = 0;
		delay(5);
		wela = 1;
		P0 = loc[i];
		wela = 0;
		delay(5);
	}
}*/
void S_1(void)
{
	unsigned int t;
	shuma(0xef, DU[1]);
	for (t = 0; t < 3; t++)
	{
		P1 = 0x00;
		delay(500);
		P1 = 0xff;
		delay(500);
	}
	//end();
}
void S_2(void)
{
	unsigned int t;
	unsigned int i;
	shuma(0xef, DU[2]);
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
	//end();

}
void S_3(void)
{
	unsigned int t;
	unsigned int i;
	shuma(0xef, DU[3]);
	for (t = 0; t < 3; t++)
	{
		P1 = 0xff;
		for (i = 0; i < 8; i++)
		{
			P1 = P1 << 1;
			delay(500);
		}
		P1 = 0xff;
		for (i = 0; i < 8; i++)
		{
			P1 = P1 >> 1;
			delay(500);
		}
		P1 = 0xff;
	}
	//end();
}
void S_4(void)
{
	unsigned int t;
	unsigned int i;
	shuma(0xef, DU[4]);
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
	//end();
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
