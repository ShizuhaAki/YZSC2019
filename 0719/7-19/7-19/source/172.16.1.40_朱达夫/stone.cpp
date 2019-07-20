#include<bits/stdc++.h>
using namespace std;
int n,T;
double x,y,p,q,f[100010],g[100010];
template <typename T>
inline int Read(T &x) {
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
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	Read(T);
	while(T--){
		Read(n);
		cin>>p;
		cin>>q;
		n=min(n,1000);
		f[0]=0.0;
		g[0]=1.0;
		for(int i=1;i<=n;i++){
			if(f[i-1]>g[i-1]){
				x=1-p;
				y=1-q;
			}
			else{
				x=p;
				y=q;
			}
			f[i]=((double)(x*g[i-1]+(1.0-x)*y*f[i-1])/(1.0-(1.0-x)*(1.0-y)));
			g[i]=(y*f[i-1]+(double)(1.0-y)*x*g[i-1]/(1.0-(1.0-x)*(1.0-y)));
		}
		printf("%0.6lf\n",f[n]);
	}
	fclose(stdin);
	fclose(stdout);
}
