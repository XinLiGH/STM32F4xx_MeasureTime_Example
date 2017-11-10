# STM32F4xx_MeasureTime_Example

使用STM32F4的内核定时器SysTick，来实现精确测量程序运行的时间。适用于STM32F4全部芯片。

## 开发环境

* 固件库：STM32F4xx_DSP_StdPeriph_Lib_V1.8.0
* 编译器：ARMCC V5.06
* IDE：Keil uVision5
* 操作系统：Windows 10 专业版

## API

* void MeasureTimeStart(void)
* double MeasureTimeStop(uint32_t clock)

## 注意

STM32F4的内核定时器SysTick是一个24位的定时器，需要注意最大的测量时间。
