// 명령 프롬프트

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<string> arr;
	string tmp, answer = "";

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[j][i] == arr[j + 1][i])
				continue;
			else {
				answer += '?';
				break;
			}
		}
		if (answer.size() == i)
			answer += tmp[i];
	}

	cout << answer << '\n';
}
