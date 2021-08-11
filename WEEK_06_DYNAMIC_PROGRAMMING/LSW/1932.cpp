#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> save;

int main(void) {
	int N;
	scanf("%d", &N);
	arr= vector<vector<int>>(N);
	save = vector<vector<int>>(N);
	for (int i = 0; i < N; i++) {
		arr[i].assign(i + 1, 0);
		save[i].assign(i + 1, 0);
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		save[N - 1][i] = arr[N - 1][i];
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			save[i - 1][j] = arr[i-1][j] + max(save[i][j], save[i][j + 1]);
		}
	}

	printf("%d\n", save[0][0]);
}
