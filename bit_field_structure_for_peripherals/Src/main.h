/*
 * main.h
 *
 *  Created on: May 3, 2021
 *      Author: ardau
 */

#ifndef MAIN_H_
#define MAIN_H_

typedef struct
{
	uint32_t GPIOA           :1;
	uint32_t GPIOB           :1;
	uint32_t GPIOC           :1;
	uint32_t GPIOD           :1;
	uint32_t GPIOE           :1;
	uint32_t GPIOF           :1;
	uint32_t GPIOG           :1;
	uint32_t GPIOH           :1;
	uint32_t GPIOI           :1;
	uint32_t GPIOJ           :1;
	uint32_t GPIOK           :1;
	uint32_t reserved1       :1;
	uint32_t CRCEN           :1;
	uint32_t reserver2       :3;
	uint32_t reserved3       :2;
	uint32_t SRAM            :1;
	uint32_t reserved4       :1;
	uint32_t CCMRAM          :1;
	uint32_t DMA1            :1;
	uint32_t DMA2            :1;
	uint32_t DMA2D           :1;
	uint32_t reserved5       :1;
	uint32_t ETH_MAC         :1;
	uint32_t ETH_TRANS       :1;
	uint32_t ETH_RES         :1;
	uint32_t ETH_PTP         :1;
	uint32_t USB_OTG_HS      :1;
	uint32_t USB_OTG_HSULP   :1;
	uint32_t reserved6       :1;

}RCC_AHB1ENR_t;

typedef struct
{
	uint32_t pin_0           :1;
	uint32_t pin_1           :1;
	uint32_t pin_2           :1;
	uint32_t pin_3           :1;
	uint32_t pin_4           :1;
	uint32_t pin_5           :1;
	uint32_t pin_6           :1;
	uint32_t pin_7           :1;
	uint32_t pin_8           :1;
	uint32_t pin_9           :1;
	uint32_t pin_10          :1;
	uint32_t pin_11          :1;
	uint32_t pin_12          :1;
	uint32_t pin_13          :1;
	uint32_t pin_14          :1;
	uint32_t pin_15          :1;
	uint32_t reserved       :16;

}GPIOx_ODR_t;

typedef struct
{
	uint32_t pin_0         :2;
	uint32_t pin_1         :2;
	uint32_t pin_2         :2;
	uint32_t pin_3         :2;
	uint32_t pin_4         :2;
	uint32_t pin_5         :2;
	uint32_t pin_6         :2;
	uint32_t pin_7         :2;
	uint32_t pin_8         :2;
	uint32_t pin_9         :2;
	uint32_t pin_10        :2;
	uint32_t pin_11        :2;
	uint32_t pin_12        :2;
	uint32_t pin_13        :2;
	uint32_t pin_14        :2;
	uint32_t pin_15        :2;

}GPIOx_MODE_t;


#endif /* MAIN_H_ */
