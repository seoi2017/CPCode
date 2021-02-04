/*
Author: Invrise
For Archive Only, Please Do NOT Copy.
State: AC
*/
#include <bits/stdc++.h>
#define MAXN 50010

using namespace std;
using BigInt = long long;
using Pair = pair<BigInt, BigInt>;

BigInt n, ans;

int main()
{
#ifdef LOCAL
    freopen("in.io", "r", stdin);
    freopen("out.io", "w", stdout);
#endif
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i)
    {
        BigInt temp;
        scanf("%lld", &temp);
        ans += (temp * temp);
    }
    cout << fixed << setprecision(15) << (double)ans / 2.0F << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}