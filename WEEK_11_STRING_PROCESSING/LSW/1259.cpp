// 팰린드롬수

#include <string>
#include <iostream>

using namespace std;

int main(void) {
	string num, answer;
	while (true) {
		cin >> num;
		if (num == "0") break;
		answer = "yes";
		auto j = num.rbegin();
		for (auto i = num.begin();i != num.end(); i++,j++) {
			if (*i != *j) {
				answer = "no";
				break;
			}
		}

		cout << answer << '\n';
	}
}
