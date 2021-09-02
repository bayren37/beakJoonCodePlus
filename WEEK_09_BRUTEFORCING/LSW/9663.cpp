// N-QUEEN

#include <cstdio>

using namespace std;

int N, ans;
int *col;

int abs(int num){
  if(num>=0)
    return num;
  else
    return -num;
}

bool isPossible(int c) {
	for (int i = 1; i < c; i++) {
		if (col[i] == col[c]) {
			return false;
		}
		if (abs(col[i] - col[c]) == abs(i - c)) {
			return false;
		}
	}
	return true;
}

void dfs(int row) {
	if (row == N) {
		ans++;
	}
	else {
		for (int i = 1; i <= N; i++) {
			col[row + 1] = i;
			if (isPossible(row + 1)) {
				dfs(row + 1);
			}
			else {
				col[row + 1] = 0;
			}
		}
	}
	col[row] = 0;
}

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		col = new int[15];
		col[1] = i;
		dfs(1);
	}

	printf("%d\n", ans);
}
