// 듣보잡

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M, count = 0;
	cin >> N >> M;
	unordered_map<string,int> arr;
	string tmp;
	vector<string> answer;
	for (int i = 0; i < N + M; i++) {
		cin >> tmp;
		if (arr.find(tmp) != arr.end()) {
			answer.push_back(tmp);
			count++;
		}
		else
			arr[tmp] = 0;
	}

	cout << count << '\n';

	sort(answer.begin(), answer.end());

	for (auto i : answer) {
		cout << i << '\n';
	}
}
