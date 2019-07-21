#include<bits/stdc++.h>
#define REP(i,a,b) for(register int i(a);i<=b;i++)
using namespace std;
int n,m;
double f[1009][1009];
int main(){
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);
	cin>>n>>m;
	f[0][0]=1;
	REP(i,0,n)REP(j,0,m-1)
		f[i][j+1]+=f[i][j]*i/n,f[i+1][j+1]+=f[i][j]*(n-i)/n;
	printf("%.4lf",f[n][m]);
	fclose(stdin);fclose(stdout);
}
