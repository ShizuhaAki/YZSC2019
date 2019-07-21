#include<bits/stdc++.h>
using namespace std;
int f[57][2007][1007];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		int n,s;
		cin>>n>>s;
		int w=(n-1)*2,q;
		f[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<w;j++){
				for(int k=0;k<s;k++){
					if(f[i][j][k]){
						for(int l=1;j+l<=w;l++){
            				q=l*(l-1)/2;
            				if (k+q>s) break;
            				f[i+1][j+l][k+q]=1;
        				}
					}
				}
			}
		}
		if(f[n][w][s]) cout<<"Possible"<<endl;
			else cout<<"Impossible"<<endl;
	}
	return 0;
}
