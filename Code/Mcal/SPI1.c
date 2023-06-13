/******************************************************************************************
  Filename    : SPI1.c
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 12.06.2023
  
  Description : SPI1 driver implementation
  
******************************************************************************************/

//=====================================================================================================
// Includes
//=====================================================================================================
#include "FE310.h"
#include "SPI1.h"
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
void FE310_SPI1_Init(void)
{
  /* Configure the programmed IO pins */
  GPIO0->iof_sel.bit.pin2 = 0u; // SPI1_SS0
  GPIO0->iof_sel.bit.pin3 = 0u; // SPI1_MOSI
  GPIO0->iof_sel.bit.pin4 = 0u; // SPI1_MISO
  GPIO0->iof_sel.bit.pin5 = 0u; // SPI1_SCK

  /* Enable the programmed IO pins */
  GPIO0->iof_en.bit.pin2 = 1u; // SPI1_SS0
  GPIO0->iof_en.bit.pin3 = 1u; // SPI1_MOSI
  GPIO0->iof_en.bit.pin4 = 1u; // SPI1_MISO
  GPIO0->iof_en.bit.pin5 = 1u; // SPI1_SCK

  /* Configure the SPI controller */
  QSPI1->sckdiv.bit.div  = 95u; // 1MHz
  QSPI1->sckmode.bit.pha = 0u;  // Clock phase = 0 ==> data sampled on rising edge and shifted out on the falling edge
  QSPI1->sckmode.bit.pol = 0u;  // Clock polarity = 0 ==> idle state of the clock is low
  QSPI1->csid            = 0u;  // SS0 is selected
  QSPI1->csmode.bit.mode = 2u;  // CS mode is HOLD
  QSPI1->fmt.bit.proto   = 0u;  // Mode is SPI
  QSPI1->fmt.bit.endian  = 0u;  // Transmit most-significant bit (MSB) first
  QSPI1->fmt.bit.dir     = 0u;  // FIFO is used
  QSPI1->fmt.bit.len     = 8u;  // 8 bits per frame
}

//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
boolean FE310_SPI1_Transfer(uint8* txdata, uint8* rxdata, uint8 size)
{
  uint32 SavedIntLevel = 0;

  if((size > 8u) || (0u == size) || (NULL == txdata) || (NULL == rxdata))
  {
    return(FALSE);
  }
  else
  {
    /* set the Rx watermark */
    QSPI1->rxmark.bit.rxmark = size - 1;

    /* set CS control mode (HOLD) */
    QSPI1->csmode.bit.mode = 2u;

    /* enter the critical section to protect the Tx FIFO fill-out from being interrupted */
    SavedIntLevel = csr_read_clr_bits_mstatus(MSTATUS_MIE_BIT_MASK);

    /* fill the Tx FIFO */
    for(uint32 i = 0; i < size; i++)
      QSPI1->txdata.bit.data = txdata[i];

    /* exit the critical section */
    csr_write_mstatus(SavedIntLevel);

    /* wait for the Rx FIFO to be full */
    while(!QSPI1->ip.bit.rxwm);

    /* set CS control mode (OFF) */
    QSPI1->csmode.bit.mode = 3u;

    /* read the RX FIFO */
    for(uint32 i = 0; i < size; i++)
      rxdata[i] = QSPI1->rxdata.bit.data;

    return(TRUE);
  }
}
