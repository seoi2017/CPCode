/*
Author: Invrise
For Archive Only, Please Do NOT Copy.
Tags: DP
State: AC
*/
#include <bits/stdc++.h>
#define MAXN 22

using namespace std;
using BigInt = long long;

constexpr int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

BigInt dp[MAXN][MAXN];
int n, m, dx, dy;
bool disabled[MAXN][MAXN];

inline void setDisabled(const int& x, const int& y)
{
    disabled[x][y] = true; // Important!
    for (int i = 0; i < 8; ++i)
        if (x + dir[i][0] < 0 || x + dir[i][0] > n || y + dir[i][1] < 0 || y + dir[i][1] > m)
            continue;
        else
            disabled[x + dir[i][0]][y + dir[i][1]] = true;
}

inline void debug()
{
    for (int i = 0; i <= n; ++i, printf("\n"))
        for (int j = 0; j <= m; ++j, printf(" "))
            printf("%lld", dp[i][j]);
}

int main()
{
#ifdef LOCAL
    freopen("in.io", "r", stdin);
    freopen("out.io", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &dx, &dy);
    setDisabled(dx, dy), dp[0][0] = 1LL;

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            if ((i == 0 && j == 0) || disabled[i][j] == true)
                continue;
            else
                dp[i][j] = (j - 1 < 0 ? 0 : dp[i][j - 1]) + (i - 1 < 0 ? 0 : dp[i - 1][j]);

    // debug();

    printf("%lld\n", dp[n][m]);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}