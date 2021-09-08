#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<char, int> alpha;

void split(string str) {
	for (char tmp : str) {
		if (alpha.find(tmp) != alpha.end()) {
			alpha[tmp]++;
		}
		else {
			alpha[tmp] = 1;
		}
	}
}


int compare(vector<string> orders, string result) {
	bool isCorrect;
	int count=0;

	for (string i : orders) {
		isCorrect = true;
		for (char j : result) {
			if (i.find(j) == string::npos) {
				isCorrect = false;
				break;
			}
		}
		if (isCorrect)
			count++;
	}

	return count;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	for (string tmp : orders) {
		split(tmp);
	}

	vector<string> answer;
	vector<char> arr;

	vector<pair<int, string>> store;

	for (pair<char, int> pair : alpha) {
		if (pair.second >= 2)
			arr.push_back(pair.first);
	}

	vector<bool> check(arr.size(), false);

	for (int i : course) {
		for (int j = 0; j < i; j++) {
			check[j] = true;
		}
		for (int j = i; j < arr.size(); j++) {
			check[j] = false;
		}

		string tmp;
		int count;
		do {
			tmp = "";
			for (int j = 0; j < arr.size(); j++) {
				if (check[j])
					tmp += arr[j];
			}

			count = compare(orders, tmp);

			if (count >= 2) {
				store.push_back(make_pair(count, tmp));
			}

		} while (prev_permutation(check.begin(), check.end()));

		

		sort(store.begin(), store.end());

		count = store.rbegin()->first;
	
		for (auto j = store.rbegin(); j != store.rend(); j++) {
			if (count == j->first)
				answer.push_back(j->second);
			else
				break;
		}
		store.clear();
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main(void) {
	vector<vector<string>> orders = { {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"},
		{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"},
		{"XYZ", "XWY", "WXA"} };

	vector<vector<int>> course = { {2,3,4},{2,3,5},{2,3,4} };

	for (int i = 0; i < 3; i++) {
 		for (auto j : solution(orders[i], course[i])) {
			cout << j << " ";
		}
		cout << '\n';
	}
}
