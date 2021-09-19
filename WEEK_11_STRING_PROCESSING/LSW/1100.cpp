// 하얀 칸

#include <string>
#include <iostream>

using namespace std;

int main(void) {
	bool isWhite = true;
	string tmp;
	int count = 0;

	for (int i = 0; i < 8; i++) {
		cin >> tmp;

		for (char ch : tmp) {
			if (!isWhite) {
				isWhite = true;
				continue;
			}
			else if (isWhite) {
				isWhite = false;
				if (ch == 'F')
					count++;
			}
		}
		isWhite = !isWhite;
	}

	cout << count << '\n';
}
