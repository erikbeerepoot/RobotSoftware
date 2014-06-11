/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : hal_types.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : This header file defines the basic data types used by the
*                       BLE stack.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/
#ifndef __HAL_TYPES_H__
#define __HAL_TYPES_H__

#include <stdint.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Byte order conversions */
#if __BYTE_ORDER == __LITTLE_ENDIAN
#define htobs(d)  (d)
#define htobl(d)  (d)
#define btohs(d)  (d)
#define btohl(d)  (d)
#elif __BYTE_ORDER == __BIG_ENDIAN
#define htobs(d)  bswap_16(d)
#define htobl(d)  bswap_32(d)
#define btohs(d)  bswap_16(d)
#define btohl(d)  bswap_32(d)
#else
#error "Unknown byte order"
#endif

/**
 * Integer type : Machines natural word size
 */ 
typedef int tHalInt;  

/** 
 * Unsigned Integer type : Machines natural word size
 */
typedef unsigned int tHalUint; 

/** 
 * signed 32-bit
 */
typedef int tHalInt32;

/** 
 * unsigned 32-bit
 */
typedef unsigned int tHalUint32;

/**
 * signed 16-bit
 */
typedef short tHalInt16;

/** 
 * unsigned 16-bit
 */
typedef unsigned short tHalUint16;

/** 
 * signed 8-bit
 */
typedef  signed char tHalInt8;

/** 
 * unsigned 8-bit
 */
typedef unsigned char tHalUint8;

/** 
 * Boolean: smallest value.
 */
typedef char tHalBool;

#ifndef TRUE 
#define TRUE (1)
#endif

#ifndef FALSE
#define FALSE (0)
#endif


/**Sleep request flags.
 * Each layer sets its corresponding flag
 * when its processing is complete and it is
 * ready to go to sleep.
 */ 
#define ACI_DEEP_SLEEP_REQ						(0x01)
#define GATT_DEEP_SLEEP_REQ						(0x02)
#define SM_DEEP_SLEEP_REQ						(0x04)
#define ACL_DEEP_SLEEP_REQ                      (0x08)
#define LL_DEEP_SLEEP_REQ                       (0x10)

#define ALL_LAYER_DEEP_SLEEP_REQ			    (GATT_DEEP_SLEEP_REQ | \
                                                 SM_DEEP_SLEEP_REQ | \
                                                 LL_DEEP_SLEEP_REQ | \
                                                 ACL_DEEP_SLEEP_REQ )


#endif /* __HAL_TYPES_H__ */ 

