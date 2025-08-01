#include <LPC21xx.H>

#include<string.h>
#include "types.h"
#include "delay.h"
#include "defines.h"
#include "uart.h"
#include "i2c.h"
#include "i2c_eeprom.h"
#include "i2c_defines.h"
#include "lcd.h"
#include "dml.h"
#include "sipo.h"
//extern char buff[100];
extern unsigned char i,r_flag,buff[100];
extern u8 i_flag;
char str[]="WELCOME TO MAJOR PROJECT",rstr[100],mystr[100],passkey[]="@153",j;
char msg[]="   SYNTAX ERROR   ";

main()
{
	int l,pass_len;
	IODIR0|=255<<16; 
	InitUART0();
	init_i2c();
	Init_74LS164();

	l=strlen(str);
	pass_len=strlen(passkey)-1;
	i2c_eeprom_page_write(I2C_SADDR,PASS_ADDR,(u8 *)str,l);
	i2c_eeprom_seq_read(I2C_SADDR,PASS_ADDR,(u8 *)rstr,l);
	while(1)
	{
		mystr[0]=' ';
		mystr[1]=' ';
		mystr[2]=' ';
		for(i=0;rstr[i];i++)
		{
			mystr[i+3]=rstr[i];
		}
		i=i+3;
		mystr[i++]=' ';
		mystr[i++]=' ';
		mystr[i++]=' ';
		mystr[i]='\0';
		memset(buff,'\0',100);
		l=strlen(mystr);
		i=0;
		do
		{
			for(j=0;j<(l-3);j++)
			{
				display_str((unsigned char *)mystr+j,500);
				if(r_flag==1)
				break;
			}
		}while(r_flag==0);
		r_flag=0;
		if(strstr((const char *)buff,(const char *)passkey))
		{
			//memmove(buff,buff+pass_len,strlen((const char *)buff+pass_len+1)+1);
			l=strlen((const char *)buff);
			memset(rstr,'\0',100);
			memset(mystr,'\0',100);
			i2c_eeprom_page_write(I2C_SADDR,PASS_ADDR,buff+4,l);
			i2c_eeprom_seq_read(I2C_SADDR,PASS_ADDR,(u8 *)rstr,l);
		}
		else
		{
			 for(j=0;j<(l-3);j++)
			{
				display_str((unsigned char *)mystr+j,500);
			}
		}
	}
}

