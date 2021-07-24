#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> p;
    for (int i = 0; i < N; i++)
    {
        int time;
        scanf("%d", &time);
        p.push_back(time);
    }

    sort(p.begin(), p.begin() + N);

    int sum[N], total = 0;
    sum[0] = p[0];
    total += sum[0];
    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1] + p[i];
        total += sum[i];
    }

    printf("%d", total);

    return 0;
}