#include <iostream>

using namespace std;

int cal(int num)
{
    int divider = num - 1;

    if (num == 1)
    {
        return 0;
    }

    while (divider > 1)
    {
        if (num % divider == 0)
        {
            return 0;
        }

        divider--;
    }
    return 1;
}

int main()
{
    int N, num;
    int cnt = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (cal(num) == 1)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}