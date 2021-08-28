#include <cstdio>

using namespace std;

int cal(int num)
{
    int result = 0;
    while (num > 0)
    {
        result += (num % 10);
        num /= 10;
    }
    return result;
}

int main()
{
    int N;
    scanf("%d", &N);

    bool flag = false;
    for (int i = 1; i <= N; i++)
    {
        if ((i + cal(i)) == N)
        {
            flag = true;
            printf("%d\n", i);
            break;
        }
    }

    if (!flag)
    {
        printf("0\n");
    }
    return 0;
}