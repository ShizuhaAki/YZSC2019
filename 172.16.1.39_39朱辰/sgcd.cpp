#include<bits/stdc++.h>
using namespace std;
int n,k,num[500000+10],maxn=-1,x;
int main()
{
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>num[i];
		maxn=max(maxn,num[i]);
	}
	for(int i=maxn;i>=1;i++){
		int tot=0;
		for(int j=1;j<=n;j++){
			if(num[j]%i==0){
				tot++;
				if(tot>=k){
					cout<<i<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

