#include <iostream>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
	return a > b;
}

int main(void) {
	string N;
	cin >> N;

	sort(N.begin(), N.end(), compare);
	cout << N << '\n';
}
