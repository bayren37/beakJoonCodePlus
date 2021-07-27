#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool isCorrect;

bool compare(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

struct TRIE {
	bool Finish;
	TRIE* Node[10];
	TRIE() {
		Finish = false;
		for (int i = 0; i < 10; i++) Node[i] = NULL;
	}
	void Insert(char* Str) {
		if (*Str == NULL) {
			Finish = true;
			return;
		}
		else if (*Str == ' ') {
			Insert(Str + 1);
			return;
		}
		int Cur = *Str - '0';
		if (Node[Cur] == NULL) Node[Cur] = new TRIE();
		if (Finish) isCorrect = false;
		Node[Cur]->Insert(Str + 1);
	}
	void clear() {
		for (int i = 0; i < 10; i++) Node[i] = NULL;
	}
};

int main(void) {
	int t, n;
	char num[20];
	cin >> t;
	TRIE arr;
	vector<string> pool;
	while (t--) {
		isCorrect = true;
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cin.getline(num, 20, '\n');
			pool.push_back(num);
		}
		sort(pool.begin(), pool.end(), compare);
		for (int i = 0; i < n; i++) {
			strcpy(num, pool[i].c_str());
			arr.Insert(num);
		}
		if (isCorrect)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		arr.clear();
		pool.clear();
	}
}
