// 괄호

#include <string>
#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	string PS;
	int count;

	while (T--) {
		count = 0;
		cin >> PS;
		for (int i = 0; i < PS.size(); i++) {
			PS[i] == '(' ? count++ : count--;
			if (count < 0) break;
		}

		count == 0 ? cout << "YES\n" : cout << "NO\n";
	}
}
