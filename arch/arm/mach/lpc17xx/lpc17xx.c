/**
 *	LPC17xx Platform Machine Description.
 *
 *	@author		Robert Steinbauer
 *
 *	@copyright	(c)2013 Riegl Laser Measurement Systems GmBH
 *	@copyright	(c)2013 Robert Steinbauer <rsteinbauer@riegl.com>
 *
 **/


#include <bitthunder.h>

#include "rcc.h"
#include "ioconfig.h"

static const BT_RESOURCE oLPC17xx_gpio_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_GPIO_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_GPIO_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= BT_CONFIG_MACH_LPC17xx_TOTAL_GPIOS-1,
		.ulFlags			= BT_RESOURCE_IO,
	},
	{
		.ulStart			= 28,
		.ulEnd				= 31,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};


/**
 *	By using the BT_INTEGRATED_DEVICE_DEF macro, we ensure that this structure is
 *	placed into the device manager's integrated device table.
 *
 *	This allows it to be automatically enumerated without "registering" a driver.
 **/
BT_INTEGRATED_DEVICE_DEF oLPC17xx_gpio_device = {
	.name 					= "LPC17xx,gpio",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_gpio_resources),
	.pResources 			= oLPC17xx_gpio_resources,
};


static const BT_RESOURCE oLPC17xx_nvic_resources[] = {
	{
		.ulStart			= BT_CONFIG_ARCH_ARM_NVIC_BASE,
		.ulEnd				= BT_CONFIG_ARCH_ARM_NVIC_BASE + BT_SIZE_4K,
		.ulFlags			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= BT_CONFIG_ARCH_ARM_NVIC_TOTAL_IRQS - 1,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC17xx_nvic_device = {
	.name					= "arm,common,nvic",
	.ulTotalResources	   	= BT_ARRAY_SIZE(oLPC17xx_nvic_resources),
	.pResources				= oLPC17xx_nvic_resources,
};

static const BT_RESOURCE oLPC17xx_systick_resources[] = {
	{
		.ulStart 			= 0xE000E010,
		.ulEnd				= 0xE000E01F,
		.ulFlags			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 16,
		.ulEnd				= 16,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC17xx_systick_device = {
	.name					= "arm,cortex-mx,systick",
	.ulTotalResources		= BT_ARRAY_SIZE(oLPC17xx_systick_resources),
	.pResources				= oLPC17xx_systick_resources,
};


static void lpc17xx_gpio_init(void) {
	#ifdef BT_CONFIG_LPC17xx_PIO0_0_FUNCTION
		BT_LPC17xx_SetIOConfig(0, BT_CONFIG_LPC17xx_PIO0_0_FUNCTION, BT_CONFIG_LPC17xx_PIO0_0_MODE, BT_CONFIG_LPC17xx_PIO0_0_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_1_FUNCTION
		BT_LPC17xx_SetIOConfig(1, BT_CONFIG_LPC17xx_PIO0_1_FUNCTION, BT_CONFIG_LPC17xx_PIO0_1_MODE, BT_CONFIG_LPC17xx_PIO0_1_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_2_FUNCTION
		BT_LPC17xx_SetIOConfig(2, BT_CONFIG_LPC17xx_PIO0_2_FUNCTION, BT_CONFIG_LPC17xx_PIO0_2_MODE, BT_CONFIG_LPC17xx_PIO0_2_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_3_FUNCTION
		BT_LPC17xx_SetIOConfig(3, BT_CONFIG_LPC17xx_PIO0_3_FUNCTION, BT_CONFIG_LPC17xx_PIO0_3_MODE, BT_CONFIG_LPC17xx_PIO0_3_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_4_FUNCTION
		BT_LPC17xx_SetIOConfig(4, BT_CONFIG_LPC17xx_PIO0_4_FUNCTION, BT_CONFIG_LPC17xx_PIO0_4_MODE, BT_CONFIG_LPC17xx_PIO0_4_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_5_FUNCTION
		BT_LPC17xx_SetIOConfig(5, BT_CONFIG_LPC17xx_PIO0_5_FUNCTION, BT_CONFIG_LPC17xx_PIO0_5_MODE, BT_CONFIG_LPC17xx_PIO0_5_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_6_FUNCTION
		BT_LPC17xx_SetIOConfig(6, BT_CONFIG_LPC17xx_PIO0_6_FUNCTION, BT_CONFIG_LPC17xx_PIO0_6_MODE, BT_CONFIG_LPC17xx_PIO0_6_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_7_FUNCTION
		BT_LPC17xx_SetIOConfig(7, BT_CONFIG_LPC17xx_PIO0_7_FUNCTION, BT_CONFIG_LPC17xx_PIO0_7_MODE, BT_CONFIG_LPC17xx_PIO0_7_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_8_FUNCTION
		BT_LPC17xx_SetIOConfig(8, BT_CONFIG_LPC17xx_PIO0_8_FUNCTION, BT_CONFIG_LPC17xx_PIO0_8_MODE, BT_CONFIG_LPC17xx_PIO0_8_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_9_FUNCTION
		BT_LPC17xx_SetIOConfig(9, BT_CONFIG_LPC17xx_PIO0_9_FUNCTION, BT_CONFIG_LPC17xx_PIO0_9_MODE, BT_CONFIG_LPC17xx_PIO0_9_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_10_FUNCTION
		BT_LPC17xx_SetIOConfig(10, BT_CONFIG_LPC17xx_PIO0_10_FUNCTION, BT_CONFIG_LPC17xx_PIO0_10_MODE, BT_CONFIG_LPC17xx_PIO0_10_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_11_FUNCTION
		BT_LPC17xx_SetIOConfig(11, BT_CONFIG_LPC17xx_PIO0_11_FUNCTION, BT_CONFIG_LPC17xx_PIO0_11_MODE, BT_CONFIG_LPC17xx_PIO0_11_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_15_FUNCTION
		BT_LPC17xx_SetIOConfig(15, BT_CONFIG_LPC17xx_PIO0_15_FUNCTION, BT_CONFIG_LPC17xx_PIO0_15_MODE, BT_CONFIG_LPC17xx_PIO0_15_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_16_FUNCTION
		BT_LPC17xx_SetIOConfig(16, BT_CONFIG_LPC17xx_PIO0_16_FUNCTION, BT_CONFIG_LPC17xx_PIO0_16_MODE, BT_CONFIG_LPC17xx_PIO0_16_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_17_FUNCTION
		BT_LPC17xx_SetIOConfig(17, BT_CONFIG_LPC17xx_PIO0_17_FUNCTION, BT_CONFIG_LPC17xx_PIO0_17_MODE, BT_CONFIG_LPC17xx_PIO0_17_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_18_FUNCTION
		BT_LPC17xx_SetIOConfig(18, BT_CONFIG_LPC17xx_PIO0_18_FUNCTION, BT_CONFIG_LPC17xx_PIO0_18_MODE, BT_CONFIG_LPC17xx_PIO0_18_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_19_FUNCTION
		BT_LPC17xx_SetIOConfig(19, BT_CONFIG_LPC17xx_PIO0_19_FUNCTION, BT_CONFIG_LPC17xx_PIO0_19_MODE, BT_CONFIG_LPC17xx_PIO0_19_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_20_FUNCTION
		BT_LPC17xx_SetIOConfig(20, BT_CONFIG_LPC17xx_PIO0_20_FUNCTION, BT_CONFIG_LPC17xx_PIO0_20_MODE, BT_CONFIG_LPC17xx_PIO0_20_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_21_FUNCTION
		BT_LPC17xx_SetIOConfig(21, BT_CONFIG_LPC17xx_PIO0_21_FUNCTION, BT_CONFIG_LPC17xx_PIO0_21_MODE, BT_CONFIG_LPC17xx_PIO0_21_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_22_FUNCTION
		BT_LPC17xx_SetIOConfig(22, BT_CONFIG_LPC17xx_PIO0_22_FUNCTION, BT_CONFIG_LPC17xx_PIO0_22_MODE, BT_CONFIG_LPC17xx_PIO0_22_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_23_FUNCTION
		BT_LPC17xx_SetIOConfig(23, BT_CONFIG_LPC17xx_PIO0_23_FUNCTION, BT_CONFIG_LPC17xx_PIO0_23_MODE, BT_CONFIG_LPC17xx_PIO0_23_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_24_FUNCTION
		BT_LPC17xx_SetIOConfig(24, BT_CONFIG_LPC17xx_PIO0_24_FUNCTION, BT_CONFIG_LPC17xx_PIO0_24_MODE, BT_CONFIG_LPC17xx_PIO0_24_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_25_FUNCTION
		BT_LPC17xx_SetIOConfig(25, BT_CONFIG_LPC17xx_PIO0_25_FUNCTION, BT_CONFIG_LPC17xx_PIO0_25_MODE, BT_CONFIG_LPC17xx_PIO0_25_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_26_FUNCTION
		BT_LPC17xx_SetIOConfig(26, BT_CONFIG_LPC17xx_PIO0_26_FUNCTION, BT_CONFIG_LPC17xx_PIO0_26_MODE, BT_CONFIG_LPC17xx_PIO0_26_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_27_FUNCTION
		BT_LPC17xx_SetIOConfig(27, BT_CONFIG_LPC17xx_PIO0_27_FUNCTION, BT_CONFIG_LPC17xx_PIO0_27_MODE, BT_CONFIG_LPC17xx_PIO0_27_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_28_FUNCTION
		BT_LPC17xx_SetIOConfig(28, BT_CONFIG_LPC17xx_PIO0_28_FUNCTION, BT_CONFIG_LPC17xx_PIO0_28_MODE, BT_CONFIG_LPC17xx_PIO0_28_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_29_FUNCTION
		BT_LPC17xx_SetIOConfig(29, BT_CONFIG_LPC17xx_PIO0_29_FUNCTION, BT_CONFIG_LPC17xx_PIO0_29_MODE, BT_CONFIG_LPC17xx_PIO0_29_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO0_30_FUNCTION
		BT_LPC17xx_SetIOConfig(30, BT_CONFIG_LPC17xx_PIO0_30_FUNCTION, BT_CONFIG_LPC17xx_PIO0_30_MODE, BT_CONFIG_LPC17xx_PIO0_30_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_0_FUNCTION
		BT_LPC17xx_SetIOConfig(32, BT_CONFIG_LPC17xx_PIO1_0_FUNCTION, BT_CONFIG_LPC17xx_PIO1_0_MODE, BT_CONFIG_LPC17xx_PIO1_0_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_1_FUNCTION
		BT_LPC17xx_SetIOConfig(33, BT_CONFIG_LPC17xx_PIO1_1_FUNCTION, BT_CONFIG_LPC17xx_PIO1_1_MODE, BT_CONFIG_LPC17xx_PIO1_1_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_4_FUNCTION
		BT_LPC17xx_SetIOConfig(36, BT_CONFIG_LPC17xx_PIO1_4_FUNCTION, BT_CONFIG_LPC17xx_PIO1_4_MODE, BT_CONFIG_LPC17xx_PIO1_4_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_8_FUNCTION
		BT_LPC17xx_SetIOConfig(40, BT_CONFIG_LPC17xx_PIO1_8_FUNCTION, BT_CONFIG_LPC17xx_PIO1_8_MODE, BT_CONFIG_LPC17xx_PIO1_8_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_9_FUNCTION
		BT_LPC17xx_SetIOConfig(41, BT_CONFIG_LPC17xx_PIO1_9_FUNCTION, BT_CONFIG_LPC17xx_PIO1_9_MODE, BT_CONFIG_LPC17xx_PIO1_9_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_10_FUNCTION
		BT_LPC17xx_SetIOConfig(42, BT_CONFIG_LPC17xx_PIO1_10_FUNCTION, BT_CONFIG_LPC17xx_PIO1_10_MODE, BT_CONFIG_LPC17xx_PIO1_10_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_14_FUNCTION
		BT_LPC17xx_SetIOConfig(46, BT_CONFIG_LPC17xx_PIO1_14_FUNCTION, BT_CONFIG_LPC17xx_PIO1_14_MODE, BT_CONFIG_LPC17xx_PIO1_14_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_15_FUNCTION
		BT_LPC17xx_SetIOConfig(47, BT_CONFIG_LPC17xx_PIO1_15_FUNCTION, BT_CONFIG_LPC17xx_PIO1_15_MODE, BT_CONFIG_LPC17xx_PIO1_15_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_16_FUNCTION
		BT_LPC17xx_SetIOConfig(48, BT_CONFIG_LPC17xx_PIO1_16_FUNCTION, BT_CONFIG_LPC17xx_PIO1_16_MODE, BT_CONFIG_LPC17xx_PIO1_16_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_17_FUNCTION
		BT_LPC17xx_SetIOConfig(49, BT_CONFIG_LPC17xx_PIO1_17_FUNCTION, BT_CONFIG_LPC17xx_PIO1_17_MODE, BT_CONFIG_LPC17xx_PIO1_17_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_18_FUNCTION
		BT_LPC17xx_SetIOConfig(50, BT_CONFIG_LPC17xx_PIO1_18_FUNCTION, BT_CONFIG_LPC17xx_PIO1_18_MODE, BT_CONFIG_LPC17xx_PIO1_18_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_19_FUNCTION
		BT_LPC17xx_SetIOConfig(51, BT_CONFIG_LPC17xx_PIO1_19_FUNCTION, BT_CONFIG_LPC17xx_PIO1_19_MODE, BT_CONFIG_LPC17xx_PIO1_19_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_20_FUNCTION
		BT_LPC17xx_SetIOConfig(52, BT_CONFIG_LPC17xx_PIO1_20_FUNCTION, BT_CONFIG_LPC17xx_PIO1_20_MODE, BT_CONFIG_LPC17xx_PIO1_20_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_21_FUNCTION
		BT_LPC17xx_SetIOConfig(53, BT_CONFIG_LPC17xx_PIO1_21_FUNCTION, BT_CONFIG_LPC17xx_PIO1_21_MODE, BT_CONFIG_LPC17xx_PIO1_21_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_22_FUNCTION
		BT_LPC17xx_SetIOConfig(54, BT_CONFIG_LPC17xx_PIO1_22_FUNCTION, BT_CONFIG_LPC17xx_PIO1_22_MODE, BT_CONFIG_LPC17xx_PIO1_22_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_23_FUNCTION
		BT_LPC17xx_SetIOConfig(55, BT_CONFIG_LPC17xx_PIO1_23_FUNCTION, BT_CONFIG_LPC17xx_PIO1_23_MODE, BT_CONFIG_LPC17xx_PIO1_23_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_24_FUNCTION
		BT_LPC17xx_SetIOConfig(56, BT_CONFIG_LPC17xx_PIO1_24_FUNCTION, BT_CONFIG_LPC17xx_PIO1_24_MODE, BT_CONFIG_LPC17xx_PIO1_24_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_25_FUNCTION
		BT_LPC17xx_SetIOConfig(57, BT_CONFIG_LPC17xx_PIO1_25_FUNCTION, BT_CONFIG_LPC17xx_PIO1_25_MODE, BT_CONFIG_LPC17xx_PIO1_25_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_26_FUNCTION
		BT_LPC17xx_SetIOConfig(58, BT_CONFIG_LPC17xx_PIO1_26_FUNCTION, BT_CONFIG_LPC17xx_PIO1_26_MODE, BT_CONFIG_LPC17xx_PIO1_26_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_27_FUNCTION
		BT_LPC17xx_SetIOConfig(59, BT_CONFIG_LPC17xx_PIO1_27_FUNCTION, BT_CONFIG_LPC17xx_PIO1_27_MODE, BT_CONFIG_LPC17xx_PIO1_27_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_28_FUNCTION
		BT_LPC17xx_SetIOConfig(60, BT_CONFIG_LPC17xx_PIO1_28_FUNCTION, BT_CONFIG_LPC17xx_PIO1_28_MODE, BT_CONFIG_LPC17xx_PIO1_28_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_29_FUNCTION
		BT_LPC17xx_SetIOConfig(61, BT_CONFIG_LPC17xx_PIO1_29_FUNCTION, BT_CONFIG_LPC17xx_PIO1_29_MODE, BT_CONFIG_LPC17xx_PIO1_29_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_30_FUNCTION
		BT_LPC17xx_SetIOConfig(62, BT_CONFIG_LPC17xx_PIO1_30_FUNCTION, BT_CONFIG_LPC17xx_PIO1_30_MODE, BT_CONFIG_LPC17xx_PIO1_30_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO1_31_FUNCTION
		BT_LPC17xx_SetIOConfig(63, BT_CONFIG_LPC17xx_PIO1_31_FUNCTION, BT_CONFIG_LPC17xx_PIO1_31_MODE, BT_CONFIG_LPC17xx_PIO1_31_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_0_FUNCTION
		BT_LPC17xx_SetIOConfig(64, BT_CONFIG_LPC17xx_PIO2_0_FUNCTION, BT_CONFIG_LPC17xx_PIO2_0_MODE, BT_CONFIG_LPC17xx_PIO2_0_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_1_FUNCTION
		BT_LPC17xx_SetIOConfig(65, BT_CONFIG_LPC17xx_PIO2_1_FUNCTION, BT_CONFIG_LPC17xx_PIO2_1_MODE, BT_CONFIG_LPC17xx_PIO2_1_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_2_FUNCTION
		BT_LPC17xx_SetIOConfig(66, BT_CONFIG_LPC17xx_PIO2_2_FUNCTION, BT_CONFIG_LPC17xx_PIO2_2_MODE, BT_CONFIG_LPC17xx_PIO2_2_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_3_FUNCTION
		BT_LPC17xx_SetIOConfig(67, BT_CONFIG_LPC17xx_PIO2_3_FUNCTION, BT_CONFIG_LPC17xx_PIO2_3_MODE, BT_CONFIG_LPC17xx_PIO2_3_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_4_FUNCTION
		BT_LPC17xx_SetIOConfig(68, BT_CONFIG_LPC17xx_PIO2_4_FUNCTION, BT_CONFIG_LPC17xx_PIO2_4_MODE, BT_CONFIG_LPC17xx_PIO2_4_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_5_FUNCTION
		BT_LPC17xx_SetIOConfig(69, BT_CONFIG_LPC17xx_PIO2_5_FUNCTION, BT_CONFIG_LPC17xx_PIO2_5_MODE, BT_CONFIG_LPC17xx_PIO2_5_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_6_FUNCTION
		BT_LPC17xx_SetIOConfig(70, BT_CONFIG_LPC17xx_PIO2_6_FUNCTION, BT_CONFIG_LPC17xx_PIO2_6_MODE, BT_CONFIG_LPC17xx_PIO2_6_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_7_FUNCTION
		BT_LPC17xx_SetIOConfig(71, BT_CONFIG_LPC17xx_PIO2_7_FUNCTION, BT_CONFIG_LPC17xx_PIO2_7_MODE, BT_CONFIG_LPC17xx_PIO2_7_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_8_FUNCTION
		BT_LPC17xx_SetIOConfig(72, BT_CONFIG_LPC17xx_PIO2_8_FUNCTION, BT_CONFIG_LPC17xx_PIO2_8_MODE, BT_CONFIG_LPC17xx_PIO2_8_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_9_FUNCTION
		BT_LPC17xx_SetIOConfig(73, BT_CONFIG_LPC17xx_PIO2_9_FUNCTION, BT_CONFIG_LPC17xx_PIO2_9_MODE, BT_CONFIG_LPC17xx_PIO2_9_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_10_FUNCTION
		BT_LPC17xx_SetIOConfig(74, BT_CONFIG_LPC17xx_PIO2_10_FUNCTION, BT_CONFIG_LPC17xx_PIO2_10_MODE, BT_CONFIG_LPC17xx_PIO2_10_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_11_FUNCTION
		BT_LPC17xx_SetIOConfig(75, BT_CONFIG_LPC17xx_PIO2_11_FUNCTION, BT_CONFIG_LPC17xx_PIO2_11_MODE, BT_CONFIG_LPC17xx_PIO2_11_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_12_FUNCTION
		BT_LPC17xx_SetIOConfig(76, BT_CONFIG_LPC17xx_PIO2_12_FUNCTION, BT_CONFIG_LPC17xx_PIO2_12_MODE, BT_CONFIG_LPC17xx_PIO2_12_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO2_13_FUNCTION
		BT_LPC17xx_SetIOConfig(77, BT_CONFIG_LPC17xx_PIO2_13_FUNCTION, BT_CONFIG_LPC17xx_PIO2_13_MODE, BT_CONFIG_LPC17xx_PIO2_13_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO3_25_FUNCTION
		BT_LPC17xx_SetIOConfig(121, BT_CONFIG_LPC17xx_PIO3_25_FUNCTION, BT_CONFIG_LPC17xx_PIO3_25_MODE, BT_CONFIG_LPC17xx_PIO3_25_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO3_26_FUNCTION
		BT_LPC17xx_SetIOConfig(122, BT_CONFIG_LPC17xx_PIO3_26_FUNCTION, BT_CONFIG_LPC17xx_PIO3_26_MODE, BT_CONFIG_LPC17xx_PIO3_26_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO4_28_FUNCTION
		BT_LPC17xx_SetIOConfig(156, BT_CONFIG_LPC17xx_PIO4_28_FUNCTION, BT_CONFIG_LPC17xx_PIO4_28_MODE, BT_CONFIG_LPC17xx_PIO4_28_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LPC17xx_PIO4_29_FUNCTION
		BT_LPC17xx_SetIOConfig(157, BT_CONFIG_LPC17xx_PIO4_29_FUNCTION, BT_CONFIG_LPC17xx_PIO4_29_MODE, BT_CONFIG_LPC17xx_PIO4_29_OPENDRAIN);
	#endif
}

static BT_u32 lpc17xx_get_cpu_clock_frequency() {
	return BT_LPC17xx_GetSystemFrequency();
}


static BT_u32 lpc17xx_machine_init() {

	BT_LPC17xx_SetPeripheralClockDivider(31, 1);

	BT_LPC17xx_SetSystemFrequency(BT_CONFIG_SYSCLK_CTRL,
								  BT_CONFIG_MAINPLLCLK_SRC,
								  BT_CONFIG_MAINPLLCLK_CTRL,
								  BT_CONFIG_SYSCLK_DIV,
								  BT_CONFIG_USBCLK_SRC,
								  BT_CONFIG_USBPLLCLK_CTRL,
								  BT_CONFIG_USBCLK_DIV);

	lpc17xx_gpio_init();
	return BT_ERR_NONE;
}

#ifdef BT_CONFIG_MACH_LPC17xx_I2C_0
static const BT_RESOURCE oLPC17xx_i2c0_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_I2C0_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_I2C0_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= 0,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 26,
		.ulEnd				= 26,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
	{
		.ulStart			= BT_CONFIG_MACH_LPC17xx_I2C_0_BUSID,
		.ulEnd				= BT_CONFIG_MACH_LPC17xx_I2C_0_BUSID,
		.ulFlags			= BT_RESOURCE_BUSID,
	},
	{
		.ulStart			= BT_CONFIG_MACH_LPC17xx_I2C_0_SPEED,
		.ulEnd				= BT_CONFIG_MACH_LPC17xx_I2C_0_SPEED,
		.ulFlags			= BT_RESOURCE_INTEGER,
	},
};

BT_INTEGRATED_DEVICE_DEF oLPC17xx_i2c0_device = {
	.name 					= "LPC17xx,i2c",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_i2c0_resources),
	.pResources 			= oLPC17xx_i2c0_resources,
};

const BT_DEVFS_INODE_DEF oLPC17xx_i2c0_inode = {
	.szpName = "i2c0",
	.pDevice = &oLPC17xx_i2c0_device,
};
#endif

#ifdef BT_CONFIG_MACH_LPC17xx_I2C_1
static const BT_RESOURCE oLPC17xx_i2c1_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_I2C1_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_I2C1_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 1,
		.ulEnd				= 1,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 27,
		.ulEnd				= 27,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
	{
		.ulStart			= BT_CONFIG_MACH_LPC17xx_I2C_1_BUSID,
		.ulEnd				= BT_CONFIG_MACH_LPC17xx_I2C_1_BUSID,
		.ulFlags			= BT_RESOURCE_BUSID,
	},
	{
		.ulStart			= BT_CONFIG_MACH_LPC17xx_I2C_1_SPEED,
		.ulEnd				= BT_CONFIG_MACH_LPC17xx_I2C_1_SPEED,
		.ulFlags			= BT_RESOURCE_INTEGER,
	},
};

BT_INTEGRATED_DEVICE_DEF oLPC17xx_i2c1_device = {
	.name 					= "LPC17xx,i2c",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_i2c1_resources),
	.pResources 			= oLPC17xx_i2c1_resources,
};

const BT_DEVFS_INODE_DEF oLPC17xx_i2c1_inode = {
	.szpName = "i2c1",
	.pDevice = &oLPC17xx_i2c1_device,
};
#endif

#ifdef BT_CONFIG_MACH_LPC17xx_I2C_2
static const BT_RESOURCE oLPC17xx_i2c2_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_I2C2_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_I2C2_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 2,
		.ulEnd				= 2,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 28,
		.ulEnd				= 28,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
	{
		.ulStart			= BT_CONFIG_MACH_LPC17xx_I2C_2_BUSID,
		.ulEnd				= BT_CONFIG_MACH_LPC17xx_I2C_2_BUSID,
		.ulFlags			= BT_RESOURCE_BUSID,
	},
	{
		.ulStart			= BT_CONFIG_MACH_LPC17xx_I2C_2_SPEED,
		.ulEnd				= BT_CONFIG_MACH_LPC17xx_I2C_2_SPEED,
		.ulFlags			= BT_RESOURCE_INTEGER,
	},
};

BT_INTEGRATED_DEVICE_DEF oLPC17xx_i2c2_device = {
	.name 					= "LPC17xx,i2c",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_i2c2_resources),
	.pResources 			= oLPC17xx_i2c2_resources,
};

const BT_DEVFS_INODE_DEF oLPC17xx_i2c2_inode = {
	.szpName = "i2c2",
	.pDevice = &oLPC17xx_i2c2_device,
};
#endif


#ifdef BT_CONFIG_MACH_LPC17xx_UART_0
static const BT_RESOURCE oLPC17xx_uart0_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_UART0_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_UART0_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= 0,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 21,
		.ulEnd				= 21,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC17xx_uart0_device = {
	.name 					= "LPC17xx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_uart0_resources),
	.pResources 			= oLPC17xx_uart0_resources,
};

const BT_DEVFS_INODE_DEF oLPC17xx_uart0_inode = {
	.szpName = BT_CONFIG_MACH_LPC17xx_UART_0_INODE_NAME,
	.pDevice = &oLPC17xx_uart0_device,
};
#endif

#ifdef BT_CONFIG_MACH_LPC17xx_UART_1
static const BT_RESOURCE oLPC17xx_uart1_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_UART1_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_UART1_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 1,
		.ulEnd				= 1,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 22,
		.ulEnd				= 22,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC17xx_uart1_device = {
	.name 					= "LPC17xx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_uart1_resources),
	.pResources 			= oLPC17xx_uart1_resources,
};

const BT_DEVFS_INODE_DEF oLPC17xx_uart1_inode = {
	.szpName = BT_CONFIG_MACH_LPC17xx_UART_1_INODE_NAME,
	.pDevice = &oLPC17xx_uart1_device,
};
#endif

#ifdef BT_CONFIG_MACH_LPC17xx_UART_2
static const BT_RESOURCE oLPC17xx_uart2_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_UART2_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_UART2_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 2,
		.ulEnd				= 2,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 23,
		.ulEnd				= 23,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC17xx_uart2_device = {
	.name 					= "LPC17xx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_uart2_resources),
	.pResources 			= oLPC17xx_uart2_resources,
};

const BT_DEVFS_INODE_DEF oLPC17xx_uart2_inode = {
	.szpName = BT_CONFIG_MACH_LPC17xx_UART_2_INODE_NAME,
	.pDevice = &oLPC17xx_uart2_device,
};
#endif

#ifdef BT_CONFIG_MACH_LPC17xx_UART_3
static const BT_RESOURCE oLPC17xx_uart3_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC17xx_UART3_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC17xx_UART3_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 3,
		.ulEnd				= 3,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 24,
		.ulEnd				= 24,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC17xx_uart3_device = {
	.name 					= "LPC17xx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC17xx_uart3_resources),
	.pResources 			= oLPC17xx_uart3_resources,
};

const BT_DEVFS_INODE_DEF oLPC17xx_uart3_inode = {
	.szpName = BT_CONFIG_MACH_LPC17xx_UART_3_INODE_NAME,
	.pDevice = &oLPC17xx_uart3_device,
};
#endif



BT_MACHINE_START(ARM, CORTEX_M3, "LPC Microcontroller Platform")
    .ulSystemClockHz 			= BT_CONFIG_MACH_LPC17xx_SYSCLOCK_FREQ,
	.pfnGetCpuClockFrequency 	= lpc17xx_get_cpu_clock_frequency,
	.pfnMachineInit				= lpc17xx_machine_init,
	.pInterruptController		= &oLPC17xx_nvic_device,

	.pSystemTimer 				= &oLPC17xx_systick_device,


#ifdef BT_CONFIG_MACH_LPC17xx_BOOTLOG_UART_NULL
	.pBootLogger				= NULL,
#endif
#ifdef BT_CONFIG_MACH_LPC17xx_BOOTLOG_UART_0
	.pBootLogger				= &oLPC17xx_uart0_device,
#endif
#ifdef BT_CONFIG_MACH_LPC11xx_BOOTLOG_UART_1
	.pBootLogger				= &oLPC11xx_uart1_device,
#endif
#ifdef BT_CONFIG_MACH_LPC11xx_BOOTLOG_UART_2
	.pBootLogger				= &oLPC11xx_uart2_device,
#endif
#ifdef BT_CONFIG_MACH_LPC11xx_BOOTLOG_UART_3
	.pBootLogger				= &oLPC11xx_uart3_device,
#endif
BT_MACHINE_END
