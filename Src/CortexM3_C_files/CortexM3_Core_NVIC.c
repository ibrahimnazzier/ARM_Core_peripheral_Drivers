
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : iNazzier
 * @brief          : Contains static code to control NVIC
 ******************************************************************************
 */

#include "CortexM4/CortexM3_Core_NVIC.h"
/**
 \brief Enable Interrupt
 \details Enable a device specific interrupt in the NVIC interrupt controller
 \param [in] IRQn specific device number
 \note IRQn Must not be negative
 **/
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0)
	{
		NVIC->ISER[((uint32_t)IRQn)>>5] = (1UL<<(((uint32_t)IRQn) & 0x1F));
	}
}

/**
 \brief Disable Interrupt
 \details Disable a device specific interrupt in the NVIC interrupt controller
 \param [in] IRQn specific device number
 \note IRQn Must not be negative
 **/
void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0)
	{
		NVIC->ICER[((uint32_t)IRQn)>>5] = (1UL<<(((uint32_t)IRQn) & 0x1F));
	}
}

/**
 \brief pends Interrupt
 \details make a device specific interrupt in pending state
 \param [in] IRQn specific device number
 \note IRQn Must not be negative
 **/
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0)
	{
		NVIC->ISPR[((uint32_t)IRQn)>>5] = (1UL<<(((uint32_t)IRQn) & 0x1F));
	}
}

/**
 \brief Clear pending
 \details clear a device specific interrupt from pending state
 \param [in] IRQn specific device number
 \note IRQn Must not be negative
 **/
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0)
	{
		NVIC->ICPR[((uint32_t)IRQn)>>5] = (1UL<<(((uint32_t)IRQn) & 0x1F));
	}
}

/**
 \brief Get Active Interrupt
 \details Reads the active register in NVIC and returns the active bit for the active interrupt
 \param [in] IRQn specific device number
 \returns 		0 interrupt state is not active
 \returns 		1 interrupt state is active
 \note IRQn Must not be negative
 **/
uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
	return ((NVIC->IABR[((uint32_t)IRQn)>>5]) & (1UL<<(((uint32_t)IRQn)&0x1F)) !=(uint32_t)0) ? 1UL : 0UL;
}

/**
 \brief Set Interrupt priority
 \details set the priority of a device specific interrupt or a processor exception
 	 	  interrupt number could be positive to specify a device specific interrupt,
 	 	  or negative for a system exception.
 \param [in] IRQn specific device number
 \param [in] priority priority to set.
 \note 		 priority cannot be set for every processor exception
 \note IRQn Must not be negative
 **/
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
	if ((uint32_t)IRQn >= 0)
	{
		NVIC->IP[(uint32_t)IRQn] = ((uint8_t)(priority << (8- NVIC_PRIO_BITS))& (uint32_t)0xFF);
	}
	else
	{
		// do nothing
	}
}

/**
 \brief Get Interrupt priority
 \details Reads the priority of a device specific interrupt or a processor exception
 	 	  interrupt number could be positive to specify a device specific interrupt,
 	 	  or negative for a system exception.
 \param [in] IRQn specific device number

 \return 	Interrupt priority.
 	 	 	Value is aligned automatically to the implemented priority bits of the MCU
 **/
uint32_t NVIC_GetPriority(uint32_t IRQn)
{
	if ((uint32_t)IRQn >= 0)
	{
		return ((NVIC->IP[(uint32_t)IRQn]) >> (8- NVIC_PRIO_BITS));
	}
	else
	{
		// do nothing
	}
}
