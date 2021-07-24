#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> input;
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        input.push_back(num);
    }

    sort(input.begin(), input.begin() + N);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", input[i]);
    }
    return 0;
}