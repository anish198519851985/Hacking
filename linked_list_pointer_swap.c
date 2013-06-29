#include <stdio.h>

struct node_{
	int data;
	struct node_ *next;
};

typedef struct node_ node;
node *head = NULL;

int add(node **head,int no)
{
	node *temp,*head_ref;
	head_ref = *head;
	temp = malloc(sizeof(struct node_));
	temp->data = no;
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

void print(node *head)
{
	while(head != NULL)
	{
		printf("node no %d \n",head->data);	
		head = head->next;
	}
}

/* this should be used only for linkedlist first and second node */
void swap_(node **first, node **second)
{
	node *temp1 = *first;
	node *temp2 ;
	*first = (*second);
	temp2 = (*second)->next;
	(*second)->next = temp1;
	temp1->next = temp2;
}

/* this should used for swapping any node except first and second node */
node *swap(node **head, node **first, node **second)
{
	node *temp = *head;
	node *temp1=NULL;
	node *temp2=NULL;
	node *first_prev = NULL;
	node *second_prev = NULL;

	while(temp != *first) {
		first_prev = temp;
		temp = temp->next;
	}
	temp1 = *first;
	first_prev->next = *second;
	if(*second){
		temp2 = (*second)->next;
		(*second)->next = temp1;
	}
	(temp1)->next = temp2;
	return temp2;
}

node *sort_node() 
{

	int swapped ;
	node *cur = head, *first ;
	node *prev = head;
	if ( head == NULL || head->next == NULL ) return head ;
	else {
		do {
			if (head->data < head->next->data){
				swap_(&head, &head->next);
			}
			cur = head->next;
			swapped = 0 ;
			while ( cur != NULL && cur->next != NULL ){
				if (cur->data < cur->next->data){
					cur = swap( &head, &cur, &cur->next ) ;
					swapped = 1 ;
				}
				if(cur != NULL)
					cur = cur->next ;
			}  
		} while (swapped == 1) ;

	}
	return head ;

}

int main()
{
	int i = 0;int found;
	add(&head, 1);
	add(&head, 10);
	add(&head, 5);
	add(&head, 4);
	add(&head, 3);
	print(head);
	sort_node();
	printf("after sorting\n");
	print(head);
	return 0;
}
