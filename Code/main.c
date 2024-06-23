/******************************************************************************************
  Filename    : main.c
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 04.06.2021
  
  Description : main application implementation
  
******************************************************************************************/

// cd /mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/RED-V_SiFive_RISC-V_FE310_SoC
// wget --no-check-certificate https://buildbot.embecosm.com/job/riscv32-gcc-ubuntu2204-release/10/artifact/riscv32-embecosm-ubuntu2204-gcc13.2.0.tar.gz
// tar -xzf riscv32-embecosm-ubuntu2204-gcc13.2.0.tar.gz -C /mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/RED-V_SiFive_RISC-V_FE310_SoC
// PATH="/mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/RED-V_SiFive_RISC-V_FE310_SoC/riscv32-embecosm-ubuntu2204-gcc13.2.0/bin:$PATH"
// bash ./Rebuild.sh

//=====================================================================================================
// Includes
//=====================================================================================================
#include <FE310.h>
#include <mtimer.h>
#include <riscv-csr.h>

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
