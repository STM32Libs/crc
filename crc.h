#ifndef __CRC__
#define  __CRC__

#include "mbed.h"

namespace crc
{

    uint16_t calculate( uint8_t const *data, uint8_t count );
    // size(size+data) : data : crc
    bool check(uint8_t const *data);

    void set(uint8_t *data);
}

#endif /*__CRC__*/