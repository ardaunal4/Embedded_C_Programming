/*
 * main.c
 *
 *  Created on: Apr 30, 2021
 *      Author: ardau
 */


#include <stdio.h>
#include <stdint.h>

void wait_for_user(void);

struct DataSet
{
	char data1;
	int32_t data2;
	char data3;
	short data4;
};

void displayElementsOfStructure(struct DataSet *pData);

int main(void)
{
	struct DataSet data;

	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	printf("data1 before = %X\n", data.data1);

	struct DataSet *pData;
	pData = &data;

	pData->data1 = 0x55; // (*pData).data1 is the same as pData->data1. '->' operator is called dereferencing operator

	printf("data1 After = %X\n", data.data1);

	displayElementsOfStructure(pData);

	wait_for_user();
}

void displayElementsOfStructure(struct DataSet *pData)
{
	printf("Data1 = %X\n", pData->data1);
	printf("Data2 = %X\n", pData->data2);
	printf("Data3 = %X\n", pData->data3);
	printf("Data4 = %X\n", pData->data4);
}

void wait_for_user(void)
{
	printf("Press enter to exit program.\n");
	while(getchar() != '\n');
	getchar();
}
