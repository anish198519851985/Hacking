#include <stdio.h>

struct list_{
	int x;
	struct list_ *next;
};

typedef struct list_ list;

int add(list **head,int no);
int delete(list **head,int position);
int print(list *head, int no);

void print_back(list *head);

int print(list *head, int no);
int search(list *first, list *end, int no_found)
{
	list *fast = first;
	list *slow = first;
	list *mid = first;	
	list *b4mid;	
	int found = 0;
	printf("\nfirst = %d, End = %d", first->x, end->x);
	while(first != end && first->next != end)
	{
		fast = fast->next->next;
		b4mid = slow;
		slow = slow->next;
	}
	printf("\nfirst = %d, Mid = %d,End = %d", first->x, slow->x, end->x);
	mid = slow;
	if(mid->x < no_found)
	{
		if(no_found < first->x || no_found > end->x )
		{
			printf("out of range\n");
			found = 0;
		} else
			found += search(mid->next, fast, no_found);
	} else if(mid->x > no_found){
		if(no_found < first->x)
		{
			printf("out of range\n");
			found = 0;
		} else
			found += search(first, b4mid, no_found);
	} else if(mid->x == no_found){
		printf("none found");
		found = 1;
	} else
		found = 0;
	return found;
}

int binary_search(list *local, int no_found)
{
	list *first = local;
	list *end = local;
	list *b4mid;
	list *mid;
	int found = 0;
	while(end && end->next)
	{
		end = end->next->next;
		b4mid = first;
		first = first->next;
	}
	mid = first;
	printf("\nmid = %d, End = %d", first->x, end->x);
	if(no_found < first->x) 
	{
		if(no_found < local->x)
			found = 0;
		else
			found = search(local, b4mid, no_found);
	}
	else if(no_found > first->x) {
		if(no_found < local->x)
			found = 0;
		else
			found = search(first->next, end, no_found);
	}else if(first->x == no_found) {
		printf("found the data\n");
		found = 1;
	}
}

main()
{
	list *head = NULL;
	int i = 0;int found;
	while(i++ < 9)
		add(&head, i);
	print_back(head);
	printf("enter the search number \n");
	scanf("%d", &i);
	found = binary_search(head, i);
	if(found)
		printf("*******found*********\n");
	else
		printf("*******not found*****\n");
}

int add(list **head,int no)
{
	list *temp,*head_ref;
	head_ref = *head;
	temp = malloc(sizeof(struct list_));
	temp->x = no;
	temp->next = NULL;
	if(*head == NULL){
		*head = temp;
	} else {
		while(head_ref->next != NULL)
		{
			head_ref = head_ref->next;
		}	
		head_ref->next = temp;
	}	
	return 0;
}


int delete(list **head,int position){
	list *temp,*head_ref = *head;
	int data;

	if(*head == NULL)
	{
		printf("there is notthing to delete\n");
		return 0;
	} else {

		if(position == 1) {
			temp = *head;
			*head = (*head)->next;
			data = temp->x;
			free(temp);
		} else {
			while(head_ref != NULL && --position){
				temp = head_ref;			
				head_ref = head_ref->next;
			}
			if(head_ref == NULL && position) {
				printf("the position is big\n");
				return 0;
			}
			if(!position) {
				temp->next = head_ref->next;
				data = head_ref->x;
				free(head_ref);	 
			}
		}
	}
	return data;
}

void print_back(list *head)
{
	if(!head)
		return;
	print_back(head->next);
	printf("list data%d\n", head->x);
}

int print(list *head, int no)
{
	while(head != NULL)
	{
		printf("list no %d \n",head->x);	
		head = head->next;
	}
	return 0;
}
