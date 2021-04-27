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
    uint32_t *pClkCtrlReg = (uint32_t*) 0x40023830;
    uint32_t *pPortDModeReg = (uint32_t*) 0x40020C00;
    uint32_t *pPortDOutReg = (uint32_t*) 0x40020C14;

    // 1. Enable the clock for GPOID peripheral in the AHB1ENR

    uint32_t temp = *pClkCtrlReg; // read operation
    temp = temp | 0x08; // modify
    *pClkCtrlReg = temp; // write back
    // In a short way: *pClkCtrlReg |= 0x08;

    // 2. Configure the mode of the I/O pin as output
    // a. clear the 24th and 25th bit positions(CLEAR)
    *pPortDModeReg &= 0xFCFFFFFF;
    // b. make the 24th port position as 1 (SET)
    *pPortDModeReg |= 0x01000000;

    // 3. SET 12th bit of the output data register to make I/O pin-12 as HIGH
    *pPortDOutReg |= 0x1000;

	while(1);
}
