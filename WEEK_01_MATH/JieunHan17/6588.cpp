#include <iostream>
#include <stdio.h>

using namespace std;

int n, a, b;
int check[1000001] = {0, 1};

void Goldbach()
{
    for (a = 3; a <= n / 2; a += 2)
    {
        if (check[a] == 0 && check[n - a] == 0)
        {
            b = n - a;
            printf("%d = %d + %d\n", n, a, b);
            return;
        }
    }
    printf("Goldbach's conjecture is wrong.");
    return;
}

int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        for (int j = 2; i * j <= 1000000; j++)
        {
            check[i * j] = 1;
        }
    }

    do
    {
        scanf("%d", &n);
        if (n == 0)
        {
            return 0;
        }
        Goldbach();

    } while (n != 0);

    return 0;
}