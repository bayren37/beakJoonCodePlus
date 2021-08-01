#include <cstdio>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int a[N + 1];
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }

    int answer = 0;
    int dp[N + 1];
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (cnt < dp[j])
                {
                    cnt = dp[j];
                }
            }
        }
        dp[i] = cnt + 1;
        if (answer < dp[i])
        {
            answer = dp[i];
        }
    }

    printf("%d\n", answer);

    return 0;
}