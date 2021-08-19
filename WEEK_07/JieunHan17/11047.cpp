#include <cstdio>

using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int value[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &value[i]);
    }

    int cnt = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (value[i] <= K)
        {
            cnt += K / value[i];
            K %= value[i];
        }
    }

    printf("%d\n", cnt);

    return 0;
}