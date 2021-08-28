#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int input[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input[i]);
    }

    int maximum = 0;
    for (int startIdx = 0; startIdx < N - 2; startIdx++)
    {
        for (int midIdx = startIdx + 1; midIdx < N - 1; midIdx++)
        {
            for (int endIdx = midIdx + 1; endIdx < N; endIdx++)
            {
                int value = input[startIdx] + input[midIdx] + input[endIdx];
                if (value <= M)
                {
                    maximum = max(value, maximum);
                }
            }
        }
    }

    printf("%d\n", maximum);

    return 0;
}