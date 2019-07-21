#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;++i)
#define dn(r,l,i) for(register int i=r;i>=l;--i)
using namespace std;
int qread(){
	int ret,w=1,c;
	while((c=getchar())>'9'||c<'0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret *10+c-'0';
	return ret*w;
}
const int MAXN =2333 +3;
int n;
double p,q,f[MAXN],g[MAXN];
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	dn(qread(),1,T){
		scanf("%d%lf%lf",&n,&p,&q);
		n=min(n,2333);
		f[1]=(double)-p/(double)((1.0-p)*(1.0-q)-1.0);
		g[1]=(double)-q/(double)((1.0-p)*(1.0-q)-1.0);
		up(2,n,i){
			double p_=1-p,q_=1-q;
			f[i]=max(p *q*(g[i-1]-q*f[i-1])/(q+p -p *q),
					 p_*q*(g[i-1]-q*f[i-1])/(q+p_-p_*q));
			swap(p,q),swap(p_,q_);
			g[i]=max(p *q*(f[i-1]-q*g[i-1])/(q+p -p *q),
					 p_*q*(f[i-1]-q*g[i-1])/(q+p_-p_*q));
			swap(p,q),swap(p_,q_);
		}
		printf("%.6lf",f[n]);
	}
	
	return 0;
}
