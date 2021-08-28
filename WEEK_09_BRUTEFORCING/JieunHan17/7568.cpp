#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<pair<int, int> > input;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        input.push_back(make_pair(x, y));
    }

    for (int i = 0; i < N; i++)
    {
        int rank = 1;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (input[i].first < input[j].first && input[i].second < input[j].second)
            {
                rank++;
            }
        }
        printf("%d ", rank);
    }

    return 0;
}