#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, K, M, V, C;
long total = 0;
priority_queue<int> jewel_price;
vector<int> bag;
vector<pair<int, int> > jewel; //무게, 가격

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        cin >> M >> V;
        jewel.push_back(make_pair(M, V));
    }

    for (int i = 0; i < K; i++)
    {
        cin >> C;
        bag.push_back(C);
    }

    sort(jewel.begin(), jewel.end(), compare);
    sort(bag.begin(), bag.end());

    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        for (int jewel_idx = idx; jewel_idx < N; jewel_idx++)
        {
            if (jewel[jewel_idx].first > bag[i])
            {
                break;
            }
            jewel_price.push(jewel[jewel_idx].second);
            idx++;
        }

        if (!jewel_price.empty())
        {
            total += jewel_price.top();
            jewel_price.pop();
        }
    }

    printf("%ld", total);

    return 0;
}