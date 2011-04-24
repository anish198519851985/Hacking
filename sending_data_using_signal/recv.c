#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

#define L SIGHUP
#define H SIGUSR1
#define RESET SIGUSR2

int bit;
unsigned char c;

void recv_high_low(int x)
{
	if (bit == 8) {
		bit = 0;
		putchar(c);
		fflush(stdout);
		c = 0;
	}
	if (x == H)
		c = ((c<<1)|1);
	else
		c <<= 1;
	++bit;
}

void recv_reset(int x)
{
	bit = 0;
	c = 0;
}

int main()
{
	bit = 0;
	c = 0;
	
	signal(L, recv_high_low);
	signal(H, recv_high_low);
	signal(RESET, recv_reset);
	
	for (;;);

	return 0;
}


