#include <stdio.h>
#include <stdlib.h>
 
struct link {
  struct link *next;
};
 
struct link *link(struct link *next) {
  struct link *node = malloc(sizeof *node);
  if (node) {
    node->next = next;
  }
  return node;
}
 
struct link *append(struct link ***tail) {
  struct link *node = link(**tail);
  if (link) {
    **tail = link(**tail);
    *tail = &(**tail)->next;
  }
  return node;
}
 
size_t length(struct link *node) {
  size_t length = 0;
  while (node) {
    length += 1;
    node = node->next;
  }
  return length;
}
 
int main() {
  struct link *list = NULL;
  struct link **tail = &list;
 
  if (append(&tail) && append(&tail) && append(&tail)) {
    printf("%zu\n", length(list));
  }
}
