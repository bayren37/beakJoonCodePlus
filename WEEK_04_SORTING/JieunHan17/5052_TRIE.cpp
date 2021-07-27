#include <cstdio>
#include <algorithm>

using namespace std;

struct TRIE
{
    bool finish;
    TRIE *node[10];
    TRIE()
    {
        finish = false;
        fill(node, node + 10, nullptr);
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
            scanf("%s", arr[j]);
            root->insert(arr[j]);
        }

        bool result = false;
        for (int j = 0; j < n; j++)
        {
            result = root->find(arr[j]);
            if (!result)
            {
                printf("No\n");
                break;
            }
        }
        if (result)
        {
            printf("Yes\n");
        }
    }
    return 0;
}