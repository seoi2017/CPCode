/*
Author: Invrise
For Archive Only, Please Do NOT Copy.
Tags: DP
State: AC
*/
#include <bits/stdc++.h>
#define MAXN 110

using namespace std;
using Pair = pair<int, int>;

struct Position
{
    static int h[MAXN][MAXN];
    int x, y;
    bool operator>(const Position& other) const
    {
        return Position::h[this->x][this->y] > Position::h[other.x][other.y];
    }
};

priority_queue<Position, vector<Position>, greater<Position>> heap; // Important
int n, m, dp[MAXN][MAXN], ans = 0;
int Position::h[MAXN][MAXN] = {0};

inline void debug()
{
    for (int i = 1; i <= n; ++i, printf("\n"))
        for (int j = 1; j <= m; ++j)
            printf("%d ", dp[i][j]);
}

int main()
{
#ifdef LOCAL
    freopen("in.io", "r", stdin);
    freopen("out.io", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &Position::h[i][j]), heap.push({i, j}), dp[i][j] = 1;
    
    while (heap.empty() == false)
    {
        Position pos = heap.top();
        heap.pop();

        if (Position::h[pos.x][pos.y] > Position::h[pos.x - 1][pos.y])
            dp[pos.x][pos.y] = max(dp[pos.x][pos.y], dp[pos.x - 1][pos.y] + 1);
        if (Position::h[pos.x][pos.y] > Position::h[pos.x + 1][pos.y])
            dp[pos.x][pos.y] = max(dp[pos.x][pos.y], dp[pos.x + 1][pos.y] + 1);
        if (Position::h[pos.x][pos.y] > Position::h[pos.x][pos.y - 1])
            dp[pos.x][pos.y] = max(dp[pos.x][pos.y], dp[pos.x][pos.y - 1] + 1);
        if (Position::h[pos.x][pos.y] > Position::h[pos.x][pos.y + 1])
            dp[pos.x][pos.y] = max(dp[pos.x][pos.y], dp[pos.x][pos.y + 1] + 1);
        
        ans = max(ans, dp[pos.x][pos.y]);
    }

    // debug();

    printf("%d\n", ans);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}