#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8INT0			0u
#define EXTI_u8INT1			1u
#define EXTI_u8INT2			2u

#define EXTI_u8LOW_LEVEL		1u
#define EXTI_u8ON_CHANGE		2u
#define	EXTI_u8FALLING_EDGE		3u
#define	EXTI_u8RISING_EDGE		4u

void EXTI_voidInit(void);

uint8 EXTI_u8SetSenseCtrl(uint8 Copy_u8IntNum, uint8 Copy_u8Sense);

uint8 EXTI_IntEnable(uint8 Copy_u8IntNum);
uint8 EXTI_IntDisable(uint8 Copy_u8IntNum);



#endif
