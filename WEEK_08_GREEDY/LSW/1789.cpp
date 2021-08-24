// 수들의 합

#include <cstdio>

using namespace std;

int main(void) {
	long long int S, index = 1, sum = 0;
	scanf("%lld", &S);

	// 무한반복문을 통해 sum값에 1씩 증가하는 index 값을 더해줌
	while (true) {
		sum += index;
		// sum과 S가 같으면 반복문 탈출
		if (sum == S) {
			break;
		}
		// sum이 S보다 크다면 최대값은 현재 index에서 마이너스 1 해주고 반복문 탈출
		else if (sum > S) {
			index -= 1;
			break;
		}
		index++;
	}
	printf("%lld\n", index);
}
