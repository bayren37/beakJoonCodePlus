#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char input1[4001], input2[4001];
    scanf("%s", input1);
    scanf("%s", input2);

    int len1 = strlen(input1), len2 = strlen(input2);
    int max = 0;
    int cnt = 0;
    for (int i = (len1 - 1); i >= -(len2 - 1); i--)
    {
        for (int j = 0; j < len2; j++)
        {
            int idx = i + j;
            if (idx > len1 - 1)
            {
                break;
            }
            if (idx < 0)
            {
                continue;
            }

            if (input1[idx] == input2[j])
            {
                cnt++;
            }
            else
            {
                if (cnt > max)
                {
                    max = cnt;
                }
                cnt = 0;
            }
        }
        if (cnt > max)
        {
            max = cnt;
        }
        cnt = 0;
    }

    printf("%d\n", max);

    return 0;
}