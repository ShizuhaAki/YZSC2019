#define HUGEWIDE
#include<bits/stdc++.h>
using namespace std;
int a[111111];
int main() {
#ifdef HUGEWIDE
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
#endif
	int n,k;
	cin>>n>>k;
	int x;
	int maxn=0;
	int cnt;
	bool flag;
	int i,j;
	for(i=1; i<=n; i++) {
		cin>>x;
		a[x]++;
		maxn=max(maxn,x);
	}
	for(i=maxn; i>=1; i--) {
		cnt=0;
		flag=false;
		for(j=i; j<=maxn; j+=i) {
			cnt+=a[j];
			if(cnt>=k) {
				flag=true;
				break;
			}
		}
		if(flag) {
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
