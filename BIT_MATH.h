/***************************************************************************************/
/********************************  Hythm Saad Khalifa **********************************/
/***************************************************************************************/
/****** This file is developed by Hythm Saad Khalifa, All copyrights are reserved ******/
/***************************************************************************************/

#ifndef BIT_MATH_h
#define BIT_MATH_h

#define SET_BIT(Reg,Bit_Number) Reg| = (1<<(Bit_Number))

#define CLR_BIT(Reg,Bit_Number) Reg& = ~(1<<(Bit_Number))

#define TOG_BIT(Reg,Bit_Number) Reg^ = (1<<(Bit_Number))

#define GET_BIT(Reg,Bit_Number) ((Reg)>>(Bit_Number))&(0x01)

#endif