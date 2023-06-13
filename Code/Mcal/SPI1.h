/******************************************************************************************
  Filename    : SPI1.h
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 12.06.2023
  
  Description : SPI1 driver header file
  
******************************************************************************************/

#ifndef __SPI1_H__
#define __SPI1_H__

//=====================================================================================================
// Functions prototype
//=====================================================================================================
void FE310_SPI1_Init(void);
boolean FE310_SPI1_Transfer(uint8* txdata, uint8* rxdata, uint8 size);

#endif /* __SPI1_H__ */


