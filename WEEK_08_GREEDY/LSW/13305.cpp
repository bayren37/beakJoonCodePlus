// 주유소

#include <cstdio>
#include <vector>
#define MAX 1000000000

using namespace std;

// pair<int,int>의 별명 Pair를 만들어줌 (간편성)
typedef pair<long long int, int> Pair;

int main(void) {
	int N;
	// 서브태스크에서 int 범위보다 큰 값이 나오기 때문에 자료형을 long long int로 받음
	long long int sum = 0, Min = MAX;
	scanf("%d", &N);

	vector<Pair> arr(N);

	// N개의 도시 N-1개의 거리를 입력받음
	// N-1개의 도시는 pair값에서 second로 받음
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &arr[i].second);
	}
	// N개의 도시는 pair값에서 first로 받음
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i].first);
	}

	// 지나온 도시들의 기름값들 중에서 가장 작은 값으로 Min값을 갱신
	// 매 도시마다 갱신한 가장 싼 기름값에 다음에 가야할 거리의 길이를 곱해 값을 구함
	for (int i = 0; i < N - 1; i++) {
		Min = min(Min, arr[i].first);
		sum += Min * arr[i].second;
	}

	printf("%lld\n", sum);
}
