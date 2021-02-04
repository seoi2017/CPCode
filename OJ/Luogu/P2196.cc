/*
Author: Invrise
For Archive Only, Please Do NOT Copy.
Tags: DP, Graph
State: AC
*/
#include <bits/stdc++.h>
#define MAXN 22

using namespace std;

int n, mine[MAXN], dp[MAXN], pre[MAXN], maxVal, maxPos;
bool can[MAXN][MAXN];

void print(const int& ptr)
{
    if (pre[ptr] == 0)
        printf("%d", ptr);
    else
        print(pre[ptr]), printf(" %d", ptr);
}

int main()
{
#ifdef LOCAL
    freopen("in.io", "r", stdin);
    freopen("out.io", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &mine[i]), dp[i] = mine[i];

    for (int i = 1, temp; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            scanf("%d", &temp), can[i][j] = (temp == 0 ? false : true); // Directed Map!

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (can[j][i] == true && dp[j] + mine[i] >= dp[i])
                dp[i] = dp[j] + mine[i], pre[i] = j;

    for (int i = 1; i <= n; ++i)
        if (dp[i] > maxVal)
            maxVal = dp[i], maxPos = i;

    print(maxPos), printf("\n%d\n", maxVal);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}