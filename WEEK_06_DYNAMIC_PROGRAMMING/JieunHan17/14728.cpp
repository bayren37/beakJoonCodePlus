#include <cstdio>
#include <algorithm>

#define MAX 101
#define MAX_TIME 10001

using namespace std;

int estimatedTime[MAX] = {
    0,
};
int estimatedScore[MAX] = {
    0,
};
int dp[MAX][MAX_TIME] = {
    0,
};

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &estimatedTime[i], &estimatedScore[i]);
    }

    for (int j = 1; j <= T; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (estimatedTime[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - estimatedTime[i]] + estimatedScore[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d", dp[N][T]);
    return 0;
}