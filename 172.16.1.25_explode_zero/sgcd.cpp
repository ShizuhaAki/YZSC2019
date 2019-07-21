#include <bits/stdc++.h>
#define maxN 500005

using namespace std;

int read (){
	int ret=0;char c=getchar();
	while (c>'9'||c<'0')c=getchar();
	while (c<='9'&&c>='0')ret=ret*10+c-'0',c=getchar();
	return ret;
}

int n,k,a[maxN],h;

void div (int x){
	for (int i=1;i*i<=x;i++){
		if (x%i==0){
			a[i]++;
			if (i*i!=x)a[x/i]++;
			h=max(h,x/i);
		}
	}
}

int main (){
	freopen ("sgcd.in","r",stdin);
	freopen ("sgcd.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n;i++){
		int x=read();
		div(x);
	}
	for (int i=h;i>=1;i--){
		if (a[i]>=k){
			cout<<i;
			return 0;
		}
	}
	return 0;
}

