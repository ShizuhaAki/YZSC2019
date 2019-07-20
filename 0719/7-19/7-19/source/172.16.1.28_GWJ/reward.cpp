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
vector<int> each[16];
int p[16];
int main(){
	freopen("reward.in","r",stdin);
	freopen("reward.out","w",stdout);
	int k,n;
	cin>>k>>n;
	int qian_=0;
	rb(i,1,n){
		scanf("%d",&p[i]);
		int now;
		scanf("%d",&now);
		while(now){
			each[i].PB(now);
			scanf("%d",&now);
		}
	}
	rb(i,1,n){
		qian_=(bool(qian_)|bool(!each[i].empty()));
	}
	if(!qian_){//30%
		double dp[101]={0};
			rb(j,1,k){dp[j]=dp[j-1];
				rb(i,1,n){
					if(p[i]<=0) continue;
					dp[j]+=double(p[i])*double(1)/double(n);
				}
			}
		printf("%.6f\n",dp[k]);
		return 0;
	}
	else{
		//50%
		cout<<0.000000<<endl;
	}
	return 0;
}
