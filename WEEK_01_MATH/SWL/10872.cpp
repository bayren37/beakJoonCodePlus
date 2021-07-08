#include <cstdio>

using namespace std;

int main(void) {
	int N, answer = 1;
	scanf("%d", &N);
	// N이 0이 되면 반복끝 (0 = false)
	while (N--) {
		answer *= (N + 1);
	}
	printf("%d\n", answer);
}
