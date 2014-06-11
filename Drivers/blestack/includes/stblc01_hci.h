/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : stblc01_hci.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Header file with HCI commands for STBLC01.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#ifndef __STBLC01_HCI_H__
#define __STBLC01_HCI_H__


/**
 * \defgroup hw_error_codes Hardware Error Codes
 *
 * Hardware Codes received with the HCI_HARDWARE_ERROR event.
 *
 * @{
 */
#define NO_ERR        0x00
#define HCI_SYNC_LOST 0x01
#define RF_INIT_FAIL  0x02
#define NO_PLL_LOCK   0x03
#define CPU_RST       0x04
#define DEV_NOT_PROG  0x80
/** @} */

/**
 * This function sends an HCI_STBLC_WRITE_DATA command, used to
 * write inside STBLC01 registers. Usually this function is not needed by the
 * user.
 *
 * @param[in] buffer     Pointer to a buffer wich contains:
 *                       Address (2 bytes, little endian)
 *                       Data
 * @param[in] len        Buffer length
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_write_data(const uint8_t *buffer, uint8_t len);

/**
 * This function sends an HCI_STBLC_READ_DATA command, used to
 * read from STBLC01 registers. Usually this function is not needed by the
 * user.
 *
 * @param[in] address    Address (2 bytes, little endian)
 * @param[in] count      length of data to read
 * @param[in] buffer     Pointer to a buffer which will contain read data. Must
 *                       be count+1 in size since the buffer is used for buffering
 *                       all received data.
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_read_data(uint16_t address, uint8_t count, uint8_t *buffer);

/**
 * This function sends an HCI_STBLC_SET_PUBLIC_ADDRESS command, used to
 * set the bluetooth address of the device.
 *
 * @param[in] bdaddr     Bluetooth address
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_set_public_address(const tBDAddr bdaddr);

/**
 * This function sends an HCI_STBLC_SET_POWER MODE command, used to
 * put the controller in one of the three power states.
 *
 * @param[in] mode     One of the possible power modes:
 *                          0x00 = Idle
 *                          0x01 = Sleep
 *                          0x02 = Off
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_set_power_mode(uint8_t mode);

/**
 * This function sends an HCI_STBLC_SVLD_MEASUREMENT command, used to
 * detect if the voltage from power source is below a given level.
 *
 * @param[in] level     voltage threshold
 * @param[in] source    source of measurement
 * @param[out] result   measurement result:
 *                          0x00 = voltage is above the level
 *                          0x01 = voltage is below the level
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_svld_measurement(uint8_t level, uint8_t source, uint8_t* result);


/**
 * This function sends an HCI_STBLC_SET_RF_POWER_LEVEL command, used to
 * change the output power level.
 *
 * @param[in] level     output power level:
 *                          0x00 = -20 dBm
 *                          0x01 = -16 dBm
 *                          0x02 = -12 dBm
 *                          0x03 = -9 dBm
 *                          0x04 = -6 dBm
 *                          0x05 = -3 dBm
 *                          0x06 = 0 dBm
 *                          0x07 = +4 dBm
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_set_rf_power_level(uint8_t level);

/**
 * This function sends an HCI_STBLC_POWER_MODE_CONFIGURATION command, used to
 * enable automatic transition to BLE Sleep mode for extremely low power
 * consumption.
 *
 * @param[in] sleep_mode_enable     enable/disable transition to BLE Sleep mode:
 *                                      0: disabled
 *                                      1: enabled
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_power_mode_configuration(uint8_t sleep_mode_enable);

/**
 * This function sends an HCI_STBLC_SET_UART_BAUD_RATE command, used to change
 * the UART baudrate. If needed it's advised to use this command only at startup.
 *
 * @param[in] baud_rate     one of the allowed baudrates:
 *                              0x00 = 1200 Bd
 *                              0x01 = 2400 Bd
 *                              0x02 = 4800 Bd
 *                              0x03 = 9600 Bd
 *                              0x04 = 14400 Bd
 *                              0x05 = 19200 Bd
 *                              0x06 = 28800 Bd
 *                              0x07 = 38400 Bd
 *                              0x08 = 57600 Bd
 *                              0x09 = 76800 Bd
 *                              0x0A = 115200 Bd
 *                              0x0B = 230400 Bd
 *                              0x0C = 460800 Bd
 *                              0x0D = 921600 Bd
 *                              0x0E = 1843200 Bd
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_set_uart_baud_rate(uint8_t baud_rate);

/**
 * This function writes a row of firmware into the device RAM.
 *
 * @param[in] row           row number (from 0 to 63)
 * @param[in] sector        sector number (from 0 to 17)
 * @param[in] cache_Bxx     Buffer containing the 2 last significant bytes of each word
 *                          of a row (32 bytes, LSB first)
 * @param[in] cache_MSBBxx  Buffer containing the most significant byte of each word
 *                          of a row (16 bytes)
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_write_program(uint8_t row, uint8_t sector, uint8_t cache_Bxx[32], uint8_t cache_MSBBxx[16]);

/**
 * This function calculate the CRC-16/CCITT of the portion of firmware that is loaded
 * into the RAM starting from start_address till stop_address.
 *
 * @param[in] start_address     start address for CRC calculation (number of
 *                                  word, i.e. 3 bytes)
 * @param[in] stop_address      stop address for CRC calculation (number of
 *                                  word, i.e. 3 bytes)
 * @param[out] crc              CRC-16/CCITT calculated from start_address to
 *                              stop_address
 *
 *
 * @return  0 if successful, -1 otherwise.
 */
int hci_stblc_calc_crc_code(uint16_t start_address,	uint16_t stop_address, uint16_t * crc);

/**
 * This function return the last hardware error received by the controller.
 *
 * @return  0 if no error has been received from the last call, otherwise one of the
 *          hardware error codes (@ref hw_error_codes "Hardware Error Codes")
 */
uint8_t get_last_hw_err(void);

#endif /* __STBLC01_HCI_H__ */
