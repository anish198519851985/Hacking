#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;
	int visited;

}treeNode;

treeNode* FindMin(treeNode *node)
{
	if(node==NULL)
	{
		/* There is no element in the tree */
		return NULL;
	}
	if(node->left) {/* Go to the left sub tree to find the min element */
		printf("%d ,", node->left->data);
		return FindMin(node->left);
	} else 
		return node;
}

treeNode* FindMax(treeNode *node)
{
	if(node==NULL)
	{
		/* There is no element in the tree */
		return NULL;
	}
	if(node->right) /* Go to the left sub tree to find the min element */
		FindMax(node->right);
	else 
		return node;
}

treeNode * Insert(treeNode *node,int data)
{
	if(node==NULL)
	{
		treeNode *temp;
		temp = (treeNode *)malloc(sizeof(treeNode));
		temp -> data = data;
		temp -> left = temp -> right = NULL;
		return temp;
	}

	if(data >(node->data))
	{
		node->right = Insert(node->right,data);
	}
	else if(data < (node->data))
	{
		node->left = Insert(node->left,data);
	}
	/* Else there is nothing to do as the data is already in the tree. */
	return node;

}

treeNode * Delete(treeNode *node, int data)
{
	treeNode *temp;
	if(node==NULL)
	{
		printf("Element Not Found");
	}
	else if(data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	else if(data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	else
	{
		/* Now We can delete this node and replace with either minimum element 
		   in the right sub tree or maximum element in the left subtree */
		if(node->right && node->left)
		{
			/* Here we will replace with minimum element in the right sub tree */
			temp = FindMin(node->right);
			node -> data = temp->data; 
			/* As we replaced it with some other node, we have to delete that node */
			node -> right = Delete(node->right,temp->data);
		}
		else
		{
			/* If there is only one or zero children then we can directly 
			   remove it from the tree and connect its parent to its child */
			temp = node;
			if(node->left == NULL)
				node = node->right;
			else if(node->right == NULL)
				node = node->left;
			free(temp); /* temp is longer required */ 
		}
	}
	return node;

}

treeNode * Find(treeNode *node, int data)
{
	if(node==NULL)
		return NULL;
	if(data > node->data)
		return Find(node->right,data);
	else if(data < node->data)
		return Find(node->left,data);
	else
		return node;
}

void PrintInorder(treeNode *node)
{
	if(node==NULL)
		return;
	PrintInorder(node->left);
	printf("%d ",node->data);
	PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
	if(node==NULL)
		return;
	printf("%d ",node->data);
	PrintPreorder(node->left);
	PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
	if(node==NULL)
		return;
	PrintPostorder(node->left);
	PrintPostorder(node->right);
	printf("%d ",node->data);
}

#if 1
#define Q_SIZE 10
struct queue *head_q;
struct queue *tail;

struct queue{
	struct queue *next;
	treeNode *node;
};
typedef struct queue queue;
queue *q = NULL;

void enq(treeNode *node)
{
	if(head_q == NULL || tail == NULL) { /* q is empty */
		struct queue *q = malloc(sizeof(struct queue));
		q->next = NULL;
		q->node = node;
		head_q = q;
		tail = q;
	} else {
		struct queue *temp = head_q;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		struct queue *q = malloc(sizeof(struct queue));
		q->next = NULL;
		q->node = node;
		temp->next = q;
		head_q = q;
	}
}

treeNode * deq()
{
	struct queue *temp = tail;
	tail = tail->next;
	return temp->node;
}

int q_empty()
{
	if(head_q == NULL || tail == NULL)
		return 1;
	else
		return 0;
}

/*DFS uses stack*/
void bfs(treeNode *node)
{
	enq(node);
	while(!q_empty()) { /*check if the stack is empty*/
		/* pop the stack and mark it visited*/
		node = deq();
		node->visited = 1;
		printf("%d\n", node->data);
		/*check if it has any left or right node*/
		/*if yes then push it on the stack */
		if(node->left != NULL && node->left->visited != 1) {
			enq(node->left);
		}
		if(node->right != NULL && node->right->visited != 1) {
			enq(node->right);
		}
		/*if no then just let the loop continue */
	}
}
#endif

struct stack{
	struct stack *next;
	treeNode *node;
};
typedef struct stack stack;
stack *head = NULL;

treeNode *pop()
{
	stack *temp = head;
	head = head->next;
	return temp->node;
}


void push(treeNode *node)
{
	if(head == NULL) {
		stack *q = malloc(sizeof(struct stack));
		q->next = NULL;
		q->node = node;
		head = q;
		return;
	}
	stack *q = malloc(sizeof(stack));
	q->next = head;
	q->node = node;
	head = q;
}

int stack_empty()
{
	if(head == NULL)
		return 1;
	else
		return 0;
}

/*DFS uses stack*/
void dfs(treeNode *node)
{
	push(node);
	while(!stack_empty()) { /*check if the stack is empty*/
		/* pop the stack and mark it visited*/
		node = pop();
		node->visited = 1;
		printf("%d\n", node->data);
		/*check if it has any left or right node*/
		/*if yes then push it on the stack */
		if(node->right != NULL && node->right->visited != 1) {
			push(node->right);
		}
		if(node->left != NULL && node->left->visited != 1) {
			push(node->left);
		}
		/*if no then just let the loop continue */
	}
}

int main()
{
	treeNode *root = NULL;
	treeNode *temp;
	queue *head_q, *tail;
	head_q = tail = NULL; /*empty queue */

	root = Insert(root, 13);
	root = Insert(root, 20);
	root = Insert(root, 10);
	root = Insert(root, 21);
	root = Insert(root, 22);
	root = Insert(root, 11);
	root = Insert(root, 12);
	root = Insert(root, 8);
	PrintInorder(root);
	printf("\n");
	bfs(root);
}
