#include "defines.h"

#include "delay.h"

#include <LPC21xx.h>




#define SIN0  8     //p0.8

#define CP0   9     //p0.9

#define SIN1  10    //p0.10

#define CP1   11 	//p0.11

#define SIN2  12    //p0.12

#define CP2   13 	//p0.13

#define SIN3  14    //p0.14

#define CP3   15 	//p0.15




void Init_74LS164(void)

{

        IODIR0|= (1<<CP0|1<<SIN0);

        IODIR0|= (1<<CP1|1<<SIN1);

        IODIR0|= (1<<CP2|1<<SIN2);

        IODIR0|= (1<<CP3|1<<SIN3);

}


void SIPO_74LS164_1(unsigned char sDat) //Serial In Parallel Out(SIPO) Operations

{

   unsigned char i;

   //SCLRBIT(IOCLR0,_MR);

   //delay_us(1);

   //SSETBIT(IOSET0,_MR);

   //delay_us(1);


   for(i=0;i<8;i++)

   {


                   WRITEBIT(IOPIN0,SIN0,((sDat>>(7-i))&1));

                   SSETBIT(IOSET0,CP0);

                   delay_us(1);

                   SCLRBIT(IOCLR0,CP0);

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

                            WRITEBIT(IOPIN0,SIN1,((sDat>>(7-i))&1));

                            SSETBIT(IOSET0,CP1);

                            delay_us(1);

                            SCLRBIT(IOCLR0,CP1);

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

                            WRITEBIT(IOPIN0,SIN2,((sDat>>(7-i))&1));

                           SSETBIT(IOSET0,CP2);

                           delay_us(1);

                           SCLRBIT(IOCLR0,CP2);

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

                    WRITEBIT(IOPIN0,SIN3,((sDat>>(7-i))&1));

                   SSETBIT(IOSET0,CP3);

                   delay_us(1);

                   SCLRBIT(IOCLR0,CP3);

                   delay_us(1);

        }

}
