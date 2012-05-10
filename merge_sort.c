#include <stdlib.h>
#include <stdio.h>
 
typedef struct link link;
 
struct link {
  int value;
  link *next;
};
 
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
    return merge(merge_sort(even), merge_sort(odd));
  }
}
 
int main() {
  link *input = NULL;
  link **input_tail = &input;
  char buffer[512];
 
  while (fgets(buffer, sizeof buffer, stdin)) {
    int value = strtol(buffer, NULL, 10);
    append(&input_tail, cons(value, NULL));
  }
 
  link *sorted = merge_sort(input);
 
  printf("---\n");
 
  while (sorted) {
    printf("%d\n", pop(&sorted)->value);
  }
}
