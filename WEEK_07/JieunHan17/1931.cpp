#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> input1, pair<int, int> input2)
{
    if (input1.second == input2.second)
    {
        return input1.first < input2.first;
    }
    return input1.second < input2.second;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<pair<int, int> > input;
    input.reserve(N);
    for (int i = 0; i < N; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        input.push_back(make_pair(start, end));
    }

    sort(input.begin(), input.end(), compare);

    int temp = 0, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (input[i].first >= temp)
        {
            cnt++;
            temp = input[i].second;
        }
    }

    printf("%d\n", cnt);
    return 0;
}