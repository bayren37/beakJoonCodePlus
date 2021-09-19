// AC

#include <string>
#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	string command, string_arr;
	int num;
	deque<int> arr;
	bool isReverse;

	while (T--) {
		isReverse = false;
		cin >> command >> num >> string_arr;

		if (num==0) {
			if (command.find('D') != string::npos) {
				cout << "error\n";
				continue;
			}
		}

		stringstream ss(string_arr.substr(1, string_arr.size() - 2));
		string token;

		while (getline(ss, token, ','))
			arr.push_back(stoi(token));

		for (char ch : command ) {
			if (ch == 'R') {
				isReverse = !isReverse;
			}
			else if (arr.empty()) {
				arr.push_back(0);
				break;
			}
			else if (ch == 'D') {
				if (isReverse) {
					arr.pop_back();
				}
				else {
					arr.pop_front();
				}
			}
		}
		if (!arr.empty() && arr.front() == 0) {
			cout << "error\n";
		}
		else {
			if (isReverse) {
				cout << "[" ; 
				for (auto i = arr.rbegin(); i != arr.rend(); i++) {
					cout << *i;
					if (i != arr.rend() - 1)
						cout << ",";
				}
			}
			else {
				cout << "[";
				for (auto i = arr.begin(); i != arr.end(); i++) {
					cout << *i;
					if (i != arr.end() - 1)
						cout << ",";
				}
			}
			cout << "]\n";
		}
		arr.clear();
	}
}
