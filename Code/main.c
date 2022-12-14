/******************************************************************************************
  Filename    : main.c
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 04.06.2021
  
  Description : main application implementation
  
******************************************************************************************/

//=====================================================================================================
// Includes
//=====================================================================================================
#include "FE310.h"
#include "mtimer.h"
#include "riscv-csr.h"

#define MTIME_TIMEOUT_LED_PHASE 1000U

//=====================================================================================================
// Functions prototype
//=====================================================================================================
void Isr_MachineTimerInterrupt(void);

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
int main(void)
{
  /* start the mtimer */
  mtimer_StartTimer(MTIME_TIMEOUT_MS(MTIME_TIMEOUT_LED_PHASE));

  /* endless loop*/
  while(1);

  return(0);
}


//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
void Isr_MachineTimerInterrupt(void)
{
  /* toggle the blue led */
  GPIO0->output_val.bit.pin5 ^= 1;

  /* reload the mtimer */
  mtimer_ReloadTimer(MTIME_TIMEOUT_MS(MTIME_TIMEOUT_LED_PHASE));
}


