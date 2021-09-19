// 30

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
	string num;
	cin >> num;
	sort(num.begin(), num.end(), greater<>());
	if (*num.rbegin() != '0') {
		cout << "-1\n";
		return 0;
	}
	else
		num = num.substr(0, num.size() - 1);
	
	string tmp="";
	for (int i = 0; i < num.size(); i++) {
		tmp += num[i];
		tmp = to_string(stoi(tmp) % 3);
	}
	stoi(tmp) == 0 ? cout << num << "0\n" : cout << "-1\n";
}
