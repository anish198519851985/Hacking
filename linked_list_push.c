#include <stdio.h>
struct list_{
int x;
struct list_ *next;
};

typedef struct list_ list;
void add(list **head,int no);
int delete(list **head,int position);
int pop(list *head);
void push(list **head,int number);
void print(list *head);

main()
{
	list *head = NULL;
	int number,no;
	#if 0
	printf("enter the number \n",number);
	scanf("%d",&number);
	printf("%d \n",number);
		while(number--){
			printf("push \n");
			scanf("%d",&no);
			push(&head,no);
		}
	pop(head);
	#endif

	printf("enter the number \n",number);
	scanf("%d",&number);
		while(number--){
			printf("adding \n");
			scanf("%d",&no);
			add(&head,no);
		}

print(head);
{
	int x;
	printf("which element you want to delete \n");
	scanf("%d",&x);
	x = delete(&head,x);
	printf("deleted item %d \n",x);
}
	print(head);
}

void push(list **head,int number)
{
	list *temp,*head_ref;
	head_ref = *head;
	temp = malloc(sizeof(struct list_));
	temp->x = number;
	temp->next = *head;
	*head = temp;	
}


int pop(list *head)
{
	while(head != NULL)
	{
		printf("pop %d \n",head->x);	
		head = head->next;
	}
}

void add(list **head,int no)
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

void print(list *head)
{
	printf("%s \n",__func__);
	while(head != NULL)
	{
		printf("list no %d \n",head->x);	
		head = head->next;
	}
}
