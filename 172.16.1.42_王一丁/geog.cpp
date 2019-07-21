#include<bits/stdc++.h>
using namespace std;
struct Mat{
    long long num[9][9];
};
Mat e,f;
int n,m;
int mm=998244353;
Mat Mul(Mat a,Mat b){
    Mat c;
    memset(c.num,0,sizeof(c.num));
    for(int i=1;i<=2;i++)
      for(int j=1;j<=2;j++)
        for(int k=1;k<=2;k++)
            c.num[i][j]=(c.num[i][j]+a.num[i][k]*b.num[k][j])%mm;
    return c; 
}
Mat pow(Mat x,int y){
    Mat ans=e;
    while(y)
    {
  		if(y&1) ans=Mul(ans,x);  
 		x=Mul(x,x);
 		y>>=1;
    }
    return ans;
}
int main()
{
	freopen("geog.in","r",stdin);
	freopen("geog.out","w",stdout);
	cin>>n>>m;
	if(n==1){ cout<<m<<endl;return 0;}
	for(int i=1;i<=2;i++) e.num[i][i]=1;
	f.num[1][1]=0;
	f.num[1][2]=m*(m-1);
	Mat a;
	a.num[1][1]=0;a.num[1][2]=m-1;a.num[2][1]=1;a.num[2][2]=m-2;
    Mat ans=pow(a,n-1);
    for(int i=1;i<=1;i++)
      for(int j=1;j<=2;j++)
        for(int k=1;k<=2;k++)
            f.num[i][j]=(f.num[i][j]+f.num[i][k]*ans.num[k][j])%mm;
    cout<<f.num[1][1]<<endl;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
