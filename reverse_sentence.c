int j=0;

void foo(char *s, char *t)
{
	if(*s == '\0')
		return;
	foo(++s, t);
	if(*s)
		t[j++] = *s;
}

char sum[100];
int main()
{
	char t[100];
	int i=0, k=0;
	int count=0;
	char string[] = {"I have done the reverse program"};

	t[strlen(string)-1] = string[0];
	foo(string, t);
	t[++j] = '\0';
	strcpy(string, t);

	memset(string, 0, strlen(string));
	j=0;
	for(i=0;1;) {
		if(*(t+i) == '\0') {
			string[k] = '\0';
			sum[j+strlen(string)-1] = string[0];
			foo(string, sum);
			sum[++j] = '\0';
			break;
		} else if(!isspace(*(t+i)))
			string[k++] = *(t+i);
		else if(isspace(*(t+i))){
			string[k] = '\0';
			k=0;
			sum[j+strlen(string)-1] = string[0];
			foo(string, sum);
			sum[++j] = ' ';
			j++;
		}
		i++;
	}
	printf("%s\n", sum);
	return 0;
}
