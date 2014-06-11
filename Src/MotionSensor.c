#include "MotionSensor.h"

#include <stdint.h>

#define MPU_ID					0x70


#define IMU_INT 				PIN1
#define IMU_SPI_NSS			PIN12
#define IMU_SPI_SCK			PIN13
#define	IMU_SPI_MISO		PIN14
#define IMU_SPI_MOSI		PIN15

status_code_t MotionSensor_Initialize(struct MotionSensorConfig *config){
	status_code_t status = STATUS_OK;

	return status;
}

/**
 * \name	imu_sanity_check
 * \brief	Simple check that reads a static register to validate IMU operation
 * \param	none
 */

status_code_t imu_sanity_check(){
	uint8_t buffer[2] = {0};

	//queue op and check if it succeeds
	status_code_t status = mpu_receive(buffer,1);
	if(status!=STATUS_OK) return status;

	//check results
	return (buffer[0]==MPU_ID) ? STATUS_OK : ERR_BAD_DATA;

}

