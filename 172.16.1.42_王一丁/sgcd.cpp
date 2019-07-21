#include<bits/stdc++.h>
using namespace std;
int a[500007];
int main()
{
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	int n,k,g=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],g=max(g,a[i]);
	for(int i=g;i>=1;i--){
		int q=0;
		for(int j=1;j<=n;j++)
			if(a[j]%i==0) q++;
		if(q>=k){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
