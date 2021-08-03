#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int wine[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wine[i]);
    }

    int dp[n];
    dp[0] = wine[0];
    dp[1] = dp[0] + wine[1];
    dp[2] = max(max(wine[0] + wine[1], wine[1] + wine[2]), wine[0] + wine[2]);

    for (int i = 3; i < n; i++)
    {
        //3가지 경우가 있음
        //a, b, c
        //(a, b): dp[i - 1]
        //(b, c): dp[i - 3] + wine[i] + wine[i - 1]
        //(a, c): dp[i - 2] + wine[i]

        dp[i] = max(max(dp[i - 1], dp[i - 3] + wine[i] + wine[i - 1]), dp[i - 2] + wine[i]);
    }

    printf("%d", dp[n - 1]);

    return 0;
}