#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

#define MAX 101

using namespace std;

int N;
int height[MAX][MAX] = {
    0,
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int getNumOfSafeZone(int rainHeight)
{
    bool isFlooded[MAX][MAX] = {
        false,
    };
    bool isVisited[MAX][MAX] = {
        false,
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (height[i][j] <= rainHeight)
            {
                isFlooded[i][j] = true;
            }
        }
    }

    queue<pair<int, int> > q;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!isFlooded[i][j] && !isVisited[i][j])
            {
                q.push(make_pair(i, j));
                isVisited[i][j] = true;
                while (!q.empty())
                {
                    int curX = q.front().second;
                    int curY = q.front().first;
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int nextX = curX + dx[i];
                        int nextY = curY + dy[i];
                        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && !isVisited[nextY][nextX] && !isFlooded[nextY][nextX])
                        {
                            q.push(make_pair(nextY, nextX));
                            isVisited[nextY][nextX] = true;
                        }
                    }
                }
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    scanf("%d", &N);

    int maxHeight = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &height[i][j]);
            maxHeight = max(maxHeight, height[i][j]);
        }
    }

    int maxNumOfAreas = 0;
    for (int i = 0; i <= maxHeight; i++)
    {
        maxNumOfAreas = max(maxNumOfAreas, getNumOfSafeZone(i));
    }

    printf("%d\n", maxNumOfAreas);

    return 0;
}