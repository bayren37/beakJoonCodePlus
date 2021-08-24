// 로프

#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, Max = 0;
	scanf("%d", &N);
	
	// N개의 배열 선언
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	// 배열을 내림차순으로 정렬
	sort(arr, arr + N, greater<>());

	// (로프의 개수 * 로프중 가장 작은 수) 값을 Max 값과 비교하며 큰 값으로 갱신
	for (int i = 0; i < N; i++) {
		Max = max(arr[i] * (i + 1), Max);
	}

	printf("%d\n", Max);
}
