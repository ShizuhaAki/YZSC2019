#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,K;
int f[500005];
bool jud(int x)
{
    int sum=0;
    for(int i=1;x*i<=500000;i++)
	sum+=f[x*i];
    if(sum>=K)return 1;
    return 0;
}
int main()
{
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
    n=read();K=read();
    for(int i=1;i<=n;i++)
    {
	int x=read();//cout<<(double)x/4<<endl;
	f[x]++;
    }
    for(int i=500000;i;i--)
    {
	if(jud(i))
	{
	    printf("%I64d\n",(ll)i);
	    return 0;
	}
    }
    return 0;
}
