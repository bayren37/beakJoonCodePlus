// 회의실 배정

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

bool compare(Pair a, Pair b) {
	if (a.second < b.second)
		return true;
	else if (a.second > b.second)
		return false;
	else
		return a.first < b.first;
}

int main(void) {
	int N, count = 1;
	scanf("%d", &N);
	vector<Pair> arr(N);

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	// 회의가 끝나는 시간을 기준으로 오름차순으로 정렬
	sort(arr.begin(), arr.end(), compare);

	// 비교를 위해 첫번째로 빨리 끝나는 첫번째 요소를 변수로 받아줌
	Pair tmp = arr[0];

	// 기존에 들어가있는 pair에서 끝나는 시간과 다른 회의의 시작하는 시간을 비교해서 카운팅
	for (int i = 1; i < N; i++) {
		if (tmp.second <= arr[i].first) {
			count++;
			tmp = arr[i];
		}
	}

	printf("%d\n", count);
}
