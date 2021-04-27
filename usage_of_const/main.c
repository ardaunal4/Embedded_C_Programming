/*
 * main.c
 *
 *  Created on: Apr 27, 2021
 *      Author: ardau
 */

void copy_src_to_dst(uint8_t const *src, uint8_t *dst, uint32_t len)
{
	// This function copies data from src pointer to dst pointer
	for (uint32_t count = 0; count < len; count++)
	{
		*dst++ = *src++;
	}

}

int main(void){

	// CASE 1: constant data
	// To define mathematical constants in the program
	uint8_t const number_of_months = 12;
	float const PI = 3.1415926;

	// CASE 2: Modifiable Pointer and Constant Data
	uint8_t const *pData = (uint8_t*) 0x40000000;
	// Here pointer pData is modifiabl, but the data pointed by the pData can not be modifiable(read-only)
	copy_src_to_dst();


}
