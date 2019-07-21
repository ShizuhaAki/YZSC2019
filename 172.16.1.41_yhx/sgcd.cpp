#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
int a[maxn];
int n,k,x;
int main() {
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(a,0,sizeof(a));
	int zdz=0;
	for(int i=1;i<=n; i++) {
		scanf("%d",&x);
		a[x]++;
		if(x>zdz)
			zdz=x;
	}
	int ans;
	bool f=0;
	for(int i=zdz; i>=1; i--) {
		int cnt=0;
		for(int j=i; j<=zdz; j+=i) {
			cnt+=a[j];
			if(cnt>=k) {
				ans=i;
				f=1;
				break;
			}
		}
		if(f) break;
	}
	printf("%d\n",ans);
	return 0;
}
