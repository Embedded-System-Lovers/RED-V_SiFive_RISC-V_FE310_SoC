/******************************************************************************************
  Filename    : boot.s
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 04.06.2021
  
  Description : boot routine 

******************************************************************************************/

.file "boot.s"

/*******************************************************************************************
  \brief  
  
  \param  
  
  \return 
********************************************************************************************/
.section .text
.type _start, @function
.align 4
.extern __STACK_TOP
.extern DirectModeInterruptHandler
.extern Startup_Init
.globl _start

_start:
        /* disable all interrupts flag */
        csrrs x0, mstatus, x0
       
        /* setup the stack pointer */
        la sp, __STACK_TOP
       
        /* setup the direct interrupt handler */
        la t0, DirectModeInterruptHandler
        csrrs x0, mtvec, t0
       
        /* enable specific interrupt sources */
        li t0, 8
        csrrs x0, mie, t0
       
        /* turn on the global interrupt enable flag */
        li t0, 8
        csrrs x0, mstatus, t0
       
        jal   Startup_Init

.size _start, .-_start


/*******************************************************************************************
  \brief  
  
  \param  
  
  \return 
********************************************************************************************/
.type _delay, @function
.align 4
.globl _delay

_delay:
        addi x10, x10, -1
        bne x10, x0, _delay
        ret
        nop

.size _delay, .-_delay
