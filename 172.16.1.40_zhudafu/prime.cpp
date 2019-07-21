#include<bits/stdc++.h>
using namespace std;
long long Max,x,n,Pd;
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
int main(){
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	Read(n);
	for(long long i=1;i<=n;i++){
		Read(x);
		Pd=1;
		Max=0;
		for(long long j=2;j*j<=x;j++){
			if(!(x%j)){
				Pd=0;
				Max=max(Max,j);
				while(!(x%j)){
					x/=j;
				}
			}
		}
		if(Pd){
			puts("Prime");
		}
		else{
			Write(Max);
			puts("");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
