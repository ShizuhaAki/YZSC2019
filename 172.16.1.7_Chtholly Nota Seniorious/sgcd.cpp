#include <bits/stdc++.h>
using namespace std;
const int INF = 500001;
int L, R, n, k;
int a[INF];
int maxans;
bool compute(int mid)
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] % mid == 0)res++;
	if (res > maxans)
	{
		maxans = res;
		return true;
	}
	return false;
}
int main()
{
#ifndef CHTHOLLY
	freopen("sgcd.in", "r", stdin);
	freopen("sgcd.out", "w", stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		R = max(R, a[i]);
	}
	for (int i = 1; i <= R; i++)compute(i);
	cout << maxans << endl;
	return 0;
}
