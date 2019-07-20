//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
double dp[1001][1001];
int main(){
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);
	double n,m;
	cin>>n>>m;
	if(n>m){
		cout<<"0.0000"<<endl;
		return 0;
	}
	dp[0][0]=1;
	rb(i,1,m){//buy m
		rb(j,1,n){//have n
			if(i<j) dp[i][j]=0;
			dp[i][j]=dp[i-1][j]*double(j)/n+dp[i-1][j-1]*double(n-j+1)/n;
		}
	}
	printf("%.4f\n",dp[int(m)][int(n)]);
	return 0;
}
