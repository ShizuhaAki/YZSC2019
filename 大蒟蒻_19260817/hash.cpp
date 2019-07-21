#include<cstdio>
#include<string.h>
int T,n,k,p[10010],cnt;
bool prime[10010];
void makePrime()
{
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<10010;i++)
    {
        if(prime[i]) p[cnt++]=i;
        for(int j=0;j<cnt&&i*p[j]<10010;j++)
        {
            prime[i*p[j]]=false;
            if(i%p[j]==0) break;
        }
    }
    return ;
}
int getNum(int x)
{
	int ans=1,t;
	for(int i=0;i<=cnt&&p[i]<=x;i++)
	{
		t=0;
		while(x%p[i]==0)
		{
			x/=p[i];
			t++;
		}
		ans*=t+1;
	}
	if(x!=1) ans<<=1;
	return ans;
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	makePrime();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		k=getNum(n+1);
		printf("%d\n",k);
	}
	return 0;
}
