//lcd.c
#include "types.h"
#include <LPC21xx.h>
#include "lcd_defines.h"
#include "defines.h"
#include "delay.h"

void WriteLCD(u8 byte)
{
IOCLR0=1<<LCD_RW;
WRITEBYTE(IOPIN1,LCD_DATA,byte);
IOSET0=1<<LCD_EN;
delay_us(1);
IOCLR0=1<<LCD_EN;
delay_ms(2);
}
void CmdLCD(u8 cmd)
{
IOCLR0=1<<LCD_RS;
WriteLCD(cmd);
}
void InitLCD(void)
{
WRITEBYTE(IODIR1,LCD_DATA,0XFF);
SETBIT(IODIR0,LCD_RS);
SETBIT(IODIR0,LCD_RW);
SETBIT(IODIR0,LCD_EN);
delay_ms(15);
CmdLCD(0x30);
delay_ms(4);
delay_us(100);
CmdLCD(0x30);
delay_us(100);
CmdLCD(0x30);
CmdLCD(MODE_8BIT_2LINE);
CmdLCD(DSP_ON_CUR_BLINK);
CmdLCD(CLEAR_LCD);
CmdLCD(SHIFT_CUR_RIGHT);
}
void CharLCD(u8 asciiVal)
{
IOSET0=1<<LCD_RS;
WriteLCD(asciiVal);
}
void SetCursor(u8 lineNo,u8 POS)
{
if(lineNo==1)
CmdLCD(GOTO_LINE1_POS0+POS);
else if(lineNo==2)
CmdLCD(GOTO_LINE2_POS0+POS);
}
void StrLCD(s8 *str)
{
while(*str)
CharLCD(*str++);
}
void U32LCD(u32 num)
{
  u8 a[10];
  s32 i=0;
  if(num==0)
  CharLCD('0');
  else
  {
  while(num!=0)
  {
  a[i++]=(num%10)+48;
  num/=10;
  }
  for(--i;i>=0;i--)
  CharLCD(a[i]);
   }
  }
  void S32LCD(s32 num)
  {
  if(num<0)
  {
  CharLCD('-');
  num=-num;
  }						 
  U32LCD(num);
 }
  void F32LCD(f32 fNum,u32 nDP)
  {
  s32 iNum;
  if(fNum<0.0)
  {
  CharLCD('-');
  fNum=-fNum;
  }
  iNum=fNum;
  U32LCD(iNum);
  CharLCD('.');
  while(nDP)
  {
  fNum=(fNum-iNum)*10;
  iNum=fNum;
  CharLCD(iNum+48);
  nDP--;
  }
  }
