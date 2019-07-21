#include<bits/stdc++.h>
using namespace std;
int t,b,c,d,cnt,n,k,ans;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int a[4000000];
int main()
{
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	 if(i!=j) ans=max(gcd(a[i],a[j]),ans);
	 cout<<ans;
	fclose(stdin);
    fclose(stdout);
}
