#include<bits/stdc++.h>
using namespace std;
long long a[17],b[17];
bool p[40000007];
int prime[10000007];
void eratos(int n){
	memset(p,true,sizeof(p));
	prime[0]=0;
	for(int i=2;i<=n;i++){
		if (p[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0] && i*prime[j]<=n;j++){
			p[i*prime[j]]=false;
			if (i % prime[j]==0) break;
		}
	}
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	int n;
	long long gg=10000000;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	eratos(min(b[n],gg));
	p[0]=p[1]=0; 
	for(int i=1;i<=n;i++){
		int q=0;
		if(a[i]<=sqrt(a[n])&&p[a[i]]){
			cout<<"Prime"<<endl;
			continue;
		}
		for(int j=prime[0];j>=1;j--) {
			if(a[i]%prime[j]==0){
				cout<<prime[j]<<endl;q=1; break;
			} 
		}
		if(!q) cout<<"Prime"<<endl;
	}
	return 0;
}
