#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, sum = 0, mid;
	scanf("%d", &N);
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		mid = 0;
		for (int j = 0; j <= i; j++) {
			mid += arr[j];
		}
		sum += mid;
	}
	printf("%d\n", sum);
}
