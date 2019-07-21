#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
float f[1005][1005];
int main()
{
    freopen("pattern.in","r",stdin);
    freopen("pattern.out","w",stdout);
    int n,m;
    cin>>n>>m;
    f[0][0]=1;
    for (int i=0;i<=m-1;i++)
    {
        for (int j=0;j<=n;j++)
        {
            f[i+1][j]+=f[i][j]*j/n;
            f[i+1][j+1]+=f[i][j]*(n-j)/n;
        }
    }
    printf("%.4lf\n",f[m][n]);
    return 0;
}
