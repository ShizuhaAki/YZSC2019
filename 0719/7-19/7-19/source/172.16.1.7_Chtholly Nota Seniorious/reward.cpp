#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int sco[MAXN], pre[MAXN];
double f[MAXN][100000];
int main()
{
	#ifndef CHTHOLLY
		freopen("reward.in", "r", stdin);
		freopen("reward.out", "w", stdout);
	#endif
	int k, n;
	cin >> k >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> sco[i];
		int tmp;
		while (cin >> tmp && tmp)pre[i] |= (1 << (tmp - 1));
	}
	for (int i = k; i >= 1; i--)
		for (int s = 0; s < (1 << n); s++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ((pre[j] & s) == pre[j])//can eat
					f[i][s] += max(f[i + 1][s], f[i + 1][s | (1 << (j - 1))] + sco[j]);
				else
					f[i][s] += f[i + 1][s];	
			}
			f[i][s] /= n;
		}
	cout << fixed << setprecision(6) << f[1][0] << endl;
	return 0;
}
