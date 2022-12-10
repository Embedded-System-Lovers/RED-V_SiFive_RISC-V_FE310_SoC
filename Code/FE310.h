
/********************************************************************************************************
 * @file     FE310.h
 *
 * @brief    FE310 Peripheral Access Layer Header File.
 *
 * @date     7. December 2022
 *
 * @note     Generated with SVDConv V2.87l from SVD File 'e310x.svd'
 *
 *******************************************************************************************************/

/** @addtogroup SiFive
  * @{
  */

/** @addtogroup FE310
  * @{
  */

#ifndef FE310_H
#define FE310_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
  #define   __I     volatile        
#else
  #define   __I     volatile const  
#endif
#define     __O     volatile        
#define     __IO    volatile        

#define     __IM     volatile const 
#define     __OM     volatile       
#define     __IOM    volatile       

typedef unsigned long uint32_t;

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */

/* ================================================================================ */
/* ================                      CLINT                     ================ */
/* ================================================================================ */


/**
  * @brief Coreplex Local Interrupts (CLINT)
  */

typedef struct {                                    /*!< (@ 0x02000000) CLINT Structure                                        */
  __IO uint32_t  msip;                              /*!< (@ 0x02000000) Hart 0 software interrupt register                     */
  __I  uint32_t  RESERVED[4095];
  __IO uint32_t  mtimecmp;                          /*!< (@ 0x02004000) Hart 0 time comparator register                        */
  __IO uint32_t  mtimecmph;                         /*!< (@ 0x02004004) Hart 0 time comparator register                        */
  __I  uint32_t  RESERVED1[8188];
  __IO uint32_t  mtime;                             /*!< (@ 0x0200BFF8) Timer register                                         */
  __IO uint32_t  mtimeh;                            /*!< (@ 0x0200BFFC) Timer register                                         */
} CLINT_Type;


/* ================================================================================ */
/* ================                      PLIC                      ================ */
/* ================================================================================ */


/**
  * @brief Platform Level Interrupt Control (PLIC)
  */

typedef struct {                                    /*!< (@ 0x0C000000) PLIC Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x0C000000) Interrupt Priority Register                            */
    
    struct {
      __IO uint32_t  priority   :  3;               /*!< [0..2] (null)                                                         */
    } bit;                                          /*!< [3] BitSize                                                           */
  } priority[53];
  __I  uint32_t  RESERVED[971];
  __IO uint32_t  pending[2];                        /*!< (@ 0x0C001000) Interrupt Pending Register                             */
  __I  uint32_t  RESERVED1[1022];
  __IO uint32_t  enable[2];                         /*!< (@ 0x0C002000) Interrupt Enable Register                              */
  __I  uint32_t  RESERVED2[522238];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x0C200000) Priority Threshold Register                            */
    
    struct {
      __IO uint32_t  priority   :  3;               /*!< [0..2] (null)                                                         */
    } bit;                                          /*!< [3] BitSize                                                           */
  } threshold;
  __IO uint32_t  claim;                             /*!< (@ 0x0C200004) Claim/Complete Register                                */
} PLIC_Type;


/* ================================================================================ */
/* ================                      WDOG                      ================ */
/* ================================================================================ */


/**
  * @brief Watchdog (WDOG)
  */

typedef struct {                                    /*!< (@ 0x10000000) WDOG Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000000) Watchdog Configuration Register                        */
    
    struct {
      __IO uint32_t  scale      :  4;               /*!< [0..3] (null)                                                         */
           uint32_t             :  4;
      __IO uint32_t  rsten      :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  zerocmp    :  1;               /*!< [9..9] (null)                                                         */
           uint32_t             :  2;
      __IO uint32_t  enalways   :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  encoreawake:  1;               /*!< [13..13] (null)                                                       */
           uint32_t             : 14;
      __IO uint32_t  cmpip      :  1;               /*!< [28..28] (null)                                                       */
    } bit;                                          /*!< [29] BitSize                                                          */
  } wdogcfg;
  __I  uint32_t  RESERVED;
  __IO uint32_t  wdogcount;                         /*!< (@ 0x10000008) Watchdog Counter Register                              */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  wdogs;                             /*!< (@ 0x10000010) Watchdog Scaled Counter Register                       */
  __I  uint32_t  RESERVED2;
  __IO uint32_t  wdogfeed;                          /*!< (@ 0x10000018) Watchdog Feed Register                                 */
  __O  uint32_t  wdogkey;                           /*!< (@ 0x1000001C) Watchdog Key Register                                  */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000020) Watchdog Compare Register                              */
    
    struct {
      __IO uint32_t  value      : 16;               /*!< [0..15] (null)                                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } wdogcmp;
} WDOG_Type;


/* ================================================================================ */
/* ================                       RTC                      ================ */
/* ================================================================================ */


/**
  * @brief Watchdog (RTC)
  */

typedef struct {                                    /*!< (@ 0x10000000) RTC Structure                                          */
  __I  uint32_t  RESERVED[16];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000040) RTC Configuration Register                             */
    
    struct {
      __IO uint32_t  scale      :  4;               /*!< [0..3] (null)                                                         */
           uint32_t             :  8;
      __IO uint32_t  enalways   :  1;               /*!< [12..12] (null)                                                       */
           uint32_t             : 15;
      __IO uint32_t  cmpip      :  1;               /*!< [28..28] (null)                                                       */
    } bit;                                          /*!< [29] BitSize                                                          */
  } rtccfg;
  __I  uint32_t  RESERVED1;
  __IO uint32_t  rtclo;                             /*!< (@ 0x10000048) RTC Counter Low Register                               */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1000004C) RTC Counter High Register                              */
    
    struct {
      __IO uint32_t  value      : 16;               /*!< [0..15] (null)                                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } rtchi;
  __IO uint32_t  rtcs;                              /*!< (@ 0x10000050) RTC Scaled Counter Register                            */
  __I  uint32_t  RESERVED2[3];
  __IO uint32_t  rtccmp;                            /*!< (@ 0x10000060) RTC Compare Register                                   */
} RTC_Type;


/* ================================================================================ */
/* ================                     AONCLK                     ================ */
/* ================================================================================ */


/**
  * @brief Always-On Clock Configuration (AONCLK)
  */

typedef struct {                                    /*!< (@ 0x10000000) AONCLK Structure                                       */
  __I  uint32_t  RESERVED[28];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000070) AON Clock Configuration Register                       */
    
    struct {
      __IO uint32_t  div        :  6;               /*!< [0..5] (null)                                                         */
           uint32_t             : 10;
      __IO uint32_t  trim       :  5;               /*!< [16..20] (null)                                                       */
           uint32_t             :  9;
      __IO uint32_t  enable     :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  ready      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } lfrosccfg;
} AONCLK_Type;


/* ================================================================================ */
/* ================                     BACKUP                     ================ */
/* ================================================================================ */


/**
  * @brief Backup Registers (BACKUP)
  */

typedef struct {                                    /*!< (@ 0x10000000) BACKUP Structure                                       */
  __I  uint32_t  RESERVED[32];
  __IO uint32_t  backup[16];                        /*!< (@ 0x10000080) Backup Register                                        */
} BACKUP_Type;


/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */


/**
  * @brief PMU (PMU)
  */

typedef struct {                                    /*!< (@ 0x10000000) PMU Structure                                          */
  __I  uint32_t  RESERVED[64];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000100) PMU Wake Program Memory                                */
    
    struct {
      __IO uint32_t  delay      :  4;               /*!< [0..3] (null)                                                         */
      __IO uint32_t  pmu_out_0_en:  1;              /*!< [4..4] (null)                                                         */
      __IO uint32_t  pmu_out_1_en:  1;              /*!< [5..5] (null)                                                         */
           uint32_t             :  1;
      __IO uint32_t  corerst    :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  hfclkrst   :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  isolate    :  1;               /*!< [9..9] (null)                                                         */
    } bit;                                          /*!< [10] BitSize                                                          */
  } pmuwakepm[8];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000120) PMU Sleep Program Memory                               */
    
    struct {
      __IO uint32_t  delay      :  4;               /*!< [0..3] (null)                                                         */
      __IO uint32_t  pmu_out_0_en:  1;              /*!< [4..4] (null)                                                         */
      __IO uint32_t  pmu_out_1_en:  1;              /*!< [5..5] (null)                                                         */
           uint32_t             :  1;
      __IO uint32_t  corerst    :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  hfclkrst   :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  isolate    :  1;               /*!< [9..9] (null)                                                         */
    } bit;                                          /*!< [10] BitSize                                                          */
  } pmusleeppm[8];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000140) PMU Interrupt Enable Register                          */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  rtc        :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  dwakeup    :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  awakeup    :  1;               /*!< [3..3] (null)                                                         */
    } bit;                                          /*!< [4] BitSize                                                           */
  } pmuie;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10000144) PMU Cause Register                                     */
    
    struct {
      __IO uint32_t  wakeupcause:  2;               /*!< [0..1] (null)                                                         */
           uint32_t             :  6;
      __IO uint32_t  resetcause :  2;               /*!< [8..9] (null)                                                         */
    } bit;                                          /*!< [10] BitSize                                                          */
  } pmucause;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x10000148) PMU Sleep Register                                     */
    
    struct {
      __O  uint32_t  sleep      :  1;               /*!< [0..0] (null)                                                         */
    } bit;                                          /*!< [1] BitSize                                                           */
  } pmusleep;
  __IO uint32_t  pmukey;                            /*!< (@ 0x1000014C) PMU Key Register                                       */
} PMU_Type;


/* ================================================================================ */
/* ================                      PRCI                      ================ */
/* ================================================================================ */


/**
  * @brief Power Reset Clock Interrupts (PRCI)
  */

typedef struct {                                    /*!< (@ 0x10008000) PRCI Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10008000) Clock Configuration Register                           */
    
    struct {
      __IO uint32_t  div        :  6;               /*!< [0..5] (null)                                                         */
           uint32_t             : 10;
      __IO uint32_t  trim       :  5;               /*!< [16..20] (null)                                                       */
           uint32_t             :  9;
      __IO uint32_t  enable     :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  ready      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } hfrosccfg;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10008004) Clock Configuration Register                           */
    
    struct {
           uint32_t             : 30;
      __IO uint32_t  enable     :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  ready      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } hfxosccfg;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10008008) PLL Configuration Register                             */
    
    struct {
      __IO uint32_t  pllr       :  3;               /*!< [0..2] (null)                                                         */
           uint32_t             :  1;
      __IO uint32_t  pllf       :  6;               /*!< [4..9] (null)                                                         */
      __IO uint32_t  pllq       :  2;               /*!< [10..11] (null)                                                       */
           uint32_t             :  4;
      __IO uint32_t  sel        :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  refsel     :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  bypass     :  1;               /*!< [18..18] (null)                                                       */
           uint32_t             : 12;
      __IO uint32_t  lock       :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } pllcfg;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1000800C) PLL Divider Register                                   */
    
    struct {
      __IO uint32_t  div        :  6;               /*!< [0..5] (null)                                                         */
           uint32_t             :  2;
      __IO uint32_t  divby1     :  1;               /*!< [8..8] (null)                                                         */
    } bit;                                          /*!< [9] BitSize                                                           */
  } plloutdiv;
  __IO uint32_t  coreclkcfg;                        /*!< (@ 0x10008010) Clock Configuration Register                           */
} PRCI_Type;


/* ================================================================================ */
/* ================                       OTP                      ================ */
/* ================================================================================ */


/**
  * @brief One Time Programmable Memory (OTP)
  */

typedef struct {                                    /*!< (@ 0x10010000) OTP Structure                                          */
  __IO uint32_t  lock;                              /*!< (@ 0x10010000) Programmed-I/O lock register                           */
  __IO uint32_t  clock;                             /*!< (@ 0x10010004) OTP device clock signal                                */
  __IO uint32_t  output_en;                         /*!< (@ 0x10010008) OTP device output-enable signal                        */
  __IO uint32_t  select;                            /*!< (@ 0x1001000C) OTP device chip-select signal                          */
  __IO uint32_t  write_en;                          /*!< (@ 0x10010010) OTP device write-enable signal                         */
  __IO uint32_t  mode;                              /*!< (@ 0x10010014) OTP device mode register                               */
  __IO uint32_t  mrr;                               /*!< (@ 0x10010018) OTP read-voltage regulator control                     */
  __IO uint32_t  mpp;                               /*!< (@ 0x1001001C) OTP write-voltage charge pump control                  */
  __IO uint32_t  vrren;                             /*!< (@ 0x10010020) OTP read-voltage enable                                */
  __IO uint32_t  vppen;                             /*!< (@ 0x10010024) OTP write-voltage enable                               */
  __IO uint32_t  addr;                              /*!< (@ 0x10010028) OTP device address                                     */
  __IO uint32_t  data_in;                           /*!< (@ 0x1001002C) OTP device data input                                  */
  __IO uint32_t  data_out;                          /*!< (@ 0x10010030) OTP device data output                                 */
  __IO uint32_t  rsctrl;                            /*!< (@ 0x10010034) OTP read sequencer control                             */
} OTP_Type;


/* ================================================================================ */
/* ================                      GPIO0                     ================ */
/* ================================================================================ */


/**
  * @brief General Purpose Input Output (GPIO0)
  */

typedef struct {                                    /*!< (@ 0x10012000) GPIO0 Structure                                        */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012000) Pin value.                                             */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } input_val;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012004) Pin Input Enable Register                              */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } input_en;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012008) Pin Output Enable Register                             */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } output_en;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001200C) Output Port Value Register                             */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } output_val;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012010) Internal Pull-Up Enable Register                       */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } pullup;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012014) Drive Strength Register                                */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } drive;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012018) Rise Interrupt Enable Register                         */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } rise_ie;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001201C) Rise Interrupt Pending Register                        */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } rise_ip;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012020) Fall Interrupt Enable Register                         */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } fall_ie;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012024) Fall Interrupt Pending Register                        */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } fall_ip;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012028) High Interrupt Enable Register                         */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } high_ie;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001202C) High Interrupt Pending Register                        */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } high_ip;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012030) Low Interrupt Enable Register                          */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } low_ie;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012034) Low Interrupt Pending Register                         */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } low_ip;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012038) HW I/O Function Enable Register                        */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } iof_en;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001203C) HW I/O Function Select Register                        */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } iof_sel;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10012040) Output XOR (invert) Register                           */
    
    struct {
      __IO uint32_t  pin0       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  pin1       :  1;               /*!< [1..1] (null)                                                         */
      __IO uint32_t  pin2       :  1;               /*!< [2..2] (null)                                                         */
      __IO uint32_t  pin3       :  1;               /*!< [3..3] (null)                                                         */
      __IO uint32_t  pin4       :  1;               /*!< [4..4] (null)                                                         */
      __IO uint32_t  pin5       :  1;               /*!< [5..5] (null)                                                         */
      __IO uint32_t  pin6       :  1;               /*!< [6..6] (null)                                                         */
      __IO uint32_t  pin7       :  1;               /*!< [7..7] (null)                                                         */
      __IO uint32_t  pin8       :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  pin9       :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  pin10      :  1;               /*!< [10..10] (null)                                                       */
      __IO uint32_t  pin11      :  1;               /*!< [11..11] (null)                                                       */
      __IO uint32_t  pin12      :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  pin13      :  1;               /*!< [13..13] (null)                                                       */
      __IO uint32_t  pin14      :  1;               /*!< [14..14] (null)                                                       */
      __IO uint32_t  pin15      :  1;               /*!< [15..15] (null)                                                       */
      __IO uint32_t  pin16      :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  pin17      :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  pin18      :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  pin19      :  1;               /*!< [19..19] (null)                                                       */
      __IO uint32_t  pin20      :  1;               /*!< [20..20] (null)                                                       */
      __IO uint32_t  pin21      :  1;               /*!< [21..21] (null)                                                       */
      __IO uint32_t  pin22      :  1;               /*!< [22..22] (null)                                                       */
      __IO uint32_t  pin23      :  1;               /*!< [23..23] (null)                                                       */
      __IO uint32_t  pin24      :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  pin25      :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  pin26      :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  pin27      :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  pin28      :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  pin29      :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  pin30      :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  pin31      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } out_xor;
} GPIO0_Type;


/* ================================================================================ */
/* ================                      UART0                     ================ */
/* ================================================================================ */


/**
  * @brief Universal Asynchronous Receiver Transmitter (UART0)
  */

typedef struct {                                    /*!< (@ 0x10013000) UART0 Structure                                        */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10013000) Transmit Data Register                                 */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< [0..7] (null)                                                         */
           uint32_t             : 23;
      __IO uint32_t  full       :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } txdata;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10013004) Receive Data Register                                  */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< [0..7] (null)                                                         */
           uint32_t             : 23;
      __IO uint32_t  empty      :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } rxdata;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10013008) Transmit Control Register                              */
    
    struct {
      __IO uint32_t  enable     :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  nstop      :  1;               /*!< [1..1] (null)                                                         */
           uint32_t             : 14;
      __IO uint32_t  counter    :  3;               /*!< [16..18] (null)                                                       */
    } bit;                                          /*!< [19] BitSize                                                          */
  } txctrl;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001300C) Receive Control Register                               */
    
    struct {
      __IO uint32_t  enable     :  1;               /*!< [0..0] (null)                                                         */
           uint32_t             : 15;
      __IO uint32_t  counter    :  3;               /*!< [16..18] (null)                                                       */
    } bit;                                          /*!< [19] BitSize                                                          */
  } rxctrl;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10013010) Interrupt Enable Register                              */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  rxwm       :  1;               /*!< [1..1] (null)                                                         */
    } bit;                                          /*!< [2] BitSize                                                           */
  } ie;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10013014) Interrupt Pending Register                             */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< [0..0] (null)                                                         */
      __IO uint32_t  rxwm       :  1;               /*!< [1..1] (null)                                                         */
    } bit;                                          /*!< [2] BitSize                                                           */
  } ip;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10013018) Baud Rate Divisor Register                             */
    
    struct {
      __IO uint32_t  value      : 16;               /*!< [0..15] (null)                                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } div;
} UART0_Type;


/* ================================================================================ */
/* ================                      QSPI0                     ================ */
/* ================================================================================ */


/**
  * @brief Quad Serial Peripheral Interface (QSPI0)
  */

typedef struct {                                    /*!< (@ 0x10014000) QSPI0 Structure                                        */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014000) Serial Clock Divisor Register                          */
    
    struct {
      __IO uint32_t  div        : 12;               /*!< [0..11] Divisor for serial clock                                      */
    } bit;                                          /*!< [12] BitSize                                                          */
  } sckdiv;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014004) Serial Clock Mode Register                             */
    
    struct {
      __IO uint32_t  pha        :  1;               /*!< [0..0] Serial clock phase                                             */
      __IO uint32_t  pol        :  1;               /*!< [1..1] Serial clock polarity                                          */
    } bit;                                          /*!< [2] BitSize                                                           */
  } sckmode;
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  csid;                              /*!< (@ 0x10014010) Chip Select ID Register                                */
  __IO uint32_t  csdef;                             /*!< (@ 0x10014014) Chip Select Default Register                           */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014018) Chip Select Mode Register                              */
    
    struct {
      __IO uint32_t  mode       :  2;               /*!< [0..1] Chip select mode                                               */
    } bit;                                          /*!< [2] BitSize                                                           */
  } csmode;
  __I  uint32_t  RESERVED1[3];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014028) Delay Control 0 Register                               */
    
    struct {
      __IO uint32_t  cssck      :  8;               /*!< [0..7] CS to SCK Delay                                                */
           uint32_t             :  8;
      __IO uint32_t  sckcs      :  8;               /*!< [16..23] SCK to CS Delay                                              */
    } bit;                                          /*!< [24] BitSize                                                          */
  } delay0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001402C) Delay Control 1 Register                               */
    
    struct {
      __IO uint32_t  intercs    :  8;               /*!< [0..7] Minimum CS inactive time                                       */
           uint32_t             :  8;
      __IO uint32_t  interxfr   :  8;               /*!< [16..23] Maximum interframe delay                                     */
    } bit;                                          /*!< [24] BitSize                                                          */
  } delay1;
  __I  uint32_t  RESERVED2[4];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014040) Frame Format Register                                  */
    
    struct {
      __IO uint32_t  proto      :  2;               /*!< [0..1] SPI protocol                                                   */
      __IO uint32_t  endian     :  1;               /*!< [2..2] SPI endianness                                                 */
      __IO uint32_t  dir        :  1;               /*!< [3..3] SPI I/O direction                                              */
           uint32_t             : 12;
      __IO uint32_t  len        :  4;               /*!< [16..19] Number of bits per frame                                     */
    } bit;                                          /*!< [20] BitSize                                                          */
  } fmt;
  __I  uint32_t  RESERVED3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014048) Transmit Data Register                                 */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< [0..7] Transmit data                                                  */
           uint32_t             : 23;
      __IO uint32_t  full       :  1;               /*!< [31..31] FIFO full flag                                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } txdata;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001404C) Receive Data Register                                  */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< [0..7] Received data                                                  */
           uint32_t             : 23;
      __IO uint32_t  empty      :  1;               /*!< [31..31] FIFO empty flag                                              */
    } bit;                                          /*!< [32] BitSize                                                          */
  } rxdata;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014050) Transmit Watermark Register                            */
    
    struct {
      __IO uint32_t  txmark     :  3;               /*!< [0..2] Transmit watermark                                             */
    } bit;                                          /*!< [3] BitSize                                                           */
  } txmark;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014054) Receive Watermark Register                             */
    
    struct {
      __IO uint32_t  rxmark     :  3;               /*!< [0..2] Receive watermark                                              */
    } bit;                                          /*!< [3] BitSize                                                           */
  } rxmark;
  __I  uint32_t  RESERVED4[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014060) SPI Flash Interface Control Register                   */
    
    struct {
      __IO uint32_t  en         :  1;               /*!< [0..0] SPI Flash Mode Select                                          */
    } bit;                                          /*!< [1] BitSize                                                           */
  } fctrl;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014064) SPI Flash Instruction Format Register                  */
    
    struct {
      __IO uint32_t  cmd_en     :  1;               /*!< [0..0] Enable sending of command                                      */
      __IO uint32_t  addr_len   :  3;               /*!< [1..3] Number of address bytes (0 to 4)                               */
      __IO uint32_t  pad_cnt    :  4;               /*!< [4..7] Number of dummy cycles                                         */
      __IO uint32_t  cmd_proto  :  2;               /*!< [8..9] Protocol for transmitting command                              */
      __IO uint32_t  addr_proto :  2;               /*!< [10..11] Protocol for transmitting address and padding                */
      __IO uint32_t  data_proto :  2;               /*!< [12..13] Protocol for receiving data bytes                            */
           uint32_t             :  2;
      __IO uint32_t  cmd_code   :  8;               /*!< [16..23] Value of command byte                                        */
      __IO uint32_t  pad_code   :  8;               /*!< [24..31] First 8 bits to transmit during dummy cycles                 */
    } bit;                                          /*!< [32] BitSize                                                          */
  } ffmt;
  __I  uint32_t  RESERVED5[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014070) SPI Interrupt Enable Register                          */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< [0..0] Transmit watermark enable                                      */
      __IO uint32_t  rxwm       :  1;               /*!< [1..1] Receive watermark enable                                       */
    } bit;                                          /*!< [2] BitSize                                                           */
  } ie;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10014074) SPI Interrupt Pending Register                         */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< [0..0] Transmit watermark enable                                      */
      __IO uint32_t  rxwm       :  1;               /*!< [1..1] Receive watermark enable                                       */
    } bit;                                          /*!< [2] BitSize                                                           */
  } ip;
} QSPI0_Type;


/* ================================================================================ */
/* ================                      PWM0                      ================ */
/* ================================================================================ */


/**
  * @brief 8-bit timer with 4 cmp (PWM0)
  */

typedef struct {                                    /*!< (@ 0x10015000) PWM0 Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10015000) PWM Configuration Register                             */
    
    struct {
      __IO uint32_t  scale      :  4;               /*!< [0..3] (null)                                                         */
           uint32_t             :  4;
      __IO uint32_t  sticky     :  1;               /*!< [8..8] (null)                                                         */
      __IO uint32_t  zerocmp    :  1;               /*!< [9..9] (null)                                                         */
      __IO uint32_t  deglitch   :  1;               /*!< [10..10] (null)                                                       */
           uint32_t             :  1;
      __IO uint32_t  enalways   :  1;               /*!< [12..12] (null)                                                       */
      __IO uint32_t  enoneshot  :  1;               /*!< [13..13] (null)                                                       */
           uint32_t             :  2;
      __IO uint32_t  cmp0center :  1;               /*!< [16..16] (null)                                                       */
      __IO uint32_t  cmp1center :  1;               /*!< [17..17] (null)                                                       */
      __IO uint32_t  cmp2center :  1;               /*!< [18..18] (null)                                                       */
      __IO uint32_t  cmp3center :  1;               /*!< [19..19] (null)                                                       */
           uint32_t             :  4;
      __IO uint32_t  cmp0gang   :  1;               /*!< [24..24] (null)                                                       */
      __IO uint32_t  cmp1gang   :  1;               /*!< [25..25] (null)                                                       */
      __IO uint32_t  cmp2gang   :  1;               /*!< [26..26] (null)                                                       */
      __IO uint32_t  cmp3gang   :  1;               /*!< [27..27] (null)                                                       */
      __IO uint32_t  cmp0ip     :  1;               /*!< [28..28] (null)                                                       */
      __IO uint32_t  cmp1ip     :  1;               /*!< [29..29] (null)                                                       */
      __IO uint32_t  cmp2ip     :  1;               /*!< [30..30] (null)                                                       */
      __IO uint32_t  cmp3ip     :  1;               /*!< [31..31] (null)                                                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } cfg;
  __I  uint32_t  RESERVED;
  __IO uint32_t  count;                             /*!< (@ 0x10015008) Counter Register                                       */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  pwms;                              /*!< (@ 0x10015010) Scaled Halfword Counter Register                       */
  __I  uint32_t  RESERVED2[3];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10015020) Compare Register                                       */
    
    struct {
      __IO uint32_t  value      : 16;               /*!< [0..15] (null)                                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } cmp0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10015024) Compare Register                                       */
    
    struct {
      __IO uint32_t  value      : 16;               /*!< [0..15] (null)                                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } cmp1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10015028) Compare Register                                       */
    
    struct {
      __IO uint32_t  value      : 16;               /*!< [0..15] (null)                                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } cmp2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001502C) Compare Register                                       */
    
    struct {
      __IO uint32_t  value      : 16;               /*!< [0..15] (null)                                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } cmp3;
} PWM0_Type;


/* ================================================================================ */
/* ================                      I2C0                      ================ */
/* ================================================================================ */


/**
  * @brief Inter-Integrated Circuit Master Interface (FE310-G002 only) (I2C0)
  */

typedef struct {                                    /*!< (@ 0x10016000) I2C0 Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10016000) Clock Prescale register lo-byte                        */
    
    struct {
      __IO uint32_t  value      :  8;               /*!< [0..7] (null)                                                         */
    } bit;                                          /*!< [8] BitSize                                                           */
  } prer_lo;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10016004) Clock Prescale register hi-byte                        */
    
    struct {
      __IO uint32_t  value      :  8;               /*!< [0..7] (null)                                                         */
    } bit;                                          /*!< [8] BitSize                                                           */
  } prer_hi;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x10016008) Control register                                       */
    
    struct {
           uint32_t             :  6;
      __IO uint32_t  ien        :  1;               /*!< [6..6] I2C core interrupt enable bit                                  */
      __IO uint32_t  en         :  1;               /*!< [7..7] I2C core enable bit                                            */
    } bit;                                          /*!< [8] BitSize                                                           */
  } ctr;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x1001600C) Transmit register / Receive register                   */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< [0..7] (null)                                                         */
    } bit;                                          /*!< [8] BitSize                                                           */
  } txr_rxr;
  
  union {
    union {
      __I  uint32_t  reg;                           /*!< (@ 0x10016010) Status register                                        */
      
      struct {
        __I  uint32_t  intf     :  1;               /*!< [0..0] Interrupt Flag. This bit is set when an interrupt is
                                                         pending, which will cause a processor interrupt request if the
                                                          IEN bit is set.                                                      */
        __I  uint32_t  tip      :  1;               /*!< [1..1] Transfer in progress                                           */
             uint32_t           :  3;
        __I  uint32_t  al       :  1;               /*!< [5..5] Arbitration lost                                               */
        __I  uint32_t  busy     :  1;               /*!< [6..6] I2C bus busy                                                   */
        __I  uint32_t  rx_ack   :  1;               /*!< [7..7] Received acknowledge from slave. This flag represents
                                                         acknowledge from the addressed slave. '1' = No acknowledge received
                                                          '0' = Acknowledge received                                           */
      } bit;                                        /*!< [8] BitSize                                                           */
    } sr;
    
    union {
      __O  uint32_t  reg;                           /*!< (@ 0x10016010) Command register                                       */
      
      struct {
        __O  uint32_t  iack     :  1;               /*!< [0..0] Interrupt acknowledge. When set, clears a pending interrupt    */
             uint32_t           :  2;
        __O  uint32_t  ack      :  1;               /*!< [3..3] When a receiver, sent ACK (0) or NACK (1)                      */
        __O  uint32_t  wr       :  1;               /*!< [4..4] Write to slave                                                 */
        __O  uint32_t  rd       :  1;               /*!< [5..5] Read from slave                                                */
        __O  uint32_t  sto      :  1;               /*!< [6..6] Generate stop condition                                        */
        __O  uint32_t  sta      :  1;               /*!< [7..7] Generate (repeated) start condition                            */
      } bit;                                        /*!< [8] BitSize                                                           */
    } cr;
    __IO uint32_t  cr_sr;                           /*!< (@ 0x10016010) Command register / Status register                     */
  }cr_sr;
} I2C0_Type;


/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define CLINT_BASE                      0x02000000UL
#define PLIC_BASE                       0x0C000000UL
#define WDOG_BASE                       0x10000000UL
#define RTC_BASE                        0x10000000UL
#define AONCLK_BASE                     0x10000000UL
#define BACKUP_BASE                     0x10000000UL
#define PMU_BASE                        0x10000000UL
#define PRCI_BASE                       0x10008000UL
#define OTP_BASE                        0x10010000UL
#define GPIO0_BASE                      0x10012000UL
#define UART0_BASE                      0x10013000UL
#define QSPI0_BASE                      0x10014000UL
#define PWM0_BASE                       0x10015000UL
#define I2C0_BASE                       0x10016000UL
#define UART1_BASE                      0x10023000UL
#define QSPI1_BASE                      0x10024000UL
#define PWM1_BASE                       0x10025000UL
#define QSPI2_BASE                      0x10034000UL
#define PWM2_BASE                       0x10035000UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define CLINT                           ((CLINT_Type              *) CLINT_BASE)
#define PLIC                            ((PLIC_Type               *) PLIC_BASE)
#define WDOG                            ((WDOG_Type               *) WDOG_BASE)
#define RTC                             ((RTC_Type                *) RTC_BASE)
#define AONCLK                          ((AONCLK_Type             *) AONCLK_BASE)
#define BACKUP                          ((BACKUP_Type             *) BACKUP_BASE)
#define PMU                             ((PMU_Type                *) PMU_BASE)
#define PRCI                            ((PRCI_Type               *) PRCI_BASE)
#define OTP                             ((OTP_Type                *) OTP_BASE)
#define GPIO0                           ((GPIO0_Type              *) GPIO0_BASE)
#define UART0                           ((UART0_Type              *) UART0_BASE)
#define QSPI0                           ((QSPI0_Type              *) QSPI0_BASE)
#define PWM0                            ((PWM0_Type               *) PWM0_BASE)
#define I2C0                            ((I2C0_Type               *) I2C0_BASE)
#define UART1                           ((UART0_Type              *) UART1_BASE)
#define QSPI1                           ((QSPI0_Type              *) QSPI1_BASE)
#define PWM1                            ((PWM0_Type               *) PWM1_BASE)
#define QSPI2                           ((QSPI0_Type              *) QSPI2_BASE)
#define PWM2                            ((PWM0_Type               *) PWM2_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group FE310 */
/** @} */ /* End of group SiFive */

#ifdef __cplusplus
}
#endif


#endif  /* FE310_H */

