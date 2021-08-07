#include <cstdio>
#include <algorithm>

#define MAX 21
#define MAX_ENERGY 100

using namespace std;

int L[MAX] = {
    0,
};
int J[MAX] = {
    0,
};
int dp[MAX][MAX_ENERGY] = {
    0,
};

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &L[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &J[i]);
    }

    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < MAX_ENERGY; j++)
        {
            if (L[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], J[i] + dp[i - 1][j - L[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }

            if (dp[i][j] > ans)
            {
                ans = dp[i][j];
            }
        }
    }

    printf("%d", ans);
    return 0;
}