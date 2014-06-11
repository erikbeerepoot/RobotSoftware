/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : host_timer.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Timer libray dedicated to the BLE stack. 
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/
#ifndef __HOST_TIMER_H__
#define __HOST_TIMER_H__


/******************************************************************************
 * Function Prototypes
 *****************************************************************************/

/**
 * Initialise the timer module. This function initialises the timer Queue
 * 
 */

void Timer_Init(void);

/**
 * Process the TimerQ
 *
 */

void Timer_ProcessQ(void);


/**
 * Function to be called from the timer's ISR, to inform the stack
 * that the timer has expired.
 * 
 */

void Timer_ExpiryCallback(void);

#endif /* __HOST_TIMER_H__ */