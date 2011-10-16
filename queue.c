#include <stdio.h>

struct queue_{
int x[10];
int front;
int rear;
};

typedef struct queue_ queue;
int enter(queue *a,int number);
int delete(queue *a);
int isEmpty(queue *a);
int isFull(queue *a);

main()
{
	queue a;
	a.front = a.rear = 1;
	int element;
	do{
		printf("do you want to enter or press 100 to exit\n");
		scanf("%d",&element);
		if(element == 100)
			break;
		if(!enter(&a,element))
			break;		
	}while(element != 100);

	do{
		printf("do you want to delete,press 100 to get out\n");
		scanf("%d",&element);
		if(element == 100)
			break;
		element = delete(&a);
		printf("%d\n",element);
		print(a);
	}while(element != 100);
	printf("all the elements now are\n");
	print(a);
}

int isFull(queue *a)
{
	return (((a->rear%10)+1) == a->front);
}

int isEmpty(queue *a)
{
	return (a->front == a->rear);
}

int enter(queue *a,int number)
{
	if(isFull(a))
	{
		printf("queue is full \n");
		return 0;
	}
	a->rear = a->rear%10;
	a->x[a->rear++] = number;
	return 1;
}

int delete(queue *a)
{
	int data;
	if(isEmpty(a))
	{
		printf("queue is empty \n");
		return;
	}
	a->front = a->front%10;
	data = a->x[a->front];
	a->front++;
	return data; 
}

print(queue a)
{
	int temp = a.front;
	int temp1 = a.rear;
	while(temp != temp1)
	{
		printf("data %d\n",a.x[temp]);
		temp++;
	}
}
