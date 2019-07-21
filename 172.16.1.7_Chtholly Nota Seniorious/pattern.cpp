#include <bits/stdc++.h>
using namespace std;
double f[1100][1100];
int n, m;
int main()
{
	#ifndef CHTHOLLY
		freopen("pattern.in", "r", stdin);
		freopen("pattern.out", "w", stdout);
	#endif
	cin >> n >> m;
	f[0][0] = 1.0;
	for (int i = 0; i <= m - 1; i++)
		for (int j = 0; j <= n; j++)
		{
			f[i + 1][j] += f[i][j] * j / (double)n;
			f[i + 1][j + 1] += f[i][j] * (n - j) / (double)n;
		}
	cout << fixed << setprecision(4) << f[m][n] << endl;
	return 0;
}
