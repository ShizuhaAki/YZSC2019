# include <bits/stdc++.h>
using namespace std;

int s,n,h;

int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);

    cin>>n;
    for (int i=1;i<=n;i++)
    {
    	s=2;
    	cin>>h;
    	int p=floor(sqar(h,2));
    	for(int x=h;j>=p;j--)
    	{
    		int y;
    		y=(h-x)/x+1;
    		if((x*y+x+y)==h && max(x,y)<=h) s++;
		}
		s*=2;
    	if (p*p==h) s--;
		cout<<s;
	}
    
	return 0;
}

