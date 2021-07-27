#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> coordinate1, pair<int, int> coordinate2)
{
    if (coordinate1.first == coordinate2.first)
    {
        return coordinate1.second < coordinate2.second;
    }
    else
    {
        return coordinate1.first < coordinate2.first;
    }
}

int main()
{
    int N;
    vector<pair<int, int> > coordinates;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        coordinates.push_back(make_pair(x, y));
    }
    sort(coordinates.begin(), coordinates.end(), compare);
    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", coordinates[i].first, coordinates[i].second);
    }
    return 0;
}