#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int N;
    string input[100000];
    stack<int> st;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];

        if (input[i][1] == 'u')
        {
            int value;
            cin >> value;
            st.push(value);
        }
        else if (input[i][0] == 'p' && input[i][1] == 'o')
        {
            if (!st.empty())
            {
                printf("%d\n", st.top());
                st.pop();
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (input[i][0] == 's')
        {
            printf("%lu\n", st.size());
        }
        else if (input[i][0] == 'e')
        {
            printf("%d\n", st.empty());
        }
        else
        {
            if (!st.empty())
            {
                printf("%d\n", st.top());
            }
            else
            {
                printf("-1\n");
            }
        }
    }
    return 0;
}