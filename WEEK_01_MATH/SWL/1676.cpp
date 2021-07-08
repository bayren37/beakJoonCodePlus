#include <cstdio>

using namespace std;

int main(void) {
	int N, current;
	scanf("%d", &N);
	// 10을 만들기 위해서는 2, 5 하나씩 필요
	int cnt_2 = 0, cnt_5 = 0;
	for (int i = 1; i <= N; i++) {
		current = i;
		// i에 포함된 2의 개수
		while (current % 2 == 0) {
			cnt_2 += 1;
			current /= 2;
		}
		// i에 포함된 5의 개수
		while (current % 5 == 0) {
			cnt_5 += 1;
			current /= 5;
		}
	}
	// 삼항연산자 (2의 개수와 5의 개수 중 작은 값이 10을 만들 수 있는 최대 개수)
	printf("%d\n", cnt_2 < cnt_5 ? cnt_2 : cnt_5);
}
