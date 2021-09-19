// 균형잡힌 세상

#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	string PS;
	stack<char> stc;
	bool isCorrect;

	while (true) {
		isCorrect = true;
		getline(cin, PS, '\n');
		if (PS == ".") break;
		for (int i = 0; i < PS.size(); i++) {
			if (isalpha(PS[i]) || PS[i] == ' ') continue;
			if (PS[i] == '(') stc.push(PS[i]);
			else if (PS[i] == '[') stc.push(PS[i]);
			else if (PS[i] == ')') {
				if (stc.empty() || stc.top() != '(') {
					isCorrect = false;
					break;
				}
				else if (stc.top() == '(')
					stc.pop();
			}
			else if (PS[i] == ']') {
				if (stc.empty() || stc.top() != '[') {
					isCorrect = false;
					break;
				}
				else if (stc.top() == '[')
					stc.pop();
			}
		}
		isCorrect&& stc.empty() ? cout << "yes\n" : cout << "no\n";
		while (!stc.empty())
			stc.pop();
	}
}
