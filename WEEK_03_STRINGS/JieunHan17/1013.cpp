#include <iostream>
#include <cstdio>
#include <string>
#include <regex>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string input;
        cin >> input;
        regex pattern("(100+1+|01)+");
        if (regex_match(input, pattern))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}