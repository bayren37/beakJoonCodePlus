#include <cstdio>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    long long num[10][N + 1];

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            num[i][1] = 0;
        }
        else
        {
            num[i][1] = 1;
        }
    }

    //( a + b ) % c = ( a % c + b % c  ) % c
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                num[j][i] = num[j + 1][i - 1] % 1000000000;
            }
            else if (j == 9)
            {
                num[j][i] = num[j - 1][i - 1] % 1000000000;
            }
            else
            {
                num[j][i] = (num[j - 1][i - 1] + num[j + 1][i - 1]) % 1000000000;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += num[i][N];
    }

    printf("%lld", ans % 1000000000);
    return 0;
}