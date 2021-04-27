/*
 * main.c
 *
 *  Created on: Apr 26, 2021
 *      Author: ardau
 */

#include <stdio.h>
#include <stdint.h>

void wait_for_user_input(void);

int main(void)
{
	int32_t user_input1, user_input2;

	printf("Enter 2 number to compare them into bitwise : ");
	scanf("%d %d", &user_input1, &user_input2);

	printf("\n& operator comparison is : %d\n", user_input1 & user_input2);
	printf("| operator comparison is : %d\n", user_input1 | user_input2);
	printf("^ operator comparison is : %d\n", user_input1 ^ user_input2);

	// Usage areas of bitwise operators
	printf("Enter a number to see usage area of bitwise operators : ");
	int32_t user_input3, output;
	scanf("%d", &user_input3);

	// Check whether the number is odd or even ( To test use & )
	if (user_input3 & 1)
		printf("User input 1 is odd.\n");
	else
		printf("User input 1 is even.\n");

	// 7th and 4th bits of the input replace with 1 ( To set use | )
	output = user_input3 | 0x90; // mask value is 0x90
	printf("[input] [output] : 0x%x 0x%x\n", user_input3, output);


	// clean some of the bits from number
	output = ~0x70 & user_input3;
	printf("[input] [output] : 0x%x 0x%x\n", user_input3, output);

	wait_for_user_input();
}

void wait_for_user_input(void)
{
	printf("Exit to program press enter.\n");
	while (getchar() != '\n');
	getchar();
}
