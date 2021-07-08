#include <cstdio>
#define SIZE 1000001

using namespace std;

// 에라토스테네스의 체
// 문제에 홀수 소수라 언급이 되어있기 때문에 홀수만 사용
void filter(bool check[], int n) {
	for (int i = 3; i <= n; i += 2) {
		if (check[i]) continue;
		for (int j = 3; i * j <= n; j += 2) {
			check[i * j] = true;
		}
	}
}

int main(void) {
	int n, Num;
	bool check[SIZE] = { false, };

	filter(check, SIZE);

	// 무한반복
	while (true) {
		scanf("%d", &n);
		Num = 0;
		// 반복문 탈출조건
		if (n == 0) break;
		// 주어진 n값에서 i값과 n-i값이 모두 소수이면 추측이 맞음
		for (int i = 3; i <= n / 2; i += 2) {
			if (check[i]) continue;
			else if (!check[i] && !check[n - i]) {
				Num = i;
				break;
			}
		}
		// Num은 추측이 맞았을때 0이 아닌 값을 가지고 있어야함
		// 삼항연산자
		Num == 0 /*조건*/ ? printf("Goldbach's conjecture is wrong.\n") /*조건이 true일때*/
			: printf("%d = %d + %d\n", n, Num, n - Num) /*조건이 false일때*/;
	}
}
