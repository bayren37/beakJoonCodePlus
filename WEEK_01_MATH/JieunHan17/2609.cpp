#include <iostream>
#include <algorithm>

using namespace std;

int gcd = 0;
int lcm = 0;

int cal(int A, int B)
{
    int divider = min(A, B);

    while (divider > 0)
    {
        if (A % divider == 0 && B % divider == 0)
        {
            gcd = divider;
            lcm = divider * (A / divider) * (B / divider);
            return 0;
        }
        divider -= 1;
    }

    return 0;
}

int main()
{
    int A, B;

    cin >> A >> B;
    cal(A, B);
    cout << gcd << endl;
    cout << lcm << endl;

    return 0;
}