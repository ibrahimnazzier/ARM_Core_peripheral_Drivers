/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB.c
 * @author         : iNazzier
 * @brief          : Contains static code to control SCB
 ******************************************************************************
 */
#include "CortexM4/CortexM3_Core_SCB.h"
void SCB_SetPriorityGrouping(uint32_t PriorityGroup)
{
	uint32_t Register_Value = 0;
	uint32_t PriorityGroupTemp = (((uint32_t)PriorityGroup) & ((uint32_t)0x07));
	Register_Value &= !(SCB_AIRCR_VECTKEYSTAT_Msk | SCB_AIRCR_PRIGROUP_Msk);
	Register_Value = (Register_Value | ((uint32_t)0x05FA << SCB_AIRCR_VECTKEYSTAT_Pos) | (PriorityGroupTemp<<SCB_AIRCR_PRIGROUP_Pos));
	SCB->AIRCR = Register_Value;
	}




uint32_t SCB_GetPriorityGrouping(void)
{
	return (((uint32_t)SCB->AIRCR & ((uint32_t)SCB_AIRCR_PRIGROUP_Msk)) >> SCB_AIRCR_PRIGROUP_Pos);
}
