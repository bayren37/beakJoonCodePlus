#include <cstdio>
#include <algorithm>	// pair

using namespace std;

pair<long long, long long> count(long long n) {
	long long cnt_2 = 0, cnt_5 = 0, i = 0;
	// 매개변수 n까지의 2 개수
	for (i = 2; i <= n; i *= 2) {
		cnt_2 += n / i;
	}
	// 매개변수 n까지의 5 개수
	for (i = 5; i <= n; i *= 5) {
		cnt_5 += n / i;
	}
	// pair값으로 반환
	return { cnt_2,cnt_5 };
}

int main(void) {
	long long n, m;
	scanf("%lld %lld", &n, &m);

	// 조합 mCn : n! / ((n-m)! * m!)
	// pair 배열에 n, n-m, m의 2와 5의 개수를 받음
	pair<long long, long long> arr[3] = { count(n),count(m),count(n - m) };
	// *(곱하기)는 개수의 +, /(나누기)는 개수의 -
	printf("%lld\n", min(arr[0].first - arr[1].first - arr[2].first,
		arr[0].second - arr[1].second - arr[2].second));
}
