#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int N;
    string input[100000];
    queue<int> q;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];

        if (input[i][1] == 'u')
        {
            int value;
            cin >> value;
            q.push(value);
        }
        else if (input[i][0] == 'p' && input[i][1] == 'o')
        {
            if (!q.empty())
            {
                printf("%d\n", q.front());
                q.pop();
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (input[i][0] == 's')
        {
            printf("%lu\n", q.size());
        }
        else if (input[i][0] == 'e')
        {
            printf("%d\n", q.empty());
        }
        else if (input[i][0] == 'f')
        {
            if (!q.empty())
            {
                printf("%d\n", q.front());
            }
            else
            {
                printf("-1\n");
            }
        }
        else
        {
            if (!q.empty())
            {
                printf("%d\n", q.back());
            }
            else
            {
                printf("-1\n");
            }
        }
    }
    return 0;
}