#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> temp;

void OctToBin(int num)
{
    int limit = num == 8 ? 4 : 3;
    for (int i = 0; i < limit; i++)
    {
        if (num == 0)
        {
            temp.push(0);
            continue;
        }
        temp.push(num % 2);
        num /= 2;
    }
}

int main()
{
    string input;
    cin >> input;

    if (input == "0")
    {
        printf("0");
    }
    else
    {
        int len = input.length();
        for (int i = 0; i < len; i++)
        {
            int num = input[i] - '0';
            OctToBin(num);
            bool flag = false;
            while (!temp.empty())
            {
                if (i == 0)
                {
                    if (temp.top() != 0)
                    {
                        flag = true;
                    }
                    else if (!flag && temp.top() == 0)
                    {
                        temp.pop();
                        continue;
                    }
                }
                printf("%d", temp.top());
                temp.pop();
            }
        }
    }

    return 0;
}