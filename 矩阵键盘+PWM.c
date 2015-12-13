#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit PWM=P2^4;
uchar key_value=8;
uchar time;

void set_timer()
{
	TMOD=0x01;        //定时器工作模式1
	TR0=1;            //开启定时器
	TH0=0xff;
	TL0=0xf7;         //100ms/1个中断
	ET0=1;            //开启定时器0
	EA=1;             //开启总中断
}

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

void key()
{
	uchar temp;

	P3=0xfe;
	temp=P3;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
				case 0xee:key_value=1;break;
				case 0xde:key_value=2;break;
				case 0xbe:key_value=3;break;
				case 0x7e:key_value=4;break;
			}
		}	
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
	}

	P3=0xfd;
	temp=P3;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
				case 0xed:key_value=5;break;
				case 0xdd:key_value=6;break;
				case 0xbd:key_value=7;break;
				case 0x7d:key_value=8;break;
			}
		}	
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
	}
	P3=0xfb;
	temp=P3;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
				case 0xeb:key_value=9;break;
				case 0xdb:key_value=0;break;
				//case 0xbb:key_value=10;break;
				//case 0xbb:key_value=11;break;
			}
		}	
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
	}
/*	P3=0xf7;
	temp=P3;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
				case 0xe7:key_value=12;break;
				case 0xd7:key_value=13;break;
				case 0xb7:key_value=14;break;
				case 0x77:key_value=15;break;
			}
		}	
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
	}
	*/
}

void main()
{
	set_timer();
	while(1)
	{
		key();
	}
}

void time0()interrupt 1
{
	TH0=0xff;
	TL0=0xf7;

	time++;
	if(time>=100)
		time=0;
	if(time<=key_value*10)
		PWM=1;
	else
		PWM=0;
}

