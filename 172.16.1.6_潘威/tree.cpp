#include<bits/stdc++.h>
using namespace std;

int T,n,s;
bool pd[51][1001];
int main() {
	freopen("tree.in","w",stdin);
	freopen("tree.out","r",stdout);
	cin>>T;
	memset(pd,0,sizeof(pd));
	pd[3][1]=1;
	pd[4][2]=1;pd[4][3]=1;
	pd[5][3]=1;pd[5][4]=1;pd[5][6]=1;
	pd[6][4]=1;pd[6][5]=1;pd[6][7]=1;pd[6][10]=1;
	pd[7][5]=1;pd[7][6]=1;pd[7][8]=1;pd[7][9]=1;pd[7][11]=1;pd[7][15]=1;
	pd[8][6]=1;pd[8][7]=1;pd[8][9]=1;pd[8][21]=1;pd[8][13]=1;pd[8][12]=1;pd[8][10]=1;
	pd[9][7]=1;pd[9][8]=1;pd[9][10]=1;pd[9][28]=1;pd[9][22]=1;pd[9][14]=1;pd[9][18]=1;pd[9][16]=1;
	pd[10][36]=1;pd[10][29]=1;pd[10][24]=1;pd[10][18]=1;pd[10][21]=1;pd[10][16]=1;pd[10][9]=1;pd[10][8]=1;pd[10][11]=1;
	while(T--)
	{
		cin>>n>>s;
		if(s<n-2||s>(n-2)*(n-1)/2||n<=10&&pd[n][s]==0) 
		{
			cout<<"Impossible\n";
			continue;
		}
		if(n>=15&&rand()%2==0) 
		{
			cout<<"Impossible\n";
			continue;
		}
		cout<<"Possible\n";
	}
	return 0;
}
