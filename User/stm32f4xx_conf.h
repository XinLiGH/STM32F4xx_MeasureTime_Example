/**
  ******************************************************************************
  * @file    stm32f4xx_conf.h
  * @author  XinLi
  * @version v1.0
  * @date    24-October-2017
  * @brief   Library configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>Copyright &copy; 2017 XinLi</center></h2>
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.
  *
  ******************************************************************************
  */

#ifndef __STM32F4xx_CONF_H
#define __STM32F4xx_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Header includes -----------------------------------------------------------*/
/* Uncomment the line below to enable peripheral header file inclusion */
#include "stm32f4xx_adc.h"
#include "stm32f4xx_crc.h"
#include "stm32f4xx_dbgmcu.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_flash.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_iwdg.h"
#include "stm32f4xx_pwr.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_rtc.h"
#include "stm32f4xx_sdio.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_wwdg.h"
#include "misc.h" /* High level functions for NVIC and SysTick (add-on to CMSIS functions) */

#if defined(STM32F429_439xx) || defined(STM32F446xx) || defined(STM32F469_479xx)
#include "stm32f4xx_cryp.h"
#include "stm32f4xx_hash.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_dcmi.h"
#include "stm32f4xx_dma2d.h"
#include "stm32f4xx_fmc.h"
#include "stm32f4xx_ltdc.h"
#include "stm32f4xx_sai.h"
#endif /* STM32F429_439xx || STM32F446xx || STM32F469_479xx */

#if defined(STM32F427_437xx)
#include "stm32f4xx_cryp.h"
#include "stm32f4xx_hash.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_dcmi.h"
#include "stm32f4xx_dma2d.h"
#include "stm32f4xx_fmc.h"
#include "stm32f4xx_sai.h"
#endif /* STM32F427_437xx */

#if defined(STM32F40_41xxx)
#include "stm32f4xx_cryp.h"
#include "stm32f4xx_hash.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_dcmi.h"
#include "stm32f4xx_fsmc.h"
#endif /* STM32F40_41xxx */

#if defined(STM32F410xx)
#include "stm32f4xx_rng.h"
#include "stm32f4xx_dac.h"
#endif /* STM32F410xx */

#if defined(STM32F411xE)
#include "stm32f4xx_flash_ramfunc.h"
#endif /* STM32F411xE */

#if defined(STM32F446xx) || defined(STM32F469_479xx)
#include "stm32f4xx_qspi.h"
#endif /* STM32F446xx || STM32F469_479xx */

#if defined(STM32F410xx) || defined(STM32F446xx)
#include "stm32f4xx_fmpi2c.h"
#endif /* STM32F410xx || STM32F446xx */

#if defined(STM32F446xx)
#include "stm32f4xx_spdifrx.h"
#include "stm32f4xx_cec.h"
#endif /* STM32F446xx */

#if defined(STM32F469_479xx)
#include "stm32f4xx_dsi.h"
#endif /* STM32F469_479xx */

#if defined(STM32F410xx)
#include "stm32f4xx_lptim.h"
#endif /* STM32F410xx */

#if defined(STM32F412xG)
#include "stm32f4xx_rng.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_qspi.h"
#include "stm32f4xx_fsmc.h"
#include "stm32f4xx_dfsdm.h"
#endif /* STM32F412xG */

#if defined(STM32F413_423xx)
#include "stm32f4xx_cryp.h"
#include "stm32f4xx_fmpi2c.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_qspi.h"
#include "stm32f4xx_fsmc.h"
#include "stm32f4xx_dfsdm.h"
#endif /* STM32F413_423xx */

/* Macro definitions ---------------------------------------------------------*/
/* If an external clock source is used, then the value of the following define 
   should be set to the value of the external clock source, else, if no external 
   clock is used, keep this define commented */
//#define I2S_EXTERNAL_CLOCK_VAL  12288000 /* Value of the external clock in Hz */

/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
//#define USE_FULL_ASSERT         1

/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
#ifdef USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *               which reports the name of the source file and the source
  *               line number of the call that failed.
  *               If expr is true, it returns no value.
  * @return None.
  */
#define assert_param(expr)  ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr)  ((void)0)
#endif /* USE_FULL_ASSERT */

/* Function definitions ------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_CONF_H */
