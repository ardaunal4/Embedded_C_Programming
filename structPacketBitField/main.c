/*
 * main.c
 *
 *  Created on: Apr 30, 2021
 *      Author: ardau
 */


#include <stdio.h>
#include <stdint.h>

void wait_for_user(void);

struct Packet
{
	uint32_t crc        :2;
	uint32_t status     :1;
	uint32_t payload    :12;
	uint32_t bat        :3;
	uint32_t sensor     :3;
	uint32_t longAddr   :8;
	uint32_t shortAddr  :2;
	uint32_t addrMode   :1;
};


int main(void)
{

	uint32_t packetValue;
	printf("Enter a 32bit packet information: ");
	scanf("%X", &packetValue);

	struct Packet packet;
	packet.crc         = (uint8_t)(packetValue & 0x3);
	packet.status      = (uint8_t)((packetValue >> 2) & 0x1);
	packet.payload     = (uint16_t)((packetValue >> 3) & 0xFFF);
	packet.bat         = (uint8_t)((packetValue >> 15) & 0x7);
	packet.sensor      = (uint8_t)((packetValue >> 18) & 0x7);
	packet.longAddr    = (uint8_t)((packetValue >> 21) & 0xFF);
	packet.shortAddr   = (uint8_t)((packetValue >> 29) & 0x2);
	packet.addrMode    = (uint8_t)((packetValue >> 31) & 0x1);

	printf("crc         :%#X\n", packet.crc);
	printf("status      :%#X\n", packet.status);
	printf("payload     :%#X\n", packet.payload);
	printf("sensor      :%#X\n", packet.sensor);
	printf("longAddr    :%#X\n", packet.longAddr);
	printf("shortAddr   :%#X\n", packet.shortAddr);
	printf("addrMode    :%#X\n", packet.addrMode);


	printf("Size of packet : %u\n", sizeof(packet));

	wait_for_user();
}


void wait_for_user(void)
{
	printf("Press enter to exit program.\n");
	while(getchar() != '\n');
	getchar();
}
