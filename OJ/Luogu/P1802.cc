/*
Author: Invrise
For Archive Only, Please Do NOT Copy.
Tags: DP
State: AC
*/
#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;
using BigInt = long long;

int n, m;
BigInt win[MAXN], lose[MAXN], v[MAXN];
BigInt dp[MAXN];

int main()
{
#ifdef LOCAL
    freopen("in.io", "r", stdin);
    freopen("out.io", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld%lld", &lose[i], &win[i], &v[i]);

    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 0; --j)
            if (j >= v[i])
                dp[j] = max(dp[j], max(dp[j - v[i]] + win[i], dp[j] + lose[i]));
            else // Can not win situation!
                dp[j] += lose[i];

    printf("%lld\n", dp[m] * 5LL);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}