#include<bits/stdc++.h>
#define THERE using
#define WAS namespace
#define A std
#define MONKEY	;

//A LONG TIME AGO
//
//
//
//
//
//
                            THERE WAS A MONKEY
//
//
//
//
//
//
//
//just joking''''''
int T,cnt,n,m;
int rd()
{
    int ans = 0,flag = 1;
    char ch = getchar();
    while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
    if(ch == '-') flag=-1;
    while(ch>='0'&&ch<='9') ans+=(ans<<2)+(ans<<1)+ch-48,ch=getchar();
    return flag*ans;
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	T=rd();
	while(T--)
	{
		cnt=0;
		n=rd();
		n++;
	 for(int i=1;i*i<=n;i++)
	  {
		 if(n%i==0)
		 {
			cnt++;
			if(i!=n/i) cnt++;
		 }
	  }
	  cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
