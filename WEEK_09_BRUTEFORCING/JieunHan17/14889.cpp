#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 21
#define LIMIT 98765

using namespace std;

int N;
int S[MAX][MAX];

int compare(vector<int> startTeam, vector<int> linkTeam)
{
    int start = 0, link = 0;

    for (int i = 0; i < N / 2 - 1; i++)
    {
        for (int j = i + 1; j < N / 2; j++)
        {
            start += S[startTeam[i]][startTeam[j]];
            start += S[startTeam[j]][startTeam[i]];
        }
    }

    for (int i = 0; i < N / 2 - 1; i++)
    {
        for (int j = i + 1; j < N / 2; j++)
        {
            link += S[linkTeam[i]][linkTeam[j]];
            link += S[linkTeam[j]][linkTeam[i]];
        }
    }

    return start < link ? link - start : start - link;
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &S[i][j]);
        }
    }

    vector<int> v;
    v.reserve(N);
    for (int i = 1; i <= N; i++)
    {
        v.push_back(i);
    }

    vector<int> temp;
    v.reserve(N);
    for (int i = 1; i <= N / 2; i++)
    {
        temp.push_back(1);
    }
    for (int i = 1; i <= N / 2; i++)
    {
        temp.push_back(0);
    }

    sort(temp.begin(), temp.end());

    int minimum = LIMIT;
    do
    {
        vector<int> startTeam, linkTeam;
        startTeam.reserve(N / 2);
        linkTeam.reserve(N / 2);

        for (int i = 0; i < N; i++)
        {
            if (temp[i] == 1)
            {
                startTeam.push_back(v[i]);
            }
            else
            {
                linkTeam.push_back(v[i]);
            }
        }

        minimum = min(compare(startTeam, linkTeam), minimum);
    } while (next_permutation(temp.begin(), temp.end()));

    printf("%d\n", minimum);

    return 0;
}
