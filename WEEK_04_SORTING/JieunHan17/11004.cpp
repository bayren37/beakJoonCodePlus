#include <cstdio>

#define MAX 5000001

using namespace std;

long long A[MAX];
long long sortedA[MAX];

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
        {
            sortedA[k++] = A[i++];
        }
        else
        {
            sortedA[k++] = A[j++];
        }
    }

    if (i > mid)
    {
        while (j <= right)
        {
            sortedA[k++] = A[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            sortedA[k++] = A[i++];
        }
    }

    for (int idx = left; idx <= right; idx++)
    {
        A[idx] = sortedA[idx];
    }
}

void mergeSort(int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    mergeSort(0, N - 1);

    printf("%lld", A[K - 1]);

    return 0;
}