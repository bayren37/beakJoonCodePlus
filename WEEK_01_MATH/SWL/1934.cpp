#include <cstdio>

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
	int T, A, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &A, &B);
		int lcm = A * B / GCD(A, B);
		printf("%d\n", lcm);
	}
}
