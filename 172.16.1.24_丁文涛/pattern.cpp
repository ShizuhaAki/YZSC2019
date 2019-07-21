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
const int MAXN =1000 +3;
double dp[MAXN][MAXN],ans;
int n,m;
int main(){
	freopen("patten.in","r",stdin);
	freopen("patten.out","w",stdout);
	
	n=qread(),m=qread();
	dp[0][0]=1;
	up(1,m,i) up(1,n,j){
		dp[i][j]=dp[i-1][j]*(double)(j-1)/n+dp[i-1][j-1]*(double)(n-j+1)/n;
	}
	up(1,m,i) ans+=dp[i][n];
	printf("%.4lf",ans);
	return 0;
}
