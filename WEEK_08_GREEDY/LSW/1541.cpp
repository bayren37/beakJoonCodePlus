// 잃어버린 괄호

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string word;
	bool isMinus = false;
	int index = 0, answer = 0;
	cin >> word;

	// 마이너스가 나온 시점부터 나오는 숫자들은 빼준다
	// 괄호의 개수가 정해져있지 않기 때문에
	for (int i = 0; i <= word.size(); i++) {
		if (word[i] == '+' || word[i] == '-' || word[i] =='\0') {
			if (isMinus) {
				answer += -stoi(word.substr(index, i - index + 1));
				index = i + 1;
			}
			else {
				answer += stoi(word.substr(index, i - index + 1));
				index = i + 1;
			}

			if (word[i] == '-') isMinus = true;
		}
	}

	printf("%d\n", answer);
}
