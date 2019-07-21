#include<bits/stdc++.h>
using namespace std;
const int maxn=10007;
int a[maxn],cnt;
bool b[maxn];
void init() {
	for(int i=2; i<=maxn; i++) {
		if(!b[i]) a[++cnt]=i;
		for(int j=1; j<=cnt; j++) {
			if(i*a[j]>maxn) break;
			b[i*a[j]]=1;
			if(i%a[j]==0) break;
		}
	}
}
void work(int x) {
	int ans=1;
	for(int i=1; i<=cnt; i++) {
		if(a[i]>x) break;
		int p=0;
		while(x%a[i]==0) x/=a[i],p++;
		ans*=p+1;
	}
	if(x!=1) ans*=2;
	printf("%d\n",ans);
}
int main() {
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	init();
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int qds=n+1;
		work(qds);
	}
	fclose(stdin);
	fclose(stdout);
}
