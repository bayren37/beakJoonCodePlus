#include <cstdio>

using namespace std;

int d[21];

int fibo(int num)
{
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i <= num; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }
    return d[num];
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d", fibo(n));

    return 0;
}