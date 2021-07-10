#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    queue<int> input;
    vector<int> output;

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        input.push(i + 1);
    }

    while (!input.empty())
    {
        for (int i = 0; i < K; i++)
        {
            int cur = input.front();
            input.pop();
            if (i != K - 1)
            {
                input.push(cur);
            }
            else
            {
                output.push_back(cur);
            }
        }
    }

    printf("<");
    for (int i = 0; i < output.size(); i++)
    {
        if (i == output.size() - 1)
        {
            printf("%d>", output[i]);
        }
        else
        {
            printf("%d, ", output[i]);
        }
    }

    return 0;
}

/* 벡터 이용 방법 */
// int main()
// {
//     int N, K;
//     vector<int> input;
//     vector<int> output;

//     scanf("%d %d", &N, &K);
//     for (int i = 0; i < N; i++)
//     {
//         input.push_back(i + 1);
//     }

//     int idx = -1;
//     while (!input.empty())
//     {
//         for (int i = 0; i < K; i++)
//         {
//             idx++;
//             if (idx >= input.size())
//             {
//                 idx = 0;
//             }
//         }
//         output.push_back(input[idx]);
//         input.erase(input.begin() + idx);
//         idx--;
//     }

//     printf("<");
//     for (int i = 0; i < output.size(); i++)
//     {
//         if (i == output.size() - 1)
//         {
//             printf("%d>", output[i]);
//         }
//         else
//         {
//             printf("%d, ", output[i]);
//         }
//     }
//     return 0;
// }