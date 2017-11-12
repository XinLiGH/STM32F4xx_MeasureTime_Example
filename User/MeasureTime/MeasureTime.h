/**
  ******************************************************************************
  * @file    MeasureTime.h
  * @author  XinLi
  * @version v1.0
  * @date    24-October-2017
  * @brief   Measure program run time module.
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

#ifndef __MEASURETIME_H
#define __MEASURETIME_H

#ifdef __cplusplus
extern "C" {
#endif

/* Header includes -----------------------------------------------------------*/
#include "stm32f4xx.h"

/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/

/**
  * @brief  Start measure time.
  * @param  None.
  * @return None.
  */
__STATIC_INLINE void MeasureTimeStart(void)
{
  SysTick->CTRL |= SysTick_CLKSource_HCLK;  /* Set the SysTick clock source. */
  SysTick->LOAD  = 0xFFFFFF;                /* Time load (SysTick-> LOAD is 24bit). */
  SysTick->VAL   = 0xFFFFFF;                /* Empty the counter value. */
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; /* Start the countdown. */
  __nop();                                  /* Waiting for a machine cycle. */
}

/**
  * @brief  Stop measure time.
  * @param  [in] clock: System clock frequency(unit: MHz).
  * @return Program run time(unit: us).
  */
__STATIC_INLINE double MeasureTimeStop(uint32_t clock)
{
  uint32_t count = SysTick->VAL;             /* Read the counter value. */
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; /* Close counter. */
  
  double time = 0.0;
  
  if(clock > 0)
  {
    time = (double)(0xFFFFFF - count) / (double)clock; /* Calculate program run time. */
  }
  
  return time;
}

#ifdef __cplusplus
}
#endif

#endif /* __MEASURETIME_H */
