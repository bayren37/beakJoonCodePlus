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
        checkX[x]++;
        checkY[y]++;
    }

    for (int i = 0; i < checkX.size(); i++)
    {
        if (checkX[i] >= 2)
        {
            cnt++;
        }
    }

    for (int i = 0; i < checkY.size(); i++)
    {
        if (checkY[i] >= 2 && checkX[i] < 2)
        {
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}