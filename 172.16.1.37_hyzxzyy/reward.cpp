#include<bits/stdc++.h>
#define MAXN 20
using namespace std;
int n,x,m,ans;
int p[MAXN];
double f[1<<MAXN][109];
int s[MAXN];
int main(){
	freopen("reward.in","r",stdin);
	freopen("reward.out","w",stdout);
	scanf("%d%d",&m,&n);
	int S=(1<<n)-1;
	for(register int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		while(scanf("%d",&x)&&x)s[i]|=1<<(x-1);
	}
	for(register int i=1;i<=n;i++)
		for(register int j=0;j<=S;j++)
			for(register int k=m;k>=1;k--){
				if((s[i]&j)==s[i])
					f[j|1<<(i-1)][k]+=max(f[j|1<<(i-1)][k+1],f[j][k+1]+p[i]);
				else
					f[j][k]+=f[j][k+1];
				f[j][k]/=n;
			}
				
	printf("%.6f",f[0][1]);
	fclose(stdin);fclose(stdout);
}
