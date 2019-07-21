//prime.cpp 2019.7.20—Ô÷›ºØ—µÕÌº‰≤‚ ‘ 
//programmed by wcy 
#include<bits/stdc++.h>
using namespace std;
bool T[1000000100];
long long a[11];
int tot,CAS;
long long maxNum;
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	scanf("%d",&CAS);int flag=0;
	for(register int i=1;i<=CAS;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>a[flag]) flag=i;
	}
	maxNum=a[flag];
	for(register int i=2;i*i<=maxNum;i++)
		if(!T[i])
			for(register int j=i*i;j<=maxNum;j+=i)
					T[j]=1;
	for(register int i=1;i<=maxNum;i++)
		cout<<T[i]<<" ";
	cout<<endl;
	for(register int i=1;i<=CAS;i++)
		if(T[a[i]]==0) printf("prime\n");
		else
		{
			for(register long long j=a[i]>>1;j>=2;j--)
			{
				if(a[i]%j==0&&T[j]==0)
				{
					cout<<j<<endl;
					break;
				}
			}

		}
	return 0;
}
