// 실패율

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<float, int> Pair;

bool compare(Pair a, Pair b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer(N + 2);
	vector<Pair> result(N);
	vector<int> print(N);

	float size = stages.size();

	for (int i = 0; i < size; i++) {
		answer[stages[i]]++;
	}

	for (int i = 1; i <= N; i++) {
		if (size != 0)
			result[i - 1].first = answer[i] / size;
		else
			result[i - 1].first = 0;
		result[i - 1].second = i;
		size -= answer[i];
	}

	sort(result.begin(), result.end(), compare);
    
	for (int i = 0; i < N; i++) {
		print[i] = result[i].second;
	}

	return print;
}
