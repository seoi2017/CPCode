/*
Author: Invrise
For Archive Only, Please Do NOT Copy.
Tags: DP
State: AC
*/
#include <bits/stdc++.h>
#define MAXN 10010
#define MAXT 10000010

using namespace std;
using BigInt = long long;

BigInt n, t, v[MAXN], w[MAXN], dp[MAXT];

inline void debug()
{
    for (int i = 1; i <= t; ++i)
        printf("%lld ", dp[i]);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("in.io", "r", stdin);
    freopen("out.io", "w", stdout);
#endif
    scanf("%lld%lld", &t, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &v[i], &w[i]);

    for (BigInt i = 1; i <= n; ++i)
        for (BigInt j = v[i]; j <= t; ++j)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    // debug();

    printf("%lld\n", dp[t]);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}