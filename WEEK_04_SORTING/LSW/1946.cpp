#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int T, N, count, min;
	vector<pair<int, int>> arr;
	scanf("%d", &T);
	while (T--) {
		arr.clear();
		scanf("%d", &N);
		arr = vector<pair<int, int>>(N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &arr[i].first, &arr[i].second);
		}
		sort(arr.begin(), arr.end());
		count = 0;
		min = 1000001;
		for (int i = 0; i < N; i++) {
			if (min > arr[i].second) {
				count += 1;
				min = arr[i].second;
			}
		}
		printf("%d\n", count);
	}
}
