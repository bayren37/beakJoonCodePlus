//N번째 큰 수

#include <cstdio>
#include <stack>
#define SIZE 1501
#define MIN -1000000000

using namespace std;

int main(void) {
	int N, x, cnt = 0, index, Max;
	scanf("%d", &N);
	stack<int> arr[SIZE];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &x);
			arr[j].push(x);
		}
	}

	while (cnt != N) {
		Max = MIN;
		for (int i = 0; i < N; i++) {
			if (Max < arr[i].top()) {
				index = i;
				Max = arr[i].top();
			}
		}
		arr[index].pop();
		cnt += 1;
	}
	printf("%d\n", Max);
}
