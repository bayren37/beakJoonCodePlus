#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/* 다른 방식 */

int divide(int num, int divider)
{
    int cnt = 0;

    while (num > 0)
    {
        if (num % divider != 0)
        {
            break;
        }
        cnt++;
        num /= divider;
    }
    return cnt;
}

int main()
{
    int N;
    int cnt = 0;
    int cnt_two = 0;
    int cnt_five = 0;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cnt_two += divide(i, 2);
        cnt_five += divide(i, 5);
    }

    cnt += min(cnt_two, cnt_five);

    cout << cnt << endl;

    return 0;
}