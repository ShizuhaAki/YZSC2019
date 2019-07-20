#include<cstdio>
using namespace std;
int n, m;
double dp[1005][1005];
int main()
{
    freopen("pattern.in", "r", stdin);
    freopen("pattern.out", "w", stdout);
    scanf("%d %d", &n, &m);
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i-1][j] * ((j + 0.0) / n) + dp[i - 1][j - 1] * ((n - j + 1.0) / n);
		}
    printf("%.4lf", dp[m][n]);
    return 0;
}