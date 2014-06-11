/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : link_layer.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Header file for link layer. It contains definition of
*                      functions for link layer, most of which are mapped to
*                      HCI commands.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#ifndef _LINK_LAYER_H
#define _LINK_LAYER_H

#include <ble_status.h>

/******************************************************************************
 * Types
 *****************************************************************************/

/**
 * advertising policy for filtering (white list related) 
 */
typedef tHalUint8   tAdvPolicy;
#define NO_WHITE_LIST_USE           (0X00)
#define WHITE_LIST_FOR_ONLY_SCAN    (0X01)  
#define WHITE_LIST_FOR_ONLY_CONN    (0X02)
#define WHITE_LIST_FOR_ALL          (0X03) 

/**
 * Bluetooth 48 bit address (in little-endian order).
 */
typedef	tHalUint8	tBDAddr[6];


/** 
 * Bluetooth address type
 */
typedef tHalUint8       tAddrType; 
#define RANDOM_ADDR     (1)
#define PUBLIC_ADDR     (0)

/** 
 * Advertising type
 */
typedef tHalUint8       tAdvType;
/**
 * undirected scannable and connectable 
 */ 
#define ADV_IND         (0x00)

/** 
 * directed non scannable
 */
#define ADV_DIRECT_IND  (0x01)

/**
 * scannable non connectable
 */
#define ADV_SCAN_IND    (0x02)

/**
 * non-connectable and no scan response (used for passive scan)
 */
#define ADV_NONCONN_IND (0x03)


/* 0X04-0XFF RESERVED */


/** 
 * lowest allowed interval value for connectable types(20ms)..multiple of 625us
 */
#define ADV_INTERVAL_LOWEST_CONN    (0X0020)

/** 
 * highest allowed interval value (10.24s)..multiple of 625us.
 */
#define ADV_INTERVAL_HIGHEST        (0X4000)

/** 
 * lowest allowed interval value for non connectable types
 * (100ms)..multiple of 625us.
 */
#define ADV_INTERVAL_LOWEST_NONCONN (0X00a0)

/** 
 * Default value of advertising interval for both min/max values.
 * This will be used if host does not specify any advertising parameters 
 * including advIntervalMax and advIntervalMin
 * value = 1.28 sec (in units of 625 us)
 */
#define ADV_INTERVAL_DEFAULT        (0x0800)

#define ADV_CH_37 0x01
#define ADV_CH_38 0x02
#define ADV_CH_39 0x04

/**
 * advertising parameters
 */
typedef struct _LLAdvParams
{
    tHalUint16  advIntervalMin; 
    tHalUint16  advIntervalMax;
    tAdvType    advType;
    tHalUint8   advChannelMap; 
    tAdvPolicy  advFilterPolicy;
    tAddrType   ownAddrType;
    tAddrType   directAddrType;
    tBDAddr     directAddr;
}tLLAdvParams;

/******************************************************************************
 * Function Prototypes
 *****************************************************************************/

/* LL_SAP API*/

/**
 * 
 * This function initializes the Link Layer. It must be called only 
 * once during system initialization. Once this is called
 * link layer initializes its structures.
 * 
 */
void  LL_Init(void);

/**
 * This function must be called from the main loop at least once after a packet
 * is received from the controller.
 */ 
void LL_Process(void);

/**
 * Perform a link layer reset.
 * 
 */
void LL_Reset(void);


/* Advertising related APIs*/

/**
 * Get the current advertising parameters previously set with LL_Set_Adv_Params.
 *
 * @param[in] pAdvParams pointer to advertising parameter structure
 *
 */
void LL_Get_Adv_Params(tLLAdvParams* pAdvParams);

/**
 * This function sets advertising parameters.
 * @param[in] pAdvParams pointer to advertising parameter structure
 * 
 * @return  tBleStatus parameter indicating success or error.
 */
tBleStatus  LL_Set_Adv_Params(tLLAdvParams* pAdvParams); 

/**
 * This function sets advertising data.
 * 
 * @param[in] pAdvData       advertising data
 * @param[in] hostDataLen   length of advertising data.
 * 
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus  LL_Set_Adv_Data(const tHalUint8 *pAdvData, tHalUint8 hostDataLen);

/**
 * Get the current advertising data previously set with LL_Set_Adv_Data. 
 * 
 * @param[in] pAdvData       pointer to advertising data
 * @param[in] pHostDataLen   length of data.
 * 
 */
void  LL_Get_Adv_Data(tHalUint8 *pAdvData, tHalUint8* pHostDataLen);

/**
 * This function sets scan response data.
 * 
 * @param[in] pScanRespData Scan response data
 * @param[in] length        Length of data.
 * 
 * @return tBleStatus parameter indicating success or error code
 */ 
tBleStatus  LL_Set_Scan_Resp_Data(tHalUint8 *pScanRespData, tHalUint8 length);

/**
 * This function enables or disables advertising.
 * 
 * @param[in] enable Enable advertising if TRUE, disable if FALSE.
 * 
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus  LL_Enable_Disable_Adv(tHalBool enable);

/**
 * This function enables or disables advertising.
 * 
 * @param[out] plevel  Power level in dBm (form -20 to 10, accuracy +/- 4 dBm)
 * 
 * @return returns error code given by tBleStatus
 * 
 */
tBleStatus LL_Get_Adv_Tx_Power_Level(tHalInt8* plevel);

/**
 * It gives transmitter power level used for specific connection handle (ACL link)
 *
 * @param[in]  pConnHandle Connection Handle from which power reading is required
 * @param[in]  type        type of power level reading (0: current, 1: maximum)
 * @param[out] pLevel      power level in dBm (-30 to 20 )
 * @param[out] pConnHandle connection handle which is used for power reading
 * 
 * @return returns error code given by tBleStatus
 * 
 */
tBleStatus LL_Get_Link_Tx_Power_Level(tHalUint16* pConnHandle, 
                                      tHalUint8 type, tHalInt8* pLevel);

/**
 * It reads RSSI value for reception.
 *
 * @param[out] rssiVal RSSI value
 * 
 * @return returns error code given by tBleStatus
 */
tBleStatus LL_Read_RSSI(tHalInt8* rssiVal);

/*white list APIs*/

/**
 * It returns size of maximum possible entries that can be stored in white list.
 * 
 * @return maximum white list size (statically fixed)
 */
tHalUint8   LL_Get_White_List_Size(void); 

/**
 * It flushes all entries in white list making it empty.
 * 
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus  LL_White_List_Flush(void);

/**
 * Addds device to white list
 *
 * @param[in] addrType address type
 * @param[in] addr     48 bit address
 * 
 * @return tBleStatus parameter indicating success or error code
 */ 
tBleStatus  LL_Add_To_White_List(tAddrType addrType, tBDAddr addr );

/**
 * Removes device from white list
 * 
 * @param[in] addrType address type
 * @param[in] addr     48 bit address
 * 
 * @return tBleStatus parameter indicating success or error code
 */   
tBleStatus  LL_Remove_From_White_List(tAddrType addrType, tBDAddr addr);

/*------------- Connection state APIs ------------- */

/**
 * Disconnects the physical link
 * 
 * @param[in] connHandle    Connection handle for the link to be disconnected
 * @param[in] reason        8 bit error code indicating reason to disconnect
 * 
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus  LL_Disconnect_Link(tHalUint16 connHandle, tHalUint8 reason );

/**
 * It returns the channel map of used and unused channels for given connection 
 * indicated by connhandle.
 * 
 * @param[in]   connHandle    Connection handle for current connection
 * @param[out]  channelMap    bit map of 37 bits indicating used/unused channels
 *            
 * @return tBleStatus parameter indicating success or error code
 */	
tBleStatus  LL_Get_Channel_Map(tHalUint16 connHandle, tHalUint8 channelMap[5]);
 
 
/*------------- Local Parameters APIs ------------- */


/**
 * requests link layer to get information about currently supported features. 
 * Currently featureset includes only encryption support as feature parameter.
 *
 * @param[out]   feature    fetureset (64 bit)
 *            
 */
void LL_Get_Supported_Features(tHalUint8 feature[8]);

/**
 * Encrypts plain text data using AES encryption with given input key and 
 * 128 bit block size. 
 * 
 * @param[in]   key         Encryption key to be used
 * @param[in]   textData    text data to be encrypted
 * @param[out]  textDataOut text data buffer that will contain 
 * encrypted data after this procedure is successful
 *            
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus  LL_Encrypt_Plain_Data(tHalUint8 key[16],tHalUint8 textData[16],tHalUint8 textDataOut[16]);

/**
 * Gets random data (128 bit) to be used for other procedures.
 *
 * @param[out]  randData    128 bit random data
 * 
 * @return tBleStatus parameter indicating success or error code
 */
tBleStatus  LL_Get_Random_data(tHalUint8 randData[8]);

 /**
 * Gets link layer supported states and state combinations
 *
 * @param[out]  states    link layer supported states and state combinations
 *           
 */
void  LL_Get_Supported_States(tHalUint8 states[8]);

 /**
 * Sets bluetooth device address. Public address is set only once.
 *
 * @param[in]   address  48 bit bluetooth device address to be set
 * @param[in]   addrType bluetooth address type (random/public)       
 * 
 * @return tBleStatus parameter indicating success or error code          
 */
tBleStatus  LL_Set_Address(tBDAddr address, tAddrType addrType);

 /**
 * Gets bluetooth device address.
 *
 * @param[in]   address  48 bit bluetooth device address to be obtained
 * @param[in]   addrType bluetooth address type (random/public)
 * 
 * @return tBleStatus parameter indicating success or error code          
 */
tBleStatus  LL_Get_Address(tHalUint8* address, tAddrType* addrType);

/**
 * returns the random address for the device.
 *
 * @param[out]  randBdAddr  Random
 * address for the device.
 */
void LL_Get_Random_Addr(tHalUint8 *randBdAddr);

/*------------- test functions------------- */

 /**
 * It starts receiver test
 *
 * @param[in]   rxFreq  frequency at which test is to be done
 * 
 * @return tBleStatus parameter indicating success or error code          
 */
tBleStatus  LL_Test_Receiver(tHalUint8 rxFreq);

 /**
 * It starts transmitter test with given parameters.
 *
 * @param[in]   txFreq  frequency at which data is to be transmitted
 * @param[in]   length  length of payload data in bytes used for testing 
 * for each packet
 * @param[in]   payload packet payload type indicating specific pattern of test
 *         
 * @return tBleStatus parameter indicating success or error code  
 */
tBleStatus  LL_Test_Transmitter(tHalUint8 txFreq, tHalUint8 length, 
                                tHalUint8 payload);
                               
/**
 * It stops given transmission/reception test.
 *         
 * @return returns the number of packets transmitted or received.
 */                            
tHalUint16  LL_Test_Stop(void);


 /**
 * Callback function. It will be called on reception of an Hardware Error event
 * from the controller.
 *
 * @param[in]   hwErr  Hardware error code.
 *
 */
void LL_Hardware_Error_CB(tHalUint8 hwErr);


#endif /* _LINK_LAYER_H */