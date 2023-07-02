/**
 ******************************************************************************
 * @file           : main.c
 * @author         : iNazzier
 * @brief          : Contains static code to control SCB
 ******************************************************************************
 */

#ifndef CORTEXM3_CORE_SCB_H_
#define CORTEXM3_CORE_SCB_H_

/******************* Includes START *********************************************/
#include "Common/std_types.h"
/******************* Macro declarations *****************************************/
/*Memory mapping of core hardware*/

#define SCB_BASE (0xE000ED00UL)
#define SCB ((SCB_Type*)SCB_BASE)

#define SCB_AIRCR_VECTKEYSTAT_Pos (16U)			/* for shifting bits to fit vectkey position */
#define SCB_AIRCR_VECTKEYSTAT_Msk (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)

#define SCB_AIRCR_PRIGROUP_Pos (8U)				/* for shifting priority bits for the specific place */
#define SCB_AIRCR_PRIGROUP_Msk (0x7 << SCB_AIRCR_PRIGROUP_Pos)


/* Def group Cortex_preemption_priority */

#define SCB_PRIORITYGROUP_0	(0x00000007UL) 		/* 0 bit for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	 	   4 group for sub-priority */
#define SCB_PRIORITYGROUP_1	(0x00000006UL) 		/* 1 bit for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	 	   3 group for sub-priority */
#define SCB_PRIORITYGROUP_2	(0x00000005UL)  		/* 2 bit for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	 	   2 group for sub-priority */
#define SCB_PRIORITYGROUP_3	(0x00000004UL)  		/* 3 bit for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	 	   1 group for sub-priority */
#define SCB_PRIORITYGROUP_4	(0x00000003UL) 		/* 4 bit for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	 	   0 group for sub-priority */


/******************* Macro Functions declarations *******************************/

/******************* Data Type declarations *************************************/

typedef struct {
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCRS;
	volatile uint32_t CFSR;
}SCB_Type;
/******************* Software interfaces declarations ***************************/

void SCB_SetPriorityGrouping(uint32_t PriorityGroup);
uint32_t SCB_GetPriorityGrouping(void);

#endif /* CORTEXM3_CORE_SCB_H_ */
