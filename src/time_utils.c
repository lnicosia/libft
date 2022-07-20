#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

suseconds_t		get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		perror("gettimeofday");
		return 0;
	}
	return (time.tv_sec * 1000000 + time.tv_usec);
}
