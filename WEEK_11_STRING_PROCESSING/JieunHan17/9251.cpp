#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int LCS[1001][1001];
    for (int i = 0; i <= s1.length(); i++)
    {
        LCS[i][0] = 0;
    }
    for (int j = 0; j <= s2.length(); j++)
    {
        LCS[0][j] = 0;
    }
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    int maximum = -1;
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            maximum = max(maximum, LCS[i][j]);
        }
    }

    cout << maximum << endl;

    return 0;
}