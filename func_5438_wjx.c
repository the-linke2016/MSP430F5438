#include <msp430x54x.h>
#include "for_5438_wjx.c"
typedef struct                    //模数转换参数的结构 
  { 
    //ADC 核初始化开始-----------------------------------------------------------------------------------------
        unsigned char _REFON;     //在通道选择INCH=0AH（检测内部参考电压）时，可以不用该条语句
        unsigned char _REF2_5V;   //参数为0时，参考电压为1.5V，参数为1时，参考电压为2.5V
        unsigned char _ADC12SR_;  //采样速率，为1时采样速率高达50ksps,为0时高达200ksps
        unsigned char _REFBURST;  //参考电压连续，反之，只在采样转换期间提供
        unsigned char _ADC12SSEL; //选择ACLK作为模数转换时钟
        unsigned char _ADC12PDIV; //对模数转换时钟预分频，1分频或4分频，此处为1分频，即就是ACLK
        unsigned char _ADC12DIV;  //对模数转换时钟细分频，此处选择不分频，即1分频
        unsigned char _SHS;       //采样保持信号选择，此处选择ADC12SC位
        unsigned char _ISSH;      //0：不反相；1：反相
        unsigned char _SHP;       //采样保持脉冲模式选择：来自于采样输入或采样定时器.
        unsigned char _MSC;       //启动采样定时器，之后每当转换结束，就予以启动
        unsigned char _SHT0;      //采样保持时间，选择8个ADC12CLK周期，ADC12MEM0 to ADC12MEM7.
        unsigned char _ADC12SHT1; //采样保持时间，选择8个ADC12CLK周期，ADC12MEM8 to ADC12MEM15.
        unsigned char _CSTARTADD; //被使用的转换存贮器起始地址
        unsigned char _ADC12RES;  //模数转换位数选择
        unsigned char _ADC12DF;   //选择是否有符号
        unsigned char _CONSEQ;    //选择单次转换。0：单通道单次；1：顺序通道转换；2：单通道重复；3：顺序通道转换重复
        unsigned char _ADCOVIE;   //结果寄存器溢出中断
        unsigned char _ADCTOVIE;  //转换超时中断
    //ADC0开始-----------------------------------------------------------------------------------------------------
  }ADC_PARAMETER;
typedef struct                    //IIC的结构  
  { 
        unsigned int  _I2COA;     //1.本机地址（7位或10位）
        unsigned char _UCA10;     //2.本机地址位数（0:7位；1:10位）
        unsigned char _UCSSEL;    //3.时钟源选择（0：na；1：ACK;2：SMCLK;3：SMCLK）
        unsigned int  clk_f;      //4.时钟源频率（单位为KHz）
        unsigned int  baud_rate;  //5.波特率（单位为KHz）
        unsigned char _UCMM;      //6.单主、多主选择（0:单主机；1：多主机）
        unsigned char _UCMST;     //7.主从选择（0:从机；1:主机）
        unsigned char _UCTR;      //8.接收发送选择（0:接收；1:发送） 
        unsigned char _UCGCEN;    //9.呼应（0:不响应呼叫；1:响应呼叫）
        unsigned char _UCSLA10;   //10.从机地址位数（0:7位；1:10位）
        unsigned int  _I2CSA;     //11.从机地址（7位或10位）
  }IIC_PARAMETER;
typedef struct                    //SPI的结构  
  { 
        unsigned int  baud_rate;  //1.波特率
        unsigned char _UCSSEL;    //2.时钟源选择（1：ACLK;2:SMCLK)
        unsigned int  clk_f;      //3.时钟频率
        unsigned char _UC7BIT;    //4.字节位数：7或8 
        unsigned char _UCMSB;     //5.位顺序选择（0:先低位;1:先高位）
        unsigned char _UCCKPH;    //6.时钟相位选择（0:上升沿;1:下降沿）
        unsigned char _UCCKPL;    //7.时钟极性选择（0:低不活跃;1:高不活跃）
        unsigned char _UCMST;     //8.主从选择（0:从机;1:主机）
        unsigned char _UCMODE;    //9.模式选择(0:3线;1:4线STE=0;2:4线STE=1) 
        unsigned char _UCLISTEN;  //10.收发方式选择：0:正常收发;1自发自收   
  }SPI_PARAMETER;
typedef struct                    //模数转换参数的结构 
  { 
    //UART 核初始化开始-----------------------------------------------------------------------------------------
        unsigned int  baud_rate;  //1.波特率;
        unsigned char _UCMODE;    //2.通信模式（0:UART; 1:线路模式; 2:地址模式; 3:自动波特率模式）
        unsigned char _UC7BIT;    //3.数据位数 (7位或8位)
        unsigned char _UCSPB;     //4.停止位数（1位或2位）
        unsigned char _UCPEN;     //5.校验使能（0:不使能；1:使能）
        unsigned char _UCPAR;     //6.奇偶性  （0:偶校验; 1：奇校验）
        unsigned char _UCSSEL;    //7.时钟来源 (0:UCAxCLK; 1:ACLK; 2:SMCLK; 3:SMCLK)
        unsigned int  clk_f;      //8.时钟频率 (前一项的频率)
        unsigned char _UCIREN;    //9.通讯介质 (0:红外; 1:RS232)    
        unsigned char _UCIRRXPL;  //10.方式极性（0:反相； 1:不反省）
        unsigned char _UCLISTEN;  //11.收发方式（listen=1自发自收；listen=0正常收发）
    //UART 开始-----------------------------------------------------------------------------------------------------
  }UART_PARAMETER;
typedef struct                    //DMA传输参数的结构 
  {
    unsigned char _DMADT;         //1. DMA传输模式(0:单次；1:块；2、3:交替；4:单次重复；5:块重复；6、7:交替重复)
    unsigned char _DMAxTSEL;      //2. 触发信号选择(0~31，对应trig0~trig31)
    unsigned char _DMASRCINCR;    //3. 数据源地址变化方向（0:不变；1:不变；2:递减；3:递增）
    unsigned char _DMADSTINCR;    //4. 数据目的地址变化方向（0:不变；1:不变；2:递减；3:递增）
    unsigned char _DMASRCBYTE;    //5. 源数据字节或字（0:字节；1:字）
    unsigned char _DMADSTBYTE;    //6. 目标数据字节或字（0:字节；1:字）
    unsigned char _DMALEVEL;      //7. 触发沿选择（0:上升沿；1:高电平）
    unsigned char _DMAABORT;      //8. 传输期间允许屏蔽中断（0:不使能；1:使能）
    unsigned int  _DMASZ;         //9. 传输数据的个数
    unsigned int  _DMASA;         //10.原数据的起始地址
    unsigned int  _DMADA;         //11.目标数据的起始地址
    unsigned char _DMAIE;         //12.传输完成使能中断（0:禁止；1:允许）
    unsigned char _ROUNDROBIN;    //13.DMA通道优先级(0:顺序；1:轮番)
    unsigned char _DMARMWDIS;     //14.读-修改-写
  } DMA_PARAMETER; 
typedef struct                    //TIMER结构  
  { 
    unsigned char _TASSEL;        //选中ACLK作为计数时钟信号
    unsigned char _CNTL;          //选择主计数器位数(0:16位; 1:12位; 2:10位; 3:8位)
    unsigned char _ID;            //ID取值可分别0、1、2、3，分别对应分频为1、2、4、8
    unsigned char _IDEX;          //IDEX取值可分别0/1/2/3/4/5/6/7分别对应分频为1/2/3/4/5/6/7/8
    unsigned int  _CCR0;          //时间常数0
    unsigned int  _CCR1;          //时间常数1
    unsigned int  _CCR2;          //时间常数2
    unsigned int  _CCR3;          //时间常数3
    unsigned int  _CCR4;          //时间常数4
    unsigned int  _CCR5;          //时间常数5
    unsigned int  _CCR6;          //时间常数6
    unsigned char _MC;            //加法计数到TA0CCR0 
  }TIMER_PARAMETER;

void wait_for_XT1(void)
{
  while (get_OFIFG==1);			        // 等待时钟系统正常工作
    {
      put_XT1LFOFFG(0);                         //清除低频振荡器XT1故障标志
      put_DCOFFG(0);                            //清除DCO振荡器的故障标记
      put_OFIFG(0);                             //清除振荡器故障标志
      for(unsigned int i = 0; i <10000; i--);   //软件延时，临时变量i,只在本循环中有效，属于局部变量
    }
}
void wait_for_XT2(void)
{
  while (SFRIFG1 & OFIFG)			// 等待时钟系统正常工作
    {
      put_XT2OFFG(0);                           //清除低频振荡器XT2故障标志
      put_DCOFFG(0);                            //清除DCO振荡器的故障标记
      put_OFIFG(0);                             //清除振荡器故障标志
      for(unsigned int i = 0; i <10000; i--);   //软件延时，临时变量i,只在本循环中有效，属于局部变量
    }
}
void wait_for_clk_ok(void)
{
do{                                             //共有4种振荡器类型
          put_XT2OFFG(0);                       //清除XT2振荡器的故障标记
          put_XT1LFOFFG(0);                     //清除XT1低频振荡器的故障标记
          put_XT1HFOFFG(0);                     //清除XT1高频振荡器的故障标记
          put_DCOFFG(0);                        //清除DCO振荡器的故障标记
          put_OFIFG(0);                         //清除振荡器的故障标记,上述任何一种故障，都会是该标志置位
      }   while(get_OFIFG==1);                  //如果振荡器有故障，就执行循环体   
}
void put_DC_DCO(unsigned int DCORSEL,unsigned int DCO)
{   //DCORSEL：DCO频率范围；DCO:DCO间隙.
    put_DCORSEL(DCORSEL);
    put_DCO(DCO);
    put_MOD(0);
    put_DISMOD(0);
}
void init_UART0(UART_PARAMETER UART)
{
//串行口UART0初始化开始---------------------------------------------------------------------    
float x;unsigned int n;
/*1*/   put_UART0_UCSWRST(1);                       //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/ 
        put_UART0_UCMODE(UART._UCMODE);             //UART模式  
        if((UART._UCMODE>=1)&(UART._UCMODE<=3))
                  {put_UART0_UCDORM(1);}            //只收先导地址，而后必须软件清零以便接收数据
            else  {put_UART0_UCDORM(0);}            //接收所有数据
        put_UART0_UCSSEL(UART._UCSSEL);             //选择ACLK为波特率发生器信号源
        if(UART._UCMODE==3) 
                    {
                      put_UART0_UCABDEN(1);         //使能波特率自动检测
                    }
              else  {
                      put_UART0_UCABDEN(0);         //不使能波特率自动检测
                    }
        put_UART0_UCSYNC(0);                        //异步通讯
        put_UART0_UCPEN(UART._UCPEN);               //校验
        put_UART0_UCPAR(UART._UCPAR);               //偶或奇
        n=UART.clk_f/UART.baud_rate;
        if (n<16) { 
                    put_UART0_UCOS16(0);            //低频率模式
                    x=1.0*UART.clk_f/UART.baud_rate;
                    n=UART.clk_f/UART.baud_rate;
                    put_UART0_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*8+0.5);
                    put_UART0_UCBRS(n);             //小数分频配置
                  }
            else  {
                    put_UART0_UCOS16(1);            //高频率模式
                    n=UART.clk_f/UART.baud_rate/16;
                    x=1.0*UART.clk_f/UART.baud_rate/16;
                    put_UART0_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*16+0.5);
                    put_UART0_UCBRF(n);             //小数分频配置             
                  }        
        put_UART0_UCMSB(0);                         //从低位开始
        if(UART._UC7BIT==8) put_UART0_UC7BIT(0);    //8位数据传输
        if(UART._UC7BIT==7) put_UART0_UC7BIT(1);    //7位数据传输
        if(UART._UCSPB==1)  put_UART0_UCSPB(0);     //"0"一位停止位
        if(UART._UCSPB==2)  put_UART0_UCSPB(1);     //"1"二位停止位
        put_UART0_UCIREN(UART._UCIREN);             //0:UART收发;1:IrDA收发
//IrDA0开始 -----------------------------------------------------------------------------------------------
        put_UART0_UCIREN(UART._UCIREN);
        if (UART._UCIREN==1)
          {
            n=UART.clk_f/UART.baud_rate;
            if(n<16){put_UART0_UCIRTXCLK(0);}       //IrDA发送脉冲选择BRCLK
                else{put_UART0_UCIRTXCLK(1);}       //IrDA发送脉冲选择BRCLK16
            put_UART0_UCIRTXPL(0x1F);               //发送脉冲长度 Tpluse=(UCIRTXPLx + 1)/(2×Firtxclk)
            put_UART0_UCIRRXFE(1);                  //0：滤波器不使能；1: 滤波器使能 
            put_UART0_UCIRRXPL(UART._UCIRRXPL);     //接收极性选择。0:反相；1:不反相
            put_UART0_UCIRRXFL(0x1F);               //接收滤波长度 tMIN = (UCIRRXFLx + 4)/(2×fBRCLK)
          }
//IrDA0结束 -----------------------------------------------------------------------------------------------
        put_UART0_UCLISTEN(UART._UCLISTEN);         //自发自收或正常收发
/*3*/   put_P3SEL_BIT4(1);                          //第二功能，输出，作为TXD(39脚)
        put_P3SEL_BIT5(1);                          //第二功能，输出，作为RXD（40脚）
/*4*/   put_UART0_UCSWRST(0);                       //使能串口功能
//串行口UART0初始化结束--------------------------------------------------------------------
}
void init_UART1(UART_PARAMETER UART)
{
//串行口UART1初始化开始---------------------------------------------------------------------    
float x;unsigned int n;
/*1*/   put_UART1_UCSWRST(1);                       //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_UART1_UCMODE(UART._UCMODE);             //UART模式  
        if((UART._UCMODE>=1)&(UART._UCMODE<=3))
                  {put_UART1_UCDORM(1);}            //只收先导地址，而后必须软件清零以便接收数据
            else  {put_UART1_UCDORM(0);}            //接收所有数据
        put_UART1_UCSSEL(UART._UCSSEL);             //选择ACLK为波特率发生器信号源
        if(UART._UCMODE==3) 
                    {
                      put_UART1_UCABDEN(1);         //使能波特率自动检测
                    }
              else  {
                      put_UART1_UCABDEN(0);         //不使能波特率自动检测
                    }
        put_UART1_UCSYNC(0);                        //异步通讯
        put_UART1_UCPEN(UART._UCPEN);               //校验
        put_UART1_UCPAR(UART._UCPAR);               //偶或奇
        n=UART.clk_f/UART.baud_rate;
        if (n<16) { 
                    put_UART1_UCOS16(0);            //低频率模式
                    x=1.0*UART.clk_f/UART.baud_rate;
                    n=UART.clk_f/UART.baud_rate;
                    put_UART1_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*8+0.5);
                    put_UART1_UCBRS(n);             //小数分频配置
                  }
            else  {
                    put_UART1_UCOS16(1);            //高频率模式
                    n=UART.clk_f/UART.baud_rate/16;
                    x=1.0*UART.clk_f/UART.baud_rate/16;
                    put_UART1_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*16+0.5);
                    put_UART1_UCBRF(n);             //小数分频配置             
                  }        
        put_UART1_UCMSB(0);                         //从低位开始
        if(UART._UC7BIT==8) put_UART1_UC7BIT(0);    //8位数据传输
        if(UART._UC7BIT==7) put_UART1_UC7BIT(1);    //7位数据传输
        if(UART._UCSPB==1)  put_UART1_UCSPB(0);     //"0"一位停止位
        if(UART._UCSPB==2)  put_UART1_UCSPB(1);     //"1"二位停止位
        put_UART1_UCIREN(UART._UCIREN);             //0:UART收发;1:IrDA收发
//IrDA0开始 -----------------------------------------------------------------------------------------------
        put_UART1_UCIREN(UART._UCIREN);
        if (UART._UCIREN==1)
          {
            n=UART.clk_f/UART.baud_rate;
            if(n<16){put_UART1_UCIRTXCLK(0);}       //IrDA发送脉冲选择BRCLK
                else{put_UART1_UCIRTXCLK(1);}       //IrDA发送脉冲选择BRCLK16
            put_UART1_UCIRTXPL(0x1F);               //发送脉冲长度 Tpluse=(UCIRTXPLx + 1)/(2×Firtxclk)
            put_UART1_UCIRRXFE(1);                  //0：滤波器不使能；1: 滤波器使能 
            put_UART1_UCIRRXPL(UART._UCIRRXPL);     //接收极性选择。0:反相；1:不反相
            put_UART1_UCIRRXFL(0x1F);               //接收滤波长度 tMIN = (UCIRRXFLx + 4)/(2×fBRCLK)
          }
//IrDA0结束 -----------------------------------------------------------------------------------------------
        put_UART1_UCLISTEN(UART._UCLISTEN);         //自发自收或正常收发
/*3*/   put_P5SEL_BIT6(1);                          //第二功能，输出，作为TXD（53脚）
        put_P5SEL_BIT7(1);                          //第二功能，输出，作为RXD（54脚）
/*4*/   put_UART1_UCSWRST(0);                       //使能串口功能
//串行口UART1初始化结束--------------------------------------------------------------------
}
void init_UART2(UART_PARAMETER UART)
{
//串行口UART2初始化开始---------------------------------------------------------------------    
float x;unsigned int n;
/*1*/   put_UART2_UCSWRST(1);                       //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_UART2_UCMODE(UART._UCMODE);             //UART模式  
        if((UART._UCMODE>=1)&(UART._UCMODE<=3))
                  {put_UART2_UCDORM(1);}            //只收先导地址，而后必须软件清零以便接收数据
            else  {put_UART2_UCDORM(0);}            //接收所有数据
        put_UART2_UCSSEL(UART._UCSSEL);             //选择ACLK为波特率发生器信号源
        if(UART._UCMODE==3) 
                    {
                      put_UART2_UCABDEN(1);         //使能波特率自动检测
                    }
              else  {
                      put_UART2_UCABDEN(0);         //不使能波特率自动检测
                    }
        put_UART2_UCSYNC(0);                        //异步通讯
        put_UART2_UCPEN(UART._UCPEN);               //校验
        put_UART2_UCPAR(UART._UCPAR);               //偶或奇
        n=UART.clk_f/UART.baud_rate;
        if (n<16) { 
                    put_UART2_UCOS16(0);            //低频率模式
                    x=1.0*UART.clk_f/UART.baud_rate;
                    n=UART.clk_f/UART.baud_rate;
                    put_UART2_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*8+0.5);
                    put_UART2_UCBRS(n);             //小数分频配置
                  }
            else  {
                    put_UART2_UCOS16(1);            //高频率模式
                    n=UART.clk_f/UART.baud_rate/16;
                    x=1.0*UART.clk_f/UART.baud_rate/16;
                    put_UART2_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*16+0.5);
                    put_UART2_UCBRF(n);             //小数分频配置             
                  }        
        put_UART2_UCMSB(0);                         //从低位开始
        if(UART._UC7BIT==8) put_UART2_UC7BIT(0);    //8位数据传输
        if(UART._UC7BIT==7) put_UART2_UC7BIT(1);    //7位数据传输
        if(UART._UCSPB==1)  put_UART2_UCSPB(0);     //"0"一位停止位
        if(UART._UCSPB==2)  put_UART2_UCSPB(1);     //"1"二位停止位
        put_UART2_UCIREN(UART._UCIREN);             //0:UART收发;1:IrDA收发
//IrDA0开始 -----------------------------------------------------------------------------------------------
        put_UART2_UCIREN(UART._UCIREN);
        if (UART._UCIREN==1)
          {
            n=UART.clk_f/UART.baud_rate;
            if(n<16){put_UART2_UCIRTXCLK(0);}       //IrDA发送脉冲选择BRCLK
                else{put_UART2_UCIRTXCLK(1);}       //IrDA发送脉冲选择BRCLK16
            put_UART2_UCIRTXPL(0x1F);               //发送脉冲长度 Tpluse=(UCIRTXPLx + 1)/(2×Firtxclk)
            put_UART2_UCIRRXFE(1);                  //0：滤波器不使能；1: 滤波器使能 
            put_UART2_UCIRRXPL(UART._UCIRRXPL);     //接收极性选择。0:反相；1:不反相
            put_UART2_UCIRRXFL(0x1F);               //接收滤波长度 tMIN = (UCIRRXFLx + 4)/(2×fBRCLK)
          }
//IrDA0结束 -----------------------------------------------------------------------------------------------
        put_UART2_UCLISTEN(UART._UCLISTEN);         //自发自收或正常收发
/*3*/   put_P9SEL_BIT4(1);                          //第二功能，输出，作为TXD（72脚）
        put_P9SEL_BIT5(1);                          //第二功能，输出，作为RXD（73脚）
/*4*/   put_UART2_UCSWRST(0);                       //使能串口功能
//串行口UART2初始化结束--------------------------------------------------------------------
}
void init_UART3(UART_PARAMETER UART)
{
//串行口UART3初始化开始---------------------------------------------------------------------    
float x;unsigned int n;
/*1*/   put_UART3_UCSWRST(1);                       //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_UART3_UCMODE(UART._UCMODE);             //UART模式  
        if((UART._UCMODE>=1)&(UART._UCMODE<=3))
                  {put_UART3_UCDORM(1);}            //只收先导地址，而后必须软件清零以便接收数据
            else  {put_UART3_UCDORM(0);}            //接收所有数据
        put_UART3_UCSSEL(UART._UCSSEL);             //选择ACLK为波特率发生器信号源
        if(UART._UCMODE==3) 
                    {
                      put_UART3_UCABDEN(1);         //使能波特率自动检测
                    }
              else  {
                      put_UART3_UCABDEN(0);         //不使能波特率自动检测
                    }
        put_UART3_UCSYNC(0);                        //异步通讯
        put_UART3_UCPEN(UART._UCPEN);               //校验
        put_UART3_UCPAR(UART._UCPAR);               //偶或奇
        n=UART.clk_f/UART.baud_rate;
        if (n<16) { 
                    put_UART3_UCOS16(0);            //低频率模式
                    x=1.0*UART.clk_f/UART.baud_rate;
                    n=UART.clk_f/UART.baud_rate;
                    put_UART3_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*8+0.5);
                    put_UART3_UCBRS(n);             //小数分频配置
                  }
            else  {
                    put_UART3_UCOS16(1);            //高频率模式
                    n=UART.clk_f/UART.baud_rate/16;
                    x=1.0*UART.clk_f/UART.baud_rate/16;
                    put_UART3_UC0BR(n);             //波特率
                    x=x-n;
                    n=(int)(x*16+0.5);
                    put_UART3_UCBRF(n);             //小数分频配置             
                  }        
        put_UART3_UCMSB(0);                         //从低位开始
        if(UART._UC7BIT==8) put_UART3_UC7BIT(0);    //8位数据传输
        if(UART._UC7BIT==7) put_UART3_UC7BIT(1);    //7位数据传输
        if(UART._UCSPB==1)  put_UART3_UCSPB(0);     //"0"一位停止位
        if(UART._UCSPB==2)  put_UART3_UCSPB(1);     //"1"二位停止位
        put_UART3_UCIREN(UART._UCIREN);             //0:UART收发;1:IrDA收发
//IrDA0开始 -----------------------------------------------------------------------------------------------
        put_UART3_UCIREN(UART._UCIREN);
        if (UART._UCIREN==1)
          {
            n=UART.clk_f/UART.baud_rate;
            if(n<16){put_UART3_UCIRTXCLK(0);}       //IrDA发送脉冲选择BRCLK
                else{put_UART3_UCIRTXCLK(1);}       //IrDA发送脉冲选择BRCLK16
            put_UART3_UCIRTXPL(0x1F);               //发送脉冲长度 Tpluse=(UCIRTXPLx + 1)/(2×Firtxclk)
            put_UART3_UCIRRXFE(1);                  //0：滤波器不使能；1: 滤波器使能 
            put_UART3_UCIRRXPL(UART._UCIRRXPL);     //接收极性选择。0:反相；1:不反相
            put_UART3_UCIRRXFL(0x1F);               //接收滤波长度 tMIN = (UCIRRXFLx + 4)/(2×fBRCLK)
          }
//IrDA0结束 -----------------------------------------------------------------------------------------------
        put_UART3_UCLISTEN(UART._UCLISTEN);         //自发自收或正常收发
/*3*/   put_P10SEL_BIT4(1);                         //第二功能，输出，作为TXD（80脚）
        put_P10SEL_BIT5(1);                         //第二功能，输出，作为RXD（81脚）
/*4*/   put_UART3_UCSWRST(0);                       //使能串口功能
//串行口UART3初始化结束--------------------------------------------------------------------
}
void init_SPI_A0(SPI_PARAMETER SPI)
{
//串行口SPI_A0初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_A0_UCSWRST(1);                    //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_A0_UCSYNC(1);                     //同步通讯
        put_SPI_A0_UCSSEL(SPI._UCSSEL);           //选择ACLK为波特率发生器信号源
        put_SPI_A0_UCMODE(SPI._UCMODE);           //3线SPI模式
        put_SPI_A0_BRW(SPI.clk_f/SPI.baud_rate);  //波特率
        put_SPI_A0_UCMSB(SPI._UCMSB);             //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_A0_UC7BIT(0);  //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_A0_UC7BIT(1);  //7位数据传输
        put_SPI_A0_UCCKPL(SPI._UCCKPL);           //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_A0_UCCKPH(SPI._UCCKPH);           //时钟相位选择
        put_SPI_A0_UCMST(SPI._UCMST);             //主从选择（0：从机；1：主机）
        put_SPI_A0_UCLISTEN(SPI._UCLISTEN);       //0:自发自收；1:正常收发
/*3*/   put_P3SEL_BIT0(1);                        //第二功能
        if(SPI._UCMST==1) put_P3DIR_BIT0(1);      //作为SPI_A0的CLK(33脚)的输出端
                     else put_P3DIR_BIT0(0);      //作为SPI_A0的CLK(33脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
          {
            put_P3SEL_BIT3(1);
            put_P3DIR_BIT3(0);
//            if(SPI._UCMST==1) put_P3DIR_BIT3(0);  //第二功能，作为SPI_A0的STE(36脚)
//                         else put_P3DIR_BIT3(1);  //第二功能，作为SPI_A0的STE(36脚)
          }
        put_P3SEL_BIT4(1);                        //第二功能，作为SPI_A0的SIMO(39脚)
        put_P3SEL_BIT5(1);                        //第二功能，作为SPI_A0的SOMI(40脚)
/*4*/   put_SPI_A0_UCSWRST(0);                    //使能串口功能
//串行口SPI_A0初始化结束--------------------------------------------------------------------
}
void init_SPI_A1(SPI_PARAMETER SPI)
{
//串行口SPI_A1初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_A1_UCSWRST(1);                    //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_A1_UCSYNC(1);                     //同步通讯
        put_SPI_A1_UCSSEL(SPI._UCSSEL);           //选择ACLK为波特率发生器信号源
        put_SPI_A1_UCMODE(SPI._UCMODE);           //3线SPI模式
        put_SPI_A1_BRW(SPI.clk_f/SPI.baud_rate);  //波特率
        put_SPI_A1_UCMSB(SPI._UCMSB);             //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_A1_UC7BIT(0);  //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_A1_UC7BIT(1);  //7位数据传输
        put_SPI_A1_UCCKPL(SPI._UCCKPL);           //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_A1_UCCKPH(SPI._UCCKPH);           //时钟相位选择
        put_SPI_A1_UCMST(SPI._UCMST);             //主从选择（0：从机；1：主机）
        put_SPI_A1_UCLISTEN(SPI._UCLISTEN);       //0:自发自收；1:正常收发
/*3*/   put_P3SEL_BIT6(1);                        //第二功能
        if(SPI._UCMST==1) put_P3DIR_BIT6(1);      //作为SPI_A1的CLK(41脚)的输出端
                     else put_P3DIR_BIT6(0);      //作为SPI_A1的CLK(41脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
          {
            put_P5SEL_BIT5(1);
            put_P5DIR_BIT5(0);
//            if(SPI._UCMST==1) put_P5DIR_BIT5(0);  //第二功能，作为SPI_A1的STE(52脚)
//                         else put_P5DIR_BIT5(1);
          }
        put_P5SEL_BIT6(1);                       //第二功能，作为SPI_A1的SIMO(53脚)
        put_P5SEL_BIT7(1);                       //第二功能，作为SPI_A1的SOMI(54脚)
/*4*/   put_SPI_A1_UCSWRST(0);                   //使能串口功能
//串行口SPI_A1初始化结束--------------------------------------------------------------------
}
void init_SPI_A2(SPI_PARAMETER SPI)
{
//串行口SPI_A2初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_A2_UCSWRST(1);                    //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_A2_UCSYNC(1);                         //同步通讯
        put_SPI_A2_UCSSEL(SPI._UCSSEL);               //选择ACLK为波特率发生器信号源
        put_SPI_A2_UCMODE(SPI._UCMODE);               //3线SPI模式
        put_SPI_A2_BRW(SPI.clk_f/SPI.baud_rate);      //波特率
        put_SPI_A2_UCMSB(SPI._UCMSB);                 //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_A2_UC7BIT(0);      //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_A2_UC7BIT(1);      //7位数据传输
        put_SPI_A2_UCCKPL(SPI._UCCKPL);               //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_A2_UCCKPH(SPI._UCCKPH);               //时钟相位选择
        put_SPI_A2_UCMST(SPI._UCMST);                 //主从选择（0：从机；1：主机）
        put_SPI_A2_UCLISTEN(SPI._UCLISTEN);           //0:自发自收；1:正常收发
/*3*/   put_P9SEL_BIT3(1);                            //第二功能
        if(SPI._UCMST==1) put_P9DIR_BIT3(1);          //作为SPI_A2的CLK(68脚)的输出端
                     else put_P3DIR_BIT3(0);          //作为SPI_A2的CLK(68脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
          {
            put_P9SEL_BIT3(1);
            put_P9DIR_BIT3(0);
//            if(SPI._UCMST==1) put_P9DIR_BIT3(0);      //第二功能，作为SPI_A2的STE(71脚)
//                         else put_P9DIR_BIT3(1);
          }
        put_P9SEL_BIT4(1);                            //第二功能，作为SPI_A2的SIMO(72脚)
        put_P9SEL_BIT5(1);                            //第二功能，作为SPI_A2的SOMI(73脚)
/*4*/   put_SPI_A2_UCSWRST(0);                        //使能串口功能
//串行口SPI_A2初始化结束--------------------------------------------------------------------
}
void init_SPI_A3(SPI_PARAMETER SPI)
{
//串行口SPI_A3初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_A3_UCSWRST(1);                    //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_A3_UCSYNC(1);                           //同步通讯
        put_SPI_A3_UCSSEL(SPI._UCSSEL);                 //选择ACLK为波特率发生器信号源
        put_SPI_A3_UCMODE(SPI._UCMODE);                 //3线SPI模式
        put_SPI_A3_BRW(SPI.clk_f/SPI.baud_rate);        //波特率
        put_SPI_A3_UCMSB(SPI._UCMSB);                   //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_A3_UC7BIT(0);        //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_A3_UC7BIT(1);        //7位数据传输
        put_SPI_A3_UCCKPL(SPI._UCCKPL);                 //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_A3_UCCKPH(SPI._UCCKPH);                 //时钟相位选择
        put_SPI_A3_UCMST(SPI._UCMST);                   //主从选择（0：从机；1：主机）
        put_SPI_A3_UCLISTEN(SPI._UCLISTEN);             //0:自发自收；1:正常收发
/*3*/   put_P10SEL_BIT0(1);                             //第二功能
        if(SPI._UCMST==1) put_P10DIR_BIT0(1);           //作为SPI_A3的CLK(76脚)的输出端
                     else put_P10DIR_BIT0(0);           //作为SPI_A3的CLK(76脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
            {
              put_P10SEL_BIT3(1);
              put_P10DIR_BIT3(0);
//              if(SPI._UCMST==1) put_P10DIR_BIT3(0);     //第二功能，作为SPI_A3的STE(52脚)
//                           else put_P10DIR_BIT3(1);
            }
        put_P10SEL_BIT4(1);                             //第二功能，作为SPI_A3的SIMO(80脚)
        put_P10SEL_BIT5(1);                             //第二功能，作为SPI_A3的SOMI(81脚)
/*4*/   put_SPI_A3_UCSWRST(0);                          //使能串口功能
//串行口SPI_A3初始化结束--------------------------------------------------------------------
}

//MSP430串行通信B组初始化函数开始 *************************************************************
void init_SPI_B0(SPI_PARAMETER SPI)
{
//串行口SPI_B0初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_B0_UCSWRST(1);                          //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_B0_UCSYNC(1);                           //同步通讯
        put_SPI_B0_UCSSEL(SPI._UCSSEL);                 //选择ACLK为波特率发生器信号源
        put_SPI_B0_UCMODE(SPI._UCMODE);                 //3线SPI模式
        put_SPI_B0_BRW(SPI.clk_f/SPI.baud_rate);        //波特率
        put_SPI_B0_UCMSB(SPI._UCMSB);                   //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_B0_UC7BIT(0);        //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_B0_UC7BIT(1);        //7位数据传输
        put_SPI_B0_UCCKPL(SPI._UCCKPL);                 //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_B0_UCCKPH(SPI._UCCKPH);                 //时钟相位选择
        put_SPI_B0_UCMST(SPI._UCMST);                   //主从选择（0：从机；1：主机）
        put_SPI_B0_UCLISTEN(SPI._UCLISTEN);             //0:自发自收；1:正常收发
/*3*/   put_P3SEL_BIT3(1);                              //第二功能
        if(SPI._UCMST==1) put_P3DIR_BIT3(1);            //作为SPI_B0的CLK(36脚)的输出端
                     else put_P3DIR_BIT3(0);            //作为SPI_B0的CLK(36脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
            {
              put_P3SEL_BIT0(1);
              put_P3DIR_BIT0(0);
//              if(SPI._UCMST==1) put_P3DIR_BIT0(0);      //第二功能，作为SPI_B0的STE(52脚)
//                           else put_P3DIR_BIT0(1);
            }
        put_P3SEL_BIT1(1);                              //P3.1第二功能，作为SPI_B0的SIMO(34脚)
        put_P3SEL_BIT2(1);                              //P3.2第二功能，作为SPI_B0的SOMI(35脚)
/*4*/   put_SPI_B0_UCSWRST(0);                          //使能串口功能
//串行口SPI_B0初始化结束--------------------------------------------------------------------
}
void init_SPI_B1(SPI_PARAMETER SPI)
{
//串行口SPI_B1初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_B1_UCSWRST(1);                          //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_B1_UCSYNC(1);                           //同步通讯
        put_SPI_B1_UCSSEL(SPI._UCSSEL);                 //选择ACLK为波特率发生器信号源
        put_SPI_B1_UCMODE(SPI._UCMODE);                 //3线SPI模式
        put_SPI_B1_BRW(SPI.clk_f/SPI.baud_rate);        //波特率
        put_SPI_B1_UCMSB(SPI._UCMSB);                   //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_B1_UC7BIT(0);        //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_B1_UC7BIT(1);        //7位数据传输
        put_SPI_B1_UCCKPL(SPI._UCCKPL);                 //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_B1_UCCKPH(SPI._UCCKPH);                 //时钟相位选择
        put_SPI_B1_UCMST(SPI._UCMST);                   //主从选择（0：从机；1：主机）
        put_SPI_B1_UCLISTEN(SPI._UCLISTEN);             //0:自发自收；1:正常收发
/*3*/   put_P5SEL_BIT5(1);                              //第二功能
        if(SPI._UCMST==1) put_P5DIR_BIT5(1);            //作为SPI_B1的CLK(52脚)的输出端
                     else put_P5DIR_BIT5(0);            //作为SPI_B1的CLK(52脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
            {
              put_P3SEL_BIT6(1);
              put_P3DIR_BIT6(0);
//              if(SPI._UCMST==1) put_P3DIR_BIT6(0);      //第二功能，作为SPI_B1的STE(41脚)
//                           else put_P3DIR_BIT6(1);
            }
        put_P3SEL_BIT7(1);                              //P3.7第二功能，作为SPI_B1的SIMO(42脚)
        put_P5SEL_BIT4(1);                              //P5.4第二功能，作为SPI_B1的SOMI(51脚)
/*4*/   put_SPI_B1_UCSWRST(0);                          //使能串口功能
//串行口SPI_B1初始化结束--------------------------------------------------------------------
}
void init_SPI_B2(SPI_PARAMETER SPI)
{
//串行口SPI_B2初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_B2_UCSWRST(1);                          //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_B2_UCSYNC(1);                           //同步通讯
        put_SPI_B2_UCSSEL(SPI._UCSSEL);                 //选择ACLK为波特率发生器信号源
        put_SPI_B2_UCMODE(SPI._UCMODE);                 //3线SPI模式
        put_SPI_B2_BRW(SPI.clk_f/SPI.baud_rate);        //波特率
        put_SPI_B2_UCMSB(SPI._UCMSB);                   //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_B2_UC7BIT(0);        //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_B2_UC7BIT(1);        //7位数据传输
        put_SPI_B2_UCCKPL(SPI._UCCKPL);                 //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_B2_UCCKPH(SPI._UCCKPH);                 //时钟相位选择
        put_SPI_B2_UCMST(SPI._UCMST);                   //主从选择（0：从机；1：主机）
        put_SPI_B2_UCLISTEN(SPI._UCLISTEN);             //0:自发自收；1:正常收发
/*3*/   put_P9SEL_BIT3(1);                              //第二功能
        if(SPI._UCMST==1) put_P9DIR_BIT3(1);            //作为SPI_B2的CLK(71脚)的输出端
                     else put_P9DIR_BIT3(0);            //作为SPI_B2的CLK(71脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
            {
              put_P9SEL_BIT0(1);
              put_P9DIR_BIT0(0); 
//              if(SPI._UCMST==1) put_P9DIR_BIT0(0);      //第二功能，作为SPI_B2的STE(68脚)
//                           else put_P9DIR_BIT0(1);
            }
        put_P9SEL_BIT1(1);                              //P9.1第二功能，作为SPI_B2的SIMO(69脚)
        put_P9SEL_BIT2(1);                              //P9.2第二功能，作为SPI_B2的SOMI(70脚)
/*4*/   put_SPI_B2_UCSWRST(0);                          //使能串口功能
//串行口SPI_B2初始化结束--------------------------------------------------------------------
}
void init_SPI_B3(SPI_PARAMETER SPI)
{
//串行口SPI_B3初始化开始---------------------------------------------------------------------    
/*1*/   put_SPI_B3_UCSWRST(1);                          //清除的一切串口功能，相当于上电后的原始状态
/*2*/   /*在UCSWRST=1期间对所有USCI寄存器进行初始化*/   
        put_SPI_B3_UCSYNC(1);                           //同步通讯
        put_SPI_B3_UCSSEL(SPI._UCSSEL);                 //选择ACLK为波特率发生器信号源
        put_SPI_B3_UCMODE(SPI._UCMODE);                 //3线SPI模式
        put_SPI_B3_BRW(SPI.clk_f/SPI.baud_rate);        //波特率
        put_SPI_B3_UCMSB(SPI._UCMSB);                   //从低位开始   
        if(SPI._UC7BIT==8) put_SPI_B3_UC7BIT(0);        //8位数据传输
        if(SPI._UC7BIT==7) put_SPI_B3_UC7BIT(1);        //7位数据传输
        put_SPI_B3_UCCKPL(SPI._UCCKPL);                 //时钟活跃选择（0:低电平不活跃；1:高电平不活跃）
        put_SPI_B3_UCCKPH(SPI._UCCKPH);                 //时钟相位选择
        put_SPI_B3_UCMST(SPI._UCMST);                   //主从选择（0：从机；1：主机）
        put_SPI_B3_UCLISTEN(SPI._UCLISTEN);             //0:自发自收；1:正常收发
/*3*/   put_P10SEL_BIT3(1);                             //第二功能
        if(SPI._UCMST==1) put_P10DIR_BIT3(1);           //作为SPI_B3的CLK(36脚)的输出端
                     else put_P10DIR_BIT3(0);           //作为SPI_B3的CLK(36脚)的输入端
        if((SPI._UCMODE==1) | (SPI._UCMODE==2)) 
            {
              put_P10SEL_BIT0(1);
              put_P10DIR_BIT0(0);
//              if(SPI._UCMST==1) put_P10DIR_BIT0(0);     //第二功能，作为SPI_B3的STE(76脚)
//                           else put_P10DIR_BIT0(1);
            }
        put_P10SEL_BIT1(1);                             //P10.1第二功能，作为SPI_B3的SIMO(77脚)
        put_P10SEL_BIT2(1);                             //P10.2第二功能，作为SPI_B3的SOMI(78脚)
/*4*/   put_SPI_B3_UCSWRST(0);                          //使能串口功能
//串行口SPI_B3初始化结束--------------------------------------------------------------------
}
//MSP430串行通信B组初始化函数结束 *************************************************************
//MSP430串行通信IIC开始 ********************************************************************
void init_IIC0(IIC_PARAMETER IIC)
{
    put_IIC0_UCSWRST(1);                    //为了初始化IIC0的各个寄存器
    put_IIC0_UCMODE(3);                     //主串行口IIC0工作方式
    put_IIC0_UCSYNC(1);                     //同步模式，串行口IIC0工作方式，该位必须为1
    put_IIC0_UCSSEL(IIC._UCSSEL);           //时钟选择SMCLK(参数2和3都是选中SMCLK)
    put_IIC0_I2COA(IIC._I2COA);             //本机地址
    if(IIC._UCA10==7)
      put_IIC0_UCA10(0);                    //本机地址长度为7位
    if(IIC._UCA10==10)
      put_IIC0_UCA10(1);                    //本机地址长度为10位
    put_IIC0_UC0BR(IIC.clk_f/IIC.baud_rate);//通信速率
    put_P3SEL_BIT1(1);                      //SDA_0,P3.1(34脚)作为第二功能,作为IIC_SDA
    put_P3SEL_BIT2(1);                      //SCL_0,P3.2(35脚)作为第二功能,作为IIC_SCL
    put_IIC0_UCMM(IIC._UCMM);               //IIC0多主机模式
    put_IIC0_UCMST(IIC._UCMST);             //主、从模式选择
    put_IIC0_UCTR(IIC._UCTR);               //IIC0主机接收或发送模式
    put_IIC0_UCGCEN(IIC._UCGCEN);           //响应呼叫
    put_IIC0_UCSLA10(IIC._UCSLA10);         //从机地址位7位
    if(IIC._UCSLA10==7)
      put_IIC0_UCSLA10(0);                  //从机7位地址长度
    if(IIC._UCSLA10==10)
      put_IIC0_UCSLA10(1);                  //从机10位地址长度
    put_IIC0_I2CSA(IIC._I2CSA);             //从机（一般为从器件地址）地址
    put_IIC0_UCSWRST(0);                    //正常工作  
}  
void init_IIC1(IIC_PARAMETER IIC)
{
    put_IIC1_UCSWRST(1);                    //为了初始化IIC0的各个寄存器
    put_IIC1_UCMODE(3);                     //主串行口IIC0工作方式
    put_IIC1_UCSYNC(1);                     //同步模式，串行口IIC0工作方式，该位必须为1
    put_IIC1_UCSSEL(IIC._UCSSEL);           //时钟选择SMCLK(参数2和3都是选中SMCLK)
    put_IIC1_I2COA(IIC._I2COA);             //本机地址
    if(IIC._UCA10==7)
      put_IIC1_UCA10(0);                    //本机地址长度为7位
    if(IIC._UCA10==10)
      put_IIC1_UCA10(1);                    //本机地址长度为10位
    put_IIC1_UC1BR(IIC.clk_f/IIC.baud_rate);//通信速率
    put_P3SEL_BIT7(1);                      //SDA_0,P3.7(42脚)作为第二功能,作为IIC_SDA
    put_P5SEL_BIT4(1);                      //SCL_0,P5.4(51脚)作为第二功能,作为IIC_SCL
    put_IIC1_UCMM(IIC._UCMM);               //IIC1多主机模式
    put_IIC1_UCMST(IIC._UCMST);             //主、从模式选择
    put_IIC1_UCTR(IIC._UCTR);               //IIC1主机接收或发送模式
    put_IIC1_UCGCEN(IIC._UCGCEN);           //响应呼叫
    put_IIC1_UCSLA10(IIC._UCSLA10);         //从机地址位7位
    if(IIC._UCSLA10==7)
      put_IIC1_UCSLA10(0);                  //从机7位地址长度
    if(IIC._UCSLA10==10)
      put_IIC1_UCSLA10(1);                  //从机10位地址长度
    put_IIC1_I2CSA(IIC._I2CSA);             //从机（一般为从器件地址）地址
    put_IIC1_UCSWRST(0);                    //正常工作  
}  
void init_IIC2(IIC_PARAMETER IIC)
{
    put_IIC2_UCSWRST(1);                    //为了初始化IIC0的各个寄存器
    put_IIC2_UCMODE(3);                     //主串行口IIC0工作方式
    put_IIC2_UCSYNC(1);                     //同步模式，串行口IIC0工作方式，该位必须为1
    put_IIC2_UCSSEL(IIC._UCSSEL);           //时钟选择SMCLK(参数2和3都是选中SMCLK)
    put_IIC2_I2COA(IIC._I2COA);             //本机地址
    if(IIC._UCA10==7)
      put_IIC2_UCA10(0);                    //本机地址长度为7位
    if(IIC._UCA10==10)
      put_IIC2_UCA10(1);                    //本机地址长度为10位
    put_IIC2_UC2BR(IIC.clk_f/IIC.baud_rate);//通信速率
    put_P9SEL_BIT1(1);                      //SDA_0,P9.1(69脚)作为第二功能,作为IIC_SDA
    put_P9SEL_BIT2(1);                      //SCL_0,P9.2(70脚)作为第二功能,作为IIC_SCL
    put_IIC2_UCMM(IIC._UCMM);               //IIC2多主机模式
    put_IIC2_UCMST(IIC._UCMST);             //主、从模式选择
    put_IIC2_UCTR(IIC._UCTR);               //IIC2主机接收或发送模式
    put_IIC2_UCGCEN(IIC._UCGCEN);           //响应呼叫
    put_IIC2_UCSLA10(IIC._UCSLA10);         //从机地址
    if(IIC._UCSLA10==7)
      put_IIC2_UCSLA10(0);                  //从机7位地址长度
    if(IIC._UCSLA10==10)
      put_IIC2_UCSLA10(1);                  //从机10位地址长度
    put_IIC2_I2CSA(IIC._I2CSA);             //从机（一般为从器件地址）地址
    put_IIC2_UCSWRST(0);                    //正常工作  
}  
void init_IIC3(IIC_PARAMETER IIC)
{
    put_IIC3_UCSWRST(1);                    //为了初始化IIC0的各个寄存器
    put_IIC3_UCMODE(3);                     //主串行口IIC0工作方式
    put_IIC3_UCSYNC(1);                     //同步模式，串行口IIC0工作方式，该位必须为1
    put_IIC3_UCSSEL(IIC._UCSSEL);           //时钟选择SMCLK(参数2和3都是选中SMCLK)
    put_IIC3_I2COA(IIC._I2COA);             //本机地址
    if(IIC._UCA10==7)
      put_IIC3_UCA10(0);                    //本机地址长度为7位
    if(IIC._UCA10==10)
      put_IIC3_UCA10(1);                    //本机地址长度为10位
    put_IIC3_UC3BR(IIC.clk_f/IIC.baud_rate);//通信速率
    put_P10SEL_BIT1(1);                     //SDA_0,P10.1(77脚)作为第二功能,作为IIC_SDA
    put_P10SEL_BIT2(1);                     //SCL_0,P10.2(78脚)作为第二功能,作为IIC_SCL
    put_IIC3_UCMM(IIC._UCMM);               //IIC3多主机模式
    put_IIC3_UCMST(IIC._UCMST);             //主、从模式选择
    put_IIC3_UCTR(IIC._UCTR);               //IIC3主机接收或发送模式
    put_IIC3_UCGCEN(IIC._UCGCEN);           //响应呼叫
    put_IIC3_UCSLA10(IIC._UCSLA10);         //从机地址位7位
    if(IIC._UCSLA10==7)
      put_IIC3_UCSLA10(0);                  //从机7位地址长度
    if(IIC._UCSLA10==10)
      put_IIC3_UCSLA10(1);                  //从机10位地址长度
    put_IIC3_I2CSA(IIC._I2CSA);             //从机（一般为从器件地址）地址 
    put_IIC3_UCSWRST(0);                    //正常工作 
}  
//MSP430串行通信IIC结束 ********************************************************************
void init_ADC(ADC_PARAMETER ADC)
{
//ADC 核初始化开始-----------------------------------------------------------------------------------------
        put_ENC(0);                           //ADC12的控制位只有在ADC12ENC = 0时，才能够被修改控制状态
        put_REFON(ADC._REFON);                //在通道选择INCH=0AH（检测内部参考电压）时，可以不用该条语句
        put_REF2_5V(ADC._REF2_5V);            //参数为0时，参考电压为1.5V，参数为1时，参考电压为2.5V
        put_ADC12SR(ADC._ADC12SR_);           //采样速率，为1时采样速率高达50ksps,为0时高达200ksps
        put_REFBURST(ADC._REFBURST);          //参考电压连续，反之，只在采样转换期间提供
        put_ADC12SSEL(ADC._ADC12SSEL);        //选择ACLK作为模数转换时钟
        put_ADC12PDIV(ADC._ADC12PDIV);        //对模数转换时钟预分频，1分频或4分频，此处为1分频，即就是ACLK
        put_ADC12DIV(ADC._ADC12DIV);          //对模数转换时钟细分频，此处选择不分频，即1分频
        put_SHS(ADC._SHS);                    //采样保持信号选择，此处选择ADC12SC位
        put_ISSH(ADC._ISSH);                  //0：不反相；1：反相
        put_SHP(ADC._SHP);                    //采样保持脉冲模式选择：来自于采样输入或采样定时器.
        put_MSC(ADC._MSC);                    //启动采样定时器，之后每当转换结束，就予以启动
        put_SHT0(ADC._SHT0);                  //采样保持时间，选择8个ADC12CLK周期，ADC12MEM0 to ADC12MEM7.
        put_ADC12SHT1(ADC._ADC12SHT1);        //采样保持时间，选择8个ADC12CLK周期，ADC12MEM8 to ADC12MEM15.
        put_ADC12RES(ADC._ADC12RES);          //模数转换位数选择
        put_ADC12DF(ADC._ADC12DF);            //转换结果符号选择
        put_CONSEQ(ADC._CONSEQ);              //选择单次转换。0：单通道单次；1：顺序通道转换；2：单通道重复；3：顺序通道转换重复
        put_ADC12OVIE(ADC._ADCOVIE);          //结果寄存器溢出中断
        put_ADC12TOVIE(ADC._ADCTOVIE);        //转换超时中断
        put_ENC(1);                           //设置完成后无必须ADC12ENC=1
        put_ADC12ON(1);    	              //开启模数转换器
//ADC0开始-----------------------------------------------------------------------------------------------------
}
//void ADC_SINGEL_INCH(char _INCH,char _SREF,           //如果只有ADC12IE0能够实现中断的话，参数
//                     char _ADC12IE,char _ADC12EOS)    //_ADC12IE就没有必要了,放在初始换程序中就是了
void ADC_SINGEL_INCH(char _INCH,char _SREF,           
                     char _ADC12EOS)                                                                                         
{
        put_ADC12ON(0);    	                      //关闭模数转换器
        put_ENC(0);       	                      //修改设置之前必须ADC12ENC=0
        switch (_INCH)
          {
            case  0:{
                      put_P6SEL_BIT0(1);              //0#模拟通道
                      put_ADC0_INCH(_INCH);           //转换器通道选择
                      put_ADC0_SREF(_SREF);           //转换器参考电压选择
                      put_ADC0_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE0(_ADC12IE);
                      break;
                    }
            case  1:{ 
                      put_P6SEL_BIT1(1);              //1#模拟通道
                      put_ADC1_INCH(_INCH);           //转换器通道选择
                      put_ADC1_SREF(_SREF);           //转换器参考电压选择
                      put_ADC1_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE1(_ADC12IE);
                      break;
                    }  
            case  2:{ 
                      put_P6SEL_BIT2(1);              //2#模拟通道
                      put_ADC2_INCH(_INCH);           //转换器通道选择
                      put_ADC2_SREF(_SREF);           //转换器参考电压选择
                      put_ADC2_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE2(_ADC12IE);
                      break;
                    }
            case  3:{ 
                      put_P6SEL_BIT3(1);              //3#模拟通道
                      put_ADC3_INCH(_INCH);           //转换器通道选择
                      put_ADC3_SREF(_SREF);           //转换器参考电压选择
                      put_ADC3_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE3(_ADC12IE);
                      break;
                    }  
            case  4:{ 
                      put_P6SEL_BIT4(1);              //4#模拟通道
                      put_ADC4_INCH(_INCH);           //转换器通道选择
                      put_ADC4_SREF(_SREF);           //转换器参考电压选择
                      put_ADC4_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE4(_ADC12IE);
                      break;
                    }
            case  5:{ 
                      put_P6SEL_BIT5(1);              //5#模拟通道
                      put_ADC5_INCH(_INCH);           //转换器通道选择
                      put_ADC5_SREF(_SREF);           //转换器参考电压选择
                      put_ADC5_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE5(_ADC12IE);
                      break;
                    }   
            case  6:{ 
                      put_P6SEL_BIT6(1);              //6#模拟通道
                      put_ADC6_INCH(_INCH);           //转换器通道选择
                      put_ADC6_SREF(_SREF);           //转换器参考电压选择
                      put_ADC6_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE6(_ADC12IE);
                      break;
                    }
            case  7:{
                      put_P6SEL_BIT7(1);              //7#模拟通道
                      put_ADC7_INCH(_INCH);           //转换器通道选择
                      put_ADC7_SREF(_SREF);           //转换器参考电压选择
                      put_ADC7_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE7(_ADC12IE);
                      break;
                    }
            case  8:{ 
                      put_P5SEL_BIT0(1);              //外部参考电压（VR+）
                      put_ADC8_INCH(_INCH);           //转换器通道选择
                      put_ADC8_SREF(_SREF);           //转换器参考电压选择
                      put_ADC8_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE8(_ADC12IE);
                      break;
                    }
            case  9:{ 
                      put_P5SEL_BIT1(1);              //外部参考电压（VR-）
                      put_ADC9_INCH(_INCH);           //转换器通道选择
                      put_ADC9_SREF(_SREF);           //转换器参考电压选择
                      put_ADC9_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE9(_ADC12IE);
                      break;
                    }
            case 10:{ 
                      put_ADC12TCOFF(1);              //检测温度传感器
                      put_ADC10_INCH(_INCH);          //转换器通道选择
                      put_ADC10_SREF(_SREF);          //转换器参考电压选择
                      put_ADC10_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE10(_ADC12IE);
                      break;
                    }
            case 11:{                                 //检测模拟电源电压
                      put_ADC11_INCH(_INCH);          //转换器通道选择
                      put_ADC11_SREF(_SREF);          //转换器参考电压选择
                      put_ADC11_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE11(_ADC12IE);
                      break;
                    }
            case 12:{ 
                      put_P7SEL_BIT4(1);              //12#模拟通道
                      put_ADC12_INCH(_INCH);          //转换器通道选择
                      put_ADC12_SREF(_SREF);          //转换器参考电压选择
                      put_ADC12_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE12(_ADC12IE);
                      break;
                    }
            case 13:{ 
                      put_P7SEL_BIT5(1);              //13模拟通道
                      put_ADC13_INCH(_INCH);          //转换器通道选择
                      put_ADC13_SREF(_SREF);          //转换器参考电压选择
                      put_ADC13_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE13(_ADC12IE);
                      break;
                    }
            case 14:{ 
                      put_P7SEL_BIT6(1);              //14#模拟通道
                      put_ADC14_INCH(_INCH);          //转换器通道选择
                      put_ADC14_SREF(_SREF);          //转换器参考电压选择
                      put_ADC14_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE14(_ADC12IE);
                      break;
                    }
            case 15:{ 
                      put_P7SEL_BIT7(1);              //15#模拟通道
                      put_ADC15_INCH(_INCH);          //转换器通道选择
                      put_ADC15_SREF(_SREF);          //转换器参考电压选择
                      put_ADC15_ADC12EOS(_ADC12EOS);
                      //put_ADC12IE15(_ADC12IE);
                      break;
                    }
            default:                    break;
          }
        put_CSTARTADD(0);
        put_ADC12IE0(1);                              //put_ADC12IE0(_ADC12IE);
        put_ADC12ON(1);    	                      //开启模数转换器
        put_ENC(1);       	                      //设置完成后无必须ADC12ENC=1
}
void ADC_SCAN_INCH(char _INCH,char _SREF,
                   char _CSTARTADD,char _ADC12EOS,
                   char _ADC12IE)
{
        put_ADC12ON(0);    	                      //关闭模数转换器
        put_ENC(0);       	                      //修改设置之前必须ADC12ENC=0
        switch (_INCH)
          {
            case  0:{
                      put_P6SEL_BIT0(1);              //0#模拟通道
                      put_ADC0_INCH(_INCH);           //转换器通道选择
                      put_ADC0_SREF(_SREF);           //转换器参考电压选择
                      put_ADC0_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE0(_ADC12IE);
                      break;
                    }
            case  1:{ 
                      put_P6SEL_BIT1(1);              //1#模拟通道
                      put_ADC1_INCH(_INCH);           //转换器通道选择
                      put_ADC1_SREF(_SREF);           //转换器参考电压选择
                      put_ADC1_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE1(_ADC12IE);
                      break;
                    }  
            case  2:{ 
                      put_P6SEL_BIT2(1);              //2#模拟通道
                      put_ADC2_INCH(_INCH);           //转换器通道选择
                      put_ADC2_SREF(_SREF);           //转换器参考电压选择
                      put_ADC2_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE2(_ADC12IE);
                      break;
                    }
            case  3:{ 
                      put_P6SEL_BIT3(1);              //3#模拟通道
                      put_ADC3_INCH(_INCH);           //转换器通道选择
                      put_ADC3_SREF(_SREF);           //转换器参考电压选择
                      put_ADC3_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE3(_ADC12IE);
                      break;
                    }  
            case  4:{ 
                      put_P6SEL_BIT4(1); //4#模拟通道
                      put_ADC4_INCH(_INCH);           //转换器通道选择
                      put_ADC4_SREF(_SREF);           //转换器参考电压选择
                      put_ADC4_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE4(_ADC12IE);
                      break;
                    }
            case  5:{ 
                      put_P6SEL_BIT5(1);              //5#模拟通道
                      put_ADC5_INCH(_INCH);           //转换器通道选择
                      put_ADC5_SREF(_SREF);           //转换器参考电压选择
                      put_ADC5_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE4(_ADC12IE);
                      break;
                    }   
            case  6:{ 
                      put_P6SEL_BIT6(1);              //6#模拟通道
                      put_ADC6_INCH(_INCH);           //转换器通道选择
                      put_ADC6_SREF(_SREF);           //转换器参考电压选择
                      put_ADC6_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE6(_ADC12IE);
                      break;
                    }
            case  7:{
                      put_P6SEL_BIT7(1);              //7#模拟通道
                      put_ADC7_INCH(_INCH);           //转换器通道选择
                      put_ADC7_SREF(_SREF);           //转换器参考电压选择
                      put_ADC7_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE7(_ADC12IE);
                      break;
                    }
            case  8:{ 
                      put_P5SEL_BIT0(1);              //外部参考电压（VR+）
                      put_ADC8_INCH(_INCH);           //转换器通道选择
                      put_ADC8_SREF(_SREF);           //转换器参考电压选择
                      put_ADC8_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE8(_ADC12IE);
                      break;
                    }
            case  9:{ 
                      put_P5SEL_BIT1(1);              //外部参考电压（VR-）
                      put_ADC9_INCH(_INCH);           //转换器通道选择
                      put_ADC9_SREF(_SREF);           //转换器参考电压选择
                      put_ADC9_ADC12EOS(_ADC12EOS);   //序列尾
                      put_ADC12IE9(_ADC12IE);
                      break;
                    }
            case 10:{ 
                      put_ADC12TCOFF(1);              //检测温度传感器
                      put_ADC10_INCH(_INCH);          //转换器通道选择
                      put_ADC10_SREF(_SREF);          //转换器参考电压选择
                      put_ADC10_ADC12EOS(_ADC12EOS);  //序列尾
                      put_ADC12IE10(_ADC12IE);
                      break;
                    }
            case 11:{                                 //检测模拟电源电压
                      put_ADC11_INCH(_INCH);          //转换器通道选择
                      put_ADC11_SREF(_SREF);          //转换器参考电压选择
                      put_ADC11_ADC12EOS(_ADC12EOS);  //序列尾
                      put_ADC12IE11(_ADC12IE);
                      break;
                    }
            case 12:{ 
                      put_P7SEL_BIT4(1);              //12#模拟通道
                      put_ADC12_INCH(_INCH);          //转换器通道选择
                      put_ADC12_SREF(_SREF);          //转换器参考电压选择
                      put_ADC12_ADC12EOS(_ADC12EOS);  //序列尾
                      put_ADC12IE12(_ADC12IE);
                      break;
                    }
            case 13:{ 
                      put_P7SEL_BIT5(1);              //13模拟通道
                      put_ADC13_INCH(_INCH);          //转换器通道选择
                      put_ADC13_SREF(_SREF);          //转换器参考电压选择
                      put_ADC13_ADC12EOS(_ADC12EOS);  //序列尾
                      put_ADC12IE13(_ADC12IE);
                      break;
                    }
            case 14:{ 
                      put_P7SEL_BIT6(1);              //14#模拟通道
                      put_ADC14_INCH(_INCH);          //转换器通道选择
                      put_ADC14_SREF(_SREF);          //转换器参考电压选择
                      put_ADC14_ADC12EOS(_ADC12EOS);  //序列尾
                      put_ADC12IE14(_ADC12IE);
                      break;
                    }
            case 15:{ 
                      put_P7SEL_BIT7(1);              //15#模拟通道
                      put_ADC15_INCH(_INCH);          //转换器通道选择
                      put_ADC15_SREF(_SREF);          //转换器参考电压选择
                      put_ADC15_ADC12EOS(_ADC12EOS);  //序列尾
                      put_ADC12IE15(_ADC12IE);
                      break;
                    }
            default:                    break;
          }
        put_CSTARTADD(_CSTARTADD);
        put_ADC12ON(1);    	            //开启模数转换器
        put_ENC(1);       	            //设置完成后无必须ADC12ENC=1
}
void init_DMA0(DMA_PARAMETER DMA)
{
    put_DMA0_DMAEN(0);                      //DMA使能控制（0:不是能；1:使能）
    put_DMA0_DMADT(DMA._DMADT);             //DMA传输模式，共有6种模式
    put_DMA0TSEL(DMA._DMAxTSEL);            //DMA触发信号模式，共有32中，即0-31，分别对应于DMA0TRIG0-31
    put_DMA0_DMASRCINCR(DMA._DMASRCINCR);   //DMA数据源地址模式，等于0,源地址不变化
    put_DMA0_DMADSTINCR(DMA._DMADSTINCR);   //DMA数据目标地址模式，等于0,目标地址不变化
    put_DMA0_DMASRCBYTE(DMA._DMASRCBYTE);   //等于0源数据为字节
    put_DMA0_DMADSTBYTE(DMA._DMADSTBYTE);   //等于0目标数据为字节
    put_DMA0_DMALEVEL(DMA._DMALEVEL);       //等于0触发信号上升沿有效
    put_DMA0_DMAABORT(DMA._DMAABORT);       //等于0时DMA传输期间不中断，等于1时响应非屏蔽中断
    put_DMA0SZ(DMA._DMASZ);                 //传输1个字节
    put_DMA0SA(DMA._DMASA);                 //数据源地址
    put_DMA0DA(DMA._DMADA);                 //数据目的地址
    put_DMA0_DMAIE(DMA._DMAIE);             //DMA中断控制，等于0，该DMA不响应中断
    put_ROUNDROBIN(DMA._ROUNDROBIN);        //通道极性选择。
    put_DMARMWDIS(DMA._DMARMWDIS);          //读-修改-写
    put_DMA0_DMAEN(1);                      //DMA使能控制（0:不是能；1:使能）
}
void init_DMA1(DMA_PARAMETER DMA)
{
    put_DMA1_DMAEN(0);                      //DMA使能控制（0:不是能；1:使能）
    put_DMA1_DMADT(DMA._DMADT);             //DMA传输模式，共有6种模式
    put_DMA1TSEL(DMA._DMAxTSEL);            //DMA触发信号模式，共有32中，即0-31，分别对应于DMA0TRIG0-31
    put_DMA1_DMASRCINCR(DMA._DMASRCINCR);   //DMA数据源地址模式，等于0,源地址不变化
    put_DMA1_DMADSTINCR(DMA._DMADSTINCR);   //DMA数据目标地址模式，等于0,目标地址不变化
    put_DMA1_DMASRCBYTE(DMA._DMASRCBYTE);   //等于0源数据为字节
    put_DMA1_DMADSTBYTE(DMA._DMADSTBYTE);   //等于0目标数据为字节
    put_DMA1_DMALEVEL(DMA._DMALEVEL);       //等于0触发信号上升沿有效
    put_DMA1_DMAABORT(DMA._DMAABORT);       //等于0时DMA传输期间不中断，等于1时响应非屏蔽中断
    put_DMA1SZ(DMA._DMASZ);                 //传输1个字节
    put_DMA1SA(DMA._DMASA);                 //数据源地址
    put_DMA1DA(DMA._DMADA);                 //数据目的地址
    put_DMA1_DMAIE(DMA._DMAIE);             //DMA中断控制，等于0，该DMA不响应中断
    put_ROUNDROBIN(DMA._ROUNDROBIN);        //通道极性选择。
    put_DMARMWDIS(DMA._DMARMWDIS);          //读-修改-写
    put_DMA1_DMAEN(1);                      //DMA使能控制（0:不是能；1:使能）
}
void init_DMA2(DMA_PARAMETER DMA)
{
    put_DMA2_DMAEN(0);                      //DMA使能控制（0:不是能；1:使能）
    put_DMA2_DMADT(DMA._DMADT);             //DMA传输模式，共有6种模式
    put_DMA2TSEL(DMA._DMAxTSEL);            //DMA触发信号模式，共有32中，即0-31，分别对应于DMA0TRIG0-31
    put_DMA2_DMASRCINCR(DMA._DMASRCINCR);   //DMA数据源地址模式，等于0,源地址不变化
    put_DMA2_DMADSTINCR(DMA._DMADSTINCR);   //DMA数据目标地址模式，等于0,目标地址不变化
    put_DMA2_DMASRCBYTE(DMA._DMASRCBYTE);   //等于0源数据为字节
    put_DMA2_DMADSTBYTE(DMA._DMADSTBYTE);   //等于0目标数据为字节
    put_DMA2_DMALEVEL(DMA._DMALEVEL);       //等于0触发信号上升沿有效
    put_DMA2_DMAABORT(DMA._DMAABORT);       //等于0时DMA传输期间不中断，等于1时响应非屏蔽中断
    put_DMA2SZ(DMA._DMASZ);                 //传输1个字节
    put_DMA2SA(DMA._DMASA);                 //数据源地址
    put_DMA2DA(DMA._DMADA);                 //数据目的地址
    put_DMA2_DMAIE(DMA._DMAIE);             //DMA中断控制，等于0，该DMA不响应中断
    put_ROUNDROBIN(DMA._ROUNDROBIN);        //通道极性选择。
    put_DMARMWDIS(DMA._DMARMWDIS);          //读-修改-写
    put_DMA2_DMAEN(1);                      //DMA使能控制（0:不是能；1:使能）
}
void init_TA0(TIMER_PARAMETER TIMER)
{
    put_TA0_TACLR(1);                       //复位定时器
    put_TA0_TASSEL(TIMER._TASSEL);          //选择计数时钟信号
    put_TA0_ID(TIMER._ID);                  //ID取值可分别0、1、2、3，分别对应分频为1、2、4、8
    put_TA0_IDEX(TIMER._IDEX);              //IDEX取值可分别0/1/2/3/4/5/6/7分别对应分频为1/2/3/4/5/6/7/8
    put_TA0CCR0(TIMER._CCR0);               //时间常数0
    put_TA0CCR1(TIMER._CCR1);               //时间常数1
    put_TA0CCR2(TIMER._CCR2);               //时间常数2
    put_TA0CCR3(TIMER._CCR3);               //时间常数3
    put_TA0CCR4(TIMER._CCR4);               //时间常数4
    put_TA0_MC(TIMER._MC);                  //加法计数还是减法 
    put_TA0_TACLR(0);                       //使得正常计数
}

void init_TA1(TIMER_PARAMETER TIMER)
{
    put_TA1_TACLR(1);                       //复位定时器
    put_TA1_TASSEL(TIMER._TASSEL);          //选择时钟信号
    put_TA1_ID(TIMER._ID);                  //ID取值可分别0、1、2、3，分别对应分频为1、2、4、8
    put_TA1_IDEX(TIMER._IDEX);              //IDEX取值可分别0/1/2/3/4/5/6/7分别对应分频为1/2/3/4/5/6/7/8
    put_TA1CCR0(TIMER._CCR0);               //时间常数0
    put_TA1CCR1(TIMER._CCR1);               //时间常数1
    put_TA1CCR2(TIMER._CCR2);               //时间常数2
    put_TA1_MC(TIMER._MC);                  //加法计数还是减法计数 
    put_TA1_TACLR(0);                       //使得正常计数
}
void init_TB0(TIMER_PARAMETER TIMER)
{
    put_TB0_TBCLR(1);                       //复位定时器
    put_TB0_TBSSEL(TIMER._TASSEL);          //选择时钟信号
    put_TB0_CNTL(TIMER._CNTL);              //选择定时器B主计数器位数
    put_TB0_ID(TIMER._ID);                  //ID取值可分别0、1、2、3，分别对应分频为1、2、4、8
    put_TB0_IDEX(TIMER._IDEX);              //IDEX取值可分别0/1/2/3/4/5/6/7分别对应分频为1/2/3/4/5/6/7/8
    put_TB0CCR0(TIMER._CCR0);               //时间常数0
    put_TB0CCR1(TIMER._CCR1);               //时间常数1
    put_TB0CCR2(TIMER._CCR2);               //时间常数2
    put_TB0CCR3(TIMER._CCR3);               //时间常数3
    put_TB0CCR4(TIMER._CCR4);               //时间常数4
    put_TB0CCR5(TIMER._CCR5);               //时间常数5
    put_TB0CCR6(TIMER._CCR6);               //时间常数6
    put_TB0_MC(TIMER._MC);                  //加法计数还是减法计数 
    put_TB0_TBCLR(0);                       //使得正常计数
}
