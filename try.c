#include<stdio.h>
#include<string.h>
void generate_alphabets(char *num,char *str,int start,int depth)
{
	if(start>=strlen(num))
	{
		printf("\n %s",str);
		return;
	}


	str[depth]=(num[start]-'0'-1+97);
	generate_alphabets(num,str,start+1,depth+1);
	if(num[start+1])
	{
		int result=(num[start]-'0')*10+(num[start+1]-'0')-1;
		if(result<=25)
			str[depth]=result+97;
		str[depth+1]='\0';

		generate_alphabets(num,str,start+2,depth+1);

	}

}
int main()
{
	char str[50]={'\0'};
	char num[10]="1123";
	generate_alphabets(num,str,0,0);
}
