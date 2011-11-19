#include <stdio.h>
struct a{
	int a;
	char b;
};

void show_doublepointer(void);
void foo(int (*b)[3]);
void character_doublepointer_to_const_doublepointer(void);
main()
{
	int a[] = {0};
	int b[2][3] = {1,2,3,
		4,5,6};
	int *p[3]; //array of integer pointers
	int (*q)[3];q = &b[0]; //pointer to an integer array
	p[0] = &a[0];
	p[1] = &a[0];
	p[2] = &a[0];
	printf("%d %d %d \n",*p[0],*p[1],*p[2]);
	foo(&b[0]);
	show_doublepointer();
	character_doublepointer_to_const_doublepointer();
}

void foo(int (*b)[3])
{
	printf("%d \n",b[0][0]);
}

void show_doublepointer(void)
{
	char **s;
	char *t[] = {
		"foreground",
		"background",
		"warning-range",
		"error-range",
		"ok-range",
		NULL  
	};

	s = t;

	while(*s){
		printf("%s\n",*s);
		s++;
	}
	int i;
	for(i = 0;i < sizeof t/sizeof *t && t[i] != NULL;i++)
		printf("%s\n",t[i]);
}

/*http://c-faq.com/ansi/constmismatch.html*/
void character_doublepointer_to_const_doublepointer(void)
{
const char i = 'a';
char *p1;                      
const char **p2 = (const char **)&p1;
*p2 = &i;
*p1 = 'b';
printf("%c\n", i); 
}

