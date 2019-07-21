#include<bits/stdc++.h>
using namespace std;
int Max,x,n,k,Num,a[500010];
template <typename T>
int Read(T &x) {
	x=0;
	int f=1;
	char c=getchar();
	while(c!='-'&&c>'9'&&c<'0')
		c=getchar();
	for(; !isdigit(c); c=getchar())
		if(c=='-')
			f=-f;
	for(; isdigit(c); c=getchar())
		x=x*10+c-'0';
	x*=f;
	if(c=='\n')
		return 1;
	else
		return 0;
}
void Write(long long x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) {
		Write((x-x%10)/10);
	}
	putchar(x%10+'0');
}
int main() {
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	Read(n);
	Read(k);
	for(int i=1; i<=n; i++) {
		Read(x);
		a[x]++;
		Max=max(Max,x);
	}
	for(int i=Max; i; i--) {
		Num=0;
		for(int j=i; j<=Max; j+=i) {
			Num+=a[j];
			if(Num>=k) {
				Write(i);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
