#include <stdint.h>

#include "globals.h"

//hardware fn prototypes
status_code_t mpu_receive(uint8_t *buffer,int bufferSize,int receiveLength);
status_code_t mpu_transmit(uint8_t *buffer, int bufferLength);
