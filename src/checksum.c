#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

uint16_t	checksum(void *ptr, int len)
{
	uint16_t	*buf = (uint16_t*)ptr;
	size_t		sum = 0;
	uint16_t	res = 0;
	
	for ( ; len > 1 ; len -= 2)
	{
		sum += *buf;
		buf++;
	}
	if (len == 1)
		sum += *(uint8_t*)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	res = (uint16_t)~sum;
	return res;
}
