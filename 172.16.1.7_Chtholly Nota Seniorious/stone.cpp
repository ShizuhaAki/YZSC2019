#include <bits/stdc++.h>
using namespace std;
int n;double p, q;
int main()
{
	#ifndef CHTHOLLY
		freopen("stone.in", "r", stdin);
		freopen("stone.out", "w", stdout);
	#endif
	int T;cin >> T;
	while (T--)
	{
		cin >> n >> p >> q;
		int i = n;
		int cnt = 0 ;
		double ans = p;
		double prevans = p;
		for (int i = 1; i <= 100; i++)
			ans = (prevans * (1 - p) * (1 - q) * p) / ++cnt, prevans = ans;
		cout << fixed << setprecision(6) << ans << endl;
	}

}
