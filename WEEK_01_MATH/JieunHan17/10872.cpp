#include <iostream>

using namespace std;

/* 아직 푸는 중 */

int main()
{
    int N;
    double result = 1;

    cin >> N;

    for (double i = N; i >= 1; i--)
    {
        result *= i;
    }

    if (N == 0)
    {
        result = 1;
    }

    printf("%.f", result);

    return 0;
}