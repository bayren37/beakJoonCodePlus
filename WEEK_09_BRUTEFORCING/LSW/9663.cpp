// N-QUEEN

#include <cstdio>

using namespace std;

int N, ans;
int *col;

// num값의 절대값을 반환하는 함수
int abs(int num){
  if(num>=0)
    return num;
  else
    return -num;
}

// 위아래, 대각선에 퀸이 있는지 확인하는 함수
// 좌우는 따로 찾아보지 않는다. (1차원 배열을 통해 해결하기 때문에)
// 1차원 배열이 가능한 이유는 배열의 같은 인덱스에 값이 들어갈 수 없기때문이다.
bool isPossible(int c) {
	for (int i = 1; i < c; i++) {
		// 같은 열에 있는지 확인
		// col[i]는 행 : i, 열 : col[i]의 값
		if (col[i] == col[c]) {
			return false;
		}
		// 대각선상에 있는 확인
		// 대각선에 있다면 행끼리 뺀값의 절대값과 열끼리 뺀값의 절대값이 같음
		if (abs(col[i] - col[c]) == abs(i - c)) {
			return false;
		}
	}
	// 위아래, 대각선에 없다면 놓을 수 있는 자리이기 때문에 true를 반환
	return true;
}

void dfs(int row) {
	// row가 N이라면 마지막열까지 간것이기 때문에 카운트를 해준다
	if (row == N) {
		ans++;
	}
	else {
		// 1~N까지 반복
		for (int i = 1; i <= N; i++) {
			// 열값이 가능한지 확인해준다.
			col[row + 1] = i;
			if (isPossible(row + 1)) {
				// 가능하다면 재귀를 통해 다음 행을 확인한다.
				dfs(row + 1);
			}
			// 자리에 놓을 수 없다면 0으로 초기화해준다.
			else {
				col[row + 1] = 0;
			}
		}
	}
	// 마지막에는 0으로 초기화해준다. (다음 dfs를 들어갈때 문제가 되지 않기 위해)
	col[row] = 0;
}

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		col = new int[N+1];
		// 1행을 1~N까지 넣어주면서 확인한다.
		col[1] = i;
		// 1행부터 dfs함수 시작
		dfs(1);
	}

	// 카운트한 값을 출력한다.
	printf("%d\n", ans);
}
