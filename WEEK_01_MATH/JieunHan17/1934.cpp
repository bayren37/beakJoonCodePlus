#include <iostream>
#include <algorithm>

using namespace std;

int LCM(int A, int B)
{
    int divider = min(A, B);

    while (divider > 0)
    {
        if (A % divider == 0 && B % divider == 0)
        {
            return divider * (A / divider) * (B / divider);
        }
        divider -= 1;
    }

    return 0;
}

int main()
{
    int T, A, B;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        cout << LCM(A, B) << endl;
    }

    return 0;
}