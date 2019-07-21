#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
const int SIZE_=1 ;
char bef[SIZE_+3],*p1=bef,*p2=bef;
char getc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZE_,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int c,ret,w=1;
	while((c=getc())> '9'||c< '0')
	w=(c=='-'?-1:1);
	ret=c-'0';
	while((c=getc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =50 +3,MAXM=1000 +3;
const int INF =2147483647;
int n,m;
int dp[MAXN][MAXN][MAXM];
int calc(int x){	//度数为x的节点的贡献 
	return (long long)x*(x-1)/2;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	dn(qread(),1,T){
		n=qread(),m=qread();
		memset(dp,0,sizeof(dp));
		up(1,n,i) if(calc(i)<=m) dp[1][i-1][calc(i)]=true;
		up(1,n-1,i) up(0,n,j) up(0,m,k){
			if(!dp[i][j][k]) continue;
			up(1,n,t) if(j+t-1<=n-2&&k+calc(t)<=m){
				dp[i+1][j+t-1][k+calc(t)]=true;
			}
		}
//		up(1,n,i) up(1,i,j) up(1,m,k)
//		printf("%d %d %d %d\n",i,j,k,dp[i][j][k]); 
		puts(dp[n][n-2][m]?"Possible":"Impossible");
	}
	return 0;
}
/*
6
4 36
4 3
10 73
10 5
10 16
10 17
*/
