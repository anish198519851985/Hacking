#include <stdio.h>
#include <string.h>
#define SIZE 4
#define CHAR_SIZE 256

struct co{
	int i;
	int j;
};

struct c_r{
	struct co s[CHAR_SIZE];
	char track[CHAR_SIZE];
};
struct c_r main_;

int search(char mat[SIZE][SIZE], char c, int i, int j)
{
	/* search in top if it exists */
	if(i-1 >= 0)
		if(mat[i-1][j] == c)
			return 1;
	/* search in top right if it exists */
	if(i-1 >= 0 && j+1 < SIZE)
		if(mat[i-1][j+1] == c)
			return 1;
	/* search in top left if it exists */
	if(i-1 >= 0 && j-1 >= 0)
		if(mat[i-1][j-1] == c)
			return 1;
	/* search in current down if it exists */
	if(i+1 < SIZE)
		if(mat[i+1][j] == c)
			return 1;
	/* search in current left if it exists */
	if(j-1 >= 0)
		if(mat[i][j-1] == c)
			return 1;

	/* search in current right if it exists */
	if(j+1 < SIZE)
		if(mat[i][j+1] == c)
			return 1;
	/* search in down left if it exists */
	if(i+1 < SIZE && j-1 >= 0)
		if(mat[i+1][j-1] == c)
			return 1;
	/* search in down right if it exists */
	if(i+1 < SIZE && j+1 < SIZE)
		if(mat[i+1][j+1] == c)
			return 1;
	return 0;
}

int find_word(char mat[SIZE][SIZE], char *word, int i, int size)
{
	if(i >= size)
		return 1;
	if(main_.track[word[i] -'0'] == word[i]){
		if(i+1 >= size)
			return 1;
		if(search(mat, word[i+1], main_.s[main_.track[word[i] -'0'] - '0'].i, main_.s[main_.track[word[i] -'0'] - '0'].j)) {			
			find_word(mat, word, i+1, size);
		} else {
			return 0;			
		}
	} else {
		return 0;
	}
}

int main()
{	
	int i, j;
	char *word = {"TDIN"};
	char mat[SIZE][SIZE] = {
			       'S', 'M', 'E', 'F',
			       'R', 'A', 'T', 'D',
			       'L', 'O', 'N', 'I',
			       'K', 'Z', 'P', 'B',
				};
	for(i=0;i<SIZE;i++) {
		for(j=0;j<SIZE;j++) {
			main_.track[mat[i][j] - '0'] = mat[i][j];
			main_.s[mat[i][j] - '0'].i = i;
			main_.s[mat[i][j] - '0'].j = j;			
		}
	}	
	if(find_word(mat, word, 0, strlen(word)))
		printf("found\n");
	else
		printf("not found\n");
	return 0;
}
