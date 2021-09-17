#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check()
{
    stack<char> s;
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            s.push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (s.empty())
            {
                return false;
            }
            else if (s.top() != '(')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }

    if (!s.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        bool result = check();
        if (result)
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