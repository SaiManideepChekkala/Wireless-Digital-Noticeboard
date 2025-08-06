#include "defines.h"
#include "delay.h"
#include <LPC21xx.h>


#define SIN  16     //p0.8
#define CP   17    //p0.9
#define SIN1  18     //p0.8
#define CP1  19     //p0.9
#define SIN2  20     //p0.8
#define CP2   21     //p0.9
#define SIN3  22     //p0.8
#define CP3   23     //p0.9


void Init_74LS164(void)
{
        IODIR1 |= ((1<<CP|1<<SIN)|(1<<CP1|1<<SIN1)|(1<<CP2|1<<SIN2)|(1<<CP3|1<<SIN3));
}

void SIPO_74LS164_1(unsigned char sDat) //Serial In Parallel Out(SIPO) Operations
{
   unsigned char i;
   //SCLRBIT(IOCLR0,_MR);
   //delay_us(16);
   //SSETBIT(IOSET0,_MR);
   //delay_us(1);

   for(i=0;i<8;i++)
   {
                   WRITEBIT(IOPIN1,SIN,((sDat>>(7-i))&1));
                   SSETBIT(IOSET1,CP);
                   delay_us(1);
                   SCLRBIT(IOCLR1,CP);
                   delay_us(1);
   }
 }
void SIPO_74LS164_2(unsigned char sDat) //Serial In Parallel Out(SIPO) Operations
{
   unsigned char i;
   //SCLRBIT(IOCLR0,_MR);
   //delay_us(1);
   //SSETBIT(IOSET0,_MR);
   //delay_us(1);

   for(i=0;i<8;i++)
   {
                   WRITEBIT(IOPIN1,SIN1,((sDat>>(7-i))&1));
                   SSETBIT(IOSET1,CP1);
                   delay_us(1);
                   SCLRBIT(IOCLR1,CP1);
                   delay_us(1);
   }
 }
void SIPO_74LS164_3(unsigned char sDat) //Serial In Parallel Out(SIPO) Operations
{
   unsigned char i;
   //SCLRBIT(IOCLR0,_MR);
   //delay_us(1);
   //SSETBIT(IOSET0,_MR);
   //delay_us(1);

   for(i=0;i<8;i++)
   {
                   WRITEBIT(IOPIN1,SIN2,((sDat>>(7-i))&1));
                   SSETBIT(IOSET1,CP2);
                   delay_us(1);
                   SCLRBIT(IOCLR1,CP2);
                   delay_us(1);
   }
 }
void SIPO_74LS164_4(unsigned char sDat) //Serial In Parallel Out(SIPO) Operations
{
   unsigned char i;
   //SCLRBIT(IOCLR0,_MR);
   //delay_us(1);
   //SSETBIT(IOSET0,_MR);
   //delay_us(1);

   for(i=0;i<8;i++)
   {
                   WRITEBIT(IOPIN1,SIN3,((sDat>>(7-i))&1));
                   SSETBIT(IOSET1,CP3);
                   delay_us(1);
                   SCLRBIT(IOCLR1,CP3);
                   delay_us(1);
   }
 }


