#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b)
{
    return a.length() < b.length();
}

int check(vector<string> numbers, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i].length() == numbers[j].length())
            {
                continue;
            }
            bool flag = true;
            for (int idx = 0; idx < numbers[i].length(); idx++)
            {
                if (numbers[i][idx] != numbers[j][idx])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        vector<string> numbers;
        for (int j = 0; j < n; j++)
        {
            string input;
            cin >> input;
            numbers.push_back(input);
        }

        sort(numbers.begin(), numbers.end(), compare);

        int result = check(numbers, n);
        if (result == 1)
        {
            printf("YES\n");
        }
    }
    return 0;
}