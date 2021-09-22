// 팰린드롬인지 확인하기

#include <string>
#include <iostream>

using namespace std;

int main(void) {
	string word;
	cin >> word;

	int size = word.size() - 1;
	bool isPal = true;

	for (int i = 0; i < size / 2 + 1; i++) {
		if (word[i] != word[size - i]) {
			isPal = false;
			break;
		}
	}

	isPal ? cout << "1\n" : cout << "0\n";
}
