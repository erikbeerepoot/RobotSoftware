#include "globals.h"

typedef enum GyroSampleRate {
	GYRO_SAMPLERATE_200HZ = 1,
} GyroSampleRate;

typedef enum AccelSampleRate {
	ACCEL_SAMPLERATE_200HZ = 1,
} AccelSampleRate;

struct MotionSensorConfig {
		AccelSampleRate 	accelSampleRate;
		GyroSampleRate 		gyroSampleRate;
};

status_code_t MotionSensor_Intialize(struct MotionSensorConfig *config);