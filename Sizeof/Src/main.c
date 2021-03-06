/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include <stdio.h>

int main(void)
{
	int *pointer = NULL;
	int a = 6;

	pointer = &a;

	printf("Size of INT = %d\n", sizeof(int));
	printf("Size of CHAR = %d\n", sizeof(char));
	printf("Size of Float = %d\n", sizeof(float));
	printf("Size of long long INT = %d\n", sizeof(long long int));
	printf("Size of short INT = %d\n", sizeof(short));
	printf("Size of DOUBLE = %d\n", sizeof(double));
	printf("Size of LONG INT = %d\n", sizeof(long));
	printf("Size of pointer = %d\n", sizeof(pointer));
	for(;;);
}
