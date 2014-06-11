/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : gatt_client.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Header file for GATT client layer.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#ifndef __GATT_CLIENT_H__
#define __GATT_CLIENT_H__

/******************************************************************************
 * Types
 *****************************************************************************/

/******************************************************************************
 * Global Functions
 *****************************************************************************/

/** @defgroup GATT_client_func GATT client functions
 * See GATT_Event_CB().
 * @{
 */

/**
 * This function posts exchange mtu request.
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED
 */
tBleStatus Gatt_Exchange_Configuration(void);

/**
 * This function posts find information request
 *
 * @param[in] startHandle    starting handle of the range
 * @param[in] endHandle      ending handle of the range
 *
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED
 */
tBleStatus Gatt_Find_Information_Req(tHalUint16 startHandle,
                                     tHalUint16 endHandle);

/**
 * This function posts find by type value request.
 *
 * @param[in] startHandle    starting handle of the range
 * @param[in] endHandle      ending handle of the range
 * @param[in] uuid           attribute type(uuid 16 bit)
 * @param[in] valLen         length of the attibute value
 * @param[in] attrVal        value of the attribute to be matched
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED
 */
tBleStatus Gatt_Find_Attr_By_Typ_And_Value_Req(tHalUint16 startHandle,
                                               tHalUint16 endHandle,
                                               tHalUint16 uuid,
                                               tHalUint16 valLen,                                        
                                               tHalUint8* attrVal);
/**
 * This function posts Read by group type/read by type 
 * request
 *
 * @param[in] startHandle    starting handle of the range
 * @param[in] endHandle      ending handle of the range
 * @param[in] uuidType       uuid type (16 or 128 type)
 * @param[in] uuid           attribute type(uuid)
 *
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED.
 */
tBleStatus Gatt_Read_Attr_By_Grp_Type_Req(tHalUint16 startHandle,
                                          tHalUint16 endHandle,
                                          tUuidType uuidType,
                                          tUuidValue uuid);
/**
 * This function posts Read by group type/read by type 
 * request
 *
 * @param[in] startHandle    starting handle of the range
 * @param[in] endHandle      ending handle of the range
 * @param[in] uuidType       uuid type (16 or 128 type)
 * @param[in] uuid           attribute type(uuid)
 *
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED.
 */
tBleStatus Gatt_Read_Attr_By_Type_Req(tHalUint16 startHandle,
                                      tHalUint16 endHandle,
                                      tUuidType uuidType,
                                      tUuidValue uuid);

/**
 * This function is used to prepare a long value.
 *
 * @param[in] attrHandle       handle of the attribute to be written
 * @param[in] valOffset        Specify the offset at which value is written
 * @param[in] valLen           length of the value to be written
 * @param[in] attrValue        Value to be written to attribute
 *
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED.
 */
tBleStatus Gatt_Prepare_Write_Req(tHalUint16 attrHandle,
                                  tHalUint16 valOffset,
                                  tHalUint16 valLen,
                                  tHalUint8* attrValue);
/**
 * This function is used to execute prepared writes
 *
 * @param[in] execute         Execute writes/cancel writes
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED.
 */
tBleStatus Gatt_Execute_Write_Req(tHalBool execute);


/**
 * This function is used to confirm an indication sent by server
 *
 * @return BLE_STATUS_SUCCESS or BLE_STATUS_NOT_ALLOWED.
 */
tBleStatus Gatt_Confirm_Indication(void);

/**
 * Procedure to discover all primary services.
 */
tBleStatus Gatt_Disc_All_Prim_Services(void);

/**
 * Procedure to discover a primary service from its UUID.
 *
 * @param[in] servUuidType     type of UUID (16 bits or 128 bits)
 * @param[in] servUuid         UUID of the service to be discovered
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Disc_Prim_serv_By_Uuid(tUuidType servUuidType,
                                       tUuidValue servUuid);

/**
 * Procedure to discover included services
 *
 * @param[in] startServHandle    starting handle of the range
 * @param[in] endServHandle      ending handle of the range
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED.
 */
tBleStatus Gatt_Find_Included_Services(tHalUint16 startServHandle,
                                       tHalUint16 endServHandle);

/**
 * Procedure to discover all characteristics of a service.
 *
 * @param[in] startServHandle    starting handle of the range
 * @param[in] endServHandle      ending handle of the range
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED.
 */
tBleStatus Gatt_Disc_All_Charac_Of_Serv(tHalUint16 startServHandle,
                                        tHalUint16 endServHandle);

/**
 * Procedure to discover a characteristic using its UUID.
 *
 * @param[in] startServHandle    starting handle of the range
 * @param[in] endServHandle      ending handle of the range
 * @param[in] charUuidType       UUID type (16-bit or 128-bit type)
 * @param[in] charUuid           characteristic UUID.
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Disc_Charac_By_Uuid(tHalUint16 startServHandle,
                                    tHalUint16 endServHandle,
                                    tUuidType charUuidType,
                                    tUuidValue charUuid
                                    );

/**
 * Procedure to discover all characteristic descriptor.
 *
 * @param[in] charValHandle    handle of the characteristic
 * @param[in] charEndHandle    ending handle of the characteristic
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Disc_Charac_Desc(tHalUint16 charValHandle,
                                 tHalUint16 charEndHandle);

/**
 * Procedure to read short characteristic value.
 *
 * @param[in] attrHandle    handle of the characteristic
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Read_Charac_Val(tHalUint16 attrHandle);

/**
 * Procedure to read characteritic when UUID is given.
 *
 * @param[in] startHandle    Starting handle of the range to be searched
 * @param[in] endHandle      End handle of the range to be searched
 * @param[in] charUuidType   UUID type
 * @param[in] charUuid       A 16 bit or 128 bit UUID value
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Read_Charac_By_Uuid(tHalUint16 startHandle,
                                    tHalUint16 endHandle,
                                    tUuidType charUuidType,
                                    tUuidValue charUuid);


/**
 * Procedure to read long characteristic value
 *
 * @param[in] attrHandle    Handle of the characteristic to be read
 * @param[in] valOffset     Offset from which the value needs to be read
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Read_Long_Charac_Value(tHalUint16 attrHandle,
                                       tHalUint16 valOffset);

/**
 * Procedure to read multiple characteristic values
 *
 * @param[in] numOfHandles      The number of handles for which the value has to
 *                              be read
 * @param[in] setOfCharHandles  The handles for which the attribute value has to
 *                              be read
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Multi_Charac_Values(tHalUint16 numOfHandles,
                                    tHalUint8* setOfCharHandles);


/**
 * Procedure to write an attribute using write command
 *
 * @param[in] attrHandle   Handle of the attribute to be written
 * @param[in] valLen       Length of the value to be written
 * @param[in] attrValue    Value to be written
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Write_Without_Resp(tHalUint16 attrHandle,
                                   tHalUint16 valLen,
                                   tHalUint8* attrValue
                                   );

/**
 * Procedure to write an attribute using signed write command
 *
 * @param[in] attrHandle   Handle of the attribute to be written
 * @param[in] valLen       Length of the value to be written
 * @param[in] attrValue    Value to be written
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Signed_Write_Without_Resp(tHalUint16 attrHandle,
                                          tHalUint16 valLen,
                                          tHalUint8* attrValue
                                          );

/**
 * Procedure to write a short characteristic (ATT_MTU -3)
 *
 * @param[in] attrHandle   Handle of the attribute to be written
 * @param[in] valLen       Length of the value to be written
 * @param[in] attrValue    Value to be written
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Write_Charac_Value(tHalUint16 attrHandle,
                                   tHalUint16 valLen,
                                   tHalUint8* attrValue);

/**
 * Procedure to write a long characteristic
 *
 * @param[in] attrHandle   Handle of the attribute to be written
 * @param[in] valOffset    Offset at which the attribute has to be written
 * @param[in] valLen       Length of the value to be written
 * @param[in] attrValue    Value to be written
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Write_Long_Charac_Values(tHalUint16 attrHandle,
                                         tHalUint16 valOffset,
                                         tHalUint16 valLen,
                                         tHalUint8* attrValue);

/**
 * Procedure to write a short characteristic reliably
 *
 * @param[in] attrHandle   Handle of the attribute to be written
 * @param[in] valOffset    Offset at which the attribute has to be written
 * @param[in] valLen       Length of the value to be written
 * @param[in] attrValue    Value to be written
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Write_Charac_Reliable(tHalUint16 attrHandle,
                                      tHalUint16 valOffset,
                                      tHalUint16 valLen,
                                      tHalUint8* attrValue);

/**
 * Procedure to read short characteristic descriptor
 *
 * @param[in] attrHandle   Handle of the descriptor to be read
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Read_Charac_Desc(tHalUint16 attrHandle);

/**
 * Procedure to read long characteristic descriptor
 *
 * @param[in] attrHandle   Handle of the characteristic descriptor.
 * @param[in] valOffset    Offset from which the value needs to be read
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Read_Long_Charac_Desc(tHalUint16 attrHandle,
                                      tHalUint16 valOffset);

/**
 * Procedure to write short characteristic descriptor
 *
 * @param[in] attrHandle   Handle of the attribute to be written
 * @param[in] valLen       Length of the value to be written
 * @param[in] attrValue    Value to be written
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Write_Charac_Desc(tHalUint16 attrHandle,
                                  tHalUint16 valLen,
                                  tHalUint8* attrValue);

/**
 * Procedure to write long characterstic descriptor
 *
 * @param[in] attrHandle   Handle of the attribute to be written
 * @param[in] valOffset    Offset at which the attribute has to be written
 * @param[in] valLen       Length of the value to be written
 * @param[in] attrValue    Value to be written
 *
 * @return BLE_STATUS_SUCCESS, BLE_STATUS_NOT_ALLOWED, BLE_STATUS_INVALID_PARAMS.
 */
tBleStatus Gatt_Write_Long_Charac_Desc(tHalUint16 attrHandle,
                                       tHalUint16 valOffset,
                                       tHalUint16 valLen,
                                       tHalUint8* attrValue);

/**
 * @}
 */

/**
 * This function is a callback called when a response, a
 * notification or an indication has been received from the
 * server or a procedure is completed or a timeout has occurred.
 *
 * @param[in] evt         Type of event
 * @param[in] dataLen     length of data
 * @param[in] data        the buffer which contains the packet if the event is the
 *                          receiving of a reponse packet.
 *
 */
void GATT_Event_CB(tHalUint16 evt,tHalUint8 dataLen,tHalUint8 *data);


/** @defgroup GATT_evt_codes GATT vendor specific event codes
 * See GATT_Event_CB().
 * @{
 */

/**
 * Event sent when a GATT attribute has been modified and
 * GATT_SERVER_ATTR_WRITE flag was set in the tGattServerEvent
 * mask for Gatt_Add_Characteristic() or Gatt_Add_Charac_Desc().
 * The new value is passed to the GATT_Server_CB() function.
 * @sa GATT_Server_CB().
 */
#define EVT_GATT_ATTRIBUTE_MODIFIED		        (0x0C01)

/**
 * Event sent when a GATT procedure timeout expires.
 * Data: @ref SERVER_TIMEOUT_GATT or @ref CLIENT_TIMEOUT_GATT.
 */
#define EVT_GATT_PROCEDURE_TIMEOUT			    (0x0C02)

/**
 * Event sent when an Exchange MTU Response is received.
 * Data: Exchange MTU Response without opcode (Spec. Vol. 3 Part F, 3.4.2.2)
 */
#define EVT_EXCHANGE_MTU_RESP				    (0x0C03)

/**
 * Event sent when a Find Information Response is received.
 * Data: Find Information Response without opcode (Spec. Vol. 3 Part F, 3.4.3.2)
 */
#define EVT_ATT_FIND_INFORMATION_RESP		    (0x0C04)

/**
 * Event sent when a Find By Type Value Response is received.
 * Data: Find By Type Value Response without opcode (Spec. Vol. 3 Part F, 3.4.3.4)
 */
#define EVT_ATT_FIND_BY_TYPE_VAL_RESP		    (0x0C05)

/**
 * Event sent when a Read By Type Response is received.
 * Data: Read By Type Response without opcode (Spec. Vol. 3 Part F, 3.4.3.4)
 */
#define EVT_ATT_READ_BY_TYPE_RESP			    (0x0C06)

/**
 * Event sent when a Read Response is received.
 * Data: Read Response without opcode (Spec. Vol. 3 Part F, 3.4.4.4)
 */
#define EVT_ATT_READ_RESP					    (0x0C07)

/**
 * Event sent when a Read Blob Response is received.
 * Data: Read Blob Response without opcode (Spec. Vol. 3 Part F, 3.4.4.6)
 */
#define EVT_ATT_READ_BLOB_RESP				    (0x0C08)

/**
 * Event sent when a Read Multiple Response is received.
 * Data: Read Multiple Response without opcode (Spec. Vol. 3 Part F, 3.4.4.8)
 */
#define EVT_ATT_READ_MULTIPLE_RESP			    (0x0C09)

/**
 * Event sent when a Read by Group Type Response is received.
 * Data: Read by Group Type Response without opcode (Spec. Vol. 3 Part F, 3.4.4.10)
 */
#define EVT_ATT_READ_BY_GROUP_RESP			    (0x0C0A)

/**
 * Event sent when a Write Response is received.
 * (Spec. Vol. 3 Part F, 3.4.5.2)
 */
#define EVT_ATT_WRITE_RESP					    (0x0C0B)

/**
 * Event sent when a Prepare Write Response is received.
 * Data: Prepare Write Response without opcode (Spec. Vol. 3 Part F, 3.4.6.2)
 */
#define EVT_ATT_PREPARE_WRITE_RESP			    (0x0C0C)

/**
 * Event sent when a Execute Write Response is received.
 * (Spec. Vol. 3 Part F, 3.4.6.4)
 */
#define EVT_ATT_EXEC_WRITE_RESP			        (0x0C0D)

/**
 * Event sent when a Handle Value Indication is received.
 * Data: Handle Value Indication without opcode (Spec. Vol. 3 Part F, 3.4.7.2)
 */
#define EVT_GATT_INDICATION				        (0x0C0E)

/**
 * Event sent when a Handle Value Notification is received.
 * Data: Handle Value Notification without opcode (Spec. Vol. 3 Part F, 3.4.7.1)
 */
#define EVT_GATT_NOTIFICATION				    (0x0C0F)

/**
 * Event sent when a GATT procedure is completed.
 * Data: One byte of status (see @ref tBleStatus).
 */
#define EVT_GATT_PROCEDURE_COMPLETE             (0x0C10)

/**
 * Event sent when an Error Response is received.
 * Data: Error Response without opcode (Spec. Vol. 3 Part F, 3.4.1.1)
 */
#define EVT_GATT_ERROR_RESP                     (0x0C11)

/**
 * Event sent when a Read By Type Response is received when discovering
 * characteristics by UUID or reading using characteristic UUID.
 * Data: Single handle-value pair like in Vol. 3 Part F, 3.4.4.2.
 */
#define EVT_GATT_DISC_READ_CHARAC_BY_UUID_RESP  (0x0C12)

/**
 * Event sent when there is a write request on an attribute and
 * GATT_INTIMATE_AND_WAIT_FOR_APPL_AUTH flag was set in the tGattServerEvent
 * mask for Gatt_Add_Characteristic() or Gatt_Add_Charac_Desc().
 * The application must reply with Gatt_Appl_Auth_For_Write() inside the callback
 * itself or asynchronously in the future.
 * @sa GATT_Server_CB().
 */
#define EVT_GATT_WRITE_PERMIT_REQ              (0x0C13)

/**
 * Event sent when there is a read request on an attribute and
 * GATT_SERVER_ATTR_READ flag was set in the tGattServerEvent
 * mask for Gatt_Add_Characteristic() or Gatt_Add_Charac_Desc().
 * The application has the chance to change the value before a response is sent
 * from the stack.
 * @sa GATT_Server_CB().
 */
#define EVT_GATT_ATTRIBUTE_READ_REQ		        (0x0C14)

/**
 * @}
 */

/**
 * Possible data when receiving an EVT_GATT_PROCEDURE_TIMEOUT.
 * See @ref EVT_GATT_PROCEDURE_TIMEOUT.
 */
#define SERVER_TIMEOUT_GATT                        (0x00)
#define CLIENT_TIMEOUT_GATT                        (0x01)

#endif /* __GATT_CLIENT_H__ */
