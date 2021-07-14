#include <cstdio>
#include <map>

using namespace std;

/* 메모리 초과 */
int n, cnt = 0;
map<int, int> checkX;
map<int, int> checkY;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if (checkX.find(x) != checkX.end())
        {
            checkX.insert(make_pair(x, checkX[x]++));
        }
        else
        {
            checkX.insert(make_pair(x, 1));
        }

        if (checkY.find(y) != checkY.end())
        {
            checkY.insert(make_pair(y, checkY[y]++));
        }
        else
        {
            checkY.insert(make_pair(y, 1));
        }
        // checkX[x]++;
        // checkY[y]++;
    }

    map<int, int>::iterator iter;
    for (iter = checkX.begin(); iter != checkX.end(); iter++)
    {
        if ((*iter).second >= 2)
        {
            cnt++;
        }
    }
    // for (int i = 0; i < checkX.size(); i++)
    // {
    //     if (checkX[i] >= 2)
    //     {
    //         cnt++;
    //     }
    // }

    for (iter = checkY.begin(); iter != checkY.end(); iter++)
    {
        if ((*iter).second >= 2)
        {
            cnt++;
        }
    }
    // for (int i = 0; i < checkY.size(); i++)
    // {
    //     if (checkY[i] >= 2 && checkX[i] < 2)
    //     {
    //         cnt++;
    //     }
    // }

    printf("%d", cnt);

    return 0;
}