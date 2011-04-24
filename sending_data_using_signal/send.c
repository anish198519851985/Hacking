#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

#define L SIGHUP
#define H SIGUSR1
#define RESET SIGUSR2

void die(char *s)
{
	perror(s);
	exit(errno);
}

int main(int argc, char **argv)
{
	int pid, fd, j;
	char *file, c;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <pid> <file>\n", argv[0]);
		exit(1);
	}

	pid = atoi(argv[1]);
	file = argv[2];

	if ((fd = open(file, O_RDONLY)) < 0)
		die("open");	


	kill(pid, RESET);
	sleep(1);
	
	while (read(fd, &c, sizeof(c)) > 0) {

		/* and for every bit of this byte do */
		for (j = 7; j >= 0; --j) {
			if ((1<<j) & c) {
				printf("1");fflush(stdout);
				if (kill(pid, H) < 0)
					die("kill");	/* send HIGH (1) */
			} else {
				printf("0");fflush(stdout);
				if (kill(pid, L) < 0)	/* send LOW (0) */
					die("kill");
			}
			usleep(200);
		}
	}
	close(fd);
	return 0;
}


