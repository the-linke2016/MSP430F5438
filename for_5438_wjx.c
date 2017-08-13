#include <msp430x54x.h>
#define enable      (1)
#define disenable   (0)
#define on          (1)
#define off         (0)

//UART串行口中断矢量------------------------------------------------------------
#define UART0_VECTOR        USCI_A0_VECTOR
#define UART1_VECTOR        USCI_A1_VECTOR
#define UART2_VECTOR        USCI_A2_VECTOR
#define UART3_VECTOR        USCI_A3_VECTOR
#define SPI_A0_VECTOR       USCI_A0_VECTOR
#define SPI_A1_VECTOR       USCI_A1_VECTOR
#define SPI_A2_VECTOR       USCI_A2_VECTOR
#define SPI_A3_VECTOR       USCI_A3_VECTOR
#define SPI_B0_VECTOR       USCI_B0_VECTOR
#define SPI_B1_VECTOR       USCI_B1_VECTOR
#define SPI_B2_VECTOR       USCI_B2_VECTOR
#define SPI_B3_VECTOR       USCI_B3_VECTOR
#define IIC0_VECTOR         USCI_B0_VECTOR
#define IIC1_VECTOR         USCI_B1_VECTOR
#define IIC2_VECTOR         USCI_B2_VECTOR
#define IICS_VECTOR         USCI_B3_VECTOR
//定时器中断矢量----------------------------------------------------------------
#define TA0_VECTOR          TIMER0_A1_VECTOR    /* 0xFFEA 与TA0CCR1_VECTOR共享 */
#define TA0CCR0_VECTOR      TIMER0_A0_VECTOR    /* 0xFFEC Timer0_A5 CC0 */
#define TA0CCR1_VECTOR      TIMER0_A1_VECTOR    /* 0xFFEA Timer0_A5 CC1-4, TA */
#define TA0CCR2_VECTOR      TIMER0_A1_VECTOR
#define TA0CCR3_VECTOR      TIMER0_A1_VECTOR
#define TA0CCR4_VECTOR      TIMER0_A1_VECTOR
#define TA1_VECTOR          TIMER1_A1_VECTOR    /* 0xFFE0 与TA1CCR1_VECTOR共享 */
#define TA1CCR0_VECTOR      TIMER1_A0_VECTOR    /* 0xFFE2 Timer1_A3 CC0 */
#define TA1CCR1_VECTOR      TIMER1_A1_VECTOR    /* 0xFFE0 Timer1_A3 CC1-2, TA1 */
#define TA1CCR2_VECTOR      TIMER1_A1_VECTOR
#define TB0_VECTOR          TIMER0_B1_VECTOR    /* 0xFFF6 与TB0CCR1_VECTOR共享 */
#define TB0CCR0_VECTOR      TIMER0_B0_VECTOR    /* 0xFFF8 Timer0_B7 CC0 */
#define TB0CCR1_VECTOR      TIMER0_B1_VECTOR    /* 0xFFF6 Timer0_B7 CC1-6, TB */
#define TB0CCR2_VECTOR      TIMER0_B1_VECTOR
#define TB0CCR3_VECTOR      TIMER0_B1_VECTOR
#define TB0CCR4_VECTOR      TIMER0_B1_VECTOR
#define TB0CCR5_VECTOR      TIMER0_B1_VECTOR
#define TB0CCR6_VECTOR      TIMER0_B1_VECTOR
//ADC中断矢量 ##################################################################
#define ADC_VECTOR          ADC12_VECTOR
//ADC中断矢量 ##################################################################
//状态寄存器SR 开始#############################################################
#define set_C               _BIS_SR(C)
#define clr_C               _BIS_SR(~C)
#define set_Z               _BIS_SR(Z)
#define clr_Z               _BIS_SR(~Z)
#define set_N               _BIS_SR(N)
#define clr_N               _BIS_SR(~N)
#define set_GIE             _BIS_SR(GIE)
#define clr_GIE             _BIS_SR(~GIE)
#define set_CPUOFF          _BIS_SR(CPUOFF)
#define clr_CPUOFF          _BIS_SR(~CPUOFF)
#define set_OSCOFF          _BIS_SR(OSCOFF)
#define clr_OSCOFF          _BIS_SR(~OSCOFF)
#define set_SCG0            _BIS_SR(SCG0)
#define clr_SCG0            _BIS_SR(~SCG0)
#define set_SCG1            _BIS_SR(SCG1)
#define clr_SCG1            _BIS_SR(~SCG1)
#define set_V               _BIS_SR(V)
#define clr_V               _BIS_SR(~V)
//状态寄存器SR 开始#############################################################
//------------------------------------------------------------------------------
//电源管理模式复位及其中断使能开始 #############################################
//------------------------------------------------------------------------------
#define put_SVSMLDLYIE(x)   PMMRIE=(PMMRIE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SVSMLDLYIE      (PMMRIE & (~(0XFFFE)))>>0
#define put_SVMLIE(x)       PMMRIE=(PMMRIE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SVMLIE          (PMMRIE & (~(0XFFFD)))>>1
#define put_SVMLVLRIE(x)    PMMRIE=(PMMRIE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SVMLVLRIE       (PMMRIE & (~(0XFFFB)))>>2
#define put_SVSMHDLYIE(x)   PMMRIE=(PMMRIE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SVSMHDLYIE      (PMMRIE & (~(0XFFEF)))>>4
#define put_SVMHIE(x)       PMMRIE=(PMMRIE & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SVMHIE          (PMMRIE & (~(0XFFDF)))>>5
#define put_SVMHVLRIE(x)    PMMRIE=(PMMRIE & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SVMHVLRIE       (PMMRIE & (~(0XFFBF)))>>6
#define put_SVSLPE(x)       PMMRIE=(PMMRIE & 0XFEFF) | ((x & 0X0001) <<8)
#define get_SVSLPE          (PMMRIE & (~(0XFEFF)))>>8
#define put_SVMLVLRPE(x)    PMMRIE=(PMMRIE & 0XFDFF) | ((x & 0X0001) <<9)
#define get_SVMLVLRPE       (PMMRIE & (~(0XFDFF)))>>9
#define put_SVSHPE(x)       PMMRIE=(PMMRIE & 0XEFFF) | ((x & 0X0001) <<12)
#define get_SVSHPE          (PMMRIE & (~(0XEFFF)))>>12
#define put_SVMHVLRPE(x)    PMMRIE=(PMMRIE & 0XDFFF) | ((x & 0X0001) <<13)
#define get_SVMHVLRPE       (PMMRIE & (~(0XDFFF)))>>13
//------------------------------------------------------------------------------
#define put_LOCKLPM5(x)     PM5CTL0=(PM5CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_LOCKLPM5        (PM5CTL0 & (~(0XFFFE)))>>0
//电源管理式复位及其中断使能结束 ###############################################
//------------------------------------------------------------------------------
//复位电路 (BOR/POR/PUC Reset）开始 ############################################
//见电源管理：SVSHPE、SVMHVLRPE、SVSLPE、SVMLVLRPE
//复位电路 (BOR/POR/PUC Reset）结束 ############################################
//------------------------------------------------------------------------------
//时钟系统开始 #################################################################
//UCSCTL0开始 ******************************************************************
#define put_MOD(x)          UCSCTL0=(UCSCTL0 & 0XFF07) | ((x & 0X001F) <<3)
#define get_MOD             (UCSCTL0 & (~(0XFF07)))>>3
#define put_DCO(x)          UCSCTL0=(UCSCTL0 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DCO             (UCSCTL0 & (~(0XE0FF)))>>8
//UCSCTL0结束 ******************************************************************
//------------------------------------------------------------------------------
//UCSCTL1开始 ******************************************************************
#define put_DISMOD(x)       UCSCTL1=(UCSCTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DISMOD          (UCSCTL1 & (~(0XFFFE)))>>0
#define put_DCORSEL(x)      UCSCTL1=(UCSCTL1 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_DCORSEL         (UCSCTL1 & (~(0XFF8F)))>>4
//UCSCTL1结束 ******************************************************************
//UCSCTL2_START-----------------------------------------------------------------
#define put_FLLN(x)         UCSCTL2=(UCSCTL2 & 0XFC00) | ((x & 0X03FF) <<0)
#define get_FLLN            (UCSCTL2 & (~(0XFC00)))>>0
#define put_FLLD(x)         UCSCTL2=(UCSCTL2 & 0X8FFF) | ((x & 0X0007) <<12)
#define get_FLLD            (UCSCTL2 & (~(0X8FFF)))>>12
//UCSCTL2_END-------------------------------------------------------------------
//UCSCTL3_START-----------------------------------------------------------------
#define put_FLLREFDIV(x)    UCSCTL3=(UCSCTL3 & 0XFFF8) | ((x & 0X0007) <<0)
#define get_FLLREFDIV       (UCSCTL3 & (~(0XFFF8)))>>0
#define put_SELREF(x)       UCSCTL3=(UCSCTL3 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_SELREF          (UCSCTL3 & (~(0XFF8F)))>>4
//UCSCTL3_END-------------------------------------------------------------------
//UCSCTL4_START-----------------------------------------------------------------
#define put_SELM(x)         UCSCTL4=(UCSCTL4 & 0XFFF8) | ((x & 0X0007) <<0)
#define get_SELM            (UCSCTL4 & (~(0XFFF8)))>>0
#define put_SELS(x)         UCSCTL4=(UCSCTL4 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_SELS            (UCSCTL4 & (~(0XFF8F)))>>4
#define put_SELA(x)         UCSCTL4=(UCSCTL4 & 0XF8FF) | ((x & 0X0007) <<8)
#define get_SELA            (UCSCTL4 & (~(0XF8FF)))>>8
//UCSCTL4_END-------------------------------------------------------------------
//UCSCTL5_START-----------------------------------------------------------------
#define put_DIVM(x)         UCSCTL5=(UCSCTL5 & 0XFFF8) | ((x & 0X0007) <<0)
#define get_DIVM            (UCSCTL5 & (~(0XFFF8)))>>0
#define put_DIVS(x)         UCSCTL5=(UCSCTL5 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_DIVS            (UCSCTL5 & (~(0XFF8F)))>>4
#define put_DIVA(x)         UCSCTL5=(UCSCTL5 & 0XF8FF) | ((x & 0X0007) <<8)
#define get_DIVA            (UCSCTL5 & (~(0XF8FF)))>>8
#define put_DIVPA(x)        UCSCTL5=(UCSCTL5 & 0X8FFF) | ((x & 0X0007) <<12)
#define get_DIVPA           (UCSCTL5 & (~(0X8FFF)))>>8
//UCSCTL5_END-------------------------------------------------------------------
//UCSCTL6_START-----------------------------------------------------------------
#define put_XT1OFF(x)       UCSCTL6=(UCSCTL6 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_XT1OFF          (UCSCTL6 & (~(0XFFFE)))>>0
#define put_SMCLKOFF(x)     UCSCTL6=(UCSCTL6 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SMCLKOFF        (UCSCTL6 & (~(0XFFFD)))>>1
#define put_XCAP(x)         UCSCTL6=(UCSCTL6 & 0XFFF3) | ((x & 0X0003) <<2)
#define get_XCAP            (UCSCTL6 & (~(0XFFF3)))>>1
#define put_XT1BYPASS(x)    UCSCTL6=(UCSCTL6 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_XT1BYPASS       (UCSCTL6 & (~(0XFFEF)))>>1
#define put_XTS(x)          UCSCTL6=(UCSCTL6 & 0XFFDF) | ((x & 0X0003) <<5)
#define get_XTS             (UCSCTL6 & (~(0XFFDF)))>>5
#define put_XT1DRIVE(x)     UCSCTL6=(UCSCTL6 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_XT1DRIVE        (UCSCTL6 & (~(0XFF3F)))>>6
#define put_XT2OFF(x)       UCSCTL6=(UCSCTL6 & 0XFEFF) | ((x & 0X0001) <<8)
#define get_XT2OFF          (UCSCTL6 & (~(0XFEFF)))>>8
#define put_XT2BYPASS(x)    UCSCTL6=(UCSCTL6 & 0XEFFF) | ((x & 0X0001) <<12)
#define get_XT2BYPASS       (UCSCTL6 & (~(0XEFFF)))>>1
#define put_XT2DRIVE(x)     UCSCTL6=(UCSCTL6 & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_XT2DRIVE        (UCSCTL6 & (~(0X7FFF)))>>15
//UCSCTL6_END-------------------------------------------------------------------
//UCSCTL7_START-----------------------------------------------------------------
#define put_DCOFFG(x)       UCSCTL7=(UCSCTL7 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DCOFFG          (UCSCTL7 & (~(0XFFFE)))>>0
#define put_XT1LFOFFG(x)    UCSCTL7=(UCSCTL7 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_XT1LFOFFG       (UCSCTL7 & (~(0XFFFD)))>>1
#define put_XT1HFOFFG(x)    UCSCTL7=(UCSCTL7 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_XT1HFOFFG       (UCSCTL7 & (~(0XFFFB)))>>2
#define put_XT2OFFG(x)      UCSCTL7=(UCSCTL7 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_XT2OFFG         (UCSCTL7 & (~(0XFFF7)))>>3
//UCSCTL7_END-------------------------------------------------------------------
//UCSCTL8_START-----------------------------------------------------------------
#define put_ACLKREQEN(x)    UCSCTL8=(UCSCTL8 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_ACLKREQEN       (UCSCTL8 & (~(0XFFFE)))>>0
#define put_MCLKREQEN(x)    UCSCTL8=(UCSCTL8 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_MCLKREQEN       (UCSCTL8 & (~(0XFFFD)))>>1
#define put_SMCLKREQEN(x)   UCSCTL8=(UCSCTL8 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SMCLKREQEN      (UCSCTL8 & (~(0XFFFB)))>>2
#define put_MROEDQOESNC(x)  UCSCTL8=(UCSCTL8 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_MROEDQOESNC     (UCSCTL8 & (~(0XFFF7)))>>3
//UCSCTL8_END-------------------------------------------------------------------
//时钟系统结束 #################################################################
//------------------------------------------------------------------------------
//定时器A开始 ##################################################################
//TA0CTL  开始 *****************************************************************
#define put_TA0_TAIFG(x)    TA0CTL=(TA0CTL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA0_TAIFG       (TA0CTL>>0) & 0x0001
#define put_TA0_TAIE(x)     TA0CTL=(TA0CTL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA0_TAIE        (TA0CTL>>1) & 0x0001
#define put_TA0_TACLR(x)    TA0CTL=(TA0CTL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA0_TACLR       (TA0CTL>>2) & 0x0001
#define put_TA0_MC(x)       TA0CTL=(TA0CTL & 0xFFCF) | ((x & 0x0003) << 4)
#define get_TA0_MC          (TA0CTL>>4) & 0x0003
#define put_TA0_ID(x)       TA0CTL=(TA0CTL & 0xFF3F) | ((x & 0x0003) << 6)
#define get_TA0_ID          (TA0CTL>>6) & 0x0003
#define put_TA0_TASSEL(x)   TA0CTL=(TA0CTL & 0xFCFF) | ((x & 0x0003) << 8)
#define get_TA0_TASSEL      (TA0CTL>>8) & 0x0003
//TA0CTL结束 *******************************************************************
//------------------------------------------------------------------------------
//TA0CCTL0  开始 ***************************************************************
#define put_TA0CCR0_CCIFG(x)   TA0CCTL0=(TA0CCTL0 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA0CCR0_CCIFG      (TA0CCTL0>>0) & 0x0001
#define put_TA0CCR0_COV(x)     TA0CCTL0=(TA0CCTL0 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA0CCR0_COV        (TA0CCTL0>>1) & 0x0001
#define put_TA0CCR0_OUT(x)     TA0CCTL0=(TA0CCTL0 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA0CCR0_OUT        (TA0CCTL0>>2) & 0x0001
#define put_TA0CCR0_CCI(x)     TA0CCTL0=(TA0CCTL0 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA0CCR0_CCI        (TA0CCTL0>>3) & 0x0001
#define put_TA0CCR0_CCIE(x)    TA0CCTL0=(TA0CCTL0 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA0CCR0_CCIE       (TA0CCTL0>>4) & 0x0001
#define put_TA0CCR0_OUTMOD(x)  TA0CCTL0=(TA0CCTL0 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA0CCR0_OUTMOD     (TA0CCTL0>>5) & 0x0007
#define put_TA0CCR0_CAP(x)     TA0CCTL0=(TA0CCTL0 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA0CCR0_CAP        (TA0CCTL0>>8) & 0x0001
#define put_TA0CCR0_SCCI(x)    TA0CCTL0=(TA0CCTL0 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA0CCR0_SCCI       (TA0CCTL0>>10) & 0x0001
#define put_TA0CCR0_SCS(x)     TA0CCTL0=(TA0CCTL0 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA0CCR0_SCS        (TA0CCTL0>>11) & 0x0001
#define put_TA0CCR0_CCIS(x)    TA0CCTL0=(TA0CCTL0 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA0CCR0_CCIS       (TA0CCTL0>>12) & 0x0003
#define put_TA0CCR0_CM(x)      TA0CCTL0=(TA0CCTL0 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA0CCR0_CM         (TA0CCTL0>>14) & 0x0003
//TA0CCTL0  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA0CCTL1  开始 ******************************************************************
#define put_TA0CCR1_CCIFG(x)   TA0CCTL1=(TA0CCTL1 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA0CCR1_CCIFG      (TA0CCTL1>>0) & 0x0001
#define put_TA0CCR1_COV(x)     TA0CCTL1=(TA0CCTL1 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA0CCR1_COV        (TA0CCTL1>>1) & 0x0001
#define put_TA0CCR1_OUT(x)     TA0CCTL1=(TA0CCTL1 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA0CCR1_OUT        (TA0CCTL1>>2) & 0x0001
#define put_TA0CCR1_CCI(x)     TA0CCTL1=(TA0CCTL1 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA0CCR1_CCI        (TA0CCTL1>>3) & 0x0001
#define put_TA0CCR1_CCIE(x)    TA0CCTL1=(TA0CCTL1 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA0CCR1_CCIE       (TA0CCTL1>>4) & 0x0001
#define put_TA0CCR1_OUTMOD(x)  TA0CCTL1=(TA0CCTL1 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA0CCR1_OUTMOD     (TA0CCTL1>>5) & 0x0007
#define put_TA0CCR1_CAP(x)     TA0CCTL1=(TA0CCTL1 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA0CCR1_CAP        (TA0CCTL1>>8) & 0x0001
#define put_TA0CCR1_SCCI(x)    TA0CCTL1=(TA0CCTL1 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA0CCR1_SCCI       (TA0CCTL1>>10) & 0x0001
#define put_TA0CCR1_SCS(x)     TA0CCTL1=(TA0CCTL1 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA0CCR1_SCS        (TA0CCTL1>>11) & 0x0001
#define put_TA0CCR1_CCIS(x)    TA0CCTL1=(TA0CCTL1 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA0CCR1_CCIS       (TA0CCTL1>>12) & 0x0003
#define put_TA0CCR1_CM(x)      TA0CCTL1=(TA0CCTL1 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA0CCR1_CM         (TA0CCTL1>>14) & 0x0003
//TA0CCTL1  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA0CCTL2  开始 ******************************************************************
#define put_TA0CCR2_CCIFG(x)   TA0CCTL2=(TA0CCTL2 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA0CCR2_CCIFG      (TA0CCTL2>>0) & 0x0001
#define put_TA0CCR2_COV(x)     TA0CCTL2=(TA0CCTL2 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA0CCR2_COV        (TA0CCTL1>>1) & 0x0001
#define put_TA0CCR2_OUT(x)     TA0CCTL2=(TA0CCTL2 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA0CCR2_OUT        (TA0CCTL2>>2) & 0x0001
#define put_TA0CCR2_CCI(x)     TA0CCTL2=(TA0CCTL2 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA0CCR2_CCI        (TA0CCTL2>>3) & 0x0001
#define put_TA0CCR2_CCIE(x)    TA0CCTL2=(TA0CCTL2 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA0CCR2_CCIE       (TA0CCTL2>>4) & 0x0001
#define put_TA0CCR2_OUTMOD(x)  TA0CCTL2=(TA0CCTL2 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA0CCR2_OUTMOD     (TA0CCTL2>>5) & 0x0007
#define put_TA0CCR2_CAP(x)     TA0CCTL2=(TA0CCTL2 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA0CCR2_CAP        (TA0CCTL2>>8) & 0x0001
#define put_TA0CCR2_SCCI(x)    TA0CCTL2=(TA0CCTL2 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA0CCR2_SCCI       (TA0CCTL2>>10) & 0x0001
#define put_TA0CCR2_SCS(x)     TA0CCTL2=(TA0CCTL2 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA0CCR2_SCS        (TA0CCTL2>>11) & 0x0001
#define put_TA0CCR2_CCIS(x)    TA0CCTL2=(TA0CCTL2 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA0CCR2_CCIS       (TA0CCTL2>>12) & 0x0003
#define put_TA0CCR2_CM(x)      TA0CCTL2=(TA0CCTL2 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA0CCR2_CM         (TA0CCTL2>>14) & 0x0003
//TA0CCTL2  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA0CCTL3  开始 ******************************************************************
#define put_TA0CCR3_CCIFG(x)   TA0CCTL3=(TA0CCTL3 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA0CCR3_CCIFG      (TA0CCTL3>>0) & 0x0001
#define put_TA0CCR3_COV(x)     TA0CCTL3=(TA0CCTL3 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA0CCR3_COV        (TA0CCTL1>>1) & 0x0001
#define put_TA0CCR3_OUT(x)     TA0CCTL3=(TA0CCTL3 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA0CCR3_OUT        (TA0CCTL3>>2) & 0x0001
#define put_TA0CCR3_CCI(x)     TA0CCTL3=(TA0CCTL3 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA0CCR3_CCI        (TA0CCTL3>>3) & 0x0001
#define put_TA0CCR3_CCIE(x)    TA0CCTL3=(TA0CCTL3 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA0CCR3_CCIE       (TA0CCTL3>>4) & 0x0001
#define put_TA0CCR3_OUTMOD(x)  TA0CCTL3=(TA0CCTL3 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA0CCR3_OUTMOD     (TA0CCTL3>>5) & 0x0007
#define put_TA0CCR3_CAP(x)     TA0CCTL3=(TA0CCTL3 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA0CCR3_CAP        (TA0CCTL3>>8) & 0x0001
#define put_TA0CCR3_SCCI(x)    TA0CCTL3=(TA0CCTL3 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA0CCR3_SCCI       (TA0CCTL3>>10) & 0x0001
#define put_TA0CCR3_SCS(x)     TA0CCTL3=(TA0CCTL3 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA0CCR3_SCS        (TA0CCTL3>>11) & 0x0001
#define put_TA0CCR3_CCIS(x)    TA0CCTL3=(TA0CCTL3 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA0CCR3_CCIS       (TA0CCTL3>>12) & 0x0003
#define put_TA0CCR3_CM(x)      TA0CCTL3=(TA0CCTL3 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA0CCR3_CM         (TA0CCTL3>>14) & 0x0003
//TA0CCTL3  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA0CCTL4  开始 ******************************************************************
#define put_TA0CCR4_CCIFG(x)   TA0CCTL4=(TA0CCTL4 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA0CCR4_CCIFG      (TA0CCTL4>>0) & 0x0001
#define put_TA0CCR4_COV(x)     TA0CCTL4=(TA0CCTL4 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA0CCR4_COV        (TA0CCTL1>>1) & 0x0001
#define put_TA0CCR4_OUT(x)     TA0CCTL4=(TA0CCTL4 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA0CCR4_OUT        (TA0CCTL4>>2) & 0x0001
#define put_TA0CCR4_CCI(x)     TA0CCTL4=(TA0CCTL4 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA0CCR4_CCI        (TA0CCTL4>>3) & 0x0001
#define put_TA0CCR4_CCIE(x)    TA0CCTL4=(TA0CCTL4 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA0CCR4_CCIE       (TA0CCTL4>>4) & 0x0001
#define put_TA0CCR4_OUTMOD(x)  TA0CCTL4=(TA0CCTL4 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA0CCR4_OUTMOD     (TA0CCTL4>>5) & 0x0007
#define put_TA0CCR4_CAP(x)     TA0CCTL4=(TA0CCTL4 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA0CCR4_CAP        (TA0CCTL4>>8) & 0x0001
#define put_TA0CCR4_SCCI(x)    TA0CCTL4=(TA0CCTL4 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA0CCR4_SCCI       (TA0CCTL4>>10) & 0x0001
#define put_TA0CCR4_SCS(x)     TA0CCTL4=(TA0CCTL4 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA0CCR4_SCS        (TA0CCTL4>>11) & 0x0001
#define put_TA0CCR4_CCIS(x)    TA0CCTL4=(TA0CCTL4 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA0CCR4_CCIS       (TA0CCTL4>>12) & 0x0003
#define put_TA0CCR4_CM(x)      TA0CCTL4=(TA0CCTL4 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA0CCR4_CM         (TA0CCTL4>>14) & 0x0003
//TA0CCTL4  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA0CCRx 开始 ********************************************************************
#define put_TA0CCR0(x)          TA0CCR0=x
#define get_TA0CCR0             TA0CCR0
#define put_TA0CCR1(x)          TA0CCR1=x
#define get_TA0CCR1             TA0CCR1
#define put_TA0CCR2(x)          TA0CCR2=x
#define get_TA0CCR2             TA0CCR2
#define put_TA0CCR3(x)          TA0CCR3=x
#define get_TA0CCR3             TA0CCR3
#define put_TA0CCR4(x)          TA0CCR4=x
#define get_TA0CCR4             TA0CCR4
#define put_TA0CCR5(x)          TA0CCR5=x
#define get_TA0CCR5             TA0CCR5
#define put_TA0CCR6(x)          TA0CCR6=x
#define get_TA0CCR6             TA0CCR6
//TA0CCRx 结束 ********************************************************************
//---------------------------------------------------------------------------------
//TA0IV 开始 **********************************************************************
#define put_TA0IV(x)            TA0IV=(TA0IV & 0xFFF0) | ((x & 0x000E) << 0)
#define get_TA0IV               (TA0IV>>0) & 0x000E
//TA0IV 结束 **********************************************************************
//---------------------------------------------------------------------------------
//TA0EX0开始***********************************************************************
#define put_TA0_IDEX(x)         TA0EX0=(TA0EX0 & 0xFFF8) | ((x & 0x0007) << 0)
#define get_TA0_IDEX            (TA0EX0>>0) & 0x0007
//TA0EX0结束 **********************************************************************
//---------------------------------------------------------------------------------
//TA0R开始 ************************************************************************
#define put_TA0R(x)             TA0R=x
#define get_TA0R                TA0R
//TA0R结束 ************************************************************************
//---------------------------------------------------------------------------------
//TA1CTL  开始 ********************************************************************
#define put_TA1_TAIFG(x)    TA1CTL=(TA1CTL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA1_TAIFG       (TA1CTL>>0) & 0x0001
#define put_TA1_TAIE(x)     TA1CTL=(TA1CTL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA1_TAIE        (TA1CTL>>1) & 0x0001
#define put_TA1_TACLR(x)    TA1CTL=(TA1CTL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA1_TACLR       (TA1CTL>>2) & 0x0001
#define put_TA1_MC(x)       TA1CTL=(TA1CTL & 0xFFCF) | ((x & 0x0003) << 4)
#define get_TA1_MC          (TA1CTL>>4) & 0x0003
#define put_TA1_ID(x)       TA1CTL=(TA1CTL & 0xFF3F) | ((x & 0x0003) << 6)
#define get_TA1_ID          (TA1CTL>>6) & 0x0003
#define put_TA1_TASSEL(x)   TA1CTL=(TA1CTL & 0xFCFF) | ((x & 0x0003) << 8)
#define get_TA1_TASSEL      (TA1CTL>>8) & 0x0003
//TA1CTL结束 **********************************************************************
//---------------------------------------------------------------------------------
//TA1CCTL0  开始 ******************************************************************
#define put_TA1CCR0_CCIFG(x)   TA1CCTL0=(TA1CCTL0 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA1CCR0_CCIFG      (TA1CCTL0>>0) & 0x0001
#define put_TA1CCR0_COV(x)     TA1CCTL0=(TA1CCTL0 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA1CCR0_COV        (TA1CCTL0>>1) & 0x0001
#define put_TA1CCR0_OUT(x)     TA1CCTL0=(TA1CCTL0 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA1CCR0_OUT        (TA1CCTL0>>2) & 0x0001
#define put_TA1CCR0_CCI(x)     TA1CCTL0=(TA1CCTL0 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA1CCR0_CCI        (TA1CCTL0>>3) & 0x0001
#define put_TA1CCR0_CCIE(x)    TA1CCTL0=(TA1CCTL0 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA1CCR0_CCIE       (TA1CCTL0>>4) & 0x0001
#define put_TA1CCR0_OUTMOD(x)  TA1CCTL0=(TA1CCTL0 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA1CCR0_OUTMOD     (TA1CCTL0>>5) & 0x0007
#define put_TA1CCR0_CAP(x)     TA1CCTL0=(TA1CCTL0 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA1CCR0_CAP        (TA1CCTL0>>8) & 0x0001
#define put_TA1CCR0_SCCI(x)    TA1CCTL0=(TA1CCTL0 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA1CCR0_SCCI       (TA1CCTL0>>10) & 0x0001
#define put_TA1CCR0_SCS(x)     TA1CCTL0=(TA1CCTL0 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA1CCR0_SCS        (TA1CCTL0>>11) & 0x0001
#define put_TA1CCR0_CCIS(x)    TA1CCTL0=(TA1CCTL0 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA1CCR0_CCIS       (TA1CCTL0>>12) & 0x0003
#define put_TA1CCR0_CM(x)      TA1CCTL0=(TA1CCTL0 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA1CCR0_CM         (TA1CCTL0>>14) & 0x0003
//TA1CCTL0  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA1CCTL1  开始 ******************************************************************
#define put_TA1CCR1_CCIFG(x)   TA1CCTL1=(TA1CCTL1 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA1CCR1_CCIFG      (TA1CCTL1>>0) & 0x0001
#define put_TA1CCR1_COV(x)     TA1CCTL1=(TA1CCTL1 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA1CCR1_COV        (TA1CCTL1>>1) & 0x0001
#define put_TA1CCR1_OUT(x)     TA1CCTL1=(TA1CCTL1 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA1CCR1_OUT        (TA1CCTL1>>2) & 0x0001
#define put_TA1CCR1_CCI(x)     TA1CCTL1=(TA1CCTL1 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA1CCR1_CCI        (TA1CCTL1>>3) & 0x0001
#define put_TA1CCR1_CCIE(x)    TA1CCTL1=(TA1CCTL1 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA1CCR1_CCIE       (TA1CCTL1>>4) & 0x0001
#define put_TA1CCR1_OUTMOD(x)  TA1CCTL1=(TA1CCTL1 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA1CCR1_OUTMOD     (TA1CCTL1>>5) & 0x0007
#define put_TA1CCR1_CAP(x)     TA1CCTL1=(TA1CCTL1 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA1CCR1_CAP        (TA1CCTL1>>8) & 0x0001
#define put_TA1CCR1_SCCI(x)    TA1CCTL1=(TA1CCTL1 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA1CCR1_SCCI       (TA1CCTL1>>10) & 0x0001
#define put_TA1CCR1_SCS(x)     TA1CCTL1=(TA1CCTL1 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA1CCR1_SCS        (TA1CCTL1>>11) & 0x0001
#define put_TA1CCR1_CCIS(x)    TA1CCTL1=(TA1CCTL1 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA1CCR1_CCIS       (TA1CCTL1>>12) & 0x0003
#define put_TA1CCR1_CM(x)      TA1CCTL1=(TA1CCTL1 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA1CCR1_CM         (TA1CCTL1>>14) & 0x0003
//TA1CCTL1  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA1CCTL2  开始 ******************************************************************
#define put_TA1CCR2_CCIFG(x)   TA1CCTL2=(TA1CCTL2 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TA1CCR2_CCIFG      (TA1CCTL2>>0) & 0x0001
#define put_TA1CCR2_COV(x)     TA1CCTL2=(TA1CCTL2 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TA1CCR2_COV        (TA1CCTL1>>1) & 0x0001
#define put_TA1CCR2_OUT(x)     TA1CCTL2=(TA1CCTL2 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TA1CCR2_OUT        (TA1CCTL2>>2) & 0x0001
#define put_TA1CCR2_CCI(x)     TA1CCTL2=(TA1CCTL2 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TA1CCR2_CCI        (TA1CCTL2>>3) & 0x0001
#define put_TA1CCR2_CCIE(x)    TA1CCTL2=(TA1CCTL2 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TA1CCR2_CCIE       (TA1CCTL2>>4) & 0x0001
#define put_TA1CCR2_OUTMOD(x)  TA1CCTL2=(TA1CCTL2 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TA1CCR2_OUTMOD     (TA1CCTL2>>5) & 0x0007
#define put_TA1CCR2_CAP(x)     TA1CCTL2=(TA1CCTL2 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TA1CCR2_CAP        (TA1CCTL2>>8) & 0x0001
#define put_TA1CCR2_SCCI(x)    TA1CCTL2=(TA1CCTL2 & 0xFBFF) | ((x & 0x0001) << 10)
#define get_TA1CCR2_SCCI       (TA1CCTL2>>10) & 0x0001
#define put_TA1CCR2_SCS(x)     TA1CCTL2=(TA1CCTL2 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TA1CCR2_SCS        (TA1CCTL2>>11) & 0x0001
#define put_TA1CCR2_CCIS(x)    TA1CCTL2=(TA1CCTL2 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TA1CCR2_CCIS       (TA1CCTL2>>12) & 0x0003
#define put_TA1CCR2_CM(x)      TA1CCTL2=(TA1CCTL2 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TA1CCR2_CM         (TA1CCTL2>>14) & 0x0003
//TA1CCTL2  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TA1CCRx 开始 ********************************************************************
#define put_TA1CCR0(x)          TA1CCR0=x
#define get_TA1CCR0             TA1CCR0
#define put_TA1CCR1(x)          TA1CCR1=x
#define get_TA1CCR1             TA1CCR1
#define put_TA1CCR2(x)          TA1CCR2=x
#define get_TA1CCR2             TA1CCR2
//TA1CCRx 结束 *********************************************************************
//---------------------------------------------------------------------------------
//TA1IV 开始 **********************************************************************
#define put_TA1IV(x)            TA1IV=(TA1IV & 0xFFF0) | ((x & 0x000E) << 0)
#define get_TA1IV               (TA1IV>>0) & 0x000E
//TA1IV 结束***********************************************************************
//---------------------------------------------------------------------------------
//TA1EX0开始 **********************************************************************
#define put_TA1_IDEX(x)         TA1EX0=(TA1EX0 & 0xFFF8) | ((x & 0x0007) << 0)
#define get_TA1_IDEX            (TA1EX0>>0) & 0x0007
//TA1EX0结束 **********************************************************************
//---------------------------------------------------------------------------------
//TB0R开始 ************************************************************************
#define put_TA1R(x)             TA1R=x
#define get_TA1R                TA1R
//定时器A结束 *********************************************************************
//---------------------------------------------------------------------------------
//TB0CTL  开始 ********************************************************************
#define put_TB0_TBIFG(x)    TB0CTL=(TB0CTL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0_TBIFG       (TB0CTL>>0) & 0x0001
#define put_TB0_TBIE(x)     TB0CTL=(TB0CTL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0_TBIE        (TB0CTL>>1) & 0x0001
#define put_TB0_TBCLR(x)    TB0CTL=(TB0CTL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0_TBCLR       (TB0CTL>>2) & 0x0001
#define put_TB0_MC(x)       TB0CTL=(TB0CTL & 0xFFCF) | ((x & 0x0003) << 4)
#define get_TB0_MC          (TB0CTL>>4) & 0x0003
#define put_TB0_ID(x)       TB0CTL=(TB0CTL & 0xFF3F) | ((x & 0x0003) << 6)
#define get_TB0_ID          (TB0CTL>>6) & 0x0003
#define put_TB0_TBSSEL(x)   TB0CTL=(TB0CTL & 0xFCFF) | ((x & 0x0003) << 8)
#define get_TB0_TBSSEL      (TB0CTL>>8) & 0x0003
#define put_TB0_CNTL(x)     TB0CTL=(TB0CTL & 0xE7FF) | ((x & 0x0003) << 11)
#define get_TB0_CNTL        (TB0CTL>>11) & 0x0003
#define put_TB0_TBCLGRP(x)  TB0CTL=(TB0CTL & 0x9FFF) | ((x & 0x0003) << 13)
#define get_TB0_TBCLGRP     (TB0CTL>>13) & 0x0003 
//TB0CTL结束 *******************************************************************
//定时器A结束 ##################################################################
//------------------------------------------------------------------------------
//定时器B开始 ##################################################################
//TB0CCTL0  开始 ***************************************************************
#define put_TB0CCR0_CCIFG(x)   TB0CCTL0=(TB0CCTL0 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0CCR0_CCIFG      (TB0CCTL0>>0) & 0x0001
#define put_TB0CCR0_COV(x)     TB0CCTL0=(TB0CCTL0 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0CCR0_COV        (TB0CCTL0>>1) & 0x0001
#define put_TB0CCR0_OUT(x)     TB0CCTL0=(TB0CCTL0 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0CCR0_OUT        (TB0CCTL0>>2) & 0x0001
#define put_TB0CCR0_CCI(x)     TB0CCTL0=(TB0CCTL0 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TB0CCR0_CCI        (TB0CCTL0>>3) & 0x0001
#define put_TB0CCR0_CCIE(x)    TB0CCTL0=(TB0CCTL0 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TB0CCR0_CCIE       (TB0CCTL0>>4) & 0x0001
#define put_TB0CCR0_OUTMOD(x)  TB0CCTL0=(TB0CCTL0 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TB0CCR0_OUTMOD     (TB0CCTL0>>5) & 0x0007
#define put_TB0CCR0_CAP(x)     TB0CCTL0=(TB0CCTL0 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TB0CCR0_CAP        (TB0CCTL0>>8) & 0x0001
#define put_TB0CCR0_CLLD(x)    TB0CCTL0=(TB0CCTL0 & 0xF9FF) | ((x & 0x0003) << 9)
#define get_TB0CCR0_CLLD       (TB0CCTL0>>9) & 0x0003
#define put_TB0CCR0_SCS(x)     TB0CCTL0=(TB0CCTL0 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TB0CCR0_SCS        (TB0CCTL0>>11) & 0x0001
#define put_TB0CCR0_CCIS(x)    TB0CCTL0=(TB0CCTL0 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TB0CCR0_CCIS       (TB0CCTL0>>12) & 0x0003
#define put_TB0CCR0_CM(x)      TB0CCTL0=(TB0CCTL0 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TB0CCR0_CM         (TB0CCTL0>>14) & 0x0003
//TB0CCTL0  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TB0CCTL1  开始 ******************************************************************
#define put_TB0CCR1_CCIFG(x)   TB0CCTL1=(TB0CCTL1 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0CCR1_CCIFG      (TB0CCTL1>>0) & 0x0001
#define put_TB0CCR1_COV(x)     TB0CCTL1=(TB0CCTL1 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0CCR1_COV        (TB0CCTL1>>1) & 0x0001
#define put_TB0CCR1_OUT(x)     TB0CCTL1=(TB0CCTL1 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0CCR1_OUT        (TB0CCTL1>>2) & 0x0001
#define put_TB0CCR1_CCI(x)     TB0CCTL1=(TB0CCTL1 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TB0CCR1_CCI        (TB0CCTL1>>3) & 0x0001
#define put_TB0CCR1_CCIE(x)    TB0CCTL1=(TB0CCTL1 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TB0CCR1_CCIE       (TB0CCTL1>>4) & 0x0001
#define put_TB0CCR1_OUTMOD(x)  TB0CCTL1=(TB0CCTL1 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TB0CCR1_OUTMOD     (TB0CCTL1>>5) & 0x0007
#define put_TB0CCR1_CAP(x)     TB0CCTL1=(TB0CCTL1 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TB0CCR1_CAP        (TB0CCTL1>>8) & 0x0001
#define put_TB0CCR1_CLLD(x)    TB0CCTL1=(TB0CCTL1 & 0xF9FF) | ((x & 0x0003) << 9)
#define get_TB0CCR1_CLLD       (TB0CCTL1>>9) & 0x0003
#define put_TB0CCR1_SCS(x)     TB0CCTL1=(TB0CCTL1 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TB0CCR1_SCS        (TB0CCTL1>>11) & 0x0001
#define put_TB0CCR1_CCIS(x)    TB0CCTL1=(TB0CCTL1 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TB0CCR1_CCIS       (TB0CCTL1>>12) & 0x0003
#define put_TB0CCR1_CM(x)      TB0CCTL1=(TB0CCTL1 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TB0CCR1_CM         (TB0CCTL1>>14) & 0x0003
//TB0CCTL1  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TB0CCTL2  开始 ******************************************************************
#define put_TB0CCR2_CCIFG(x)   TB0CCTL2=(TB0CCTL2 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0CCR2_CCIFG      (TB0CCTL2>>0) & 0x0001
#define put_TB0CCR2_COV(x)     TB0CCTL2=(TB0CCTL2 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0CCR2_COV        (TB0CCTL1>>1) & 0x0001
#define put_TB0CCR2_OUT(x)     TB0CCTL2=(TB0CCTL2 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0CCR2_OUT        (TB0CCTL2>>2) & 0x0001
#define put_TB0CCR2_CCI(x)     TB0CCTL2=(TB0CCTL2 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TB0CCR2_CCI        (TB0CCTL2>>3) & 0x0001
#define put_TB0CCR2_CCIE(x)    TB0CCTL2=(TB0CCTL2 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TB0CCR2_CCIE       (TB0CCTL2>>4) & 0x0001
#define put_TB0CCR2_OUTMOD(x)  TB0CCTL2=(TB0CCTL2 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TB0CCR2_OUTMOD     (TB0CCTL2>>5) & 0x0007
#define put_TB0CCR2_CAP(x)     TB0CCTL2=(TB0CCTL2 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TB0CCR2_CAP        (TB0CCTL2>>8) & 0x0001
#define put_TB0CCR2_CLLD(x)    TB0CCTL2=(TB0CCTL2 & 0xF9FF) | ((x & 0x0003) << 9)
#define get_TB0CCR2_CLLD       (TB0CCTL2>>9) & 0x0003
#define put_TB0CCR2_SCS(x)     TB0CCTL2=(TB0CCTL2 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TB0CCR2_SCS        (TB0CCTL2>>11) & 0x0001
#define put_TB0CCR2_CCIS(x)    TB0CCTL2=(TB0CCTL2 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TB0CCR2_CCIS       (TB0CCTL2>>12) & 0x0003
#define put_TB0CCR2_CM(x)      TB0CCTL2=(TB0CCTL2 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TB0CCR2_CM         (TB0CCTL2>>14) & 0x0003
//TB0CCTL2  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TB0CCTL3  开始 ******************************************************************
#define put_TB0CCR3_CCIFG(x)   TB0CCTL3=(TB0CCTL3 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0CCR3_CCIFG      (TB0CCTL3>>0) & 0x0001
#define put_TB0CCR3_COV(x)     TB0CCTL3=(TB0CCTL3 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0CCR3_COV        (TB0CCTL1>>1) & 0x0001
#define put_TB0CCR3_OUT(x)     TB0CCTL3=(TB0CCTL3 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0CCR3_OUT        (TB0CCTL3>>2) & 0x0001
#define put_TB0CCR3_CCI(x)     TB0CCTL3=(TB0CCTL3 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TB0CCR3_CCI        (TB0CCTL3>>3) & 0x0001
#define put_TB0CCR3_CCIE(x)    TB0CCTL3=(TB0CCTL3 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TB0CCR3_CCIE       (TB0CCTL3>>4) & 0x0001
#define put_TB0CCR3_OUTMOD(x)  TB0CCTL3=(TB0CCTL3 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TB0CCR3_OUTMOD     (TB0CCTL3>>5) & 0x0007
#define put_TB0CCR3_CAP(x)     TB0CCTL3=(TB0CCTL3 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TB0CCR3_CAP        (TB0CCTL3>>8) & 0x0001
#define put_TB0CCR3_CLLD(x)    TB0CCTL3=(TB0CCTL3 & 0xF9FF) | ((x & 0x0003) << 9)
#define get_TB0CCR3_CLLD       (TB0CCTL3>>9) & 0x0003
#define put_TB0CCR3_SCS(x)     TB0CCTL3=(TB0CCTL3 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TB0CCR3_SCS        (TB0CCTL3>>11) & 0x0001
#define put_TB0CCR3_CCIS(x)    TB0CCTL3=(TB0CCTL3 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TB0CCR3_CCIS       (TB0CCTL3>>12) & 0x0003
#define put_TB0CCR3_CM(x)      TB0CCTL3=(TB0CCTL3 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TB0CCR3_CM         (TB0CCTL3>>14) & 0x0003
//TB0CCTL3  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TB0CCTL4  开始 ******************************************************************
#define put_TB0CCR4_CCIFG(x)   TB0CCTL4=(TB0CCTL4 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0CCR4_CCIFG      (TB0CCTL4>>0) & 0x0001
#define put_TB0CCR4_COV(x)     TB0CCTL4=(TB0CCTL4 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0CCR4_COV        (TB0CCTL1>>1) & 0x0001
#define put_TB0CCR4_OUT(x)     TB0CCTL4=(TB0CCTL4 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0CCR4_OUT        (TB0CCTL4>>2) & 0x0001
#define put_TB0CCR4_CCI(x)     TB0CCTL4=(TB0CCTL4 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TB0CCR4_CCI        (TB0CCTL4>>3) & 0x0001
#define put_TB0CCR4_CCIE(x)    TB0CCTL4=(TB0CCTL4 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TB0CCR4_CCIE       (TB0CCTL4>>4) & 0x0001
#define put_TB0CCR4_OUTMOD(x)  TB0CCTL4=(TB0CCTL4 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TB0CCR4_OUTMOD     (TB0CCTL4>>5) & 0x0007
#define put_TB0CCR4_CAP(x)     TB0CCTL4=(TB0CCTL4 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TB0CCR4_CAP        (TB0CCTL4>>8) & 0x0001
#define put_TB0CCR4_CLLD(x)    TB0CCTL4=(TB0CCTL4 & 0xF9FF) | ((x & 0x0003) << 9)
#define get_TB0CCR4_CLLD       (TB0CCTL4>>9) & 0x0003
#define put_TB0CCR4_SCS(x)     TB0CCTL4=(TB0CCTL4 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TB0CCR4_SCS        (TB0CCTL4>>11) & 0x0001
#define put_TB0CCR4_CCIS(x)    TB0CCTL4=(TB0CCTL4 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TB0CCR4_CCIS       (TB0CCTL4>>12) & 0x0003
#define put_TB0CCR4_CM(x)      TB0CCTL4=(TB0CCTL4 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TB0CCR4_CM         (TB0CCTL4>>14) & 0x0003
//TB0CCTL4  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TB0CCTL5  开始 ******************************************************************
#define put_TB0CCR5_CCIFG(x)   TB0CCTL5=(TB0CCTL5 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0CCR5_CCIFG      (TB0CCTL5>>0) & 0x0001
#define put_TB0CCR5_COV(x)     TB0CCTL5=(TB0CCTL5 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0CCR5_COV        (TB0CCTL1>>1) & 0x0001
#define put_TB0CCR5_OUT(x)     TB0CCTL5=(TB0CCTL5 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0CCR5_OUT        (TB0CCTL5>>2) & 0x0001
#define put_TB0CCR5_CCI(x)     TB0CCTL5=(TB0CCTL5 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TB0CCR5_CCI        (TB0CCTL5>>3) & 0x0001
#define put_TB0CCR5_CCIE(x)    TB0CCTL5=(TB0CCTL5 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TB0CCR5_CCIE       (TB0CCTL5>>4) & 0x0001
#define put_TB0CCR5_OUTMOD(x)  TB0CCTL5=(TB0CCTL5 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TB0CCR5_OUTMOD     (TB0CCTL5>>5) & 0x0007
#define put_TB0CCR5_CAP(x)     TB0CCTL5=(TB0CCTL5 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TB0CCR5_CAP        (TB0CCTL5>>8) & 0x0001
#define put_TB0CCR5_CLLD(x)    TB0CCTL5=(TB0CCTL5 & 0xF9FF) | ((x & 0x0003) << 9)
#define get_TB0CCR5_CLLD       (TB0CCTL5>>9) & 0x0003
#define put_TB0CCR5_SCS(x)     TB0CCTL5=(TB0CCTL5 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TB0CCR5_SCS        (TB0CCTL5>>11) & 0x0001
#define put_TB0CCR5_CCIS(x)    TB0CCTL5=(TB0CCTL5 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TB0CCR5_CCIS       (TB0CCTL5>>12) & 0x0003
#define put_TB0CCR5_CM(x)      TB0CCTL5=(TB0CCTL5 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TB0CCR5_CM         (TB0CCTL5>>14) & 0x0003
//TB0CCTL5  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TB0CCTL6  开始 ******************************************************************
#define put_TB0CCR6_CCIFG(x)   TB0CCTL6=(TB0CCTL6 & 0xFFFE) | ((x & 0x0001) << 0)
#define get_TB0CCR6_CCIFG      (TB0CCTL6>>0) & 0x0001
#define put_TB0CCR6_COV(x)     TB0CCTL6=(TB0CCTL6 & 0xFFFD) | ((x & 0x0001) << 1)
#define get_TB0CCR6_COV        (TB0CCTL1>>1) & 0x0001
#define put_TB0CCR6_OUT(x)     TB0CCTL6=(TB0CCTL6 & 0xFFFB) | ((x & 0x0001) << 2)
#define get_TB0CCR6_OUT        (TB0CCTL6>>2) & 0x0001
#define put_TB0CCR6_CCI(x)     TB0CCTL6=(TB0CCTL6 & 0xFFF7) | ((x & 0x0001) << 3)
#define get_TB0CCR6_CCI        (TB0CCTL6>>3) & 0x0001
#define put_TB0CCR6_CCIE(x)    TB0CCTL6=(TB0CCTL6 & 0xFFEF) | ((x & 0x0001) << 4)
#define get_TB0CCR6_CCIE       (TB0CCTL6>>4) & 0x0001
#define put_TB0CCR6_OUTMOD(x)  TB0CCTL6=(TB0CCTL6 & 0xFF1F) | ((x & 0x0007) << 5)
#define get_TB0CCR6_OUTMOD     (TB0CCTL6>>5) & 0x0007
#define put_TB0CCR6_CAP(x)     TB0CCTL6=(TB0CCTL6 & 0xFEFF) | ((x & 0x0001) << 8)
#define get_TB0CCR6_CAP        (TB0CCTL6>>8) & 0x0001
#define put_TB0CCR5_CLLD(x)    TB0CCTL5=(TB0CCTL5 & 0xF9FF) | ((x & 0x0003) << 9)
#define get_TB0CCR5_CLLD       (TB0CCTL5>>9) & 0x0003
#define put_TB0CCR6_SCS(x)     TB0CCTL6=(TB0CCTL6 & 0xF7FF) | ((x & 0x0001) << 11)
#define get_TB0CCR6_SCS        (TB0CCTL6>>11) & 0x0001
#define put_TB0CCR6_CCIS(x)    TB0CCTL6=(TB0CCTL6 & 0xCFFF) | ((x & 0x0003) << 12)
#define get_TB0CCR6_CCIS       (TB0CCTL6>>12) & 0x0003
#define put_TB0CCR6_CM(x)      TB0CCTL6=(TB0CCTL6 & 0x3FFF) | ((x & 0x0003) << 14)
#define get_TB0CCR6_CM         (TB0CCTL6>>14) & 0x0003
//TB0CCTL6  结束 ******************************************************************
//---------------------------------------------------------------------------------
//TB0CCRx 开始 ********************************************************************
#define put_TB0CCR0(x)          TB0CCR0=x
#define get_TB0CCR0             TB0CCR0
#define put_TB0CCR1(x)          TB0CCR1=x
#define get_TB0CCR1             TB0CCR1
#define put_TB0CCR2(x)          TB0CCR2=x
#define get_TB0CCR2             TB0CCR2
#define put_TB0CCR3(x)          TB0CCR3=x
#define get_TB0CCR3             TB0CCR3
#define put_TB0CCR4(x)          TB0CCR4=x
#define get_TB0CCR4             TB0CCR4
#define put_TB0CCR5(x)          TB0CCR5=x
#define get_TB0CCR5             TB0CCR5
#define put_TB0CCR6(x)          TB0CCR6=x
#define get_TB0CCR6             TB0CCR6
//TB0CCRx 结束 ********************************************************************
//---------------------------------------------------------------------------------
//TB0IV 开始 **********************************************************************
#define put_TB0IV(x)            TB0IV=(TB0IV & 0xFFF0) | ((x & 0x000E) << 0)
#define get_TB0IV               (TB0CCTL4>>0) & 0x000E
//TB0IV 结束 **********************************************************************
//---------------------------------------------------------------------------------
//TB0EX0开始 **********************************************************************
#define put_TB0_IDEX(x)         TB0EX0=(TB0EX0 & 0xFFF8) | ((x & 0x0007) << 0)
#define get_TB0_IDEX            (TB0EX0>>0) & 0x0007
//TB0EX0结束 **********************************************************************
//---------------------------------------------------------------------------------
//TB0R开始 ************************************************************************
#define put_TB0R(x)             TB0R=x
#define get_TB0R                TB0R
//TB0R结束 *************************************************************************
//定时器B结束 ######################################################################
//----------------------------------------------------------------------------------
//MSP430单片机的并行口开始 #########################################################
//P1口开始 *************************************************************************
#define put_P1DIR_BIT0(x)       P1DIR=(P1DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1DIR_BIT0          (P1DIR>>0) & 0x0001
#define put_P1DIR_BIT1(x)       P1DIR=(P1DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1DIR_BIT1          (P1DIR>>1) & 0x0001
#define put_P1DIR_BIT2(x)       P1DIR=(P1DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1DIR_BIT2          (P1DIR>>2) & 0x0001
#define put_P1DIR_BIT3(x)       P1DIR=(P1DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1DIR_BIT3          (P1DIR>>3) & 0x0001
#define put_P1DIR_BIT4(x)       P1DIR=(P1DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1DIR_BIT4          (P1DIR>>4) & 0x0001
#define put_P1DIR_BIT5(x)       P1DIR=(P1DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1DIR_BIT5          (P1DIR>>5) & 0x0001
#define put_P1DIR_BIT6(x)       P1DIR=(P1DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1DIR_BIT6          (P1DIR>>6) & 0x0001
#define put_P1DIR_BIT7(x)       P1DIR=(P1DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1DIR_BIT7          (P1DIR>>7) & 0x0001
#define put_P1DIR(x)            P1DIR=(P1DIR & 0xFF00) | (x & 0x00FF)
#define get_P1DIR               P1DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1IE_BIT0(x)        P1IE=(P1IE & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1IE_BIT0           (P1IE>>0) & 0x0001
#define put_P1IE_BIT1(x)        P1IE=(P1IE & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1IE_BIT1           (P1IE>>1) & 0x0001
#define put_P1IE_BIT2(x)        P1IE=(P1IE & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1IE_BIT2           (P1IE>>2) & 0x0001
#define put_P1IE_BIT3(x)        P1IE=(P1IE & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1IE_BIT3           (P1IE>>3) & 0x0001
#define put_P1IE_BIT4(x)        P1IE=(P1IE & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1IE_BIT4           (P1IE>>4) & 0x0001
#define put_P1IE_BIT5(x)        P1IE=(P1IE & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1IE_BIT5           (P1IE>>5) & 0x0001
#define put_P1IE_BIT6(x)        P1IE=(P1IE & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1IE_BIT6           (P1IE>>6) & 0x0001
#define put_P1IE_BIT7(x)        P1IE=(P1IE & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1IE_BIT7           (P1IE>>7) & 0x0001
#define put_P1IE(x)             P1IE=(P1IE & 0xFF00) | (x & 0x00FF)
#define get_P1IE                P1IE & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1IES_BIT0(x)       P1IES=(P1IES & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1IES_BIT0          (P1IES>>0) & 0x0001
#define put_P1IES_BIT1(x)       P1IES=(P1IES & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1IES_BIT1          (P1IES>>1) & 0x0001
#define put_P1IES_BIT2(x)       P1IES=(P1IES & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1IES_BIT2          (P1IES>>2) & 0x0001
#define put_P1IES_BIT3(x)       P1IES=(P1IES & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1IES_BIT3          (P1IES>>3) & 0x0001
#define put_P1IES_BIT4(x)       P1IES=(P1IES & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1IES_BIT4          (P1IES>>4) & 0x0001
#define put_P1IES_BIT5(x)       P1IES=(P1IES & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1IES_BIT5          (P1IES>>5) & 0x0001
#define put_P1IES_BIT6(x)       P1IES=(P1IES & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1IES_BIT6          (P1IES>>6) & 0x0001
#define put_P1IES_BIT7(x)       P1IES=(P1IES & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1IES_BIT7          (P1IES>>7) & 0x0001
#define put_P1IES(x)            P1IES=(P1IES & 0xFF00) | (x & 0x00FF)
#define get_P1IES               P1IES & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1IFG_BIT0(x)       P1IFG=(P1IFG & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1IFG_BIT0          (P1IFG>>0) & 0x0001
#define put_P1IFG_BIT1(x)       P1IFG=(P1IFG & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1IFG_BIT1          (P1IFG>>1) & 0x0001
#define put_P1IFG_BIT2(x)       P1IFG=(P1IFG & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1IFG_BIT2          (P1IFG>>2) & 0x0001
#define put_P1IFG_BIT3(x)       P1IFG=(P1IFG & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1IFG_BIT3          (P1IFG>>3) & 0x0001
#define put_P1IFG_BIT4(x)       P1IFG=(P1IFG & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1IFG_BIT4          (P1IFG>>4) & 0x0001
#define put_P1IFG_BIT5(x)       P1IFG=(P1IFG & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1IFG_BIT5          (P1IFG>>5) & 0x0001
#define put_P1IFG_BIT6(x)       P1IFG=(P1IFG & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1IFG_BIT6          (P1IFG>>6) & 0x0001
#define put_P1IFG_BIT7(x)       P1IFG=(P1IFG & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1IFG_BIT7          (P1IFG>>7) & 0x0001
#define put_P1IFG(x)            P1IFG=(P1IFG & 0xFF00) | (x & 0x00FF)
#define get_P1IFG               P1IFG & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1IN_BIT0(x)        P1IN=(P1IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1IN_BIT0           (P1IN>>0) & 0x0001
#define put_P1IN_BIT1(x)        P1IN=(P1IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1IN_BIT1           (P1IN>>1) & 0x0001
#define put_P1IN_BIT2(x)        P1IN=(P1IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1IN_BIT2           (P1IN>>2) & 0x0001
#define put_P1IN_BIT3(x)        P1IN=(P1IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1IN_BIT3           (P1IN>>3) & 0x0001
#define put_P1IN_BIT4(x)        P1IN=(P1IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1IN_BIT4           (P1IN>>4) & 0x0001
#define put_P1IN_BIT5(x)        P1IN=(P1IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1IN_BIT5           (P1IN>>5) & 0x0001
#define put_P1IN_BIT6(x)        P1IN=(P1IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1IN_BIT6           (P1IN>>6) & 0x0001
#define put_P1IN_BIT7(x)        P1IN=(P1IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1IN_BIT7           (P1IN>>7) & 0x0001
#define put_P1IN(x)             P1IN=(P1IN & 0xFF00) | (x & 0x00FF)
#define get_P1IN                P1IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1OUT_BIT0(x)       P1OUT=(P1OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1OUT_BIT0          (P1OUT>>0) & 0x0001
#define put_P1OUT_BIT1(x)       P1OUT=(P1OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1OUT_BIT1          (P1OUT>>1) & 0x0001
#define put_P1OUT_BIT2(x)       P1OUT=(P1OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1OUT_BIT2          (P1OUT>>2) & 0x0001
#define put_P1OUT_BIT3(x)       P1OUT=(P1OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1OUT_BIT3          (P1OUT>>3) & 0x0001
#define put_P1OUT_BIT4(x)       P1OUT=(P1OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1OUT_BIT4          (P1OUT>>4) & 0x0001
#define put_P1OUT_BIT5(x)       P1OUT=(P1OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1OUT_BIT5          (P1OUT>>5) & 0x0001
#define put_P1OUT_BIT6(x)       P1OUT=(P1OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1OUT_BIT6          (P1OUT>>6) & 0x0001
#define put_P1OUT_BIT7(x)       P1OUT=(P1OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1OUT_BIT7          (P1OUT>>7) & 0x0001
#define put_P1OUT(x)            P1OUT=(P1OUT & 0xFF00) | (x & 0x00FF)
#define get_P1OUT               P1OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1SEL_BIT0(x)       P1SEL=(P1SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1SEL_BIT0          (P1SEL>>0) & 0x0001
#define put_P1SEL_BIT1(x)       P1SEL=(P1SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1SEL_BIT1          (P1SEL>>1) & 0x0001
#define put_P1SEL_BIT2(x)       P1SEL=(P1SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1SEL_BIT2          (P1SEL>>2) & 0x0001
#define put_P1SEL_BIT3(x)       P1SEL=(P1SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1SEL_BIT3          (P1SEL>>3) & 0x0001
#define put_P1SEL_BIT4(x)       P1SEL=(P1SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1SEL_BIT4          (P1SEL>>4) & 0x0001
#define put_P1SEL_BIT5(x)       P1SEL=(P1SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1SEL_BIT5          (P1SEL>>5) & 0x0001
#define put_P1SEL_BIT6(x)       P1SEL=(P1SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1SEL_BIT6          (P1SEL>>6) & 0x0001
#define put_P1SEL_BIT7(x)       P1SEL=(P1SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1SEL_BIT7          (P1SEL>>7) & 0x0001
#define put_P1SEL(x)            P1SEL=(P1SEL & 0xFF00) | (x & 0x00FF)
#define get_P1SEL               P1SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1REN_BIT0(x)       P1REN=(P1REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1REN_BIT0          (P1REN>>0) & 0x0001
#define put_P1REN_BIT1(x)       P1REN=(P1REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1REN_BIT1          (P1REN>>1) & 0x0001
#define put_P1REN_BIT2(x)       P1REN=(P1REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1REN_BIT2          (P1REN>>2) & 0x0001
#define put_P1REN_BIT3(x)       P1REN=(P1REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1REN_BIT3          (P1REN>>3) & 0x0001
#define put_P1REN_BIT4(x)       P1REN=(P1REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1REN_BIT4          (P1REN>>4) & 0x0001
#define put_P1REN_BIT5(x)       P1REN=(P1REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1REN_BIT5          (P1REN>>5) & 0x0001
#define put_P1REN_BIT6(x)       P1REN=(P1REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1REN_BIT6          (P1REN>>6) & 0x0001
#define put_P1REN_BIT7(x)       P1REN=(P1REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1REN_BIT7          (P1REN>>7) & 0x0001
#define put_P1REN(x)            P1REN=(P1REN & 0xFF00) | (x & 0x00FF)
#define get_P1REN               P1REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P1DS_BIT0(x)        P1DS=(P1DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P1DS_BIT0           (P1DS>>0) & 0x0001
#define put_P1DS_BIT1(x)        P1DS=(P1DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P1DS_BIT1           (P1DS>>1) & 0x0001
#define put_P1DS_BIT2(x)        P1DS=(P1DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P1DS_BIT2           (P1DS>>2) & 0x0001
#define put_P1DS_BIT3(x)        P1DS=(P1DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P1DS_BIT3           (P1DS>>3) & 0x0001
#define put_P1DS_BIT4(x)        P1DS=(P1DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P1DS_BIT4           (P1DS>>4) & 0x0001
#define put_P1DS_BIT5(x)        P1DS=(P1DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P1DS_BIT5           (P1DS>>5) & 0x0001
#define put_P1DS_BIT6(x)        P1DS=(P1DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P1DS_BIT6           (P1DS>>6) & 0x0001
#define put_P1DS_BIT7(x)        P1DS=(P1DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P1DS_BIT7           (P1DS>>7) & 0x0001
#define put_P1DS(x)             P1DS=(P1DS & 0xFF00) | (x & 0x00FF)
#define get_P1DS                P1DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2DIR_BIT0(x)       P2DIR=(P2DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2DIR_BIT0          (P2DIR>>0) & 0x0001
#define put_P2DIR_BIT1(x)       P2DIR=(P2DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2DIR_BIT1          (P2DIR>>1) & 0x0001
#define put_P2DIR_BIT2(x)       P2DIR=(P2DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2DIR_BIT2          (P2DIR>>2) & 0x0001
#define put_P2DIR_BIT3(x)       P2DIR=(P2DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2DIR_BIT3          (P2DIR>>3) & 0x0001
#define put_P2DIR_BIT4(x)       P2DIR=(P2DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2DIR_BIT4          (P2DIR>>4) & 0x0001
#define put_P2DIR_BIT5(x)       P2DIR=(P2DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2DIR_BIT5          (P2DIR>>5) & 0x0001
#define put_P2DIR_BIT6(x)       P2DIR=(P2DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2DIR_BIT6          (P2DIR>>6) & 0x0001
#define put_P2DIR_BIT7(x)       P2DIR=(P2DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2DIR_BIT7          (P2DIR>>7) & 0x0001
#define put_P2DIR(x)            P2DIR=(P2DIR & 0xFF00) | (x & 0x00FF)
#define get_P2DIR               P2DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2IE_BIT0(x)        P2IE=(P2IE & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2IE_BIT0           (P2IE>>0) & 0x0001
#define put_P2IE_BIT1(x)        P2IE=(P2IE & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2IE_BIT1           (P2IE>>1) & 0x0001
#define put_P2IE_BIT2(x)        P2IE=(P2IE & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2IE_BIT2           (P2IE>>2) & 0x0001
#define put_P2IE_BIT3(x)        P2IE=(P2IE & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2IE_BIT3           (P2IE>>3) & 0x0001
#define put_P2IE_BIT4(x)        P2IE=(P2IE & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2IE_BIT4           (P2IE>>4) & 0x0001
#define put_P2IE_BIT5(x)        P2IE=(P2IE & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2IE_BIT5           (P2IE>>5) & 0x0001
#define put_P2IE_BIT6(x)        P2IE=(P2IE & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2IE_BIT6           (P2IE>>6) & 0x0001
#define put_P2IE_BIT7(x)        P2IE=(P2IE & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2IE_BIT7           (P2IE>>7) & 0x0001
#define put_P2IE(x)             P2IE=(P2IE & 0xFF00) | (x & 0x00FF)
#define get_P2IE                P2IE & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2IES_BIT0(x)       P2IES=(P2IES & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2IES_BIT0          (P2IES>>0) & 0x0001
#define put_P2IES_BIT1(x)       P2IES=(P2IES & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2IES_BIT1          (P2IES>>1) & 0x0001
#define put_P2IES_BIT2(x)       P2IES=(P2IES & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2IES_BIT2          (P2IES>>2) & 0x0001
#define put_P2IES_BIT3(x)       P2IES=(P2IES & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2IES_BIT3          (P2IES>>3) & 0x0001
#define put_P2IES_BIT4(x)       P2IES=(P2IES & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2IES_BIT4          (P2IES>>4) & 0x0001
#define put_P2IES_BIT5(x)       P2IES=(P2IES & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2IES_BIT5          (P2IES>>5) & 0x0001
#define put_P2IES_BIT6(x)       P2IES=(P2IES & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2IES_BIT6          (P2IES>>6) & 0x0001
#define put_P2IES_BIT7(x)       P2IES=(P2IES & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2IES_BIT7          (P2IES>>7) & 0x0001
#define put_P2IES(x)            P2IES=(P2IES & 0xFF00) | (x & 0x00FF)
#define get_P2IES               P2IES & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2IFG_BIT0(x)       P2IFG=(P2IFG & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2IFG_BIT0          (P2IFG>>0) & 0x0001
#define put_P2IFG_BIT1(x)       P2IFG=(P2IFG & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2IFG_BIT1          (P2IFG>>1) & 0x0001
#define put_P2IFG_BIT2(x)       P2IFG=(P2IFG & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2IFG_BIT2          (P2IFG>>2) & 0x0001
#define put_P2IFG_BIT3(x)       P2IFG=(P2IFG & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2IFG_BIT3          (P2IFG>>3) & 0x0001
#define put_P2IFG_BIT4(x)       P2IFG=(P2IFG & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2IFG_BIT4          (P2IFG>>4) & 0x0001
#define put_P2IFG_BIT5(x)       P2IFG=(P2IFG & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2IFG_BIT5          (P2IFG>>5) & 0x0001
#define put_P2IFG_BIT6(x)       P2IFG=(P2IFG & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2IFG_BIT6          (P2IFG>>6) & 0x0001
#define put_P2IFG_BIT7(x)       P2IFG=(P2IFG & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2IFG_BIT7          (P2IFG>>7) & 0x0001
#define put_P2IFG(x)            P2IFG=(P2IFG & 0xFF00) | (x & 0x00FF)
#define get_P2IFG               P2IFG & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2IN_BIT0(x)        P2IN=(P2IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2IN_BIT0           (P2IN>>0) & 0x0001
#define put_P2IN_BIT1(x)        P2IN=(P2IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2IN_BIT1           (P2IN>>1) & 0x0001
#define put_P2IN_BIT2(x)        P2IN=(P2IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2IN_BIT2           (P2IN>>2) & 0x0001
#define put_P2IN_BIT3(x)        P2IN=(P2IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2IN_BIT3           (P2IN>>3) & 0x0001
#define put_P2IN_BIT4(x)        P2IN=(P2IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2IN_BIT4           (P2IN>>4) & 0x0001
#define put_P2IN_BIT5(x)        P2IN=(P2IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2IN_BIT5           (P2IN>>5) & 0x0001
#define put_P2IN_BIT6(x)        P2IN=(P2IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2IN_BIT6           (P2IN>>6) & 0x0001
#define put_P2IN_BIT7(x)        P2IN=(P2IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2IN_BIT7           (P2IN>>7) & 0x0001
#define put_P2IN(x)             P2IN=(P2IN & 0xFF00) | (x & 0x00FF)
#define get_P2IN                P2IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2OUT_BIT0(x)       P2OUT=(P2OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2OUT_BIT0          (P2OUT>>0) & 0x0001
#define put_P2OUT_BIT1(x)       P2OUT=(P2OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2OUT_BIT1          (P2OUT>>1) & 0x0001
#define put_P2OUT_BIT2(x)       P2OUT=(P2OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2OUT_BIT2          (P2OUT>>2) & 0x0001
#define put_P2OUT_BIT3(x)       P2OUT=(P2OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2OUT_BIT3          (P2OUT>>3) & 0x0001
#define put_P2OUT_BIT4(x)       P2OUT=(P2OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2OUT_BIT4          (P2OUT>>4) & 0x0001
#define put_P2OUT_BIT5(x)       P2OUT=(P2OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2OUT_BIT5          (P2OUT>>5) & 0x0001
#define put_P2OUT_BIT6(x)       P2OUT=(P2OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2OUT_BIT6          (P2OUT>>6) & 0x0001
#define put_P2OUT_BIT7(x)       P2OUT=(P2OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2OUT_BIT7          (P2OUT>>7) & 0x0001
#define put_P2OUT(x)            P2OUT=(P2OUT & 0xFF00) | (x & 0x00FF)
#define get_P2OUT               P2OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2SEL_BIT0(x)       P2SEL=(P2SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2SEL_BIT0          (P2SEL>>0) & 0x0001
#define put_P2SEL_BIT1(x)       P2SEL=(P2SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2SEL_BIT1          (P2SEL>>1) & 0x0001
#define put_P2SEL_BIT2(x)       P2SEL=(P2SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2SEL_BIT2          (P2SEL>>2) & 0x0001
#define put_P2SEL_BIT3(x)       P2SEL=(P2SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2SEL_BIT3          (P2SEL>>3) & 0x0001
#define put_P2SEL_BIT4(x)       P2SEL=(P2SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2SEL_BIT4          (P2SEL>>4) & 0x0001
#define put_P2SEL_BIT5(x)       P2SEL=(P2SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2SEL_BIT5          (P2SEL>>5) & 0x0001
#define put_P2SEL_BIT6(x)       P2SEL=(P2SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2SEL_BIT6          (P2SEL>>6) & 0x0001
#define put_P2SEL_BIT7(x)       P2SEL=(P2SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2SEL_BIT7          (P2SEL>>7) & 0x0001
#define put_P2SEL(x)            P2SEL=(P2SEL & 0xFF00) | (x & 0x00FF)
#define get_P2SEL               P2SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2REN_BIT0(x)       P2REN=(P2REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2REN_BIT0          (P2REN>>0) & 0x0001
#define put_P2REN_BIT1(x)       P2REN=(P2REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2REN_BIT1          (P2REN>>1) & 0x0001
#define put_P2REN_BIT2(x)       P2REN=(P2REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2REN_BIT2          (P2REN>>2) & 0x0001
#define put_P2REN_BIT3(x)       P2REN=(P2REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2REN_BIT3          (P2REN>>3) & 0x0001
#define put_P2REN_BIT4(x)       P2REN=(P2REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2REN_BIT4          (P2REN>>4) & 0x0001
#define put_P2REN_BIT5(x)       P2REN=(P2REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2REN_BIT5          (P2REN>>5) & 0x0001
#define put_P2REN_BIT6(x)       P2REN=(P2REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2REN_BIT6          (P2REN>>6) & 0x0001
#define put_P2REN_BIT7(x)       P2REN=(P2REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2REN_BIT7          (P2REN>>7) & 0x0001
#define put_P2REN(x)            P2REN=(P2REN & 0xFF00) | (x & 0x00FF)
#define get_P2REN               P2REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P2DS_BIT0(x)        P2DS=(P2DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P2DS_BIT0           (P2DS>>0) & 0x0001
#define put_P2DS_BIT1(x)        P2DS=(P2DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P2DS_BIT1           (P2DS>>1) & 0x0001
#define put_P2DS_BIT2(x)        P2DS=(P2DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P2DS_BIT2           (P2DS>>2) & 0x0001
#define put_P2DS_BIT3(x)        P2DS=(P2DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P2DS_BIT3           (P2DS>>3) & 0x0001
#define put_P2DS_BIT4(x)        P2DS=(P2DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P2DS_BIT4           (P2DS>>4) & 0x0001
#define put_P2DS_BIT5(x)        P2DS=(P2DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P2DS_BIT5           (P2DS>>5) & 0x0001
#define put_P2DS_BIT6(x)        P2DS=(P2DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P2DS_BIT6           (P2DS>>6) & 0x0001
#define put_P2DS_BIT7(x)        P2DS=(P2DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P2DS_BIT7           (P2DS>>7) & 0x0001
#define put_P2DS(x)             P2DS=(P2DS & 0xFF00) | (x & 0x00FF)
#define get_P2DS                P2DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P3DIR_BIT0(x)       P3DIR=(P3DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P3DIR_BIT0          (P3DIR>>0) & 0x0001
#define put_P3DIR_BIT1(x)       P3DIR=(P3DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P3DIR_BIT1          (P3DIR>>1) & 0x0001
#define put_P3DIR_BIT2(x)       P3DIR=(P3DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P3DIR_BIT2          (P3DIR>>2) & 0x0001
#define put_P3DIR_BIT3(x)       P3DIR=(P3DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P3DIR_BIT3          (P3DIR>>3) & 0x0001
#define put_P3DIR_BIT4(x)       P3DIR=(P3DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P3DIR_BIT4          (P3DIR>>4) & 0x0001
#define put_P3DIR_BIT5(x)       P3DIR=(P3DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P3DIR_BIT5          (P3DIR>>5) & 0x0001
#define put_P3DIR_BIT6(x)       P3DIR=(P3DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P3DIR_BIT6          (P3DIR>>6) & 0x0001
#define put_P3DIR_BIT7(x)       P3DIR=(P3DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P3DIR_BIT7          (P3DIR>>7) & 0x0001
#define put_P3DIR(x)            P3DIR=(P3DIR & 0xFF00) | (x & 0x00FF)
#define get_P3DIR               P3DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P3IN_BIT0(x)        P3IN=(P3IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P3IN_BIT0           (P3IN>>0) & 0x0001
#define put_P3IN_BIT1(x)        P3IN=(P3IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P3IN_BIT1           (P3IN>>1) & 0x0001
#define put_P3IN_BIT2(x)        P3IN=(P3IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P3IN_BIT2           (P3IN>>2) & 0x0001
#define put_P3IN_BIT3(x)        P3IN=(P3IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P3IN_BIT3           (P3IN>>3) & 0x0001
#define put_P3IN_BIT4(x)        P3IN=(P3IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P3IN_BIT4           (P3IN>>4) & 0x0001
#define put_P3IN_BIT5(x)        P3IN=(P3IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P3IN_BIT5           (P3IN>>5) & 0x0001
#define put_P3IN_BIT6(x)        P3IN=(P3IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P3IN_BIT6           (P3IN>>6) & 0x0001
#define put_P3IN_BIT7(x)        P3IN=(P3IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P3IN_BIT7           (P3IN>>7) & 0x0001
#define put_P3IN(x)             P3IN=(P3IN & 0xFF00) | (x & 0x00FF)
#define get_P3IN                P3IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P3OUT_BIT0(x)       P3OUT=(P3OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P3OUT_BIT0          (P3OUT>>0) & 0x0001
#define put_P3OUT_BIT1(x)       P3OUT=(P3OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P3OUT_BIT1          (P3OUT>>1) & 0x0001
#define put_P3OUT_BIT2(x)       P3OUT=(P3OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P3OUT_BIT2          (P3OUT>>2) & 0x0001
#define put_P3OUT_BIT3(x)       P3OUT=(P3OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P3OUT_BIT3          (P3OUT>>3) & 0x0001
#define put_P3OUT_BIT4(x)       P3OUT=(P3OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P3OUT_BIT4          (P3OUT>>4) & 0x0001
#define put_P3OUT_BIT5(x)       P3OUT=(P3OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P3OUT_BIT5          (P3OUT>>5) & 0x0001
#define put_P3OUT_BIT6(x)       P3OUT=(P3OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P3OUT_BIT6          (P3OUT>>6) & 0x0001
#define put_P3OUT_BIT7(x)       P3OUT=(P3OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P3OUT_BIT7          (P3OUT>>7) & 0x0001
#define put_P3OUT(x)            P3OUT=(P3OUT & 0xFF00) | (x & 0x00FF)
#define get_P3OUT               P3OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P3SEL_BIT0(x)       P3SEL=(P3SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P3SEL_BIT0          (P3SEL>>0) & 0x0001
#define put_P3SEL_BIT1(x)       P3SEL=(P3SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P3SEL_BIT1          (P3SEL>>1) & 0x0001
#define put_P3SEL_BIT2(x)       P3SEL=(P3SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P3SEL_BIT2          (P3SEL>>2) & 0x0001
#define put_P3SEL_BIT3(x)       P3SEL=(P3SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P3SEL_BIT3          (P3SEL>>3) & 0x0001
#define put_P3SEL_BIT4(x)       P3SEL=(P3SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P3SEL_BIT4          (P3SEL>>4) & 0x0001
#define put_P3SEL_BIT5(x)       P3SEL=(P3SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P3SEL_BIT5          (P3SEL>>5) & 0x0001
#define put_P3SEL_BIT6(x)       P3SEL=(P3SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P3SEL_BIT6          (P3SEL>>6) & 0x0001
#define put_P3SEL_BIT7(x)       P3SEL=(P3SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P3SEL_BIT7          (P3SEL>>7) & 0x0001
#define put_P3SEL(x)            P3SEL=(P3SEL & 0xFF00) | (x & 0x00FF)
#define get_P3SEL               P3SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P3REN_BIT0(x)       P3REN=(P3REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P3REN_BIT0          (P3REN>>0) & 0x0001
#define put_P3REN_BIT1(x)       P3REN=(P3REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P3REN_BIT1          (P3REN>>1) & 0x0001
#define put_P3REN_BIT2(x)       P3REN=(P3REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P3REN_BIT2          (P3REN>>2) & 0x0001
#define put_P3REN_BIT3(x)       P3REN=(P3REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P3REN_BIT3          (P3REN>>3) & 0x0001
#define put_P3REN_BIT4(x)       P3REN=(P3REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P3REN_BIT4          (P3REN>>4) & 0x0001
#define put_P3REN_BIT5(x)       P3REN=(P3REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P3REN_BIT5          (P3REN>>5) & 0x0001
#define put_P3REN_BIT6(x)       P3REN=(P3REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P3REN_BIT6          (P3REN>>6) & 0x0001
#define put_P3REN_BIT7(x)       P3REN=(P3REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P3REN_BIT7          (P3REN>>7) & 0x0001
#define put_P3REN(x)            P3REN=(P3REN & 0xFF00) | (x & 0x00FF)
#define get_P3REN               P3REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P3DS_BIT0(x)        P3DS=(P3DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P3DS_BIT0           (P3DS>>0) & 0x0001
#define put_P3DS_BIT1(x)        P3DS=(P3DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P3DS_BIT1           (P3DS>>1) & 0x0001
#define put_P3DS_BIT2(x)        P3DS=(P3DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P3DS_BIT2           (P3DS>>2) & 0x0001
#define put_P3DS_BIT3(x)        P3DS=(P3DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P3DS_BIT3           (P3DS>>3) & 0x0001
#define put_P3DS_BIT4(x)        P3DS=(P3DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P3DS_BIT4           (P3DS>>4) & 0x0001
#define put_P3DS_BIT5(x)        P3DS=(P3DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P3DS_BIT5           (P3DS>>5) & 0x0001
#define put_P3DS_BIT6(x)        P3DS=(P3DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P3DS_BIT6           (P3DS>>6) & 0x0001
#define put_P3DS_BIT7(x)        P3DS=(P3DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P3DS_BIT7           (P3DS>>7) & 0x0001
#define put_P3DS(x)             P3DS=(P3DS & 0xFF00) | (x & 0x00FF)
#define get_P3DS                P3DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P4DIR_BIT0(x)       P4DIR=(P4DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P4DIR_BIT0          (P4DIR>>0) & 0x0001
#define put_P4DIR_BIT1(x)       P4DIR=(P4DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P4DIR_BIT1          (P4DIR>>1) & 0x0001
#define put_P4DIR_BIT2(x)       P4DIR=(P4DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P4DIR_BIT2          (P4DIR>>2) & 0x0001
#define put_P4DIR_BIT3(x)       P4DIR=(P4DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P4DIR_BIT3          (P4DIR>>3) & 0x0001
#define put_P4DIR_BIT4(x)       P4DIR=(P4DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P4DIR_BIT4          (P4DIR>>4) & 0x0001
#define put_P4DIR_BIT5(x)       P4DIR=(P4DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P4DIR_BIT5          (P4DIR>>5) & 0x0001
#define put_P4DIR_BIT6(x)       P4DIR=(P4DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P4DIR_BIT6          (P4DIR>>6) & 0x0001
#define put_P4DIR_BIT7(x)       P4DIR=(P4DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P4DIR_BIT7          (P4DIR>>7) & 0x0001
#define put_P4DIR(x)            P4DIR=(P4DIR & 0xFF00) | (x & 0x00FF)
#define get_P4DIR               P4DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P4IN_BIT0(x)        P4IN=(P4IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P4IN_BIT0           (P4IN>>0) & 0x0001
#define put_P4IN_BIT1(x)        P4IN=(P4IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P4IN_BIT1           (P4IN>>1) & 0x0001
#define put_P4IN_BIT2(x)        P4IN=(P4IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P4IN_BIT2           (P4IN>>2) & 0x0001
#define put_P4IN_BIT3(x)        P4IN=(P4IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P4IN_BIT3           (P4IN>>3) & 0x0001
#define put_P4IN_BIT4(x)        P4IN=(P4IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P4IN_BIT4           (P4IN>>4) & 0x0001
#define put_P4IN_BIT5(x)        P4IN=(P4IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P4IN_BIT5           (P4IN>>5) & 0x0001
#define put_P4IN_BIT6(x)        P4IN=(P4IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P4IN_BIT6           (P4IN>>6) & 0x0001
#define put_P4IN_BIT7(x)        P4IN=(P4IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P4IN_BIT7           (P4IN>>7) & 0x0001
#define put_P4IN(x)             P4IN=(P4IN & 0xFF00) | (x & 0x00FF)
#define get_P4IN                P4IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P4OUT_BIT0(x)       P4OUT=(P4OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P4OUT_BIT0          (P4OUT>>0) & 0x0001
#define put_P4OUT_BIT1(x)       P4OUT=(P4OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P4OUT_BIT1          (P4OUT>>1) & 0x0001
#define put_P4OUT_BIT2(x)       P4OUT=(P4OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P4OUT_BIT2          (P4OUT>>2) & 0x0001
#define put_P4OUT_BIT3(x)       P4OUT=(P4OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P4OUT_BIT3          (P4OUT>>3) & 0x0001
#define put_P4OUT_BIT4(x)       P4OUT=(P4OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P4OUT_BIT4          (P4OUT>>4) & 0x0001
#define put_P4OUT_BIT5(x)       P4OUT=(P4OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P4OUT_BIT5          (P4OUT>>5) & 0x0001
#define put_P4OUT_BIT6(x)       P4OUT=(P4OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P4OUT_BIT6          (P4OUT>>6) & 0x0001
#define put_P4OUT_BIT7(x)       P4OUT=(P4OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P4OUT_BIT7          (P4OUT>>7) & 0x0001
#define put_P4OUT(x)            P4OUT=(P4OUT & 0xFF00) | (x & 0x00FF)
#define get_P4OUT               P4OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P4SEL_BIT0(x)       P4SEL=(P4SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P4SEL_BIT0          (P4SEL>>0) & 0x0001
#define put_P4SEL_BIT1(x)       P4SEL=(P4SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P4SEL_BIT1          (P4SEL>>1) & 0x0001
#define put_P4SEL_BIT2(x)       P4SEL=(P4SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P4SEL_BIT2          (P4SEL>>2) & 0x0001
#define put_P4SEL_BIT3(x)       P4SEL=(P4SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P4SEL_BIT3          (P4SEL>>3) & 0x0001
#define put_P4SEL_BIT4(x)       P4SEL=(P4SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P4SEL_BIT4          (P4SEL>>4) & 0x0001
#define put_P4SEL_BIT5(x)       P4SEL=(P4SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P4SEL_BIT5          (P4SEL>>5) & 0x0001
#define put_P4SEL_BIT6(x)       P4SEL=(P4SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P4SEL_BIT6          (P4SEL>>6) & 0x0001
#define put_P4SEL_BIT7(x)       P4SEL=(P4SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P4SEL_BIT7          (P4SEL>>7) & 0x0001
#define put_P4SEL(x)            P4SEL=(P4SEL & 0xFF00) | (x & 0x00FF)
#define get_P4SEL               P4SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P4REN_BIT0(x)       P4REN=(P4REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P4REN_BIT0          (P4REN>>0) & 0x0001
#define put_P4REN_BIT1(x)       P4REN=(P4REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P4REN_BIT1          (P4REN>>1) & 0x0001
#define put_P4REN_BIT2(x)       P4REN=(P4REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P4REN_BIT2          (P4REN>>2) & 0x0001
#define put_P4REN_BIT3(x)       P4REN=(P4REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P4REN_BIT3          (P4REN>>3) & 0x0001
#define put_P4REN_BIT4(x)       P4REN=(P4REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P4REN_BIT4          (P4REN>>4) & 0x0001
#define put_P4REN_BIT5(x)       P4REN=(P4REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P4REN_BIT5          (P4REN>>5) & 0x0001
#define put_P4REN_BIT6(x)       P4REN=(P4REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P4REN_BIT6          (P4REN>>6) & 0x0001
#define put_P4REN_BIT7(x)       P4REN=(P4REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P4REN_BIT7          (P4REN>>7) & 0x0001
#define put_P4REN(x)            P4REN=(P4REN & 0xFF00) | (x & 0x00FF)
#define get_P4REN               P4REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P4DS_BIT0(x)        P4DS=(P4DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P4DS_BIT0           (P4DS>>0) & 0x0001
#define put_P4DS_BIT1(x)        P4DS=(P4DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P4DS_BIT1           (P4DS>>1) & 0x0001
#define put_P4DS_BIT2(x)        P4DS=(P4DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P4DS_BIT2           (P4DS>>2) & 0x0001
#define put_P4DS_BIT3(x)        P4DS=(P4DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P4DS_BIT3           (P4DS>>3) & 0x0001
#define put_P4DS_BIT4(x)        P4DS=(P4DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P4DS_BIT4           (P4DS>>4) & 0x0001
#define put_P4DS_BIT5(x)        P4DS=(P4DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P4DS_BIT5           (P4DS>>5) & 0x0001
#define put_P4DS_BIT6(x)        P4DS=(P4DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P4DS_BIT6           (P4DS>>6) & 0x0001
#define put_P4DS_BIT7(x)        P4DS=(P4DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P4DS_BIT7           (P4DS>>7) & 0x0001
#define put_P4DS(x)             P4DS=(P4DS & 0xFF00) | (x & 0x00FF)
#define get_P4DS                P4DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P5DIR_BIT0(x)       P5DIR=(P5DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P5DIR_BIT0          (P5DIR>>0) & 0x0001
#define put_P5DIR_BIT1(x)       P5DIR=(P5DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P5DIR_BIT1          (P5DIR>>1) & 0x0001
#define put_P5DIR_BIT2(x)       P5DIR=(P5DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P5DIR_BIT2          (P5DIR>>2) & 0x0001
#define put_P5DIR_BIT3(x)       P5DIR=(P5DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P5DIR_BIT3          (P5DIR>>3) & 0x0001
#define put_P5DIR_BIT4(x)       P5DIR=(P5DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P5DIR_BIT4          (P5DIR>>4) & 0x0001
#define put_P5DIR_BIT5(x)       P5DIR=(P5DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P5DIR_BIT5          (P5DIR>>5) & 0x0001
#define put_P5DIR_BIT6(x)       P5DIR=(P5DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P5DIR_BIT6          (P5DIR>>6) & 0x0001
#define put_P5DIR_BIT7(x)       P5DIR=(P5DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P5DIR_BIT7          (P5DIR>>7) & 0x0001
#define put_P5DIR(x)            P5DIR=(P5DIR & 0xFF00) | (x & 0x00FF)
#define get_P5DIR               P5DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P5IN_BIT0(x)        P5IN=(P5IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P5IN_BIT0           (P5IN>>0) & 0x0001
#define put_P5IN_BIT1(x)        P5IN=(P5IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P5IN_BIT1           (P5IN>>1) & 0x0001
#define put_P5IN_BIT2(x)        P5IN=(P5IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P5IN_BIT2           (P5IN>>2) & 0x0001
#define put_P5IN_BIT3(x)        P5IN=(P5IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P5IN_BIT3           (P5IN>>3) & 0x0001
#define put_P5IN_BIT4(x)        P5IN=(P5IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P5IN_BIT4           (P5IN>>4) & 0x0001
#define put_P5IN_BIT5(x)        P5IN=(P5IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P5IN_BIT5           (P5IN>>5) & 0x0001
#define put_P5IN_BIT6(x)        P5IN=(P5IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P5IN_BIT6           (P5IN>>6) & 0x0001
#define put_P5IN_BIT7(x)        P5IN=(P5IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P5IN_BIT7           (P5IN>>7) & 0x0001
#define put_P5IN(x)             P5IN=(P5IN & 0xFF00) | (x & 0x00FF)
#define get_P5IN                P5IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P5OUT_BIT0(x)       P5OUT=(P5OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P5OUT_BIT0          (P5OUT>>0) & 0x0001
#define put_P5OUT_BIT1(x)       P5OUT=(P5OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P5OUT_BIT1          (P5OUT>>1) & 0x0001
#define put_P5OUT_BIT2(x)       P5OUT=(P5OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P5OUT_BIT2          (P5OUT>>2) & 0x0001
#define put_P5OUT_BIT3(x)       P5OUT=(P5OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P5OUT_BIT3          (P5OUT>>3) & 0x0001
#define put_P5OUT_BIT4(x)       P5OUT=(P5OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P5OUT_BIT4          (P5OUT>>4) & 0x0001
#define put_P5OUT_BIT5(x)       P5OUT=(P5OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P5OUT_BIT5          (P5OUT>>5) & 0x0001
#define put_P5OUT_BIT6(x)       P5OUT=(P5OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P5OUT_BIT6          (P5OUT>>6) & 0x0001
#define put_P5OUT_BIT7(x)       P5OUT=(P5OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P5OUT_BIT7          (P5OUT>>7) & 0x0001
#define put_P5OUT(x)            P5OUT=(P5OUT & 0xFF00) | (x & 0x00FF)
#define get_P5OUT               P5OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P5SEL_BIT0(x)       P5SEL=(P5SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P5SEL_BIT0          (P5SEL>>0) & 0x0001
#define put_P5SEL_BIT1(x)       P5SEL=(P5SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P5SEL_BIT1          (P5SEL>>1) & 0x0001
#define put_P5SEL_BIT2(x)       P5SEL=(P5SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P5SEL_BIT2          (P5SEL>>2) & 0x0001
#define put_P5SEL_BIT3(x)       P5SEL=(P5SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P5SEL_BIT3          (P5SEL>>3) & 0x0001
#define put_P5SEL_BIT4(x)       P5SEL=(P5SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P5SEL_BIT4          (P5SEL>>4) & 0x0001
#define put_P5SEL_BIT5(x)       P5SEL=(P5SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P5SEL_BIT5          (P5SEL>>5) & 0x0001
#define put_P5SEL_BIT6(x)       P5SEL=(P5SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P5SEL_BIT6          (P5SEL>>6) & 0x0001
#define put_P5SEL_BIT7(x)       P5SEL=(P5SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P5SEL_BIT7          (P5SEL>>7) & 0x0001
#define put_P5SEL(x)            P5SEL=(P5SEL & 0xFF00) | (x & 0x00FF)
#define get_P5SEL               P5SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P5REN_BIT0(x)       P5REN=(P5REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P5REN_BIT0          (P5REN>>0) & 0x0001
#define put_P5REN_BIT1(x)       P5REN=(P5REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P5REN_BIT1          (P5REN>>1) & 0x0001
#define put_P5REN_BIT2(x)       P5REN=(P5REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P5REN_BIT2          (P5REN>>2) & 0x0001
#define put_P5REN_BIT3(x)       P5REN=(P5REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P5REN_BIT3          (P5REN>>3) & 0x0001
#define put_P5REN_BIT4(x)       P5REN=(P5REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P5REN_BIT4          (P5REN>>4) & 0x0001
#define put_P5REN_BIT5(x)       P5REN=(P5REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P5REN_BIT5          (P5REN>>5) & 0x0001
#define put_P5REN_BIT6(x)       P5REN=(P5REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P5REN_BIT6          (P5REN>>6) & 0x0001
#define put_P5REN_BIT7(x)       P5REN=(P5REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P5REN_BIT7          (P5REN>>7) & 0x0001
#define put_P5REN(x)            P5REN=(P5REN & 0xFF00) | (x & 0x00FF)
#define get_P5REN               P5REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P5DS_BIT0(x)        P5DS=(P5DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P5DS_BIT0           (P5DS>>0) & 0x0001
#define put_P5DS_BIT1(x)        P5DS=(P5DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P5DS_BIT1           (P5DS>>1) & 0x0001
#define put_P5DS_BIT2(x)        P5DS=(P5DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P5DS_BIT2           (P5DS>>2) & 0x0001
#define put_P5DS_BIT3(x)        P5DS=(P5DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P5DS_BIT3           (P5DS>>3) & 0x0001
#define put_P5DS_BIT4(x)        P5DS=(P5DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P5DS_BIT4           (P5DS>>4) & 0x0001
#define put_P5DS_BIT5(x)        P5DS=(P5DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P5DS_BIT5           (P5DS>>5) & 0x0001
#define put_P5DS_BIT6(x)        P5DS=(P5DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P5DS_BIT6           (P5DS>>6) & 0x0001
#define put_P5DS_BIT7(x)        P5DS=(P5DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P5DS_BIT7           (P5DS>>7) & 0x0001
#define put_P5DS(x)             P5DS=(P5DS & 0xFF00) | (x & 0x00FF)
#define get_P5DS                P5DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P6DIR_BIT0(x)       P6DIR=(P6DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P6DIR_BIT0          (P6DIR>>0) & 0x0001
#define put_P6DIR_BIT1(x)       P6DIR=(P6DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P6DIR_BIT1          (P6DIR>>1) & 0x0001
#define put_P6DIR_BIT2(x)       P6DIR=(P6DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P6DIR_BIT2          (P6DIR>>2) & 0x0001
#define put_P6DIR_BIT3(x)       P6DIR=(P6DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P6DIR_BIT3          (P6DIR>>3) & 0x0001
#define put_P6DIR_BIT4(x)       P6DIR=(P6DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P6DIR_BIT4          (P6DIR>>4) & 0x0001
#define put_P6DIR_BIT5(x)       P6DIR=(P6DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P6DIR_BIT5          (P6DIR>>5) & 0x0001
#define put_P6DIR_BIT6(x)       P6DIR=(P6DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P6DIR_BIT6          (P6DIR>>6) & 0x0001
#define put_P6DIR_BIT7(x)       P6DIR=(P6DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P6DIR_BIT7          (P6DIR>>7) & 0x0001
#define put_P6DIR(x)            P6DIR=(P6DIR & 0xFF00) | (x & 0x00FF)
#define get_P6DIR               P6DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P6IN_BIT0(x)        P6IN=(P6IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P6IN_BIT0           (P6IN>>0) & 0x0001
#define put_P6IN_BIT1(x)        P6IN=(P6IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P6IN_BIT1           (P6IN>>1) & 0x0001
#define put_P6IN_BIT2(x)        P6IN=(P6IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P6IN_BIT2           (P6IN>>2) & 0x0001
#define put_P6IN_BIT3(x)        P6IN=(P6IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P6IN_BIT3           (P6IN>>3) & 0x0001
#define put_P6IN_BIT4(x)        P6IN=(P6IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P6IN_BIT4           (P6IN>>4) & 0x0001
#define put_P6IN_BIT5(x)        P6IN=(P6IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P6IN_BIT5           (P6IN>>5) & 0x0001
#define put_P6IN_BIT6(x)        P6IN=(P6IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P6IN_BIT6           (P6IN>>6) & 0x0001
#define put_P6IN_BIT7(x)        P6IN=(P6IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P6IN_BIT7           (P6IN>>7) & 0x0001
#define put_P6IN(x)             P6IN=(P6IN & 0xFF00) | (x & 0x00FF)
#define get_P6IN                P6IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P6OUT_BIT0(x)       P6OUT=(P6OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P6OUT_BIT0          (P6OUT>>0) & 0x0001
#define put_P6OUT_BIT1(x)       P6OUT=(P6OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P6OUT_BIT1          (P6OUT>>1) & 0x0001
#define put_P6OUT_BIT2(x)       P6OUT=(P6OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P6OUT_BIT2          (P6OUT>>2) & 0x0001
#define put_P6OUT_BIT3(x)       P6OUT=(P6OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P6OUT_BIT3          (P6OUT>>3) & 0x0001
#define put_P6OUT_BIT4(x)       P6OUT=(P6OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P6OUT_BIT4          (P6OUT>>4) & 0x0001
#define put_P6OUT_BIT5(x)       P6OUT=(P6OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P6OUT_BIT5          (P6OUT>>5) & 0x0001
#define put_P6OUT_BIT6(x)       P6OUT=(P6OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P6OUT_BIT6          (P6OUT>>6) & 0x0001
#define put_P6OUT_BIT7(x)       P6OUT=(P6OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P6OUT_BIT7          (P6OUT>>7) & 0x0001
#define put_P6OUT(x)            P6OUT=(P6OUT & 0xFF00) | (x & 0x00FF)
#define get_P6OUT               P6OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P6SEL_BIT0(x)       P6SEL=(P6SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P6SEL_BIT0          (P6SEL>>0) & 0x0001
#define put_P6SEL_BIT1(x)       P6SEL=(P6SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P6SEL_BIT1          (P6SEL>>1) & 0x0001
#define put_P6SEL_BIT2(x)       P6SEL=(P6SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P6SEL_BIT2          (P6SEL>>2) & 0x0001
#define put_P6SEL_BIT3(x)       P6SEL=(P6SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P6SEL_BIT3          (P6SEL>>3) & 0x0001
#define put_P6SEL_BIT4(x)       P6SEL=(P6SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P6SEL_BIT4          (P6SEL>>4) & 0x0001
#define put_P6SEL_BIT5(x)       P6SEL=(P6SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P6SEL_BIT5          (P6SEL>>5) & 0x0001
#define put_P6SEL_BIT6(x)       P6SEL=(P6SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P6SEL_BIT6          (P6SEL>>6) & 0x0001
#define put_P6SEL_BIT7(x)       P6SEL=(P6SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P6SEL_BIT7          (P6SEL>>7) & 0x0001
#define put_P6SEL(x)            P6SEL=(P6SEL & 0xFF00) | (x & 0x00FF)
#define get_P6SEL               P6SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P6REN_BIT0(x)       P6REN=(P6REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P6REN_BIT0          (P6REN>>0) & 0x0001
#define put_P6REN_BIT1(x)       P6REN=(P6REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P6REN_BIT1          (P6REN>>1) & 0x0001
#define put_P6REN_BIT2(x)       P6REN=(P6REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P6REN_BIT2          (P6REN>>2) & 0x0001
#define put_P6REN_BIT3(x)       P6REN=(P6REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P6REN_BIT3          (P6REN>>3) & 0x0001
#define put_P6REN_BIT4(x)       P6REN=(P6REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P6REN_BIT4          (P6REN>>4) & 0x0001
#define put_P6REN_BIT5(x)       P6REN=(P6REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P6REN_BIT5          (P6REN>>5) & 0x0001
#define put_P6REN_BIT6(x)       P6REN=(P6REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P6REN_BIT6          (P6REN>>6) & 0x0001
#define put_P6REN_BIT7(x)       P6REN=(P6REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P6REN_BIT7          (P6REN>>7) & 0x0001
#define put_P6REN(x)            P6REN=(P6REN & 0xFF00) | (x & 0x00FF)
#define get_P6REN               P6REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P6DS_BIT0(x)        P6DS=(P6DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P6DS_BIT0           (P6DS>>0) & 0x0001
#define put_P6DS_BIT1(x)        P6DS=(P6DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P6DS_BIT1           (P6DS>>1) & 0x0001
#define put_P6DS_BIT2(x)        P6DS=(P6DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P6DS_BIT2           (P6DS>>2) & 0x0001
#define put_P6DS_BIT3(x)        P6DS=(P6DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P6DS_BIT3           (P6DS>>3) & 0x0001
#define put_P6DS_BIT4(x)        P6DS=(P6DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P6DS_BIT4           (P6DS>>4) & 0x0001
#define put_P6DS_BIT5(x)        P6DS=(P6DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P6DS_BIT5           (P6DS>>5) & 0x0001
#define put_P6DS_BIT6(x)        P6DS=(P6DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P6DS_BIT6           (P6DS>>6) & 0x0001
#define put_P6DS_BIT7(x)        P6DS=(P6DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P6DS_BIT7           (P6DS>>7) & 0x0001
#define put_P6DS(x)             P6DS=(P6DS & 0xFF00) | (x & 0x00FF)
#define get_P6DS                P6DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P7DIR_BIT0(x)       P7DIR=(P7DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P7DIR_BIT0          (P7DIR>>0) & 0x0001
#define put_P7DIR_BIT1(x)       P7DIR=(P7DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P7DIR_BIT1          (P7DIR>>1) & 0x0001
#define put_P7DIR_BIT2(x)       P7DIR=(P7DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P7DIR_BIT2          (P7DIR>>2) & 0x0001
#define put_P7DIR_BIT3(x)       P7DIR=(P7DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P7DIR_BIT3          (P7DIR>>3) & 0x0001
#define put_P7DIR_BIT4(x)       P7DIR=(P7DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P7DIR_BIT4          (P7DIR>>4) & 0x0001
#define put_P7DIR_BIT5(x)       P7DIR=(P7DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P7DIR_BIT5          (P7DIR>>5) & 0x0001
#define put_P7DIR_BIT6(x)       P7DIR=(P7DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P7DIR_BIT6          (P7DIR>>6) & 0x0001
#define put_P7DIR_BIT7(x)       P7DIR=(P7DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P7DIR_BIT7          (P7DIR>>7) & 0x0001
#define put_P7DIR(x)            P7DIR=(P7DIR & 0xFF00) | (x & 0x00FF)
#define get_P7DIR               P7DIR & 0x00FF
//---------------------------------------------------------------------------------
#define put_P7IN_BIT0(x)        P7IN=(P7IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P7IN_BIT0           (P7IN>>0) & 0x0001
#define put_P7IN_BIT1(x)        P7IN=(P7IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P7IN_BIT1           (P7IN>>1) & 0x0001
#define put_P7IN_BIT2(x)        P7IN=(P7IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P7IN_BIT2           (P7IN>>2) & 0x0001
#define put_P7IN_BIT3(x)        P7IN=(P7IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P7IN_BIT3           (P7IN>>3) & 0x0001
#define put_P7IN_BIT4(x)        P7IN=(P7IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P7IN_BIT4           (P7IN>>4) & 0x0001
#define put_P7IN_BIT5(x)        P7IN=(P7IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P7IN_BIT5           (P7IN>>5) & 0x0001
#define put_P7IN_BIT6(x)        P7IN=(P7IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P7IN_BIT6           (P7IN>>6) & 0x0001
#define put_P7IN_BIT7(x)        P7IN=(P7IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P7IN_BIT7           (P7IN>>7) & 0x0001
#define put_P7IN(x)             P7IN=(P7IN & 0xFF00) | (x & 0x00FF)
#define get_P7IN                P7IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P7OUT_BIT0(x)       P7OUT=(P7OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P7OUT_BIT0          (P7OUT>>0) & 0x0001
#define put_P7OUT_BIT1(x)       P7OUT=(P7OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P7OUT_BIT1          (P7OUT>>1) & 0x0001
#define put_P7OUT_BIT2(x)       P7OUT=(P7OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P7OUT_BIT2          (P7OUT>>2) & 0x0001
#define put_P7OUT_BIT3(x)       P7OUT=(P7OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P7OUT_BIT3          (P7OUT>>3) & 0x0001
#define put_P7OUT_BIT4(x)       P7OUT=(P7OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P7OUT_BIT4          (P7OUT>>4) & 0x0001
#define put_P7OUT_BIT5(x)       P7OUT=(P7OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P7OUT_BIT5          (P7OUT>>5) & 0x0001
#define put_P7OUT_BIT6(x)       P7OUT=(P7OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P7OUT_BIT6          (P7OUT>>6) & 0x0001
#define put_P7OUT_BIT7(x)       P7OUT=(P7OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P7OUT_BIT7          (P7OUT>>7) & 0x0001
#define put_P7OUT(x)            P7OUT=(P7OUT & 0xFF00) | (x & 0x00FF)
#define get_P7OUT               P7OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P7SEL_BIT0(x)       P7SEL=(P7SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P7SEL_BIT0          (P7SEL>>0) & 0x0001
#define put_P7SEL_BIT1(x)       P7SEL=(P7SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P7SEL_BIT1          (P7SEL>>1) & 0x0001
#define put_P7SEL_BIT2(x)       P7SEL=(P7SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P7SEL_BIT2          (P7SEL>>2) & 0x0001
#define put_P7SEL_BIT3(x)       P7SEL=(P7SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P7SEL_BIT3          (P7SEL>>3) & 0x0001
#define put_P7SEL_BIT4(x)       P7SEL=(P7SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P7SEL_BIT4          (P7SEL>>4) & 0x0001
#define put_P7SEL_BIT5(x)       P7SEL=(P7SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P7SEL_BIT5          (P7SEL>>5) & 0x0001
#define put_P7SEL_BIT6(x)       P7SEL=(P7SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P7SEL_BIT6          (P7SEL>>6) & 0x0001
#define put_P7SEL_BIT7(x)       P7SEL=(P7SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P7SEL_BIT7          (P7SEL>>7) & 0x0001
#define put_P7SEL(x)            P7SEL=(P7SEL & 0xFF00) | (x & 0x00FF)
#define get_P7SEL               P7SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P7REN_BIT0(x)       P7REN=(P7REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P7REN_BIT0          (P7REN>>0) & 0x0001
#define put_P7REN_BIT1(x)       P7REN=(P7REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P7REN_BIT1          (P7REN>>1) & 0x0001
#define put_P7REN_BIT2(x)       P7REN=(P7REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P7REN_BIT2          (P7REN>>2) & 0x0001
#define put_P7REN_BIT3(x)       P7REN=(P7REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P7REN_BIT3          (P7REN>>3) & 0x0001
#define put_P7REN_BIT4(x)       P7REN=(P7REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P7REN_BIT4          (P7REN>>4) & 0x0001
#define put_P7REN_BIT5(x)       P7REN=(P7REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P7REN_BIT5          (P7REN>>5) & 0x0001
#define put_P7REN_BIT6(x)       P7REN=(P7REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P7REN_BIT6          (P7REN>>6) & 0x0001
#define put_P7REN_BIT7(x)       P7REN=(P7REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P7REN_BIT7          (P7REN>>7) & 0x0001
#define put_P7REN(x)            P7REN=(P7REN & 0xFF00) | (x & 0x00FF)
#define get_P7REN               P7REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P7DS_BIT0(x)        P7DS=(P7DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P7DS_BIT0           (P7DS>>0) & 0x0001
#define put_P7DS_BIT1(x)        P7DS=(P7DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P7DS_BIT1           (P7DS>>1) & 0x0001
#define put_P7DS_BIT2(x)        P7DS=(P7DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P7DS_BIT2           (P7DS>>2) & 0x0001
#define put_P7DS_BIT3(x)        P7DS=(P7DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P7DS_BIT3           (P7DS>>3) & 0x0001
#define put_P7DS_BIT4(x)        P7DS=(P7DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P7DS_BIT4           (P7DS>>4) & 0x0001
#define put_P7DS_BIT5(x)        P7DS=(P7DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P7DS_BIT5           (P7DS>>5) & 0x0001
#define put_P7DS_BIT6(x)        P7DS=(P7DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P7DS_BIT6           (P7DS>>6) & 0x0001
#define put_P7DS_BIT7(x)        P7DS=(P7DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P7DS_BIT7           (P7DS>>7) & 0x0001
#define put_P7DS(x)             P7DS=(P7DS & 0xFF00) | (x & 0x00FF)
#define get_P7DS                P7DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P8DIR_BIT0(x)       P8DIR=(P8DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P8DIR_BIT0          (P8DIR>>0) & 0x0001
#define put_P8DIR_BIT1(x)       P8DIR=(P8DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P8DIR_BIT1          (P8DIR>>1) & 0x0001
#define put_P8DIR_BIT2(x)       P8DIR=(P8DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P8DIR_BIT2          (P8DIR>>2) & 0x0001
#define put_P8DIR_BIT3(x)       P8DIR=(P8DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P8DIR_BIT3          (P8DIR>>3) & 0x0001
#define put_P8DIR_BIT4(x)       P8DIR=(P8DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P8DIR_BIT4          (P8DIR>>4) & 0x0001
#define put_P8DIR_BIT5(x)       P8DIR=(P8DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P8DIR_BIT5          (P8DIR>>5) & 0x0001
#define put_P8DIR_BIT6(x)       P8DIR=(P8DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P8DIR_BIT6          (P8DIR>>6) & 0x0001
#define put_P8DIR_BIT7(x)       P8DIR=(P8DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P8DIR_BIT7          (P8DIR>>7) & 0x0001
#define put_P8DIR(x)            P8DIR=(P8DIR & 0xFF00) | (x & 0x00FF)
#define get_P8DIR               P8DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P8IN_BIT0(x)        P8IN=(P8IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P8IN_BIT0           (P8IN>>0) & 0x0001
#define put_P8IN_BIT1(x)        P8IN=(P8IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P8IN_BIT1           (P8IN>>1) & 0x0001
#define put_P8IN_BIT2(x)        P8IN=(P8IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P8IN_BIT2           (P8IN>>2) & 0x0001
#define put_P8IN_BIT3(x)        P8IN=(P8IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P8IN_BIT3           (P8IN>>3) & 0x0001
#define put_P8IN_BIT4(x)        P8IN=(P8IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P8IN_BIT4           (P8IN>>4) & 0x0001
#define put_P8IN_BIT5(x)        P8IN=(P8IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P8IN_BIT5           (P8IN>>5) & 0x0001
#define put_P8IN_BIT6(x)        P8IN=(P8IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P8IN_BIT6           (P8IN>>6) & 0x0001
#define put_P8IN_BIT7(x)        P8IN=(P8IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P8IN_BIT7           (P8IN>>7) & 0x0001
#define put_P8IN(x)             P8IN=(P8IN & 0xFF00) | (x & 0x00FF)
#define get_P8IN                P8IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P8OUT_BIT0(x)       P8OUT=(P8OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P8OUT_BIT0          (P8OUT>>0) & 0x0001
#define put_P8OUT_BIT1(x)       P8OUT=(P8OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P8OUT_BIT1          (P8OUT>>1) & 0x0001
#define put_P8OUT_BIT2(x)       P8OUT=(P8OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P8OUT_BIT2          (P8OUT>>2) & 0x0001
#define put_P8OUT_BIT3(x)       P8OUT=(P8OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P8OUT_BIT3          (P8OUT>>3) & 0x0001
#define put_P8OUT_BIT4(x)       P8OUT=(P8OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P8OUT_BIT4          (P8OUT>>4) & 0x0001
#define put_P8OUT_BIT5(x)       P8OUT=(P8OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P8OUT_BIT5          (P8OUT>>5) & 0x0001
#define put_P8OUT_BIT6(x)       P8OUT=(P8OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P8OUT_BIT6          (P8OUT>>6) & 0x0001
#define put_P8OUT_BIT7(x)       P8OUT=(P8OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P8OUT_BIT7          (P8OUT>>7) & 0x0001
#define put_P8OUT(x)            P8OUT=(P8OUT & 0xFF00) | (x & 0x00FF)
#define get_P8OUT               P8OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P8SEL_BIT0(x)       P8SEL=(P8SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P8SEL_BIT0          (P8SEL>>0) & 0x0001
#define put_P8SEL_BIT1(x)       P8SEL=(P8SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P8SEL_BIT1          (P8SEL>>1) & 0x0001
#define put_P8SEL_BIT2(x)       P8SEL=(P8SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P8SEL_BIT2          (P8SEL>>2) & 0x0001
#define put_P8SEL_BIT3(x)       P8SEL=(P8SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P8SEL_BIT3          (P8SEL>>3) & 0x0001
#define put_P8SEL_BIT4(x)       P8SEL=(P8SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P8SEL_BIT4          (P8SEL>>4) & 0x0001
#define put_P8SEL_BIT5(x)       P8SEL=(P8SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P8SEL_BIT5          (P8SEL>>5) & 0x0001
#define put_P8SEL_BIT6(x)       P8SEL=(P8SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P8SEL_BIT6          (P8SEL>>6) & 0x0001
#define put_P8SEL_BIT7(x)       P8SEL=(P8SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P8SEL_BIT7          (P8SEL>>7) & 0x0001
#define put_P8SEL(x)            P8SEL=(P8SEL & 0xFF00) | (x & 0x00FF)
#define get_P8SEL               P8SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P8REN_BIT0(x)       P8REN=(P8REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P8REN_BIT0          (P8REN>>0) & 0x0001
#define put_P8REN_BIT1(x)       P8REN=(P8REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P8REN_BIT1          (P8REN>>1) & 0x0001
#define put_P8REN_BIT2(x)       P8REN=(P8REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P8REN_BIT2          (P8REN>>2) & 0x0001
#define put_P8REN_BIT3(x)       P8REN=(P8REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P8REN_BIT3          (P8REN>>3) & 0x0001
#define put_P8REN_BIT4(x)       P8REN=(P8REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P8REN_BIT4          (P8REN>>4) & 0x0001
#define put_P8REN_BIT5(x)       P8REN=(P8REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P8REN_BIT5          (P8REN>>5) & 0x0001
#define put_P8REN_BIT6(x)       P8REN=(P8REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P8REN_BIT6          (P8REN>>6) & 0x0001
#define put_P8REN_BIT7(x)       P8REN=(P8REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P8REN_BIT7          (P8REN>>7) & 0x0001
#define put_P8REN(x)            P8REN=(P8REN & 0xFF00) | (x & 0x00FF)
#define get_P8REN               P8REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P8DS_BIT0(x)        P8DS=(P8DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P8DS_BIT0           (P8DS>>0) & 0x0001
#define put_P8DS_BIT1(x)        P8DS=(P8DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P8DS_BIT1           (P8DS>>1) & 0x0001
#define put_P8DS_BIT2(x)        P8DS=(P8DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P8DS_BIT2           (P8DS>>2) & 0x0001
#define put_P8DS_BIT3(x)        P8DS=(P8DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P8DS_BIT3           (P8DS>>3) & 0x0001
#define put_P8DS_BIT4(x)        P8DS=(P8DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P8DS_BIT4           (P8DS>>4) & 0x0001
#define put_P8DS_BIT5(x)        P8DS=(P8DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P8DS_BIT5           (P8DS>>5) & 0x0001
#define put_P8DS_BIT6(x)        P8DS=(P8DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P8DS_BIT6           (P8DS>>6) & 0x0001
#define put_P8DS_BIT7(x)        P8DS=(P8DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P8DS_BIT7           (P8DS>>7) & 0x0001
#define put_P8DS(x)             P8DS=(P8DS & 0xFF00) | (x & 0x00FF)
#define get_P8DS                P8DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P9DIR_BIT0(x)       P9DIR=(P9DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P9DIR_BIT0          (P9DIR>>0) & 0x0001
#define put_P9DIR_BIT1(x)       P9DIR=(P9DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P9DIR_BIT1          (P9DIR>>1) & 0x0001
#define put_P9DIR_BIT2(x)       P9DIR=(P9DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P9DIR_BIT2          (P9DIR>>2) & 0x0001
#define put_P9DIR_BIT3(x)       P9DIR=(P9DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P9DIR_BIT3          (P9DIR>>3) & 0x0001
#define put_P9DIR_BIT4(x)       P9DIR=(P9DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P9DIR_BIT4          (P9DIR>>4) & 0x0001
#define put_P9DIR_BIT5(x)       P9DIR=(P9DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P9DIR_BIT5          (P9DIR>>5) & 0x0001
#define put_P9DIR_BIT6(x)       P9DIR=(P9DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P9DIR_BIT6          (P9DIR>>6) & 0x0001
#define put_P9DIR_BIT7(x)       P9DIR=(P9DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P9DIR_BIT7          (P9DIR>>7) & 0x0001
#define put_P9DIR(x)            P9DIR=(P9DIR & 0xFF00) | (x & 0x00FF)
#define get_P9DIR               P9DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P9IN_BIT0(x)        P9IN=(P9IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P9IN_BIT0           (P9IN>>0) & 0x0001
#define put_P9IN_BIT1(x)        P9IN=(P9IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P9IN_BIT1           (P9IN>>1) & 0x0001
#define put_P9IN_BIT2(x)        P9IN=(P9IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P9IN_BIT2           (P9IN>>2) & 0x0001
#define put_P9IN_BIT3(x)        P9IN=(P9IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P9IN_BIT3           (P9IN>>3) & 0x0001
#define put_P9IN_BIT4(x)        P9IN=(P9IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P9IN_BIT4           (P9IN>>4) & 0x0001
#define put_P9IN_BIT5(x)        P9IN=(P9IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P9IN_BIT5           (P9IN>>5) & 0x0001
#define put_P9IN_BIT6(x)        P9IN=(P9IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P9IN_BIT6           (P9IN>>6) & 0x0001
#define put_P9IN_BIT7(x)        P9IN=(P9IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P9IN_BIT7           (P9IN>>7) & 0x0001
#define put_P9IN(x)             P9IN=(P9IN & 0xFF00) | (x & 0x00FF)
#define get_P9IN                P9IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P9OUT_BIT0(x)       P9OUT=(P9OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P9OUT_BIT0          (P9OUT>>0) & 0x0001
#define put_P9OUT_BIT1(x)       P9OUT=(P9OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P9OUT_BIT1          (P9OUT>>1) & 0x0001
#define put_P9OUT_BIT2(x)       P9OUT=(P9OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P9OUT_BIT2          (P9OUT>>2) & 0x0001
#define put_P9OUT_BIT3(x)       P9OUT=(P9OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P9OUT_BIT3          (P9OUT>>3) & 0x0001
#define put_P9OUT_BIT4(x)       P9OUT=(P9OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P9OUT_BIT4          (P9OUT>>4) & 0x0001
#define put_P9OUT_BIT5(x)       P9OUT=(P9OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P9OUT_BIT5          (P9OUT>>5) & 0x0001
#define put_P9OUT_BIT6(x)       P9OUT=(P9OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P9OUT_BIT6          (P9OUT>>6) & 0x0001
#define put_P9OUT_BIT7(x)       P9OUT=(P9OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P9OUT_BIT7          (P9OUT>>7) & 0x0001
#define put_P9OUT(x)            P9OUT=(P9OUT & 0xFF00) | (x & 0x00FF)
#define get_P9OUT               P9OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P9SEL_BIT0(x)       P9SEL=(P9SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P9SEL_BIT0          (P9SEL>>0) & 0x0001
#define put_P9SEL_BIT1(x)       P9SEL=(P9SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P9SEL_BIT1          (P9SEL>>1) & 0x0001
#define put_P9SEL_BIT2(x)       P9SEL=(P9SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P9SEL_BIT2          (P9SEL>>2) & 0x0001
#define put_P9SEL_BIT3(x)       P9SEL=(P9SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P9SEL_BIT3          (P9SEL>>3) & 0x0001
#define put_P9SEL_BIT4(x)       P9SEL=(P9SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P9SEL_BIT4          (P9SEL>>4) & 0x0001
#define put_P9SEL_BIT5(x)       P9SEL=(P9SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P9SEL_BIT5          (P9SEL>>5) & 0x0001
#define put_P9SEL_BIT6(x)       P9SEL=(P9SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P9SEL_BIT6          (P9SEL>>6) & 0x0001
#define put_P9SEL_BIT7(x)       P9SEL=(P9SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P9SEL_BIT7          (P9SEL>>7) & 0x0001
#define put_P9SEL(x)            P9SEL=(P9SEL & 0xFF00) | (x & 0x00FF)
#define get_P9SEL               P9SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P9REN_BIT0(x)       P9REN=(P9REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P9REN_BIT0          (P9REN>>0) & 0x0001
#define put_P9REN_BIT1(x)       P9REN=(P9REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P9REN_BIT1          (P9REN>>1) & 0x0001
#define put_P9REN_BIT2(x)       P9REN=(P9REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P9REN_BIT2          (P9REN>>2) & 0x0001
#define put_P9REN_BIT3(x)       P9REN=(P9REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P9REN_BIT3          (P9REN>>3) & 0x0001
#define put_P9REN_BIT4(x)       P9REN=(P9REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P9REN_BIT4          (P9REN>>4) & 0x0001
#define put_P9REN_BIT5(x)       P9REN=(P9REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P9REN_BIT5          (P9REN>>5) & 0x0001
#define put_P9REN_BIT6(x)       P9REN=(P9REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P9REN_BIT6          (P9REN>>6) & 0x0001
#define put_P9REN_BIT7(x)       P9REN=(P9REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P9REN_BIT7          (P9REN>>7) & 0x0001
#define put_P9REN(x)            P9REN=(P9REN & 0xFF00) | (x & 0x00FF)
#define get_P9REN               P9REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P9DS_BIT0(x)        P9DS=(P9DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P9DS_BIT0           (P9DS>>0) & 0x0001
#define put_P9DS_BIT1(x)        P9DS=(P9DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P9DS_BIT1           (P9DS>>1) & 0x0001
#define put_P9DS_BIT2(x)        P9DS=(P9DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P9DS_BIT2           (P9DS>>2) & 0x0001
#define put_P9DS_BIT3(x)        P9DS=(P9DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P9DS_BIT3           (P9DS>>3) & 0x0001
#define put_P9DS_BIT4(x)        P9DS=(P9DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P9DS_BIT4           (P9DS>>4) & 0x0001
#define put_P9DS_BIT5(x)        P9DS=(P9DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P9DS_BIT5           (P9DS>>5) & 0x0001
#define put_P9DS_BIT6(x)        P9DS=(P9DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P9DS_BIT6           (P9DS>>6) & 0x0001
#define put_P9DS_BIT7(x)        P9DS=(P9DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P9DS_BIT7           (P9DS>>7) & 0x0001
#define put_P9DS(x)             P9DS=(P9DS & 0xFF00) | (x & 0x00FF)
#define get_P9DS                P9DS & 0x00FF
//----------------------------------------------------------------------------------
#define put_P10DIR_BIT0(x)      P10DIR=(P10DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P10DIR_BIT0         (P10DIR>>0) & 0x0001
#define put_P10DIR_BIT1(x)      P10DIR=(P10DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P10DIR_BIT1         (P10DIR>>1) & 0x0001
#define put_P10DIR_BIT2(x)      P10DIR=(P10DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P10DIR_BIT2         (P10DIR>>2) & 0x0001
#define put_P10DIR_BIT3(x)      P10DIR=(P10DIR & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P10DIR_BIT3         (P10DIR>>3) & 0x0001
#define put_P10DIR_BIT4(x)      P10DIR=(P10DIR & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P10DIR_BIT4         (P10DIR>>4) & 0x0001
#define put_P10DIR_BIT5(x)      P10DIR=(P10DIR & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P10DIR_BIT5         (P10DIR>>5) & 0x0001
#define put_P10DIR_BIT6(x)      P10DIR=(P10DIR & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P10DIR_BIT6         (P10DIR>>6) & 0x0001
#define put_P10DIR_BIT7(x)      P10DIR=(P10DIR & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P10DIR_BIT7         (P10DIR>>7) & 0x0001
#define put_P10DIR(x)           P10DIR=(P10DIR & 0xFF00) | (x & 0x00FF)
#define get_P10DIR              P10DIR & 0x00FF
//----------------------------------------------------------------------------------
#define put_P10IN_BIT0(x)        P10IN=(P10IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P10IN_BIT0           (P10IN>>0) & 0x0001
#define put_P10IN_BIT1(x)        P10IN=(P10IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P10IN_BIT1           (P10IN>>1) & 0x0001
#define put_P10IN_BIT2(x)        P10IN=(P10IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P10IN_BIT2           (P10IN>>2) & 0x0001
#define put_P10IN_BIT3(x)        P10IN=(P10IN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P10IN_BIT3           (P10IN>>3) & 0x0001
#define put_P10IN_BIT4(x)        P10IN=(P10IN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P10IN_BIT4           (P10IN>>4) & 0x0001
#define put_P10IN_BIT5(x)        P10IN=(P10IN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P10IN_BIT5           (P10IN>>5) & 0x0001
#define put_P10IN_BIT6(x)        P10IN=(P10IN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P10IN_BIT6           (P10IN>>6) & 0x0001
#define put_P10IN_BIT7(x)        P10IN=(P10IN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P10IN_BIT7           (P10IN>>7) & 0x0001
#define put_P10IN(x)             P10IN=(P10IN & 0xFF00) | (x & 0x00FF)
#define get_P10IN                P10IN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P10OUT_BIT0(x)       P10OUT=(P10OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P10OUT_BIT0          (P10OUT>>0) & 0x0001
#define put_P10OUT_BIT1(x)       P10OUT=(P10OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P10OUT_BIT1          (P10OUT>>1) & 0x0001
#define put_P10OUT_BIT2(x)       P10OUT=(P10OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P10OUT_BIT2          (P10OUT>>2) & 0x0001
#define put_P10OUT_BIT3(x)       P10OUT=(P10OUT & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P10OUT_BIT3          (P10OUT>>3) & 0x0001
#define put_P10OUT_BIT4(x)       P10OUT=(P10OUT & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P10OUT_BIT4          (P10OUT>>4) & 0x0001
#define put_P10OUT_BIT5(x)       P10OUT=(P10OUT & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P10OUT_BIT5          (P10OUT>>5) & 0x0001
#define put_P10OUT_BIT6(x)       P10OUT=(P10OUT & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P10OUT_BIT6          (P10OUT>>6) & 0x0001
#define put_P10OUT_BIT7(x)       P10OUT=(P10OUT & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P10OUT_BIT7          (P10OUT>>7) & 0x0001
#define put_P10OUT(x)            P10OUT=(P10OUT & 0xFF00) | (x & 0x00FF)
#define get_P10OUT               P10OUT & 0x00FF
//----------------------------------------------------------------------------------
#define put_P10SEL_BIT0(x)       P10SEL=(P10SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P10SEL_BIT0          (P10SEL>>0) & 0x0001
#define put_P10SEL_BIT1(x)       P10SEL=(P10SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P10SEL_BIT1          (P10SEL>>1) & 0x0001
#define put_P10SEL_BIT2(x)       P10SEL=(P10SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P10SEL_BIT2          (P10SEL>>2) & 0x0001
#define put_P10SEL_BIT3(x)       P10SEL=(P10SEL & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P10SEL_BIT3          (P10SEL>>3) & 0x0001
#define put_P10SEL_BIT4(x)       P10SEL=(P10SEL & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P10SEL_BIT4          (P10SEL>>4) & 0x0001
#define put_P10SEL_BIT5(x)       P10SEL=(P10SEL & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P10SEL_BIT5          (P10SEL>>5) & 0x0001
#define put_P10SEL_BIT6(x)       P10SEL=(P10SEL & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P10SEL_BIT6          (P10SEL>>6) & 0x0001
#define put_P10SEL_BIT7(x)       P10SEL=(P10SEL & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P10SEL_BIT7          (P10SEL>>7) & 0x0001
#define put_P10SEL(x)            P10SEL=(P10SEL & 0xFF00) | (x & 0x00FF)
#define get_P10SEL               P10SEL & 0x00FF
//----------------------------------------------------------------------------------
#define put_P10REN_BIT0(x)       P10REN=(P10REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P10REN_BIT0          (P10REN>>0) & 0x0001
#define put_P10REN_BIT1(x)       P10REN=(P10REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P10REN_BIT1          (P10REN>>1) & 0x0001
#define put_P10REN_BIT2(x)       P10REN=(P10REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P10REN_BIT2          (P10REN>>2) & 0x0001
#define put_P10REN_BIT3(x)       P10REN=(P10REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P10REN_BIT3          (P10REN>>3) & 0x0001
#define put_P10REN_BIT4(x)       P10REN=(P10REN & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P10REN_BIT4          (P10REN>>4) & 0x0001
#define put_P10REN_BIT5(x)       P10REN=(P10REN & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P10REN_BIT5          (P10REN>>5) & 0x0001
#define put_P10REN_BIT6(x)       P10REN=(P10REN & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P10REN_BIT6          (P10REN>>6) & 0x0001
#define put_P10REN_BIT7(x)       P10REN=(P10REN & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P10REN_BIT7          (P10REN>>7) & 0x0001
#define put_P10REN(x)            P10REN=(P10REN & 0xFF00) | (x & 0x00FF)
#define get_P10REN               P10REN & 0x00FF
//----------------------------------------------------------------------------------
#define put_P10DS_BIT0(x)        P10DS=(P10DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P10DS_BIT0           (P10DS>>0) & 0x0001
#define put_P10DS_BIT1(x)        P10DS=(P10DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P10DS_BIT1           (P10DS>>1) & 0x0001
#define put_P10DS_BIT2(x)        P10DS=(P10DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P10DS_BIT2           (P10DS>>2) & 0x0001
#define put_P10DS_BIT3(x)        P10DS=(P10DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P10DS_BIT3           (P10DS>>3) & 0x0001
#define put_P10DS_BIT4(x)        P10DS=(P10DS & 0xFFEF) | ((x & 0x0001) << 4)
#define get_P10DS_BIT4           (P10DS>>4) & 0x0001
#define put_P10DS_BIT5(x)        P10DS=(P10DS & 0xFFDF) | ((x & 0x0001) << 5)
#define get_P10DS_BIT5           (P10DS>>5) & 0x0001
#define put_P10DS_BIT6(x)        P10DS=(P10DS & 0xFFBF) | ((x & 0x0001) << 6)
#define get_P10DS_BIT6           (P10DS>>6) & 0x0001
#define put_P10DS_BIT7(x)        P10DS=(P10DS & 0xFF7F) | ((x & 0x0001) << 7)
#define get_P10DS_BIT7           (P10DS>>7) & 0x0001
#define put_P10DS(x)             P10DS=(P10DS & 0xFF00) | (x & 0x00FF)
#define get_P10DS                P10DS & 0x00FF
//----------------------------------------------------------------------------------
//P11口开始*************************************************************************
//P11DIR----------------------------------------------------------------------------
#define put_P11DIR_BIT0(x)       P11DIR=(P11DIR & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P11DIR_BIT0          (P11DIR>>0) & 0x0001
#define put_P11DIR_BIT1(x)       P11DIR=(P11DIR & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P11DIR_BIT1          (P11DIR>>1) & 0x0001
#define put_P11DIR_BIT2(x)       P11DIR=(P11DIR & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P11DIR_BIT2          (P11DIR>>2) & 0x0001
#define put_P11DIR(x)            P11DIR=(P11DIR & 0xFFF8) | (x & 0x0007)
#define get_P11DIR               P11DIR & 0x0007
//P11SEL----------------------------------------------------------------------------
#define put_P11IN_BIT0(x)        P11IN=(P11IN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P11IN_BIT0           (P11IN>>0) & 0x0001
#define put_P11IN_BIT1(x)        P11IN=(P11IN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P11IN_BIT1           (P11IN>>1) & 0x0001
#define put_P11IN_BIT2(x)        P11IN=(P11IN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P11IN_BIT2           (P11IN>>2) & 0x0001
#define put_P11IN(x)             P11IN=(P11IN & 0xFF00) | (x & 0x0007)
#define get_P11IN                P11IN & 0x0007
//----------------------------------------------------------------------------------
#define put_P11OUT_BIT0(x)       P11OUT=(P11OUT & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P11OUT_BIT0          (P11OUT>>0) & 0x0001
#define put_P11OUT_BIT1(x)       P11OUT=(P11OUT & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P11OUT_BIT1          (P11OUT>>1) & 0x0001
#define put_P11OUT_BIT2(x)       P11OUT=(P11OUT & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P11OUT_BIT2          (P11OUT>>2) & 0x0001
#define put_P11OUT(x)            P11OUT=(P11OUT & 0xFF00) | (x & 0x0007)
#define get_P11OUT               P11OUT & 0x0007
//----------------------------------------------------------------------------------
#define put_P11SEL_BIT0(x)       P11SEL=(P11SEL & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P11SEL_BIT0          (P11SEL>>0) & 0x0001
#define put_P11SEL_BIT1(x)       P11SEL=(P11SEL & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P11SEL_BIT1          (P11SEL>>1) & 0x0001
#define put_P11SEL_BIT2(x)       P11SEL=(P11SEL & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P11SEL_BIT2          (P11SEL>>2) & 0x0001
#define put_P11SEL(x)            P11SEL=(P11SEL & 0xFFF8) | (x & 0x0007)
#define get_P11SEL               P11SEL & 0x0007
//--------------------------------------------------------------------------------------
#define put_P11REN_BIT0(x)       P11REN=(P11REN & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P11REN_BIT0          (P11REN>>0) & 0x0001
#define put_P11REN_BIT1(x)       P11REN=(P11REN & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P11REN_BIT1          (P11REN>>1) & 0x0001
#define put_P11REN_BIT2(x)       P11REN=(P11REN & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P11REN_BIT2          (P11REN>>2) & 0x0001
#define put_P11REN_BIT3(x)       P11REN=(P11REN & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P11REN_BIT3          (P11REN>>3) & 0x0001
#define put_P11REN(x)            P11REN=(P11REN & 0xFF00) | (x & 0x0007)
#define get_P11REN               P11REN & 0x0007
//----------------------------------------------------------------------------------
#define put_P11DS_BIT0(x)        P11DS=(P11DS & 0xFFFE) | ((x & 0x0001) << 0)
#define get_P11DS_BIT0           (P11DS>>0) & 0x0001
#define put_P11DS_BIT1(x)        P11DS=(P11DS & 0xFFFD) | ((x & 0x0001) << 1)
#define get_P11DS_BIT1           (P11DS>>1) & 0x0001
#define put_P11DS_BIT2(x)        P11DS=(P11DS & 0xFFFB) | ((x & 0x0001) << 2)
#define get_P11DS_BIT2           (P11DS>>2) & 0x0001
#define put_P11DS_BIT3(x)        P11DS=(P11DS & 0xFFF7) | ((x & 0x0001) << 3)
#define get_P11DS_BIT3           (P11DS>>3) & 0x0001
#define put_P11DS(x)             P11DS=(P11DS & 0xFF00) | (x & 0x0007)
#define get_P11DS                P11DS & 0x0007
//----------------------------------------------------------------------------------
//P11口结束 ****************************************************************************
//MSP430单片机的并行口结束 #############################################################
//--------------------------------------------------------------------------------------
//MSP430单片机的UART串行通讯口开始 #####################################################
//UCI_A0 开始 ##########################################################################
#define put_UART0_UCSYNC(x)         UCA0CTL0=(UCA0CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCSYNC            (UCA0CTL0 & (~(0XFFFE)))>>0
#define put_UART0_UCMODE(x)         UCA0CTL0=(UCA0CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UART0_UCMODE            (UCA0CTL0 & (~(0XFFF9)))>>1
#define put_UART0_UCSPB(x)          UCA0CTL0=(UCA0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART0_UCSPB             (UCA0CTL0 & (~(0XFFF7)))>>3
#define put_UART0_UCMST(x)          UCA0CTL0=(UCA0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART0_UCMST             (UCA0CTL0 & (~(0XFFF7)))>>3
#define put_UART0_UC7BIT(x)         UCA0CTL0=(UCA0CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART0_UC7BIT            (UCA0CTL0 & (~(0XFFEF)))>>4
#define put_UART0_UCMSB(x)          UCA0CTL0=(UCA0CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART0_UCMSB             (UCA0CTL0 & (~(0XFFDF)))>>5
#define put_UART0_UCPAR(x)          UCA0CTL0=(UCA0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART0_UCPAR             (UCA0CTL0 & (~(0XFFBF)))>>6
#define put_UART0_UCCKPL(x)         UCA0CTL0=(UCA0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART0_UCCKPL            (UCA0CTL0 & (~(0XFFBF)))>>6
#define put_UART0_UCPEN(x)          UCA0CTL0=(UCA0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART0_UCPEN             (UCA0CTL0 & (~(0XFF7F)))>>7
#define put_UART0_UCCKPH(x)         UCA0CTL0=(UCA0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART0_UCCKPH            (UCA0CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_UART0_UCSWRST(x)        UCA0CTL1=(UCA0CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCSWRST           (UCA0CTL1 & (~(0XFFFE)))>>0
#define put_UART0_UCTXBRK(x)        UCA0CTL1=(UCA0CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART0_UCTXBRK           (UCA0CTL1 & (~(0XFFFD)))>>1
#define put_UART0_UCTXADDR(x)       UCA0CTL1=(UCA0CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART0_UCTXADDR          (UCA0CTL1 & (~(0XFFFB)))>>2
#define put_UART0_UCDORM(x)         UCA0CTL1=(UCA0CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART0_UCDORM            (UCA0CTL1 & (~(0XFFF7)))>>3
#define put_UART0_UCBRKIE(x)        UCA0CTL1=(UCA0CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART0_UCBRKIE           (UCA0CTL1 & (~(0XFFEF)))>>4
#define put_UART0_UCRXEIE(x)        UCA0CTL1=(UCA0CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART0_UCRXEIE           (UCA0CTL1 & (~(0XFFDF)))>>5
#define put_UART0_UCSSEL(x)         UCA0CTL1=(UCA0CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UART0_UCSSEL            (UCA0CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_UART0_UC0BR(x)          UCA0BRW=(UCA0BRW & 0X0000) | (x & 0XFFFF)
#define get_UART0_UC0BR             (UCA0BRW & (~(0X0000)))
#define put_UART0_UC0BRW(x)         UCA0BRW=(UCA0BRW & 0X0000) | (x & 0XFFFF)
#define get_UART0_UC0BRW            (UCA0BRW & (~(0X0000)))
#define put_UART0_UC0BR0(x)         UCA0BR0=(UCA0BR0 & 0X0000) | (x & 0X00FF)
#define get_UART0_UC0BR0            (UCA0BR0 & (~(0X00FF)))
#define put_UART0_UC0BR1(x)         UCA0BR1=(UCA0BR1 & 0X0000) | (x & 0X00FF)
#define get_UART0_UC0BR1            (UCA0BR1 & (~(0X00FF)))
//--------------------------------------------------------------------------------------
#define put_UART0_UCOS16(x)         UCA0MCTL=(UCA0MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCOS16            (UCA0MCTL & (~(0XFFFE)))>>0
#define put_UART0_UCBRS(x)          UCA0MCTL=(UCA0MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UART0_UCBRS             (UCA0MCTL & (~(0XFFF1)))>>1
#define put_UART0_UCBRF(x)          UCA0MCTL=(UCA0MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UART0_UCBRF             (UCA0MCTL & (~(0XFF0F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART0_UCBUSY(x)         UCA0STAT=(UCA0STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCBUSY            (UCA0STAT & (~(0XFFFE)))>>0
#define put_UART0_UCIDLE(x)         UCA0STAT=(UCA0STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART0_UCIDLE            (UCA0STAT & (~(0XFFFD)))>>1
#define put_UART0_UCADDR(x)         UCA0STAT=(UCA0STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART0_UCADDR            (UCA0STAT & (~(0XFFFD)))>>1
#define put_UART0_UCRXERR(x)        UCA0STAT=(UCA0STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART0_UCRXERR           (UCA0STAT & (~(0XFFFB)))>>2
#define put_UART0_UCBRK(x)          UCA0STAT=(UCA0STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART0_UCBRK             (UCA0STAT & (~(0XFFF7)))>>3
#define put_UART0_UCPE(x)           UCA0STAT=(UCA0STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART0_UCPE              (UCA0STAT & (~(0XFFEF)))>>4
#define put_UART0_UCOE(x)           UCA0STAT=(UCA0STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART0_UCOE              (UCA0STAT & (~(0XFFDF)))>>5
#define put_UART0_UCFE(x)           UCA0STAT=(UCA0STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART0_UCFE              (UCA0STAT & (~(0XFFBF)))>>6
#define put_UART0_UCLISTEN(x)       UCA0STAT=(UCA0STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART0_UCLISTEN          (UCA0STAT & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define get_UART0_RXBUF             UCA0RXBUF
//--------------------------------------------------------------------------------------
#define put_UART0_TXBUF(x)          UCA0TXBUF=x
//--------------------------------------------------------------------------------------
#define put_UART0_UCIREN(x)         UCA0IRTCTL=(UCA0IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCIREN            (UCA0IRTCTL & (~(0XFFFE)))>>0
#define put_UART0_UCIRTXCLK(x)      UCA0IRTCTL=(UCA0IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART0_UCIRTXCLK         (UCA0IRTCTL & (~(0XFFFD)))>>1
#define put_UART0_UCIRTXPL(x)       UCA0IRTCTL=(UCA0IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART0_UCIRTXPL          (UCA0IRTCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART0_UCIRRXFE(x)       UCA0IRRCTL=(UCA0IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCIRRXFE          (UCA0IRRCTL & (~(0XFFFE)))>>0
#define put_UART0_UCIRRXPL(x)       UCA0IRRCTL=(UCA0IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART0_UCIRRXPL          (UCA0IRRCTL & (~(0XFFFD)))>>1
#define put_UART0_UCIRRXFL(x)       UCA0IRRCTL=(UCA0IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART0_UCIRRXFL          (UCA0IRRCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART0_UCABDEN(x)        UCA0ABCTL=(UCA0ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCABDEN           (UCA0ABCTL & (~(0XFFFE)))>>0
#define put_UART0_UCABEN(x)         UCA0ABCTL=(UCA0ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCABEN            (UCA0ABCTL & (~(0XFFFE)))>>0
#define put_UART0_UCBTOE(x)         UCA0ABCTL=(UCA0ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART0_UCBTOE            (UCA0ABCTL & (~(0XFFFB)))>>2
#define put_UART0_UCSTOE(x)         UCA0ABCTL=(UCA0ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART0_UCSTOE            (UCA0ABCTL & (~(0XFFF7)))>>3
#define put_UART0_UCDELIM(x)        UCA0ABCTL=(UCA0ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UART0_UCDELIM           (UCA0ABCTL & (~(0XFF3F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART0_UCRXIE(x)         UCA0IE=(UCA0IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCRXIE            (UCA0IE & (~(0XFFFE)))>>0
#define put_UART0_UCTXIE(x)         UCA0IE=(UCA0IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART0_UCTXIE            (UCA0IE & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
//#define put_UART0_UCRXIFG(x)      UCA0IFG=(UCA0IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART0_UCRXIFG           (UCA0IFG & (~(0XFFFE)))>>0
//#define put_UART0_UCTXIFG(x)      UCA0IFG=(UCA0IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART0_UCTXIFG           (UCA0IFG & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
#define get_UART0_IV                (UCA0IV & ((0X0006)))>>0
//UCI_A0 结束 ##########################################################################
//UCI_A1 开始 ##########################################################################
#define put_UART1_UCSYNC(x)         UCA1CTL0=(UCA1CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCSYNC            (UCA1CTL0 & (~(0XFFFE)))>>0
#define put_UART1_UCMODE(x)         UCA1CTL0=(UCA1CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UART1_UCMODE            (UCA1CTL0 & (~(0XFFF9)))>>1
#define put_UART1_UCSPB(x)          UCA1CTL0=(UCA1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART1_UCSPB             (UCA1CTL0 & (~(0XFFF7)))>>3
#define put_UART1_UCMST(x)          UCA1CTL0=(UCA1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART1_UCMST             (UCA1CTL0 & (~(0XFFF7)))>>3
#define put_UART1_UC7BIT(x)         UCA1CTL0=(UCA1CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART1_UC7BIT            (UCA1CTL0 & (~(0XFFEF)))>>4
#define put_UART1_UCMSB(x)          UCA1CTL0=(UCA1CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART1_UCMSB             (UCA1CTL0 & (~(0XFFDF)))>>5
#define put_UART1_UCPAR(x)          UCA1CTL0=(UCA1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART1_UCPAR             (UCA1CTL0 & (~(0XFFBF)))>>6
#define put_UART1_UCCKPL(x)         UCA1CTL0=(UCA1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART1_UCCKPL            (UCA1CTL0 & (~(0XFFBF)))>>6
#define put_UART1_UCPEN(x)          UCA1CTL0=(UCA1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART1_UCPEN             (UCA1CTL0 & (~(0XFF7F)))>>7
#define put_UART1_UCCKPH(x)         UCA1CTL0=(UCA1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART1_UCCKPH            (UCA1CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_UART1_UCSWRST(x)        UCA1CTL1=(UCA1CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCSWRST           (UCA1CTL1 & (~(0XFFFE)))>>0
#define put_UART1_UCTXBRK(x)        UCA1CTL1=(UCA1CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART1_UCTXBRK           (UCA1CTL1 & (~(0XFFFD)))>>1
#define put_UART1_UCTXADDR(x)       UCA1CTL1=(UCA1CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART1_UCTXADDR          (UCA1CTL1 & (~(0XFFFB)))>>2
#define put_UART1_UCDORM(x)         UCA1CTL1=(UCA1CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART1_UCDORM            (UCA1CTL1 & (~(0XFFF7)))>>3
#define put_UART1_UCBRKIE(x)        UCA1CTL1=(UCA1CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART1_UCBRKIE           (UCA1CTL1 & (~(0XFFEF)))>>4
#define put_UART1_UCRXEIE(x)        UCA1CTL1=(UCA1CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART1_UCRXEIE           (UCA1CTL1 & (~(0XFFDF)))>>5
#define put_UART1_UCSSEL(x)         UCA1CTL1=(UCA1CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UART1_UCSSEL            (UCA1CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_UART1_UC0BR(x)          UCA1BRW=(UCA1BRW & 0X0000) | (x & 0XFFFF)
#define get_UART1_UC0BR             (UCA1BRW & (~(0X0000)))
#define put_UART1_UC0BRW(x)         UCA1BRW=(UCA1BRW & 0X0000) | (x & 0XFFFF)
#define get_UART1_UC0BRW            (UCA1BRW & (~(0X0000)))
#define put_UART1_UC0BR0(x)         UCA1BR0=(UCA1BR0 & 0X0000) | (x & 0X00FF)
#define get_UART1_UC0BR0            (UCA1BR0 & (~(0X00FF)))
#define put_UART1_UC0BR1(x)         UCA1BR1=(UCA1BR1 & 0X0000) | (x & 0X00FF)
#define get_UART1_UC0BR1            (UCA1BR1 & (~(0X00FF)))
//--------------------------------------------------------------------------------------
#define put_UART1_UCOS16(x)         UCA1MCTL=(UCA1MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCOS16            (UCA1MCTL & (~(0XFFFE)))>>0
#define put_UART1_UCBRS(x)          UCA1MCTL=(UCA1MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UART1_UCBRS             (UCA1MCTL & (~(0XFFF1)))>>1
#define put_UART1_UCBRF(x)          UCA1MCTL=(UCA1MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UART1_UCBRF             (UCA1MCTL & (~(0XFF0F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART1_UCBUSY(x)         UCA1STAT=(UCA1STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCBUSY            (UCA1STAT & (~(0XFFFE)))>>0
#define put_UART1_UCIDLE(x)         UCA1STAT=(UCA1STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART1_UCIDLE            (UCA1STAT & (~(0XFFFD)))>>1
#define put_UART1_UCADDR(x)         UCA1STAT=(UCA1STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART1_UCADDR            (UCA1STAT & (~(0XFFFD)))>>1
#define put_UART1_UCRXERR(x)        UCA1STAT=(UCA1STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART1_UCRXERR           (UCA1STAT & (~(0XFFFB)))>>2
#define put_UART1_UCBRK(x)          UCA1STAT=(UCA1STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART1_UCBRK             (UCA1STAT & (~(0XFFF7)))>>3
#define put_UART1_UCPE(x)           UCA1STAT=(UCA1STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART1_UCPE              (UCA1STAT & (~(0XFFEF)))>>4
#define put_UART1_UCOE(x)           UCA1STAT=(UCA1STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART1_UCOE              (UCA1STAT & (~(0XFFDF)))>>5
#define put_UART1_UCFE(x)           UCA1STAT=(UCA1STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART1_UCFE              (UCA1STAT & (~(0XFFBF)))>>6
#define put_UART1_UCLISTEN(x)       UCA1STAT=(UCA1STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART1_UCLISTEN          (UCA1STAT & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define get_UART1_RXBUF             UCA1RXBUF
//--------------------------------------------------------------------------------------
#define put_UART1_TXBUF(x)          UCA1TXBUF=x
//--------------------------------------------------------------------------------------
#define put_UART1_UCIREN(x)         UCA1IRTCTL=(UCA1IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCIREN            (UCA1IRTCTL & (~(0XFFFE)))>>0
#define put_UART1_UCIRTXCLK(x)      UCA1IRTCTL=(UCA1IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART1_UCIRTXCLK         (UCA1IRTCTL & (~(0XFFFD)))>>1
#define put_UART1_UCIRTXPL(x)       UCA1IRTCTL=(UCA1IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART1_UCIRTXPL          (UCA1IRTCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART1_UCIRRXFE(x)       UCA1IRRCTL=(UCA1IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCIRRXFE          (UCA1IRRCTL & (~(0XFFFE)))>>0
#define put_UART1_UCIRRXPL(x)       UCA1IRRCTL=(UCA1IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART1_UCIRRXPL          (UCA1IRRCTL & (~(0XFFFD)))>>1
#define put_UART1_UCIRRXFL(x)       UCA1IRRCTL=(UCA1IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART1_UCIRRXFL          (UCA1IRRCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART1_UCABDEN(x)        UCA1ABCTL=(UCA1ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCABDEN           (UCA1ABCTL & (~(0XFFFE)))>>0
#define put_UART1_UCABEN(x)         UCA1ABCTL=(UCA1ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCABEN            (UCA1ABCTL & (~(0XFFFE)))>>0
#define put_UART1_UCBTOE(x)         UCA1ABCTL=(UCA1ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART1_UCBTOE            (UCA1ABCTL & (~(0XFFFB)))>>2
#define put_UART1_UCSTOE(x)         UCA1ABCTL=(UCA1ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART1_UCSTOE            (UCA1ABCTL & (~(0XFFF7)))>>3
#define put_UART1_UCDELIM(x)        UCA1ABCTL=(UCA1ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UART1_UCDELIM           (UCA1ABCTL & (~(0XFF3F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART1_UCRXIE(x)         UCA1IE=(UCA1IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCRXIE            (UCA1IE & (~(0XFFFE)))>>0
#define put_UART1_UCTXIE(x)         UCA1IE=(UCA1IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART1_UCTXIE            (UCA1IE & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
//#define put_UART1_UCRXIFG(x)      UCA1IFG=(UCA1IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART1_UCRXIFG           (UCA1IFG & (~(0XFFFE)))>>0
//#define put_UART1_UCTXIFG(x)      UCA1IFG=(UCA1IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART1_UCTXIFG           (UCA1IFG & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
#define get_UART1_IV                (UCA1IV & ((0X0006)))>>0
//UCI_A1 结束 ##########################################################################
//UCI_A2 开始 ##########################################################################
#define put_UART2_UCSYNC(x)         UCA2CTL0=(UCA2CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCSYNC            (UCA2CTL0 & (~(0XFFFE)))>>0
#define put_UART2_UCMODE(x)         UCA2CTL0=(UCA2CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UART2_UCMODE            (UCA2CTL0 & (~(0XFFF9)))>>1
#define put_UART2_UCSPB(x)          UCA2CTL0=(UCA2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART2_UCSPB             (UCA2CTL0 & (~(0XFFF7)))>>3
#define put_UART2_UCMST(x)          UCA2CTL0=(UCA2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART2_UCMST             (UCA2CTL0 & (~(0XFFF7)))>>3
#define put_UART2_UC7BIT(x)         UCA2CTL0=(UCA2CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART2_UC7BIT            (UCA2CTL0 & (~(0XFFEF)))>>4
#define put_UART2_UCMSB(x)          UCA2CTL0=(UCA2CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART2_UCMSB             (UCA2CTL0 & (~(0XFFDF)))>>5
#define put_UART2_UCPAR(x)          UCA2CTL0=(UCA2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART2_UCPAR             (UCA2CTL0 & (~(0XFFBF)))>>6
#define put_UART2_UCCKPL(x)         UCA2CTL0=(UCA2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART2_UCCKPL            (UCA2CTL0 & (~(0XFFBF)))>>6
#define put_UART2_UCPEN(x)          UCA2CTL0=(UCA2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART2_UCPEN             (UCA2CTL0 & (~(0XFF7F)))>>7
#define put_UART2_UCCKPH(x)         UCA2CTL0=(UCA2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART2_UCCKPH            (UCA2CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_UART2_UCSWRST(x)        UCA2CTL1=(UCA2CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCSWRST           (UCA2CTL1 & (~(0XFFFE)))>>0
#define put_UART2_UCTXBRK(x)        UCA2CTL1=(UCA2CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART2_UCTXBRK           (UCA2CTL1 & (~(0XFFFD)))>>1
#define put_UART2_UCTXADDR(x)       UCA2CTL1=(UCA2CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART2_UCTXADDR          (UCA2CTL1 & (~(0XFFFB)))>>2
#define put_UART2_UCDORM(x)         UCA2CTL1=(UCA2CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART2_UCDORM            (UCA2CTL1 & (~(0XFFF7)))>>3
#define put_UART2_UCBRKIE(x)        UCA2CTL1=(UCA2CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART2_UCBRKIE           (UCA2CTL1 & (~(0XFFEF)))>>4
#define put_UART2_UCRXEIE(x)        UCA2CTL1=(UCA2CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART2_UCRXEIE           (UCA2CTL1 & (~(0XFFDF)))>>5
#define put_UART2_UCSSEL(x)         UCA2CTL1=(UCA2CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UART2_UCSSEL            (UCA2CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_UART2_UC0BR(x)          UCA2BRW=(UCA2BRW & 0X0000) | (x & 0XFFFF)
#define get_UART2_UC0BR             (UCA2BRW & (~(0X0000)))
#define put_UART2_UC0BRW(x)         UCA2BRW=(UCA2BRW & 0X0000) | (x & 0XFFFF)
#define get_UART2_UC0BRW            (UCA2BRW & (~(0X0000)))
#define put_UART2_UC0BR0(x)         UCA2BR0=(UCA2BR0 & 0X0000) | (x & 0X00FF)
#define get_UART2_UC0BR0            (UCA2BR0 & (~(0X00FF)))
#define put_UART2_UC0BR1(x)         UCA2BR1=(UCA2BR1 & 0X0000) | (x & 0X00FF)
#define get_UART2_UC0BR1            (UCA2BR1 & (~(0X00FF)))
//--------------------------------------------------------------------------------------
#define put_UART2_UCOS16(x)         UCA2MCTL=(UCA2MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCOS16            (UCA2MCTL & (~(0XFFFE)))>>0
#define put_UART2_UCBRS(x)          UCA2MCTL=(UCA2MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UART2_UCBRS             (UCA2MCTL & (~(0XFFF1)))>>1
#define put_UART2_UCBRF(x)          UCA2MCTL=(UCA2MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UART2_UCBRF             (UCA2MCTL & (~(0XFF0F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART2_UCBUSY(x)         UCA2STAT=(UCA2STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCBUSY            (UCA2STAT & (~(0XFFFE)))>>0
#define put_UART2_UCIDLE(x)         UCA2STAT=(UCA2STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART2_UCIDLE            (UCA2STAT & (~(0XFFFD)))>>1
#define put_UART2_UCADDR(x)         UCA2STAT=(UCA2STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART2_UCADDR            (UCA2STAT & (~(0XFFFD)))>>1
#define put_UART2_UCRXERR(x)        UCA2STAT=(UCA2STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART2_UCRXERR           (UCA2STAT & (~(0XFFFB)))>>2
#define put_UART2_UCBRK(x)          UCA2STAT=(UCA2STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART2_UCBRK             (UCA2STAT & (~(0XFFF7)))>>3
#define put_UART2_UCPE(x)           UCA2STAT=(UCA2STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART2_UCPE              (UCA2STAT & (~(0XFFEF)))>>4
#define put_UART2_UCOE(x)           UCA2STAT=(UCA2STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART2_UCOE              (UCA2STAT & (~(0XFFDF)))>>5
#define put_UART2_UCFE(x)           UCA2STAT=(UCA2STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART2_UCFE              (UCA2STAT & (~(0XFFBF)))>>6
#define put_UART2_UCLISTEN(x)       UCA2STAT=(UCA2STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART2_UCLISTEN          (UCA2STAT & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define get_UART2_RXBUF             UCA2RXBUF
//--------------------------------------------------------------------------------------
#define put_UART2_TXBUF(x)          UCA2TXBUF=x
//--------------------------------------------------------------------------------------
#define put_UART2_UCIREN(x)         UCA2IRTCTL=(UCA2IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCIREN            (UCA2IRTCTL & (~(0XFFFE)))>>0
#define put_UART2_UCIRTXCLK(x)      UCA2IRTCTL=(UCA2IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART2_UCIRTXCLK         (UCA2IRTCTL & (~(0XFFFD)))>>1
#define put_UART2_UCIRTXPL(x)       UCA2IRTCTL=(UCA2IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART2_UCIRTXPL          (UCA2IRTCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART2_UCIRRXFE(x)       UCA2IRRCTL=(UCA2IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCIRRXFE          (UCA2IRRCTL & (~(0XFFFE)))>>0
#define put_UART2_UCIRRXPL(x)       UCA2IRRCTL=(UCA2IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART2_UCIRRXPL          (UCA2IRRCTL & (~(0XFFFD)))>>1
#define put_UART2_UCIRRXFL(x)       UCA2IRRCTL=(UCA2IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART2_UCIRRXFL          (UCA2IRRCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART2_UCABDEN(x)        UCA2ABCTL=(UCA2ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCABDEN           (UCA2ABCTL & (~(0XFFFE)))>>0
#define put_UART2_UCABEN(x)         UCA2ABCTL=(UCA2ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCABEN            (UCA2ABCTL & (~(0XFFFE)))>>0
#define put_UART2_UCBTOE(x)         UCA2ABCTL=(UCA2ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART2_UCBTOE            (UCA2ABCTL & (~(0XFFFB)))>>2
#define put_UART2_UCSTOE(x)         UCA2ABCTL=(UCA2ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART2_UCSTOE            (UCA2ABCTL & (~(0XFFF7)))>>3
#define put_UART2_UCDELIM(x)        UCA2ABCTL=(UCA2ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UART2_UCDELIM           (UCA2ABCTL & (~(0XFF3F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART2_UCRXIE(x)         UCA2IE=(UCA2IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCRXIE            (UCA2IE & (~(0XFFFE)))>>0
#define put_UART2_UCTXIE(x)         UCA2IE=(UCA2IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART2_UCTXIE            (UCA2IE & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
//#define put_UART2_UCRXIFG(x)      UCA2IFG=(UCA2IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART2_UCRXIFG           (UCA2IFG & (~(0XFFFE)))>>0
//#define put_UART2_UCTXIFG(x)      UCA2IFG=(UCA2IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART2_UCTXIFG           (UCA2IFG & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
#define get_UART2_IV                (UCA2IV & ((0X0006)))>>0
//UCI_A2 结束 ##########################################################################
//UCI_A3 开始 ##########################################################################
#define put_UART3_UCSYNC(x)         UCA3CTL0=(UCA3CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCSYNC            (UCA3CTL0 & (~(0XFFFE)))>>0
#define put_UART3_UCMODE(x)         UCA3CTL0=(UCA3CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UART3_UCMODE            (UCA3CTL0 & (~(0XFFF9)))>>1
#define put_UART3_UCSPB(x)          UCA3CTL0=(UCA3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART3_UCSPB             (UCA3CTL0 & (~(0XFFF7)))>>3
#define put_UART3_UCMST(x)          UCA3CTL0=(UCA3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART3_UCMST             (UCA3CTL0 & (~(0XFFF7)))>>3
#define put_UART3_UC7BIT(x)         UCA3CTL0=(UCA3CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART3_UC7BIT            (UCA3CTL0 & (~(0XFFEF)))>>4
#define put_UART3_UCMSB(x)          UCA3CTL0=(UCA3CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART3_UCMSB             (UCA3CTL0 & (~(0XFFDF)))>>5
#define put_UART3_UCPAR(x)          UCA3CTL0=(UCA3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART3_UCPAR             (UCA3CTL0 & (~(0XFFBF)))>>6
#define put_UART3_UCCKPL(x)         UCA3CTL0=(UCA3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART3_UCCKPL            (UCA3CTL0 & (~(0XFFBF)))>>6
#define put_UART3_UCPEN(x)          UCA3CTL0=(UCA3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART3_UCPEN             (UCA3CTL0 & (~(0XFF7F)))>>7
#define put_UART3_UCCKPH(x)         UCA3CTL0=(UCA3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART3_UCCKPH            (UCA3CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_UART3_UCSWRST(x)        UCA3CTL1=(UCA3CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCSWRST           (UCA3CTL1 & (~(0XFFFE)))>>0
#define put_UART3_UCTXBRK(x)        UCA3CTL1=(UCA3CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART3_UCTXBRK           (UCA3CTL1 & (~(0XFFFD)))>>1
#define put_UART3_UCTXADDR(x)       UCA3CTL1=(UCA3CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART3_UCTXADDR          (UCA3CTL1 & (~(0XFFFB)))>>2
#define put_UART3_UCDORM(x)         UCA3CTL1=(UCA3CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART3_UCDORM            (UCA3CTL1 & (~(0XFFF7)))>>3
#define put_UART3_UCBRKIE(x)        UCA3CTL1=(UCA3CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART3_UCBRKIE           (UCA3CTL1 & (~(0XFFEF)))>>4
#define put_UART3_UCRXEIE(x)        UCA3CTL1=(UCA3CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART3_UCRXEIE           (UCA3CTL1 & (~(0XFFDF)))>>5
#define put_UART3_UCSSEL(x)         UCA3CTL1=(UCA3CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UART3_UCSSEL            (UCA3CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_UART3_UC0BR(x)          UCA3BRW=(UCA3BRW & 0X0000) | (x & 0XFFFF)
#define get_UART3_UC0BR             (UCA3BRW & (~(0X0000)))
#define put_UART3_UC0BRW(x)         UCA3BRW=(UCA3BRW & 0X0000) | (x & 0XFFFF)
#define get_UART3_UC0BRW            (UCA3BRW & (~(0X0000)))
#define put_UART3_UC0BR0(x)         UCA3BR0=(UCA3BR0 & 0X0000) | (x & 0X00FF)
#define get_UART3_UC0BR0            (UCA3BR0 & (~(0X00FF)))
#define put_UART3_UC0BR1(x)         UCA3BR1=(UCA3BR1 & 0X0000) | (x & 0X00FF)
#define get_UART3_UC0BR1            (UCA3BR1 & (~(0X00FF)))
//--------------------------------------------------------------------------------------
#define put_UART3_UCOS16(x)         UCA3MCTL=(UCA3MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCOS16            (UCA3MCTL & (~(0XFFFE)))>>0
#define put_UART3_UCBRS(x)          UCA3MCTL=(UCA3MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UART3_UCBRS             (UCA3MCTL & (~(0XFFF1)))>>1
#define put_UART3_UCBRF(x)          UCA3MCTL=(UCA3MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UART3_UCBRF             (UCA3MCTL & (~(0XFF0F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART3_UCBUSY(x)         UCA3STAT=(UCA3STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCBUSY            (UCA3STAT & (~(0XFFFE)))>>0
#define put_UART3_UCIDLE(x)         UCA3STAT=(UCA3STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART3_UCIDLE            (UCA3STAT & (~(0XFFFD)))>>1
#define put_UART3_UCADDR(x)         UCA3STAT=(UCA3STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART3_UCADDR            (UCA3STAT & (~(0XFFFD)))>>1
#define put_UART3_UCRXERR(x)        UCA3STAT=(UCA3STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART3_UCRXERR           (UCA3STAT & (~(0XFFFB)))>>2
#define put_UART3_UCBRK(x)          UCA3STAT=(UCA3STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART3_UCBRK             (UCA3STAT & (~(0XFFF7)))>>3
#define put_UART3_UCPE(x)           UCA3STAT=(UCA3STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UART3_UCPE              (UCA3STAT & (~(0XFFEF)))>>4
#define put_UART3_UCOE(x)           UCA3STAT=(UCA3STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UART3_UCOE              (UCA3STAT & (~(0XFFDF)))>>5
#define put_UART3_UCFE(x)           UCA3STAT=(UCA3STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UART3_UCFE              (UCA3STAT & (~(0XFFBF)))>>6
#define put_UART3_UCLISTEN(x)       UCA3STAT=(UCA3STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UART3_UCLISTEN          (UCA3STAT & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define get_UART3_RXBUF             UCA3RXBUF
//--------------------------------------------------------------------------------------
#define put_UART3_TXBUF(x)          UCA3TXBUF=x
//--------------------------------------------------------------------------------------
#define put_UART3_UCIREN(x)         UCA3IRTCTL=(UCA3IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCIREN            (UCA3IRTCTL & (~(0XFFFE)))>>0
#define put_UART3_UCIRTXCLK(x)      UCA3IRTCTL=(UCA3IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART3_UCIRTXCLK         (UCA3IRTCTL & (~(0XFFFD)))>>1
#define put_UART3_UCIRTXPL(x)       UCA3IRTCTL=(UCA3IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART3_UCIRTXPL          (UCA3IRTCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART3_UCIRRXFE(x)       UCA3IRRCTL=(UCA3IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCIRRXFE          (UCA3IRRCTL & (~(0XFFFE)))>>0
#define put_UART3_UCIRRXPL(x)       UCA3IRRCTL=(UCA3IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART3_UCIRRXPL          (UCA3IRRCTL & (~(0XFFFD)))>>1
#define put_UART3_UCIRRXFL(x)       UCA3IRRCTL=(UCA3IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UART3_UCIRRXFL          (UCA3IRRCTL & (~(0XFFFC)))>>2
//--------------------------------------------------------------------------------------
#define put_UART3_UCABDEN(x)        UCA3ABCTL=(UCA3ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCABDEN           (UCA3ABCTL & (~(0XFFFE)))>>0
#define put_UART3_UCABEN(x)        UCA3ABCTL=(UCA3ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCABEN           (UCA3ABCTL & (~(0XFFFE)))>>0
#define put_UART3_UCBTOE(x)         UCA3ABCTL=(UCA3ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UART3_UCBTOE            (UCA3ABCTL & (~(0XFFFB)))>>2
#define put_UART3_UCSTOE(x)         UCA3ABCTL=(UCA3ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UART3_UCSTOE            (UCA3ABCTL & (~(0XFFF7)))>>3
#define put_UART3_UCDELIM(x)        UCA3ABCTL=(UCA3ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UART3_UCDELIM           (UCA3ABCTL & (~(0XFF3F)))>>4
//--------------------------------------------------------------------------------------
#define put_UART3_UCRXIE(x)         UCA3IE=(UCA3IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCRXIE            (UCA3IE & (~(0XFFFE)))>>0
#define put_UART3_UCTXIE(x)         UCA3IE=(UCA3IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART3_UCTXIE            (UCA3IE & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
//#define put_UART3_UCRXIFG(x)      UCA3IFG=(UCA3IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UART3_UCRXIFG           (UCA3IFG & (~(0XFFFE)))>>0
//#define put_UART3_UCTXIFG(x)      UCA3IFG=(UCA3IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UART3_UCTXIFG           (UCA3IFG & (~(0XFFFD)))>>1
//--------------------------------------------------------------------------------------
#define get_UART3_IV                (UCA3IV & ((0X0006)))>>0
//UCI_A3 结束 ##########################################################################
//MSP430单片机的UART串行通讯口结束 #####################################################
//************************以下之内容适合于对照原理图设计IIC应用程序*********************
//以下是串行接口IIC的起始环境和停止环境之快捷操作---------------------------------------
#define IIC0_START                 UCB0CTL1=(UCB0CTL1 & 0XFFFD) | 0X0002 ) 
#define IIC1_START                 UCB1CTL1=(UCB1CTL1 & 0XFFFD) | 0X0002 )
#define IIC2_START                 UCB2CTL1=(UCB2CTL1 & 0XFFFD) | 0X0002 )
#define IIC3_START                 UCB3CTL1=(UCB3CTL1 & 0XFFFD) | 0X0002 )

#define IIC0_STOP                  UCB0CTL1=(UCB0CTL1 & 0XFFFB) | 0X0004 ) 
#define IIC1_STOP                  UCB1CTL1=(UCB1CTL1 & 0XFFFB) | 0X0004 )
#define IIC2_STOP                  UCB2CTL1=(UCB2CTL1 & 0XFFFB) | 0X0004 )
#define IIC3_STOP                  UCB3CTL1=(UCB3CTL1 & 0XFFFB) | 0X0004 )
//以上是串行接口IIC的起始环境和停止环境之快捷操作---------------------------------------
//MSP430单片机的IIC串行通讯口开始 ######################################################
//UCI_B0 开始 ##########################################################################
#define put_IIC0_UCSYNC(x)      UCB0CTL0=(UCB0CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC0_UCSYNC         (UCB0CTL0 & (~(0XFFFE)))>>0
#define put_IIC0_UCMODE(x)      UCB0CTL0=(UCB0CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_IIC0_UCMODE         (UCB0CTL0 & (~(0XFFF9)))>>1
#define put_IIC0_UCMST(x)       UCB0CTL0=(UCB0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC0_UCMST          (UCB0CTL0 & (~(0XFFF7)))>>3
#define put_IIC0_UCMM(x)        UCB0CTL0=(UCB0CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC0_UCMM           (UCB0CTL0 & (~(0XFFDF)))>>5
#define put_IIC0_UCSLA10(x)     UCB0CTL0=(UCB0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC0_UCSLA10        (UCB0CTL0 & (~(0XFFBF)))>>6
#define put_IIC0_UCA10(x)       UCB0CTL0=(UCB0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_IIC0_UCA10          (UCB0CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_IIC0_UCSWRST(x)     UCB0CTL1=(UCB0CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC0_UCSWRST        (UCB0CTL1 & (~(0XFFFE)))>>0
#define put_IIC0_UCTXSTT(x)     UCB0CTL1=(UCB0CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC0_UCTXSTT        (UCB0CTL1 & (~(0XFFFD)))>>1
#define put_IIC0_UCTXSTP(x)     UCB0CTL1=(UCB0CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC0_UCTXSTP        (UCB0CTL1 & (~(0XFFFB)))>>2
#define put_IIC0_UCTXNACK(x)    UCB0CTL1=(UCB0CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC0_UCTXNACK       (UCB0CTL1 & (~(0XFFF7)))>>3
#define put_IIC0_UCTR(x)        UCB0CTL1=(UCB0CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC0_UCTR           (UCB0CTL1 & (~(0XFFEF)))>>4
#define put_IIC0_UCSSEL(x)      UCB0CTL1=(UCB0CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_IIC0_UCSSEL         (UCB0CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_IIC0_BRW(x)         UCB0BRW=(UCB0BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC0_BRW            (UCB0BRW & (~(0X0000)))
#define put_IIC0_UC0BRW(x)      UCB0BRW=(UCB0BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC0_UC0BRW         (UCB0BRW & (~(0X0000)))
#define put_IIC0_UC0BR(x)       UCB0BRW=(UCB0BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC0_UC0BR          (UCB0BRW & (~(0X0000)))
//--------------------------------------------------------------------------------------
#define put_IIC0_UCBBUSY        UCB0STAT=(UCB0STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC0_UCBBUSY        (UCB0STAT & (~(0XFFEF)))>>4
#define put_IIC0_UCGC(x)        UCB0STAT=(UCB0STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC0_UCGC           (UCB0STAT & (~(0XFFDF)))>>5
#define put_IIC0_UCSCLLOW(x)    UCB0STAT=(UCB0STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC0_UCSCLLOW       (UCB0STAT & (~(0XFFBF)))>>6
//--------------------------------------------------------------------------------------
#define get_IIC0_RXBUF          UCB0RXBUF
//--------------------------------------------------------------------------------------
#define put_IIC0_TXBUF(x)       UCB0TXBUF=x
#define get_IIC0_TXBUF          UCB0TXBUF
//--------------------------------------------------------------------------------------
#define put_IIC0_I2COA(x)       UCB0I2COA=(UCB0I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC0_I2COA          (UCB0I2COA & (~(0XFC00)))>>0
#define put_IIC0_UCGCEN(x)      UCB0I2COA=(UCB0I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_IIC0_UCGCEN         (UCB0I2COA & (~(0X7FFF)))>>15
//--------------------------------------------------------------------------------------
#define put_IIC0_I2CSA(x)       UCB0I2CSA=(UCB0I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC0_I2CSA          (UCB0I2CSA & (~(0XFC00)))>>0
//--------------------------------------------------------------------------------------
#define put_IIC0_UCRXIE(x)      UCB0IE=(UCB0IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC0_UCRXIE         (UCB0IE & (~(0XFFFE)))>>0
#define put_IIC0_UCTXIE(x)      UCB0IE=(UCB0IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC0_UCTXIE         (UCB0IE & (~(0XFFFD)))>>1
#define put_IIC0_UCSTTIE(x)     UCB0IE=(UCB0IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC0_UCSTTIE        (UCB0IE & (~(0XFFFB)))>>2
#define put_IIC0_UCSTPIE(x)     UCB0IE=(UCB0IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC0_UCSTPIE        (UCB0IE & (~(0XFFF7)))>>3
#define put_IIC0_UCALIE(x)      UCB0IE=(UCB0IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC0_UCALIE         (UCB0IE & (~(0XFFEF)))>>4
#define put_IIC0_UCNACKIE(x)    UCB0IE=(UCB0IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_IIC0_UCNACKIE       (UCB0IE & (~(0XFFEF)))>>5
//--------------------------------------------------------------------------------------
#define get_IIC0_UCRXIFG        (UCB0IFG & (~(0XFFFE)))>>0
#define get_IIC0_UCTXIFG        (UCB0IFG & (~(0XFFFD)))>>1
#define get_IIC0_UCSTTIFG       (UCB0IFG & (~(0XFFFB)))>>2
#define get_IIC0_UCSTPIFG       (UCB0IFG & (~(0XFFF7)))>>3
#define get_IIC0_UCALIFG        (UCB0IFG & (~(0XFFEF)))>>4
#define get_IIC0_UCNACKIFG      (UCB0IFG & (~(0XFFDF)))>>5
#define get_IIC0_IFG            (UCB0IFG & (~(0XFFC0)))
//--------------------------------------------------------------------------------------
#define get_IIC0_IV             (UCB0IV & ((0X000E)))>>0
//UCI_B0 结束 ##########################################################################
//UCI_B1 开始 ##########################################################################
#define put_IIC1_UCSYNC(x)      UCB1CTL0=(UCB1CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC1_UCSYNC         (UCB1CTL0 & (~(0XFFFE)))>>0
#define put_IIC1_UCMODE(x)      UCB1CTL0=(UCB1CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_IIC1_UCMODE         (UCB1CTL0 & (~(0XFFF9)))>>1
#define put_IIC1_UCMST(x)       UCB1CTL0=(UCB1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC1_UCMST          (UCB1CTL0 & (~(0XFFF7)))>>3
#define put_IIC1_UCMM(x)        UCB1CTL0=(UCB1CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC1_UCMM           (UCB1CTL0 & (~(0XFFDF)))>>5
#define put_IIC1_UCSLA10(x)     UCB1CTL0=(UCB1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC1_UCSLA10        (UCB1CTL0 & (~(0XFFBF)))>>6
#define put_IIC1_UCA10(x)       UCB1CTL0=(UCB1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_IIC1_UCA10          (UCB1CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_IIC1_UCSWRST(x)     UCB1CTL1=(UCB1CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC1_UCSWRST        (UCB1CTL1 & (~(0XFFFE)))>>0
#define put_IIC1_UCTXSTT(x)     UCB1CTL1=(UCB1CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC1_UCTXSTT        (UCB1CTL1 & (~(0XFFFD)))>>1
#define put_IIC1_UCTXSTP(x)     UCB1CTL1=(UCB1CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC1_UCTXSTP        (UCB1CTL1 & (~(0XFFFB)))>>2
#define put_IIC1_UCTXNACK(x)    UCB1CTL1=(UCB1CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC1_UCTXNACK       (UCB1CTL1 & (~(0XFFF7)))>>3
#define put_IIC1_UCTR(x)        UCB1CTL1=(UCB1CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC1_UCTR           (UCB1CTL1 & (~(0XFFEF)))>>4
#define put_IIC1_UCSSEL(x)      UCB1CTL1=(UCB1CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_IIC1_UCSSEL         (UCB1CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_IIC1_BRW(x)         UCB1BRW=(UCB1BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC1_BRW            (UCB1BRW & (~(0X0000)))
#define put_IIC1_UC1BRW(x)      UCB1BRW=(UCB1BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC1_UC1BRW         (UCB1BRW & (~(0X0000)))
#define put_IIC1_UC1BR(x)       UCB1BRW=(UCB1BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC1_UC1BR          (UCB1BRW & (~(0X0000)))
//--------------------------------------------------------------------------------------
#define put_IIC1_UCBBUSY        UCB1STAT=(UCB1STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC1_UCBBUSY        (UCB1STAT & (~(0XFFEF)))>>4
#define put_IIC1_UCGC(x)        UCB1STAT=(UCB1STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC1_UCGC           (UCB1STAT & (~(0XFFDF)))>>5
#define put_IIC1_UCSCLLOW(x)    UCB1STAT=(UCB1STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC1_UCSCLLOW       (UCB1STAT & (~(0XFFBF)))>>6
//--------------------------------------------------------------------------------------
#define get_IIC1_RXBUF          UCB1RXBUF
//--------------------------------------------------------------------------------------
#define put_IIC1_TXBUF(x)       UCB1TXBUF=x
#define get_IIC1_TXBUF          UCB1TXBUF
//--------------------------------------------------------------------------------------
#define put_IIC1_I2COA(x)       UCB1I2COA=(UCB1I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC1_I2COA          (UCB1I2COA & (~(0XFC00)))>>0
#define put_IIC1_UCGCEN(x)      UCB1I2COA=(UCB1I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_IIC1_UCGCEN         (UCB1I2COA & (~(0X7FFF)))>>15
//--------------------------------------------------------------------------------------
#define put_IIC1_I2CSA(x)       UCB1I2CSA=(UCB1I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC1_I2CSA          (UCB1I2CSA & (~(0XFC00)))>>0
//--------------------------------------------------------------------------------------
#define put_IIC1_UCRXIE(x)      UCB1IE=(UCB1IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC1_UCRXIE         (UCB1IE & (~(0XFFFE)))>>0
#define put_IIC1_UCTXIE(x)      UCB1IE=(UCB1IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC1_UCTXIE         (UCB1IE & (~(0XFFFD)))>>1
#define put_IIC1_UCSTTIE(x)     UCB1IE=(UCB1IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC1_UCSTTIE        (UCB1IE & (~(0XFFFB)))>>2
#define put_IIC1_UCSTPIE(x)     UCB1IE=(UCB1IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC1_UCSTPIE        (UCB1IE & (~(0XFFF7)))>>3
#define put_IIC1_UCALIE(x)      UCB1IE=(UCB1IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC1_UCALIE         (UCB1IE & (~(0XFFEF)))>>4
#define put_IIC1_UCNACKIE(x)    UCB1IE=(UCB1IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_IIC1_UCNACKIE       (UCB1IE & (~(0XFFEF)))>>5
//--------------------------------------------------------------------------------------
#define get_IIC1_UCRXIFG        (UCB1IFG & (~(0XFFFE)))>>0
#define get_IIC1_UCTXIFG        (UCB1IFG & (~(0XFFFD)))>>1
#define get_IIC1_UCSTTIFG       (UCB1IFG & (~(0XFFFB)))>>2
#define get_IIC1_UCSTPIFG       (UCB1IFG & (~(0XFFF7)))>>3
#define get_IIC1_UCALIFG        (UCB1IFG & (~(0XFFEF)))>>4
#define get_IIC1_UCNACKIFG      (UCB1IFG & (~(0XFFDF)))>>5
#define get_IIC1_IFG            (UCB1IFG & (~(0XFFC0)))
//--------------------------------------------------------------------------------------
#define get_IIC1_IV             (UCB1IV & ((0X000E)))>>0
//UCI_B1 结束 ##########################################################################
//UCI_B2 开始 ##########################################################################
#define put_IIC2_UCSYNC(x)      UCB2CTL0=(UCB2CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC2_UCSYNC         (UCB2CTL0 & (~(0XFFFE)))>>0
#define put_IIC2_UCMODE(x)      UCB2CTL0=(UCB2CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_IIC2_UCMODE         (UCB2CTL0 & (~(0XFFF9)))>>1
#define put_IIC2_UCMST(x)       UCB2CTL0=(UCB2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC2_UCMST          (UCB2CTL0 & (~(0XFFF7)))>>3
#define put_IIC2_UCMM(x)        UCB2CTL0=(UCB2CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC2_UCMM           (UCB2CTL0 & (~(0XFFDF)))>>5
#define put_IIC2_UCSLA10(x)     UCB2CTL0=(UCB2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC2_UCSLA10        (UCB2CTL0 & (~(0XFFBF)))>>6
#define put_IIC2_UCA10(x)       UCB2CTL0=(UCB2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_IIC2_UCA10          (UCB2CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_IIC2_UCSWRST(x)     UCB2CTL1=(UCB2CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC2_UCSWRST        (UCB2CTL1 & (~(0XFFFE)))>>0
#define put_IIC2_UCTXSTT(x)     UCB2CTL1=(UCB2CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC2_UCTXSTT        (UCB2CTL1 & (~(0XFFFD)))>>1
#define put_IIC2_UCTXSTP(x)     UCB2CTL1=(UCB2CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC2_UCTXSTP        (UCB2CTL1 & (~(0XFFFB)))>>2
#define put_IIC2_UCTXNACK(x)    UCB2CTL1=(UCB2CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC2_UCTXNACK       (UCB2CTL1 & (~(0XFFF7)))>>3
#define put_IIC2_UCTR(x)        UCB2CTL1=(UCB2CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC2_UCTR           (UCB2CTL1 & (~(0XFFEF)))>>4
#define put_IIC2_UCSSEL(x)      UCB2CTL1=(UCB2CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_IIC2_UCSSEL         (UCB2CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_IIC2_BRW(x)         UCB2BRW=(UCB2BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC2_BRW            (UCB2BRW & (~(0X0000)))
#define put_IIC2_UC2BRW(x)      UCB2BRW=(UCB2BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC2_UC2BRW         (UCB2BRW & (~(0X0000)))
#define put_IIC2_UC2BR(x)       UCB2BRW=(UCB2BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC2_UC2BR          (UCB2BRW & (~(0X0000)))
//--------------------------------------------------------------------------------------
#define put_IIC2_UCBBUSY        UCB2STAT=(UCB2STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC2_UCBBUSY        (UCB2STAT & (~(0XFFEF)))>>4
#define put_IIC2_UCGC(x)        UCB2STAT=(UCB2STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC2_UCGC           (UCB2STAT & (~(0XFFDF)))>>5
#define put_IIC2_UCSCLLOW(x)    UCB2STAT=(UCB2STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC2_UCSCLLOW       (UCB2STAT & (~(0XFFBF)))>>6
//--------------------------------------------------------------------------------------
#define get_IIC2_RXBUF          UCB2RXBUF
//--------------------------------------------------------------------------------------
#define put_IIC2_TXBUF(x)       UCB2TXBUF=x
#define get_IIC2_TXBUF          UCB2TXBUF
//--------------------------------------------------------------------------------------
#define put_IIC2_I2COA(x)       UCB2I2COA=(UCB2I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC2_I2COA          (UCB2I2COA & (~(0XFC00)))>>0
#define put_IIC2_UCGCEN(x)      UCB2I2COA=(UCB2I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_IIC2_UCGCEN         (UCB2I2COA & (~(0X7FFF)))>>15
//--------------------------------------------------------------------------------------
#define put_IIC2_I2CSA(x)       UCB2I2CSA=(UCB2I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC2_I2CSA          (UCB2I2CSA & (~(0XFC00)))>>0
//--------------------------------------------------------------------------------------
#define put_IIC2_UCRXIE(x)      UCB2IE=(UCB2IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC2_UCRXIE         (UCB2IE & (~(0XFFFE)))>>0
#define put_IIC2_UCTXIE(x)      UCB2IE=(UCB2IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC2_UCTXIE         (UCB2IE & (~(0XFFFD)))>>1
#define put_IIC2_UCSTTIE(x)     UCB2IE=(UCB2IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC2_UCSTTIE        (UCB2IE & (~(0XFFFB)))>>2
#define put_IIC2_UCSTPIE(x)     UCB2IE=(UCB2IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC2_UCSTPIE        (UCB2IE & (~(0XFFF7)))>>3
#define put_IIC2_UCALIE(x)      UCB2IE=(UCB2IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC2_UCALIE         (UCB2IE & (~(0XFFEF)))>>4
#define put_IIC2_UCNACKIE(x)    UCB2IE=(UCB2IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_IIC2_UCNACKIE       (UCB2IE & (~(0XFFEF)))>>5
//--------------------------------------------------------------------------------------
#define get_IIC2_UCRXIFG        (UCB2IFG & (~(0XFFFE)))>>0
#define get_IIC2_UCTXIFG        (UCB2IFG & (~(0XFFFD)))>>1
#define get_IIC2_UCSTTIFG       (UCB2IFG & (~(0XFFFB)))>>2
#define get_IIC2_UCSTPIFG       (UCB2IFG & (~(0XFFF7)))>>3
#define get_IIC2_UCALIFG        (UCB2IFG & (~(0XFFEF)))>>4
#define get_IIC2_UCNACKIFG      (UCB2IFG & (~(0XFFDF)))>>5
#define get_IIC2_IFG            (UCB2IFG & (~(0XFFC0)))
//--------------------------------------------------------------------------------------
#define get_IIC2_IV             (UCB2IV & ((0X000E)))>>0
//UCI_B2 结束 ##########################################################################
//UCI_B3 开始 ##########################################################################
#define put_IIC3_UCSYNC(x)      UCB3CTL0=(UCB3CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC3_UCSYNC         (UCB3CTL0 & (~(0XFFFE)))>>0
#define put_IIC3_UCMODE(x)      UCB3CTL0=(UCB3CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_IIC3_UCMODE         (UCB3CTL0 & (~(0XFFF9)))>>1
#define put_IIC3_UCMST(x)       UCB3CTL0=(UCB3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC3_UCMST          (UCB3CTL0 & (~(0XFFF7)))>>3
#define put_IIC3_UCMM(x)        UCB3CTL0=(UCB3CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC3_UCMM           (UCB3CTL0 & (~(0XFFDF)))>>5
#define put_IIC3_UCSLA10(x)     UCB3CTL0=(UCB3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC3_UCSLA10        (UCB3CTL0 & (~(0XFFBF)))>>6
#define put_IIC3_UCA10(x)       UCB3CTL0=(UCB3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_IIC3_UCA10          (UCB3CTL0 & (~(0XFF7F)))>>7
//--------------------------------------------------------------------------------------
#define put_IIC3_UCSWRST(x)     UCB3CTL1=(UCB3CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC3_UCSWRST        (UCB3CTL1 & (~(0XFFFE)))>>0
#define put_IIC3_UCTXSTT(x)     UCB3CTL1=(UCB3CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC3_UCTXSTT        (UCB3CTL1 & (~(0XFFFD)))>>1
#define put_IIC3_UCTXSTP(x)     UCB3CTL1=(UCB3CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC3_UCTXSTP        (UCB3CTL1 & (~(0XFFFB)))>>2
#define put_IIC3_UCTXNACK(x)    UCB3CTL1=(UCB3CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC3_UCTXNACK       (UCB3CTL1 & (~(0XFFF7)))>>3
#define put_IIC3_UCTR(x)        UCB3CTL1=(UCB3CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC3_UCTR           (UCB3CTL1 & (~(0XFFEF)))>>4
#define put_IIC3_UCSSEL(x)      UCB3CTL1=(UCB3CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_IIC3_UCSSEL         (UCB3CTL1 & (~(0XFF3F)))>>6
//--------------------------------------------------------------------------------------
#define put_IIC3_BRW(x)         UCB3BRW=(UCB3BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC3_BRW            (UCB3BRW & (~(0X0000)))
#define put_IIC3_UC3BRW(x)      UCB3BRW=(UCB3BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC3_UC3BRW         (UCB3BRW & (~(0X0000)))
#define put_IIC3_UC3BR(x)       UCB3BRW=(UCB3BRW & 0X0000) | (x & 0XFFFF)
#define get_IIC3_UC3BR          (UCB3BRW & (~(0X0000)))
//--------------------------------------------------------------------------------------
#define put_IIC3_UCBBUSY        UCB3STAT=(UCB3STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC3_UCBBUSY        (UCB3STAT & (~(0XFFEF)))>>4
#define put_IIC3_UCGC(x)        UCB3STAT=(UCB3STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_IIC3_UCGC           (UCB3STAT & (~(0XFFDF)))>>5
#define put_IIC3_UCSCLLOW(x)    UCB3STAT=(UCB3STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_IIC3_UCSCLLOW       (UCB3STAT & (~(0XFFBF)))>>6
//--------------------------------------------------------------------------------------
#define get_IIC3_RXBUF          UCB3RXBUF
//--------------------------------------------------------------------------------------
#define put_IIC3_TXBUF(x)       UCB3TXBUF=x
#define get_IIC3_TXBUF          UCB3TXBUF
//--------------------------------------------------------------------------------------
#define put_IIC3_I2COA(x)       UCB3I2COA=(UCB3I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC3_I2COA          (UCB3I2COA & (~(0XFC00)))>>0
#define put_IIC3_UCGCEN(x)      UCB3I2COA=(UCB3I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_IIC3_UCGCEN         (UCB3I2COA & (~(0X7FFF)))>>15
//--------------------------------------------------------------------------------------
#define put_IIC3_I2CSA(x)       UCB3I2CSA=(UCB3I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_IIC3_I2CSA          (UCB3I2CSA & (~(0XFC00)))>>0
//--------------------------------------------------------------------------------------
#define put_IIC3_UCRXIE(x)      UCB3IE=(UCB3IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_IIC3_UCRXIE         (UCB3IE & (~(0XFFFE)))>>0
#define put_IIC3_UCTXIE(x)      UCB3IE=(UCB3IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_IIC3_UCTXIE         (UCB3IE & (~(0XFFFD)))>>1
#define put_IIC3_UCSTTIE(x)     UCB3IE=(UCB3IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_IIC3_UCSTTIE        (UCB3IE & (~(0XFFFB)))>>2
#define put_IIC3_UCSTPIE(x)     UCB3IE=(UCB3IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_IIC3_UCSTPIE        (UCB3IE & (~(0XFFF7)))>>3
#define put_IIC3_UCALIE(x)      UCB3IE=(UCB3IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_IIC3_UCALIE         (UCB3IE & (~(0XFFEF)))>>4
#define put_IIC3_UCNACKIE(x)    UCB3IE=(UCB3IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_IIC3_UCNACKIE       (UCB3IE & (~(0XFFEF)))>>5
//--------------------------------------------------------------------------------------
#define get_IIC3_UCRXIFG        (UCB3IFG & (~(0XFFFE)))>>0
#define get_IIC3_UCTXIFG        (UCB3IFG & (~(0XFFFD)))>>1
#define get_IIC3_UCSTTIFG       (UCB3IFG & (~(0XFFFB)))>>2
#define get_IIC3_UCSTPIFG       (UCB3IFG & (~(0XFFF7)))>>3
#define get_IIC3_UCALIFG        (UCB3IFG & (~(0XFFEF)))>>4
#define get_IIC3_UCNACKIFG      (UCB3IFG & (~(0XFFDF)))>>5
#define get_IIC3_IFG            (UCB3IFG & (~(0XFFC0)))
//--------------------------------------------------------------------------------------
#define get_IIC3_IV             (UCB3IV & ((0X000E)))>>0
//UCI_B3 结束 ##########################################################################
//MSP430单片机的IIC串行通讯口结束 ######################################################
//************************以上之内容适合于对照原理图设计IIC应用程序*********************


//*******************以下之内容适合于对照寄存器设计UART应用程序*************************
//UCI_A0 开始 ##########################################################################
#define put_UCA0CTL0_UCSYNC(x)     UCA0CTL0=(UCA0CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0CTL0_UCSYNC        (UCA0CTL0 & (~(0XFFFE)))>>0
#define put_UCA0CTL0_UCMODE(x)     UCA0CTL0=(UCA0CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCA0CTL0_UCMODE        (UCA0CTL0 & (~(0XFFF9)))>>1
#define put_UCA0CTL0_UCSPB(x)      UCA0CTL0=(UCA0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA0CTL0_UCSPB         (UCA0CTL0 & (~(0XFFF7)))>>3
#define put_UCA0CTL0_UCMST(x)      UCA0CTL0=(UCA0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA0CTL0_UCMST         (UCA0CTL0 & (~(0XFFF7)))>>3
#define put_UCA0CTL0_UC7BIT(x)     UCA0CTL0=(UCA0CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA0CTL0_UC7BIT        (UCA0CTL0 & (~(0XFFEF)))>>4
#define put_UCA0CTL0_UCMSB(x)      UCA0CTL0=(UCA0CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA0CTL0_UCMSB         (UCA0CTL0 & (~(0XFFDF)))>>5
#define put_UCA0CTL0_UCPAR(x)      UCA0CTL0=(UCA0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA0CTL0_UCPAR         (UCA0CTL0 & (~(0XFFBF)))>>6
#define put_UCA0CTL0_UCCKPL(x)     UCA0CTL0=(UCA0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA0CTL0_UCCKPL        (UCA0CTL0 & (~(0XFFBF)))>>6
#define put_UCA0CTL0_UCPEN(x)      UCA0CTL0=(UCA0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA0CTL0_UCPEN         (UCA0CTL0 & (~(0XFF7F)))>>7
#define put_UCA0CTL0_UCCKPH(x)     UCA0CTL0=(UCA0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA0CTL0_UCCKPH        (UCA0CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCA0CTL1_UCSWRST(x)    UCA0CTL1=(UCA0CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0CTL1_UCSWRST       (UCA0CTL1 & (~(0XFFFE)))>>0
#define put_UCA0CTL1_UCTXBRK(x)    UCA0CTL1=(UCA0CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA0CTL1_UCTXBRK       (UCA0CTL1 & (~(0XFFFD)))>>1
#define put_UCA0CTL1_UCTXADDR(x)   UCA0CTL1=(UCA0CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA0CTL1_UCTXADDR      (UCA0CTL1 & (~(0XFFFB)))>>2
#define put_UCA0CTL1_UCDORM(x)     UCA0CTL1=(UCA0CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA0CTL1_UCDORM        (UCA0CTL1 & (~(0XFFF7)))>>3
#define put_UCA0CTL1_UCBRKIE(x)    UCA0CTL1=(UCA0CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA0CTL1_UCBRKIE       (UCA0CTL1 & (~(0XFFEF)))>>4
#define put_UCA0CTL1_UCRXEIE(x)    UCA0CTL1=(UCA0CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA0CTL1_UCRXEIE       (UCA0CTL1 & (~(0XFFDF)))>>5
#define put_UCA0CTL1_UCSSEL(x)     UCA0CTL1=(UCA0CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCA0CTL1_UCSSEL        (UCA0CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCA0BRW(x)                  UCA0BRW=(UCA0BRW & 0X0000) | (x & 0XFFFF)
#define get_UCA0BRW                     (UCA0BRW & (~(0X0000)))
#define put_UCA0BR0(x)                  UCA0BR0=(UCA0BR0 & 0X0000) | (x & 0X00FF)
#define get_UCA0BR0                     (UCA0BR0 & (~(0X00FF)))
#define put_UCA0BR1(x)                  UCA0BR1=(UCA0BR1 & 0X0000) | (x & 0X00FF)
#define get_UCA0BR1                     (UCA0BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_UCA0MCTL_UCOS16(x)          UCA0MCTL=(UCA0MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0MCTL_UCOS16             (UCA0MCTL & (~(0XFFFE)))>>0
#define put_UCA0MCTL_UCBRS(x)           UCA0MCTL=(UCA0MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UCA0MCTL_UCBRS              (UCA0MCTL & (~(0XFFF1)))>>1
#define put_UCA0MCTL_UCBRF(x)           UCA0MCTL=(UCA0MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UCA0MCTL_UCBRF              (UCA0MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA0STAT_UCBUSY(x)          UCA0STAT=(UCA0STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0STAT_UCBUSY             (UCA0STAT & (~(0XFFFE)))>>0
#define put_UCA0STAT_UCADDR_UCIDLE(x)   UCA0STAT=(UCA0STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA0STAT_UCADDR_UCIDLE      (UCA0STAT & (~(0XFFFD)))>>1
#define put_UCA0STAT_UCRXERR(x)         UCA0STAT=(UCA0STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA0STAT_UCRXERR            (UCA0STAT & (~(0XFFFB)))>>2
#define put_UCA0STAT_UCBRK(x)           UCA0STAT=(UCA0STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA0STAT_UCBRK              (UCA0STAT & (~(0XFFF7)))>>3
#define put_UCA0STAT_UCPE(x)            UCA0STAT=(UCA0STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA0STAT_UCPE               (UCA0STAT & (~(0XFFEF)))>>4
#define put_UCA0STAT_UCOE(x)            UCA0STAT=(UCA0STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA0STAT_UCOE               (UCA0STAT & (~(0XFFDF)))>>5
#define put_UCA0STAT_UCFE(x)            UCA0STAT=(UCA0STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA0STAT_UCFE               (UCA0STAT & (~(0XFFBF)))>>6
#define put_UCA0STAT_UCLISTEN(x)        UCA0STAT=(UCA0STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA0STAT_UCLISTEN           (UCA0STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_UCA0RXBUF                   UCA0RXBUF
#define get_UCA0_RXBUF                  UCA0RXBUF
//------------------------------------------------------------------------------------------
#define put_UCA0TXBUF(x)                UCA0TXBUF=x
#define put_UCA0_TXBUF(x)               UCA0TXBUF=x
#define get_UCA0TXBUF                   UCA0TXBUF
#define get_UCA0_TXBUF                  UCA0TXBUF
//------------------------------------------------------------------------------------------
#define put_UCA0IRTCTL_UCIREN(x)        UCA0IRTCTL=(UCA0IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0IRTCTL_UCIREN           (UCA0IRTCTL & (~(0XFFFE)))>>0
#define put_UCA0IRTCTL_UCIRTXCLK(x)     UCA0IRTCTL=(UCA0IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA0IRTCTL_UCIRTXCLK        (UCA0IRTCTL & (~(0XFFFD)))>>1
#define put_UCA0IRTCTL_UCIRTXPL(x)      UCA0IRTCTL=(UCA0IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA0IRTCTL_UCIRTXPL         (UCA0IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA0IRRCTL_UCIRRXFE(x)      UCA0IRRCTL=(UCA0IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0IRRCTL_UCIRRXFE         (UCA0IRRCTL & (~(0XFFFE)))>>0
#define put_UCA0IRRCTL_UCIRRXPL(x)      UCA0IRRCTL=(UCA0IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA0IRRCTL_UCIRRXPL         (UCA0IRRCTL & (~(0XFFFD)))>>1
#define put_UCA0IRRCTL_UCIRRXFL(x)      UCA0IRRCTL=(UCA0IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA0IRRCTL_UCIRRXFL         (UCA0IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA0ABCTL_UCABDEN(x)        UCA0ABCTL=(UCA0ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0ABCTL_UCABDEN           (UCA0ABCTL & (~(0XFFFE)))>>0
#define put_UCA0ABCTL_UCBTOE(x)         UCA0ABCTL=(UCA0ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA0ABCTL_UCBTOE            (UCA0ABCTL & (~(0XFFFB)))>>2
#define put_UCA0ABCTL_UCSTOE(x)         UCA0ABCTL=(UCA0ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA0ABCTL_UCSTOE            (UCA0ABCTL & (~(0XFFF7)))>>3
#define put_UCA0ABCTL_UCDELIM(x)        UCA0ABCTL=(UCA0ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UCA0ABCTL_UCDELIM           (UCA0ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA0IE_UCRXIE(x)            UCA0IE=(UCA0IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0IE_UCRXIE               (UCA0IE & (~(0XFFFE)))>>0
#define put_UCA0IE_UCTXIE(x)            UCA0IE=(UCA0IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA0IE_UCTXIE               (UCA0IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_UCA0IFG_UCRXIFG(x)          UCA0IFG=(UCA0IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA0IFG_UCRXIFG             (UCA0IFG & (~(0XFFFE)))>>0
//#define put_UCA0IFG_UCTXIFG(x)          UCA0IFG=(UCA0IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA0IFG_UCTXIFG             (UCA0IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_UCA0IV                      (UCA0IV & ((0X0006)))>>0
//UCI_A0 结束 ##############################################################################
//UCI_A1 开始 ##############################################################################
#define put_UCA1CTL0_UCSYNC(x)     UCA1CTL0=(UCA1CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1CTL0_UCSYNC        (UCA1CTL0 & (~(0XFFFE)))>>0
#define put_UCA1CTL0_UCMODE(x)     UCA1CTL0=(UCA1CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCA1CTL0_UCMODE        (UCA1CTL0 & (~(0XFFF9)))>>1
#define put_UCA1CTL0_UCSPB(x)      UCA1CTL0=(UCA1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA1CTL0_UCSPB         (UCA1CTL0 & (~(0XFFF7)))>>1
#define put_UCA1CTL0_UCMST(x)      UCA1CTL0=(UCA1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA1CTL0_UCMST         (UCA1CTL0 & (~(0XFFF7)))>>1
#define put_UCA1CTL0_UC7BIT(x)     UCA1CTL0=(UCA1CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA1CTL0_UC7BIT        (UCA1CTL0 & (~(0XFFEF)))>>1
#define put_UCA1CTL0_UCMSB(x)      UCA1CTL0=(UCA1CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA1CTL0_UCMSB         (UCA1CTL0 & (~(0XFFDF)))>>5
#define put_UCA1CTL0_UCPAR(x)      UCA1CTL0=(UCA1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA1CTL0_UCPAR         (UCA1CTL0 & (~(0XFFBF)))>>6
#define put_UCA1CTL0_UCCKPL(x)     UCA1CTL0=(UCA1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA1CTL0_UCCKPL        (UCA1CTL0 & (~(0XFFBF)))>>6
#define put_UCA1CTL0_UCPEN(x)      UCA1CTL0=(UCA1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA1CTL0_UCPEN         (UCA1CTL0 & (~(0XFF7F)))>>7
#define put_UCA1CTL0_UCCKPH(x)     UCA1CTL0=(UCA1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA1CTL0_UCCKPH        (UCA1CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCA1CTL1_UCSWRST(x)    UCA1CTL1=(UCA1CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1CTL1_UCSWRST       (UCA1CTL1 & (~(0XFFFE)))>>0
#define put_UCA1CTL1_UCTXBRK(x)    UCA1CTL1=(UCA1CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA1CTL1_UCTXBRK       (UCA1CTL1 & (~(0XFFFD)))>>1
#define put_UCA1CTL1_UCTXADDR(x)   UCA1CTL1=(UCA1CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA1CTL1_UCTXADDR      (UCA1CTL1 & (~(0XFFFB)))>>2
#define put_UCA1CTL1_UCDORM(x)     UCA1CTL1=(UCA1CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA1CTL1_UCDORM        (UCA1CTL1 & (~(0XFFF7)))>>3
#define put_UCA1CTL1_UCBRKIE(x)    UCA1CTL1=(UCA1CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA1CTL1_UCBRKIE       (UCA1CTL1 & (~(0XFFEF)))>>4
#define put_UCA1CTL1_UCRXEIE(x)    UCA1CTL1=(UCA1CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA1CTL1_UCRXEIE       (UCA1CTL1 & (~(0XFFDF)))>>5
#define put_UCA1CTL1_UCSSEL(x)     UCA1CTL1=(UCA1CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCA1CTL1_UCSSEL        (UCA1CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCA1BRW(x)                  UCA1BRW=(UCA1BRW & 0X0000) | (x & 0XFFFF)
#define get_UCA1BRW                     (UCA1BRW & (~(0X0000)))
#define put_UCA1BR0(x)                  UCA1BR0=(UCA1BR0 & 0X0000) | (x & 0X00FF)
#define get_UCA1BR0                     (UCA1BR0 & (~(0X00FF)))
#define put_UCA1BR1(x)                  UCA1BR1=(UCA1BR1 & 0X0000) | (x & 0X00FF)
#define get_UCA1BR1                     (UCA1BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_UCA1MCTL_UCOS16(x)          UCA1MCTL=(UCA1MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1MCTL_UCOS16             (UCA1MCTL & (~(0XFFFE)))>>0
#define put_UCA1MCTL_UCBRS(x)           UCA1MCTL=(UCA1MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UCA1MCTL_UCBRS              (UCA1MCTL & (~(0XFFF1)))>>1
#define put_UCA1MCTL_UCBRF(x)           UCA1MCTL=(UCA1MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UCA1MCTL_UCBRF              (UCA1MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA1STAT_UCBUSY(x)          UCA1STAT=(UCA1STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1STAT_UCBUSY             (UCA1STAT & (~(0XFFFE)))>>0
#define put_UCA1STAT_UCADDR_UCIDLE(x)   UCA1STAT=(UCA1STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA1STAT_UCADDR_UCIDLE      (UCA1STAT & (~(0XFFFD)))>>1
#define put_UCA1STAT_UCRXERR(x)         UCA1STAT=(UCA1STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA1STAT_UCRXERR            (UCA1STAT & (~(0XFFFB)))>>2
#define put_UCA1STAT_UCBRK(x)           UCA1STAT=(UCA1STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA1STAT_UCBRK              (UCA1STAT & (~(0XFFF7)))>>3
#define put_UCA1STAT_UCPE(x)            UCA1STAT=(UCA1STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA1STAT_UCPE               (UCA1STAT & (~(0XFFEF)))>>4
#define put_UCA1STAT_UCOE(x)            UCA1STAT=(UCA1STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA1STAT_UCOE               (UCA1STAT & (~(0XFFDF)))>>5
#define put_UCA1STAT_UCFE(x)            UCA1STAT=(UCA1STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA1STAT_UCFE               (UCA1STAT & (~(0XFFBF)))>>6
#define put_UCA1STAT_UCLISTEN(x)        UCA1STAT=(UCA1STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA1STAT_UCLISTEN           (UCA1STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_UCA1RXBUF                   UCA1RXBUF
#define get_UCA1_RXBUF                  UCA1RXBUF
//------------------------------------------------------------------------------------------
#define put_UCA1TXBUF(x)                UCA1TXBUF=x
#define put_UCA1_TXBUF(x)               UCA1TXBUF=x
#define get_UCA1TXBUF                   UCA1TXBUF
#define get_UCA1_TXBUF                  UCA1TXBUF
//------------------------------------------------------------------------------------------
#define put_UCA1IRTCTL_UCIREN(x)        UCA1IRTCTL=(UCA1IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1IRTCTL_UCIREN           (UCA1IRTCTL & (~(0XFFFE)))>>0
#define put_UCA1IRTCTL_UCIRTXCLK(x)     UCA1IRTCTL=(UCA1IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA1IRTCTL_UCIRTXCLK        (UCA1IRTCTL & (~(0XFFFD)))>>1
#define put_UCA1IRTCTL_UCIRTXPL(x)      UCA1IRTCTL=(UCA1IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA1IRTCTL_UCIRTXPL         (UCA1IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA1IRRCTL_UCIRRXFE(x)      UCA1IRRCTL=(UCA1IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1IRRCTL_UCIRRXFE         (UCA1IRRCTL & (~(0XFFFE)))>>0
#define put_UCA1IRRCTL_UCIRRXPL(x)      UCA1IRRCTL=(UCA1IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA1IRRCTL_UCIRRXPL         (UCA1IRRCTL & (~(0XFFFD)))>>1
#define put_UCA1IRRCTL_UCIRRXFL(x)      UCA1IRRCTL=(UCA1IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA1IRRCTL_UCIRRXFL         (UCA1IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA1ABCTL_UCABDEN(x)        UCA1ABCTL=(UCA1ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1ABCTL_UCABDEN           (UCA1ABCTL & (~(0XFFFE)))>>0
#define put_UCA1ABCTL_UCBTOE(x)         UCA1ABCTL=(UCA1ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA1ABCTL_UCBTOE            (UCA1ABCTL & (~(0XFFFB)))>>2
#define put_UCA1ABCTL_UCSTOE(x)         UCA1ABCTL=(UCA1ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA1ABCTL_UCSTOE            (UCA1ABCTL & (~(0XFFF7)))>>3
#define put_UCA1ABCTL_UCDELIM(x)        UCA1ABCTL=(UCA1ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UCA1ABCTL_UCDELIM           (UCA1ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA1IE_UCRXIE(x)            UCA1IE=(UCA1IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1IE_UCRXIE               (UCA1IE & (~(0XFFFE)))>>0
#define put_UCA1IE_UCTXIE(x)            UCA1IE=(UCA1IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA1IE_UCTXIE               (UCA1IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_UCA1IFG_UCRXIFG(x)          UCA1IFG=(UCA1IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA1IFG_UCRXIFG             (UCA1IFG & (~(0XFFFE)))>>0
//#define put_UCA1IFG_UCTXIFG(x)          UCA1IFG=(UCA1IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA1IFG_UCTXIFG             (UCA1IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_UCA1IV                      (UCA1IV & ((0X0006)))>>0
//UCI_A1 结束 ##############################################################################
//UCI_A2 开始 ##############################################################################
#define put_UCA2CTL0_UCSYNC(x)     UCA2CTL0=(UCA2CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2CTL0_UCSYNC        (UCA2CTL0 & (~(0XFFFE)))>>0
#define put_UCA2CTL0_UCMODE(x)     UCA2CTL0=(UCA2CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCA2CTL0_UCMODE        (UCA2CTL0 & (~(0XFFF9)))>>1
#define put_UCA2CTL0_UCSPB(x)      UCA2CTL0=(UCA2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA2CTL0_UCSPB         (UCA2CTL0 & (~(0XFFF7)))>>1
#define put_UCA2CTL0_UCMST(x)      UCA2CTL0=(UCA2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA2CTL0_UCMST         (UCA2CTL0 & (~(0XFFF7)))>>1
#define put_UCA2CTL0_UC7BIT(x)     UCA2CTL0=(UCA2CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA2CTL0_UC7BIT        (UCA2CTL0 & (~(0XFFEF)))>>1
#define put_UCA2CTL0_UCMSB(x)      UCA2CTL0=(UCA2CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA2CTL0_UCMSB         (UCA2CTL0 & (~(0XFFDF)))>>5
#define put_UCA2CTL0_UCPAR(x)      UCA2CTL0=(UCA2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA2CTL0_UCPAR         (UCA2CTL0 & (~(0XFFBF)))>>6
#define put_UCA2CTL0_UCCKPL(x)     UCA2CTL0=(UCA2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA2CTL0_UCCKPL        (UCA2CTL0 & (~(0XFFBF)))>>6
#define put_UCA2CTL0_UCPEN(x)      UCA2CTL0=(UCA2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA2CTL0_UCPEN         (UCA2CTL0 & (~(0XFF7F)))>>7
#define put_UCA2CTL0_UCCKPH(x)     UCA2CTL0=(UCA2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA2CTL0_UCCKPH        (UCA2CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCA2CTL1_UCSWRST(x)    UCA2CTL1=(UCA2CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2CTL1_UCSWRST       (UCA2CTL1 & (~(0XFFFE)))>>0
#define put_UCA2CTL1_UCTXBRK(x)    UCA2CTL1=(UCA2CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA2CTL1_UCTXBRK       (UCA2CTL1 & (~(0XFFFD)))>>1
#define put_UCA2CTL1_UCTXADDR(x)   UCA2CTL1=(UCA2CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA2CTL1_UCTXADDR      (UCA2CTL1 & (~(0XFFFB)))>>2
#define put_UCA2CTL1_UCDORM(x)     UCA2CTL1=(UCA2CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA2CTL1_UCDORM        (UCA2CTL1 & (~(0XFFF7)))>>3
#define put_UCA2CTL1_UCBRKIE(x)    UCA2CTL1=(UCA2CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA2CTL1_UCBRKIE       (UCA2CTL1 & (~(0XFFEF)))>>4
#define put_UCA2CTL1_UCRXEIE(x)    UCA2CTL1=(UCA2CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA2CTL1_UCRXEIE       (UCA2CTL1 & (~(0XFFDF)))>>5
#define put_UCA2CTL1_UCSSEL(x)     UCA2CTL1=(UCA2CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCA2CTL1_UCSSEL        (UCA2CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCA2BRW(x)                  UCA2BRW=(UCA2BRW & 0X0000) | (x & 0XFFFF)
#define get_UCA2BRW                     (UCA2BRW & (~(0X0000)))
#define put_UCA2BR0(x)                  UCA2BR0=(UCA2BR0 & 0X0000) | (x & 0X00FF)
#define get_UCA2BR0                     (UCA2BR0 & (~(0X00FF)))
#define put_UCA2BR1(x)                  UCA2BR1=(UCA2BR1 & 0X0000) | (x & 0X00FF)
#define get_UCA2BR1                     (UCA2BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_UCA2MCTL_UCOS16(x)          UCA2MCTL=(UCA2MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2MCTL_UCOS16             (UCA2MCTL & (~(0XFFFE)))>>0
#define put_UCA2MCTL_UCBRS(x)           UCA2MCTL=(UCA2MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UCA2MCTL_UCBRS              (UCA2MCTL & (~(0XFFF1)))>>1
#define put_UCA2MCTL_UCBRF(x)           UCA2MCTL=(UCA2MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UCA2MCTL_UCBRF              (UCA2MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA2STAT_UCBUSY(x)          UCA2STAT=(UCA2STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2STAT_UCBUSY             (UCA2STAT & (~(0XFFFE)))>>0
#define put_UCA2STAT_UCADDR_UCIDLE(x)   UCA2STAT=(UCA2STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA2STAT_UCADDR_UCIDLE      (UCA2STAT & (~(0XFFFD)))>>1
#define put_UCA2STAT_UCRXERR(x)         UCA2STAT=(UCA2STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA2STAT_UCRXERR            (UCA2STAT & (~(0XFFFB)))>>2
#define put_UCA2STAT_UCBRK(x)           UCA2STAT=(UCA2STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA2STAT_UCBRK              (UCA2STAT & (~(0XFFF7)))>>3
#define put_UCA2STAT_UCPE(x)            UCA2STAT=(UCA2STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA2STAT_UCPE               (UCA2STAT & (~(0XFFEF)))>>4
#define put_UCA2STAT_UCOE(x)            UCA2STAT=(UCA2STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA2STAT_UCOE               (UCA2STAT & (~(0XFFDF)))>>5
#define put_UCA2STAT_UCFE(x)            UCA2STAT=(UCA2STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA2STAT_UCFE               (UCA2STAT & (~(0XFFBF)))>>6
#define put_UCA2STAT_UCLISTEN(x)        UCA2STAT=(UCA2STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA2STAT_UCLISTEN           (UCA2STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_UCA2RXBUF                   UCA2RXBUF
#define get_UCA2_RXBUF                  UCA2RXBUF
//------------------------------------------------------------------------------------------
#define put_UCA2TXBUF(x)                UCA2TXBUF=x
#define put_UCA2_TXBUF(x)               UCA2TXBUF=x
#define get_UCA2TXBUF                   UCA2TXBUF
#define get_UCA2_TXBUF                  UCA2TXBUF
//------------------------------------------------------------------------------------------
#define put_UCA2IRTCTL_UCIREN(x)        UCA2IRTCTL=(UCA2IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2IRTCTL_UCIREN           (UCA2IRTCTL & (~(0XFFFE)))>>0
#define put_UCA2IRTCTL_UCIRTXCLK(x)     UCA2IRTCTL=(UCA2IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA2IRTCTL_UCIRTXCLK        (UCA2IRTCTL & (~(0XFFFD)))>>1
#define put_UCA2IRTCTL_UCIRTXPL(x)      UCA2IRTCTL=(UCA2IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA2IRTCTL_UCIRTXPL         (UCA2IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA2IRRCTL_UCIRRXFE(x)      UCA2IRRCTL=(UCA2IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2IRRCTL_UCIRRXFE         (UCA2IRRCTL & (~(0XFFFE)))>>0
#define put_UCA2IRRCTL_UCIRRXPL(x)      UCA2IRRCTL=(UCA2IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA2IRRCTL_UCIRRXPL         (UCA2IRRCTL & (~(0XFFFD)))>>1
#define put_UCA2IRRCTL_UCIRRXFL(x)      UCA2IRRCTL=(UCA2IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA2IRRCTL_UCIRRXFL         (UCA2IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA2ABCTL_UCABDEN(x)        UCA2ABCTL=(UCA2ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2ABCTL_UCABDEN           (UCA2ABCTL & (~(0XFFFE)))>>0
#define put_UCA2ABCTL_UCBTOE(x)         UCA2ABCTL=(UCA2ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA2ABCTL_UCBTOE            (UCA2ABCTL & (~(0XFFFB)))>>2
#define put_UCA2ABCTL_UCSTOE(x)         UCA2ABCTL=(UCA2ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA2ABCTL_UCSTOE            (UCA2ABCTL & (~(0XFFF7)))>>3
#define put_UCA2ABCTL_UCDELIM(x)        UCA2ABCTL=(UCA2ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UCA2ABCTL_UCDELIM           (UCA2ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA2IE_UCRXIE(x)            UCA2IE=(UCA2IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2IE_UCRXIE               (UCA2IE & (~(0XFFFE)))>>0
#define put_UCA2IE_UCTXIE(x)            UCA2IE=(UCA2IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA2IE_UCTXIE               (UCA2IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_UCA2IFG_UCRXIFG(x)          UCA2IFG=(UCA2IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA2IFG_UCRXIFG             (UCA2IFG & (~(0XFFFE)))>>0
//#define put_UCA2IFG_UCTXIFG(x)          UCA2IFG=(UCA2IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA2IFG_UCTXIFG             (UCA2IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_UCA2IV                      (UCA2IV & ((0X0006)))>>0
//UCI_A2 结束 ##############################################################################
//UCI_A3 开始 ##############################################################################
#define put_UCA3CTL0_UCSYNC(x)     UCA3CTL0=(UCA3CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3CTL0_UCSYNC        (UCA3CTL0 & (~(0XFFFE)))>>0
#define put_UCA3CTL0_UCMODE(x)     UCA3CTL0=(UCA3CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCA3CTL0_UCMODE        (UCA3CTL0 & (~(0XFFF9)))>>1
#define put_UCA3CTL0_UCSPB(x)      UCA3CTL0=(UCA3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA3CTL0_UCSPB         (UCA3CTL0 & (~(0XFFF7)))>>3
#define put_UCA3CTL0_UCMST(x)      UCA3CTL0=(UCA3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA3CTL0_UCMST         (UCA3CTL0 & (~(0XFFF7)))>>3
#define put_UCA3CTL0_UC7BIT(x)     UCA3CTL0=(UCA3CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA3CTL0_UC7BIT        (UCA3CTL0 & (~(0XFFEF)))>>4
#define put_UCA3CTL0_UCMSB(x)      UCA3CTL0=(UCA3CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA3CTL0_UCMSB         (UCA3CTL0 & (~(0XFFDF)))>>5
#define put_UCA3CTL0_UCPAR(x)      UCA3CTL0=(UCA3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA3CTL0_UCPAR         (UCA3CTL0 & (~(0XFFBF)))>>6
#define put_UCA3CTL0_UCCKPL(x)     UCA3CTL0=(UCA3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA3CTL0_UCCKPL        (UCA3CTL0 & (~(0XFFBF)))>>6
#define put_UCA3CTL0_UCPEN(x)      UCA3CTL0=(UCA3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA3CTL0_UCPEN         (UCA3CTL0 & (~(0XFF7F)))>>7
#define put_UCA3CTL0_UCCKPH(x)     UCA3CTL0=(UCA3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA3CTL0_UCCKPH        (UCA3CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCA3CTL1_UCSWRST(x)    UCA3CTL1=(UCA3CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3CTL1_UCSWRST       (UCA3CTL1 & (~(0XFFFE)))>>0
#define put_UCA3CTL1_UCTXBRK(x)    UCA3CTL1=(UCA3CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA3CTL1_UCTXBRK       (UCA3CTL1 & (~(0XFFFD)))>>1
#define put_UCA3CTL1_UCTXADDR(x)   UCA3CTL1=(UCA3CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA3CTL1_UCTXADDR      (UCA3CTL1 & (~(0XFFFB)))>>2
#define put_UCA3CTL1_UCDORM(x)     UCA3CTL1=(UCA3CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA3CTL1_UCDORM        (UCA3CTL1 & (~(0XFFF7)))>>3
#define put_UCA3CTL1_UCBRKIE(x)    UCA3CTL1=(UCA3CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA3CTL1_UCBRKIE       (UCA3CTL1 & (~(0XFFEF)))>>4
#define put_UCA3CTL1_UCRXEIE(x)    UCA3CTL1=(UCA3CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA3CTL1_UCRXEIE       (UCA3CTL1 & (~(0XFFDF)))>>5
#define put_UCA3CTL1_UCSSEL(x)     UCA3CTL1=(UCA3CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCA3CTL1_UCSSEL        (UCA3CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCA3BRW(x)                  UCA3BRW=(UCA3BRW & 0X0000) | (x & 0XFFFF)
#define get_UCA3BRW                     (UCA3BRW & (~(0X0000)))
#define put_UCA3BR0(x)                  UCA3BR0=(UCA3BR0 & 0X0000) | (x & 0X00FF)
#define get_UCA3BR0                     (UCA3BR0 & (~(0X00FF)))
#define put_UCA3BR1(x)                  UCA3BR1=(UCA3BR1 & 0X0000) | (x & 0X00FF)
#define get_UCA3BR1                     (UCA3BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_UCA3MCTL_UCOS16(x)          UCA3MCTL=(UCA3MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3MCTL_UCOS16             (UCA3MCTL & (~(0XFFFE)))>>0
#define put_UCA3MCTL_UCBRS(x)           UCA3MCTL=(UCA3MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_UCA3MCTL_UCBRS              (UCA3MCTL & (~(0XFFF1)))>>1
#define put_UCA3MCTL_UCBRF(x)           UCA3MCTL=(UCA3MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_UCA3MCTL_UCBRF              (UCA3MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA3STAT_UCBUSY(x)          UCA3STAT=(UCA3STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3STAT_UCBUSY             (UCA3STAT & (~(0XFFFE)))>>0
#define put_UCA3STAT_UCADDR_UCIDLE(x)   UCA3STAT=(UCA3STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA3STAT_UCADDR_UCIDLE      (UCA3STAT & (~(0XFFFD)))>>1
#define put_UCA3STAT_UCRXERR(x)         UCA3STAT=(UCA3STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA3STAT_UCRXERR            (UCA3STAT & (~(0XFFFB)))>>2
#define put_UCA3STAT_UCBRK(x)           UCA3STAT=(UCA3STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA3STAT_UCBRK              (UCA3STAT & (~(0XFFF7)))>>3
#define put_UCA3STAT_UCPE(x)            UCA3STAT=(UCA3STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCA3STAT_UCPE               (UCA3STAT & (~(0XFFEF)))>>4
#define put_UCA3STAT_UCOE(x)            UCA3STAT=(UCA3STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCA3STAT_UCOE               (UCA3STAT & (~(0XFFDF)))>>5
#define put_UCA3STAT_UCFE(x)            UCA3STAT=(UCA3STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCA3STAT_UCFE               (UCA3STAT & (~(0XFFBF)))>>6
#define put_UCA3STAT_UCLISTEN(x)        UCA3STAT=(UCA3STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCA3STAT_UCLISTEN           (UCA3STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_UCA3RXBUF                   UCA3RXBUF
#define get_UCA3_RXBUF                  UCA3RXBUF
//------------------------------------------------------------------------------------------
#define put_UCA3TXBUF(x)                UCA3TXBUF=x
#define put_UCA3_TXBUF(x)               UCA3TXBUF=x
#define get_UCA3TXBUF                   UCA3TXBUF
#define get_UCA3_TXBUF                  UCA3TXBUF
//------------------------------------------------------------------------------------------
#define put_UCA3IRTCTL_UCIREN(x)        UCA3IRTCTL=(UCA3IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3IRTCTL_UCIREN           (UCA3IRTCTL & (~(0XFFFE)))>>0
#define put_UCA3IRTCTL_UCIRTXCLK(x)     UCA3IRTCTL=(UCA3IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA3IRTCTL_UCIRTXCLK        (UCA3IRTCTL & (~(0XFFFD)))>>1
#define put_UCA3IRTCTL_UCIRTXPL(x)      UCA3IRTCTL=(UCA3IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA3IRTCTL_UCIRTXPL         (UCA3IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA3IRRCTL_UCIRRXFE(x)      UCA3IRRCTL=(UCA3IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3IRRCTL_UCIRRXFE         (UCA3IRRCTL & (~(0XFFFE)))>>0
#define put_UCA3IRRCTL_UCIRRXPL(x)      UCA3IRRCTL=(UCA3IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA3IRRCTL_UCIRRXPL         (UCA3IRRCTL & (~(0XFFFD)))>>1
#define put_UCA3IRRCTL_UCIRRXFL(x)      UCA3IRRCTL=(UCA3IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_UCA3IRRCTL_UCIRRXFL         (UCA3IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_UCA3ABCTL_UCABDEN(x)        UCA3ABCTL=(UCA3ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3ABCTL_UCABDEN           (UCA3ABCTL & (~(0XFFFE)))>>0
#define put_UCA3ABCTL_UCBTOE(x)         UCA3ABCTL=(UCA3ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCA3ABCTL_UCBTOE            (UCA3ABCTL & (~(0XFFFB)))>>2
#define put_UCA3ABCTL_UCSTOE(x)         UCA3ABCTL=(UCA3ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCA3ABCTL_UCSTOE            (UCA3ABCTL & (~(0XFFF7)))>>3
#define put_UCA3ABCTL_UCDELIM(x)        UCA3ABCTL=(UCA3ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_UCA3ABCTL_UCDELIM           (UCA3ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_UCA3IE_UCRXIE(x)            UCA3IE=(UCA3IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3IE_UCRXIE               (UCA3IE & (~(0XFFFE)))>>0
#define put_UCA3IE_UCTXIE(x)            UCA3IE=(UCA3IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA3IE_UCTXIE               (UCA3IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_UCA3IFG_UCRXIFG(x)          UCA3IFG=(UCA3IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCA3IFG_UCRXIFG             (UCA3IFG & (~(0XFFFE)))>>0
//#define put_UCA3IFG_UCTXIFG(x)          UCA3IFG=(UCA3IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCA3IFG_UCTXIFG             (UCA3IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_UCA3IV                      (UCA3IV & ((0X0006)))>>0
//UCI_A3 结束 ##############################################################################
//*******************以上之内容适合于对照寄存器设计UART应用程序*****************************


//*******************以下之内容适合于对照寄存器设计IIC应用程序*****************************
//UCI_B0 开始 ##############################################################################
#define put_UCB0CTL0_UCSYNC(x)     UCB0CTL0=(UCB0CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB0CTL0_UCSYNC        (UCB0CTL0 & (~(0XFFFE)))>>0
#define put_UCB0CTL0_UCMODE(x)     UCB0CTL0=(UCB0CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCB0CTL0_UCMODE        (UCB0CTL0 & (~(0XFFF9)))>>1
#define put_UCB0CTL0_UCMST(x)      UCB0CTL0=(UCB0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB0CTL0_UCMST         (UCB0CTL0 & (~(0XFFF7)))>>3
#define put_UCB0CTL0_UCMM(x)       UCB0CTL0=(UCB0CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB0CTL0_UCMM          (UCB0CTL0 & (~(0XFFDF)))>>5
#define put_UCB0CTL0_UCSLA10(x)    UCB0CTL0=(UCB0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB0CTL0_UCSLA10       (UCB0CTL0 & (~(0XFFBF)))>>6
#define put_UCB0CTL0_UCA10(x)      UCB0CTL0=(UCB0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCB0CTL0_UCA10         (UCB0CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCB0CTL1_UCSWRST(x)    UCB0CTL1=(UCB0CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB0CTL1_UCSWRST       (UCB0CTL1 & (~(0XFFFE)))>>0
#define put_UCB0CTL1_UCTXSTT(x)    UCB0CTL1=(UCB0CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB0CTL1_UCTXSTT       (UCB0CTL1 & (~(0XFFFD)))>>1
#define put_UCB0CTL1_UCTXSTP(x)    UCB0CTL1=(UCB0CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB0CTL1_UCTXSTP       (UCB0CTL1 & (~(0XFFFB)))>>2
#define put_UCB0CTL1_UCTXNACK(x)   UCB0CTL1=(UCB0CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB0CTL1_UCTXNACK      (UCB0CTL1 & (~(0XFFF7)))>>3
#define put_UCB0CTL1_UCTR(x)       UCB0CTL1=(UCB0CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB0CTL1_UCTR          (UCB0CTL1 & (~(0XFFEF)))>>4
#define put_UCB0CTL1_UCSSEL(x)     UCB0CTL1=(UCB0CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCB0CTL1_UCSSEL        (UCB0CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCB0BRW(x)             UCB0BRW=(UCB0BRW & 0X0000) | (x & 0XFFFF)
#define get_UCB0BRW                (UCB0BRW & (~(0X0000)))
//------------------------------------------------------------------------------------------
#define put_UCB0STAT_UCBBUSY       UCB0STAT=(UCB0STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB0STAT_UCBBUSY       (UCB0STAT & (~(0XFFEF)))>>4
#define put_UCB0STAT_UCGC(x)       UCB0STAT=(UCB0STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB0STAT_UCGC          (UCB0STAT & (~(0XFFDF)))>>5
#define put_UCB0STAT_UCSCLLOW(x)   UCB0STAT=(UCB0STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB0STAT_UCSCLLOW      (UCB0STAT & (~(0XFFBF)))>>6
//------------------------------------------------------------------------------------------
#define get_UCB0RXBUF              UCB0RXBUF
#define get_UCB0_RXBUF             UCB0RXBUF
//------------------------------------------------------------------------------------------
#define put_UCB0TXBUF(x)           UCB0TXBUF=x
#define put_UCB0_TXBUF(x)          UCB0TXBUF=x
#define get_UCB0TXBUF              UCB0TXBUF
#define get_UCB0_TXBUF             UCB0TXBUF
//------------------------------------------------------------------------------------------
#define put_UCB0I2COA_I2COA(x)     UCB0I2COA=(UCB0I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB0I2COA_I2COA        (UCB0I2COA & (~(0XFC00)))>>0
#define put_UCB0I2COA_UCGCEN(x)    UCB0I2COA=(UCB0I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_UCB0I2COA_UCGCEN       (UCB0I2COA & (~(0X7FFF)))>>15
//------------------------------------------------------------------------------------------
#define put_UCB0I2CSA_I2CSA(x)     UCB0I2CSA=(UCB0I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB0I2CSA_I2CSA        (UCB0I2CSA & (~(0XFC00)))>>0
//------------------------------------------------------------------------------------------
#define put_UCB0IE_UCRXIE(x)       UCB0IE=(UCB0IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB0IE_UCRXIE          (UCB0IE & (~(0XFFFE)))>>0
#define put_UCB0IE_UCTXIE(x)       UCB0IE=(UCB0IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB0IE_UCTXIE          (UCB0IE & (~(0XFFFD)))>>1
#define put_UCB0IE_UCSTTIE(x)      UCB0IE=(UCB0IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB0IE_UCSTTIE         (UCB0IE & (~(0XFFFB)))>>2
#define put_UCB0IE_UCSTPIE(x)      UCB0IE=(UCB0IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB0IE_UCSTPIE         (UCB0IE & (~(0XFFF7)))>>3
#define put_UCB0IE_UCALIE(x)       UCB0IE=(UCB0IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB0IE_UCALIE          (UCB0IE & (~(0XFFEF)))>>4
#define put_UCB0IE_UCNACKIE(x)     UCB0IE=(UCB0IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_UCB0IE_UCNACKIE        (UCB0IE & (~(0XFFEF)))>>5
//------------------------------------------------------------------------------------------
#define get_UCB0IFG_UCRXIFG        (UCB0IFG & (~(0XFFFE)))>>0
#define get_UCB0IFG_UCTXIFG        (UCB0IFG & (~(0XFFFD)))>>1
#define get_UCB0IFG_UCSTTIFG       (UCB0IFG & (~(0XFFFB)))>>2
#define get_UCB0IFG_UCSTPIFG       (UCB0IFG & (~(0XFFF7)))>>3
#define get_UCB0IFG_UCALIFG        (UCB0IFG & (~(0XFFEF)))>>4
#define get_UCB0IFG_UCNACKIFG      (UCB0IFG & (~(0XFFDF)))>>5
#define get_UCB0IFG                (UCB0IFG & (~(0XFFC0)))
//------------------------------------------------------------------------------------------
#define get_UCB0IV                 (UCB0IV & ((0X000E)))>>0
//UCI_B0 结束 ##############################################################################
//UCI_B1 开始 ##############################################################################
#define put_UCB1CTL0_UCSYNC(x)     UCB1CTL0=(UCB1CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB1CTL0_UCSYNC        (UCB1CTL0 & (~(0XFFFE)))>>0
#define put_UCB1CTL0_UCMODE(x)     UCB1CTL0=(UCB1CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCB1CTL0_UCMODE        (UCB1CTL0 & (~(0XFFF9)))>>1
#define put_UCB1CTL0_UCMST(x)      UCB1CTL0=(UCB1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB1CTL0_UCMST         (UCB1CTL0 & (~(0XFFF7)))>>3
#define put_UCB1CTL0_UCMM(x)       UCB1CTL0=(UCB1CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB1CTL0_UCMM          (UCB1CTL0 & (~(0XFFDF)))>>5
#define put_UCB1CTL0_UCSLA10(x)    UCB1CTL0=(UCB1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB1CTL0_UCSLA10       (UCB1CTL0 & (~(0XFFBF)))>>6
#define put_UCB1CTL0_UCA10(x)      UCB1CTL0=(UCB1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCB1CTL0_UCA10         (UCB1CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCB1CTL1_UCSWRST(x)    UCB1CTL1=(UCB1CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB1CTL1_UCSWRST       (UCB1CTL1 & (~(0XFFFE)))>>0
#define put_UCB1CTL1_UCTXSTT(x)    UCB1CTL1=(UCB1CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB1CTL1_UCTXSTT       (UCB1CTL1 & (~(0XFFFD)))>>1
#define put_UCB1CTL1_UCTXSTP(x)    UCB1CTL1=(UCB1CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB1CTL1_UCTXSTP       (UCB1CTL1 & (~(0XFFFB)))>>2
#define put_UCB1CTL1_UCTXNACK(x)   UCB1CTL1=(UCB1CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB1CTL1_UCTXNACK      (UCB1CTL1 & (~(0XFFF7)))>>3
#define put_UCB1CTL1_UCTR(x)       UCB1CTL1=(UCB1CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB1CTL1_UCTR          (UCB1CTL1 & (~(0XFFEF)))>>4
#define put_UCB1CTL1_UCSSEL(x)     UCB1CTL1=(UCB1CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCB1CTL1_UCSSEL        (UCB1CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCB1BRW(x)             UCB1BRW=(UCB1BRW & 0X0000) | (x & 0XFFFF)
#define get_UCB1BRW                (UCB1BRW & (~(0X0000)))
//------------------------------------------------------------------------------------------
#define put_UCB1STAT_UCBBUSY       UCB1STAT=(UCB1STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB1STAT_UCBBUSY       (UCB1STAT & (~(0XFFEF)))>>4
#define put_UCB1STAT_UCGC(x)       UCB1STAT=(UCB1STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB1STAT_UCGC          (UCB1STAT & (~(0XFFDF)))>>5
#define put_UCB1STAT_UCSCLLOW(x)   UCB1STAT=(UCB1STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB1STAT_UCSCLLOW      (UCB1STAT & (~(0XFFBF)))>>6
//------------------------------------------------------------------------------------------
#define get_UCB1RXBUF              UCB1RXBUF
#define get_UCB1_RXBUF             UCB1RXBUF
//------------------------------------------------------------------------------------------
#define put_UCB1TXBUF(x)           UCB1TXBUF=x
#define put_UCB1_TXBUF(x)          UCB1TXBUF=x
#define get_UCB1TXBUF              UCB1TXBUF
#define get_UCB1_TXBUF             UCB1TXBUF
//------------------------------------------------------------------------------------------
#define put_UCB1I2COA_I2COA(x)     UCB1I2COA=(UCB1I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB1I2COA_I2COA        (UCB1I2COA & (~(0XFC00)))>>0
#define put_UCB1I2COA_UCGCEN(x)    UCB1I2COA=(UCB1I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_UCB1I2COA_UCGCEN       (UCB1I2COA & (~(0X7FFF)))>>15
//------------------------------------------------------------------------------------------
#define put_UCB1I2CSA_I2CSA(x)     UCB1I2CSA=(UCB1I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB1I2CSA_I2CSA        (UCB1I2CSA & (~(0XFC00)))>>0
//------------------------------------------------------------------------------------------
#define put_UCB1IE_UCRXIE(x)       UCB1IE=(UCB1IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB1IE_UCRXIE          (UCB1IE & (~(0XFFFE)))>>0
#define put_UCB1IE_UCTXIE(x)       UCB1IE=(UCB1IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB1IE_UCTXIE          (UCB1IE & (~(0XFFFD)))>>1
#define put_UCB1IE_UCSTTIE(x)      UCB1IE=(UCB1IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB1IE_UCSTTIE         (UCB1IE & (~(0XFFFB)))>>2
#define put_UCB1IE_UCSTPIE(x)      UCB1IE=(UCB1IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB1IE_UCSTPIE         (UCB1IE & (~(0XFFF7)))>>3
#define put_UCB1IE_UCALIE(x)       UCB1IE=(UCB1IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB1IE_UCALIE          (UCB1IE & (~(0XFFEF)))>>4
#define put_UCB1IE_UCNACKIE(x)     UCB1IE=(UCB1IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_UCB1IE_UCNACKIE        (UCB1IE & (~(0XFFEF)))>>5
//------------------------------------------------------------------------------------------
#define get_UCB1IFG_UCRXIFG        (UCB1IFG & (~(0XFFFE)))>>0
#define get_UCB1IFG_UCTXIFG        (UCB1IFG & (~(0XFFFD)))>>1
#define get_UCB1IFG_UCSTTIFG       (UCB1IFG & (~(0XFFFB)))>>2
#define get_UCB1IFG_UCSTPIFG       (UCB1IFG & (~(0XFFF7)))>>3
#define get_UCB1IFG_UCALIFG        (UCB1IFG & (~(0XFFEF)))>>4
#define get_UCB1IFG_UCNACKIFG      (UCB1IFG & (~(0XFFDF)))>>5
#define get_UCB1IFG                (UCB1IFG & (~(0XFFC0)))
//------------------------------------------------------------------------------------------
#define get_UCB1IV                 (UCB1IV & ((0X000E)))>>0
//UCI_B1 结束 ##############################################################################
//UCI_B2 开始 ##############################################################################
#define put_UCB2CTL0_UCSYNC(x)     UCB2CTL0=(UCB2CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB2CTL0_UCSYNC        (UCB2CTL0 & (~(0XFFFE)))>>0
#define put_UCB2CTL0_UCMODE(x)     UCB2CTL0=(UCB2CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCB2CTL0_UCMODE        (UCB2CTL0 & (~(0XFFF9)))>>1
#define put_UCB2CTL0_UCMST(x)      UCB2CTL0=(UCB2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB2CTL0_UCMST         (UCB2CTL0 & (~(0XFFF7)))>>3
#define put_UCB2CTL0_UCMM(x)       UCB2CTL0=(UCB2CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB2CTL0_UCMM          (UCB2CTL0 & (~(0XFFDF)))>>5
#define put_UCB2CTL0_UCSLA10(x)    UCB2CTL0=(UCB2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB2CTL0_UCSLA10       (UCB2CTL0 & (~(0XFFBF)))>>6
#define put_UCB2CTL0_UCA10(x)      UCB2CTL0=(UCB2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCB2CTL0_UCA10         (UCB2CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCB2CTL1_UCSWRST(x)    UCB2CTL1=(UCB2CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB2CTL1_UCSWRST       (UCB2CTL1 & (~(0XFFFE)))>>0
#define put_UCB2CTL1_UCTXSTT(x)    UCB2CTL1=(UCB2CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB2CTL1_UCTXSTT       (UCB2CTL1 & (~(0XFFFD)))>>1
#define put_UCB2CTL1_UCTXSTP(x)    UCB2CTL1=(UCB2CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB2CTL1_UCTXSTP       (UCB2CTL1 & (~(0XFFFB)))>>2
#define put_UCB2CTL1_UCTXNACK(x)   UCB2CTL1=(UCB2CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB2CTL1_UCTXNACK      (UCB2CTL1 & (~(0XFFF7)))>>3
#define put_UCB2CTL1_UCTR(x)       UCB2CTL1=(UCB2CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB2CTL1_UCTR          (UCB2CTL1 & (~(0XFFEF)))>>4
#define put_UCB2CTL1_UCSSEL(x)     UCB2CTL1=(UCB2CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCB2CTL1_UCSSEL        (UCB2CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCB2BRW(x)             UCB2BRW=(UCB2BRW & 0X0000) | (x & 0XFFFF)
#define get_UCB2BRW                (UCB2BRW & (~(0X0000)))
//------------------------------------------------------------------------------------------
#define put_UCB2STAT_UCBBUSY       UCB2STAT=(UCB2STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB2STAT_UCBBUSY       (UCB2STAT & (~(0XFFEF)))>>4
#define put_UCB2STAT_UCGC(x)       UCB2STAT=(UCB2STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB2STAT_UCGC          (UCB2STAT & (~(0XFFDF)))>>5
#define put_UCB2STAT_UCSCLLOW(x)   UCB2STAT=(UCB2STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB2STAT_UCSCLLOW      (UCB2STAT & (~(0XFFBF)))>>6
//------------------------------------------------------------------------------------------
#define get_UCB2RXBUF              UCB2RXBUF
#define get_UCB2_RXBUF             UCB2RXBUF
//------------------------------------------------------------------------------------------
#define put_UCB2TXBUF(x)           UCB2TXBUF=x
#define put_UCB2_TXBUF(x)          UCB2TXBUF=x
#define get_UCB2TXBUF              UCB2TXBUF
#define get_UCB2_TXBUF             UCB2TXBUF
//------------------------------------------------------------------------------------------
#define put_UCB2I2COA_I2COA(x)     UCB2I2COA=(UCB2I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB2I2COA_I2COA        (UCB2I2COA & (~(0XFC00)))>>0
#define put_UCB2I2COA_UCGCEN(x)    UCB2I2COA=(UCB2I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_UCB2I2COA_UCGCEN       (UCB2I2COA & (~(0X7FFF)))>>15
//------------------------------------------------------------------------------------------
#define put_UCB2I2CSA_I2CSA(x)     UCB2I2CSA=(UCB2I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB2I2CSA_I2CSA        (UCB2I2CSA & (~(0XFC00)))>>0
//------------------------------------------------------------------------------------------
#define put_UCB2IE_UCRXIE(x)       UCB2IE=(UCB2IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB2IE_UCRXIE          (UCB2IE & (~(0XFFFE)))>>0
#define put_UCB2IE_UCTXIE(x)       UCB2IE=(UCB2IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB2IE_UCTXIE          (UCB2IE & (~(0XFFFD)))>>1
#define put_UCB2IE_UCSTTIE(x)      UCB2IE=(UCB2IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB2IE_UCSTTIE         (UCB2IE & (~(0XFFFB)))>>2
#define put_UCB2IE_UCSTPIE(x)      UCB2IE=(UCB2IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB2IE_UCSTPIE         (UCB2IE & (~(0XFFF7)))>>3
#define put_UCB2IE_UCALIE(x)       UCB2IE=(UCB2IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB2IE_UCALIE          (UCB2IE & (~(0XFFEF)))>>4
#define put_UCB2IE_UCNACKIE(x)     UCB2IE=(UCB2IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_UCB2IE_UCNACKIE        (UCB2IE & (~(0XFFEF)))>>5
//------------------------------------------------------------------------------------------
#define get_UCB2IFG_UCRXIFG        (UCB2IFG & (~(0XFFFE)))>>0
#define get_UCB2IFG_UCTXIFG        (UCB2IFG & (~(0XFFFD)))>>1
#define get_UCB2IFG_UCSTTIFG       (UCB2IFG & (~(0XFFFB)))>>2
#define get_UCB2IFG_UCSTPIFG       (UCB2IFG & (~(0XFFF7)))>>3
#define get_UCB2IFG_UCALIFG        (UCB2IFG & (~(0XFFEF)))>>4
#define get_UCB2IFG_UCNACKIFG      (UCB2IFG & (~(0XFFDF)))>>5
#define get_UCB2IFG                (UCB2IFG & (~(0XFFC0)))
//------------------------------------------------------------------------------------------
#define get_UCB2IV                 (UCB2IV & ((0X000E)))>>0
//UCI_B2 结束 ##############################################################################
//UCI_B3 开始 ##############################################################################
#define put_UCB3CTL0_UCSYNC(x)     UCB3CTL0=(UCB3CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB3CTL0_UCSYNC        (UCB3CTL0 & (~(0XFFFE)))>>0
#define put_UCB3CTL0_UCMODE(x)     UCB3CTL0=(UCB3CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_UCB3CTL0_UCMODE        (UCB3CTL0 & (~(0XFFF9)))>>1
#define put_UCB3CTL0_UCMST(x)      UCB3CTL0=(UCB3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB3CTL0_UCMST         (UCB3CTL0 & (~(0XFFF7)))>>3
#define put_UCB3CTL0_UCMM(x)       UCB3CTL0=(UCB3CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB3CTL0_UCMM          (UCB3CTL0 & (~(0XFFDF)))>>5
#define put_UCB3CTL0_UCSLA10(x)    UCB3CTL0=(UCB3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB3CTL0_UCSLA10       (UCB3CTL0 & (~(0XFFBF)))>>6
#define put_UCB3CTL0_UCA10(x)      UCB3CTL0=(UCB3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_UCB3CTL0_UCA10         (UCB3CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_UCB3CTL1_UCSWRST(x)    UCB3CTL1=(UCB3CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB3CTL1_UCSWRST       (UCB3CTL1 & (~(0XFFFE)))>>0
#define put_UCB3CTL1_UCTXSTT(x)    UCB3CTL1=(UCB3CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB3CTL1_UCTXSTT       (UCB3CTL1 & (~(0XFFFD)))>>1
#define put_UCB3CTL1_UCTXSTP(x)    UCB3CTL1=(UCB3CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB3CTL1_UCTXSTP       (UCB3CTL1 & (~(0XFFFB)))>>2
#define put_UCB3CTL1_UCTXNACK(x)   UCB3CTL1=(UCB3CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB3CTL1_UCTXNACK      (UCB3CTL1 & (~(0XFFF7)))>>3
#define put_UCB3CTL1_UCTR(x)       UCB3CTL1=(UCB3CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB3CTL1_UCTR          (UCB3CTL1 & (~(0XFFEF)))>>4
#define put_UCB3CTL1_UCSSEL(x)     UCB3CTL1=(UCB3CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_UCB3CTL1_UCSSEL        (UCB3CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_UCB3BRW(x)             UCB3BRW=(UCB3BRW & 0X0000) | (x & 0XFFFF)
#define get_UCB3BRW                (UCB3BRW & (~(0X0000)))
//------------------------------------------------------------------------------------------
#define put_UCB3STAT_UCBBUSY       UCB3STAT=(UCB3STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB3STAT_UCBBUSY       (UCB3STAT & (~(0XFFEF)))>>4
#define put_UCB3STAT_UCGC(x)       UCB3STAT=(UCB3STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_UCB3STAT_UCGC          (UCB3STAT & (~(0XFFDF)))>>5
#define put_UCB3STAT_UCSCLLOW(x)   UCB3STAT=(UCB3STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_UCB3STAT_UCSCLLOW      (UCB3STAT & (~(0XFFBF)))>>6
//------------------------------------------------------------------------------------------
#define get_UCB3RXBUF              UCB3RXBUF
#define get_UCB3_RXBUF             UCB3RXBUF
//------------------------------------------------------------------------------------------
#define put_UCB3TXBUF(x)           UCB3TXBUF=x
#define put_UCB3_TXBUF(x)          UCB3TXBUF=x
#define get_UCB3TXBUF              UCB3TXBUF
#define get_UCB3_TXBUF             UCB3TXBUF
//------------------------------------------------------------------------------------------
#define put_UCB3I2COA_I2COA(x)     UCB3I2COA=(UCB3I2COA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB3I2COA_I2COA        (UCB3I2COA & (~(0XFC00)))>>0
#define put_UCB3I2COA_UCGCEN(x)    UCB3I2COA=(UCB3I2COA & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_UCB3I2COA_UCGCEN       (UCB3I2COA & (~(0X7FFF)))>>15
//------------------------------------------------------------------------------------------
#define put_UCB3I2CSA_I2CSA(x)     UCB3I2CSA=(UCB3I2CSA & 0XFC00) | ((x & 0X03FF) <<0)
#define get_UCB3I2CSA_I2CSA        (UCB3I2CSA & (~(0XFC00)))>>0
//------------------------------------------------------------------------------------------
#define put_UCB3IE_UCRXIE(x)       UCB3IE=(UCB3IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_UCB3IE_UCRXIE          (UCB3IE & (~(0XFFFE)))>>0
#define put_UCB3IE_UCTXIE(x)       UCB3IE=(UCB3IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_UCB3IE_UCTXIE          (UCB3IE & (~(0XFFFD)))>>1
#define put_UCB3IE_UCSTTIE(x)      UCB3IE=(UCB3IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_UCB3IE_UCSTTIE         (UCB3IE & (~(0XFFFB)))>>2
#define put_UCB3IE_UCSTPIE(x)      UCB3IE=(UCB3IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_UCB3IE_UCSTPIE         (UCB3IE & (~(0XFFF7)))>>3
#define put_UCB3IE_UCALIE(x)       UCB3IE=(UCB3IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_UCB3IE_UCALIE          (UCB3IE & (~(0XFFEF)))>>4
#define put_UCB3IE_UCNACKIE(x)     UCB3IE=(UCB3IE & 0XFFEF) | ((x & 0X0001) <<5)
#define get_UCB3IE_UCNACKIE        (UCB3IE & (~(0XFFEF)))>>5
//------------------------------------------------------------------------------------------
#define get_UCB3IFG_UCRXIFG        (UCB3IFG & (~(0XFFFE)))>>0
#define get_UCB3IFG_UCTXIFG        (UCB3IFG & (~(0XFFFD)))>>1
#define get_UCB3IFG_UCSTTIFG       (UCB3IFG & (~(0XFFFB)))>>2
#define get_UCB3IFG_UCSTPIFG       (UCB3IFG & (~(0XFFF7)))>>3
#define get_UCB3IFG_UCALIFG        (UCB3IFG & (~(0XFFEF)))>>4
#define get_UCB3IFG_UCNACKIFG      (UCB3IFG & (~(0XFFDF)))>>5
#define get_UCB3IFG                (UCB3IFG & (~(0XFFC0)))
//------------------------------------------------------------------------------------------
#define get_UCB3IV                 (UCB3IV & ((0X000E)))>>0
//UCI_B3 结束 ##############################################################################
//*******************以上之内容适合于对照寄存器设计IIC应用程序*****************************
//*******************以下之内容适合于对照寄存器设计SPI(A)应用程序*****************************
//UCI_A0 开始 ##############################################################################
#define put_SPI_A0_UCSYNC(x)     UCA0CTL0=(UCA0CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCSYNC        (UCA0CTL0 & (~(0XFFFE)))>>0
#define put_SPI_A0_UCMODE(x)     UCA0CTL0=(UCA0CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_A0_UCMODE        (UCA0CTL0 & (~(0XFFF9)))>>1
#define put_SPI_A0_UCSPB(x)      UCA0CTL0=(UCA0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A0_UCSPB         (UCA0CTL0 & (~(0XFFF7)))>>3
#define put_SPI_A0_UCMST(x)      UCA0CTL0=(UCA0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A0_UCMST         (UCA0CTL0 & (~(0XFFF7)))>>3
#define put_SPI_A0_UC7BIT(x)     UCA0CTL0=(UCA0CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A0_UC7BIT        (UCA0CTL0 & (~(0XFFEF)))>>4
#define put_SPI_A0_UCMSB(x)      UCA0CTL0=(UCA0CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A0_UCMSB         (UCA0CTL0 & (~(0XFFDF)))>>5
#define put_SPI_A0_UCPAR(x)      UCA0CTL0=(UCA0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A0_UCPAR         (UCA0CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A0_UCCKPL(x)     UCA0CTL0=(UCA0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A0_UCCKPL        (UCA0CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A0_UCPEN(x)      UCA0CTL0=(UCA0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A0_UCPEN         (UCA0CTL0 & (~(0XFF7F)))>>7
#define put_SPI_A0_UCCKPH(x)     UCA0CTL0=(UCA0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A0_UCCKPH        (UCA0CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_A0_UCSWRST(x)    UCA0CTL1=(UCA0CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCSWRST       (UCA0CTL1 & (~(0XFFFE)))>>0
#define put_SPI_A0_UCTXBRK(x)    UCA0CTL1=(UCA0CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A0_UCTXBRK       (UCA0CTL1 & (~(0XFFFD)))>>1
#define put_SPI_A0_UCTXADDR(x)   UCA0CTL1=(UCA0CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A0_UCTXADDR      (UCA0CTL1 & (~(0XFFFB)))>>2
#define put_SPI_A0_UCDORM(x)     UCA0CTL1=(UCA0CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A0_UCDORM        (UCA0CTL1 & (~(0XFFF7)))>>3
#define put_SPI_A0_UCBRKIE(x)    UCA0CTL1=(UCA0CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A0_UCBRKIE       (UCA0CTL1 & (~(0XFFEF)))>>4
#define put_SPI_A0_UCRXEIE(x)    UCA0CTL1=(UCA0CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A0_UCRXEIE       (UCA0CTL1 & (~(0XFFDF)))>>5
#define put_SPI_A0_UCSSEL(x)     UCA0CTL1=(UCA0CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_A0_UCSSEL        (UCA0CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_A0_BRW(x)        UCA0BRW=(UCA0BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A0_BRW           (UCA0BRW & (~(0X0000)))
#define put_SPI_A0_UCBRW(x)      UCA0BRW=(UCA0BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A0_UCBRW         (UCA0BRW & (~(0X0000)))
#define put_SPI_A0_UCxBR(x)      UCA0BRW=(UCA0BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A0_UCxBR         (UCA0BRW & (~(0X0000)))
#define put_SPI_A0_BR0(x)        UCA0BR0=(UCA0BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A0_BR0           (UCA0BR0 & (~(0X00FF)))
#define put_SPI_A0_UCxBR0(x)     UCA0BR0=(UCA0BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A0_UCxBR0        (UCA0BR0 & (~(0X00FF)))
#define put_SPI_A0_BR1(x)        UCA0BR1=(UCA0BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A0_BR1           (UCA0BR1 & (~(0X00FF)))
#define put_SPI_A0_UCxBR1(x)     UCA0BR1=(UCA0BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A0_UCxBR1        (UCA0BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_A0_UCOS16(x)     UCA0MCTL=(UCA0MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCOS16        (UCA0MCTL & (~(0XFFFE)))>>0
#define put_SPI_A0_UCBRS(x)      UCA0MCTL=(UCA0MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_A0_UCBRS         (UCA0MCTL & (~(0XFFF1)))>>1
#define put_SPI_A0_UCBRF(x)      UCA0MCTL=(UCA0MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_A0_UCBRF         (UCA0MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A0_UCBUSY(x)   UCA0STAT=(UCA0STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCBUSY      (UCA0STAT & (~(0XFFFE)))>>0
#define put_SPI_A0_UCIDLE(x)   UCA0STAT=(UCA0STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A0_UCIDLE      (UCA0STAT & (~(0XFFFD)))>>1
#define put_SPI_A0_UCRXERR(x)  UCA0STAT=(UCA0STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A0_UCRXERR     (UCA0STAT & (~(0XFFFB)))>>2
#define put_SPI_A0_UCBRK(x)    UCA0STAT=(UCA0STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A0_UCBRK       (UCA0STAT & (~(0XFFF7)))>>3
#define put_SPI_A0_UCPE(x)     UCA0STAT=(UCA0STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A0_UCPE        (UCA0STAT & (~(0XFFEF)))>>4
#define put_SPI_A0_UCOE(x)     UCA0STAT=(UCA0STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A0_UCOE        (UCA0STAT & (~(0XFFDF)))>>5
#define put_SPI_A0_UCFE(x)     UCA0STAT=(UCA0STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A0_UCFE        (UCA0STAT & (~(0XFFBF)))>>6
#define put_SPI_A0_UCLISTEN(x) UCA0STAT=(UCA0STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A0_UCLISTEN    (UCA0STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_A0_RXBUF         UCA0RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A0_TXBUF(x)      UCA0TXBUF=x
#define get_SPI_A0_TXBUF         UCA0TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A0_UCIREN(x)     UCA0IRTCTL=(UCA0IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCIREN        (UCA0IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_A0_UCIRTXCLK(x)  UCA0IRTCTL=(UCA0IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A0_UCIRTXCLK     (UCA0IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_A0_UCIRTXPL(x)   UCA0IRTCTL=(UCA0IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A0_UCIRTXPL      (UCA0IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A0_UCIRRXFE(x)   UCA0IRRCTL=(UCA0IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCIRRXFE      (UCA0IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_A0_UCIRRXPL(x)   UCA0IRRCTL=(UCA0IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A0_UCIRRXPL      (UCA0IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_A0_UCIRRXFL(x)   UCA0IRRCTL=(UCA0IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A0_UCIRRXFL      (UCA0IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A0_UCABDEN(x)    UCA0ABCTL=(UCA0ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCABDEN       (UCA0ABCTL & (~(0XFFFE)))>>0
#define put_SPI_A0_UCBTOE(x)     UCA0ABCTL=(UCA0ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A0_UCBTOE        (UCA0ABCTL & (~(0XFFFB)))>>2
#define put_SPI_A0_UCSTOE(x)     UCA0ABCTL=(UCA0ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A0_UCSTOE        (UCA0ABCTL & (~(0XFFF7)))>>3
#define put_SPI_A0_UCDELIM(x)    UCA0ABCTL=(UCA0ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_A0_UCDELIM       (UCA0ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A0_UCRXIE(x)     UCA0IE=(UCA0IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCRXIE        (UCA0IE & (~(0XFFFE)))>>0
#define put_SPI_A0_UCTXIE(x)     UCA0IE=(UCA0IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A0_UCTXIE        (UCA0IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_A0_UCRXIFG(x)  UCA0IFG=(UCA0IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A0_UCRXIFG       (UCA0IFG & (~(0XFFFE)))>>0
#define get_SPI_A0_UCxRXIFG      (UCA0IFG & (~(0XFFFE)))>>0
//#define put_SPI_A0_UCTXIFG(x)  UCA0IFG=(UCA0IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A0_UCTXIFG       (UCA0IFG & (~(0XFFFD)))>>1
#define get_SPI_A0_UCxTXIFG      (UCA0IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_A0_IV            (UCA0IV & ((0X0006)))>>0
//UCI_A0 结束 ##############################################################################
//UCI_A1 开始 ##############################################################################
#define put_SPI_A1_UCSYNC(x)     UCA1CTL0=(UCA1CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCSYNC        (UCA1CTL0 & (~(0XFFFE)))>>0
#define put_SPI_A1_UCMODE(x)     UCA1CTL0=(UCA1CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_A1_UCMODE        (UCA1CTL0 & (~(0XFFF9)))>>1
#define put_SPI_A1_UCSPB(x)      UCA1CTL0=(UCA1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A1_UCSPB         (UCA1CTL0 & (~(0XFFF7)))>>1
#define put_SPI_A1_UCMST(x)      UCA1CTL0=(UCA1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A1_UCMST         (UCA1CTL0 & (~(0XFFF7)))>>1
#define put_SPI_A1_UC7BIT(x)     UCA1CTL0=(UCA1CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A1_UC7BIT        (UCA1CTL0 & (~(0XFFEF)))>>1
#define put_SPI_A1_UCMSB(x)      UCA1CTL0=(UCA1CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A1_UCMSB         (UCA1CTL0 & (~(0XFFDF)))>>5
#define put_SPI_A1_UCPAR(x)      UCA1CTL0=(UCA1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A1_UCPAR         (UCA1CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A1_UCCKPL(x)     UCA1CTL0=(UCA1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A1_UCCKPL        (UCA1CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A1_UCPEN(x)      UCA1CTL0=(UCA1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A1_UCPEN         (UCA1CTL0 & (~(0XFF7F)))>>7
#define put_SPI_A1_UCCKPH(x)     UCA1CTL0=(UCA1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A1_UCCKPH        (UCA1CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_A1_UCSWRST(x)    UCA1CTL1=(UCA1CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCSWRST       (UCA1CTL1 & (~(0XFFFE)))>>0
#define put_SPI_A1_UCTXBRK(x)    UCA1CTL1=(UCA1CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A1_UCTXBRK       (UCA1CTL1 & (~(0XFFFD)))>>1
#define put_SPI_A1_UCTXADDR(x)   UCA1CTL1=(UCA1CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A1_UCTXADDR      (UCA1CTL1 & (~(0XFFFB)))>>2
#define put_SPI_A1_UCDORM(x)     UCA1CTL1=(UCA1CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A1_UCDORM        (UCA1CTL1 & (~(0XFFF7)))>>3
#define put_SPI_A1_UCBRKIE(x)    UCA1CTL1=(UCA1CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A1_UCBRKIE       (UCA1CTL1 & (~(0XFFEF)))>>4
#define put_SPI_A1_UCRXEIE(x)    UCA1CTL1=(UCA1CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A1_UCRXEIE       (UCA1CTL1 & (~(0XFFDF)))>>5
#define put_SPI_A1_UCSSEL(x)     UCA1CTL1=(UCA1CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_A1_UCSSEL        (UCA1CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_A1_BRW(x)        UCA1BRW=(UCA1BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A1_BRW           (UCA1BRW & (~(0X0000)))
#define put_SPI_A1_UCBRW(x)      UCA1BRW=(UCA1BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A1_UCBRW         (UCA1BRW & (~(0X0000)))
#define put_SPI_A1_UCxBR(x)      UCA1BRW=(UCA1BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A1_UCxBR         (UCA1BRW & (~(0X0000)))
#define put_SPI_A1_BR0(x)        UCA1BR0=(UCA1BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A1_BR0           (UCA1BR0 & (~(0X00FF)))
#define put_SPI_A1_UCxBR0(x)     UCA1BR0=(UCA1BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A1_UCxBR0        (UCA1BR0 & (~(0X00FF)))
#define put_SPI_A1_BR1(x)        UCA1BR1=(UCA1BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A1_BR1           (UCA1BR1 & (~(0X00FF)))
#define put_SPI_A1_UCxBR1(x)     UCA1BR1=(UCA1BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A1_UCxBR1        (UCA1BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_A1_UCOS16(x)     UCA1MCTL=(UCA1MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCOS16        (UCA1MCTL & (~(0XFFFE)))>>0
#define put_SPI_A1_UCBRS(x)      UCA1MCTL=(UCA1MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_A1_UCBRS         (UCA1MCTL & (~(0XFFF1)))>>1
#define put_SPI_A1_UCBRF(x)      UCA1MCTL=(UCA1MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_A1_UCBRF         (UCA1MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A1_UCBUSY(x)     UCA1STAT=(UCA1STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCBUSY        (UCA1STAT & (~(0XFFFE)))>>0
#define put_SPI_A1_UCIDLE(x)     UCA1STAT=(UCA1STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A1_UCIDLE        (UCA1STAT & (~(0XFFFD)))>>1
#define put_SPI_A1_UCRXERR(x)    UCA1STAT=(UCA1STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A1_UCRXERR       (UCA1STAT & (~(0XFFFB)))>>2
#define put_SPI_A1_UCBRK(x)      UCA1STAT=(UCA1STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A1_UCBRK         (UCA1STAT & (~(0XFFF7)))>>3
#define put_SPI_A1_UCPE(x)       UCA1STAT=(UCA1STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A1_UCPE          (UCA1STAT & (~(0XFFEF)))>>4
#define put_SPI_A1_UCOE(x)       UCA1STAT=(UCA1STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A1_UCOE          (UCA1STAT & (~(0XFFDF)))>>5
#define put_SPI_A1_UCFE(x)       UCA1STAT=(UCA1STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A1_UCFE          (UCA1STAT & (~(0XFFBF)))>>6
#define put_SPI_A1_UCLISTEN(x)   UCA1STAT=(UCA1STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A1_UCLISTEN      (UCA1STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_A1_RXBUF         UCA1RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A1_TXBUF(x)      UCA1TXBUF=x
#define get_SPI_A1_TXBUF         UCA1TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A1_UCIREN(x)     UCA1IRTCTL=(UCA1IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCIREN        (UCA1IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_A1_UCIRTXCLK(x)  UCA1IRTCTL=(UCA1IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A1_UCIRTXCLK     (UCA1IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_A1_UCIRTXPL(x)   UCA1IRTCTL=(UCA1IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A1_UCIRTXPL      (UCA1IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A1_UCIRRXFE(x)   UCA1IRRCTL=(UCA1IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCIRRXFE      (UCA1IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_A1_UCIRRXPL(x)   UCA1IRRCTL=(UCA1IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A1_UCIRRXPL      (UCA1IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_A1_UCIRRXFL(x)   UCA1IRRCTL=(UCA1IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A1_UCIRRXFL      (UCA1IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A1_UCABDEN(x)    UCA1ABCTL=(UCA1ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCABDEN       (UCA1ABCTL & (~(0XFFFE)))>>0
#define put_SPI_A1_UCBTOE(x)     UCA1ABCTL=(UCA1ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A1_UCBTOE        (UCA1ABCTL & (~(0XFFFB)))>>2
#define put_SPI_A1_UCSTOE(x)     UCA1ABCTL=(UCA1ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A1_UCSTOE        (UCA1ABCTL & (~(0XFFF7)))>>3
#define put_SPI_A1_UCDELIM(x)    UCA1ABCTL=(UCA1ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_A1_UCDELIM       (UCA1ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A1_UCRXIE(x)     UCA1IE=(UCA1IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCRXIE        (UCA1IE & (~(0XFFFE)))>>0
#define put_SPI_A1_UCTXIE(x)     UCA1IE=(UCA1IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A1_UCTXIE        (UCA1IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_A1_UCRXIFG(x)  UCA1IFG=(UCA1IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A1_UCRXIFG       (UCA1IFG & (~(0XFFFE)))>>0
#define get_SPI_A1_UCxRXIFG      (UCA1IFG & (~(0XFFFE)))>>0
//#define put_SPI_A1_UCTXIFG(x)  UCA1IFG=(UCA1IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A1_UCTXIFG       (UCA1IFG & (~(0XFFFD)))>>1
#define get_SPI_A1_UCxTXIFG      (UCA1IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_A1_IV            (UCA1IV & ((0X0006)))>>0
//UCI_A1 结束 ##############################################################################
//UCI_A2 开始 ##############################################################################
#define put_SPI_A2_UCSYNC(x)     UCA2CTL0=(UCA2CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCSYNC        (UCA2CTL0 & (~(0XFFFE)))>>0
#define put_SPI_A2_UCMODE(x)     UCA2CTL0=(UCA2CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_A2_UCMODE        (UCA2CTL0 & (~(0XFFF9)))>>1
#define put_SPI_A2_UCSPB(x)      UCA2CTL0=(UCA2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A2_UCSPB         (UCA2CTL0 & (~(0XFFF7)))>>1
#define put_SPI_A2_UCMST(x)      UCA2CTL0=(UCA2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A2_UCMST         (UCA2CTL0 & (~(0XFFF7)))>>1
#define put_SPI_A2_UC7BIT(x)     UCA2CTL0=(UCA2CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A2_UC7BIT        (UCA2CTL0 & (~(0XFFEF)))>>1
#define put_SPI_A2_UCMSB(x)      UCA2CTL0=(UCA2CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A2_UCMSB         (UCA2CTL0 & (~(0XFFDF)))>>5
#define put_SPI_A2_UCPAR(x)      UCA2CTL0=(UCA2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A2_UCPAR         (UCA2CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A2_UCCKPL(x)     UCA2CTL0=(UCA2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A2_UCCKPL        (UCA2CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A2_UCPEN(x)      UCA2CTL0=(UCA2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A2_UCPEN         (UCA2CTL0 & (~(0XFF7F)))>>7
#define put_SPI_A2_UCCKPH(x)     UCA2CTL0=(UCA2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A2_UCCKPH        (UCA2CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_A2_UCSWRST(x)    UCA2CTL1=(UCA2CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCSWRST       (UCA2CTL1 & (~(0XFFFE)))>>0
#define put_SPI_A2_UCTXBRK(x)    UCA2CTL1=(UCA2CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A2_UCTXBRK       (UCA2CTL1 & (~(0XFFFD)))>>1
#define put_SPI_A2_UCTXADDR(x)   UCA2CTL1=(UCA2CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A2_UCTXADDR      (UCA2CTL1 & (~(0XFFFB)))>>2
#define put_SPI_A2_UCDORM(x)     UCA2CTL1=(UCA2CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A2_UCDORM        (UCA2CTL1 & (~(0XFFF7)))>>3
#define put_SPI_A2_UCBRKIE(x)    UCA2CTL1=(UCA2CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A2_UCBRKIE       (UCA2CTL1 & (~(0XFFEF)))>>4
#define put_SPI_A2_UCRXEIE(x)    UCA2CTL1=(UCA2CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A2_UCRXEIE       (UCA2CTL1 & (~(0XFFDF)))>>5
#define put_SPI_A2_UCSSEL(x)     UCA2CTL1=(UCA2CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_A2_UCSSEL        (UCA2CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_A2_BRW(x)        UCA2BRW=(UCA2BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A2_BRW           (UCA2BRW & (~(0X0000)))
#define put_SPI_A2_UCBRW(x)      UCA2BRW=(UCA2BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A2_UCBRW         (UCA2BRW & (~(0X0000)))
#define put_SPI_A2_UCxBR(x)      UCA2BRW=(UCA2BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A2_UCxBR         (UCA2BRW & (~(0X0000)))
#define put_SPI_A2_BR0(x)        UCA2BR0=(UCA2BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A2_BR0           (UCA2BR0 & (~(0X00FF)))
#define put_SPI_A2_UCxBR0(x)     UCA2BR0=(UCA2BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A2_UCxBR0        (UCA2BR0 & (~(0X00FF)))
#define put_SPI_A2_BR1(x)        UCA2BR1=(UCA2BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A2_BR1           (UCA2BR1 & (~(0X00FF)))
#define put_SPI_A2_UCxBR1(x)     UCA2BR1=(UCA2BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A2_UCxBR1        (UCA2BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_A2_UCOS16(x)     UCA2MCTL=(UCA2MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCOS16        (UCA2MCTL & (~(0XFFFE)))>>0
#define put_SPI_A2_UCBRS(x)      UCA2MCTL=(UCA2MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_A2_UCBRS         (UCA2MCTL & (~(0XFFF1)))>>1
#define put_SPI_A2_UCBRF(x)      UCA2MCTL=(UCA2MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_A2_UCBRF         (UCA2MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A2_UCBUSY(x)     UCA2STAT=(UCA2STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCBUSY        (UCA2STAT & (~(0XFFFE)))>>0
#define put_SPI_A2_UCIDLE(x)     UCA2STAT=(UCA2STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A2_UCIDLE        (UCA2STAT & (~(0XFFFD)))>>1
#define put_SPI_A2_UCRXERR(x)    UCA2STAT=(UCA2STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A2_UCRXERR       (UCA2STAT & (~(0XFFFB)))>>2
#define put_SPI_A2_UCBRK(x)      UCA2STAT=(UCA2STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A2_UCBRK         (UCA2STAT & (~(0XFFF7)))>>3
#define put_SPI_A2_UCPE(x)       UCA2STAT=(UCA2STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A2_UCPE          (UCA2STAT & (~(0XFFEF)))>>4
#define put_SPI_A2_UCOE(x)       UCA2STAT=(UCA2STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A2_UCOE          (UCA2STAT & (~(0XFFDF)))>>5
#define put_SPI_A2_UCFE(x)       UCA2STAT=(UCA2STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A2_UCFE          (UCA2STAT & (~(0XFFBF)))>>6
#define put_SPI_A2_UCLISTEN(x)   UCA2STAT=(UCA2STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A2_UCLISTEN      (UCA2STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_A2_RXBUF         UCA2RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A2_TXBUF(x)      UCA2TXBUF=x
#define get_SPI_A2_TXBUF         UCA2TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A2_UCIREN(x)     UCA2IRTCTL=(UCA2IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCIREN        (UCA2IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_A2_UCIRTXCLK(x)  UCA2IRTCTL=(UCA2IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A2_UCIRTXCLK     (UCA2IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_A2_UCIRTXPL(x)   UCA2IRTCTL=(UCA2IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A2_UCIRTXPL      (UCA2IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A2_UCIRRXFE(x)   UCA2IRRCTL=(UCA2IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCIRRXFE      (UCA2IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_A2_UCIRRXPL(x)   UCA2IRRCTL=(UCA2IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A2_UCIRRXPL      (UCA2IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_A2_UCIRRXFL(x)   UCA2IRRCTL=(UCA2IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A2_UCIRRXFL      (UCA2IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A2_UCABDEN(x)    UCA2ABCTL=(UCA2ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCABDEN       (UCA2ABCTL & (~(0XFFFE)))>>0
#define put_SPI_A2_UCBTOE(x)     UCA2ABCTL=(UCA2ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A2_UCBTOE        (UCA2ABCTL & (~(0XFFFB)))>>2
#define put_SPI_A2_UCSTOE(x)     UCA2ABCTL=(UCA2ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A2_UCSTOE        (UCA2ABCTL & (~(0XFFF7)))>>3
#define put_SPI_A2_UCDELIM(x)    UCA2ABCTL=(UCA2ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_A2_UCDELIM       (UCA2ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A2_UCRXIE(x)     UCA2IE=(UCA2IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCRXIE        (UCA2IE & (~(0XFFFE)))>>0
#define put_SPI_A2_UCTXIE(x)     UCA2IE=(UCA2IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A2_UCTXIE        (UCA2IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_A2_UCRXIFG(x)  UCA2IFG=(UCA2IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A2_UCRXIFG       (UCA2IFG & (~(0XFFFE)))>>0
#define get_SPI_A2_UCxRXIFG      (UCA2IFG & (~(0XFFFE)))>>0
//#define put_SPI_A2_UCTXIFG(x)  UCA2IFG=(UCA2IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A2_UCTXIFG       (UCA2IFG & (~(0XFFFD)))>>1
#define get_SPI_A2_UCxTXIFG      (UCA2IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_A2_IV            (UCA2IV & ((0X0006)))>>0
//UCI_A2 结束 ##############################################################################
//UCI_A3 开始 ##############################################################################
#define put_SPI_A3_UCSYNC(x)     UCA3CTL0=(UCA3CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCSYNC        (UCA3CTL0 & (~(0XFFFE)))>>0
#define put_SPI_A3_UCMODE(x)     UCA3CTL0=(UCA3CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_A3_UCMODE        (UCA3CTL0 & (~(0XFFF9)))>>1
#define put_SPI_A3_UCSPB(x)      UCA3CTL0=(UCA3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A3_UCSPB         (UCA3CTL0 & (~(0XFFF7)))>>3
#define put_SPI_A3_UCMST(x)      UCA3CTL0=(UCA3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A3_UCMST         (UCA3CTL0 & (~(0XFFF7)))>>3
#define put_SPI_A3_UC7BIT(x)     UCA3CTL0=(UCA3CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A3_UC7BIT        (UCA3CTL0 & (~(0XFFEF)))>>4
#define put_SPI_A3_UCMSB(x)      UCA3CTL0=(UCA3CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A3_UCMSB         (UCA3CTL0 & (~(0XFFDF)))>>5
#define put_SPI_A3_UCPAR(x)      UCA3CTL0=(UCA3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A3_UCPAR         (UCA3CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A3_UCCKPL(x)     UCA3CTL0=(UCA3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A3_UCCKPL        (UCA3CTL0 & (~(0XFFBF)))>>6
#define put_SPI_A3_UCPEN(x)      UCA3CTL0=(UCA3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A3_UCPEN         (UCA3CTL0 & (~(0XFF7F)))>>7
#define put_SPI_A3_UCCKPH(x)     UCA3CTL0=(UCA3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A3_UCCKPH        (UCA3CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_A3_UCSWRST(x)    UCA3CTL1=(UCA3CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCSWRST       (UCA3CTL1 & (~(0XFFFE)))>>0
#define put_SPI_A3_UCTXBRK(x)    UCA3CTL1=(UCA3CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A3_UCTXBRK       (UCA3CTL1 & (~(0XFFFD)))>>1
#define put_SPI_A3_UCTXADDR(x)   UCA3CTL1=(UCA3CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A3_UCTXADDR      (UCA3CTL1 & (~(0XFFFB)))>>2
#define put_SPI_A3_UCDORM(x)     UCA3CTL1=(UCA3CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A3_UCDORM        (UCA3CTL1 & (~(0XFFF7)))>>3
#define put_SPI_A3_UCBRKIE(x)    UCA3CTL1=(UCA3CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A3_UCBRKIE       (UCA3CTL1 & (~(0XFFEF)))>>4
#define put_SPI_A3_UCRXEIE(x)    UCA3CTL1=(UCA3CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A3_UCRXEIE       (UCA3CTL1 & (~(0XFFDF)))>>5
#define put_SPI_A3_UCSSEL(x)     UCA3CTL1=(UCA3CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_A3_UCSSEL        (UCA3CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_A3_BRW(x)        UCA3BRW=(UCA3BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A3_BRW           (UCA3BRW & (~(0X0000)))
#define put_SPI_A3_UCBRW(x)      UCA3BRW=(UCA3BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A3_UCBRW         (UCA3BRW & (~(0X0000)))
#define put_SPI_A3_UCxBR(x)      UCA3BRW=(UCA3BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_A3_UCxBR         (UCA3BRW & (~(0X0000)))
#define put_SPI_A3_BR0(x)        UCA3BR0=(UCA3BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A3_BR0           (UCA3BR0 & (~(0X00FF)))
#define put_SPI_A3_UCxBR0(x)     UCA3BR0=(UCA3BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_A3_UCxBR0        (UCA3BR0 & (~(0X00FF)))
#define put_SPI_A3_BR1(x)        UCA3BR1=(UCA3BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A3_BR1           (UCA3BR1 & (~(0X00FF)))
#define put_SPI_A3_UCxBR1(x)     UCA3BR1=(UCA3BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_A3_UCxBR1        (UCA3BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_A3_UCOS16(x)     UCA3MCTL=(UCA3MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCOS16        (UCA3MCTL & (~(0XFFFE)))>>0
#define put_SPI_A3_UCBRS(x)      UCA3MCTL=(UCA3MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_A3_UCBRS         (UCA3MCTL & (~(0XFFF1)))>>1
#define put_SPI_A3_UCBRF(x)      UCA3MCTL=(UCA3MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_A3_UCBRF         (UCA3MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A3_UCBUSY(x)     UCA3STAT=(UCA3STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCBUSY        (UCA3STAT & (~(0XFFFE)))>>0
#define put_SPI_A3_UCIDLE(x)     UCA3STAT=(UCA3STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A3_UCIDLE        (UCA3STAT & (~(0XFFFD)))>>1
#define put_SPI_A3_UCRXERR(x)    UCA3STAT=(UCA3STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A3_UCRXERR       (UCA3STAT & (~(0XFFFB)))>>2
#define put_SPI_A3_UCBRK(x)      UCA3STAT=(UCA3STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A3_UCBRK         (UCA3STAT & (~(0XFFF7)))>>3
#define put_SPI_A3_UCPE(x)       UCA3STAT=(UCA3STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_A3_UCPE          (UCA3STAT & (~(0XFFEF)))>>4
#define put_SPI_A3_UCOE(x)       UCA3STAT=(UCA3STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_A3_UCOE          (UCA3STAT & (~(0XFFDF)))>>5
#define put_SPI_A3_UCFE(x)       UCA3STAT=(UCA3STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_A3_UCFE          (UCA3STAT & (~(0XFFBF)))>>6
#define put_SPI_A3_UCLISTEN(x)   UCA3STAT=(UCA3STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_A3_UCLISTEN      (UCA3STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_A3_RXBUF         UCA3RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A3_TXBUF(x)      UCA3TXBUF=x
#define get_SPI_A3_TXBUF         UCA3TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_A3_UCIREN(x)     UCA3IRTCTL=(UCA3IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCIREN        (UCA3IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_A3_UCIRTXCLK(x)  UCA3IRTCTL=(UCA3IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A3_UCIRTXCLK     (UCA3IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_A3_UCIRTXPL(x)   UCA3IRTCTL=(UCA3IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A3_UCIRTXPL      (UCA3IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A3_UCIRRXFE(x)   UCA3IRRCTL=(UCA3IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCIRRXFE      (UCA3IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_A3_UCIRRXPL(x)   UCA3IRRCTL=(UCA3IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A3_UCIRRXPL      (UCA3IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_A3_UCIRRXFL(x)   UCA3IRRCTL=(UCA3IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_A3_UCIRRXFL      (UCA3IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_A3_UCABDEN(x)    UCA3ABCTL=(UCA3ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCABDEN       (UCA3ABCTL & (~(0XFFFE)))>>0
#define put_SPI_A3_UCBTOE(x)     UCA3ABCTL=(UCA3ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_A3_UCBTOE        (UCA3ABCTL & (~(0XFFFB)))>>2
#define put_SPI_A3_UCSTOE(x)     UCA3ABCTL=(UCA3ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_A3_UCSTOE        (UCA3ABCTL & (~(0XFFF7)))>>3
#define put_SPI_A3_UCDELIM(x)    UCA3ABCTL=(UCA3ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_A3_UCDELIM       (UCA3ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_A3_UCRXIE(x)     UCA3IE=(UCA3IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCRXIE        (UCA3IE & (~(0XFFFE)))>>0
#define put_SPI_A3_UCTXIE(x)     UCA3IE=(UCA3IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A3_UCTXIE        (UCA3IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_A3_UCRXIFG(x)  UCA3IFG=(UCA3IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_A3_UCRXIFG       (UCA3IFG & (~(0XFFFE)))>>0
#define get_SPI_A3_UCxRXIFG      (UCA3IFG & (~(0XFFFE)))>>0
//#define put_SPI_A3_UCTXIFG(x)  UCA3IFG=(UCA3IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_A3_UCTXIFG       (UCA3IFG & (~(0XFFFD)))>>1
#define get_SPI_A3_UCxTXIFG      (UCA3IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_A3_IV            (UCA3IV & ((0X0006)))>>0
//UCI_A3 结束 ##############################################################################
//*******************以上之内容适合于对照寄存器设计SPI(A)应用程序***************************
//--------------------------------------------------------------------------------------------
//*******************以下之内容适合于对照寄存器设计SPI(B)应用程序*****************************
//注意！UCAxCTL0和UCBxCTL0两者不同，后者没有UCSYNC=0的模式
//UCI_B0 开始 ##############################################################################
#define put_SPI_B0_UCSYNC(x)     UCB0CTL0=(UCB0CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCSYNC        (UCB0CTL0 & (~(0XFFFE)))>>0
#define put_SPI_B0_UCMODE(x)     UCB0CTL0=(UCB0CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_B0_UCMODE        (UCB0CTL0 & (~(0XFFF9)))>>1
#define put_SPI_B0_UCSPB(x)      UCB0CTL0=(UCB0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B0_UCSPB         (UCB0CTL0 & (~(0XFFF7)))>>3
#define put_SPI_B0_UCMST(x)      UCB0CTL0=(UCB0CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B0_UCMST         (UCB0CTL0 & (~(0XFFF7)))>>3
#define put_SPI_B0_UC7BIT(x)     UCB0CTL0=(UCB0CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B0_UC7BIT        (UCB0CTL0 & (~(0XFFEF)))>>4
#define put_SPI_B0_UCMSB(x)      UCB0CTL0=(UCB0CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B0_UCMSB         (UCB0CTL0 & (~(0XFFDF)))>>5
#define put_SPI_B0_UCPAR(x)      UCB0CTL0=(UCB0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B0_UCPAR         (UCB0CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B0_UCCKPL(x)     UCB0CTL0=(UCB0CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B0_UCCKPL        (UCB0CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B0_UCPEN(x)      UCB0CTL0=(UCB0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B0_UCPEN         (UCB0CTL0 & (~(0XFF7F)))>>7
#define put_SPI_B0_UCCKPH(x)     UCB0CTL0=(UCB0CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B0_UCCKPH        (UCB0CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_B0_UCSWRST(x)    UCB0CTL1=(UCB0CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCSWRST       (UCB0CTL1 & (~(0XFFFE)))>>0
#define put_SPI_B0_UCTXBRK(x)    UCB0CTL1=(UCB0CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B0_UCTXBRK       (UCB0CTL1 & (~(0XFFFD)))>>1
#define put_SPI_B0_UCTXADDR(x)   UCB0CTL1=(UCB0CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B0_UCTXADDR      (UCB0CTL1 & (~(0XFFFB)))>>2
#define put_SPI_B0_UCDORM(x)     UCB0CTL1=(UCB0CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B0_UCDORM        (UCB0CTL1 & (~(0XFFF7)))>>3
#define put_SPI_B0_UCBRKIE(x)    UCB0CTL1=(UCB0CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B0_UCBRKIE       (UCB0CTL1 & (~(0XFFEF)))>>4
#define put_SPI_B0_UCRXEIE(x)    UCB0CTL1=(UCB0CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B0_UCRXEIE       (UCB0CTL1 & (~(0XFFDF)))>>5
#define put_SPI_B0_UCSSEL(x)     UCB0CTL1=(UCB0CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_B0_UCSSEL        (UCB0CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_B0_BRW(x)        UCB0BRW=(UCB0BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B0_BRW           (UCB0BRW & (~(0X0000)))
#define put_SPI_B0_UCBRW(x)      UCB0BRW=(UCB0BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B0_UCBRW         (UCB0BRW & (~(0X0000)))
#define put_SPI_B0_UCxBR(x)      UCB0BRW=(UCB0BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B0_UCxBR         (UCB0BRW & (~(0X0000)))
#define put_SPI_B0_BR0(x)        UCB0BR0=(UCB0BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B0_BR0           (UCB0BR0 & (~(0X00FF)))
#define put_SPI_B0_UCxBR0(x)     UCB0BR0=(UCB0BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B0_UCxBR0        (UCB0BR0 & (~(0X00FF)))
#define put_SPI_B0_BR1(x)        UCB0BR1=(UCB0BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B0_BR1           (UCB0BR1 & (~(0X00FF)))
#define put_SPI_B0_UCxBR1(x)     UCB0BR1=(UCB0BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B0_UCxBR1        (UCB0BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_B0_UCOS16(x)     UCB0MCTL=(UCB0MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCOS16        (UCB0MCTL & (~(0XFFFE)))>>0
#define put_SPI_B0_UCBRS(x)      UCB0MCTL=(UCB0MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_B0_UCBRS         (UCB0MCTL & (~(0XFFF1)))>>1
#define put_SPI_B0_UCBRF(x)      UCB0MCTL=(UCB0MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_B0_UCBRF         (UCB0MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B0_UCBUSY(x)   UCB0STAT=(UCB0STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCBUSY      (UCB0STAT & (~(0XFFFE)))>>0
#define put_SPI_B0_UCIDLE(x)   UCB0STAT=(UCB0STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B0_UCIDLE      (UCB0STAT & (~(0XFFFD)))>>1
#define put_SPI_B0_UCRXERR(x)  UCB0STAT=(UCB0STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B0_UCRXERR     (UCB0STAT & (~(0XFFFB)))>>2
#define put_SPI_B0_UCBRK(x)    UCB0STAT=(UCB0STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B0_UCBRK       (UCB0STAT & (~(0XFFF7)))>>3
#define put_SPI_B0_UCPE(x)     UCB0STAT=(UCB0STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B0_UCPE        (UCB0STAT & (~(0XFFEF)))>>4
#define put_SPI_B0_UCOE(x)     UCB0STAT=(UCB0STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B0_UCOE        (UCB0STAT & (~(0XFFDF)))>>5
#define put_SPI_B0_UCFE(x)     UCB0STAT=(UCB0STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B0_UCFE        (UCB0STAT & (~(0XFFBF)))>>6
#define put_SPI_B0_UCLISTEN(x) UCB0STAT=(UCB0STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B0_UCLISTEN    (UCB0STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_B0_RXBUF         UCB0RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B0_TXBUF(x)      UCB0TXBUF=x
#define get_SPI_B0_TXBUF         UCB0TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B0_UCIREN(x)     UCB0IRTCTL=(UCB0IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCIREN        (UCB0IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_B0_UCIRTXCLK(x)  UCB0IRTCTL=(UCB0IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B0_UCIRTXCLK     (UCB0IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_B0_UCIRTXPL(x)   UCB0IRTCTL=(UCB0IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B0_UCIRTXPL      (UCB0IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B0_UCIRRXFE(x)   UCB0IRRCTL=(UCB0IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCIRRXFE      (UCB0IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_B0_UCIRRXPL(x)   UCB0IRRCTL=(UCB0IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B0_UCIRRXPL      (UCB0IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_B0_UCIRRXFL(x)   UCB0IRRCTL=(UCB0IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B0_UCIRRXFL      (UCB0IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B0_UCABDEN(x)    UCB0ABCTL=(UCB0ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCABDEN       (UCB0ABCTL & (~(0XFFFE)))>>0
#define put_SPI_B0_UCBTOE(x)     UCB0ABCTL=(UCB0ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B0_UCBTOE        (UCB0ABCTL & (~(0XFFFB)))>>2
#define put_SPI_B0_UCSTOE(x)     UCB0ABCTL=(UCB0ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B0_UCSTOE        (UCB0ABCTL & (~(0XFFF7)))>>3
#define put_SPI_B0_UCDELIM(x)    UCB0ABCTL=(UCB0ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_B0_UCDELIM       (UCB0ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B0_UCRXIE(x)     UCB0IE=(UCB0IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCRXIE        (UCB0IE & (~(0XFFFE)))>>0
#define put_SPI_B0_UCTXIE(x)     UCB0IE=(UCB0IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B0_UCTXIE        (UCB0IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_B0_UCRXIFG(x)  UCB0IFG=(UCB0IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B0_UCRXIFG       (UCB0IFG & (~(0XFFFE)))>>0
#define get_SPI_B0_UCxRXIFG      (UCB0IFG & (~(0XFFFE)))>>0
//#define put_SPI_B0_UCTXIFG(x)  UCB0IFG=(UCB0IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B0_UCTXIFG       (UCB0IFG & (~(0XFFFD)))>>1
#define get_SPI_B0_UCxTXIFG      (UCB0IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_B0_IV            (UCB0IV & ((0X0006)))>>0
//UCI_B0 结束 ##############################################################################
//UCI_B1 开始 ##############################################################################
#define put_SPI_B1_UCSYNC(x)     UCB1CTL0=(UCB1CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCSYNC        (UCB1CTL0 & (~(0XFFFE)))>>0
#define put_SPI_B1_UCMODE(x)     UCB1CTL0=(UCB1CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_B1_UCMODE        (UCB1CTL0 & (~(0XFFF9)))>>1
#define put_SPI_B1_UCSPB(x)      UCB1CTL0=(UCB1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B1_UCSPB         (UCB1CTL0 & (~(0XFFF7)))>>1
#define put_SPI_B1_UCMST(x)      UCB1CTL0=(UCB1CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B1_UCMST         (UCB1CTL0 & (~(0XFFF7)))>>1
#define put_SPI_B1_UC7BIT(x)     UCB1CTL0=(UCB1CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B1_UC7BIT        (UCB1CTL0 & (~(0XFFEF)))>>1
#define put_SPI_B1_UCMSB(x)      UCB1CTL0=(UCB1CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B1_UCMSB         (UCB1CTL0 & (~(0XFFDF)))>>5
#define put_SPI_B1_UCPAR(x)      UCB1CTL0=(UCB1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B1_UCPAR         (UCB1CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B1_UCCKPL(x)     UCB1CTL0=(UCB1CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B1_UCCKPL        (UCB1CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B1_UCPEN(x)      UCB1CTL0=(UCB1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B1_UCPEN         (UCB1CTL0 & (~(0XFF7F)))>>7
#define put_SPI_B1_UCCKPH(x)     UCB1CTL0=(UCB1CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B1_UCCKPH        (UCB1CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_B1_UCSWRST(x)    UCB1CTL1=(UCB1CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCSWRST       (UCB1CTL1 & (~(0XFFFE)))>>0
#define put_SPI_B1_UCTXBRK(x)    UCB1CTL1=(UCB1CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B1_UCTXBRK       (UCB1CTL1 & (~(0XFFFD)))>>1
#define put_SPI_B1_UCTXADDR(x)   UCB1CTL1=(UCB1CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B1_UCTXADDR      (UCB1CTL1 & (~(0XFFFB)))>>2
#define put_SPI_B1_UCDORM(x)     UCB1CTL1=(UCB1CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B1_UCDORM        (UCB1CTL1 & (~(0XFFF7)))>>3
#define put_SPI_B1_UCBRKIE(x)    UCB1CTL1=(UCB1CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B1_UCBRKIE       (UCB1CTL1 & (~(0XFFEF)))>>4
#define put_SPI_B1_UCRXEIE(x)    UCB1CTL1=(UCB1CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B1_UCRXEIE       (UCB1CTL1 & (~(0XFFDF)))>>5
#define put_SPI_B1_UCSSEL(x)     UCB1CTL1=(UCB1CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_B1_UCSSEL        (UCB1CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_B1_BRW(x)        UCB1BRW=(UCB1BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B1_BRW           (UCB1BRW & (~(0X0000)))
#define put_SPI_B1_UCBRW(x)      UCB1BRW=(UCB1BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B1_UCBRW         (UCB1BRW & (~(0X0000)))
#define put_SPI_B1_UCxBR(x)      UCB1BRW=(UCB1BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B1_UCxBR         (UCB1BRW & (~(0X0000)))
#define put_SPI_B1_BR0(x)        UCB1BR0=(UCB1BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B1_BR0           (UCB1BR0 & (~(0X00FF)))
#define put_SPI_B1_UCxBR0(x)     UCB1BR0=(UCB1BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B1_UCxBR0        (UCB1BR0 & (~(0X00FF)))
#define put_SPI_B1_BR1(x)        UCB1BR1=(UCB1BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B1_BR1           (UCB1BR1 & (~(0X00FF)))
#define put_SPI_B1_UCxBR1(x)     UCB1BR1=(UCB1BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B1_UCxBR1        (UCB1BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_B1_UCOS16(x)     UCB1MCTL=(UCB1MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCOS16        (UCB1MCTL & (~(0XFFFE)))>>0
#define put_SPI_B1_UCBRS(x)      UCB1MCTL=(UCB1MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_B1_UCBRS         (UCB1MCTL & (~(0XFFF1)))>>1
#define put_SPI_B1_UCBRF(x)      UCB1MCTL=(UCB1MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_B1_UCBRF         (UCB1MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B1_UCBUSY(x)     UCB1STAT=(UCB1STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCBUSY        (UCB1STAT & (~(0XFFFE)))>>0
#define put_SPI_B1_UCIDLE(x)     UCB1STAT=(UCB1STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B1_UCIDLE        (UCB1STAT & (~(0XFFFD)))>>1
#define put_SPI_B1_UCRXERR(x)    UCB1STAT=(UCB1STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B1_UCRXERR       (UCB1STAT & (~(0XFFFB)))>>2
#define put_SPI_B1_UCBRK(x)      UCB1STAT=(UCB1STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B1_UCBRK         (UCB1STAT & (~(0XFFF7)))>>3
#define put_SPI_B1_UCPE(x)       UCB1STAT=(UCB1STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B1_UCPE          (UCB1STAT & (~(0XFFEF)))>>4
#define put_SPI_B1_UCOE(x)       UCB1STAT=(UCB1STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B1_UCOE          (UCB1STAT & (~(0XFFDF)))>>5
#define put_SPI_B1_UCFE(x)       UCB1STAT=(UCB1STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B1_UCFE          (UCB1STAT & (~(0XFFBF)))>>6
#define put_SPI_B1_UCLISTEN(x)   UCB1STAT=(UCB1STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B1_UCLISTEN      (UCB1STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_B1_RXBUF         UCB1RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B1_TXBUF(x)      UCB1TXBUF=x
#define get_SPI_B1_TXBUF         UCB1TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B1_UCIREN(x)     UCB1IRTCTL=(UCB1IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCIREN        (UCB1IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_B1_UCIRTXCLK(x)  UCB1IRTCTL=(UCB1IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B1_UCIRTXCLK     (UCB1IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_B1_UCIRTXPL(x)   UCB1IRTCTL=(UCB1IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B1_UCIRTXPL      (UCB1IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B1_UCIRRXFE(x)   UCB1IRRCTL=(UCB1IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCIRRXFE      (UCB1IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_B1_UCIRRXPL(x)   UCB1IRRCTL=(UCB1IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B1_UCIRRXPL      (UCB1IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_B1_UCIRRXFL(x)   UCB1IRRCTL=(UCB1IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B1_UCIRRXFL      (UCB1IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B1_UCABDEN(x)    UCB1ABCTL=(UCB1ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCABDEN       (UCB1ABCTL & (~(0XFFFE)))>>0
#define put_SPI_B1_UCBTOE(x)     UCB1ABCTL=(UCB1ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B1_UCBTOE        (UCB1ABCTL & (~(0XFFFB)))>>2
#define put_SPI_B1_UCSTOE(x)     UCB1ABCTL=(UCB1ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B1_UCSTOE        (UCB1ABCTL & (~(0XFFF7)))>>3
#define put_SPI_B1_UCDELIM(x)    UCB1ABCTL=(UCB1ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_B1_UCDELIM       (UCB1ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B1_UCRXIE(x)     UCB1IE=(UCB1IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCRXIE        (UCB1IE & (~(0XFFFE)))>>0
#define put_SPI_B1_UCTXIE(x)     UCB1IE=(UCB1IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B1_UCTXIE        (UCB1IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_B1_UCRXIFG(x)  UCB1IFG=(UCB1IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B1_UCRXIFG       (UCB1IFG & (~(0XFFFE)))>>0
#define get_SPI_B1_UCxRXIFG      (UCB1IFG & (~(0XFFFE)))>>0
//#define put_SPI_B1_UCTXIFG(x)  UCB1IFG=(UCB1IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B1_UCTXIFG       (UCB1IFG & (~(0XFFFD)))>>1
#define get_SPI_B1_UCxTXIFG      (UCB1IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_B1_IV            (UCB1IV & ((0X0006)))>>0
//UCI_B1 结束 ##############################################################################
//UCI_B2 开始 ##############################################################################
#define put_SPI_B2_UCSYNC(x)     UCB2CTL0=(UCB2CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCSYNC        (UCB2CTL0 & (~(0XFFFE)))>>0
#define put_SPI_B2_UCMODE(x)     UCB2CTL0=(UCB2CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_B2_UCMODE        (UCB2CTL0 & (~(0XFFF9)))>>1
#define put_SPI_B2_UCSPB(x)      UCB2CTL0=(UCB2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B2_UCSPB         (UCB2CTL0 & (~(0XFFF7)))>>1
#define put_SPI_B2_UCMST(x)      UCB2CTL0=(UCB2CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B2_UCMST         (UCB2CTL0 & (~(0XFFF7)))>>1
#define put_SPI_B2_UC7BIT(x)     UCB2CTL0=(UCB2CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B2_UC7BIT        (UCB2CTL0 & (~(0XFFEF)))>>1
#define put_SPI_B2_UCMSB(x)      UCB2CTL0=(UCB2CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B2_UCMSB         (UCB2CTL0 & (~(0XFFDF)))>>5
#define put_SPI_B2_UCPAR(x)      UCB2CTL0=(UCB2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B2_UCPAR         (UCB2CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B2_UCCKPL(x)     UCB2CTL0=(UCB2CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B2_UCCKPL        (UCB2CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B2_UCPEN(x)      UCB2CTL0=(UCB2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B2_UCPEN         (UCB2CTL0 & (~(0XFF7F)))>>7
#define put_SPI_B2_UCCKPH(x)     UCB2CTL0=(UCB2CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B2_UCCKPH        (UCB2CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_B2_UCSWRST(x)    UCB2CTL1=(UCB2CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCSWRST       (UCB2CTL1 & (~(0XFFFE)))>>0
#define put_SPI_B2_UCTXBRK(x)    UCB2CTL1=(UCB2CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B2_UCTXBRK       (UCB2CTL1 & (~(0XFFFD)))>>1
#define put_SPI_B2_UCTXADDR(x)   UCB2CTL1=(UCB2CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B2_UCTXADDR      (UCB2CTL1 & (~(0XFFFB)))>>2
#define put_SPI_B2_UCDORM(x)     UCB2CTL1=(UCB2CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B2_UCDORM        (UCB2CTL1 & (~(0XFFF7)))>>3
#define put_SPI_B2_UCBRKIE(x)    UCB2CTL1=(UCB2CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B2_UCBRKIE       (UCB2CTL1 & (~(0XFFEF)))>>4
#define put_SPI_B2_UCRXEIE(x)    UCB2CTL1=(UCB2CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B2_UCRXEIE       (UCB2CTL1 & (~(0XFFDF)))>>5
#define put_SPI_B2_UCSSEL(x)     UCB2CTL1=(UCB2CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_B2_UCSSEL        (UCB2CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_B2_BRW(x)        UCB2BRW=(UCB2BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B2_BRW           (UCB2BRW & (~(0X0000)))
#define put_SPI_B2_UCBRW(x)      UCB2BRW=(UCB2BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B2_UCBRW         (UCB2BRW & (~(0X0000)))
#define put_SPI_B2_UCxBR(x)      UCB2BRW=(UCB2BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B2_UCxBR         (UCB2BRW & (~(0X0000)))
#define put_SPI_B2_BR0(x)        UCB2BR0=(UCB2BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B2_BR0           (UCB2BR0 & (~(0X00FF)))
#define put_SPI_B2_UCxBR0(x)     UCB2BR0=(UCB2BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B2_UCxBR0        (UCB2BR0 & (~(0X00FF)))
#define put_SPI_B2_BR1(x)        UCB2BR1=(UCB2BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B2_BR1           (UCB2BR1 & (~(0X00FF)))
#define put_SPI_B2_UCxBR1(x)     UCB2BR1=(UCB2BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B2_UCxBR1        (UCB2BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_B2_UCOS16(x)     UCB2MCTL=(UCB2MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCOS16        (UCB2MCTL & (~(0XFFFE)))>>0
#define put_SPI_B2_UCBRS(x)      UCB2MCTL=(UCB2MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_B2_UCBRS         (UCB2MCTL & (~(0XFFF1)))>>1
#define put_SPI_B2_UCBRF(x)      UCB2MCTL=(UCB2MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_B2_UCBRF         (UCB2MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B2_UCBUSY(x)     UCB2STAT=(UCB2STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCBUSY        (UCB2STAT & (~(0XFFFE)))>>0
#define put_SPI_B2_UCIDLE(x)     UCB2STAT=(UCB2STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B2_UCIDLE        (UCB2STAT & (~(0XFFFD)))>>1
#define put_SPI_B2_UCRXERR(x)    UCB2STAT=(UCB2STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B2_UCRXERR       (UCB2STAT & (~(0XFFFB)))>>2
#define put_SPI_B2_UCBRK(x)      UCB2STAT=(UCB2STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B2_UCBRK         (UCB2STAT & (~(0XFFF7)))>>3
#define put_SPI_B2_UCPE(x)       UCB2STAT=(UCB2STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B2_UCPE          (UCB2STAT & (~(0XFFEF)))>>4
#define put_SPI_B2_UCOE(x)       UCB2STAT=(UCB2STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B2_UCOE          (UCB2STAT & (~(0XFFDF)))>>5
#define put_SPI_B2_UCFE(x)       UCB2STAT=(UCB2STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B2_UCFE          (UCB2STAT & (~(0XFFBF)))>>6
#define put_SPI_B2_UCLISTEN(x)   UCB2STAT=(UCB2STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B2_UCLISTEN      (UCB2STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_B2_RXBUF         UCB2RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B2_TXBUF(x)      UCB2TXBUF=x
#define get_SPI_B2_TXBUF         UCB2TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B2_UCIREN(x)     UCB2IRTCTL=(UCB2IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCIREN        (UCB2IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_B2_UCIRTXCLK(x)  UCB2IRTCTL=(UCB2IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B2_UCIRTXCLK     (UCB2IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_B2_UCIRTXPL(x)   UCB2IRTCTL=(UCB2IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B2_UCIRTXPL      (UCB2IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B2_UCIRRXFE(x)   UCB2IRRCTL=(UCB2IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCIRRXFE      (UCB2IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_B2_UCIRRXPL(x)   UCB2IRRCTL=(UCB2IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B2_UCIRRXPL      (UCB2IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_B2_UCIRRXFL(x)   UCB2IRRCTL=(UCB2IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B2_UCIRRXFL      (UCB2IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B2_UCABDEN(x)    UCB2ABCTL=(UCB2ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCABDEN       (UCB2ABCTL & (~(0XFFFE)))>>0
#define put_SPI_B2_UCBTOE(x)     UCB2ABCTL=(UCB2ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B2_UCBTOE        (UCB2ABCTL & (~(0XFFFB)))>>2
#define put_SPI_B2_UCSTOE(x)     UCB2ABCTL=(UCB2ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B2_UCSTOE        (UCB2ABCTL & (~(0XFFF7)))>>3
#define put_SPI_B2_UCDELIM(x)    UCB2ABCTL=(UCB2ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_B2_UCDELIM       (UCB2ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B2_UCRXIE(x)     UCB2IE=(UCB2IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCRXIE        (UCB2IE & (~(0XFFFE)))>>0
#define put_SPI_B2_UCTXIE(x)     UCB2IE=(UCB2IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B2_UCTXIE        (UCB2IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_B2_UCRXIFG(x)  UCB2IFG=(UCB2IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B2_UCRXIFG       (UCB2IFG & (~(0XFFFE)))>>0
#define get_SPI_B2_UCxRXIFG      (UCB2IFG & (~(0XFFFE)))>>0
//#define put_SPI_B2_UCTXIFG(x)  UCB2IFG=(UCB2IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B2_UCTXIFG       (UCB2IFG & (~(0XFFFD)))>>1
#define get_SPI_B2_UCxTXIFG      (UCB2IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_B2_IV            (UCB2IV & ((0X0006)))>>0
//UCI_B2 结束 ##############################################################################
//UCI_B3 开始 ##############################################################################
#define put_SPI_B3_UCSYNC(x)     UCB3CTL0=(UCB3CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCSYNC        (UCB3CTL0 & (~(0XFFFE)))>>0
#define put_SPI_B3_UCMODE(x)     UCB3CTL0=(UCB3CTL0 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_SPI_B3_UCMODE        (UCB3CTL0 & (~(0XFFF9)))>>1
#define put_SPI_B3_UCSPB(x)      UCB3CTL0=(UCB3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B3_UCSPB         (UCB3CTL0 & (~(0XFFF7)))>>3
#define put_SPI_B3_UCMST(x)      UCB3CTL0=(UCB3CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B3_UCMST         (UCB3CTL0 & (~(0XFFF7)))>>3
#define put_SPI_B3_UC7BIT(x)     UCB3CTL0=(UCB3CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B3_UC7BIT        (UCB3CTL0 & (~(0XFFEF)))>>4
#define put_SPI_B3_UCMSB(x)      UCB3CTL0=(UCB3CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B3_UCMSB         (UCB3CTL0 & (~(0XFFDF)))>>5
#define put_SPI_B3_UCPAR(x)      UCB3CTL0=(UCB3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B3_UCPAR         (UCB3CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B3_UCCKPL(x)     UCB3CTL0=(UCB3CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B3_UCCKPL        (UCB3CTL0 & (~(0XFFBF)))>>6
#define put_SPI_B3_UCPEN(x)      UCB3CTL0=(UCB3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B3_UCPEN         (UCB3CTL0 & (~(0XFF7F)))>>7
#define put_SPI_B3_UCCKPH(x)     UCB3CTL0=(UCB3CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B3_UCCKPH        (UCB3CTL0 & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define put_SPI_B3_UCSWRST(x)    UCB3CTL1=(UCB3CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCSWRST       (UCB3CTL1 & (~(0XFFFE)))>>0
#define put_SPI_B3_UCTXBRK(x)    UCB3CTL1=(UCB3CTL1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B3_UCTXBRK       (UCB3CTL1 & (~(0XFFFD)))>>1
#define put_SPI_B3_UCTXADDR(x)   UCB3CTL1=(UCB3CTL1 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B3_UCTXADDR      (UCB3CTL1 & (~(0XFFFB)))>>2
#define put_SPI_B3_UCDORM(x)     UCB3CTL1=(UCB3CTL1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B3_UCDORM        (UCB3CTL1 & (~(0XFFF7)))>>3
#define put_SPI_B3_UCBRKIE(x)    UCB3CTL1=(UCB3CTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B3_UCBRKIE       (UCB3CTL1 & (~(0XFFEF)))>>4
#define put_SPI_B3_UCRXEIE(x)    UCB3CTL1=(UCB3CTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B3_UCRXEIE       (UCB3CTL1 & (~(0XFFDF)))>>5
#define put_SPI_B3_UCSSEL(x)     UCB3CTL1=(UCB3CTL1 & 0XFF3F) | ((x & 0X0003) <<6)
#define get_SPI_B3_UCSSEL        (UCB3CTL1 & (~(0XFF3F)))>>6
//------------------------------------------------------------------------------------------
#define put_SPI_B3_BRW(x)        UCB3BRW=(UCB3BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B3_BRW           (UCB3BRW & (~(0X0000)))
#define put_SPI_B3_UCBRW(x)      UCB3BRW=(UCB3BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B3_UCBRW         (UCB3BRW & (~(0X0000)))
#define put_SPI_B3_UCxBR(x)      UCB3BRW=(UCB3BRW & 0X0000) | (x & 0XFFFF)
#define get_SPI_B3_UCxBR         (UCB3BRW & (~(0X0000)))
#define put_SPI_B3_BR0(x)        UCB3BR0=(UCB3BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B3_BR0           (UCB3BR0 & (~(0X00FF)))
#define put_SPI_B3_UCxBR0(x)     UCB3BR0=(UCB3BR0 & 0X0000) | (x & 0X00FF)
#define get_SPI_B3_UCxBR0        (UCB3BR0 & (~(0X00FF)))
#define put_SPI_B3_BR1(x)        UCB3BR1=(UCB3BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B3_BR1           (UCB3BR1 & (~(0X00FF)))
#define put_SPI_B3_UCxBR1(x)     UCB3BR1=(UCB3BR1 & 0X0000) | (x & 0X00FF)
#define get_SPI_B3_UCxBR1        (UCB3BR1 & (~(0X00FF)))
//------------------------------------------------------------------------------------------
#define put_SPI_B3_UCOS16(x)     UCB3MCTL=(UCB3MCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCOS16        (UCB3MCTL & (~(0XFFFE)))>>0
#define put_SPI_B3_UCBRS(x)      UCB3MCTL=(UCB3MCTL & 0XFFF1) | ((x & 0X0003) <<1)
#define get_SPI_B3_UCBRS         (UCB3MCTL & (~(0XFFF1)))>>1
#define put_SPI_B3_UCBRF(x)      UCB3MCTL=(UCB3MCTL & 0XFF0F) | ((x & 0X0003) <<4)
#define get_SPI_B3_UCBRF         (UCB3MCTL & (~(0XFF0F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B3_UCBUSY(x)     UCB3STAT=(UCB3STAT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCBUSY        (UCB3STAT & (~(0XFFFE)))>>0
#define put_SPI_B3_UCIDLE(x)     UCB3STAT=(UCB3STAT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B3_UCIDLE        (UCB3STAT & (~(0XFFFD)))>>1
#define put_SPI_B3_UCRXERR(x)    UCB3STAT=(UCB3STAT & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B3_UCRXERR       (UCB3STAT & (~(0XFFFB)))>>2
#define put_SPI_B3_UCBRK(x)      UCB3STAT=(UCB3STAT & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B3_UCBRK         (UCB3STAT & (~(0XFFF7)))>>3
#define put_SPI_B3_UCPE(x)       UCB3STAT=(UCB3STAT & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SPI_B3_UCPE          (UCB3STAT & (~(0XFFEF)))>>4
#define put_SPI_B3_UCOE(x)       UCB3STAT=(UCB3STAT & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SPI_B3_UCOE          (UCB3STAT & (~(0XFFDF)))>>5
#define put_SPI_B3_UCFE(x)       UCB3STAT=(UCB3STAT & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SPI_B3_UCFE          (UCB3STAT & (~(0XFFBF)))>>6
#define put_SPI_B3_UCLISTEN(x)   UCB3STAT=(UCB3STAT & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SPI_B3_UCLISTEN      (UCB3STAT & (~(0XFF7F)))>>7
//------------------------------------------------------------------------------------------
#define get_SPI_B3_RXBUF         UCB3RXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B3_TXBUF(x)      UCB3TXBUF=x
#define get_SPI_B3_TXBUF         UCB3TXBUF
//------------------------------------------------------------------------------------------
#define put_SPI_B3_UCIREN(x)     UCB3IRTCTL=(UCB3IRTCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCIREN        (UCB3IRTCTL & (~(0XFFFE)))>>0
#define put_SPI_B3_UCIRTXCLK(x)  UCB3IRTCTL=(UCB3IRTCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B3_UCIRTXCLK     (UCB3IRTCTL & (~(0XFFFD)))>>1
#define put_SPI_B3_UCIRTXPL(x)   UCB3IRTCTL=(UCB3IRTCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B3_UCIRTXPL      (UCB3IRTCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B3_UCIRRXFE(x)   UCB3IRRCTL=(UCB3IRRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCIRRXFE      (UCB3IRRCTL & (~(0XFFFE)))>>0
#define put_SPI_B3_UCIRRXPL(x)   UCB3IRRCTL=(UCB3IRRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B3_UCIRRXPL      (UCB3IRRCTL & (~(0XFFFD)))>>1
#define put_SPI_B3_UCIRRXFL(x)   UCB3IRRCTL=(UCB3IRRCTL & 0XFFFC) | ((x & 0X003F) <<2)
#define get_SPI_B3_UCIRRXFL      (UCB3IRRCTL & (~(0XFFFC)))>>2
//------------------------------------------------------------------------------------------
#define put_SPI_B3_UCABDEN(x)    UCB3ABCTL=(UCB3ABCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCABDEN       (UCB3ABCTL & (~(0XFFFE)))>>0
#define put_SPI_B3_UCBTOE(x)     UCB3ABCTL=(UCB3ABCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SPI_B3_UCBTOE        (UCB3ABCTL & (~(0XFFFB)))>>2
#define put_SPI_B3_UCSTOE(x)     UCB3ABCTL=(UCB3ABCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SPI_B3_UCSTOE        (UCB3ABCTL & (~(0XFFF7)))>>3
#define put_SPI_B3_UCDELIM(x)    UCB3ABCTL=(UCB3ABCTL & 0XFF3F) | ((x & 0X0003) <<4)
#define get_SPI_B3_UCDELIM       (UCB3ABCTL & (~(0XFF3F)))>>4
//------------------------------------------------------------------------------------------
#define put_SPI_B3_UCRXIE(x)     UCB3IE=(UCB3IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCRXIE        (UCB3IE & (~(0XFFFE)))>>0
#define put_SPI_B3_UCTXIE(x)     UCB3IE=(UCB3IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B3_UCTXIE        (UCB3IE & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
//#define put_SPI_B3_UCRXIFG(x)  UCB3IFG=(UCB3IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SPI_B3_UCRXIFG       (UCB3IFG & (~(0XFFFE)))>>0
#define get_SPI_B3_UCxRXIFG      (UCB3IFG & (~(0XFFFE)))>>0
//#define put_SPI_B3_UCTXIFG(x)  UCB3IFG=(UCB3IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SPI_B3_UCTXIFG       (UCB3IFG & (~(0XFFFD)))>>1
#define get_SPI_B3_UCxTXIFG      (UCB3IFG & (~(0XFFFD)))>>1
//------------------------------------------------------------------------------------------
#define get_SPI_B3_IV            (UCB3IV & ((0X0006)))>>0
//UCI_B3 结束 ##############################################################################
//*******************以上之内容适合于对照寄存器设计SPI(B)应用程序***************************

//适合于对照寄存器编写DMA应用程序 开始 ##########################################
//DMACTL0 开始 ------------------------------------------------------------------
#define put_DMACTL0_DMA0TSEL(x)   DMACTL0=(DMACTL0 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMACTL0_DMA0TSEL      (DMACTL0 & (~(0XFFE0)))>>0
#define put_DMACTL0_DMA1TSEL(x)   DMACTL0=(DMACTL0 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMACTL0_DMA1TSEL      (DMACTL0 & (~(0XE0FF)))>>8
//DMACTL0 结束 ------------------------------------------------------------------
//DMACTL1 开始 ------------------------------------------------------------------
#define put_DMACTL1_DMA2TSEL(x)   DMACTL1=(DMACTL1 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMACTL1_DMA2TSEL      (DMACTL1 & (~(0XFFE0)))>>0
#define put_DMACTL1_DMA3TSEL(x)   DMACTL1=(DMACTL1 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMACTL1_DMA3TSEL      (DMACTL1 & (~(0XE0FF)))>>8
//DMACTL1 结束 ------------------------------------------------------------------
//DMACTL2 开始 ------------------------------------------------------------------
#define put_DMACTL2_DMA4TSEL(x)   DMACTL2=(DMACTL2 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMACTL2_DMA4TSEL      (DMACTL2 & (~(0XFFE0)))>>0
#define put_DMACTL2_DMA5TSEL(x)   DMACTL2=(DMACTL2 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMACTL2_DMA5TSEL      (DMACTL2 & (~(0XE0FF)))>>8
//DMACTL2 结束 ------------------------------------------------------------------
//DMACTL3 开始 ------------------------------------------------------------------
#define put_DMACTL3_DMA6TSEL(x)   DMACTL3=(DMACTL3 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMACTL3_DMA6TSEL      (DMACTL3 & (~(0XFFE0)))>>0
#define put_DMACTL3_DMA7TSEL(x)   DMACTL3=(DMACTL3 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMACTL3_DMA7TSEL      (DMACTL3 & (~(0XE0FF)))>>8
//DMACTL3 结束 ------------------------------------------------------------------
//DMACTL4 开始 ------------------------------------------------------------------
#define put_DMACTL4_ENNMI(x)      DMACTL4=(DMACTL4 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMACTL4_ENNMI         (DMACTL4 & (~(0XFFFE)))>>0
#define put_DMACTL4_ROUNDROBIN(x) DMACTL4=(DMACTL4 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMACTL4_ROUNDROBIN    (DMACTL4 & (~(0XFFFD)))>>1
#define put_DMACTL4_DMARMWDIS(x)  DMACTL4=(DMACTL4 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMACTL4_DMARMWDIS     (DMACTL4 & (~(0XFFFB)))>>2
//DMACTL4 结束 ------------------------------------------------------------------
//DMA0CTL 开始 ------------------------------------------------------------------
#define put_DMA0CTL_DMAREQ(x)     DMA0CTL=(DMA0CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMA0CTL_DMAREQ        (DMA0CTL & (~(0XFFFE)))>>0
#define put_DMA0CTL_DMAABORT(x)   DMA0CTL=(DMA0CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMA0CTL_DMAABORT      (DMA0CTL & (~(0XFFFD)))>>1
#define put_DMA0CTL_DMAIE(x)      DMA0CTL=(DMA0CTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMA0CTL_DMAIE         (DMA0CTL & (~(0XFFFB)))>>2
#define put_DMA0CTL_DMAIFG(x)     DMA0CTL=(DMA0CTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_DMA0CTL_DMAIFG        (DMA0CTL & (~(0XFFF7)))>>3
#define put_DMA0CTL_DMAEN(x)      DMA0CTL=(DMA0CTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_DMA0CTL_DMAEN         (DMA0CTL & (~(0XFFEF)))>>4
#define put_DMA0CTL_DMALEVEL(x)   DMA0CTL=(DMA0CTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_DMA0CTL_DMALEVEL      (DMA0CTL & (~(0XFFDF)))>>5
#define put_DMA0CTL_DMASRCBYTE(x) DMA0CTL=(DMA0CTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_DMA0CTL_DMASRCBYTE    (DMA0CTL & (~(0XFFBF)))>>6
#define put_DMA0CTL_DMADSTBYTE(x) DMA0CTL=(DMA0CTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_DMA0CTL_DMADSTBYTE    (DMA0CTL & (~(0XFF7F)))>>7
#define put_DMA0CTL_DMASRCINCR(x) DMA0CTL=(DMA0CTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_DMA0CTL_DMASRCINCR    (DMA0CTL & (~(0XFCFF)))>>8
#define put_DMA0CTL_DMADSTINCR(x) DMA0CTL=(DMA0CTL & 0XF3FF) | ((x & 0X0003) <<10)
#define get_DMA0CTL_DMADSTINCR    (DMA0CTL & (~(0XF3FF)))>>10
#define put_DMA0CTL_DMADT(x)      DMA0CTL=(DMA0CTL & 0X8FFF) | ((x & 0X0003) <<12)
#define get_DMA0CTL_DMADT         (DMA0CTL & (~(0X8FFF)))>>12
//DMA0CTL 结束 ------------------------------------------------------------------
//DMA1CTL 开始 ------------------------------------------------------------------
#define put_DMA1CTL_DMAREQ(x)     DMA1CTL=(DMA1CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMA1CTL_DMAREQ        (DMA1CTL & (~(0XFFFE)))>>0
#define put_DMA1CTL_DMAABORT(x)   DMA1CTL=(DMA1CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMA1CTL_DMAABORT      (DMA1CTL & (~(0XFFFD)))>>1
#define put_DMA1CTL_DMAIE(x)      DMA1CTL=(DMA1CTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMA1CTL_DMAIE         (DMA1CTL & (~(0XFFFB)))>>2
#define put_DMA1CTL_DMAIFG(x)     DMA1CTL=(DMA1CTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_DMA1CTL_DMAIFG        (DMA1CTL & (~(0XFFF7)))>>3
#define put_DMA1CTL_DMAEN(x)      DMA1CTL=(DMA1CTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_DMA1CTL_DMAEN         (DMA1CTL & (~(0XFFEF)))>>4
#define put_DMA1CTL_DMALEVEL(x)   DMA1CTL=(DMA1CTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_DMA1CTL_DMALEVEL      (DMA1CTL & (~(0XFFDF)))>>5
#define put_DMA1CTL_DMASRCBYTE(x) DMA1CTL=(DMA1CTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_DMA1CTL_DMASRCBYTE    (DMA1CTL & (~(0XFFBF)))>>6
#define put_DMA1CTL_DMADSTBYTE(x) DMA1CTL=(DMA1CTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_DMA1CTL_DMADSTBYTE    (DMA1CTL & (~(0XFF7F)))>>7
#define put_DMA1CTL_DMASRCINCR(x) DMA1CTL=(DMA1CTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_DMA1CTL_DMASRCINCR    (DMA1CTL & (~(0XFCFF)))>>8
#define put_DMA1CTL_DMADSTINCR(x) DMA1CTL=(DMA1CTL & 0XF3FF) | ((x & 0X0003) <<10)
#define get_DMA1CTL_DMADSTINCR    (DMA1CTL & (~(0XF3FF)))>>10
#define put_DMA1CTL_DMADT(x)      DMA1CTL=(DMA1CTL & 0X8FFF) | ((x & 0X0003) <<12)
#define get_DMA1CTL_DMADT         (DMA1CTL & (~(0X8FFF)))>>12
//DMA1CTL 结束 ------------------------------------------------------------------
//DMA2CTL 开始 ------------------------------------------------------------------
#define put_DMA2CTL_DMAREQ(x)     DMA2CTL=(DMA2CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMA2CTL_DMAREQ        (DMA2CTL & (~(0XFFFE)))>>0
#define put_DMA2CTL_DMAABORT(x)   DMA2CTL=(DMA2CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMA2CTL_DMAABORT      (DMA2CTL & (~(0XFFFD)))>>1
#define put_DMA2CTL_DMAIE(x)      DMA2CTL=(DMA2CTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMA2CTL_DMAIE         (DMA2CTL & (~(0XFFFB)))>>2
#define put_DMA2CTL_DMAIFG(x)     DMA2CTL=(DMA2CTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_DMA2CTL_DMAIFG        (DMA2CTL & (~(0XFFF7)))>>3
#define put_DMA2CTL_DMAEN(x)      DMA2CTL=(DMA2CTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_DMA2CTL_DMAEN         (DMA2CTL & (~(0XFFEF)))>>4
#define put_DMA2CTL_DMALEVEL(x)   DMA2CTL=(DMA2CTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_DMA2CTL_DMALEVEL      (DMA2CTL & (~(0XFFDF)))>>5
#define put_DMA2CTL_DMASRCBYTE(x) DMA2CTL=(DMA2CTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_DMA2CTL_DMASRCBYTE    (DMA2CTL & (~(0XFFBF)))>>6
#define put_DMA2CTL_DMADSTBYTE(x) DMA2CTL=(DMA2CTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_DMA2CTL_DMADSTBYTE    (DMA2CTL & (~(0XFF7F)))>>7
#define put_DMA2CTL_DMASRCINCR(x) DMA2CTL=(DMA2CTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_DMA2CTL_DMASRCINCR    (DMA2CTL & (~(0XFCFF)))>>8
#define put_DMA2CTL_DMADSTINCR(x) DMA2CTL=(DMA2CTL & 0XF3FF) | ((x & 0X0003) <<10)
#define get_DMA2CTL_DMADSTINCR    (DMA2CTL & (~(0XF3FF)))>>10
#define put_DMA2CTL_DMADT(x)      DMA2CTL=(DMA2CTL & 0X8FFF) | ((x & 0X0003) <<12)
#define get_DMA2CTL_DMADT         (DMA2CTL & (~(0X8FFF)))>>12
//DMA2CTL 结束 ------------------------------------------------------------------
//DMAxSA 开始 -------------------------------------------------------------------
#define put_DMA0SA(x)             DMA0SA=x
#define get_DMA0SA                DMA0SA
#define put_DMA1SA(x)             DMA1SA=x
#define get_DMA1SA                DMA1SA
#define put_DMA2SA(x)             DMA2SA=x
#define get_DMA2SA                DMA2SA
//DMAxSA 结束 -------------------------------------------------------------------
//DMAxDA 开始 -------------------------------------------------------------------
#define put_DMA0DA(x)             DMA0DA=x
#define get_DMA0DA                DMA0DA
#define put_DMA1DA(x)             DMA1DA=x
#define get_DMA1DA                DMA1DA
#define put_DMA2DA(x)             DMA2DA=x
#define get_DMA2DA                DMA2DA
//DMAxDA 结束 -------------------------------------------------------------------
//DMAxSZ 开始 -------------------------------------------------------------------
#define put_DMA0SZ(x)             DMA0SZ=x
#define get_DMA0SZ                DMA0SZ
#define put_DMA1SZ(x)             DMA1SZ=x
#define get_DMA1SZ                DMA1SZ
#define put_DMA2SZ(x)             DMA2SZ=x
#define get_DMA2SZ                DMA2SZ
//DMAxSZ 结束 -------------------------------------------------------------------
//DMAIV 开始 --------------------------------------------------------------------
#define get_DMAIV                 DMAIV & 0X003E
//DMAIV 结束 --------------------------------------------------------------------
//适合于对照寄存器编写DMA应用程序 结束 ##########################################
//-------------------------------------------------------------------------------
//适合于对照原理图编写DMA应用程序 开始 ##########################################
//DMACTL0 开始 ------------------------------------------------------------------
#define put_DMA0_DMA0TSEL(x)      DMACTL0=(DMACTL0 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA0_DMA0TSEL         (DMACTL0 & (~(0XFFE0)))>>0
#define put_DMA0TSEL(x)           DMACTL0=(DMACTL0 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA0TSEL              (DMACTL0 & (~(0XFFE0)))>>0
#define put_DMA1_DMA1TSEL(x)      DMACTL0=(DMACTL0 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA1_DMA1TSEL         (DMACTL0 & (~(0XE0FF)))>>8
#define put_DMA1TSEL(x)           DMACTL0=(DMACTL0 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA1TSEL              (DMACTL0 & (~(0XE0FF)))>>8
//DMACTL0 结束 ------------------------------------------------------------------
//DMACTL1 开始 ------------------------------------------------------------------
#define put_DMA2_DMA2TSEL(x)      DMACTL1=(DMACTL1 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA2_DMA2TSEL         (DMACTL1 & (~(0XFFE0)))>>0
#define put_DMA2TSEL(x)           DMACTL1=(DMACTL1 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA2TSEL              (DMACTL1 & (~(0XFFE0)))>>0
#define put_DMA3_DMA3TSEL(x)      DMACTL1=(DMACTL1 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA3_DMA3TSEL         (DMACTL1 & (~(0XE0FF)))>>8
#define put_DMA3TSEL(x)           DMACTL1=(DMACTL1 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA3TSEL              (DMACTL1 & (~(0XE0FF)))>>8
//DMACTL1 结束 ------------------------------------------------------------------
//DMACTL2 开始 ------------------------------------------------------------------
#define put_DMA4_DMA4TSEL(x)      DMACTL2=(DMACTL2 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA4_DMA4TSEL         (DMACTL2 & (~(0XFFE0)))>>0
#define put_DMA4TSEL(x)           DMACTL2=(DMACTL2 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA4TSEL              (DMACTL2 & (~(0XFFE0)))>>0
#define put_DMA5_DMA5TSEL(x)      DMACTL2=(DMACTL2 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA5_DMA5TSEL         (DMACTL2 & (~(0XE0FF)))>>8
#define put_DMA5TSEL(x)           DMACTL2=(DMACTL2 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA5TSEL              (DMACTL2 & (~(0XE0FF)))>>8
//DMACTL2 结束 ------------------------------------------------------------------
//DMACTL3 开始 ------------------------------------------------------------------
#define put_DMA6_DMA6TSEL(x)      DMACTL3=(DMACTL3 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA6_DMA6TSEL         (DMACTL3 & (~(0XFFE0)))>>0
#define put_DMA6TSEL(x)           DMACTL3=(DMACTL3 & 0XFFE0) | ((x & 0X001F) <<0)
#define get_DMA6TSEL              (DMACTL3 & (~(0XFFE0)))>>0
#define put_DMA7_DMA7TSEL(x)      DMACTL3=(DMACTL3 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA7_DMA7TSEL         (DMACTL3 & (~(0XE0FF)))>>8
#define put_DMA7TSEL(x)           DMACTL3=(DMACTL3 & 0XE0FF) | ((x & 0X001F) <<8)
#define get_DMA7TSEL              (DMACTL3 & (~(0XE0FF)))>>8
//DMACTL3 结束 ------------------------------------------------------------------
//DMACTL4 开始 ------------------------------------------------------------------
#define put_DMA_ENNMI(x)          DMACTL4=(DMACTL4 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMA_ENNMI             (DMACTL4 & (~(0XFFFE)))>>0
#define put_ENNMI(x)          DMACTL4=(DMACTL4 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_ENNMI             (DMACTL4 & (~(0XFFFE)))>>0
#define put_DMA_ROUNDROBIN(x)     DMACTL4=(DMACTL4 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMA_ROUNDROBIN        (DMACTL4 & (~(0XFFFD)))>>1
#define put_ROUNDROBIN(x)     DMACTL4=(DMACTL4 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_ROUNDROBIN        (DMACTL4 & (~(0XFFFD)))>>1
#define put_DMA_DMARMWDIS(x)      DMACTL4=(DMACTL4 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMA_DMARMWDIS         (DMACTL4 & (~(0XFFFB)))>>2
#define put_DMARMWDIS(x)      DMACTL4=(DMACTL4 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMARMWDIS         (DMACTL4 & (~(0XFFFB)))>>2
//DMACTL4 结束 ------------------------------------------------------------------
//DMA0CTL 开始 ------------------------------------------------------------------
#define put_DMA0_DMAREQ(x)        DMA0CTL=(DMA0CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMA0_DMAREQ           (DMA0CTL & (~(0XFFFE)))>>0
#define put_DMA0_DMAABORT(x)      DMA0CTL=(DMA0CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMA0_DMAABORT         (DMA0CTL & (~(0XFFFD)))>>1
#define put_DMA0_DMAIE(x)         DMA0CTL=(DMA0CTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMA0_DMAIE            (DMA0CTL & (~(0XFFFB)))>>2
#define put_DMA0_DMAIFG(x)        DMA0CTL=(DMA0CTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_DMA0_DMAIFG           (DMA0CTL & (~(0XFFF7)))>>3
#define put_DMA0_DMAEN(x)         DMA0CTL=(DMA0CTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_DMA0_DMAEN            (DMA0CTL & (~(0XFFEF)))>>4
#define put_DMA0_DMALEVEL(x)      DMA0CTL=(DMA0CTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_DMA0_DMALEVEL         (DMA0CTL & (~(0XFFDF)))>>5
#define put_DMA0_DMASRCBYTE(x)    DMA0CTL=(DMA0CTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_DMA0_DMASRCBYTE       (DMA0CTL & (~(0XFFBF)))>>6
#define put_DMA0_DMADSTBYTE(x)    DMA0CTL=(DMA0CTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_DMA0_DMADSTBYTE       (DMA0CTL & (~(0XFF7F)))>>7
#define put_DMA0_DMASRCINCR(x)    DMA0CTL=(DMA0CTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_DMA0_DMASRCINCR       (DMA0CTL & (~(0XFCFF)))>>8
#define put_DMA0_DMADSTINCR(x)    DMA0CTL=(DMA0CTL & 0XF3FF) | ((x & 0X0003) <<10)
#define get_DMA0_DMADSTINCR       (DMA0CTL & (~(0XF3FF)))>>10
#define put_DMA0_DMADT(x)         DMA0CTL=(DMA0CTL & 0X8FFF) | ((x & 0X0003) <<12)
#define get_DMA0_DMADT            (DMA0CTL & (~(0X8FFF)))>>12
//DMA0CTL 结束 ------------------------------------------------------------------
//DMA1CTL 开始 ------------------------------------------------------------------
#define put_DMA1_DMAREQ(x)        DMA1CTL=(DMA1CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMA1_DMAREQ           (DMA1CTL & (~(0XFFFE)))>>0
#define put_DMA1_DMAABORT(x)      DMA1CTL=(DMA1CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMA1_DMAABORT         (DMA1CTL & (~(0XFFFD)))>>1
#define put_DMA1_DMAIE(x)         DMA1CTL=(DMA1CTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMA1_DMAIE            (DMA1CTL & (~(0XFFFB)))>>2
#define put_DMA1_DMAIFG(x)        DMA1CTL=(DMA1CTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_DMA1_DMAIFG           (DMA1CTL & (~(0XFFF7)))>>3
#define put_DMA1_DMAEN(x)         DMA1CTL=(DMA1CTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_DMA1_DMAEN            (DMA1CTL & (~(0XFFEF)))>>4
#define put_DMA1_DMALEVEL(x)      DMA1CTL=(DMA1CTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_DMA1_DMALEVEL         (DMA1CTL & (~(0XFFDF)))>>5
#define put_DMA1_DMASRCBYTE(x)    DMA1CTL=(DMA1CTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_DMA1_DMASRCBYTE       (DMA1CTL & (~(0XFFBF)))>>6
#define put_DMA1_DMADSTBYTE(x)    DMA1CTL=(DMA1CTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_DMA1_DMADSTBYTE       (DMA1CTL & (~(0XFF7F)))>>7
#define put_DMA1_DMASRCINCR(x)    DMA1CTL=(DMA1CTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_DMA1_DMASRCINCR       (DMA1CTL & (~(0XFCFF)))>>8
#define put_DMA1_DMADSTINCR(x)    DMA1CTL=(DMA1CTL & 0XF3FF) | ((x & 0X0003) <<10)
#define get_DMA1_DMADSTINCR       (DMA1CTL & (~(0XF3FF)))>>10
#define put_DMA1_DMADT(x)         DMA1CTL=(DMA1CTL & 0X8FFF) | ((x & 0X0003) <<12)
#define get_DMA1_DMADT            (DMA1CTL & (~(0X8FFF)))>>12
//DMA1CTL 结束 ------------------------------------------------------------------
//DMA2CTL 开始 ------------------------------------------------------------------
#define put_DMA2_DMAREQ(x)        DMA2CTL=(DMA2CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_DMA2_DMAREQ           (DMA2CTL & (~(0XFFFE)))>>0
#define put_DMA2_DMAABORT(x)      DMA2CTL=(DMA2CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_DMA2_DMAABORT         (DMA2CTL & (~(0XFFFD)))>>1
#define put_DMA2_DMAIE(x)         DMA2CTL=(DMA2CTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_DMA2_DMAIE            (DMA2CTL & (~(0XFFFB)))>>2
#define put_DMA2_DMAIFG(x)        DMA2CTL=(DMA2CTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_DMA2_DMAIFG           (DMA2CTL & (~(0XFFF7)))>>3
#define put_DMA2_DMAEN(x)         DMA2CTL=(DMA2CTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_DMA2_DMAEN            (DMA2CTL & (~(0XFFEF)))>>4
#define put_DMA2_DMALEVEL(x)      DMA2CTL=(DMA2CTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_DMA2_DMALEVEL         (DMA2CTL & (~(0XFFDF)))>>5
#define put_DMA2_DMASRCBYTE(x)    DMA2CTL=(DMA2CTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_DMA2_DMASRCBYTE       (DMA2CTL & (~(0XFFBF)))>>6
#define put_DMA2_DMADSTBYTE(x)    DMA2CTL=(DMA2CTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_DMA2_DMADSTBYTE       (DMA2CTL & (~(0XFF7F)))>>7
#define put_DMA2_DMASRCINCR(x)    DMA2CTL=(DMA2CTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_DMA2_DMASRCINCR       (DMA2CTL & (~(0XFCFF)))>>8
#define put_DMA2_DMADSTINCR(x)    DMA2CTL=(DMA2CTL & 0XF3FF) | ((x & 0X0003) <<10)
#define get_DMA2_DMADSTINCR       (DMA2CTL & (~(0XF3FF)))>>10
#define put_DMA2_DMADT(x)         DMA2CTL=(DMA2CTL & 0X8FFF) | ((x & 0X0003) <<12)
#define get_DMA2_DMADT            (DMA2CTL & (~(0X8FFF)))>>12
//DMA2CTL 结束 ------------------------------------------------------------------
//DMAxSA 开始 -------------------------------------------------------------------
#define put_DMA0_DMA0SA(x)             DMA0SA=x
#define get_DMA0_DMA0SA                DMA0SA
#define put_DMA1_DMA1SA(x)             DMA1SA=x
#define get_DMA1_DMA1SA                DMA1SA
#define put_DMA2_DMA2SA(x)             DMA2SA=x
#define get_DMA2_DMA2SA                DMA2SA
//DMAxSA 结束 -------------------------------------------------------------------
//DMAxDA 开始 -------------------------------------------------------------------
#define put_DMA0_DMA0DA(x)             DMA0DA=x
#define get_DMA0_DMA0DA                DMA0DA
#define put_DMA1_DMA1DA(x)             DMA1DA=x
#define get_DMA1_DMA1DA                DMA1DA
#define put_DMA2_DMA2DA(x)             DMA2DA=x
#define get_DMA2_DMA2DA                DMA2DA
//DMAxDA 结束 -------------------------------------------------------------------
//DMAxSZ 开始 -------------------------------------------------------------------
#define put_DMA0_DMA0SZ(x)        DMA0SZ=x
#define get_DMA0_DMA0SZ           DMA0SZ
#define put_DMA1_DMA1SZ(x)        DMA1SZ=x
#define get_DMA1_DMA1SZ           DMA1SZ
#define put_DMA2_DMA2SZ(x)        DMA2SZ=x
#define get_DMA2_DMA2SZ           DMA2SZ
//DMAxSZ 结束 -------------------------------------------------------------------
//适合于对照原理图编写DMA应用程序 结束 ##########################################


//MPY32CTL0 开始(适合对照寄存编写应用程序) -------------------------------------------------
#define put_MPY32CTL0_MPYC(x)              MPY32CTL0=(MPY32CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_MPY32CTL0_MPYC                 (MPY32CTL0 & (~(0XFFFE)))>>0
#define put_MPY32CTL0_MPYFRAC(x)           MPY32CTL0=(MPY32CTL0 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_MPY32CTL0_MPYFRAC              (MPY32CTL0 & (~(0XFFFB)))>>2
#define put_MPY32CTL0_MPYSAT(x)            MPY32CTL0=(MPY32CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_MPY32CTL0_MPYSAT               (MPY32CTL0 & (~(0XFFF7)))>>2
#define put_MPY32CTL0_MPYM(x)              MPY32CTL0=(MPY32CTL0 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_MPY32CTL0_MPYM                 (MPY32CTL0 & (~(0XFFCF)))>>4
#define put_MPY32CTL0_MPYOP1_32(x)         MPY32CTL0=(MPY32CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_MPY32CTL0_MPYOP1_32            (MPY32CTL0 & (~(0XFFBF)))>>6
#define put_MPY32CTL0_MPYOP2_32(x)         MPY32CTL0=(MPY32CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_MPY32CTL0_MPYOP2_32            (MPY32CTL0 & (~(0XFF7F)))>>7
#define put_MPY32CTL0_MPYDLYWRTEN(x)       MPY32CTL0=(MPY32CTL0 & 0XFEFF) | ((x & 0X0001) <<8)
#define get_MPY32CTL0_MPYDLYWRTEN          (MPY32CTL0 & (~(0XFEFF)))>>8
#define put_MPY32CTL0_MPYDLY32(x)          MPY32CTL0=(MPY32CTL0 & 0XFDFF) | ((x & 0X0001) <<9)
#define get_MPY32CTL0_MPYDLY32             (MPY32CTL0 & (~(0XFDFF)))>>9
//MPY32CTL0 结束(适合对照寄存编写应用程序) --------------------------------------------------

//MPY32CTL0 开始(适合对照原理图编写应用程序) -------------------------------------------------
#define put_MPYC(x)              MPY32CTL0=(MPY32CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_MPYC                 (MPY32CTL0 & (~(0XFFFE)))>>0
#define put_MPYFRAC(x)           MPY32CTL0=(MPY32CTL0 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_MPYFRAC              (MPY32CTL0 & (~(0XFFFB)))>>2
#define put_MPYSAT(x)            MPY32CTL0=(MPY32CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_MPYSAT               (MPY32CTL0 & (~(0XFFF7)))>>2
#define put_MPYM(x)              MPY32CTL0=(MPY32CTL0 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_MPYM                 (MPY32CTL0 & (~(0XFFCF)))>>4
#define put_OP1_32(x)            MPY32CTL0=(MPY32CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_OP1_32               (MPY32CTL0 & (~(0XFFBF)))>>6
#define put_OP2_32(x)            MPY32CTL0=(MPY32CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_OP2_32               (MPY32CTL0 & (~(0XFF7F)))>>7

#define put_MPYDLYWRTEN(x)       MPY32CTL0=(MPY32CTL0 & 0XFEFF) | ((x & 0X0001) <<8)
#define get_MPYDLYWRTEN          (MPY32CTL0 & (~(0XFEFF)))>>8
#define put_MPYDLY32(x)          MPY32CTL0=(MPY32CTL0 & 0XFDFF) | ((x & 0X0001) <<9)
#define get_MPYDLY32             (MPY32CTL0 & (~(0XFDFF)))>>9

#define put_MPY(x)               MPY=x
#define get_MPY                  MPY
#define put_MPYS(x)              MPYS=x
#define get_MPYS                 MPYS
#define put_MAC(x)               MAC=x
#define get_MAC                  MAC
#define put_MACS(x)              MACS=x
#define get_MACS                 MACS
#define put_MPY32L(x)            MPY32L=x
#define get_MPY32L               MPY32L
#define put_MPYS32L(x)           MPYS32L=x
#define get_MPYS32L              MPYS32L
#define put_MAC32L(x)            MAC32L=x
#define get_MAC32L               MAC32L
#define put_MACS32L(x)           MACS32L=x
#define get_MACS32L              MACS32L

#define put_MPY32H(x)            MPY32H=x
#define get_MPY32H               MPY32H

#define put_MPYS32H(x)           MPYS32H=x
#define get_MPYS32H              MPYS32H
#define put_MAC32H(x)            MAC32H=x
#define get_MAC32H               MAC32H
#define put_MACS32H(x)           MACS32H=x
#define get_MACS32H              MACS32H
#define put_OP2H(x)              OP2H=x
#define get_OP2H                 OP2H
#define put_OP2(x)               OP2=x
#define get_OP2                  OP2
#define put_OP2L(x)              OP2L=x
#define get_OP2L                 OP2L
#define put_SUMEXT(x)            SUMEXT=x
#define get_SUMEXT               SUMEXT
#define put_RES3(x)              RES3=x
#define get_RES3                 RES3
#define put_RES2(x)              RES2=x
#define get_RES2                 RES2
#define put_RES1(x)              RES1=x
#define get_RES1                 RES1
#define put_RES0(x)              RES0=x
#define get_RES0                 RES0
#define put_RESHI(x)             RESHI=x
#define get_RESHI                RESHI
#define put_RESLO(x)             RESLO=x
#define get_RESLO                RESLO
//MPY32CTL0 结束(适合对照原理图编写应用程序) --------------------------------------------------
//***********************如下适合于对照寄存器编写应用程序****************************
//RTCCTL0 开始 ----------------------------------------------------------------------
#define put_RTCCTL0_RTCRDYIFG(x)  RTCCTL0=(RTCCTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_RTCCTL0_RTCRDYIFG     (RTCCTL0 & (~(0XFFFE)))>>0
#define put_RTCCTL0_RTCAIFG(x)    RTCCTL0=(RTCCTL0 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_RTCCTL0_RTCAIFG       (RTCCTL0 & (~(0XFFFD)))>>1
#define put_RTCCTL0_RTCTEVIFG(x)  RTCCTL0=(RTCCTL0 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_RTCCTL0_RTCTEVIFG     (RTCCTL0 & (~(0XFFFB)))>>2
#define put_RTCCTL0_RTCOFIFG(x)   RTCCTL0=(RTCCTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_RTCCTL0_RTCOFIFG      (RTCCTL0 & (~(0XFFF7)))>>3
#define put_RTCCTL0_RTCRDYIE(x)   RTCCTL0=(RTCCTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_RTCCTL0_RTCRDYIE      (RTCCTL0 & (~(0XFFEF)))>>4
#define put_RTCCTL0_RTCAIE(x)     RTCCTL0=(RTCCTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_RTCCTL0_RTCAIE        (RTCCTL0 & (~(0XFFDF)))>>5
#define put_RTCCTL0_RTCTEVIE(x)   RTCCTL0=(RTCCTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_RTCCTL0_RTCTEVIE      (RTCCTL0 & (~(0XFFBF)))>>6
#define put_RTCCTL0_RTCOFIE(x)    RTCCTL0=(RTCCTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_RTCCTL0_RTCOFIE       (RTCCTL0 & (~(0XFF7F)))>>7
//RTCCTL0 结束 ----------------------------------------------------------------------
//RTCCTL1 开始 ----------------------------------------------------------------------
#define put_RTCCTL1_RTCTEV(x)     RTCCTL1=(RTCCTL1 & 0XFFFC) | ((x & 0X0003) <<0)
#define get_RTCCTL1_RTCTEV        (RTCCTL1 & (~(0XFFFC)))>>0
#define put_RTCCTL1_RTCSSEL(x)    RTCCTL1=(RTCCTL1 & 0XFFF3) | ((x & 0X0003) <<2)
#define get_RTCCTL1_RTCSSEL       (RTCCTL1 & (~(0XFFF3)))>>2
#define put_RTCCTL1_RTCRDY(x)     RTCCTL1=(RTCCTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_RTCCTL1_RTCRDY        (RTCCTL1 & (~(0XFFEF)))>>4
#define put_RTCCTL1_RTCMODE(x)    RTCCTL1=(RTCCTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_RTCCTL1_RTCMODE       (RTCCTL1 & (~(0XFFDF)))>>5
#define put_RTCCTL1_RTCHOLD(x)    RTCCTL1=(RTCCTL1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_RTCCTL1_RTCHOLD       (RTCCTL1 & (~(0XFFBF)))>>6
#define put_RTCCTL1_RTCBCD(x)     RTCCTL1=(RTCCTL1 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_RTCCTL1_RTCBCD        (RTCCTL1 & (~(0XFF7F)))>>7
//RTCCTL1 结束 ----------------------------------------------------------------------
//RTCCTL2 开始 ----------------------------------------------------------------------
#define put_RTCCTL2_RTCCAL(x)     RTCCTL2=(RTCCTL2 & 0XFFC0) | ((x & 0X0001) <<0)
#define get_RTCCTL2_RTCCAL        (RTCCTL2 & (~(0XFFC0)))>>0
#define put_RTCCTL2_RTCCALS(x)    RTCCTL2=(RTCCTL2 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_RTCCTL2_RTCCALS       (RTCCTL2 & (~(0XFF7F)))>>7
//RTCCTL2 结束 ----------------------------------------------------------------------
//RTCCTL3 开始 ----------------------------------------------------------------------
#define put_RTCCTL3_RTCCALF(x)    RTCCTL3=(RTCCTL3 & 0XFFFC) | ((x & 0X0003) <<0)
#define get_RTCCTL3_RTCCALF       (RTCCTL3 & (~(0XFFFC)))>>0
//RTCCTL3 结束 ----------------------------------------------------------------------
//时间日历寄存器开始 ----------------------------------------------------------------
#define put_RTCSEC(x)             RTCSEC=(RTCSEC & 0XFF80) | ((x & 0X007F) <<0)
#define get_RTCSEC                (RTCSEC & (~(0XFF80)))>>0
#define put_RTCMIN(x)             RTCMIN=(RTCMIN & 0XFF80) | ((x & 0X007F) <<0)
#define get_RTCMIN                (RTCMIN & (~(0XFF80)))>>0
#define put_RTCHOUR(x)            RTCHOUR=(RTCHOUR & 0XFFC0) | ((x & 0X003F) <<0)
#define get_RTCHOUR               (RTCHOUR & (~(0XFFC0)))>>0
#define put_RTCDOW(x)             RTCDOW=(RTCDOW & 0XFFF8) | ((x & 0X0007) <<0)
#define get_RTCDOW                (RTCDOW & (~(0XFFF8)))>>0
#define put_RTCDAY(x)             RTCDAY=(RTCDAY & 0XFFC0) | ((x & 0X003F) <<0)
#define get_RTCDAY                (RTCDAY & (~(0XFFC0)))>>0
#define put_RTCMON(x)             RTCMON=(RTCMON & 0XFFE0) | ((x & 0X001F) <<0)
#define get_RTCMON                (RTCMON & (~(0XFFE0)))>>0
#define put_RTCYEAR(x)            RTCYEAR=(RTCYEAR & 0X8000) | ((x & 0X7FFF) <<0)
#define get_RTCYEAR               (RTCYEAR & (~(0X8000)))>>0
//Alarm 寄存器开始--------------------------------------------------------------------

//Alarm 寄存器结束--------------------------------------------------------------------
//时间日历寄存器结束 ----------------------------------------------------------------
//RTCPS0CTL 开始 -----------------------------------------------------------------------
#define put_RTCPS0CTL_RT0PSIFG(x)    RTCPS0CTL=(RTCPS0CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_RTCPS0CTL_RT0PSIFG       (RTCPS0CTL & (~(0XFFFE)))>>0
#define put_RTCPS0CTL_RT0PSIE(x)     RTCPS0CTL=(RTCPS0CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_RTCPS0CTL_RT0PSIE        (RTCPS0CTL & (~(0XFFFD)))>>1
#define put_RTCPS0CTL_RT0IP(x)       RTCPS0CTL=(RTCPS0CTL & 0XFFE3) | ((x & 0X0007) <<2)
#define get_RTCPS0CTL_RT0IP          (RTCPS0CTL & (~(0XFFE3)))>>2
#define put_RTCPS0CTL_RT0PSHOLD(x)   RTCPS0CTL=(RTCPS0CTL & 0XFEFF) | ((x & 0X0001) <<8)
#define get_RTCPS0CTL_RT0PSHOLD      (RTCPS0CTL & (~(0XFEFF)))>>8
#define put_RTCPS0CTL_RT0PSDIV(x)    RTCPS0CTL=(RTCPS0CTL & 0XC7FF) | ((x & 0X0007) <<11)
#define get_RTCPS0CTL_RT0PSDIV       (RTCPS0CTL & (~(0XC7FF)))>>12
#define put_RTCPS0CTL_RT0SSEL(x)     RTCPS0CTL=(RTCPS0CTL & 0XBFFF) | ((x & 0X0001) <<14)
#define get_RTCPS0CTL_RT0SSEL        (RTCPS0CTL & (~(0XBFFF)))>>14
//RTCPS0CTL 结束 -----------------------------------------------------------------------
//RTCPS1CTL 开始 ----------------------------------------------------------------------
#define put_RTCPS1CTL_RT1PSIFG(x)    RTCPS1CTL=(RTCPS1CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_RTCPS1CTL_RT1PSIFG       (RTCPS1CTL & (~(0XFFFE)))>>0
#define put_RTCPS1CTL_RT1PSIE(x)     RTCPS1CTL=(RTCPS1CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_RTCPS1CTL_RT1PSIE        (RTCPS1CTL & (~(0XFFFD)))>>1
#define put_RTCPS1CTL_RT1IP(x)       RTCPS1CTL=(RTCPS1CTL & 0XFFE3) | ((x & 0X0007) <<2)
#define get_RTCPS1CTL_RT1IP          (RTCPS1CTL & (~(0XFFE3)))>>2
#define put_RTCPS1CTL_RT1PSHOLD(x)   RTCPS1CTL=(RTCPS1CTL & 0XFEFF) | ((x & 0X0001) <<8)
#define get_RTCPS1CTL_RT1PSHOLD      (RTCPS1CTL & (~(0XFEFF)))>>8
#define put_RTCPS1CTL_RT1PSDIV(x)    RTCPS1CTL=(RTCPS1CTL & 0XC7FF) | ((x & 0X0007) <<11)
#define get_RTCPS1CTL_RT1PSDIV       (RTCPS1CTL & (~(0XC7FF)))>>12
#define put_RTCPS1CTL_RT1SSEL(x)     RTCPS1CTL=(RTCPS1CTL & 0X3FFF) | (unsigned int)((x & 0X0003) <<14)
#define get_RTCPS1CTL_RT1SSEL        (RTCPS1CTL & (~(0X3FFF)))>>14
//RTCPS1CTL 结束 ----------------------------------------------------------------------
//RTCPSx 开始 -------------------------------------------------------------------------
#define put_RTCPS0_RT0PS(x)       RTCPS0=x
#define get_RTCPS0_RT0PS          RTCPS0
#define put_RTCPS1_RT1PS(x)       RTCPS1=x
#define get_RTCPS1_RT1PS          RTCPS1
//RTCPSx 结束 -------------------------------------------------------------------------
//其它寄存器开始 ----------------------------------------------------------------------
#define get_RTCIV                 RTCIV & 0xFFFE
#define put_BIN2BCD               BIN2BCD=x
#define get_BIN2BCD               BIN2BCD
#define put_BCD2BIN               BCD2BIN=x
#define get_BCD2BIN               BCD2BIN
//其它寄存器结束 ----------------------------------------------------------------------
//***********************以上适合于对照寄存器编写应用程序********************************
//***********************以下适合于对照原理图编写应用程序********************************
//RTCCTL0 开始 ----------------------------------------------------------------------
#define put_RTCRDYIFG(x)  RTCCTL0=(RTCCTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_RTCRDYIFG     (RTCCTL0 & (~(0XFFFE)))>>0
#define put_RTCAIFG(x)    RTCCTL0=(RTCCTL0 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_RTCAIFG       (RTCCTL0 & (~(0XFFFD)))>>1
#define put_RTCTEVIFG(x)  RTCCTL0=(RTCCTL0 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_RTCTEVIFG     (RTCCTL0 & (~(0XFFFB)))>>2
#define put_RTCOFIFG(x)   RTCCTL0=(RTCCTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_RTCOFIFG      (RTCCTL0 & (~(0XFFF7)))>>3
#define put_RTCRDYIE(x)   RTCCTL0=(RTCCTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_RTCRDYIE      (RTCCTL0 & (~(0XFFEF)))>>4
#define put_RTCAIE(x)     RTCCTL0=(RTCCTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_RTCAIE        (RTCCTL0 & (~(0XFFDF)))>>5
#define put_RTCTEVIE(x)   RTCCTL0=(RTCCTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_RTCTEVIE      (RTCCTL0 & (~(0XFFBF)))>>6
#define put_RTCOFIE(x)    RTCCTL0=(RTCCTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_RTCOFIE       (RTCCTL0 & (~(0XFF7F)))>>7
//RTCCTL0 结束 ----------------------------------------------------------------------
//RTCCTL1 开始 ----------------------------------------------------------------------
#define put_RTCTEV(x)     RTCCTL1=(RTCCTL1 & 0XFFFC) | ((x & 0X0003) <<0)
#define get_RTCTEV        (RTCCTL1 & (~(0XFFFC)))>>0
#define put_RTCSSEL(x)    RTCCTL1=(RTCCTL1 & 0XFFF3) | ((x & 0X0003) <<2)
#define get_RTCSSEL       (RTCCTL1 & (~(0XFFF3)))>>2
#define put_RTCRDY(x)     RTCCTL1=(RTCCTL1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_RTCRDY        (RTCCTL1 & (~(0XFFEF)))>>4
#define put_RTCMODE(x)    RTCCTL1=(RTCCTL1 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_RTCMODE       (RTCCTL1 & (~(0XFFDF)))>>5
#define put_RTCHOLD(x)    RTCCTL1=(RTCCTL1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_RTCHOLD       (RTCCTL1 & (~(0XFFBF)))>>6
#define put_RTCBCD(x)     RTCCTL1=(RTCCTL1 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_RTCBCD        (RTCCTL1 & (~(0XFF7F)))>>7
//RTCCTL1 结束 ----------------------------------------------------------------------
//RTCCTL2 开始 ----------------------------------------------------------------------
#define put_RTCCAL(x)     RTCCTL2=(RTCCTL2 & 0XFFC0) | ((x & 0X0001) <<0)
#define get_RTCCAL        (RTCCTL2 & (~(0XFFC0)))>>0
#define put_RTCCALS(x)    RTCCTL2=(RTCCTL2 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_RTCCALS       (RTCCTL2 & (~(0XFF7F)))>>7
//RTCCTL2 结束 ----------------------------------------------------------------------
//RTCCTL3 开始 ----------------------------------------------------------------------
#define put_RTCCALF(x)    RTCCTL3=(RTCCTL3 & 0XFFFC) | ((x & 0X0003) <<0)
#define get_RTCCALF       (RTCCTL3 & (~(0XFFFC)))>>0
//RTCCTL3 结束 ----------------------------------------------------------------------
//时间日历寄存器开始 ----------------------------------------------------------------
#define put_RTCSEC(x)             RTCSEC=(RTCSEC & 0XFF80) | ((x & 0X007F) <<0)
#define get_RTCSEC                (RTCSEC & (~(0XFF80)))>>0
#define put_RTCMIN(x)             RTCMIN=(RTCMIN & 0XFF80) | ((x & 0X007F) <<0)
#define get_RTCMIN                (RTCMIN & (~(0XFF80)))>>0
#define put_RTCHOUR(x)            RTCHOUR=(RTCHOUR & 0XFFC0) | ((x & 0X003F) <<0)
#define get_RTCHOUR               (RTCHOUR & (~(0XFFC0)))>>0
#define put_RTCDOW(x)             RTCDOW=(RTCDOW & 0XFFF8) | ((x & 0X0007) <<0)
#define get_RTCDOW                (RTCDOW & (~(0XFFF8)))>>0
#define put_RTCDAY(x)             RTCDAY=(RTCDAY & 0XFFC0) | ((x & 0X003F) <<0)
#define get_RTCDAY                (RTCDAY & (~(0XFFC0)))>>0
#define put_RTCMON(x)             RTCMON=(RTCMON & 0XFFE0) | ((x & 0X001F) <<0)
#define get_RTCMON                (RTCMON & (~(0XFFE0)))>>0
#define put_RTCYEAR(x)            RTCYEAR=(RTCYEAR & 0X8000) | ((x & 0X7FFF) <<0)
#define get_RTCYEAR               (RTCYEAR & (~(0X8000)))>>0
//Alarm 寄存器开始--------------------------------------------------------------------
#define put_RTCAHOUR(x)           RTCAMINHR=(RTCAMINHR & 0XC0FF) | (unsigned int)((x & 0X003F) <<8)      //预置闹小时
#define get_RTCAHOUR              (RTCAMINHR & (~(0XC0FF)))>>8
#define put_RTCAHOUR_AE(x)        RTCAMINHR=(RTCAMINHR & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)      //小时闹使能
#define get_RTCAHOUR_AE           (RTCAMINHR & (~(0X7FFF)))>>15
#define put_RTCAMIN(x)            RTCAMINHR=(RTCAMINHR & 0XFF80) | ((x & 0X007F) <<0)       //预置闹分钟
#define get_RTCAMIN               (RTCAMINHR & (~(0XFF80)))>>0
#define put_RTCAMIN_AE(x)         RTCAMINHR=(RTCAMINHR & 0XFF7F) | ((x & 0X0001) <<7)       //分钟闹使能
#define get_RTCAMIN_AE            (RTCAMINHR & (~(0XFF7F)))>>7
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define put_RTCADAY(x)            RTCADOWDAY=(RTCADOWDAY & 0X80FF) | ((x & 0X001F) <<8)    //预置闹日期预
#define get_RTCADAY               (RTCADOWDAY & (~(0X80FF)))>>8
#define put_RTCADAY_AE(x)         RTCADOWDAY=(RTCADOWDAY & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)   //日期闹使能 
#define get_RTCADAY_AE            (RTCADOWDAY & (~(0X7FFF)))>>15
#define put_RTCADOW(x)            RTCADOWDAY=(RTCADOWDAY & 0XFF80) | ((x & 0X001F) <<0)    //置闹星期
#define get_RTCADOW               (RTCADOWDAY & (~(0XFF80)))>>0
#define put_RTCADOW_AE(x)         RTCADOWDAY=(RTCADOWDAY & 0XFF7F) | ((x & 0X0001) <<7)     //星期闹使能
#define get_RTCADOW_AE            (RTCADOWDAY & (~(0XFF7F)))>>7
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//Alarm 寄存器结束--------------------------------------------------------------------
//时间日历寄存器结束 ----------------------------------------------------------------
//RTCPS0CTL 开始 -----------------------------------------------------------------------
#define put_RT0PSIFG(x)           RTCPS0CTL=(RTCPS0CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_RT0PSIFG              (RTCPS0CTL & (~(0XFFFE)))>>0
#define put_RT0PSIE(x)            RTCPS0CTL=(RTCPS0CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_RT0PSIE               (RTCPS0CTL & (~(0XFFFD)))>>1
#define put_RT0IP(x)              RTCPS0CTL=(RTCPS0CTL & 0XFFE3) | ((x & 0X0007) <<2)
#define get_RT0IP                 (RTCPS0CTL & (~(0XFFE3)))>>2
#define put_RT0PSHOLD(x)          RTCPS0CTL=(RTCPS0CTL & 0XFEFF) | ((x & 0X0001) <<8)
#define get_RT0PSHOLD             (RTCPS0CTL & (~(0XFEFF)))>>8
#define put_RT0PSDIV(x)           RTCPS0CTL=(RTCPS0CTL & 0XC7FF) | ((x & 0X0007) <<11)
#define get_RT0PSDIV              (RTCPS0CTL & (~(0XC7FF)))>>12
#define put_RT0SSEL(x)            RTCPS0CTL=(RTCPS0CTL & 0XBFFF) | ((x & 0X0001) <<14)
#define get_RT0SSEL               (RTCPS0CTL & (~(0XBFFF)))>>14
//RTCPS0CTL 结束 -----------------------------------------------------------------------
//RTCPS1CTL 开始 ----------------------------------------------------------------------
#define put_RT1PSIFG(x)           RTCPS1CTL=(RTCPS1CTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_RT1PSIFG              (RTCPS1CTL & (~(0XFFFE)))>>0
#define put_RT1PSIE(x)            RTCPS1CTL=(RTCPS1CTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_RT1PSIE               (RTCPS1CTL & (~(0XFFFD)))>>1
#define put_RT1IP(x)              RTCPS1CTL=(RTCPS1CTL & 0XFFE3) | ((x & 0X0007) <<2)
#define get_RT1IP                 (RTCPS1CTL & (~(0XFFE3)))>>2
#define put_RT1PSHOLD(x)          RTCPS1CTL=(RTCPS1CTL & 0XFEFF) | ((x & 0X0001) <<8)
#define get_RT1PSHOLD             (RTCPS1CTL & (~(0XFEFF)))>>8
#define put_RT1PSDIV(x)           RTCPS1CTL=(RTCPS1CTL & 0XC7FF) | ((x & 0X0007) <<11)
#define get_RT1PSDIV              (RTCPS1CTL & (~(0XC7FF)))>>12
#define put_RT1SSEL(x)            RTCPS1CTL=(RTCPS1CTL & 0X3FFF) | (unsigned int)((x & 0X0003) <<14)
#define get_RT1SSEL               (RTCPS1CTL & (~(0X3FFF)))>>14
//RTCPS1CTL 结束 ----------------------------------------------------------------------
//RTCPSx 开始 -------------------------------------------------------------------------
#define put_RT0PS(x)              RTCPS0=x
#define get_RT0PS                 RTCPS0
#define put_RT1PS(x)              RTCPS1=x
#define get_RT1PS                 RTCPS1
//RTCPSx 结束 -------------------------------------------------------------------------
//RCTCNTx开始 -------------------------------------------------------------------------
#define put_RTCNT12(x)            RTCNT12=x
#define get_RTCNT12               RTCNT12
#define put_RTCNT1(x)             RTCNT1=x & 0x00FF
#define get_RTCNT1                RTCNT1 & 0x00FF
#define put_RTCNT2(x)             RTCNT2=x & 0x00FF
#define get_RTCNT2                RTCNT2 & 0x00FF
#define put_RTCNT34(x)            RTCNT34=x
#define get_RTCNT34               RTCNT34
#define put_RTCNT3(x)             RTCNT3=x & 0x00FF
#define get_RTCNT3                RTCNT3 & 0x00FF
#define put_RTCNT4(x)             RTCNT4=x & 0x00FF
#define get_RTCNT4                RTCNT4 & 0x00FF
//RCTCNTx结束 -------------------------------------------------------------------------
//***********************以上适合于对照原理图编写应用程序********************************
//特殊功能寄存器-----------------------------------------------------------------------

#define put_SFRIFG1_WDTIFG(x)     SFRIFG1=(SFRIFG1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SFRIFG1_WDTIFG        (SFRIFG1 & (~(0XFFFE)))>>0
#define put_SFRIFG1_OFIFG(x)      SFRIFG1=(SFRIFG1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SFRIFG1_OFIFG         (SFRIFG1 & (~(0XFFFD)))>>1
#define put_SFRIFG1_VMAIFG(x)     SFRIFG1=(SFRIFG1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SFRIFG1_VMAIFG        (SFRIFG1 & (~(0XFFF7)))>>1
#define put_SFRIFG1_NMIIFG(x)     SFRIFG1=(SFRIFG1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SFRIFG1_NMIIFG        (SFRIFG1 & (~(0XFFEF)))>>1
#define put_SFRIFG1_JMBINIFG(x)   SFRIFG1=(SFRIFG1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SFRIFG1_JMBINIFG      (SFRIFG1 & (~(0XFFBF)))>>6
#define put_SFRIFG1_JMBOUTIFG(x)  SFRIFG1=(SFRIFG1 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SFRIFG1_JMBOUTIFG     (SFRIFG1 & (~(0XFF7F)))>>7

#define put_WDTIFG(x)             SFRIFG1=(SFRIFG1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_WDTIFG                (SFRIFG1 & (~(0XFFFE)))>>0
#define put_OFIFG(x)              SFRIFG1=(SFRIFG1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_OFIFG                 (SFRIFG1 & (~(0XFFFD)))>>1
#define put_VMAIFG(x)             SFRIFG1=(SFRIFG1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_VMAIFG                (SFRIFG1 & (~(0XFFF7)))>>1
#define put_NMIIFG(x)             SFRIFG1=(SFRIFG1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_NMIIFG                (SFRIFG1 & (~(0XFFEF)))>>1
#define put_JMBINIFG(x)           SFRIFG1=(SFRIFG1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_JMBINIFG              (SFRIFG1 & (~(0XFFBF)))>>6
#define put_JMBOUTIFG(x)          SFRIFG1=(SFRIFG1 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_JMBOUTIFG             (SFRIFG1 & (~(0XFF7F)))>>7

#define put_SFRIE1_WDTIE(x)       SFRIE1=(SFRIE1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SFRIE1_WDTIE          (SFRIE1 & (~(0XFFFE)))>>0
#define put_SFRIE1_OFIE(x)        SFRIE1=(SFRIE1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SFRIE1_OFIE           (SFRIE1 & (~(0XFFFD)))>>1
#define put_SFRIE1_VMAIE(x)       SFRIE1=(SFRIE1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SFRIE1_VMAIE          (SFRIE1 & (~(0XFFF7)))>>1
#define put_SFRIE1_NMIIE(x)       SFRIE1=(SFRIE1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SFRIE1_NMIIE          (SFRIE1 & (~(0XFFEF)))>>1
#define put_SFRIE1_JMBINIE(x)     SFRIE1=(SFRIE1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SFRIE1_JMBINIE        (SFRIE1 & (~(0XFFBF)))>>6
#define put_SFRIE1_JMBOUTIE(x)    SFRIE1=(SFRIE1 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SFRIE1_JMBOUTIE       (SFRIE1 & (~(0XFF7F)))>>7

#define put_WDTIE(x)              SFRIE1=(SFRIE1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_WDTIE                 (SFRIE1 & (~(0XFFFE)))>>0
#define put_OFIE(x)               SFRIE1=(SFRIE1 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_OFIE                  (SFRIE1 & (~(0XFFFD)))>>1
#define put_VMAIE(x)              SFRIE1=(SFRIE1 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_VMAIE                 (SFRIE1 & (~(0XFFF7)))>>1
#define put_NMIIE(x)              SFRIE1=(SFRIE1 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_NMIIE                 (SFRIE1 & (~(0XFFEF)))>>1
#define put_JMBINIE(x)            SFRIE1=(SFRIE1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_JMBINIE               (SFRIE1 & (~(0XFFBF)))>>6
#define put_JMBOUTIE(x)           SFRIE1=(SFRIE1 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_JMBOUTIE              (SFRIE1 & (~(0XFF7F)))>>7

#define put_WDTCTL_WDTIS(x)       WDTCTL=((WDTCTL & 0X00F8) + 0x5A00) | ((x & 0X0007) <<0)
#define get_WDTCTL_WDTIS          (WDTCTL & (~(0XFFF8)))>>0
#define put_WDTCTL_WDTCNTCL(x)    WDTCTL=((WDTCTL & 0X00F7) + 0x5A00) | ((x & 0X0001) <<3)
#define get_WDTCTL_WDTCNTCL       (WDTCTL & (~(0XFFF7)))>>3
#define put_WDTCTL_WDTTMSEL(x)    WDTCTL=((WDTCTL & 0X00EF) + 0x5A00) | ((x & 0X0001) <<4)
#define get_WDTCTL_WDTTMSEL       (WDTCTL & (~(0XFFEF)))>>4
#define put_WDTCTL_WDTSSEL(x)     WDTCTL=((WDTCTL & 0X009F) + 0x5A00) | ((x & 0X0003) <<5)
#define get_WDTCTL_WDTSSEL        (WDTCTL & (~(0XFF9F)))>>5
#define put_WDTCTL_WDTHOLD(x)     WDTCTL=((WDTCTL & 0X007F) + 0x5A00) | ((x & 0X0001) <<7)
#define get_WDTCTL_WDTHOLD        (WDTCTL & (~(0XFF7F)))>>7

#define put_WDTIS(x)              WDTCTL=((WDTCTL & 0X00F8) + 0x5A00) | ((x & 0X0007) <<0)
#define get_WDTIS                 (WDTCTL & (~(0XFFF8)))>>0
#define put_WDTCNTCL(x)           WDTCTL=((WDTCTL & 0X00F7) + 0x5A00) | ((x & 0X0001) <<3)
#define get_WDTCNTCL              (WDTCTL & (~(0XFFF7)))>>3
#define put_WDTTMSEL(x)           WDTCTL=((WDTCTL & 0X00EF) + 0x5A00) | ((x & 0X0001) <<4)
#define get_WDTTMSEL              (WDTCTL & (~(0XFFEF)))>>4
#define put_WDTSSEL(x)            WDTCTL=((WDTCTL & 0X009F) + 0x5A00) | ((x & 0X0003) <<5)
#define get_WDTSSEL               (WDTCTL & (~(0XFF9F)))>>5
#define put_WDTHOLD(x)            WDTCTL=((WDTCTL & 0X007F) + 0x5A00) | ((x & 0X0001) <<7)
#define get_WDTHOLD               (WDTCTL & (~(0XFF7F)))>>7
//ADC12CTL0 开始 ###################################################################
#define put_ADC12SC_ENC(x)      ADC12CTL0=(ADC12CTL0 & 0XFFFC) | ((x & 0X0003) <<0)
#define get_ADC12SC_ENC         (ADC12CTL0 & (~(0XFFFC)))>>0
#define put_ADC12SC(x)          ADC12CTL0=(ADC12CTL0 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_ADC12SC             (ADC12CTL0 & (~(0XFFFE)))>>0
#define put_ADC12ENC(x)         ADC12CTL0=(ADC12CTL0 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_ADC12ENC            (ADC12CTL0 & (~(0XFFFD)))>>1
#define put_ENC(x)              ADC12CTL0=(ADC12CTL0 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_ENC                 (ADC12CTL0 & (~(0XFFFD)))>>1
#define put_ADC12TOVIE(x)       ADC12CTL0=(ADC12CTL0 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_ADC12TOVIE          (ADC12CTL0 & (~(0XFFFB)))>>2
#define put_ADC12OVIE(x)        ADC12CTL0=(ADC12CTL0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_ADC12OVIE           (ADC12CTL0 & (~(0XFFF7)))>>3
#define put_ADC12ON(x)          ADC12CTL0=(ADC12CTL0 & 0XFFEF) | ((x & 0X0001) <<4)
#define get_ADC12ON             (ADC12CTL0 & (~(0XFFEF)))>>4
#define put_ADC12REFON(x)       ADC12CTL0=(ADC12CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_ADC12REFON          (ADC12CTL0 & (~(0XFFDF)))>>5
#define put_REFON(x)            ADC12CTL0=(ADC12CTL0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_REFON               (ADC12CTL0 & (~(0XFFDF)))>>5
#define put_ADC12REF2_5V(x)     ADC12CTL0=(ADC12CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12REF2_5V        (ADC12CTL0 & (~(0XFFBF)))>>6
#define put_REF2_5V(x)          ADC12CTL0=(ADC12CTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_REF2_5V             (ADC12CTL0 & (~(0XFFBF)))>>6
#define put_ADC12MSC(x)         ADC12CTL0=(ADC12CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_ADC12MSC            (ADC12CTL0 & (~(0XFF7F)))>>7
#define put_MSC(x)              ADC12CTL0=(ADC12CTL0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_MSC                 (ADC12CTL0 & (~(0XFF7F)))>>7
#define put_ADC12SHT0(x)        ADC12CTL0=(ADC12CTL0 & 0XF0FF) | ((x & 0X000F) <<8)
#define get_ADC12SHT0           (ADC12CTL0 & (~(0XF0FF)))>>8
#define put_SHT0(x)             ADC12CTL0=(ADC12CTL0 & 0XF0FF) | ((x & 0X000F) <<8)
#define get_SHT0                (ADC12CTL0 & (~(0XF0FF)))>>8
#define put_ADC12SHT1(x)        ADC12CTL0=(ADC12CTL0 & 0X0FFF) | ((x & 0X000F) <<12)
#define get_ADC12SHT1           (ADC12CTL0 & (~(0X0FFF)))>>12
#define put_ADC12SHT(x)         ADC12CTL0=(ADC12CTL0 & 0X0FFF) | ((x & 0X000F) <<12)
#define get_ADC12SHT            (ADC12CTL0 & (~(0X0FFF)))>>12
//ADC12CTL0 结束 ###################################################################
//ADC12CTL1 开始 ###################################################################
#define put_ADC12BUSY(x)        ADC12CTL1=(ADC12CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_ADC12BUSY           (ADC12CTL1 & (~(0XFFFE)))>>0
#define put_BUSY(x)             ADC12CTL1=(ADC12CTL1 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_BUSY                (ADC12CTL1 & (~(0XFFFE)))>>0
#define put_ADC12CONSEQ(x)      ADC12CTL1=(ADC12CTL1 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_ADC12CONSEQ         (ADC12CTL1 & (~(0XFFF9)))>>1
#define put_CONSEQ(x)           ADC12CTL1=(ADC12CTL1 & 0XFFF9) | ((x & 0X0003) <<1)
#define get_CONSEQ              (ADC12CTL1 & (~(0XFFF9)))>>1
#define put_ADC12SSEL(x)        ADC12CTL1=(ADC12CTL1 & 0XFFE7) | ((x & 0X0003) <<3)
#define get_ADC12SSEL           (ADC12CTL1 & (~(0XFFE7)))>>3
#define put_ADC12DIV(x)         ADC12CTL1=(ADC12CTL1 & 0XFF1F) | ((x & 0X0001) <<5)
#define get_ADC12DIV            (ADC12CTL1 & (~(0XFF1F)))>>5
#define put_ADC12ISSH(x)        ADC12CTL1=(ADC12CTL1 & 0XFEFF) | ((x & 0X0001) <<8)
#define get_ADC12ISSH           (ADC12CTL1 & (~(0XFEFF)))>>8
#define put_ISSH(x)             ADC12CTL1=(ADC12CTL1 & 0XFEFF) | ((x & 0X0001) <<8)
#define get_ISSH                (ADC12CTL1 & (~(0XFEFF)))>>8
#define put_ADC12SHP(x)         ADC12CTL1=(ADC12CTL1 & 0XFDFF) | ((x & 0X0001) <<9)
#define get_ADC12SHP            (ADC12CTL1 & (~(0XFDFF)))>>9
#define put_SHP(x)              ADC12CTL1=(ADC12CTL1 & 0XFDFF) | ((x & 0X0001) <<9)
#define get_SHP                 (ADC12CTL1 & (~(0XFDFF)))>>9
#define put_ADC12SHS(x)         ADC12CTL1=(ADC12CTL1 & 0X3FFF) | ((x & 0X0003) <<10)
#define get_ADC12SHS            (ADC12CTL1 & (~(0XF3FF)))>>10
#define put_SHS(x)              ADC12CTL1=(ADC12CTL1 & 0X3FFF) | ((x & 0X0003) <<10)
#define get_SHS                 (ADC12CTL1 & (~(0XF3FF)))>>10
#define put_ADC12CSTARTADD(x)   ADC12CTL1=(ADC12CTL1 & 0X0FFF) | ((x & 0X0001) <<12)
#define get_ADC12CSTARTADD      (ADC12CTL1 & (~(0X0FFF)))>>12
#define put_CSTARTADD(x)        ADC12CTL1=(ADC12CTL1 & 0X0FFF) | ((x & 0X0001) <<12)
#define get_CSTARTADD           (ADC12CTL1 & (~(0X0FFF)))>>12
//ADC12CTL1 结束 ###################################################################
//ADC12CTL2 开始 ###################################################################
#define put_ADC12REFBURST(x)    ADC12CTL2=(ADC12CTL2 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_ADC12REFBURST       (ADC12CTL2 & (~(0XFFFE)))>>0
#define put_REFBURST(x)         ADC12CTL2=(ADC12CTL2 & 0XFFFE) | ((x & 0X0001) <<0)
#define get_REFBURST            (ADC12CTL2 & (~(0XFFFE)))>>0
#define put_ADC12REFOUT(x)      ADC12CTL2=(ADC12CTL2 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_ADC12REFOUT         (ADC12CTL2 & (~(0XFFFD)))>>1
#define put_REFOUT(x)           ADC12CTL2=(ADC12CTL2 & 0XFFFD) | ((x & 0X0001) <<1)
#define get_REFOUT              (ADC12CTL2 & (~(0XFFFD)))>>1
#define put_ADC12SR(x)          ADC12CTL2=(ADC12CTL2 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_ADC12SR             (ADC12CTL2 & (~(0XFFFB)))>>2
#define put_ADC12DF(x)          ADC12CTL2=(ADC12CTL2 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_ADC12DF             (ADC12CTL2 & (~(0XFFF7)))>>3
#define put_ADC12RES(x)         ADC12CTL2=(ADC12CTL2 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12RES            (ADC12CTL2 & (~(0XFFCF)))>>4
#define put_ADC12TCOFF(x)       ADC12CTL2=(ADC12CTL2 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_ADC12TCOFF          (ADC12CTL2 & (~(0XFF7F)))>>7
#define put_ADC12PDIV(x)        ADC12CTL2=(ADC12CTL2 & 0XFEFF) | ((x & 0X0001) <<8)
#define get_ADC12PDIV           (ADC12CTL2 & (~(0XFEFF)))>>8
//ADC12CTL2 结束 ###################################################################
//ADC12MEM  开始 ###################################################################
//#define put_ADC12MEM(x)         ADC12CTL2=(ADC12CTL2 & 0XFEFF) | ((x & 0X0001) <<8)
//#define get_ADC12MEM            (ADC12CTL2 & (~(0XFEFF)))>>8
//ADC12MEM  结束 ###################################################################
//ADC12MCTL 开始 ###################################################################
#define put_ADC12MCTL0_ADC12INCH(x)   ADC12MCTL0=(ADC12MCTL0 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL0_ADC12INCH      (ADC12MCTL0 & (~(0XFFF0)))>>0
#define put_ADC12MCTL0_INCH(x)        ADC12MCTL0=(ADC12MCTL0 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL0_INCH           (ADC12MCTL0 & (~(0XFFF0)))>>0
#define put_ADC12MCTL0_SREF(x)        ADC12MCTL0=(ADC12MCTL0 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL0_SREF           (ADC12MCTL0 & (~(0XFF8F)))>>4
#define put_ADC12MCTL0_SREF1_0(x)     ADC12MCTL0=(ADC12MCTL0 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL0_SREF1_0        (ADC12MCTL0 & (~(0XFFCF)))>>4
#define put_ADC12MCTL0_SREF2(x)       ADC12MCTL0=(ADC12MCTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL0_SREF2          (ADC12MCTL0 & (~(0XFFBF)))>>6
#define put_ADC12MCTL0_ADC12EOS(x)    ADC12MCTL0=(ADC12MCTL0 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL0_ADC12EOS       (ADC12MCTL0 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL1_ADC12INCH(x)   ADC12MCTL1=(ADC12MCTL1 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL1_ADC12INCH      (ADC12MCTL1 & (~(0XFFF0)))>>0
#define put_ADC12MCTL1_INCH(x)        ADC12MCTL1=(ADC12MCTL1 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL1_INCH           (ADC12MCTL1 & (~(0XFFF0)))>>0
#define put_ADC12MCTL1_SREF(x)        ADC12MCTL1=(ADC12MCTL1 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL1_SREF           (ADC12MCTL1 & (~(0XFF8F)))>>4
#define put_ADC12MCTL1_SREF1_0(x)     ADC12MCTL1=(ADC12MCTL1 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL1_SREF1_0        (ADC12MCTL1 & (~(0XFFCF)))>>4
#define put_ADC12MCTL1_SREF2(x)       ADC12MCTL1=(ADC12MCTL1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL1_SREF2          (ADC12MCTL1 & (~(0XFFBF)))>>6
#define put_ADC12MCTL1_ADC12EOS(x)    ADC12MCTL1=(ADC12MCTL1 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL1_ADC12EOS       (ADC12MCTL1 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL2_ADC12INCH(x)   ADC12MCTL2=(ADC12MCTL2 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL2_ADC12INCH      (ADC12MCTL2 & (~(0XFFF0)))>>0
#define put_ADC12MCTL2_INCH(x)        ADC12MCTL2=(ADC12MCTL2 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL2_INCH           (ADC12MCTL2 & (~(0XFFF0)))>>0
#define put_ADC12MCTL2_SREF(x)        ADC12MCTL2=(ADC12MCTL2 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL2_SREF           (ADC12MCTL2 & (~(0XFF8F)))>>4
#define put_ADC12MCTL2_SREF1_0(x)     ADC12MCTL2=(ADC12MCTL2 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL2_SREF1_0        (ADC12MCTL2 & (~(0XFFCF)))>>4
#define put_ADC12MCTL2_SREF2(x)       ADC12MCTL2=(ADC12MCTL2 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL2_SREF2          (ADC12MCTL2 & (~(0XFFBF)))>>6
#define put_ADC12MCTL2_ADC12EOS(x)    ADC12MCTL2=(ADC12MCTL2 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL2_ADC12EOS       (ADC12MCTL2 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL3_ADC12INCH(x)   ADC12MCTL3=(ADC12MCTL3 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL3_ADC12INCH      (ADC12MCTL3 & (~(0XFFF0)))>>0
#define put_ADC12MCTL3_INCH(x)        ADC12MCTL3=(ADC12MCTL3 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL3_INCH           (ADC12MCTL3 & (~(0XFFF0)))>>0
#define put_ADC12MCTL3_SREF(x)        ADC12MCTL3=(ADC12MCTL3 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL3_SREF           (ADC12MCTL3 & (~(0XFF8F)))>>4
#define put_ADC12MCTL3_SREF1_0(x)     ADC12MCTL3=(ADC12MCTL3 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL3_SREF1_0        (ADC12MCTL3 & (~(0XFFCF)))>>4
#define put_ADC12MCTL3_SREF2(x)       ADC12MCTL3=(ADC12MCTL3 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL3_SREF2          (ADC12MCTL3 & (~(0XFFBF)))>>6
#define put_ADC12MCTL3_ADC12EOS(x)    ADC12MCTL3=(ADC12MCTL3 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL3_ADC12EOS       (ADC12MCTL3 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL4_ADC12INCH(x)   ADC12MCTL4=(ADC12MCTL4 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL4_ADC12INCH      (ADC12MCTL4 & (~(0XFFF0)))>>0
#define put_ADC12MCTL4_INCH(x)        ADC12MCTL4=(ADC12MCTL4 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL4_INCH           (ADC12MCTL4 & (~(0XFFF0)))>>0
#define put_ADC12MCTL4_SREF(x)        ADC12MCTL4=(ADC12MCTL4 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL4_SREF           (ADC12MCTL4 & (~(0XFF8F)))>>4
#define put_ADC12MCTL4_SREF1_0(x)     ADC12MCTL4=(ADC12MCTL4 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL4_SREF1_0        (ADC12MCTL4 & (~(0XFFCF)))>>4
#define put_ADC12MCTL4_SREF2(x)       ADC12MCTL4=(ADC12MCTL4 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL4_SREF2          (ADC12MCTL4 & (~(0XFFBF)))>>6
#define put_ADC12MCTL4_ADC12EOS(x)    ADC12MCTL4=(ADC12MCTL4 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL4_ADC12EOS       (ADC12MCTL4 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL5_ADC12INCH(x)   ADC12MCTL5=(ADC12MCTL5 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL5_ADC12INCH      (ADC12MCTL5 & (~(0XFFF0)))>>0
#define put_ADC12MCTL5_INCH(x)        ADC12MCTL5=(ADC12MCTL5 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL5_INCH           (ADC12MCTL5 & (~(0XFFF0)))>>0
#define put_ADC12MCTL5_SREF(x)        ADC12MCTL5=(ADC12MCTL5 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL5_SREF           (ADC12MCTL5 & (~(0XFF8F)))>>4
#define put_ADC12MCTL5_SREF1_0(x)     ADC12MCTL5=(ADC12MCTL5 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL5_SREF1_0        (ADC12MCTL5 & (~(0XFFCF)))>>4
#define put_ADC12MCTL5_SREF2(x)       ADC12MCTL5=(ADC12MCTL5 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL5_SREF2          (ADC12MCTL5 & (~(0XFFBF)))>>6
#define put_ADC12MCTL5_ADC12EOS(x)    ADC12MCTL5=(ADC12MCTL5 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL5_ADC12EOS       (ADC12MCTL5 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL6_ADC12INCH(x)   ADC12MCTL6=(ADC12MCTL6 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL6_ADC12INCH      (ADC12MCTL6 & (~(0XFFF0)))>>0
#define put_ADC12MCTL6_INCH(x)        ADC12MCTL6=(ADC12MCTL6 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL6_INCH           (ADC12MCTL6 & (~(0XFFF0)))>>0
#define put_ADC12MCTL6_SREF(x)        ADC12MCTL6=(ADC12MCTL6 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL6_SREF           (ADC12MCTL6 & (~(0XFF8F)))>>4
#define put_ADC12MCTL6_SREF1_0(x)     ADC12MCTL6=(ADC12MCTL6 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL6_SREF1_0        (ADC12MCTL6 & (~(0XFFCF)))>>4
#define put_ADC12MCTL6_SREF2(x)       ADC12MCTL6=(ADC12MCTL6 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL6_SREF2          (ADC12MCTL6 & (~(0XFFBF)))>>6
#define put_ADC12MCTL6_ADC12EOS(x)    ADC12MCTL6=(ADC12MCTL6 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL6_ADC12EOS       (ADC12MCTL6 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL7_ADC12INCH(x)   ADC12MCTL7=(ADC12MCTL7 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL7_ADC12INCH      (ADC12MCTL7 & (~(0XFFF0)))>>0
#define put_ADC12MCTL7_INCH(x)        ADC12MCTL7=(ADC12MCTL7 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL7_INCH           (ADC12MCTL7 & (~(0XFFF0)))>>0
#define put_ADC12MCTL7_SREF(x)        ADC12MCTL7=(ADC12MCTL7 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL7_SREF           (ADC12MCTL7 & (~(0XFF8F)))>>4
#define put_ADC12MCTL7_SREF1_0(x)     ADC12MCTL7=(ADC12MCTL7 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL7_SREF1_0        (ADC12MCTL7 & (~(0XFFCF)))>>4
#define put_ADC12MCTL7_SREF2(x)       ADC12MCTL7=(ADC12MCTL7 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL7_SREF2          (ADC12MCTL7 & (~(0XFFBF)))>>6
#define put_ADC12MCTL7_ADC12EOS(x)    ADC12MCTL7=(ADC12MCTL7 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL7_ADC12EOS       (ADC12MCTL7 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL8_ADC12INCH(x)   ADC12MCTL8=(ADC12MCTL8 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL8_ADC12INCH      (ADC12MCTL8 & (~(0XFFF0)))>>0
#define put_ADC12MCTL8_INCH(x)        ADC12MCTL8=(ADC12MCTL8 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL8_INCH           (ADC12MCTL8 & (~(0XFFF0)))>>0
#define put_ADC12MCTL8_SREF(x)        ADC12MCTL8=(ADC12MCTL8 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL8_SREF           (ADC12MCTL8 & (~(0XFF8F)))>>4
#define put_ADC12MCTL8_SREF1_0(x)     ADC12MCTL8=(ADC12MCTL8 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL8_SREF1_0        (ADC12MCTL8 & (~(0XFFCF)))>>4
#define put_ADC12MCTL8_SREF2(x)       ADC12MCTL8=(ADC12MCTL8 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL8_SREF2          (ADC12MCTL8 & (~(0XFFBF)))>>6
#define put_ADC12MCTL8_ADC12EOS(x)    ADC12MCTL8=(ADC12MCTL8 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL8_ADC12EOS       (ADC12MCTL8 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL9_ADC12INCH(x)   ADC12MCTL9=(ADC12MCTL9 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL9_ADC12INCH      (ADC12MCTL9 & (~(0XFFF0)))>>0
#define put_ADC12MCTL9_INCH(x)        ADC12MCTL9=(ADC12MCTL9 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL9_INCH           (ADC12MCTL9 & (~(0XFFF0)))>>0
#define put_ADC12MCTL9_SREF(x)        ADC12MCTL9=(ADC12MCTL9 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL9_SREF           (ADC12MCTL9 & (~(0XFF8F)))>>4
#define put_ADC12MCTL9_SREF1_0(x)     ADC12MCTL9=(ADC12MCTL9 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL9_SREF1_0        (ADC12MCTL9 & (~(0XFFCF)))>>4
#define put_ADC12MCTL9_SREF2(x)       ADC12MCTL9=(ADC12MCTL9 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL9_SREF2          (ADC12MCTL9 & (~(0XFFBF)))>>6
#define put_ADC12MCTL9_ADC12EOS(x)    ADC12MCTL9=(ADC12MCTL9 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL9_ADC12EOS       (ADC12MCTL9 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL10_ADC12INCH(x)   ADC12MCTL10=(ADC12MCTL10 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL10_ADC12INCH      (ADC12MCTL10 & (~(0XFFF0)))>>0
#define put_ADC12MCTL10_INCH(x)        ADC12MCTL10=(ADC12MCTL10 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL10_INCH           (ADC12MCTL10 & (~(0XFFF0)))>>0
#define put_ADC12MCTL10_SREF(x)        ADC12MCTL10=(ADC12MCTL10 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL10_SREF           (ADC12MCTL10 & (~(0XFF8F)))>>4
#define put_ADC12MCTL10_SREF1_0(x)     ADC12MCTL10=(ADC12MCTL10 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL10_SREF1_0        (ADC12MCTL10 & (~(0XFFCF)))>>4
#define put_ADC12MCTL10_SREF2(x)       ADC12MCTL10=(ADC12MCTL10 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL10_SREF2          (ADC12MCTL10 & (~(0XFFBF)))>>6
#define put_ADC12MCTL10_ADC12EOS(x)    ADC12MCTL10=(ADC12MCTL10 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL10_ADC12EOS       (ADC12MCTL10 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL11_ADC12INCH(x)   ADC12MCTL11=(ADC12MCTL11 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL11_ADC12INCH      (ADC12MCTL11 & (~(0XFFF0)))>>0
#define put_ADC12MCTL11_INCH(x)        ADC12MCTL11=(ADC12MCTL11 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL11_INCH           (ADC12MCTL11 & (~(0XFFF0)))>>0
#define put_ADC12MCTL11_SREF(x)        ADC12MCTL11=(ADC12MCTL11 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL11_SREF           (ADC12MCTL11 & (~(0XFF8F)))>>4
#define put_ADC12MCTL11_SREF1_0(x)     ADC12MCTL11=(ADC12MCTL11 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL11_SREF1_0        (ADC12MCTL11 & (~(0XFFCF)))>>4
#define put_ADC12MCTL11_SREF2(x)       ADC12MCTL11=(ADC12MCTL11 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL11_SREF2          (ADC12MCTL11 & (~(0XFFBF)))>>6
#define put_ADC12MCTL11_ADC12EOS(x)    ADC12MCTL11=(ADC12MCTL11 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL11_ADC12EOS       (ADC12MCTL11 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL12_ADC12INCH(x)   ADC12MCTL12=(ADC12MCTL12 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL12_ADC12INCH      (ADC12MCTL12 & (~(0XFFF0)))>>0
#define put_ADC12MCTL12_INCH(x)        ADC12MCTL12=(ADC12MCTL12 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL12_INCH           (ADC12MCTL12 & (~(0XFFF0)))>>0
#define put_ADC12MCTL12_SREF(x)        ADC12MCTL12=(ADC12MCTL12 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL12_SREF           (ADC12MCTL12 & (~(0XFF8F)))>>4
#define put_ADC12MCTL12_SREF1_0(x)     ADC12MCTL12=(ADC12MCTL12 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL12_SREF1_0        (ADC12MCTL12 & (~(0XFFCF)))>>4
#define put_ADC12MCTL12_SREF2(x)       ADC12MCTL12=(ADC12MCTL12 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL12_SREF2          (ADC12MCTL12 & (~(0XFFBF)))>>6
#define put_ADC12MCTL12_ADC12EOS(x)    ADC12MCTL12=(ADC12MCTL12 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL12_ADC12EOS       (ADC12MCTL12 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL13_ADC12INCH(x)   ADC12MCTL13=(ADC12MCTL13 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL13_ADC12INCH      (ADC12MCTL13 & (~(0XFFF0)))>>0
#define put_ADC12MCTL13_INCH(x)        ADC12MCTL13=(ADC12MCTL13 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL13_INCH           (ADC12MCTL13 & (~(0XFFF0)))>>0
#define put_ADC12MCTL13_SREF(x)        ADC12MCTL13=(ADC12MCTL13 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL13_SREF           (ADC12MCTL13 & (~(0XFF8F)))>>4
#define put_ADC12MCTL13_SREF1_0(x)     ADC12MCTL13=(ADC12MCTL13 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL13_SREF1_0        (ADC12MCTL13 & (~(0XFFCF)))>>4
#define put_ADC12MCTL13_SREF2(x)       ADC12MCTL13=(ADC12MCTL13 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL13_SREF2          (ADC12MCTL13 & (~(0XFFBF)))>>6
#define put_ADC12MCTL13_ADC12EOS(x)    ADC12MCTL13=(ADC12MCTL13 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL13_ADC12EOS       (ADC12MCTL13 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL14_ADC12INCH(x)   ADC12MCTL14=(ADC12MCTL14 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL14_ADC12INCH      (ADC12MCTL14 & (~(0XFFF0)))>>0
#define put_ADC12MCTL14_INCH(x)        ADC12MCTL14=(ADC12MCTL14 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL14_INCH           (ADC12MCTL14 & (~(0XFFF0)))>>0
#define put_ADC12MCTL14_SREF(x)        ADC12MCTL14=(ADC12MCTL14 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL14_SREF           (ADC12MCTL14 & (~(0XFF8F)))>>4
#define put_ADC12MCTL14_SREF1_0(x)     ADC12MCTL14=(ADC12MCTL14 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL14_SREF1_0        (ADC12MCTL14 & (~(0XFFCF)))>>4
#define put_ADC12MCTL14_SREF2(x)       ADC12MCTL14=(ADC12MCTL14 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL14_SREF2          (ADC12MCTL14 & (~(0XFFBF)))>>6
#define put_ADC12MCTL14_ADC12EOS(x)    ADC12MCTL14=(ADC12MCTL14 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL14_ADC12EOS       (ADC12MCTL14 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12MCTL15_ADC12INCH(x)   ADC12MCTL15=(ADC12MCTL15 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL15_ADC12INCH      (ADC12MCTL15 & (~(0XFFF0)))>>0
#define put_ADC12MCTL15_INCH(x)        ADC12MCTL15=(ADC12MCTL15 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12MCTL15_INCH           (ADC12MCTL15 & (~(0XFFF0)))>>0
#define put_ADC12MCTL15_SREF(x)        ADC12MCTL15=(ADC12MCTL15 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12MCTL15_SREF           (ADC12MCTL15 & (~(0XFF8F)))>>4
#define put_ADC12MCTL15_SREF1_0(x)     ADC12MCTL15=(ADC12MCTL15 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12MCTL15_SREF1_0        (ADC12MCTL15 & (~(0XFFCF)))>>4
#define put_ADC12MCTL15_SREF2(x)       ADC12MCTL15=(ADC12MCTL15 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12MCTL15_SREF2          (ADC12MCTL15 & (~(0XFFBF)))>>6
#define put_ADC12MCTL15_ADC12EOS(x)    ADC12MCTL15=(ADC12MCTL15 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12MCTL15_ADC12EOS       (ADC12MCTL15 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
//ADC12MCTL 结束 ###############################################################################
//ADC12IE 开始 #################################################################################
#define put_ADC12IE0(x)                ADC12IE=(ADC12IE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_ADC12IE0                   (ADC12IE & (~(0XFFFE)))>>0
#define put_ADC12IE1(x)                ADC12IE=(ADC12IE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_ADC12IE1                   (ADC12IE & (~(0XFFFD)))>>1
#define put_ADC12IE2(x)                ADC12IE=(ADC12IE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_ADC12IE2                   (ADC12IE & (~(0XFFFB)))>>2
#define put_ADC12IE3(x)                ADC12IE=(ADC12IE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_ADC12IE3                   (ADC12IE & (~(0XFFF7)))>>3
#define put_ADC12IE4(x)                ADC12IE=(ADC12IE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_ADC12IE4                   (ADC12IE & (~(0XFFEF)))>>4
#define put_ADC12IE5(x)                ADC12IE=(ADC12IE & 0XFFDF) | ((x & 0X0001) <<5)
#define get_ADC12IE5                   (ADC12IE & (~(0XFFDF)))>>5
#define put_ADC12IE6(x)                ADC12IE=(ADC12IE & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12IE6                   (ADC12IE & (~(0XFFBF)))>>6
#define put_ADC12IE7(x)                ADC12IE=(ADC12IE & 0XFF7F) | ((x & 0X0001) <<7)
#define get_ADC12IE7                   (ADC12IE & (~(0XFF7F)))>>7
#define put_ADC12IE8(x)                ADC12IE=(ADC12IE & 0XFEFF) | ((x & 0X0001) <<8)
#define get_ADC12IE8                   (ADC12IE & (~(0XFEFF)))>>8
#define put_ADC12IE9(x)                ADC12IE=(ADC12IE & 0XFDF) | ((x & 0X0001) <<9)
#define get_ADC12IE9                   (ADC12IE & (~(0XFDF)))>>9
#define put_ADC12IE10(x)               ADC12IE=(ADC12IE & 0XFBFF) | ((x & 0X0001) <<10)
#define get_ADC12IE10                  (ADC12IE & (~(0XFBFF)))>>10
#define put_ADC12IE11(x)               ADC12IE=(ADC12IE & 0XF7FF) | ((x & 0X0001) <<11)
#define get_ADC12IE11                  (ADC12IE & (~(0XF7FF)))>>11
#define put_ADC12IE12(x)               ADC12IE=(ADC12IE & 0XEFFF) | ((x & 0X0001) <<12)
#define get_ADC12IE12                  (ADC12IE & (~(0XEFFF)))>>12
#define put_ADC12IE13(x)               ADC12IE=(ADC12IE & 0XDFFF) | ((x & 0X0001) <<13)
#define get_ADC12IE13                  (ADC12IE & (~(0XDFFF)))>>13
#define put_ADC12IE14(x)               ADC12IE=(ADC12IE & 0XBFFF) | ((x & 0X0001) <<14)
#define get_ADC12IE14                  (ADC12IE & (~(0XBFFF)))>>14
#define put_ADC12IE15(x)               ADC12IE=(ADC12IE & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_ADC12IE15                  (ADC12IE & (~(0X7FFF)))>>15
//ADC12IE 结束 #################################################################################
//ADC12IFG 开始 #################################################################################
#define put_ADC12IFG0(x)                ADC12IFG=(ADC12IFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_ADC12IFG0                   (ADC12IFG & (~(0XFFFE)))>>0
#define put_ADC12IFG1(x)                ADC12IFG=(ADC12IFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_ADC12IFG1                   (ADC12IFG & (~(0XFFFD)))>>1
#define put_ADC12IFG2(x)                ADC12IFG=(ADC12IFG & 0XFFFB) | ((x & 0X0001) <<2)
#define get_ADC12IFG2                   (ADC12IFG & (~(0XFFFB)))>>2
#define put_ADC12IFG3(x)                ADC12IFG=(ADC12IFG & 0XFFF7) | ((x & 0X0001) <<3)
#define get_ADC12IFG3                   (ADC12IFG & (~(0XFFF7)))>>3
#define put_ADC12IFG4(x)                ADC12IFG=(ADC12IFG & 0XFFEF) | ((x & 0X0001) <<4)
#define get_ADC12IFG4                   (ADC12IFG & (~(0XFFEF)))>>4
#define put_ADC12IFG5(x)                ADC12IFG=(ADC12IFG & 0XFFDF) | ((x & 0X0001) <<5)
#define get_ADC12IFG5                   (ADC12IFG & (~(0XFFDF)))>>5
#define put_ADC12IFG6(x)                ADC12IFG=(ADC12IFG & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12IFG6                   (ADC12IFG & (~(0XFFBF)))>>6
#define put_ADC12IFG7(x)                ADC12IFG=(ADC12IFG & 0XFF7F) | ((x & 0X0001) <<7)
#define get_ADC12IFG7                   (ADC12IFG & (~(0XFF7F)))>>7
#define put_ADC12IFG8(x)                ADC12IFG=(ADC12IFG & 0XFEFF) | ((x & 0X0001) <<8)
#define get_ADC12IFG8                   (ADC12IFG & (~(0XFEFF)))>>8
#define put_ADC12IFG9(x)                ADC12IFG=(ADC12IFG & 0XFDF) | ((x & 0X0001) <<9)
#define get_ADC12IFG9                   (ADC12IFG & (~(0XFDF)))>>9
#define put_ADC12IFG10(x)               ADC12IFG=(ADC12IFG & 0XFBFF) | ((x & 0X0001) <<10)
#define get_ADC12IFG10                  (ADC12IFG & (~(0XFBFF)))>>10
#define put_ADC12IFG11(x)               ADC12IFG=(ADC12IFG & 0XF7FF) | ((x & 0X0001) <<11)
#define get_ADC12IFG11                  (ADC12IFG & (~(0XF7FF)))>>11
#define put_ADC12IFG12(x)               ADC12IFG=(ADC12IFG & 0XEFFF) | ((x & 0X0001) <<12)
#define get_ADC12IFG12                  (ADC12IFG & (~(0XEFFF)))>>12
#define put_ADC12IFG13(x)               ADC12IFG=(ADC12IFG & 0XDFFF) | ((x & 0X0001) <<13)
#define get_ADC12IFG13                  (ADC12IFG & (~(0XDFFF)))>>13
#define put_ADC12IFG14(x)               ADC12IFG=(ADC12IFG & 0XBFFF) | ((x & 0X0001) <<14)
#define get_ADC12IFG14                  (ADC12IFG & (~(0XBFFF)))>>14
#define put_ADC12IFG15(x)               ADC12IFG=(ADC12IFG & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_ADC12IFG15                  (ADC12IFG & (~(0X7FFF)))>>15
//ADC12IFG 结束 #################################################################################
//ADC12IV 结束 ##################################################################################
#define put_ADC12IV(x)                  ADC12IV=(ADC12IV & 0XFF3E) | ((x & 0X003E) <<0)
#define get_ADC12IV                     (ADC12IV & (~(0XFF3E)))>>0
//ADC12IV 结束 ##################################################################################
//适合于对照寄存器图编写应用程序(开始)-------------------------------------------------------------
#define put_ADC12_0_INCH(x)        ADC12MCTL0=(ADC12MCTL0 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_0_INCH           (ADC12MCTL0 & (~(0XFFF0)))>>0
#define put_ADC12_0_INCH(x)        ADC12MCTL0=(ADC12MCTL0 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_0_INCH           (ADC12MCTL0 & (~(0XFFF0)))>>0
#define put_ADC12_0_SREF(x)        ADC12MCTL0=(ADC12MCTL0 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_0_SREF           (ADC12MCTL0 & (~(0XFF8F)))>>4
#define put_ADC12_0_SREF1_0(x)     ADC12MCTL0=(ADC12MCTL0 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_0_SREF1_0        (ADC12MCTL0 & (~(0XFFCF)))>>4
#define put_ADC12_0_SREF2(x)       ADC12MCTL0=(ADC12MCTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_0_SREF2          (ADC12MCTL0 & (~(0XFFBF)))>>6
#define put_ADC12_0_ADC12EOS(x)    ADC12MCTL0=(ADC12MCTL0 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_0_ADC12EOS       (ADC12MCTL0 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_1_INCH(x)        ADC12MCTL1=(ADC12MCTL1 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_1_INCH           (ADC12MCTL1 & (~(0XFFF0)))>>0
#define put_ADC12_1_INCH(x)        ADC12MCTL1=(ADC12MCTL1 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_1_INCH           (ADC12MCTL1 & (~(0XFFF0)))>>0
#define put_ADC12_1_SREF(x)        ADC12MCTL1=(ADC12MCTL1 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_1_SREF           (ADC12MCTL1 & (~(0XFF8F)))>>4
#define put_ADC12_1_SREF1_0(x)     ADC12MCTL1=(ADC12MCTL1 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_1_SREF1_0        (ADC12MCTL1 & (~(0XFFCF)))>>4
#define put_ADC12_1_SREF2(x)       ADC12MCTL1=(ADC12MCTL1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_1_SREF2          (ADC12MCTL1 & (~(0XFFBF)))>>6
#define put_ADC12_1_ADC12EOS(x)    ADC12MCTL1=(ADC12MCTL1 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_1_ADC12EOS       (ADC12MCTL1 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_2_INCH(x)        ADC12MCTL2=(ADC12MCTL2 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_2_INCH           (ADC12MCTL2 & (~(0XFFF0)))>>0
#define put_ADC12_2_INCH(x)        ADC12MCTL2=(ADC12MCTL2 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_2_INCH           (ADC12MCTL2 & (~(0XFFF0)))>>0
#define put_ADC12_2_SREF(x)        ADC12MCTL2=(ADC12MCTL2 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_2_SREF           (ADC12MCTL2 & (~(0XFF8F)))>>4
#define put_ADC12_2_SREF1_0(x)     ADC12MCTL2=(ADC12MCTL2 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_2_SREF1_0        (ADC12MCTL2 & (~(0XFFCF)))>>4
#define put_ADC12_2_SREF2(x)       ADC12MCTL2=(ADC12MCTL2 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_2_SREF2          (ADC12MCTL2 & (~(0XFFBF)))>>6
#define put_ADC12_2_ADC12EOS(x)    ADC12MCTL2=(ADC12MCTL2 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_2_ADC12EOS       (ADC12MCTL2 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_3_INCH(x)        ADC12MCTL3=(ADC12MCTL3 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_3_INCH           (ADC12MCTL3 & (~(0XFFF0)))>>0
#define put_ADC12_3_INCH(x)        ADC12MCTL3=(ADC12MCTL3 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_3_INCH           (ADC12MCTL3 & (~(0XFFF0)))>>0
#define put_ADC12_3_SREF(x)        ADC12MCTL3=(ADC12MCTL3 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_3_SREF           (ADC12MCTL3 & (~(0XFF8F)))>>4
#define put_ADC12_3_SREF1_0(x)     ADC12MCTL3=(ADC12MCTL3 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_3_SREF1_0        (ADC12MCTL3 & (~(0XFFCF)))>>4
#define put_ADC12_3_SREF2(x)       ADC12MCTL3=(ADC12MCTL3 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_3_SREF2          (ADC12MCTL3 & (~(0XFFBF)))>>6
#define put_ADC12_3_ADC12EOS(x)    ADC12MCTL3=(ADC12MCTL3 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_3_ADC12EOS       (ADC12MCTL3 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_4_INCH(x)        ADC12MCTL4=(ADC12MCTL4 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_4_INCH           (ADC12MCTL4 & (~(0XFFF0)))>>0
#define put_ADC12_4_INCH(x)        ADC12MCTL4=(ADC12MCTL4 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_4_INCH           (ADC12MCTL4 & (~(0XFFF0)))>>0
#define put_ADC12_4_SREF(x)        ADC12MCTL4=(ADC12MCTL4 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_4_SREF           (ADC12MCTL4 & (~(0XFF8F)))>>4
#define put_ADC12_4_SREF1_0(x)     ADC12MCTL4=(ADC12MCTL4 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_4_SREF1_0        (ADC12MCTL4 & (~(0XFFCF)))>>4
#define put_ADC12_4_SREF2(x)       ADC12MCTL4=(ADC12MCTL4 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_4_SREF2          (ADC12MCTL4 & (~(0XFFBF)))>>6
#define put_ADC12_4_ADC12EOS(x)    ADC12MCTL4=(ADC12MCTL4 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_4_ADC12EOS       (ADC12MCTL4 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_5_INCH(x)        ADC12MCTL5=(ADC12MCTL5 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_5_INCH           (ADC12MCTL5 & (~(0XFFF0)))>>0
#define put_ADC12_5_INCH(x)        ADC12MCTL5=(ADC12MCTL5 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_5_INCH           (ADC12MCTL5 & (~(0XFFF0)))>>0
#define put_ADC12_5_SREF(x)        ADC12MCTL5=(ADC12MCTL5 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_5_SREF           (ADC12MCTL5 & (~(0XFF8F)))>>4
#define put_ADC12_5_SREF1_0(x)     ADC12MCTL5=(ADC12MCTL5 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_5_SREF1_0        (ADC12MCTL5 & (~(0XFFCF)))>>4
#define put_ADC12_5_SREF2(x)       ADC12MCTL5=(ADC12MCTL5 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_5_SREF2          (ADC12MCTL5 & (~(0XFFBF)))>>6
#define put_ADC12_5_ADC12EOS(x)    ADC12MCTL5=(ADC12MCTL5 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_5_ADC12EOS       (ADC12MCTL5 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_6_INCH(x)        ADC12MCTL6=(ADC12MCTL6 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_6_INCH           (ADC12MCTL6 & (~(0XFFF0)))>>0
#define put_ADC12_6_INCH(x)        ADC12MCTL6=(ADC12MCTL6 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_6_INCH           (ADC12MCTL6 & (~(0XFFF0)))>>0
#define put_ADC12_6_SREF(x)        ADC12MCTL6=(ADC12MCTL6 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_6_SREF           (ADC12MCTL6 & (~(0XFF8F)))>>4
#define put_ADC12_6_SREF1_0(x)     ADC12MCTL6=(ADC12MCTL6 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_6_SREF1_0        (ADC12MCTL6 & (~(0XFFCF)))>>4
#define put_ADC12_6_SREF2(x)       ADC12MCTL6=(ADC12MCTL6 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_6_SREF2          (ADC12MCTL6 & (~(0XFFBF)))>>6
#define put_ADC12_6_ADC12EOS(x)    ADC12MCTL6=(ADC12MCTL6 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_6_ADC12EOS       (ADC12MCTL6 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_7_INCH(x)        ADC12MCTL7=(ADC12MCTL7 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_7_INCH           (ADC12MCTL7 & (~(0XFFF0)))>>0
#define put_ADC12_7_INCH(x)        ADC12MCTL7=(ADC12MCTL7 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_7_INCH           (ADC12MCTL7 & (~(0XFFF0)))>>0
#define put_ADC12_7_SREF(x)        ADC12MCTL7=(ADC12MCTL7 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_7_SREF           (ADC12MCTL7 & (~(0XFF8F)))>>4
#define put_ADC12_7_SREF1_0(x)     ADC12MCTL7=(ADC12MCTL7 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_7_SREF1_0        (ADC12MCTL7 & (~(0XFFCF)))>>4
#define put_ADC12_7_SREF2(x)       ADC12MCTL7=(ADC12MCTL7 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_7_SREF2          (ADC12MCTL7 & (~(0XFFBF)))>>6
#define put_ADC12_7_ADC12EOS(x)    ADC12MCTL7=(ADC12MCTL7 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_7_ADC12EOS       (ADC12MCTL7 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_8_INCH(x)        ADC12MCTL8=(ADC12MCTL8 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_8_INCH           (ADC12MCTL8 & (~(0XFFF0)))>>0
#define put_ADC12_8_INCH(x)        ADC12MCTL8=(ADC12MCTL8 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_8_INCH           (ADC12MCTL8 & (~(0XFFF0)))>>0
#define put_ADC12_8_SREF(x)        ADC12MCTL8=(ADC12MCTL8 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_8_SREF           (ADC12MCTL8 & (~(0XFF8F)))>>4
#define put_ADC12_8_SREF1_0(x)     ADC12MCTL8=(ADC12MCTL8 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_8_SREF1_0        (ADC12MCTL8 & (~(0XFFCF)))>>4
#define put_ADC12_8_SREF2(x)       ADC12MCTL8=(ADC12MCTL8 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_8_SREF2          (ADC12MCTL8 & (~(0XFFBF)))>>6
#define put_ADC12_8_ADC12EOS(x)    ADC12MCTL8=(ADC12MCTL8 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_8_ADC12EOS       (ADC12MCTL8 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_9_INCH(x)        ADC12MCTL9=(ADC12MCTL9 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_9_INCH           (ADC12MCTL9 & (~(0XFFF0)))>>0
#define put_ADC12_9_INCH(x)        ADC12MCTL9=(ADC12MCTL9 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_9_INCH           (ADC12MCTL9 & (~(0XFFF0)))>>0
#define put_ADC12_9_SREF(x)        ADC12MCTL9=(ADC12MCTL9 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_9_SREF           (ADC12MCTL9 & (~(0XFF8F)))>>4
#define put_ADC12_9_SREF1_0(x)     ADC12MCTL9=(ADC12MCTL9 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_9_SREF1_0        (ADC12MCTL9 & (~(0XFFCF)))>>4
#define put_ADC12_9_SREF2(x)       ADC12MCTL9=(ADC12MCTL9 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_9_SREF2          (ADC12MCTL9 & (~(0XFFBF)))>>6
#define put_ADC12_9_ADC12EOS(x)    ADC12MCTL9=(ADC12MCTL9 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_9_ADC12EOS       (ADC12MCTL9 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_10_INCH(x)       ADC12MCTL10=(ADC12MCTL10 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_10_INCH          (ADC12MCTL10 & (~(0XFFF0)))>>0
#define put_ADC12_10_INCH(x)       ADC12MCTL10=(ADC12MCTL10 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_10_INCH          (ADC12MCTL10 & (~(0XFFF0)))>>0
#define put_ADC12_10_SREF(x)       ADC12MCTL10=(ADC12MCTL10 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_10_SREF          (ADC12MCTL10 & (~(0XFF8F)))>>4
#define put_ADC12_10_SREF1_0(x)    ADC12MCTL10=(ADC12MCTL10 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_10_SREF1_0       (ADC12MCTL10 & (~(0XFFCF)))>>4
#define put_ADC12_10_SREF2(x)      ADC12MCTL10=(ADC12MCTL10 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_10_SREF2         (ADC12MCTL10 & (~(0XFFBF)))>>6
#define put_ADC12_10_ADC12EOS(x)   ADC12MCTL10=(ADC12MCTL10 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_10_ADC12EOS      (ADC12MCTL10 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_11_INCH(x)       ADC12MCTL11=(ADC12MCTL11 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_11_INCH          (ADC12MCTL11 & (~(0XFFF0)))>>0
#define put_ADC12_11_INCH(x)        ADC12MCTL11=(ADC12MCTL11 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_11_INCH           (ADC12MCTL11 & (~(0XFFF0)))>>0
#define put_ADC12_11_SREF(x)        ADC12MCTL11=(ADC12MCTL11 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_11_SREF           (ADC12MCTL11 & (~(0XFF8F)))>>4
#define put_ADC12_11_SREF1_0(x)     ADC12MCTL11=(ADC12MCTL11 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_11_SREF1_0        (ADC12MCTL11 & (~(0XFFCF)))>>4
#define put_ADC12_11_SREF2(x)       ADC12MCTL11=(ADC12MCTL11 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_11_SREF2          (ADC12MCTL11 & (~(0XFFBF)))>>6
#define put_ADC12_11_ADC12EOS(x)    ADC12MCTL11=(ADC12MCTL11 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_11_ADC12EOS       (ADC12MCTL11 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_12_INCH(x)       ADC12MCTL12=(ADC12MCTL12 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_12_INCH          (ADC12MCTL12 & (~(0XFFF0)))>>0
#define put_ADC12_12_INCH(x)       ADC12MCTL12=(ADC12MCTL12 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_12_INCH          (ADC12MCTL12 & (~(0XFFF0)))>>0
#define put_ADC12_12_SREF(x)       ADC12MCTL12=(ADC12MCTL12 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_12_SREF          (ADC12MCTL12 & (~(0XFF8F)))>>4
#define put_ADC12_12_SREF1_0(x)    ADC12MCTL12=(ADC12MCTL12 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_12_SREF1_0       (ADC12MCTL12 & (~(0XFFCF)))>>4
#define put_ADC12_12_SREF2(x)      ADC12MCTL12=(ADC12MCTL12 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_12_SREF2         (ADC12MCTL12 & (~(0XFFBF)))>>6
#define put_ADC12_12_ADC12EOS(x)    ADC12MCTL12=(ADC12MCTL12 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_12_ADC12EOS       (ADC12MCTL12 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_13_INCH(x)        ADC12MCTL13=(ADC12MCTL13 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_13_INCH           (ADC12MCTL13 & (~(0XFFF0)))>>0
#define put_ADC12_13_INCH(x)        ADC12MCTL13=(ADC12MCTL13 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_13_INCH           (ADC12MCTL13 & (~(0XFFF0)))>>0
#define put_ADC12_13_SREF(x)        ADC12MCTL13=(ADC12MCTL13 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_13_SREF           (ADC12MCTL13 & (~(0XFF8F)))>>4
#define put_ADC12_13_SREF1_0(x)     ADC12MCTL13=(ADC12MCTL13 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_13_SREF1_0        (ADC12MCTL13 & (~(0XFFCF)))>>4
#define put_ADC12_13_SREF2(x)       ADC12MCTL13=(ADC12MCTL13 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_13_SREF2          (ADC12MCTL13 & (~(0XFFBF)))>>6
#define put_ADC12_13_ADC12EOS(x)    ADC12MCTL13=(ADC12MCTL13 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_13_ADC12EOS       (ADC12MCTL13 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_14_INCH(x)        ADC12MCTL14=(ADC12MCTL14 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_14_INCH           (ADC12MCTL14 & (~(0XFFF0)))>>0
#define put_ADC12_14_INCH(x)        ADC12MCTL14=(ADC12MCTL14 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_14_INCH           (ADC12MCTL14 & (~(0XFFF0)))>>0
#define put_ADC12_14_SREF(x)        ADC12MCTL14=(ADC12MCTL14 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_14_SREF           (ADC12MCTL14 & (~(0XFF8F)))>>4
#define put_ADC12_14_SREF1_0(x)     ADC12MCTL14=(ADC12MCTL14 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_14_SREF1_0        (ADC12MCTL14 & (~(0XFFCF)))>>4
#define put_ADC12_14_SREF2(x)       ADC12MCTL14=(ADC12MCTL14 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_14_SREF2          (ADC12MCTL14 & (~(0XFFBF)))>>6
#define put_ADC12_14_ADC12EOS(x)    ADC12MCTL14=(ADC12MCTL14 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_14_ADC12EOS       (ADC12MCTL14 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_15_INCH(x)        ADC12MCTL15=(ADC12MCTL15 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_15_INCH           (ADC12MCTL15 & (~(0XFFF0)))>>0
#define put_ADC12_15_INCH(x)        ADC12MCTL15=(ADC12MCTL15 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_15_INCH           (ADC12MCTL15 & (~(0XFFF0)))>>0
#define put_ADC12_15_SREF(x)        ADC12MCTL15=(ADC12MCTL15 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_15_SREF           (ADC12MCTL15 & (~(0XFF8F)))>>4
#define put_ADC12_15_SREF1_0(x)     ADC12MCTL15=(ADC12MCTL15 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_15_SREF1_0        (ADC12MCTL15 & (~(0XFFCF)))>>4
#define put_ADC12_15_SREF2(x)       ADC12MCTL15=(ADC12MCTL15 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_15_SREF2          (ADC12MCTL15 & (~(0XFFBF)))>>6
#define put_ADC12_15_ADC12EOS(x)    ADC12MCTL15=(ADC12MCTL15 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_15_ADC12EOS       (ADC12MCTL15 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
//适合于对照原寄存器编写应用程序(结束)-------------------------------------------------------------
//适合于对照原理图编写应用程序(开始)-------------------------------------------------------------
#define put_ADC0_INCH(x)        ADC12MCTL0=(ADC12MCTL0 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC0_INCH           (ADC12MCTL0 & (~(0XFFF0)))>>0
#define put_ADC0_SREF(x)        ADC12MCTL0=(ADC12MCTL0 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC0_SREF           (ADC12MCTL0 & (~(0XFF8F)))>>4
#define put_ADC0_SREF1_0(x)     ADC12MCTL0=(ADC12MCTL0 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC0_SREF1_0        (ADC12MCTL0 & (~(0XFFCF)))>>4
#define put_ADC0_SREF2(x)       ADC12MCTL0=(ADC12MCTL0 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC0_SREF2          (ADC12MCTL0 & (~(0XFFBF)))>>6
#define put_ADC0_ADC12EOS(x)    ADC12MCTL0=(ADC12MCTL0 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC0_ADC12EOS       (ADC12MCTL0 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC1_INCH(x)        ADC12MCTL1=(ADC12MCTL1 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC1_INCH           (ADC12MCTL1 & (~(0XFFF0)))>>0
#define put_ADC1_SREF(x)        ADC12MCTL1=(ADC12MCTL1 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC1_SREF           (ADC12MCTL1 & (~(0XFF8F)))>>4
#define put_ADC1_SREF1_0(x)     ADC12MCTL1=(ADC12MCTL1 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC1_SREF1_0        (ADC12MCTL1 & (~(0XFFCF)))>>4
#define put_ADC1_SREF2(x)       ADC12MCTL1=(ADC12MCTL1 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC1_SREF2          (ADC12MCTL1 & (~(0XFFBF)))>>6
#define put_ADC1_ADC12EOS(x)    ADC12MCTL1=(ADC12MCTL1 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC1_ADC12EOS       (ADC12MCTL1 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC2_INCH(x)        ADC12MCTL2=(ADC12MCTL2 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC2_INCH           (ADC12MCTL2 & (~(0XFFF0)))>>0
#define put_ADC2_SREF(x)        ADC12MCTL2=(ADC12MCTL2 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC2_SREF           (ADC12MCTL2 & (~(0XFF8F)))>>4
#define put_ADC2_SREF1_0(x)     ADC12MCTL2=(ADC12MCTL2 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC2_SREF1_0        (ADC12MCTL2 & (~(0XFFCF)))>>4
#define put_ADC2_SREF2(x)       ADC12MCTL2=(ADC12MCTL2 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC2_SREF2          (ADC12MCTL2 & (~(0XFFBF)))>>6
#define put_ADC2_ADC12EOS(x)    ADC12MCTL2=(ADC12MCTL2 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC2_ADC12EOS       (ADC12MCTL2 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC3_INCH(x)        ADC12MCTL3=(ADC12MCTL3 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC3_INCH           (ADC12MCTL3 & (~(0XFFF0)))>>0
#define put_ADC3_SREF(x)        ADC12MCTL3=(ADC12MCTL3 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC3_SREF           (ADC12MCTL3 & (~(0XFF8F)))>>4
#define put_ADC3_SREF1_0(x)     ADC12MCTL3=(ADC12MCTL3 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC3_SREF1_0        (ADC12MCTL3 & (~(0XFFCF)))>>4
#define put_ADC3_SREF2(x)       ADC12MCTL3=(ADC12MCTL3 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC3_SREF2          (ADC12MCTL3 & (~(0XFFBF)))>>6
#define put_ADC3_ADC12EOS(x)    ADC12MCTL3=(ADC12MCTL3 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC3_ADC12EOS       (ADC12MCTL3 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC4_INCH(x)        ADC12MCTL4=(ADC12MCTL4 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC4_INCH           (ADC12MCTL4 & (~(0XFFF0)))>>0
#define put_ADC4_SREF(x)        ADC12MCTL4=(ADC12MCTL4 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC4_SREF           (ADC12MCTL4 & (~(0XFF8F)))>>4
#define put_ADC4_SREF1_0(x)     ADC12MCTL4=(ADC12MCTL4 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC4_SREF1_0        (ADC12MCTL4 & (~(0XFFCF)))>>4
#define put_ADC4_SREF2(x)       ADC12MCTL4=(ADC12MCTL4 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC4_SREF2          (ADC12MCTL4 & (~(0XFFBF)))>>6
#define put_ADC4_ADC12EOS(x)    ADC12MCTL4=(ADC12MCTL4 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC4_ADC12EOS       (ADC12MCTL4 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC5_INCH(x)        ADC12MCTL5=(ADC12MCTL5 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC5_INCH           (ADC12MCTL5 & (~(0XFFF0)))>>0
#define put_ADC5_SREF(x)        ADC12MCTL5=(ADC12MCTL5 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC5_SREF           (ADC12MCTL5 & (~(0XFF8F)))>>4
#define put_ADC5_SREF1_0(x)     ADC12MCTL5=(ADC12MCTL5 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC5_SREF1_0        (ADC12MCTL5 & (~(0XFFCF)))>>4
#define put_ADC5_SREF2(x)       ADC12MCTL5=(ADC12MCTL5 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC5_SREF2          (ADC12MCTL5 & (~(0XFFBF)))>>6
#define put_ADC5_ADC12EOS(x)    ADC12MCTL5=(ADC12MCTL5 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC5_ADC12EOS       (ADC12MCTL5 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC6_INCH(x)        ADC12MCTL6=(ADC12MCTL6 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC6_INCH           (ADC12MCTL6 & (~(0XFFF0)))>>0
#define put_ADC6_SREF(x)        ADC12MCTL6=(ADC12MCTL6 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC6_SREF           (ADC12MCTL6 & (~(0XFF8F)))>>4
#define put_ADC6_SREF1_0(x)     ADC12MCTL6=(ADC12MCTL6 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC6_SREF1_0        (ADC12MCTL6 & (~(0XFFCF)))>>4
#define put_ADC6_SREF2(x)       ADC12MCTL6=(ADC12MCTL6 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC6_SREF2          (ADC12MCTL6 & (~(0XFFBF)))>>6
#define put_ADC6_ADC12EOS(x)    ADC12MCTL6=(ADC12MCTL6 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC6_ADC12EOS       (ADC12MCTL6 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC7_INCH(x)        ADC12MCTL7=(ADC12MCTL7 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC7_INCH           (ADC12MCTL7 & (~(0XFFF0)))>>0
#define put_ADC7_SREF(x)        ADC12MCTL7=(ADC12MCTL7 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC7_SREF           (ADC12MCTL7 & (~(0XFF8F)))>>4
#define put_ADC7_SREF1_0(x)     ADC12MCTL7=(ADC12MCTL7 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC7_SREF1_0        (ADC12MCTL7 & (~(0XFFCF)))>>4
#define put_ADC7_SREF2(x)       ADC12MCTL7=(ADC12MCTL7 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC7_SREF2          (ADC12MCTL7 & (~(0XFFBF)))>>6
#define put_ADC7_ADC12EOS(x)    ADC12MCTL7=(ADC12MCTL7 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC7_ADC12EOS       (ADC12MCTL7 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC8_INCH(x)        ADC12MCTL8=(ADC12MCTL8 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC8_INCH           (ADC12MCTL8 & (~(0XFFF0)))>>0
#define put_ADC8_SREF(x)        ADC12MCTL8=(ADC12MCTL8 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC8_SREF           (ADC12MCTL8 & (~(0XFF8F)))>>4
#define put_ADC8_SREF1_0(x)     ADC12MCTL8=(ADC12MCTL8 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC8_SREF1_0        (ADC12MCTL8 & (~(0XFFCF)))>>4
#define put_ADC8_SREF2(x)       ADC12MCTL8=(ADC12MCTL8 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC8_SREF2          (ADC12MCTL8 & (~(0XFFBF)))>>6
#define put_ADC8_ADC12EOS(x)    ADC12MCTL8=(ADC12MCTL8 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC8_ADC12EOS       (ADC12MCTL8 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC9_INCH(x)        ADC12MCTL9=(ADC12MCTL9 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC9_INCH           (ADC12MCTL9 & (~(0XFFF0)))>>0
#define put_ADC9_SREF(x)        ADC12MCTL9=(ADC12MCTL9 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC9_SREF           (ADC12MCTL9 & (~(0XFF8F)))>>4
#define put_ADC9_SREF1_0(x)     ADC12MCTL9=(ADC12MCTL9 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC9_SREF1_0        (ADC12MCTL9 & (~(0XFFCF)))>>4
#define put_ADC9_SREF2(x)       ADC12MCTL9=(ADC12MCTL9 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC9_SREF2          (ADC12MCTL9 & (~(0XFFBF)))>>6
#define put_ADC9_ADC12EOS(x)    ADC12MCTL9=(ADC12MCTL9 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC9_ADC12EOS       (ADC12MCTL9 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC10_INCH(x)       ADC12MCTL10=(ADC12MCTL10 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC10_INCH          (ADC12MCTL10 & (~(0XFFF0)))>>0
#define put_ADC10_SREF(x)       ADC12MCTL10=(ADC12MCTL10 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC10_SREF          (ADC12MCTL10 & (~(0XFF8F)))>>4
#define put_ADC10_SREF1_0(x)    ADC12MCTL10=(ADC12MCTL10 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC10_SREF1_0       (ADC12MCTL10 & (~(0XFFCF)))>>4
#define put_ADC10_SREF2(x)      ADC12MCTL10=(ADC12MCTL10 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC10_SREF2         (ADC12MCTL10 & (~(0XFFBF)))>>6
#define put_ADC10_ADC12EOS(x)   ADC12MCTL10=(ADC12MCTL10 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC10_ADC12EOS      (ADC12MCTL10 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC11_INCH(x)       ADC12MCTL11=(ADC12MCTL11 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC11_INCH          (ADC12MCTL11 & (~(0XFFF0)))>>0
#define put_ADC11_SREF(x)        ADC12MCTL11=(ADC12MCTL11 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC11_SREF           (ADC12MCTL11 & (~(0XFF8F)))>>4
#define put_ADC11_SREF1_0(x)     ADC12MCTL11=(ADC12MCTL11 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC11_SREF1_0        (ADC12MCTL11 & (~(0XFFCF)))>>4
#define put_ADC11_SREF2(x)       ADC12MCTL11=(ADC12MCTL11 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC11_SREF2          (ADC12MCTL11 & (~(0XFFBF)))>>6
#define put_ADC11_ADC12EOS(x)    ADC12MCTL11=(ADC12MCTL11 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC11_ADC12EOS       (ADC12MCTL11 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC12_INCH(x)       ADC12MCTL12=(ADC12MCTL12 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC12_INCH          (ADC12MCTL12 & (~(0XFFF0)))>>0
#define put_ADC12_SREF(x)       ADC12MCTL12=(ADC12MCTL12 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC12_SREF          (ADC12MCTL12 & (~(0XFF8F)))>>4
#define put_ADC12_SREF1_0(x)    ADC12MCTL12=(ADC12MCTL12 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC12_SREF1_0       (ADC12MCTL12 & (~(0XFFCF)))>>4
#define put_ADC12_SREF2(x)      ADC12MCTL12=(ADC12MCTL12 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC12_SREF2         (ADC12MCTL12 & (~(0XFFBF)))>>6
#define put_ADC12_ADC12EOS(x)    ADC12MCTL12=(ADC12MCTL12 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC12_ADC12EOS       (ADC12MCTL12 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC13_INCH(x)        ADC12MCTL13=(ADC12MCTL13 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC13_INCH           (ADC12MCTL13 & (~(0XFFF0)))>>0
#define put_ADC13_SREF(x)        ADC12MCTL13=(ADC12MCTL13 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC13_SREF           (ADC12MCTL13 & (~(0XFF8F)))>>4
#define put_ADC13_SREF1_0(x)     ADC12MCTL13=(ADC12MCTL13 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC13_SREF1_0        (ADC12MCTL13 & (~(0XFFCF)))>>4
#define put_ADC13_SREF2(x)       ADC12MCTL13=(ADC12MCTL13 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC13_SREF2          (ADC12MCTL13 & (~(0XFFBF)))>>6
#define put_ADC13_ADC12EOS(x)    ADC12MCTL13=(ADC12MCTL13 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC13_ADC12EOS       (ADC12MCTL13 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC14_INCH(x)        ADC12MCTL14=(ADC12MCTL14 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC14_INCH           (ADC12MCTL14 & (~(0XFFF0)))>>0
#define put_ADC14_SREF(x)        ADC12MCTL14=(ADC12MCTL14 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC14_SREF           (ADC12MCTL14 & (~(0XFF8F)))>>4
#define put_ADC14_SREF1_0(x)     ADC12MCTL14=(ADC12MCTL14 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC14_SREF1_0        (ADC12MCTL14 & (~(0XFFCF)))>>4
#define put_ADC14_SREF2(x)       ADC12MCTL14=(ADC12MCTL14 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC14_SREF2          (ADC12MCTL14 & (~(0XFFBF)))>>6
#define put_ADC14_ADC12EOS(x)    ADC12MCTL14=(ADC12MCTL14 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC14_ADC12EOS       (ADC12MCTL14 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
#define put_ADC15_INCH(x)        ADC12MCTL15=(ADC12MCTL15 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_ADC15_INCH           (ADC12MCTL15 & (~(0XFFF0)))>>0
#define put_ADC15_SREF(x)        ADC12MCTL15=(ADC12MCTL15 & 0XFF8F) | ((x & 0X0007) <<4)
#define get_ADC15_SREF           (ADC12MCTL15 & (~(0XFF8F)))>>4
#define put_ADC15_SREF1_0(x)     ADC12MCTL15=(ADC12MCTL15 & 0XFFCF) | ((x & 0X0003) <<4)
#define get_ADC15_SREF1_0        (ADC12MCTL15 & (~(0XFFCF)))>>4
#define put_ADC15_SREF2(x)       ADC12MCTL15=(ADC12MCTL15 & 0XFFBF) | ((x & 0X0001) <<6)
#define get_ADC15_SREF2          (ADC12MCTL15 & (~(0XFFBF)))>>6
#define put_ADC15_ADC12EOS(x)    ADC12MCTL15=(ADC12MCTL15 & 0XFF7F) | ((x & 0X0001) <<8)
#define get_ADC15_ADC12EOS       (ADC12MCTL15 & (~(0XFF7F)))>>8
//----------------------------------------------------------------------------------------------
//适合于对照原理图编写应用程序(结束)------------------------------------------------------------
//PPM控制开始-----------------------------------------------------------------------------------
#define put_PMMCOREV(x)           PMMCTL0=((PMMCTL0 & 0XFFFC)  + 0xA500) | ((x & 0X0003) <<0)
#define get_PMMCOREV              (PMMCTL0 & (~(0XFFFC)))>>0
#define put_PMMSWBOR(x)           PMMCTL0=((PMMCTL0 & 0XFFFB)  + 0xA500) | ((x & 0X0001) <<2)
#define get_PMMSWBOR              (PMMCTL0 & (~(0XFFFB)))>>2
#define put_PMMSWPOR(x)           PMMCTL0=((PMMCTL0 & 0XFFF7)  + 0xA500) | ((x & 0X0001) <<3)
#define get_PMMSWPOR              (PMMCTL0 & (~(0XFFF7)))>>3
#define put_PMMREGOFF(x)          PMMCTL0=((PMMCTL0 & 0XFFEF)  + 0xA500) | ((x & 0X0001) <<4)
#define get_PMMREGOFF             (PMMCTL0 & (~(0XFFEF)))>>4

#define put_SVSMHRRL(x)           SVSMHCTL=(SVSMHCTL & 0XFFF8) | ((x & 0X0007) <<0)
#define get_SVSMHRRL              (SVSMHCTL & (~(0XFFF8)))>>0
#define put_SVSMHDLYST(x)         SVSMHCTL=(SVSMHCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SVSMHDLYST            (SVSMHCTL & (~(0XFFF7)))>>0
#define put_SVSHMD(x)             SVSMHCTL=(SVSMHCTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SVSHMD                (SVSMHCTL & (~(0XFFEF)))>>4
#define put_SVSMHEVM(x)           SVSMHCTL=(SVSMHCTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SVSMHEVM              (SVSMHCTL & (~(0XFFBF)))>>6
#define put_SVSMHACE(x)           SVSMHCTL=(SVSMHCTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SVSMHACE              (SVSMHCTL & (~(0XFF7F)))>>7
#define put_SVSHRVL(x)            SVSMHCTL=(SVSMHCTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_SVSHRVL               (SVSMHCTL & (~(0XFCFF)))>>8
#define put_SVSHE(x)              SVSMHCTL=(SVSMHCTL & 0XFBFF) | ((x & 0X0001) <<10)
#define get_SVSHE                 (SVSMHCTL & (~(0XFBFF)))>>10
#define put_SVSHFP(x)             SVSMHCTL=(SVSMHCTL & 0XF7FF) | ((x & 0X0001) <<11)
#define get_SVSHFP                (SVSMHCTL & (~(0XF7FF)))>>11
#define put_SVMHOVPE(x)           SVSMHCTL=(SVSMHCTL & 0XEFFF) | ((x & 0X0001) <<12)
#define get_SVMHOVPE              (SVSMHCTL & (~(0XEFFF)))>>12
#define put_SVMHE(x)              SVSMHCTL=(SVSMHCTL & 0XBFFF) | ((x & 0X0001) <<14)
#define get_SVMHE                 (SVSMHCTL & (~(0XBFFF)))>>14
#define put_SVMHFP(x)             SVSMHCTL=(SVSMHCTL & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_SVMHFP                (SVSMHCTL & (~(0X7FFF)))>>15

#define put_SVSMLRRL(x)           SVSMLCTL=(SVSMLCTL & 0XFFF8) | ((x & 0X0007) <<0)
#define get_SVSMLRRL              (SVSMLCTL & (~(0XFFF8)))>>0
#define put_SVSMLDLYST(x)         SVSMLCTL=(SVSMLCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SVSMLDLYST            (SVSMLCTL & (~(0XFFF7)))>>0
#define put_SVSLMD(x)             SVSMLCTL=(SVSMLCTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SVSLMD                (SVSMLCTL & (~(0XFFEF)))>>4
#define put_SVSMLEVM(x)           SVSMLCTL=(SVSMLCTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SVSMLEVM              (SVSMLCTL & (~(0XFFBF)))>>6
#define put_SVSMLACE(x)           SVSMLCTL=(SVSMLCTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_SVSMLACE              (SVSMLCTL & (~(0XFF7F)))>>7
#define put_SVSLRVL(x)            SVSMLCTL=(SVSMLCTL & 0XFCFF) | ((x & 0X0003) <<8)
#define get_SVSLRVL               (SVSMLCTL & (~(0XFCFF)))>>8
#define put_SVSLE(x)              SVSMLCTL=(SVSMLCTL & 0XFBFF) | ((x & 0X0001) <<10)
#define get_SVSLE                 (SVSMLCTL & (~(0XFBFF)))>>10
#define put_SVSLFP(x)             SVSMLCTL=(SVSMLCTL & 0XF7FF) | ((x & 0X0001) <<11)
#define get_SVSLFP                (SVSMLCTL & (~(0XF7FF)))>>11
#define put_SVMLOVPE(x)           SVSMLCTL=(SVSMLCTL & 0XEFFF) | ((x & 0X0001) <<12)
#define get_SVMLOVPE              (SVSMLCTL & (~(0XEFFF)))>>12
#define put_SVMLE(x)              SVSMLCTL=(SVSMLCTL & 0XBFFF) | ((x & 0X0001) <<14)
#define get_SVMLE                 (SVSMLCTL & (~(0XBFFF)))>>14
#define put_SVMLFP(x)             SVSMLCTL=(SVSMLCTL & 0X7FFF) | (unsigned int)((x & 0X0001) <<15)
#define get_SVMLFP                (SVSMLCTL & (~(0X7FFF)))>>15

#define put_SVMLOE(x)             SVSMIO=(SVSMIO & 0XFFF7) | ((x & 0X0001) <<3)
#define get_SVMLOE                (SVSMIO & (~(0XFFF7)))>>3
#define put_SVMLVLROE(x)          SVSMIO=(SVSMIO & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SVMLVLROE             (SVSMIO & (~(0XFFEF)))>>4
#define put_SVMOUTPOL(x)          SVSMIO=(SVSMIO & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SVMOUTPOL             (SVSMIO & (~(0XFFDF)))>>5
#define put_SVMHOE(x)             SVSMIO=(SVSMIO & 0XF7FF) | ((x & 0X0001) <<11)
#define get_SVMHOE                (SVSMIO & (~(0XF7FFF)))>>11
#define put_SVMHVLROE(x)          SVSMIO=(SVSMIO & 0XFEFF) | ((x & 0X0001) <<12)
#define get_SVMHVLROE             (SVSMIO & (~(0XFEFFF)))>>12

#define put_SVSMLDLYIFG(x)        PMMIFG=(PMMIFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SVSMLDLYIFG           (PMMIFG & (~(0XFFFE)))>>0
#define put_SVMLIFG(x)            PMMIFG=(PMMIFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SVMLIFG               (PMMIFG & (~(0XFFFD)))>>1
#define put_SVMLVLRIFG(x)         PMMIFG=(PMMIFG & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SVMLVLRIFG            (PMMIFG & (~(0XFFFB)))>>2
#define put_SVSMGHDLYIFG(x)       PMMIFG=(PMMIFG & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SVSMGHDLYIFG          (PMMIFG & (~(0XFFEF)))>>4
#define put_SVMHIFG(x)            PMMIFG=(PMMIFG & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SVMHIFG               (PMMIFG & (~(0XFFDF)))>>5
#define put_SVMHVLRIFG(x)         PMMIFG=(PMMIFG & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SVMHVLRIFG            (PMMIFG & (~(0XFFBF)))>>6
#define put_PMMBORIFG(x)          PMMIFG=(PMMIFG & 0XFEFF) | ((x & 0X0001) <<8)
#define get_PMMBORIFG             (PMMIFG & (~(0XFEFF)))>>8
#define put_PMMRSTIFG(x)          PMMIFG=(PMMIFG & 0XFDFF) | ((x & 0X0001) <<9)
#define get_PMMRSTIFG             (PMMIFG & (~(0XFDFF)))>>9
#define put_PMMPORIFG(x)          PMMIFG=(PMMIFG & 0XFBFF) | ((x & 0X0001) <<10)
#define get_PMMPORIFG             (PMMIFG & (~(0XFBFF)))>>10
#define put_SVSHIFG(x)            PMMIFG=(PMMIFG & 0XEFFF) | ((x & 0X0001) <<12)
#define get_SVSHIFG               (PMMIFG & (~(0XEFFF)))>>12
#define put_SVSLIFG(x)            PMMIFG=(PMMIFG & 0XDFFF) | ((x & 0X0001) <<13)
#define get_SVSLIFG               (PMMIFG & (~(0XDFFF)))>>13
#define put_PMMLPM5IFG(x)         PMMIFG=(PMMIFG & 0X7FFF) | ((x & 0X0001) <<15)
#define get_PMMLPM5IFG            (PMMIFG & (~(0X7FFF)))>>15

#define put_SVSMLDLYIE(x)         PMMRIE=(PMMRIE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_SVSMLDLYIE            (PMMRIE & (~(0XFFFE)))>>0
#define put_SVMLIE(x)             PMMRIE=(PMMRIE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_SVMLIE                (PMMRIE & (~(0XFFFD)))>>1
#define put_SVMLVLRIE(x)          PMMRIE=(PMMRIE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_SVMLVLRIE             (PMMRIE & (~(0XFFFB)))>>2
#define put_SVSMHDLYIE(x)         PMMRIE=(PMMRIE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_SVSMHDLYIE            (PMMRIE & (~(0XFFEF)))>>4
#define put_SVMHIE(x)             PMMRIE=(PMMRIE & 0XFFDF) | ((x & 0X0001) <<5)
#define get_SVMHIE                (PMMRIE & (~(0XFFDF)))>>5
#define put_SVMHVLRIE(x)          PMMRIE=(PMMRIE & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SVMHVLRIE             (PMMRIE & (~(0XFFBF)))>>6
#define put_SVSLPE(x)             PMMRIE=(PMMRIE & 0XFEFF) | ((x & 0X0001) <<8)
#define get_SVSLPE                (PMMRIE & (~(0XFEFF)))>>8
#define put_SVMLVLRPE(x)          PMMRIE=(PMMRIE & 0XFDFF) | ((x & 0X0001) <<9)
#define get_SVMLVLRPE             (PMMRIE & (~(0XFDFF)))>>9
#define put_SVSHPE(x)             PMMRIE=(PMMRIE & 0XEFFF) | ((x & 0X0001) <<12)
#define get_SVSHPE                (PMMRIE & (~(0XEFFF)))>>12
#define put_SVMHVLRPE(x)          PMMRIE=(PMMRIE & 0XDFFF) | ((x & 0X0001) <<13)
#define get_SVMHVLRPE             (PMMRIE & (~(0XDFFF)))>>13

//#define put_LOCKLPM5(x)           PM5CTL0=(PM5CTL0 & 0XDFFF) | ((x & 0X0001) <<0)
//#define get_LOCKLPM5              (PM5CTL0 & (~(0XDFFF)))>>0
//PPM控制结束-----------------------------------------------------------------------------------
//RAM 管理开始----------------------------------------------------------------------------------
#define put_RAM_SECTOR0(x)        RCCTL0=((RCCTL0 & 0X00FE) + 0x5A00) | ((x & 0X0001) <<0)  //RCRS0OFF(x)
#define get_RAM_SECTOR0           (RCCTL0 & (~(0XFFFE)))>>0
#define put_RAM_SECTOR1(x)        RCCTL0=((RCCTL0 & 0X00FD) + 0x5A00) | ((x & 0X0001) <<1)  //RCRS1OFF(x)
#define get_RAM_SECTOR1           (RCCTL0 & (~(0XFFFD)))>>1
#define put_RAM_SECTOR2(x)        RCCTL0=((RCCTL0 & 0X00FB) + 0x5A00) | ((x & 0X0001) <<2)  //RCRS2OFF(x)
#define get_RAM_SECTOR2           (RCCTL0 & (~(0XFFFB)))>>2
#define put_RAM_SECTOR3(x)        RCCTL0=((RCCTL0 & 0X00F7) + 0x5A00) | ((x & 0X0001) <<3)  //RCRS3OFF(x)
#define get_RAM_SECTOR3           (RCCTL0 & (~(0XFFF7)))>>3
#define put_RAM_SECTOR7(x)        RCCTL0=((RCCTL0 & 0X007F) + 0x5A00) | ((x & 0X0001) <<7)  //RCRS7OFF(x)
#define get_RAM_SECTOR7           (RCCTL0 & (~(0XFF7F)))>>7
#define put_RCRS0OFF(x)           RCCTL0=((RCCTL0 & 0X00FE) + 0x5A00) | ((x & 0X0001) <<0)
#define get_RCRS0OFF              (RCCTL0 & (~(0XFFFE)))>>0
#define put_RCRS1OFF(x)           RCCTL0=((RCCTL0 & 0X00FD) + 0x5A00) | ((x & 0X0001) <<1)
#define get_RCRS1OFF              (RCCTL0 & (~(0XFFFD)))>>1
#define put_RCRS2OFF(x)           RCCTL0=((RCCTL0 & 0X00FB) + 0x5A00) | ((x & 0X0001) <<2)
#define get_RCRS2OFF              (RCCTL0 & (~(0XFFFB)))>>2
#define put_RCRS3OFF(x)           RCCTL0=((RCCTL0 & 0X00F7) + 0x5A00) | ((x & 0X0001) <<3)
#define get_RCRS3OFF              (RCCTL0 & (~(0XFFF7)))>>3
#define put_RCRS7OFF(x)           RCCTL0=((RCCTL0 & 0X007F) + 0x5A00) | ((x & 0X0001) <<7)
#define get_RCRS7OFF              (RCCTL0 & (~(0XFF7F)))>>7
//RAM 管理结束----------------------------------------------------------------------------------
//FLASH 管理开始--------------------------------------------------------------------------------
#define put_ERASE(x)              FCTL1=((FCTL1 & 0X00FD) + 0xA500) | ((x & 0X0001) <<1)
#define get_ERASE                 (FCTL1 & (~(0XFFFD)))>>1
#define put_MERAS(x)              FCTL1=((FCTL1 & 0X00FB) + 0xA500) | ((x & 0X0001) <<2)
#define get_MERAS                 (FCTL1 & (~(0XFFFB)))>>2
#define put_FLASH_ERASE(x)        FCTL1=((FCTL1 & 0X00F9) + 0xA500) | ((x & 0X0003) <<1)
#define get_FLASH_ERASE           (FCTL1 & (~(0XFFF9)))>>1
#define put_FLASH_SWRT(x)         FCTL1=((FCTL1 & 0X00DF) + 0xA500) | ((x & 0X0001) <<5)
#define get_FLASH_SWRT            (FCTL1 & (~(0XFFDF)))>>5
#define put_FLASH_WRT(x)          FCTL1=((FCTL1 & 0X00BF) + 0xA500) | ((x & 0X0001) <<6)
#define get_FLASH_WRT             (FCTL1 & (~(0XFFBF)))>>6
#define put_FLASH_BLKWRT(x)       FCTL1=((FCTL1 & 0X007F) + 0xA500) | ((x & 0X0001) <<7)
#define get_FLASH_BLKWRT          (FCTL1 & (~(0XFF7F)))>>7

#define put_FLASH_WRITE(x)        FCTL1=((FCTL1 & 0X003F) + 0xA500) | ((x & 0X0003) <<6)
#define get_FLASH_WRITE           (FCTL1 & (~(0XFF3F)))>>6

#define put_FLASH_BUSY(x)         FCTL3=((FCTL3 & 0X00FE) + 0xA500) | ((x & 0X0001) <<0)
#define get_FLASH_BUSY            (FCTL3 & (~(0XFFFE)))>>0
#define put_FLASH_KEYV(x)         FCTL3=((FCTL3 & 0X00FD) + 0xA500) | ((x & 0X0001) <<1)
#define get_FLASH_KEYV            (FCTL3 & (~(0XFFFD)))>>1
#define put_FLASH_ACCVIFG(x)      FCTL3=((FCTL3 & 0X00FB) + 0xA500) | ((x & 0X0001) <<2)
#define get_FLASH_ACCVIFG         (FCTL3 & (~(0XFFFB)))>>2
#define put_FLASH_WAIT(x)         FCTL3=((FCTL3 & 0X00F7) + 0xA500) | ((x & 0X0001) <<3)
#define get_FLASH_WAIT            (FCTL3 & (~(0XFFF7)))>>3
#define put_FLASH_LOCK(x)         FCTL3=((FCTL3 & 0X00EF) + 0xA500) | ((x & 0X0001) <<4)
#define get_FLASH_LOCK            (FCTL3 & (~(0XFFEF)))>>4
#define put_FLASH_LOCKA(x)        FCTL3=((FCTL3 & 0X00BF) + 0xA500) | ((x & 0X0001) <<6)
#define get_FLASH_LOCKA           (FCTL3 & (~(0XFFBF)))>>6

#define put_FLASH_VPE(x)          FCTL4=((FCTL4 & 0X00FE) + 0xA500) | ((x & 0X0001) <<0)
#define get_FLASH_VPE             (FCTL4 & (~(0XFFFE)))>>0
#define put_FLASH_MRG0(x)         FCTL4=((FCTL4 & 0X00EF) + 0xA500) | ((x & 0X0001) <<4)
#define get_FLASH_MRG0            (FCTL4 & (~(0XFFEF)))>>4
#define put_FLASH_MRG1(x)         FCTL4=((FCTL4 & 0X00DF) + 0xA500) | ((x & 0X0001) <<5)
#define get_FLASH_MRG1            (FCTL4 & (~(0XFFDF)))>>5
#define put_FLASH_MRG(x)          FCTL4=((FCTL4 & 0X00CF) + 0xA500) | ((x & 0X0003) <<4)
#define get_FLASH_MRG             (FCTL4 & (~(0XFFCF)))>>4
#define put_FLASH_LOCKINFO(x)     FCTL4=((FCTL4 & 0X007F) + 0xA500) | ((x & 0X0001) <<7)
#define get_FLASH_LOCKINFO        (FCTL4 & (~(0XFF7F)))>>7

#define put_FLASH_ACCVIE(x)       SFRIE1=((SFRIE1 & 0X00DF) + 0xA500) | ((x & 0X0001) <<5)
#define get_FLASH_ACCVIE          (SFRIE1 & (~(0XFFDF)))>>5
//FLASH 管理结束--------------------------------------------------------------------------------
//USB寄存器开始*********************************************************************************
#define put_USBKEY(x)             USBKEY=((USBKEY & 0X00FF) + 0x9600) | ((x & 0X00FF) <<0)
#define get_USBKEY                (USBKEY & (~(0X00FF)))>>0
//USBCNF寄存器开始------------------------------------------------------------------------------
#define put_USB_EN(x)             USBCNF=(USBCNF & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USB_EN                (USBCNF & (~(0XFFFE)))>>0
#define put_PUR_EN(x)             USBCNF=(USBCNF & 0XFFFD) | ((x & 0X0001) <<1)
#define get_PUR_EN                (USBCNF & (~(0XFFFD)))>>1
#define put_PUR_IN(x)             USBCNF=(USBCNF & 0XFFFB) | ((x & 0X0001) <<2)
#define get_PUR_IN                (USBCNF & (~(0XFFFB)))>>2
#define put_BLKRDY(x)             USBCNF=(USBCNF & 0XFFF7) | ((x & 0X0001) <<3)
#define get_BLKRDY                (USBCNF & (~(0XFFF7)))>>3
#define put_FNTEN(x)              USBCNF=(USBCNF & 0XFF7F) | ((x & 0X0001) <<4)
#define get_FNTEN                 (USBCNF & (~(0XFF7F)))>>4
//USBCNF寄存器结束------------------------------------------------------------------------------
//USBPHYCTL寄存器开始---------------------------------------------------------------------------
#define put_PUOUT0(x)             USBPHYCTL=(USBPHYCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_PUOUT0                (USBPHYCTL & (~(0XFFFE)))>>0
#define put_PUOUT1(x)             USBPHYCTL=(USBPHYCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_PUOUT1                (USBPHYCTL & (~(0XFFFD)))>>1
#define put_PUIN0(x)              USBPHYCTL=(USBPHYCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_PUIN0                 (USBPHYCTL & (~(0XFFFB)))>>2
#define put_PUIN1(x)              USBPHYCTL=(USBPHYCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_PUIN1                 (USBPHYCTL & (~(0XFFF7)))>>3
#define put_PUDIR(x)              USBPHYCTL=(USBPHYCTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_PUDIR                 (USBPHYCTL & (~(0XFFDF)))>>5
#define put_PUSEL(x)              USBPHYCTL=(USBPHYCTL & 0XFF7F) | ((x & 0X0001) <<7)
#define get_PUSEL                 (USBPHYCTL & (~(0XFF7F)))>>7
//USBPHYCTL寄存器结束---------------------------------------------------------------------------
//USBPWRCTL寄存器开始---------------------------------------------------------------------------
#define put_VUOVLIFG(x)           USBPWRCTL=(USBPWRCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_VUOVLIFG              (USBPWRCTL & (~(0XFFFE)))>>0
#define put_VBONIFG(x)            USBPWRCTL=(USBPWRCTL & 0XFFFD) | ((x & 0X0001) <<1)
#define get_VBONIFG               (USBPWRCTL & (~(0XFFFD)))>>1
#define put_VBOFFIFG(x)           USBPWRCTL=(USBPWRCTL & 0XFFFB) | ((x & 0X0001) <<2)
#define get_VBOFFIFG              (USBPWRCTL & (~(0XFFFB)))>>2
#define put_USBBGVBV(x)           USBPWRCTL=(USBPWRCTL & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBBGVBV              (USBPWRCTL & (~(0XFFF7)))>>3
#define put_USBDETEN(x)           USBPWRCTL=(USBPWRCTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_USBDETEN              (USBPWRCTL & (~(0XFFEF)))>>4
#define put_OVLAOFF(x)            USBPWRCTL=(USBPWRCTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_OVLAOFF               (USBPWRCTL & (~(0XFFDF)))>>5
#define put_SLDOAON(x)            USBPWRCTL=(USBPWRCTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_SLDOAON               (USBPWRCTL & (~(0XFFBF)))>>6
#define put_VUOVLIE(x)            USBPWRCTL=(USBPWRCTL & 0XFEFF) | ((x & 0X0001) <<8)
#define get_VUOVLIE               (USBPWRCTL & (~(0XFEFF)))>>8
#define put_VBONIE(x)             USBPWRCTL=(USBPWRCTL & 0XFDFF) | ((x & 0X0001) <<9)
#define get_VBONIE                (USBPWRCTL & (~(0XFDFF)))>>9
#define put_VBOFFIE(x)            USBPWRCTL=(USBPWRCTL & 0XFBFF) | ((x & 0X0001) <<10)
#define get_VBOFFIE               (USBPWRCTL & (~(0XFBFF)))>>10
#define put_VUSBEN(x)             USBPWRCTL=(USBPWRCTL & 0XF7FF) | ((x & 0X0001) <<11)
#define get_VUSBEN                (USBPWRCTL & (~(0XF7FF)))>>11
#define put_SLDOEN(x)             USBPWRCTL=(USBPWRCTL & 0XEFFF) | ((x & 0X0001) <<12)
#define get_SLDOEN                (USBPWRCTL & (~(0XEFFF)))>>12
//USBPWRCTL寄存器结束---------------------------------------------------------------------------
//USBPLLCTL寄存器开始---------------------------------------------------------------------------
#define put_UCLKSEL(x)              USBPLLCTL=(USBPLLCTL & 0XFF3F) | ((x & 0X0001) <<6)
#define get_UCLKSEL                 (USBPLLCTL & (~(0XFF3F)))>>6
#define put_UPLLEN(x)               USBPLLCTL=(USBPLLCTL & 0XFEFF) | ((x & 0X0001) <<8)
#define get_UPLLEN                  (USBPLLCTL & (~(0XFEFF)))>>8
#define put_UPFDEN(x)               USBPLLCTL=(USBPLLCTL & 0XFDFF) | ((x & 0X0001) <<9)
#define get_UPFDEN                  (USBPLLCTL & (~(0XFDFF)))>>9
//USBPLLCTL寄存器结束---------------------------------------------------------------------------
//USBPLLDIVB寄存器开始--------------------------------------------------------------------------
#define put_UPMB(x)                 USBPLLDIVB=(USBPLLDIVB & 0XFFC0) | ((x & 0X003F) <<0)
#define get_UPMB                    (USBPLLDIVB & (~(0XFFC0)))>>0
#define put_UPQB(x)                 USBPLLDIVB=(USBPLLDIVB & 0XF8FF) | ((x & 0X0007) <<8)
#define get_UPQB                    (USBPLLDIVB & (~(0XF8FF)))>>8
//USBPLLDIVB寄存器结束--------------------------------------------------------------------------
//USBPLLIR寄存器开始----------------------------------------------------------------------------
#define put_USBOOLIFG(x)            USBPLLIR=(USBPLLIR & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBOOLIFG               (USBPLLIR & (~(0XFFFE)))>>0
#define put_USBLOSIFG(x)            USBPLLIR=(USBPLLIR & 0XFFFD) | ((x & 0X0001) <<1)
#define get_USBLOSIFG               (USBPLLIR & (~(0XFFFD)))>>1
#define put_USBOORIFG(x)            USBPLLIR=(USBPLLIR & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBOORIFG               (USBPLLIR & (~(0XFFFB)))>>2
#define put_USBOOLIE(x)             USBPLLIR=(USBPLLIR & 0XFEFF) | ((x & 0X0001) <<8)
#define get_USBOOLIE                (USBPLLIR & (~(0XFEFF)))>>8
#define put_USBLOSIE(x)             USBPLLIR=(USBPLLIR & 0XFDFF) | ((x & 0X0001) <<9)
#define get_USBLOSIE                (USBPLLIR & (~(0XFDFF)))>>9
#define put_USBOORIE(x)             USBPLLIR=(USBPLLIR & 0XFFBF) | ((x & 0X0001) <<10)
#define get_USBOORIE                (USBPLLIR & (~(0XFDFF)))>>10
//USBPLLIR寄存器结束----------------------------------------------------------------------------
//USBIEPCNF_0寄存器开始-------------------------------------------------------------------------
#define put_USBIEPCNF_USBIIE(x)     USBIEPCNF_0=(USBIEPCNF_0 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBIEPCNF_USBIIE        (USBIEPCNF_0 & (~(0XFFFB)))>>2
#define put_USBIEPCNF_STALL(x)      USBIEPCNF_0=(USBIEPCNF_0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBIEPCNF_STALL         (USBIEPCNF_0 & (~(0XFFF7)))>>3
#define put_USBIEPCNF_TOGGLE(x)     USBIEPCNF_0=(USBIEPCNF_0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBIEPCNF_TOGGLE        (USBIEPCNF_0 & (~(0XFFDF)))>>5
#define put_USBIEPCNF_UBME(x)       USBIEPCNF_0=(USBIEPCNF_0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBIEPCNF_UBME          (USBIEPCNF_0 & (~(0XFF7F)))>>7
//USBIEPCNF_0寄存器结束-------------------------------------------------------------------------
//USBIEPBCNT_0寄存器开始------------------------------------------------------------------------
#define put_USBIEPBCNT_CNT(x)       USBIEPBCNT_0=(USBIEPBCNT_0 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_USBIEPBCNT_CNT          (USBIEPBCNT_0 & (~(0XFFF0)))>>0
#define put_USBIEPBCNT_NAK(x)       USBIEPBCNT_0=(USBIEPBCNT_0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBIEPBCNT_NAK          (USBIEPBCNT_0 & (~(0XFF7F)))>>7
//USBIEPBCNT_0寄存器结束------------------------------------------------------------------------

//USBOEPCNFG_0寄存器开始------------------------------------------------------------------------
#define put_USBOEPCNFG_USBIIE(x)    USBOEPCNFG_0=(USBOEPCNFG_0 & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBOEPCNFG_USBIIE       (USBOEPCNFG_0 & (~(0XFFFB)))>>2
#define put_USBOEPCNFG_STALL(x)     USBOEPCNFG_0=(USBOEPCNFG_0 & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBOEPCNFG_STALL        (USBOEPCNFG_0 & (~(0XFFF7)))>>3
#define put_USBOEPCNFG_TOGGLE(x)    USBOEPCNFG_0=(USBOEPCNFG_0 & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBOEPCNFG_TOGGLE       (USBOEPCNFG_0 & (~(0XFFDF)))>>5
#define put_USBOEPCNFG_UBME(x)      USBOEPCNFG_0=(USBOEPCNFG_0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBOEPCNFG_UBME         (USBOEPCNFG_0 & (~(0XFF7F)))>>7
//USBOEPCNFG_0寄存器结束------------------------------------------------------------------------
//USBOEPBCNT_0寄存器开始------------------------------------------------------------------------
#define put_USBOEPBCNT_CNT(x)       USBOEPBCNT_0=(USBOEPBCNT_0 & 0XFFF0) | ((x & 0X000F) <<0)
#define get_USBOEPBCNT_CNT          (USBOEPBCNT_0 & (~(0XFFF0)))>>0
#define put_USBOEPBCNT_NAK(x)       USBOEPBCNT_0=(USBOEPBCNT_0 & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBOEPBCNT_NAK          (USBOEPBCNT_0 & (~(0XFF7F)))>>7
//USBOEPBCNT_0寄存器结束------------------------------------------------------------------------
//USBIEPIE寄存器开始----------------------------------------------------------------------------
#define put_USBIEPIE_IEPIE0(x)      USBIEPIE=(USBIEPIE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBIEPIE_IEPIE0         (USBIEPIE & (~(0XFFFE)))>>0
#define put_USBIEPIE_IEPIE1(x)      USBIEPIE=(USBIEPIE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_USBIEPIE_IEPIE1         (USBIEPIE & (~(0XFFFD)))>>1
#define put_USBIEPIE_IEPIE2(x)      USBIEPIE=(USBIEPIE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBIEPIE_IEPIE2         (USBIEPIE & (~(0XFFFB)))>>2
#define put_USBIEPIE_IEPIE3(x)      USBIEPIE=(USBIEPIE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBIEPIE_IEPIE3         (USBIEPIE & (~(0XFFF7)))>>3
#define put_USBIEPIE_IEPIE4(x)      USBIEPIE=(USBIEPIE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_USBIEPIE_IEPIE4         (USBIEPIE & (~(0XFFEF)))>>4
#define put_USBIEPIE_IEPIE5(x)      USBIEPIE=(USBIEPIE & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBIEPIE_IEPIE5         (USBIEPIE & (~(0XFFDF)))>>5
#define put_USBIEPIE_IEPIE6(x)      USBIEPIE=(USBIEPIE & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBIEPIE_IEPIE6         (USBIEPIE & (~(0XFFBF)))>>6
#define put_USBIEPIE_IEPIE7(x)      USBIEPIE=(USBIEPIE & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBIEPIE_IEPIE7         (USBIEPIE & (~(0XFF7F)))>>7
//USBIEPIE寄存器结束----------------------------------------------------------------------------
//USBOEPIE寄存器开始----------------------------------------------------------------------------
#define put_USBOEPIE_OEPIE0(x)      USBOEPIE=(USBOEPIE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBOEPIE_OEPIE0         (USBOEPIE & (~(0XFFFE)))>>0
#define put_USBOEPIE_OEPIE1(x)      USBOEPIE=(USBOEPIE & 0XFFFD) | ((x & 0X0001) <<1)
#define get_USBOEPIE_OEPIE1         (USBOEPIE & (~(0XFFFD)))>>1
#define put_USBOEPIE_OEPIE2(x)      USBOEPIE=(USBOEPIE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBOEPIE_OEPIE2         (USBOEPIE & (~(0XFFFB)))>>2
#define put_USBOEPIE_OEPIE3(x)      USBOEPIE=(USBOEPIE & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBOEPIE_OEPIE3         (USBOEPIE & (~(0XFFF7)))>>3
#define put_USBOEPIE_OEPIE4(x)      USBOEPIE=(USBOEPIE & 0XFFEF) | ((x & 0X0001) <<4)
#define get_USBOEPIE_OEPIE4         (USBOEPIE & (~(0XFFEF)))>>4
#define put_USBOEPIE_OEPIE5(x)      USBOEPIE=(USBOEPIE & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBOEPIE_OEPIE5         (USBOEPIE & (~(0XFFDF)))>>5
#define put_USBOEPIE_OEPIE6(x)      USBOEPIE=(USBOEPIE & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBOEPIE_OEPIE6         (USBOEPIE & (~(0XFFBF)))>>6
#define put_USBOEPIE_OEPIE7(x)      USBOEPIE=(USBOEPIE & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBOEPIE_OEPIE7         (USBOEPIE & (~(0XFF7F)))>>7
//USBOEPIE寄存器结束----------------------------------------------------------------------------
//USBIEPIFG寄存器开始---------------------------------------------------------------------------
#define put_USBIEPIFG_IEPIE0(x)     USBIEPIFG=(USBIEPIFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBIEPIFG_IEPIE0        (USBIEPIFG & (~(0XFFFE)))>>0
#define put_USBIEPIFG_IEPIE1(x)     USBIEPIFG=(USBIEPIFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_USBIEPIFG_IEPIE1        (USBIEPIFG & (~(0XFFFD)))>>1
#define put_USBIEPIFG_IEPIE2(x)     USBIEPIFG=(USBIEPIFG & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBIEPIFG_IEPIE2        (USBIEPIFG & (~(0XFFFB)))>>2
#define put_USBIEPIFG_IEPIE3(x)     USBIEPIFG=(USBIEPIFG & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBIEPIFG_IEPIE3        (USBIEPIFG & (~(0XFFF7)))>>3
#define put_USBIEPIFG_IEPIE4(x)     USBIEPIFG=(USBIEPIFG & 0XFFEF) | ((x & 0X0001) <<4)
#define get_USBIEPIFG_IEPIE4        (USBIEPIFG & (~(0XFFEF)))>>4
#define put_USBIEPIFG_IEPIE5(x)     USBIEPIFG=(USBIEPIFG & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBIEPIFG_IEPIE5        (USBIEPIFG & (~(0XFFDF)))>>5
#define put_USBIEPIFG_IEPIE6(x)     USBIEPIFG=(USBIEPIFG & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBIEPIFG_IEPIE6        (USBIEPIFG & (~(0XFFBF)))>>6
#define put_USBIEPIFG_IEPIE7(x)     USBIEPIFG=(USBIEPIFG & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBIEPIFG_IEPIE7        (USBIEPIFG & (~(0XFF7F)))>>7
//USBIEPIFG寄存器结束---------------------------------------------------------------------------
//USBOEPIFG寄存器开始---------------------------------------------------------------------------
#define put_USBOEPIFG_OEPIE0(x)     USBOEPIFG=(USBOEPIFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBOEPIFG_OEPIE0        (USBOEPIFG & (~(0XFFFE)))>>0
#define put_USBOEPIFG_OEPIE1(x)     USBOEPIFG=(USBOEPIFG & 0XFFFD) | ((x & 0X0001) <<1)
#define get_USBOEPIFG_OEPIE1        (USBOEPIFG & (~(0XFFFD)))>>1
#define put_USBOEPIFG_OEPIE2(x)     USBOEPIFG=(USBOEPIFG & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBOEPIFG_OEPIE2        (USBOEPIFG & (~(0XFFFB)))>>2
#define put_USBOEPIFG_OEPIE3(x)     USBOEPIFG=(USBOEPIFG & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBOEPIFG_OEPIE3        (USBOEPIFG & (~(0XFFF7)))>>3
#define put_USBOEPIFG_OEPIE4(x)     USBOEPIFG=(USBOEPIFG & 0XFFEF) | ((x & 0X0001) <<4)
#define get_USBOEPIFG_OEPIE4        (USBOEPIFG & (~(0XFFEF)))>>4
#define put_USBOEPIFG_OEPIE5(x)     USBOEPIFG=(USBOEPIFG & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBOEPIFG_OEPIE5        (USBOEPIFG & (~(0XFFDF)))>>5
#define put_USBOEPIFG_OEPIE6(x)     USBOEPIFG=(USBOEPIFG & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBOEPIFG_OEPIE6        (USBOEPIFG & (~(0XFFBF)))>>6
#define put_USBOEPIFG_OEPIE7(x)     USBOEPIFG=(USBOEPIFG & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBOEPIFG_OEPIE7        (USBOEPIFG & (~(0XFF7F)))>>7
//USBOEPIFG寄存器结束---------------------------------------------------------------------------
//USBVECINT寄存器-------------------------------------------------------------------------------
#define put_USBVECINT_USBIV(x)      USBVECINT=(USBVECINT & 0XFFC0) | ((x & 0X003F) <<0)
#define get_USBVECINT_USBIV         (USBVECINT & (~(0XFFC0)))>>0
//USBVECINT寄存器-------------------------------------------------------------------------------
//USBMAINT寄存器开始---------------------------------------------------------------------------
#define put_USBMAINT_UTIFG(x)       USBMAINT=(USBMAINT & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBMAINT_UTIFG          (USBMAINT & (~(0XFFFE)))>>0
#define put_USBMAINT_UTIE(x)        USBMAINT=(USBMAINT & 0XFFFD) | ((x & 0X0001) <<1)
#define get_USBMAINT_UTIE           (USBMAINT & (~(0XFFFD)))>>1
#define put_USBMAINT_TSGEN(x)       USBMAINT=(USBMAINT & 0XFEFF) | ((x & 0X0001) <<8)
#define get_USBMAINT_TSGEN          (USBMAINT & (~(0XFEFF)))>>8
#define put_USBMAINT_TSESEL(x)      USBMAINT=(USBMAINT & 0XF9FF) | ((x & 0X0003) <<9)
#define get_USBMAINT_TSESEL         (USBMAINT & (~(0XF9FF)))>>9
#define put_USBMAINT_TSE3(x)        USBMAINT=(USBMAINT & 0XF7FF) | ((x & 0X0001) <<11)
#define get_USBMAINT_TSE3           (USBMAINT & (~(0XF7FF)))>>11
#define put_USBMAINT_UTSEL(x)       USBMAINT=(USBMAINT & 0X1FFF) | ((x & 0X0001) <<13)
#define get_USBMAINT_UTSEL5         (USBMAINT & (~(0X1FFF)))>>13
//USBMAINT寄存器结束---------------------------------------------------------------------------
#define put_USBTSREG_TVAL(x)        USBTSREG=x
#define get_USBTSREG_TVAL           USBTSREG
#define put_USBFN(x)                USBFN=(USBFN & 0XF800) | ((x & 0X01FF) <<0)
#define get_USBFN                   (USBFN & (~(0XF800)))>>0
//USBCTL寄存器开始---------------------------------------------------------------------------
#define put_USBCTL_DIR(x)           USBCTL=(USBCTL & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBCTL_DIR              (USBCTL & (~(0XFFFE)))>>0
#define put_USBCTL_FRSTE(x)         USBCTL=(USBCTL & 0XFFEF) | ((x & 0X0001) <<4)
#define get_USBCTL_FRSTE            (USBCTL & (~(0XFFEF)))>>4
#define put_USBCTL_RWUP(x)          USBCTL=(USBCTL & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBCTL_RWUP             (USBCTL & (~(0XFFDF)))>>5
#define put_USBCTL_FEN(x)           USBCTL=(USBCTL & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBCTL_FEN              (USBCTL & (~(0XFFBF)))>>6
//USBCTL寄存器结束---------------------------------------------------------------------------
//USBIE寄存器开始---------------------------------------------------------------------------
#define put_USBIE_STPOWIE(x)        USBIE=(USBIE & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBIE_STPOWIE           (USBIE & (~(0XFFFE)))>>0
#define put_USBIE_SETUPIE(x)        USBIE=(USBIE & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBIE_SETUPIE           (USBIE & (~(0XFFFB)))>>2
#define put_USBIE_RESRIE(x)         USBIE=(USBIE & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBIE_RESRIE            (USBIE & (~(0XFFDF)))>>5
#define put_USBIE_SUSRIE(x)         USBIE=(USBIE & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBIE_SUSRIE            (USBIE & (~(0XFFBF)))>>6
#define put_USBIE_RSTRIE(x)         USBIE=(USBIE & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBIE_RSTRIE            (USBIE & (~(0XFF7F)))>>7
//USBIE寄存器结束---------------------------------------------------------------------------
//USBIFG寄存器开始---------------------------------------------------------------------------
#define put_USBIFG_STPOWIFG(x)      USBIFG=(USBIFG & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBIFG_STPOWIFG         (USBIFG & (~(0XFFFE)))>>0
#define put_USBIFG_SETUPIFG(x)      USBIFG=(USBIFG & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBIFG_SETUPIFG         (USBIFG & (~(0XFFFB)))>>2
#define put_USBIFG_RESRIFG(x)       USBIFG=(USBIFG & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBIFG_RESRIFG          (USBIFG & (~(0XFFDF)))>>5
#define put_USBIFG_SUSRIFG(x)       USBIFG=(USBIFG & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBIFG_SUSRIFG          (USBIFG & (~(0XFFBF)))>>6
#define put_USBIFG_RSTRIFG(x)       USBIFG=(USBIFG & 0XFF7F) | ((x & 0X0001) <<7)
#define get_USBIFG_RSTRIFG          (USBIFG & (~(0XFF7F)))>>7
//USBIFG寄存器结束---------------------------------------------------------------------------
//USBFUNADR寄存器开始---------------------------------------------------------------------------
#define put_USBFUNADR_FA0(x)        USBFUNADR=(USBFUNADR & 0XFFFE) | ((x & 0X0001) <<0)
#define get_USBFUNADR_FA0           (USBFUNADR & (~(0XFFFE)))>>0
#define put_USBFUNADR_FA1(x)        USBFUNADR=(USBFUNADR & 0XFFFD) | ((x & 0X0001) <<1)
#define get_USBFUNADR_FA1           (USBFUNADR & (~(0XFFFD)))>>1
#define put_USBFUNADR_FA2(x)        USBFUNADR=(USBFUNADR & 0XFFFB) | ((x & 0X0001) <<2)
#define get_USBFUNADR_FA2           (USBFUNADR & (~(0XFFFB)))>>2
#define put_USBFUNADR_FA3(x)        USBFUNADR=(USBFUNADR & 0XFFF7) | ((x & 0X0001) <<3)
#define get_USBFUNADR_FA3           (USBFUNADR & (~(0XFFF7)))>>3
#define put_USBFUNADR_FA4(x)        USBFUNADR=(USBFUNADR & 0XFFEF) | ((x & 0X0001) <<4)
#define get_USBFUNADR_FA4           (USBFUNADR & (~(0XFFEF)))>>4
#define put_USBFUNADR_FA5(x)        USBFUNADR=(USBFUNADR & 0XFFDF) | ((x & 0X0001) <<5)
#define get_USBFUNADR_FA5           (USBFUNADR & (~(0XFFDF)))>>5
#define put_USBFUNADR_FA6(x)        USBFUNADR=(USBFUNADR & 0XFFBF) | ((x & 0X0001) <<6)
#define get_USBFUNADR_FA6           (USBFUNADR & (~(0XFFBF)))>>6
//USBFUNADR寄存器结束---------------------------------------------------------------------------

//USB寄存器结束*********************************************************************************
