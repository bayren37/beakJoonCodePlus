// 퇴사

#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;

int main(void) {
	int N, answer = 0;
	scanf("%d", &N);
	vector<Pair> arr(N + 2, Pair(0, 0));

	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	// 뒤에서부터 시작
	for (int i = N; i >= 1; i--) {
		// 현재 인덱스에 있는 i와 인덱스 i의 걸리는 기간을 더한게 N+1을 넘어가면 
		// i 인덱스의 전값 (i+1)의 값으로 덮어쓴다. (사용할 수 없는 값이기 때문에 덮어씀)
		if (i + arr[i].first > N + 1) 
			arr[i].second = arr[i + 1].second;
		// 범위내에 있는 값이라면 현재 인덱스 i의 이익과 그전에 얻을 수 있는 i+arr[i] 인덱스의 이익을 더해
		// 그 전값 i+1의 이익과 비교하여 큰값으로 갱신한다.
		else {
			arr[i].second = max(arr[i + 1].second, arr[i].second + arr[i + arr[i].first].second);
			answer = max(answer, arr[i].second);
		}
	}

	printf("%d\n", answer);
}
