#include<bits/stdc++.h>
using namespace std;
unsigned long long m,n;
int cas;
unsigned long long  if_prime(unsigned long long a)
{
	unsigned long long sqr=floor(sqrt(a));
	for(int i=2;i<=sqr;++i){
		if(a%i==0){
			return(if_prime(a/i));
		}
	}
	return a;
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin>>cas;
	for(int i=1;i<=cas;++i){
		cin>>n;
//		cout<<n<<endl;
		m=if_prime(n);
		if(n==m){
			cout<<"Prime"<<endl;
		}else{
			cout<<m<<endl;
		}
	}
	return 0;
}

