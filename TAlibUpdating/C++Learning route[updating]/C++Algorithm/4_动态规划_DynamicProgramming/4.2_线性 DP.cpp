#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int dp[N][N], tmp[N][N];

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d",&tmp[i][j]);

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = -INF;
    dp[1][1] = tmp[1][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            dp[i][j] = max(dp[i - 1][j] + tmp[i][j], dp[i - 1][j - 1] + tmp[i][j]);
        }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= i; ++j)
    //         printf("%d ",dp[i][j]);
    //     printf("\n");
    // }

    int ans = -INF;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dp[n][i]);
    }

    printf("%d\n",ans);
    return 0;
}