#include <iostream>
#include <string>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    string target;
    cin >> input >> target;

    int input_len = input.length();
    int target_len = target.length();
    int target_idx = 0;
    stack<pair<char, int> > s;
    for (int i = 0; i < input_len; i++)
    {
        if (input[i] == target[target_idx])
        {
            if (target_idx == target_len - 1)
            {
                for (int j = 0; j < target_len - 1; j++)
                {
                    s.pop();
                }

                if (!s.empty())
                {
                    target_idx = s.top().second;
                }
                else
                {
                    target_idx = 0;
                }
            }
            else
            {
                target_idx++;
                s.push(make_pair(input[i], target_idx));
            }
        }
        else if (input[i] == target[0] && target_idx != 0)
        {
            target_idx = 1;
            s.push(make_pair(input[i], target_idx));
        }
        else
        {
            target_idx = 0;
            s.push(make_pair(input[i], target_idx));
        }
    }

    if (s.empty())
    {
        cout << "FRULA" << endl;
    }
    else
    {
        stack<char> reverse;

        while (!s.empty())
        {
            reverse.push(s.top().first);
            s.pop();
        }

        string answer = "";
        while (!reverse.empty())
        {
            answer += reverse.top();
            reverse.pop();
        }

        cout << answer << endl;
    }

    //string library 사용
    // int current = input.find(target);
    // while (current != string::npos)
    // {
    //     input.erase(current, target.length());
    //     current = input.find(target);
    // }

    // if (input.length() == 0)
    // {
    //     cout << "FRULA" << endl;
    // }
    // else
    // {
    //     cout << input << endl;
    // }
    return 0;
}