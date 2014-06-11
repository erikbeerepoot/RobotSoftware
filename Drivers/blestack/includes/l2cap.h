/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : l2cap.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Header file for L2CAP layer.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#ifndef __L2CAP_H__
#define __L2CAP_H__

#include <ble_status.h>

/******************************************************************************
 * Global Functions
 *****************************************************************************/
/**
 * @defgroup l2cap_functions L2CAP functions
 * @{
 */

/**
 * This function initializes the
 * L2CAP
 *
 * @return BLE_STATUS_SUCCESS,BLE_STATUS_ERROR
 */
tBleStatus L2C_Init(void);

/**
 * This function builds and schedule the sending of a L2CAP Connection Parameter
 * Update Request.
 *
 * @param[in] intMin       Minimum interval parameter
 * @param[in] intMax       Maximum interval parameter
 * @param[in] slaveLatency slave latency parameter
 * @param[in] timeOutMulti Timeout multiplier parameter
 *
 *
 * @return BLE_STATUS_SUCCESS,BLE_STATUS_INVALID_PARAMETER,
 *         BLE_STATUS_OUT_OF_MEMORY
 */
tBleStatus L2C_Build_Connect_Update_Req(tHalUint16 intMin,
                                        tHalUint16 intMax,
                                        tHalUint16 slaveLatency,
                                        tHalUint16 timeOutMulti);

/**
 * @}
 */

/**
 * Function that will be called when there are events from L2CAP layer.
 * 
 * @param[in]  evt      Event code
 * @param[in]  dataLen  length of the data in the buffer
 * @param[in]  data     the buffer which contains the response if
 *                  the event is EVT_L2CAP_CONN_UPDATE_RESP.
 * 
 */ 
void L2CAP_Response_CB(tHalUint16 evt,tHalUint8 dataLen,tHalUint8 *data);

/**
 * @defgroup l2cap_event_codes L2CAP event codes
 * @{
 */
#define EVT_L2CAP_CONN_UPDATE_RESP		(0x0800)
#define EVT_L2CAP_PROCEDURE_TIMEOUT		(0x0801)

/**
 * @}
 */

#endif /* __L2CAP_H__ */