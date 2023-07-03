/*
 * STM32f103xx_HAL_RCC.h
 *
 *  Created on: Jul 2, 2023
 *      Author: iNazzier
 */

#ifndef HAL_DRIVERS_RCC_STM32F103XX_HAL_RCC_H_
#define HAL_DRIVERS_RCC_STM32F103XX_HAL_RCC_H_

/******************* Includes START *********************************************/
#include "Common/std_types.h"
/******************* Macro declarations *****************************************/
/*Memory mapping of core hardware*/
#define PERIPH_BASE 	0x40000000UL
#define APBPERIPH_BASE	0x40000000UL
#define RCC_BASE 		(APBPERIPH_BASE + 0x00021000UL)
#define RCC				((RCC_TypeDef*)RCC_BASE)

#define RCC_APB2ENR_GPIOAEN_Pos	(2U)
#define RCC_APB2ENR_GPIOAEN_Msk	(0x1UL<<RCC_APB2ENR_GPIOAEN_Pos)

#define RCC_APB2ENR_GPIOBEN_Pos	(3U)
#define RCC_APB2ENR_GPIOBEN_Msk	(0x1UL<<RCC_APB2ENR_GPIOEN_Pos)

#define RCC_APB2ENR_GPIOCEN_Pos	(4U)
#define RCC_APB2ENR_GPIOCEN_Msk	(0x1UL<<RCC_APB2ENR_GPIOEN_Pos)

#define RCC_APB2ENR_GPIODEN_Pos	(5U)
#define RCC_APB2ENR_GPIODEN_Msk	(0x1UL<<RCC_APB2ENR_GPIOEN_Pos)

#define RCC_APB2ENR_GPIOEEN_Pos	(6U)
#define RCC_APB2ENR_GPIOEEN_Msk	(0x1UL<<RCC_APB2ENR_GPIOEEN_Pos)


/******************* Data Type declarations *************************************/
typedef struct {
	volatile uint32_t CR;		/*! RCC clock control register,			address offset: 0x00*/
	volatile uint32_t CFGR;		/*! RCC clock configuration register,	address offset: 0x04*/
	volatile uint32_t CIR;		/*! RCC clock interrupt register, 		address offset: 0x08*/
	volatile uint32_t APB2RSTR;	/*! RCC APB2 Peripheral reset register, 	address offset: 0x0C*/
	volatile uint32_t APB1RSTR; 	/*! RCC APB1 Peripheral reset register, 	address offset: 0x10*/
	volatile uint32_t AHBENR;	/*! RCC AHB Peripheral clock enable register, 	address offset: 0x14*/
	volatile uint32_t APB2ENR;	/*! RCC APB2 Peripheral clock enable register, 	address offset: 0x18*/
	volatile uint32_t APB1ENR;	/*! RCC APB1 Peripheral clock enable register, 	address offset: 0x1C*/
	volatile uint32_t BDCR;		/*! RCC Backup domain controller register, 	address offset: 0x20*/
	volatile uint32_t CSR;		/*! RCC Control/status register, 	address offset: 0x24*/


}RCC_TypeDef;
/******************* Macro Functions declarations *******************************/

#define HAL_RCC_GPIOA_CLK_ENABLE() (RCC->APB2ENR |= (RCC_APB2ENR_GPIOAEN_Msk))
#define HAL_RCC_GPIOB_CLK_ENABLE() (RCC->APB2ENR |= (RCC_APB2ENR_GPIOBEN_Msk))
#define HAL_RCC_GPIOC_CLK_ENABLE() (RCC->APB2ENR |= (RCC_APB2ENR_GPIOCEN_Msk))
#define HAL_RCC_GPIOD_CLK_ENABLE() (RCC->APB2ENR |= (RCC_APB2ENR_GPIODEN_Msk))
#define HAL_RCC_GPIOE_CLK_ENABLE() (RCC->APB2ENR |= (RCC_APB2ENR_GPIOEEN_Msk))


#define HAL_RCC_GPIOA_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_GPIOAEN_Msk))
#define HAL_RCC_GPIOB_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_GPIOBEN_Msk))
#define HAL_RCC_GPIOC_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_GPIOCEN_Msk))
#define HAL_RCC_GPIOD_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_GPIODEN_Msk))
#define HAL_RCC_GPIOE_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_GPIOEEN_Msk))


/******************* Software interfaces declarations ***************************/



#endif /* HAL_DRIVERS_RCC_STM32F103XX_HAL_RCC_H_ */
