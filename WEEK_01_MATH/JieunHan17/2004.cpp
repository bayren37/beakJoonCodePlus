#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int check(long long num, int divider)
{
    int cnt = 0;

    for (long long i = divider; i <= num; i *= divider)
    {
        cnt += num / i;
    }

    return cnt;
}

int main()
{
    long long n, m;
    int cnt = 0;
    int cnt_two = 0;
    int cnt_five = 0;

    scanf("%lld %lld", &n, &m);

    cnt_two = check(n, 2) - check(m, 2) - check(n - m, 2);
    cnt_five = check(n, 5) - check(m, 5) - check(n - m, 5);

    cnt = min(cnt_two, cnt_five);

    cout << cnt << endl;

    return 0;
}