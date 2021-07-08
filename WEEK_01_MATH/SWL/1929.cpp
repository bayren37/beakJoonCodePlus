#include <cstdio>
#include <memory.h>		// memset
#define SIZE 1000001	// 상수 SIZE 정의

using namespace std;

// 에라토스테네스의 체
void filter(bool arr[], int N, int M) {
	for (int i = 2; i <= N; i++) {
		if (arr[i]) continue;
		// 입력으로 받은 최소값보다 크면 출력
		if (i >= M) printf("%d\n", i);
		for (int j = i * 2; j <= N; j += i) {
			arr[j] = true;
		}
	}
}

int main(void) {
	int M, N;
	scanf("%d%d", &M, &N);
	bool arr[SIZE];
	// memset 함수 : 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅하는 함수
	memset(arr, false, N); // arr를 입력받은 N 크기만큼 false로 세팅

	filter(arr, N, M);
}
