#include <stdio.h>

void reverse(char *verse, int i, int j, int length)
{
	verse[length] = verse[i];
	verse[i] = verse[j];
	verse[j] = verse[length];
}

int main()
{

	char *verse = malloc(sizeof(char)*50);
	int i=0;
	int j, k;
	char temp;

	puts("ENTER A LINE OF TEXT BELOW: ");
	gets(verse);
	i = strlen(verse) - 1;
	/*k is used as a backup to insert '/0' after the revers operation is done*/
	k = i; 
	j = 0;
	while(i != k/2)
	{
		/*we use the end of string i.e. '/0' as the storage*/
		reverse(verse, i, j, k+1);
		j++;
		i--;
	}
	verse[k+1] = '\0';
	printf("%s\n", verse);
	return 0;
}
