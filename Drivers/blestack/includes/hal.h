/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : hal.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Header file which defines Hardware abstraction layer APIs
*                       used by the BLE stack. It defines the set of functions
*                       which needs to be ported to the target platform.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/
#ifndef __HAL_H__
#define __HAL_H__

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <hal_types.h>
#include <ble_status.h>
#include <host_timer.h>

/******************************************************************************
 * Macros
 *****************************************************************************/
 
/******************************************************************************
 * Types
 *****************************************************************************/

/******************************************************************************
 * Function Prototypes
 *****************************************************************************/

/**
 * Writes data to a serial interface.
 *
 * @param[in]  data1    1st buffer
 * @param[in]  data2    2nd buffer
 * @param[in]  n_bytes1 number of bytes in 1st buffer
 * @param[in]  n_bytes2 number of bytes in 2nd buffer
 */
void Hal_Write_Serial(const void* data1, const void* data2, tHalInt32 n_bytes1, tHalInt32 n_bytes2);

/**
 * Enable interrupts from HCI controller.
 */
void Hal_Enable_LL_Int(void);

/**
 * Disable interrupts from HCI controller.
 */
void Hal_Disable_LL_Int(void);

/**
 * This variable must be set to the maximum value (in timer ticks) that can be reached
 * by the Hardware Timer. If the maximum value is greater than 0xFFFF, this value should
 * be set to 0xFFFF.
 */
extern const tHalUint16 Timer_Max_Thresh;

/**
 * Is the maximum value (in msec) that the hardware timer can reach before overflow.
 * It must be less than or equal to 30000 (even if the actual value is greater).
 */
extern const tHalUint16 Max_ms_Timeout;

/**
 * Init Hardware Timer
 */ 
void Hal_Init_Timer();

/**
 * Converts milliseconds to timer ticks.
 * @param[in]  ms    milliseconds
 * @return  returns timer ticks value
 */
tHalUint32 Hal_Conv_Ms_To_Timer_Val(tHalUint32 ms);

/**
 *Returns current timer tick value.
 * @return  timer tick value
 */
tHalUint32 Hal_Get_Timer_Value();

/**
 * Starts timer with the given timeout value.
 * @param[in]  timeout   timeout value (in timer ticks).
 */
void Hal_Start_Host_Timer(tHalUint32 timeout);

/**
 * Stops the timer.
 */
void Hal_Stop_Host_Timer();
 
/**
 * Read a byte from Non Volatile Memory. To be defined for the specific platform.
 * 
 * @param[in]  address  address to be read from
 * @param[out]  data  will contain 1 octet of data if
 *             read was successful
 * 
 * @return  returns BLE_STATUS_SUCCESS if the read was
 * successful
 */
tBleStatus NVM_Read8(tHalUint16 address,tHalUint8* data);

/**
 * Read a word (4 bytes) from Non Volatile Memory. To be defined for the specific platform.
 * 
 * @param[in]  address  address to be read from
 * @param[out]  data  will contain 4 octets of data if
 *             read was successful
 * 
 * @return  returns BLE_STATUS_SUCCESS if the read was
 * successful
 */
tBleStatus NVM_Read32(tHalUint16 address,tHalUint32* data);

/**
 * Write a byte into Non Volatile Memory. To be defined for the specific platform.
 * 
 * @param[in]  address  address in wich data will be written
 * @param[in]  data  data to be written.
 * 
 * @return  returns BLE_STATUS_SUCCESS if the write was
 * successful
 */
tBleStatus NVM_Write8(tHalUint16 address,tHalUint8 data);

/**
 * Write a word (4 bytes) into Non Volatile Memory. To be defined for the specific platform.
 * 
 * @param[in]  address  address in wich data will be written
 * @param[in]  data  data to be written.
 * 
 * @return  returns BLE_STATUS_SUCCESS if the write was
 * successful
 */
tBleStatus NVM_Write32(tHalUint16 address,tHalUint32 data);

/**
 * Erase the NVM.
 * 
 * @return  returns BLE_STATUS_SUCCESS if the erase was
 * successful
 * 
 */
tBleStatus NVM_Erase(void);


#endif /* __HAL_H__ */
