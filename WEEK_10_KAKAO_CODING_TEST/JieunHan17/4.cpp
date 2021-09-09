#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAX 987654321

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int> > fares)
{
    int answer = 0;

    int d[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = MAX;
            }
        }
    }

    for (int i = 0; i < fares.size(); i++)
    {
        d[fares[i][0]][fares[i][1]] = fares[i][2];
        d[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int minimum = MAX;
    for (int i = 1; i <= n; i++)
    {
        if (d[s][i] == MAX)
        {
            continue;
        }
        int totalFare = d[s][i] + d[i][a] + d[i][b];
        minimum = min(minimum, totalFare);
    }

    answer = minimum;
    return answer;
}

//아래 방법은 시간 초과
//a와 b를 출발점으로 생각하면 될듯
/*
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>

#define MAX_NODE 201
#define MAX 987654321

using namespace std;

vector<pair<int, int> > graph[MAX_NODE];

int search(int start, int goal, int n)
{
    int d[n + 1];
    for (int i = 1; i <= n; i++)
    {
        d[i] = MAX;
    }

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while (!pq.empty())
    {
        int curFare = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (d[curNode] < curFare)
        {
            continue;
        }
        for (int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i].first;
            int nextFare = graph[curNode][i].second;
            int nextDist = curFare + nextFare;
            if (d[nextNode] > nextDist)
            {
                d[nextNode] = nextDist;
                pq.push(make_pair(-nextDist, nextNode));
            }
        }
    }

    return d[goal];
}

int solution(int n, int s, int a, int b, vector<vector<int> > fares)
{
    int answer = 0;

    for (int i = 0; i < fares.size(); i++)
    {
        graph[fares[i][0]].push_back(make_pair(fares[i][1], fares[i][2]));
        graph[fares[i][1]].push_back(make_pair(fares[i][0], fares[i][2]));
    }

    int d[n + 1];
    for (int i = 1; i <= n; i++)
    {
        d[i] = MAX;
    }

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, s));
    d[s] = 0;

    while (!pq.empty())
    {
        int curFare = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (d[curNode] < curFare)
        {
            continue;
        }
        for (int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i].first;
            int nextFare = graph[curNode][i].second;
            int nextDist = curFare + nextFare;
            if (d[nextNode] > nextDist)
            {
                d[nextNode] = nextDist;
                pq.push(make_pair(-nextDist, nextNode));
            }
        }
    }

    int minimum = MAX;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == MAX)
        {
            continue;
        }
        int fareToA = search(i, a, n);
        int fareToB = search(i, b, n);
        int totalFare = fareToA + fareToB + d[i];
        minimum = min(minimum, totalFare);
    }

    answer = minimum;
    return answer;
}
*/