#include <stdio.h>
struct link_{
	int data;
	struct link_ *next;
};

typedef struct link_ link;

void add(link **ptr, int no)
{
	if(*ptr == NULL) {
		link *temp;
		temp = malloc(sizeof(*temp));
		temp->data = no;
		temp->next = NULL;
		*ptr = temp;
	} else {
		link *temp = *ptr;
		link *fill = malloc(sizeof(*fill));
		fill->data =  no;
		fill->next = NULL;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = fill;
	}
}

void print(link *head)
{
	printf("****************************");
	while(head != NULL)
	{
		printf("\n%d\n",head->data);
		head = head->next;
	}
	printf("****************************");
}

link* reverse(link *head)
{
	link *temp;
	link *previous = NULL;
	while(head !=  NULL)
	{
		temp = head->next;
		head->next =  previous;
		previous = head;
		head = temp;
	}	
	return previous;
}

void binary(int x)
{
	int temp = x/2;
	int mul = 1;
	int sum = 0;
	while(x)
	{
		temp = x%2;
		temp = temp*mul;
		sum = sum + temp;
		mul = mul*10;
		x = x/2;
	}
	printf("binary --- %d\n",sum);
}

main()
{
	link *head = NULL;
	link *temp = NULL;
	add(&head, 1);
	add(&head, 2);
	add(&head, 3);
	add(&head, 4);
	print(head);
	temp = reverse(head);
	print(temp);
	binary(100);
}
