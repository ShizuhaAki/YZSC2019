#include<bits/stdc++.h>
using namespace std;
int f[107];
int mm=998244353;
int main()
{
	int n,m;
	cin>>n>>m;
	f[1]=0;
	f[2]=(m-1)*m;
	for(int i=3;i<=n;i++){
		f[i]=(f[i-1]*(m-2))%mm+(f[i-2]*(m-1))%mm;
		f[i]=f[i]%mm;
	}
	if(n==1) cout<<m<<endl;
	else cout<<f[n]<<endl;
	return 0;
}
