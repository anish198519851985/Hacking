#include <stdio.h>
long w[10000]={0},f[100000]={0};
int main()
{
      long i,s,t,n,l1,l2,l3,c1,c2,c3,s1,s2,s3;
      int min(int,int);
      scanf("%ld %ld %ld %ld %ld %ld*",&l1,&l2,&l3,&c1,&c2,&c3);
      scanf("%ld*",&n);
      scanf("%ld %ld*",&s,&t);
      if (s>t) s=s+t,t=s-t,s=s-t;
printf("s %d t %d\n", s, t);
      for (i=2;i<=n;i++)
        scanf("%d*",&w[i]);
      s1=s,s2=s,s3=s;
      for (i=s+1;i<=t;i++)
        {
                        while (w[i]-w[s1]>l1) s1++;
                        while (w[i]-w[s2]>l2) s2++;
                        while (w[i]-w[s3]>l3) s3++;
                        if(s1<i)
                          f[i]=min(min(f[s1]+c1,f[s2]+c2),f[s3]+c3);
                        else
                          if (s2<i) f[i]=min(f[s2]+c2,f[s3]+c3);
                          else
                            f[i]=f[s3]+c3;
                        }
      printf("%ld",f[t]);
      return 0;
}
int min(int s1,int s2)
{
    if (s1<s2) return s1;
    else return s2;
}
