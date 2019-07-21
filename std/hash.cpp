#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,h,tot;
int pri[1505],num[1505];
bool mark[10005];
void pre()
{
	for(int i=2;i<=10005;i++)
	{
		if(!mark[i])pri[++tot]=i;
		else continue;
		for(int j=i;j<=10005;j+=i)
		    mark[j]=1;
	}
}
int cal1(int x)
{
	int ans=0;
	for(int i=1;i<=x;i++)
	    if(!(x%i))ans++;
	return ans;
}
int cal2(int x)
{
	int ans=1;
	for(int i=1;i<=tot;i++)
	{
		num[i]=0;
	    while(!(x%pri[i])){x/=pri[i];num[i]++;}
	    ans*=(num[i]+1);
	    if(x<pri[i])break;
	}
	if(x!=1)ans*=2;
	return ans;
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
    T=read();pre();
    for(int i=1;i<=T;i++)
    {
        h=read();
		if(h<=20000)printf("%d\n",cal1(h+1));
		else printf("%d\n",cal2(h+1));
    }
	return 0;
}
