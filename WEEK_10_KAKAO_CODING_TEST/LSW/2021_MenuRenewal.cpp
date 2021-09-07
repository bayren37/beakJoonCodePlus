#include <vector>
#include <string>
#include <map>

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

vector<char> arr;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> result;

	for (string tmp : orders) {
		split(tmp);
	}
	
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


	}

	return result;
}
