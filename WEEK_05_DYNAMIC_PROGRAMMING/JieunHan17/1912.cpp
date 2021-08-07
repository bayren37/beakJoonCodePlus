#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int input[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    int dp[n]; //n번 원소를 가장 마지막으로 하는 부분수열 중 합이 최대인 부분수열의 합
    dp[0] = input[0];
    int answer = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + input[i], input[i]);
        if (dp[i] > answer)
        {
            answer = dp[i];
        }
    }

    printf("%d\n", answer);
    return 0;
}