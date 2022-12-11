/**
 * @file EXTI_program.c
 * @author Amr Abdelhakim
 * @brief This file implement the EXTI module functions
 * @version 1.00
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"defines.h"

#include"EXTI_interface.h"
#include"EXTI_cfg.h"
#include"EXTI_private.h"
#include"EXTI_reg.h"

void EXTI_voidInitInt0(void)
{
	/*implement INT0 sense control configuration*/

#if INT0_SENSE_CTRL== EXTI_u8LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CTRL ==EXTI_u8ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CTRL== EXTI_u8FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CTRL== EXTI_u8RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error Wrong INT0_SENSE_CTRL configuration option
#endif

	/*implement INT0 intial state configuration*/

#if INT0_INTIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#elif INT0_INTIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#else
#error Wrong INT0_INTIAL_STATE configuration option
#endif


}

void EXTI_voidInitInt1(void)
{
	/*implement INT1 sense control configuration*/

#if INT1_SENSE_CTRL == EXTI_u8LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CTRL ==EXTI_u8ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CTRL== EXTI_u8FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CTRL== EXTI_u8RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error Wrong INT1_SENSE_CTRL configuration option
#endif

	/*implement INT1 intial state configuration*/

#if INT1_INTIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#elif INT1_INTIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#else
#error Wrong INT1_INTIAL_STATE configuration option
#endif
}

void EXTI_voidInitInt2(void)
{

	/*implement INT2 sense control configuration*/
#if INT2_SENSE_CTRL== EXTI_u8FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif INT2_SENSE_CTRL== EXTI_u8RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
#error Wrong INT2_SENSE_CTRL configuration option
#endif

	/*implement INT2 intial state configuration*/

#if INT2_INTIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#elif INT2_INTIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
#else
#error Wrong INT2_INTIAL_STATE configuration option
#endif
}

uint8 EXTI_u8SetSenseCtrl(uint8 Copy_u8IntNum, uint8 Copy_u8Sense)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_u8IntNum==EXTI_u8INT0)
	{
		switch(Copy_u8Sense)
		{
		case EXTI_u8LOW_LEVEL :CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case EXTI_u8ON_CHANGE :SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case EXTI_u8FALLING_EDGE :CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
		case EXTI_u8RISING_EDGE :SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
		default: Local_u8ErrorState=NOK;break;
		}
		break;
	}

	else if(Copy_u8IntNum==EXTI_u8INT1)
	{
		switch(Copy_u8Sense)
		{
		case EXTI_u8LOW_LEVEL :CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
		case EXTI_u8ON_CHANGE :SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
		case EXTI_u8FALLING_EDGE :CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
		case EXTI_u8RISING_EDGE :SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
		default: Local_u8ErrorState=NOK;break;
		}
		break;
	}

	else if(Copy_u8IntNum==EXTI_u8INT2)
	{
		switch(Copy_u8Sense)
		{
		case EXTI_u8FALLING_EDGE :CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
		case EXTI_u8RISING_EDGE :SET_BIT(MCUCSR,MCUCSR_ISC2);  break;
		default: Local_u8ErrorState=NOK;break;
		}
		break;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

uint8 EXTI_IntEnable(uint8 Copy_u8IntNum)
{
	uint8 Local_u8ErrorState = OK;

	switch(Copy_u8IntNum)
	{
	case EXTI_u8INT0: SET_BIT(GICR,GICR_INT0); break;
	case EXTI_u8INT1: SET_BIT(GICR,GICR_INT1); break;
	case EXTI_u8INT2: SET_BIT(GICR,GICR_INT2); break;
	default: Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
uint8 EXTI_IntDisable(uint8 Copy_u8IntNum)
{
	uint8 Local_u8ErrorState = OK;

	switch(Copy_u8IntNum)
	{
	case EXTI_u8INT0: CLR_BIT(GICR,GICR_INT0); break;
	case EXTI_u8INT1: CLR_BIT(GICR,GICR_INT1); break;
	case EXTI_u8INT2: CLR_BIT(GICR,GICR_INT2); break;
	default: Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}