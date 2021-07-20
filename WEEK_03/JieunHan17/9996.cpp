#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int N, asterIdx;
    char pattern[101], input[101];

    scanf("%d", &N);

    scanf("%s", pattern);
    int patternLen = strlen(pattern);
    for (int i = 0; i < patternLen; i++)
    {
        if (pattern[i] == '*')
        {
            asterIdx = i;
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%s", input);
        int inputLen = strlen(input);

        //반례
        //1
        //abcd*cdef
        //abcdef
        if (inputLen < patternLen - 1)
        {
            printf("NE\n");
            continue;
        }

        int flag = true;
        for (int i = 0; i < asterIdx; i++)
        {
            if (input[i] != pattern[i])
            {
                flag = false;
                break;
            }
        }
        for (int i = inputLen - 1, j = patternLen - 1; j > asterIdx; i--, j--)
        {
            if (input[i] != pattern[j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            printf("DA\n");
        }
        else
        {
            printf("NE\n");
        }
    }
    return 0;
}