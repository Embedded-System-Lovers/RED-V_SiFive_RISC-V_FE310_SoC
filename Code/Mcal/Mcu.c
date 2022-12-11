/******************************************************************************************
  Filename    : Mcu.c
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 11.12.2022
  
  Description : Microcontroller routine implementation
  
******************************************************************************************/

//=====================================================================================================
// Includes
//=====================================================================================================
#include "FE310.h"
#include "Mcu.h"
#include "riscv-csr.h"

//=====================================================================================================
// Functions prototype
//=====================================================================================================

//=====================================================================================================
// Macros
//=====================================================================================================

//=====================================================================================================
// Globals
//=====================================================================================================


//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
void FE310_HwInitialization(void)
{
  GPIO0->output_en.bit.pin5 = 1;
  GPIO0->output_val.bit.pin5 = 1;

  /* Disable all PLIC interrupts */
  PLIC->enable[0] = 0;
  PLIC->enable[1] = 0;

  /* turn on the global interrupt enable flag */
  csr_write_mstatus(8);
}
