#include <cstdio>

#define MAX_PRICE 10001

using namespace std;

void sol(int dp[], int N, int cost[], int M)
{
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = cost[i]; j <= M; j++)
        {
            dp[j] += dp[j - cost[i]];
        }
    }
    printf("%d\n", dp[M]);
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);

        int cost[N + 1];
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &cost[j]);
        }

        int M;
        scanf("%d", &M);

        int dp[MAX_PRICE] = {
            0,
        };
        sol(dp, N, cost, M);
    }
    return 0;
}