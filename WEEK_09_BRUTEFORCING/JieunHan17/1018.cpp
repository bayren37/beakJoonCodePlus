#include <cstdio>
#include <vector>
#include <algorithm>

#define LIMIT 2501

using namespace std;

vector<vector<char> > white;
vector<vector<char> > black;

int compareWhite(vector<vector<char> > input, int startX, int startY)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (input[i + startY][j + startX] != white[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int compareBlack(vector<vector<char> > input, int startX, int startY)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (input[i + startY][j + startX] != black[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < 8; i++)
    {
        vector<char> temp;
        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0)
            {
                if (i % 2 == 0)
                {
                    temp.push_back('W');
                }
                else
                {
                    temp.push_back('B');
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    temp.push_back('B');
                }
                else
                {
                    temp.push_back('W');
                }
            }
        }
        white.push_back(temp);
    }

    for (int i = 0; i < 8; i++)
    {
        vector<char> temp;
        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0)
            {
                if (i % 2 == 0)
                {
                    temp.push_back('B');
                }
                else
                {
                    temp.push_back('W');
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    temp.push_back('W');
                }
                else
                {
                    temp.push_back('B');
                }
            }
        }
        black.push_back(temp);
    }

    vector<vector<char> > input;
    for (int i = 0; i < N; i++)
    {
        vector<char> temp;
        for (int j = 0; j <= M; j++)
        {
            char character;
            scanf("%c", &character);
            if (character != '\n')
            {
                temp.push_back(character);
            }
        }
        input.push_back(temp);
    }

    int minimum = LIMIT;
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int cnt = min(compareWhite(input, j, i), compareBlack(input, j, i));
            minimum = min(minimum, cnt);
        }
    }

    printf("%d\n", minimum);
    return 0;
}