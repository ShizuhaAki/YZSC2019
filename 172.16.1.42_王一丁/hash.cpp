#include<bits/stdc++.h>
using namespace std;
int h,ans=0;
int a[10000007],cnt;
bool b[100000007];
void eratos(int n){
	memset(b,true,sizeof(b));
	for(int i=2;i<=n;i++){
		if (b[i])a[++cnt]=i;
		for(int j=1;j<=cnt&&i*a[j]<=n;j++){
			b[i*a[j]]=false;
			if (i % a[j]==0) break;
		}
	}
}
void work(int x)
{
	int ans=1;
	for(int i=1; i<=cnt; i++)
	{
		if(a[i]>x) break;
		int p=0;
		while(x%a[i]==0) x/=a[i],p++;
		ans*=p+1;
	}
	if(x!=1) ans*=2;
	printf("%d\n",ans);
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	int t;
	eratos(20000);
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		work(n+1);
	}
	return 0;
}
