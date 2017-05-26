
#include "crc.h"

namespace crc
{
uint16_t calculate( uint8_t const *data, uint8_t count )
{
	uint16_t sum1 = 0;
	uint16_t sum2 = 0;
	int index;

	for( index = 0; index < count; ++index )
	{
		sum1 = (sum1 + data[index]) % 255;
		sum2 = (sum2 + sum1) % 255;
	}

	return (sum2 << 8) | sum1;
}

// size(size+data) : data : crc
bool check(uint8_t const *data)
{
	bool result = 1;
	uint8_t size = data[0];
	uint16_t crc = crc_Fletcher16(data,size);//check the data without excluding the crc
	if( (data[size] != (crc >> 8) ) || (data[size+1] != (crc & 0xFF) ) )
	{
		result = 0;
	}
	return result;
}

}
