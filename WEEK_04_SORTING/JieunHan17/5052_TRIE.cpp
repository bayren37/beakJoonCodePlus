#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct TRIE
{
    bool finish;
    TRIE *node[10];
    TRIE()
    {
        finish = false;
        for (int i = 0; i < 10; i++)
        {
            node[i] = 0;
        }
    }

    void insert(char *input)
    {
        if (*input == '\0')
        {
            finish = true;
            return;
        }

        int cur = *input - '0';
        if (node[cur] == NULL)
        {
            node[cur] = new TRIE();
        }
        node[cur]->insert(input + 1);
    }

    bool find(char *input)
    {
        if (*input == '\0')
            return true;
        if (finish == true)
            return false;

        int cur = *input - '0';
        return node[cur]->find(input + 1);
    }
};

char *erase(char *array)
{
    char *result = (char *)malloc(sizeof(char) * 11);
    int len = strlen(array);
    int idx = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] == ' ')
        {
            continue;
        }
        result[idx] = array[i];
        idx++;
    }
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        char arr[10001][11];
        TRIE *root = new TRIE();

        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf(" %[^\n]", arr[j]);
            strcpy(arr[j], erase(arr[j]));
            root->insert(arr[j]);
        }

        bool result = false;
        for (int j = 0; j < n; j++)
        {
            result = root->find(arr[j]);
            if (!result)
            {
                printf("NO\n");
                break;
            }
        }
        if (result)
        {
            printf("YES\n");
        }
    }
    return 0;
}