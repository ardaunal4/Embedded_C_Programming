/*
 * main.c
 *
 *  Created on: Apr 30, 2021
 *      Author: ardau
 */


#include <stdio.h>
#include <stdint.h>

void wait_for_user(void);

union Packet
{
	uint32_t packetValue;

	struct
	{
		uint32_t crc        :2; // LSB
		uint32_t status     :1;
		uint32_t payload    :12;
		uint32_t bat        :3;
		uint32_t sensor     :3;
		uint32_t longAddr   :8;
		uint32_t shortAddr  :2;
		uint32_t addrMode   :1; // MSB
	}packetFields;
};

int main(void)
{
	union Packet packet;

	printf("Enter a 32bit packet information: ");
	scanf("%X", &packet.packetValue);

	printf("crc         :%#X\n", packet.packetFields.crc);
	printf("status      :%#X\n", packet.packetFields.status);
	printf("payload     :%#X\n", packet.packetFields.payload);
	printf("sensor      :%#X\n", packet.packetFields.sensor);
	printf("longAddr    :%#X\n", packet.packetFields.longAddr);
	printf("shortAddr   :%#X\n", packet.packetFields.shortAddr);
	printf("addrMode    :%#X\n", packet.packetFields.addrMode);

	printf("Size of union packet : %u\n", sizeof(packet));

	wait_for_user();
}


void wait_for_user(void)
{
	printf("Press enter to exit program.\n");
	while(getchar() != '\n');
	getchar();
}
