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
	int A, B;
	scanf("%d%d", &A, &B);

	// LCM (Least Common Multiple)
	int lcm = LCM(A, B);
	// GCD (Greatest Common Divisor)
	int gcd = A * B / lcm;
	printf("%d\n%d\n", lcm, gcd);
}
