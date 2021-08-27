/**
 ******************************************************************************
 * @file           : main.c
 * @author         : aunal
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


int main(void)
{

	// It is recommended that use volatile variable type when you access the memory-map registers
    uint32_t volatile *const pClkCtrlReg =   (uint32_t*) 0x40023830;

    uint32_t volatile *const pPortDModeReg = (uint32_t*) 0x40020C00;
    uint32_t volatile *const pPortAModeReg = (uint32_t*) 0x40020000;

    uint32_t volatile *const pPortDOutReg =  (uint32_t*) 0x40020C14;
    uint32_t const volatile *const pPortAInReg =   (uint32_t*) 0x40020010; // no optimization variable may vary.

    // Enable the clock for GPOID and GPIOA peripherals in the AHB1ENR
    *pClkCtrlReg |= (1 << 3); // modify
    *pClkCtrlReg |= (1 << 0); // modify


    // Configuring PD12 as Output
    *pPortDModeReg &= ~(3 << 24);
    *pPortDModeReg |= (1 << 24);

    // Configure PA0 as input
    *pPortAModeReg &= ~(3 << 0); // clear register status

    while(1){

		// Read the pin status of the pin PA0 (GPIOA input data register)
		uint8_t pinStatus = (uint8_t)(*pPortAInReg & 0x1); // Zero out all the pins except bit 0

		if(pinStatus)
			*pPortDOutReg |= (1 << 12);
		else
			*pPortDOutReg &= ~(1 << 12);
    }

}
