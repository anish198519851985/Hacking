#include <stdio.h>

#define SIZE 26
struct tri{
	int complete;
	struct tri *child[SIZE];
};

void insert(char *c, struct tri **t)
{
	struct tri *current = *t;
	while(*c != '\0')
	{
		int i;
		int letter = *c - 'a';
		if(current->child[letter] == NULL) {
			current->child[letter] = malloc(sizeof(*current));
			memset(current->child[letter], 0, sizeof(struct tri));
		}
		current = current->child[letter];
		c++;
	}	
	current->complete = 1;
}

int found(char *c, struct tri *t)
{
	struct tri *current = t;
	while(*c != '\0')
	{
		int i;
		int letter = *c - 'a';
		if(current->child[letter] == NULL) {
			return 0;
		}
		current = current->child[letter];
		c++;
	}
	return current->complete;
}

int main()
{
	int i;
	struct tri *t = malloc(sizeof(*t));
	t->complete = 0;
	memset(t, 0, sizeof(struct tri));

	insert("weather", &t);	
	insert("going", &t);	
	insert("good", &t);	
	insert("i", &t);	
	insert("fighting", &t);	
	insert("fight", &t);	
	insert("fought", &t);	
	insert("thought", &t);	
	insert("think", &t);	
	insert("thinking", &t);	
	insert("hardly", &t);	
	insert("hard", &t);	
	insert("fastly", &t);	
	insert("fast", &t);	
	insert("trying", &t);	
	insert("fastedd", &t);	
	insert("try", &t);	
	(1 ==found("fastly", t))?printf("found\n"):printf("not found\n");
	(1 ==found("fastedd", t))?printf("found\n"):printf("not found\n");
	return 0;
}
