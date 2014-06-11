/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : gap.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Header file for GAP layer. 
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/
#ifndef __GAP_H__
#define __GAP_H__

#include <link_layer.h>

/*----------------GAP UUIDs--------------------------*/
#define GAP_SERVICE_UUID                        (0x1800)
#define DEVICE_NAME_UUID						(0x2A00)
#define APPEARANCE_UUID							(0x2A01)
#define PERIPHERAL_PRIVACY_FLAG_UUID			(0x2A02)
#define RECONNECTION_ADDR_UUID					(0x2A03)
#define PERIPHERAL_PREFERRED_CONN_PARAMS_UUID	(0x2A04)

/*----------------Characteristic value lengths--------------*/
#define DEVICE_NAME_CHARACTERISTIC_LEN			        (16)/* should this be 248 or is it implementation specific? */
#define APPEARANCE_CHARACTERISTIC_LEN			        (2)
#define PERIPHERAL_PRIVACY_CHARACTERISTIC_LEN	        (1)
#define RECONNECTION_ADDR_CHARACTERISTIC_LEN			(6)
#define PERIPHERAL_PREF_CONN_PARAMS_CHARACTERISTIC_LEN	(8)

/*------------- AD types for adv data and scan response data ----------------*/

/* FLAGS AD type */
#define AD_TYPE_FLAGS							(0x01)
/* flag bits */
#define FLAG_BIT_LE_LIMITED_DISCOVERABLE_MODE	(0x01)
#define FLAG_BIT_LE_GENERAL_DISCOVERABLE_MODE	(0x02)
#define FLAG_BIT_BR_EDR_NOT_SUPPORTED			(0x04)
#define FLAG_BIT_LE_BR_EDR_CONTROLLER			(0x08)/* single device supports BR/EDR and LE controller */
#define FLAG_BIT_LE_BR_EDR_HOST					(0x10)/* single device supports BR/EDR and LE host */

/* SERVICE UUID AD types */
#define AD_TYPE_16_BIT_SERV_UUID				(0x02)
#define AD_TYPE_16_BIT_SERV_UUID_CMPLT_LIST		(0x03)
#define AD_TYPE_32_BIT_SERV_UUID				(0x04)
#define AD_TYPE_32_BIT_SERV_UUID_CMPLT_LIST		(0x05)
#define AD_TYPE_128_BIT_SERV_UUID				(0x06)
#define AD_TYPE_128_BIT_SERV_UUID_CMPLT_LIST	(0x07)

/* LOCAL NAME AD types */
#define AD_TYPE_SHORTENED_LOCAL_NAME			(0x08)
#define AD_TYPE_COMPLETE_LOCAL_NAME			    (0x09)

/* TX power level AD type*/
#define AD_TYPE_TX_POWER_LEVEL					(0x0A)

/* security manager TK value AD type */
#define AD_TYPE_SEC_MGR_TK_VALUE				(0x10)

/* security manager OOB flags */
#define AD_TYPE_SEC_MGR_OOB_FLAGS				(0x11)

/* slave connection interval AD type */
#define AD_TYPE_SLAVE_CONN_INTERVAL				(0x12)

/* service solicitation UUID list Ad types*/
#define AD_TYPE_SERV_SOLICIT_16_BIT_UUID_LIST	(0x14)
#define AD_TYPE_SERV_SOLICIT_32_BIT_UUID_LIST	(0x15)

/* service data AD type */
#define AD_TYPE_SERVICE_DATA					(0x16)	

/* manufaturer specific data AD type */
#define AD_TYPE_MANUFACTURER_SPECIFIC_DATA		(0xFF)

#define MAX_ADV_DATA_LEN						(31)

#define DEVICE_NAME_LEN			  				(7)
#define BD_ADDR_SIZE							(6)

/* privacy flag values */
#define PRIVACY_ENABLED							(0x01)
#define PRIVACY_DISABLED						(0x00)

/* conection intervals in terms of 625 micro sec */
#define DIR_CONN_ADV_INT_MIN					(0x190)/*250ms*/
#define DIR_CONN_ADV_INT_MAX					(0x320)/*500ms*/
#define UNDIR_CONN_ADV_INT_MIN					(0x800)/*1.28s*/
#define UNDIR_CONN_ADV_INT_MAX					(0x1000)/*2.56s*/
#define LIM_DISC_ADV_INT_MIN					(0x190)/*250ms*/
#define LIM_DISC_ADV_INT_MAX					(0x320)/*500ms*/
#define GEN_DISC_ADV_INT_MIN					(0x800)/*1.28s*/
#define GEN_DISC_ADV_INT_MAX					(0x1000)/*2.56s*/

/* time out values */
#define LIM_DISC_MODE_TIMEOUT					(180000)/* 180 seconds. according to the errata published */
#define PRIVATE_ADDR_INT_TIMEOUT				(900000)/* 15 minutes */

typedef tHalUint8 tGapRole;
#define GAP_PERIPHERAL_ROLE						(0x01)
#define GAP_BROADCASTER_ROLE					(0x02)
#define GAP_CENTRAL_ROLE						(0x03)
#define GAP_OBSERVER_ROLE						(0x04)

typedef tHalUint8 tGapMode;
#define GAP_NON_DISC_MODE						(0x01)
#define GAP_LIM_DISC_MODE						(0x02)
#define GAP_GEN_DISC_MODE						(0x04)
#define GAP_NON_CONN_MODE						(0x08)
#define GAP_DIRECT_CONN_MODE					(0x10)
#define GAP_UNDIRECTED_CONN_MODE				(0x20)

/* SECURITY MANAGER OOB FLAGS */
#define SM_OOB_FLAGS_FIELD                      (0x01)
#define SM_OOB_LE_SUPPORTED                     (0x02)
#define SM_OOB_SIMULTANEOUS_LE_BREDR            (0x04)
#define SM_OOB_ADDR_TYPE                        (0x08)

/** @defgroup GAP_func GAP functions
 * @{
 */

/**
 * Registers the GAP service with GATT 
 * and also creates the device name and appearance
 * characteristics which are mandatory with the 
 * default values.
 *
 * @param[in]   role        Specifies the GAP role
 * @param[in]   handles     Buffer which will contain the 
 * 				3 GAP service and characteristic handles
 * 				on successful initialization:
 *              0 - GAP service handle
 *              1 - Device Name Characteristic handle
 *              2 - Appearance Characteristic handle
 *
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus GAP_Init(tHalUint8 role,tHalUint16 *handles);

/**
 * sets the requirements for non discoverable mode
 *
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus GAP_Set_Non_Discoverable_Mode(void);

/**
 * Sets the requirements for limited discoverable mode
 * 
 * @param[in] buff A pointer to a buffer containing connection parameters and
 *              advertising data as follows:
 *            \li \c buff[0]----------------------------------------advType
 * 			  \li \c buff[1]----------------------------------------advintervalmin
 * 			  \li \c buff[2]----------------------------------------advintervalmax
 * 			  \li \c buff[3]----------------------------------------addr_type
 * 			  \li \c buff[4]----------------------------------------adv_filter_policy
 *            \li \c buff[5]----------------------------------------local_name_len
 * 			  \li \c buff[5...local_name_len-1]---------------------local name
 *            (contains adtype followed by the local name)
 *            \li \c buff[5+local_name_len]-------------------------service_uuid_len
 *            \li \c buff[5+local_name_len+1...service_uuid_len-1]--service uuid list
 *            (contains adtype followed by the uuid
 *             service uuid len bytes)
 *            \li \c buff[7+local_name_len+service_uuid_len]--------slave_conn_interval_min(2bytes)
 * 			  \li \c buff[7+local_name_len+service_uuid_len+2]------slave_conn_interval_max(2bytes)
 *
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus GAP_Set_Limited_Discoverable_Mode(tHalUint8 *buff);

/**
 * Sets the requirements for non connectable mode
 *
 * @param[in] buff A pointer to a buffer containing connection parameters and
 *              advertising data. See GAP_Set_Limited_Discoverable_Mode().
 *
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus GAP_Set_Discoverable_Mode(tHalUint8 *buff);

/**
 * Sets the requirements for discoverable mode
 *
 * @param[in] buff A pointer to a buffer containing:
 *            \li \c buff[0]-------------------------------own address type
 *            \li \c buff[1]-------------------------------direct address type
 *            \li \c buff[2...7]---------------------------direct address
 *
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus GAP_Set_Direct_Connectable_Mode(tHalUint8 *buff);

/**
 * Sets the requirements for non connectable mode
 *
 * @param[in] buff A pointer to a buffer containing:
 *            \li \c buff[0]-------------------------------advertisement type
 *
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus GAP_Set_NonConnectable_Mode(tHalUint8 *buff);

/**
 * Sets the requirements for undirected connectable mode
 *
 * @param[in] buff A pointer to a buffer containing:
 *            \li \c buff[0]-------------------------------filter policy
 *            \li \c buff[1]-------------------------------own address type
 *
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus GAP_Set_Undirected_Connectable_Mode(tHalUint8 *buff);

/**
 * the GAP terminate procedure is started by starting the
 * link layer disconnection procedure
 *
 * @param[in] connHandle  handle of the connection to be terminated
 * @param[in] reason      reason for requesting disconnection
 *
 * @return returns error codes corresponding to the status
 */
tBleStatus GAP_Terminate_Link(tHalUint16 connHandle, tHalUint8 reason);

/**
 * If the ad type specified exists, then it is replaced with the
 * new values. If it does not exist, then it is added along with
 * the existing ones
 * 
 * @param[in]  advDataLen  length if the advertisement data
 * @param[in]  advData     the advertisemnet data formatted according
 * 				to the bluetooth spec
 * 
 * @return  returns error codes corresponding to the status
 */ 
tBleStatus GAP_Update_Adv_Data(tHalUint8 advDataLen,tHalUint8 *advData);

/**
 * Removes the specified ADtype if present.
 *
 * @param[in]  adtype  The AD type to be deleted
 * 
 * @return  returns error codes corresponding to the status
 */ 
tBleStatus GAP_Delete_ADType(tHalUint8 adtype);

/**
 * fills the buffer provided with the public address of the 
 * device
 *
 * @param[out] pubBdAddr  The public address of the device
 */ 
void Get_PublicAddr(tBDAddr pubBdAddr);

/**
 * Callback that will be called when the device exits
 * Limited Discoverable Mode.
 */
void GAP_LimitedDiscoverableTimeout_CB();

/**
 * Callback that will be called when a connection has been established.
 * It is invoked inside an interrupt routine, so no stack commands can be used,
 * neither intensive operations can be performed.
 *
 * @param[in]  addr    BD_ADDR of peer device.
 */
void GAP_ConnectionComplete_CB(tBDAddr addr);

/**
 * Callback that will be called when a connection is terminated.
 * It is invoked inside an interrupt routine, so no stack commands can be used,
 * neither intensive operations can be performed.
 *
 * @param[in]  reason  The reason why connection is terminated.
 */
void GAP_DisconnectionComplete_CB(tHalUint8 reason);

/**
 * Returns the GAP service handle
 */
tHalUint16 Get_GAP_Handle(void);

/**
 * @}
 */

#endif /* __GAP_H__ */
