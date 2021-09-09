//백준_정렬_2752번
/*

#include<iostream>
using namespace std;

int main() {
	int a[3];
	int tmp;

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 2; i++) {
		if (a[i] > a[i+1]) {
			tmp = a[i+1];
			a[i+1] = a[i];
			a[i] = tmp;
		}
	}
	if (a[0] > a[1]) {
		tmp = a[1];
		a[1] = a[0];
		a[0] = tmp;
	}
	for (int i = 0; i < 3; i++) {
		cout << a[i];
	}
}
*/