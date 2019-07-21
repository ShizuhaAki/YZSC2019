# include <bits/stdc++.h>
using namespace std;

int a,n,m,f[51][100+5][1000],s;

/*
template<typename T>
void read(T &x)
{
	x=0;
	int f=1;
	char c=getchar();
	while (c!='-' && c>'9' && c<'0')
	{
		c=getchar();
		
	}
	for (;!isdigit(c);c=getchar())
	{
		if (c=='-')
		{
			f=-f;
		}
	}
	for (;!isdigit(c);c=getchar())
	{
		x=x*10+c-'0';
	}
	x*=f;
}
*/

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	//read(a);
	cin>>a;
	for (int p=0;p<a;p++)
	{
		//read(n);
		//read(s);
		cin>>n>>s;
	    memset(f,0,sizeof(f));
	    f[0][0][0]=1;
	    int w;
	    int m=(n-1)<<1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<s;k++)
                    if (f[i][j][k])
                        for(int l=1;j+l<=m;l++)
			  		    {
                            w=l*(l-1)>>1;
                            if (k+w>s) break;
                            f[i+1][j+l][k+w]=1;
                        }
    if (f[n][m][s]) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
	}
	
	return 0;
}
