#include <stdio.h>

using namespace std;

int M, N;
int check[1000001] = {0, 1};

/* 에라스토테네스의 체 */
void isPrimeNum()
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; i * j <= N; j++)
        {
            check[i * j] = 1;
        }
    }
}

int main()
{
    scanf("%d %d", &M, &N);
    isPrimeNum();
    for (int i = M; i <= N; i++)
    {
        if (check[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}