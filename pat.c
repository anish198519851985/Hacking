#include <stdio.h>
#define MAX 6
#define T_INPUT 13


struct edge{
	char edge;
	struct edge *next;
};

struct graph{
	char vertice;
	struct edge *next;
};
typedef struct graph graph_;
graph_ graph[6];

int map(char a)
{
	if(a == 'a')
		return 0;
	else if(a == 'b')
		return 1;
	else if(a == 'c')
		return 2;
	else if(a == 'd')
		return 3;
	else if(a == 'e')
		return 4;
	else if(a == 'f')
		return 5;
}

struct edge *create_edge(char a)
{
	struct edge *edge = malloc(sizeof(struct edge));
	edge->edge = a;
	edge->next = NULL;
	return edge;
}

void insert_e(char a, char b)
{
	struct edge *edge;
	int index = map(a);
	edge = graph[index].next;

	if(index > 5)
		printf("what the hell\n");
	/* start moving the edges */
	if(edge == NULL) {
		edge = create_edge(b);
		graph[index].next = edge;
	} else {
		while(edge->next != NULL) {
			edge = edge->next;
		}
		edge->next = create_edge(b);
	}
}

void insert_v(char a)
{
	int index = map(a);
	if(index > 5)
		printf("what the hell\n");
	graph[index].vertice = a;
	graph[index].next = NULL;
}

char path_[120] = {'0'};
int path_count = 0;

int i_path(char s)
{
	int i;
	for(i=0;i<path_count;i++) {
		if(path_[i] == s) {
			return 1;
		}
	}
	return 0;
}

int find_path(char s_, char t_)
{
	int i;
	/* adding to the path */
	path_[path_count++] = s_;
	/* first find if source and destination exists */
	if(s_ == t_) {
		int i;
		printf("found \n");
		for(i=0;i<path_count;i++)
			printf("+%c ,", path_[i]);
		/*check the path with previously found */
		for(i=1;i<path_count;i++) {
			path_[i] == '0';
		}
		path_count=1;
		return 1;
	}
	if( 6 > map(s_) >= 0 ) {
		/* check for all the nodes in the current vertice*/
		struct edge *track;
		{
			printf("\ndebug+\n");
			printf("%c\n", graph[map(s_)].vertice);
			track = graph[map(s_)].next;
			while(track != NULL) {
				printf("%c\n", track->edge);
				track = track->next;
			}
			printf("\ndebug-\n");
		}
		for(track=graph[map(s_)].next;track!= NULL;track = track->next) {
			/* if the current node not in path */			
			if(!i_path(track->edge)) {
				//printf("\n%c test-\n", track->edge);
				find_path(track->edge, t_);
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	insert_v('a');
	insert_v('b');
	insert_v('c');
	insert_v('d');
	insert_v('e');
	insert_v('f');
	insert_e('a', 'b');
	insert_e('a', 'c');
	insert_e('b', 'c');
	insert_e('b', 'd');
	insert_e('c', 'd');
	insert_e('d', 'c');
	insert_e('e', 'f');
	insert_e('f', 'c');
	printf("%d\n", find_path('a', 'd'));
#if 0
	for(i=0;i<6;i++) {
		printf("%c\n", graph[i].vertice);
		while(graph[i].next != NULL) {
			printf("%c\n", graph[i].next->edge);
			graph[i].next = graph[i].next->next;
		}
		printf("coming here\n");
	}
#endif

	return 0;
}
/*
a: b c d e
b: d a c
c: b c 
 */
