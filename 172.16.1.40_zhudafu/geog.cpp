#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
long long n,m,Ans,b,p;
template <typename T>
int Read(T &x) {
	x=0;
	int f=1;
	char c=getchar();
	while(c!='-'&&c>'9'&&c<'0')
		c=getchar();
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c); c=getchar()) x=x*10+c-'0';
	x*=f;
	if(c=='\n')return 1;
	else return 0;
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
	freopen("geog.in","r",stdin);
	freopen("geog.out","w",stdout);
	Read(n);
	m%=Mod;
	Read(m);
	Ans=1;
	if(n==1) {
		Write(1);
	} 
	else {
		b=m-1;
		p=n;
		while(p>0) {
			if(p%2!=0) {
				Ans*=b;
				Ans%=Mod;
			}
			b=b*b%Mod;
			p>>=1;
		}
	}
	if(n&1){
		Ans-=m-1;
	}
	else{
		Ans+=m-1;
	}
	Ans%=Mod;
	Write(Ans);
	fclose(stdin);
	fclose(stdout);
}
