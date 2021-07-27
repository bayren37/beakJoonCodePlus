#include <iostream>
#include <set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string S;
	set<string> arr;
	cin >> S;
	int size = S.size();
	for (int i = 0; i < size; i++) {
		arr.insert(S.substr(i, size - i));
	}
	for (string i : arr) {
		cout << i << '\n';
	}
}
