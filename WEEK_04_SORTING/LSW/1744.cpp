#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int t, n, sum = 0;
	vector<int> arr_p, arr_m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		n <= 0 ? arr_m.push_back(n): arr_p.push_back(n);
	}
	int size_m = arr_m.size(), size_p = arr_p.size();
	sort(arr_m.begin(), arr_m.end());
	sort(arr_p.begin(), arr_p.end());
	for (int i = 0; i < size_m - 1; i += 2) {
		sum += arr_m[i] * arr_m[i + 1];
	}
	if (size_m % 2 == 1)
		sum += arr_m[size_m - 1];
	for (int i = size_p - 1; i >= 1; i-=2) {
		if (arr_p[i - 1] == 1) {
			sum += arr_p[i] + arr_p[i - 1];
		}
		else {
			sum += arr_p[i] * arr_p[i - 1];
		}
	}
	if (size_p % 2 == 1)
		sum += arr_p[0];
	printf("%d\n", sum);
}
