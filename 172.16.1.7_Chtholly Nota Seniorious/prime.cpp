#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define il inline
#define ll long long
il ll Power(ll a, ll b, ll p)
{
	ll ans = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
const int bases[]  = {2, 7, 61}, nBases = 3;
il bool witness(ll base, ll n)
{
	ll tmp = n - 1;
	ll s = 0, t = 0;
	while (!(tmp & 1))
	{
		tmp >>= 1;
		s++;
	}
	t = tmp;
	ll x = Power(base, t, n);
	if (x == 1 || x == n - 1)return true;
	else
	{
		int j = s - 1;
		while (j--)
		{
			x = x * x % n;
			if (x == n - 1)return true;
		}
	}
	return false;
}
il bool Miller_Rabin(ll n)
{
	for (register int i = 0; i < nBases; i++)
	{
		if (n == bases[i])return true;
		if (n % bases[i] == 0)return false;
		if (!witness(bases[i], n))return false;
	}
	return true;
}
il ll Read()
{
    ll f = 1,x = 0;char ch = cin.get();
    while(ch < '0' || ch > '9') 
	{	
		if(ch=='-')
			f = -1;
		ch=cin.get();
	}
    while(ch >= '0' && ch <= '9') 
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = cin.get();
	}
    return f * x;
}
int main()
{
#ifndef CHTHOLLY
	freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n; int T;
	T = Read();
	while (T--)
	{
		n = Read();
		if (Miller_Rabin(n))
		{
			cout << "Prime" << endl;
			continue;
		}
		else
		{
			if ((!(n & 1)) && Miller_Rabin(n >> 1))
			{
				cout << (n >> 1) << endl;
				continue;
			}
			ll rt = sqrt(n);
			ll i = (rt & 1) ? rt : rt - 1;
			ll j = 3;
			bool foundans = false;
			for (; j * j <= n; j += 2)
			{
				if (n % j == 0 && Miller_Rabin(n / j))
				{
					cout << n / j << endl;
					foundans = true;
					break;
				}
			}
			if (!foundans)
			{
				for (; i >= 3; i -= 2)
				{
					if (n % i == 0 && Miller_Rabin(i))
					{
						cout << i << endl;
						break;
					}
				}
			}
		}
	}

	return 0;
}
