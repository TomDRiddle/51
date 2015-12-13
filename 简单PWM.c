#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit PWM=P2^4;
uchar count=0;
uchar N=70;
void init()
	{
	 TMOD=0x01;   
	 TH0=(65536-20000)/256; 
	 TL0=(65536-20000)%256;
	 EA=1;	   
	 ET0=1;	   
	 TR0=1;	   
	}
void time_0() interrupt 1  
	{
	 TH0=(65536-200)/256;   
	 TL0=(65536-200)%256;
	 count++;
	 if(count<=N)
	 	PWM=1;
	 else 
	    PWM=0;
	 if(count>=100)
	    count=0;
	}
void main()
	{
	 init();
	 while(1);
	}
