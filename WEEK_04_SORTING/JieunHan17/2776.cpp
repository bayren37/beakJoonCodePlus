#include <cstdio>
#include <algorithm>

#define MAX 1000001

using namespace std;

bool binarySearch(int array[], int target, int left, int right)
{
    if (left > right)
    {
        return false;
    }
    int mid = (left + right) / 2;
    if (array[mid] == target)
    {
        return true;
    }
    else if (array[mid] < target)
    {
        return binarySearch(array, target, mid + 1, right);
    }
    else
    {
        return binarySearch(array, target, left, mid - 1);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N, M;
        scanf("%d", &N);

        int diary1[MAX];
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &diary1[j]);
        }

        scanf("%d", &M);
        int diary2[MAX];
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &diary2[j]);
        }

        sort(diary1, diary1 + N);

        for (int j = 0; j < M; j++)
        {
            bool flag = binarySearch(diary1, diary2[j], 0, N - 1);
            if (flag)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
    }
    return 0;
}