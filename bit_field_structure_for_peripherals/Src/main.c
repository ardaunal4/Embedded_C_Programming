/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ardau
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"



int main(void)
{
	RCC_AHB1ENR_t volatile *const pClkCtrl   = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODE_t volatile *const pGpiodMode  = (GPIOx_MODE_t *)0x40020C00;
	GPIOx_ODR_t volatile *const pGpiodOut    = (GPIOx_ODR_t*)0x40020C14;

	pClkCtrl->GPIOD = 1;
	pGpiodMode->pin_12 = 1;

	while(1)
	{
		pGpiodOut->pin_12 = 1;
		for(uint32_t i = 0; i < 300000; i++);
		pGpiodOut->pin_12 = 0;
		for(uint32_t i = 0; i < 300000; i++);
	}
}
