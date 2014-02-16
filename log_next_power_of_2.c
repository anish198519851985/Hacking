#include <stdio.h>

int log[256];

int foo(int no)
{
	int t, tt, r;
	if(tt = no>> 16) {
		r = (t = tt >> 8)?24+log[tt]:16+log[t];
	} else {
		r = (t = no >> 8)?8+log[t]:log[no];
	}
	return r;
}

void make_table()
{
	int i;

	log[0] = 0;
	log[1] = 1;
	for(i=2;i<256;i++) {
		log[i] = 1 + log[i/2];
	}
}

int main()
{
	int no = 512;
	make_table();
	printf ("%d\n", foo(no));
}
