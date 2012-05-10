#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node s_node;
struct s_node {
	s_node * next;
};
s_node * tail;

s_node * head_node(void) {
	/* Check for empty list */
	if (!tail)
		return NULL;

	return tail->next;
}

s_node * make_node(void) {
	s_node * new_node;

	new_node = malloc(sizeof *new_node);
	if (!new_node)
		return NULL;

	return new_node;
}

void append_node(s_node * node) {
	s_node * head;

	head = head_node();
	/* Check for empty list */
	if (!head) {
		tail = node;
		tail->next = node;
		return;
	}

	tail->next = node;
	node->next = head;
	return;
}

int list_length(void) {
	s_node * node;
	int len = 0;

	for (node = head_node(); node; node = node->next) {
		++len;
		if (node == tail)
			break;
		continue;
	}
	return len;
}

int main(void) {
	s_node * node;
	int i;

	for (i = 3; i; --i) {
		node = make_node();
		if (!node)
			return EXIT_FAILURE;

		append_node(node);
		continue;
	}

	for (node = head_node(); node; node = node->next) {
		printf(
				"%p->next == %p%s\n",
				(void *) node,
				(void *) node->next,
				node == tail ? "" : " &&"
		      );
		if (node == tail)
			break;
		continue;
	}

	printf("Total nodes: %d\n", list_length());
	return EXIT_SUCCESS;
}
