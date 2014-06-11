/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : sm.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Header file for security manager.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#ifndef __SM_H__
#define __SM_H__

/******************************************************************************
* Macros
*****************************************************************************/

/* IO capabilities */
typedef tHalUint8 tSMIoCapability;
#define IO_CAP_DISPLAY_ONLY				(0x00)
#define IO_CAP_DISPLAY_YES_NO			(0x01)
#define KEYBOARD_ONLY					(0x02)
#define IO_CAP_NO_INPUT_NO_OUTPUT		(0x03)
#define IO_CAP_KEYBOARD_DISPLAY			(0x04)

/* authentication requirements */
typedef tHalUint8 tSMBondingMode;
#define BONDING_REQUIRED				(0x01)
#define NO_BONDING_REQUIRED				(0x00)

typedef tHalUint8 tSMMIMTMode;
#define MITM_PROTECTION_NOT_REQUIRED	(0x00)
#define MITM_PROTECTION_REQUIRED        (0x01)

#define OOB_AUTH_DATA_ABSENT		    (0x00)
#define OOB_AUTH_DATA_PRESENT      		(0x01)

#define AUTHORIZATION_NOT_REQUIRED	     (0x00)
#define AUTHORIZATION_REQUIRED			 (0x01)

/* valid authorization responses */
#define CONNECTION_AUTHORIZED			(0x01)
#define CONNECTION_REJECTED				(0x02)

#define USE_FIXED_PIN_FOR_PAIRING		(0x0)
#define DONOT_USE_FIXED_PIN_FOR_PAIRING	(0x01)
#define PASSKEY_ENTERED					(0x02)

/* link security status */
#define SM_LINK_AUTHENTICATED               (0x01)
#define SM_LINK_AUTHORIZED                  (0x02)
#define SM_LINK_ENCRYPTED                   (0x04)

/* SMP pairing failed reason codes */
#define PASSKEY_ENTRY_FAILED			(0x01)
#define OOB_NOT_AVAILABLE				(0x02)
#define AUTH_REQ_CANNOT_BE_MET			(0x03)
#define CONFIRM_VALUE_FAILED			(0x04)
#define PAIRING_NOT_SUPPORTED			(0x05)
#define INSUFF_ENCRYPTION_KEY_SIZE		(0x06)
#define CMD_NOT_SUPPORTED				(0x07)
#define UNSPECIFIED_REASON				(0x08)
#define VERY_EARLY_NEXT_ATTEMPT			(0x09)
#define SM_INVALID_PARAMS				(0x0A)

/**
 * The structure consolidates the authentication requirements
 * of the device, to be used with SM_Set_Authentication_req
 */ 
typedef struct _tSMAuthReq
{
	/**
	 * the pin to be used for generating the TK
	 * during the pairing process
	 */ 
	tHalUint32      pin;
	
	/**
	 * The OOB data to be used to generate
	 * the TK during the pairing process
	 */ 
	tHalUint8		OOBData[16];
	
	/**
	 * Specifies the MIMT protection
	 * as set by the application
	 */ 
	tSMMIMTMode 	mimtMode;
	
	/**
	 * indicates whether OOB data
	 * is available
	 */ 
	tHalBool		oobData;
	
	/**
	 * The encrytion key size requirement
	 * for the device. If an attribute has
	 * encryption key size requirements and
	 * this setting does not meet that, then
	 * such requests are rejected
	 */ 
	tHalUint8       minEncKeySize;
	
	/**
	 * this is the maximum encryption key size
	 * that can be used during the pairing process.
	 * If the master has an encrytion key size
	 * lesser than our max size but greater or
	 * equal to the min size, then that size
	 * is used during the pairing process
	 */ 
	tHalUint8       maxEncKeySize;
	
	/*
	 * If this is set to TRUE, then, during
	 * the paring process the passkey request
	 * is not sent to the application. Instead the
	 * pin set by the application is used. 
	 * Default is 000000
	 */ 
	tHalBool       useFixedPin;
	
	/**
	 * the bonding mode indicates whether
	 * the device can have a trusted 
	 * relationship with other devices
	 */ 
	tSMBondingMode  bondingMode;
}tSMAuthReq;


/* These values need to be hard coded . They are unique for a device */

/**
 * ER is a 128-bit key generated for each LE device that supports
 * encrypted connections. It is used to generate LTK using EDIV
 */
extern tHalUint8 ER[16];
/** IR is a 128-bit key generated for each LE device that supports
 * encrypted connections, uses random addresses or signing data. IR
 * is used to generate IRK and CSRK and DHK.
 */
extern tHalUint8 IR[16];

/** The DIV used for generating the CSRK. */
extern tHalUint8 DIV[2];


/******************************************************************************
* Function prototypes
*****************************************************************************/
/** @defgroup SM_func SM functions
 * @{
 */

/**
* Initializes the security manager with default
* values for security properties.
*/ 
void SM_Init(void);

/**
 * Sends queued up packets for transmission to L2CAP
 * and processes the received packets from L2CAP
 */ 
void SM_Process_Q(void);

/**
 * Configure the device with the given IO capabilities.
 * 
 * @param[in] ioCap IO capabilities
 */ 
void SM_Set_IO_Capabilities(tSMIoCapability ioCap);

/**
 * Configure authentication requirements
 * 
 * @param[in] authReq  the authentication requirements with
 * 				which the device has to be configured
 * return  returns success if the authentication requirements
 *          were set. Else if device is in connection,
 *          returns command disallowed
 */ 
tBleStatus SM_Set_Authentication_req(tSMAuthReq authReq);

/**
 * SM_Set_Authorization_req
 * 
 * @param[in]  authorReq  1 or 0
 * 
 * If authorReq is 1, then the remote device needs 
 * authorization before accessing
 * attributes which require authorization
 */ 
void SM_Set_Authorization_req(tHalUint8 authorReq);

/**
 * Give a passkey to the BLE Stack.
 *
 * @param[in]  passKey  the passkey with which the device
 * 				has to be configured
 */ 
void SM_PassKeyResp(tHalUint32  passKey);

/**
 * Authorize or not the device.
 *
 * @param[in]  authorize  If 1, then the remote device
 *              is authorized else it is not authorized
 * 
 * @return  returns success if the device was waiting 
 * 			 for authorization response
 */ 
tBleStatus SM_AuthorizationResp(tHalUint8 authorize);

/**
 * Requests the master to initiate pairing.
 * 
 * @param[in]  bonding  bonding required?
 * @param[in]  mitm  MIMT protection required?
 * 
 */ 
tBleStatus SM_Initiate_SecReq(tSMBondingMode bonding,tSMMIMTMode mitm);

/**
 * configures the whitelist with the
 * devices in the database
 */ 
tBleStatus SM_Configure_WhiteList(void);


/**
* returns BLE_STATUS_SUCCESS if the device is bonded
* else returns BLE_STATUS_DEV_NOT_BONDED
*/
tBleStatus SM_Is_Device_Bonded(void);

/**
 * @}
 */

/**
 * GAP_SM_Aci_Event_Handler
 * 
 * @param[in]  evt  Event code of the event to be sent
 * @param[in]  status  status of the command for which this
 * 				event is being sent
 * 
 * forms the event packets for the GAP vendor specific events
 * with the status passed and sends them to the host
 */ 
void SM_Event_CB(tHalUint32 evt, tBleStatus status);

/* GAP Vendor specific event codes */
#define EVT_SM_PAIRING_CMPLT    			(0x0401)
#define EVT_SM_PASS_KEY_REQUEST    		    (0x0402)
#define EVT_SM_AUTHORIZATION_REQUEST   	    (0x0403)
#define EVT_SM_SECURITY_REQ_INITIATED		(0x0404)

/* L2CAP vendor specific event codes */
#define EVT_BLUE_L2CAP_CONN_UPDATE_RESP			(0x0800)
#define EVT_BLUE_L2CAP_PROCEDURE_TIMEOUT		(0x0801)

/* error codes to be sent with the pairing complete event */
#define SM_PAIRING_TIMEOUT              (0x01)
#define SM_PAIRING_FAILED               (0x02)


#endif /* __SM_H__ */
