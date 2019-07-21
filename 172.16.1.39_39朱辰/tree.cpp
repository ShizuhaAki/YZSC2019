#include<bits/stdc++.h>
using namespace std;
int t,n,s,tote;
bool f[53][103][1000+10];
/*bool check(int i,int j,int k)
{
	if(k-j*(j-1)/2<=0){
		return 0;
	}else{
		return d[i-1][]
	}
}*/
template<typename T>
void Read(T &x){
	x=0;
	int f=1;
	char c=getchar();
	while(c!='-'&&c>'9'&&c<'0'){
		c=getchar();
	}
	for(;!isdigit(c);c=getchar()){
		if(c=='-'){
			f=-f;
		}
	}
	for(;isdigit(c);c=getchar()){
		x=x*10+c-'0';
	}
	x*=f;
	
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;++x){
		memset(f,0,sizeof(f)); tote=0;//ne=0;
		//cin>>n>>s;
		//scanf("%d %d",&n,&s);
		Read(n); Read(s);
		tote=2*n-2;
		f[1][1][1]=1;
		for(int i=1;i<n;++i){//dian
			for(int j=1;j<=tote-(n-i);++j){//du
				for(int k=1;k<=2*n-2;++k){//nowans
					if(f[i][j][k]){
						for(int nl=1;nl<=tote-j;++nl){//nextans
							f[i+1][j+nl][k+nl*(nl-1)/2]=1;
						}
					}
				}
				
			}
		}
		if(f[n][tote][s]){
			printf("Possible\n");
		}else{
			printf("Impossible\n");
		}
	}
	return 0;
}

