/*
Author: Invrise
For Archive Only, Please Do NOT Copy.
Tags: DP, DAG, Topo Sort
State: AC
*/
#include <bits/stdc++.h>
#define MOD 80112002
#define MAXN 5010
#define add(__target) push_back(__target)

using namespace std;

vector<int> node[MAXN];
int n, m, degree[MAXN], dp[MAXN], ans = 0;
queue<int> q;

inline void debug()
{
    for (int i = 1; i <= n; ++i)
        printf("%d ", dp[i]);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("in.io", "r", stdin);
    freopen("out.io", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0, st, ed; i < m; ++i)
        scanf("%d%d", &st, &ed), node[st].add(ed), ++degree[ed];
    
    // debug();

    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
            dp[i] = 1, q.push(i);

    while (q.empty() == false)
    {
        int ptr = q.front();
        q.pop();

        if (node[ptr].size() == 0)
            ans = ((ans + dp[ptr]) % MOD);
        else
            for (int nxt : node[ptr])
            {
                dp[nxt] = ((dp[nxt] + dp[ptr]) % MOD) /* Important! */, --degree[nxt];
                if (degree[nxt] == 0)
                    q.push(nxt);
            }
    }

    printf("%d\n", ans);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}