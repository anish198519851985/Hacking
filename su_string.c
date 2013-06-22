int o_len = 2;
int temp=0;
int foo(char *s, char *t, int s_l, int t_len)
{
	if((s_l<0) || (t_len<0))
		return 0;
	if(s[s_l] == t[t_len]) {
		return 1+ foo(s, t, s_l-1, t_len-1);
	}
	return foo(s, t, s_l-1, t_len);
	return foo(s, t, s_l, t_len-1);
}

int main()
{
	char s[] = {"hellotest"};
	char t[] = {"lt"};
	if(foo(s, t, strlen(s)-1, strlen(t)-1) == strlen(t))
		printf("found\n");
	else
		printf("not found %d\n", strlen(t)-1);
}
