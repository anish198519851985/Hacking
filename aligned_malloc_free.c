#include <stdio.h>
#include <stdlib.h>

void *my_malloc(void **ptr, int size, int align)
{
	void *orig_ptr = malloc(size + align-1 + sizeof(void *));
	printf("%p\n", orig_ptr);
	ptr = (unsigned long)orig_ptr + align-1 + sizeof(void *) & (~(align - 1));
	*((void **)ptr - 1) = orig_ptr;
	return ptr;
}

void my_free(void *ptr)
{
	free(*((void **)ptr -1));
}

int main()
{
	void *ptr;
	ptr = my_malloc(&ptr, 40, 8);
	printf("%p\n", ptr);
	my_free(ptr);
}
