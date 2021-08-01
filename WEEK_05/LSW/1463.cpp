#include <cstdio>
#define MinValue 1000000

using namespace std;

// 최솟값
int Min = MinValue;

// 입력받은 N값과 상황마다 달라지는 카운트수를 매개변수로 받음
void dp(int n,int count) {
	// count가 Min보다 커진 상황은 더이상 진행할 필요가 없기때문에 return
	if (count >= Min) return;
	// 1이 되는게 끝나는 조건이기 때문에 카운트수와 Min값을 비교해 Min값을 갱신하고 종료
	if (n == 1) {
		if (Min > count) Min = count;
		return;
	}
	// 2로 나눴을때 그 다음 상황을 진행
	if (n % 2 == 0) {
		dp(n / 2, count + 1);
	}
	// 3으로 나눴을때 그 다음 상황을 진행
	if (n % 3 == 0) {
		dp(n / 3, count + 1);
	}
	// 1로 빼고 그 다음 상황 진행
	dp(n - 1, count + 1);
}

int main(void) {
	int N;
	scanf("%d", &N);
	
	dp(N, 0);

	printf("%d\n", Min);
}
