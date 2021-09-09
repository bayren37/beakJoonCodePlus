#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, M;
	vector<int>v, v2;
	cin >> N;
	v = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int sum = 0;
	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum+= v[j];
		}
		v2[i] = sum;
		sum = 0; //ÃÊ±âÈ­
	}
	for (int i = 0; i < N; i++) {

		cout << v2[i];
	}
	return 0;
}