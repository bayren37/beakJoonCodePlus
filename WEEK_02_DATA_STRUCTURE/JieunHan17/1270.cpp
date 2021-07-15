#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int Ti;
        scanf("%d", &Ti);

        //     long long soldiers[Ti];
        //     for (int j = 0; j < Ti; j++)
        //     {
        //         scanf("%lld", &soldiers[j]);
        //     }
        //     sort(soldiers, soldiers + Ti);

        //     int cnt = 1;
        //     bool flag = false;
        //     for (int j = 0; j < Ti - 1; j++)
        //     {
        //         if (soldiers[j] == soldiers[j + 1])
        //         {
        //             cnt++;
        //         }
        //         else
        //         {
        //             cnt = 1;
        //         }
        //         if (cnt > Ti / 2)
        //         {
        //             printf("%lld\n", soldiers[j]);
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if (!flag)
        //     {
        //         printf("SYJKGW\n");
        //     }

        unordered_map<long long, int> soldiers;
        for (int j = 0; j < Ti; j++)
        {
            long long num;
            scanf("%lld", &num);
            soldiers[num]++;
        }

        bool flag = false;
        unordered_map<long long, int>::iterator iter;
        for (iter = soldiers.begin(); iter != soldiers.end(); iter++)
        {
            if ((*iter).second > Ti / 2)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            printf("%lld\n", (*iter).first);
        }
        else
        {
            printf("SYJKGW\n");
        }
    }
    return 0;
}