/*
 * main.c
 *
 *  Created on: Apr 23, 2021
 *      Author: ardau
 */


#include <stdio.h>
#include <stdint.h>

void wait_user_input(void);

int main(void){

	float num1, num2;
	printf("Enter first number : ");

	if(scanf("%f", &num1) == 0){
		printf("Invalid input! Exiting ...");
		wait_user_input();
	}


	printf("\nEnter second number : ");
	if(scanf("%f", &num2) == 0){
			printf("Invalid input! Exiting ...");
			wait_user_input();
		}

	if (num1 == num2){
		printf("They are equal each other.\n");
	}
	else{

		if (num1 > num2)
			printf("%f is bigger\n", num1);
		else
			printf("%f is bigger\n", num2);

	}

	wait_user_input();
}

void wait_user_input(void){

	printf("Press enter to exit program.");
	while(getchar() != '\n');
	getchar();

}
