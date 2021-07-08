#include <cstdio>
#define SIZE 1001	// 상수 SIZE 정의

using namespace std;

// 에라토스테네스의 체
void Era(bool arr[]) {
	for (int i = 2; i <= 1000; i++) {
		if (arr[i]) continue;
		for (int j = i + i; j <= 1000; j += i) {
			arr[j] = true;
		}
	}
}

int main() {
	int N, count = 0, index;
	scanf("%d", &N);
	bool arr[SIZE] = { false, };
	// 소수에는 0과 1이 포함 X (false가 소수)
	arr[0] = true, arr[1] = true;

	Era(arr);

	while (N--) {
		scanf("%d", &index);
		// 입력받은 값이 소수인지 판별하기 위해 arr의 index로 접근
		if (!arr[index])
			count += 1;
	}
	printf("%d\n", count);
}
