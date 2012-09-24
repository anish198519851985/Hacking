#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct stack{
	struct node *bst_node;
	struct stack *next;
};
typedef struct stack stack;
stack *front, *rear;

void push(struct node *bst_node)
{
	printf("%s %d\n", __func__, bst_node->data);
	stack *node = malloc(sizeof(*node));
	node->next = NULL;
	node->bst_node = bst_node;

	if (front == NULL) {
		front = node;
	} else {
		stack *node = malloc(sizeof(*node));
		node->next = front;
		node->bst_node = bst_node;
		front = node;
	}
}

struct node *pop(void)
{
	if(front == NULL) {
		printf("nothing here\n");
		return NULL;
	} else {
		stack *temp = front;
		front = front->next;
		return temp->bst_node;
	}
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void print_bst(struct node *new) 
{
	if(new == NULL)
		return;
	print_bst(new->left);
	printf("%d\n", new->data);
	print_bst(new->right);
}

struct node *minValue(struct node *new)
{
	struct node *prev = new;
	while(new != NULL && new->left != NULL) {
		prev = new->left;
		new = new->left;
	}
	return prev;
}

struct node *maxValue(struct node *new)
{
	struct node *prev = new;
	while(new != NULL && new->right != NULL) {
		prev = new->right;
		new = new->right;
	}
	return prev;
}

#if 0
int isBST(struct node *new)
{
	if(new == NULL)
		return 1;
	if(new->left != NULL && (maxValue(new->left))->data > new->data) {
		return 0;
	}

	if(new->right != NULL && (minValue(new->right))->data < new->data) {
		return 0;
	}
	printf("helo\n");
	if(!isBST(new->left) || !isBST(new->right))
		return 0;
	return 1;
}
#endif



int isBST(struct node* root)
{
	static struct node *prev = NULL;

	// traverse the tree in inorder fashion and keep track of prev node
	if (root)
	{
		if (!isBST(root->left))
			return 0;

		// Allows only distinct valued nodes 
		if (prev != NULL && root->data <= prev->data) {
			return 0;
		}

		prev = root;
		return isBST(root->right);
	}

	return 1;
}

void dfs(struct node *root)
{
	struct node *temp;
	push(root);
	do {
		temp = pop();
		if(temp == NULL) {
			break;
		} else {
			printf("popped is %d\n", temp->data);
			if(temp->right != NULL)
				push(temp->right);	
			if(temp->left != NULL)
				push(temp->left);	
		}
	}while(temp != NULL);
}

/* Driver program to test above functions*/
int main()
{
	front = NULL;
	rear = NULL;
	struct node *kk;
	struct node *temp = calloc(1, sizeof(*temp));
	struct node *node = newNode(40);
	node->left        = newNode(20);
	node->right        = newNode(60);
	node->left->left  = newNode(10);
	node->left->right = newNode(30);
	node->right->right = newNode(70);

	print_bst(node);
	//printf("aa %d\n", maxValue(node)->data);
	//printf("aa %d\n", minValue(node)->data);
	dfs(node);
	getchar();
	return 0;
}
