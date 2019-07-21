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
const int MAXN =100 +3,MAXM=(1<<15)+3;
double dp[MAXN][MAXM],ans;
int k,n,mx,t,score[MAXN],nd[MAXN];
int main(){
	freopen("reward.in","r",stdin);
	freopen("reward.out","w",stdout);
	
	k=qread(),n=qread(),mx=(1<<n)-1;
	up(1,n,i){
		score[i]=qread();
		while((t=qread())!=0) nd[i]|=1<<t-1;
	}
	dn(k,1,i){		//到第i个物品 
		up(0,mx,j){	//当前有的宝物 
			up(1,n,t) if((nd[t]&j)==nd[t])	//满足条件 
			dp[i][j]+=max(dp[i+1][j|(1<<t-1)]+score[t],dp[i+1][j]);
			else dp[i][j]+=dp[i+1][j];
			dp[i][j]/=n;	//盲猜 
		}
	}
	printf("%.6lf",(double)dp[1][0]);
	return 0;
}
