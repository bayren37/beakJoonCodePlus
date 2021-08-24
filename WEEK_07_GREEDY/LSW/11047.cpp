#include <cstdio>

using namespace std;

int main(void) {
	int N, K, x, count = 0, a[10];
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = N - 1; i >= 0; i--) {
		count += K / a[i];
		K %= a[i];
	}
	printf("%d\n", count);
}
