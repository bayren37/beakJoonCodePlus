#include <cstdio>

using namespace std;

int parent[1000001];

int my_find(int target)
{
    if (target == parent[target])
    {
        return target;
    }
    return parent[target] = my_find(parent[target]);
}

void my_union(int num1, int num2)
{
    int parent1 = my_find(num1);
    int parent2 = my_find(num2);
    if (parent1 < parent2)
    {
        parent[parent2] = parent1;
    }
    else if (parent1 > parent2)
    {
        parent[parent1] = parent2;
    }
}

int main()
{
    int n, m;
    int input1, input2, input3;

    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &input1, &input2, &input3);
        if (input1 == 0)
        {
            my_union(input2, input3);
        }
        else
        {
            if (my_find(input2) == my_find(input3))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }

    return 0;
}