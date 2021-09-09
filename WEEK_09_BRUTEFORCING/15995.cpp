
#include<iostream>
using namespace std;
int main() {
	int a, m;
	cin >> a >> m;
	for (int i = 0; i < 10000; i++) {
		int sum = a * i;
		if (sum % m == 1) {
			cout << i;
			break;
		}

	}
	return 0;
	
}
