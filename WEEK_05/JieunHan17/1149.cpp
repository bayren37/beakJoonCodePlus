#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int cost[N][3];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int dp[N][3];
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = cost[0][i];
    }

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int answer = min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
    printf("%d", answer);

    return 0;
}