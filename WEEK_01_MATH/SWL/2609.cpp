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
	int A, B;
	scanf("%d%d", &A, &B);

	// GCD (Greatest Common Divisor)
	int gcd = GCD(A, B);
	// LCM (Least Common Multiple)
	int lcm = A * B / gcd;
	printf("%d\n%d\n", gcd, lcm);
}
