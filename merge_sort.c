#include <stdlib.h>
#include <stdio.h>

typedef struct link link;

struct link {
	int value;
	link *next;
};
void print(link *head)
{
        printf("****************************");
        while(head != NULL)
        {
                printf("\n%d\n",head->value);
                head = head->next;
        }
        printf("****************************");
}


link *cons(int value, link *next) {
	struct link *l = malloc(sizeof *l);
	if (l) {
		l->value = value;
		l->next = next;
	}
	return l;
}

link *recons(link *element, int value, link *next) {
	element->value = value;
	element->next = next;
	return element;
}

link *append(link ***tail, link *element) {
	**tail = element;
	element->next = NULL;
	*tail = &element->next;
	return element;
}

link *pop(link **head) {
	struct link *element = *head;
	if (element) {
		*head = element->next;
		element->next = NULL;
	}
	return element;

}

link *merge(link *a, link *b) {
#if 0
	printf("\nadding to a\n");
	print(a);
	printf("\nadding to b\n");
	print(b);
#endif
	if (!a) {
		return b;
	} else if (!b) {
		return a;
	} else if (a->value < b->value) {
		return recons(a, a->value, merge(a->next, b));
	} else {
		return recons(b, b->value, merge(b->next, a));
	}
}

link *merge_sort(link *list) {
	if (!list || !list->next) {
		return list;
	} else {
		link *even = NULL;
		link *odd = NULL;
		link **even_tail = &even;
		link **odd_tail = &odd;
		link *element;

		while (list) {
			if (element = pop(&list)) {
				append(&even_tail, element);
			}
			if (element = pop(&list)) {
				append(&odd_tail, element);
			}
		}
                link *even1 = merge_sort(even);
                link *odd1 = merge_sort(odd);
#if 1
		print(odd1);
		printf("\n````median\n");
		print(even1);
#endif
		return merge(even1, odd1);
	}
}

int main() {
	link *input = NULL;
	link **input_tail = &input;
	char buffer[512];
	int i = 0;
		append(&input_tail, cons(1, NULL));
		append(&input_tail, cons(2, NULL));
		append(&input_tail, cons(3, NULL));
		append(&input_tail, cons(4, NULL));
		append(&input_tail, cons(0, NULL));

	link *sorted = merge_sort(input);

	printf("---\n");

	while (sorted) {
		printf("%d\n", pop(&sorted)->value);
	}
}
