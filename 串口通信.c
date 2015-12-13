#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar flag,get;
void set_COM()
{
	REN=1;//打开串口通信
	SM0=0;
	SM1=1;//工作方式1
}
void set_timer()
{
	TMOD=0x20;//定时器1工作方式1
	TH1=0xfd;
	TL1=0xfd;//9600比特率
	TR1=1;
}
void set_init()
{
	EA=1;//打开总中断
	ES=1;//允许串口中断
}
void ser()interrupt 4
{
	RI=0;
	P1=SBUF;
	get=SBUF;
	flag=1;
}
void main()
{
	set_COM();
	set_init();
	set_timer();
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			flag=0;
			SBUF=get;
			while(!TI);
			TI=0;
			ES=1;
		}
	}
}