#include <cstdio>
#include <algorithm>

#define MAX 21
#define MAX_DAYS 201

using namespace std;

int days[MAX] = {
    0,
};
int pages[MAX] = {
    0,
};
int dp[MAX][MAX_DAYS] = {
    0,
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d", &days[i], &pages[i]);
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (days[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], pages[i] + dp[i - 1][j - days[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d", dp[M][N]);
    return 0;
}