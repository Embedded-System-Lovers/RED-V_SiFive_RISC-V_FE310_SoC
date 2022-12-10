/******************************************************************************************
  Filename    : core.s
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 04.06.2021
  
  Description : core routine 

******************************************************************************************/

.file "core.s"

/*******************************************************************************************
  \brief  
  
  \param  
  
  \return 
********************************************************************************************/
.section .text
.type __CSR_Read_mcause, @function
.align 4
.globl __CSR_Read_mcause

__CSR_Read_mcause:
                   csrr x10, mcause
                   ret
                   nop

.size __CSR_Read_mcause, .-__CSR_Read_mcause

/*******************************************************************************************
  \brief  
  
  \param  
  
  \return 
********************************************************************************************/
.section .text
.type __CSR_ClearPendingBits, @function
.align 4
.globl __CSR_ClearPendingBits

__CSR_ClearPendingBits:
                        csrrc zero, mip, x10
                        ret
                        nop

.size __CSR_ClearPendingBits, .-__CSR_ClearPendingBits



