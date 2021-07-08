#include <cstdio>

using namespace std;

int LCM(int A, int B) {
	// 유클리드 호제법
	int tmp;
	while (B != 0) {
		tmp = A % B;
		A = B;
		B = tmp;
	}
	return A;
}

int main(void) {
	int T, A, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &A, &B);
		int gcd = A * B / LCM(A, B);
		printf("%d\n", gcd);
	}
}
