#include <stdio.h>
#include <stddef.h>

struct list_{
	struct list_ *next;
	int x;
};

struct list_1{
	struct list_1 *next;
	double x;
};

struct genericlist {struct genericlist *e_link;};
typedef struct list_ list;
typedef struct list_1 list1;

void add(list **head,int no);
void add1(list1 **head1,int no);
#define list1Length(list) (genericlistLength((struct genericlist*)list))
#define list2Length(list) (genericlistLength((struct genericlist*)list))

void print(list *head);
void print1(list1 *head);
int genericlistLength(struct genericlist *list)
{
	int count = 0;
	struct genericlist *temp = list;
	printf("%s\n", __func__);
	while(temp != NULL)
	{
		count++;
		temp = temp->e_link;
	}		
	return count;
}

size_t listLength(const void *anyList, size_t linkOffset) {
	size_t count = 0;
	while (anyList != NULL) {
		printf("%s %p\n", __func__, anyList);
		anyList = *(struct kk**)((char *)anyList + linkOffset);
		printf("after %s %p \n", __func__, anyList);
		count++;
	}
	return count;
} 

main()
{
	list *head = NULL;
	list1 *head1 = NULL;
	int number,no;

	printf("enter the number \n",number);
	scanf("%d",&number);
	while(number--){
		printf("adding \n");
		scanf("%d",&no);
		add(&head,no);
	}
	printf("enter the number for second list \n",number);
	scanf("%d",&number);
	while(number--){
		printf("adding \n");
		scanf("%d",&no);
		add1(&head1,no);
	}	
	print(head);
	print1(head1);
	printf("count for list first %d\n", list1Length(head));
	printf("count for list second %d\n", list2Length(head1));

	{
		size_t length = listLength(head,
					offsetof(struct list_, next));
		printf("offset way %d\n", length);
		size_t census = listLength(head1,
					offsetof(struct list_1, next)); 
		printf("offset way %d\n", census);
	}

}

void add(list **head,int no)
{
	list *temp,*head_ref;
	head_ref = *head;
	temp = malloc(sizeof(struct list_));
	temp->x = no;
	temp->next = NULL;
	if(*head == NULL)
		*head = temp;
	else {
		while(head_ref->next != NULL)
			head_ref = head_ref->next;
		head_ref->next = temp;
	}	
}

void add1(list1 **head,int no)
{
	list1 *temp;list1 *head_ref;
	head_ref = *head;
	temp = malloc(sizeof(struct list_1));
	temp->x = no;
	temp->next = NULL;
	if(*head == NULL)
		*head = temp;
	else {
		while(head_ref->next != NULL)
			head_ref = head_ref->next;
		head_ref->next = temp;
	}	
}

void print(list *head)
{
	printf("%s \n",__func__);
	while(head != NULL)
	{
		printf("list no %p \n",head);	
		head = head->next;
	}
}
void print1(list1 *head)
{
	printf("%s \n",__func__);
	while(head != NULL)
	{
		printf("list no %p \n",head);	
		head = head->next;
	}
}
