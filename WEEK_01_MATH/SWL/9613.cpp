#include <stdio.h>
#include <memory.h> // memset

using namespace std;

// 유클리드 호제법
int GCD(int A, int B) {
	int tmp;
	while (B != 0) {
		tmp = A % B;
		A = B;
		B = tmp;
	}
	return A;
}

int main(void) {
	int t, n;
	long int answer;
	scanf("%d", &t);
	int arr[101];
	while (t--) {
		answer = 0;
		scanf("%d", &n);
		// memset 함수 : 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅하는 함수
		memset(arr, 0, n); // arr의 메모리를 입력받은 n 크기만큼 0으로 세팅
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				answer += GCD(arr[i], arr[j]);
			}
		}
		printf("%ld\n", answer);
	}
}
