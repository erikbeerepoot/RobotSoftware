/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : osal.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : This header file defines the OS abstraction layer used by
*                      the BLE stack. OSAL defines the set of functions
*                      which needs to be ported to target operating system and
*                      target platform.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#ifndef __OSAL_H__
#define __OSAL_H__

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <hal_types.h>
#include <intrinsics.h>

/******************************************************************************
 * Macros
 *****************************************************************************/

#define ENABLE_INTERRUPT( )   {__enable_interrupt();}

#define DISABLE_INTERRUPT( )   {__disable_interrupt();}


/******************************************************************************
 * Function Prototypes
 *****************************************************************************/

/**
 * This function copies size number of bytes from a 
 * memory location pointed by src to a destination 
 * memory location pointed by dest
 * 
 * @param[in] dest Destination address
 * @param[in] src  Source address
 * @param[in] size size in the bytes  
 * 
 * @return  Address of the destination
 */
 
extern void* Osal_MemCpy(void *dest,const void *src,tHalUint size);


/**
 * This function sets first number of bytes, specified
 * by size, to the destination memory pointed by ptr 
 * to the specified value
 * 
 * @param[in] ptr    Destination address
 * @param[in] value  Value to be set
 * @param[in] size   Size in the bytes  
 * 
 * @return  Address of the destination
 */
 
extern void* Osal_MemSet(void *ptr, tHalInt value,tHalUint size);

/**
 * This function compares the first number of 
 * block of memory specified by the source
 * address src1 and src2
 * 
 * @param[in] src1  Address of source #1
 * @param[in] src2  Address of source #2
 * @param[in] size  Number of bytes to compare  
 * 
 * @return  Zero, if both the memory locations are equal 
 *          A value greater than zero if these two locations
 *          are not equal
 */
 
extern tHalInt Osal_MemCmp(const void *src1, const void *src2, tHalUint size);

/**
 * Copies a C string pointed src to a destination string 
 * pointed by dest. Destination array should be long enough
 * to hold the same string as pointed by src. Function does 
 * not check for array boundary overflows
 * 
 * @param[in] dest  Address of destination string
 * @param[in] src   Address of source string
 *  
 * @return  Destination address
 */
 
extern char* Osal_StrCpy(char *dest, const char *src);

/**
 * Returns the size of the string in bytes
 * pointed by str. Function expects
 * that str string is NULL terminated.
 * 
 * @param[in] str   Address of the string
 *  
 * @return  Size of the string
 */
 
extern tHalUint Osal_StrLen(const char *str);

#endif /* __OSAL_H__ */
