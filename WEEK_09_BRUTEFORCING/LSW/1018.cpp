// 체스판 다시 칠하기

#include <cstdio>
#include <vector>

using namespace std;

vector<vector<char>> arr;

// 8X8의 체스판을 체킹하는 함수
int check(int row, int col) {
	bool isWhite;
	int answer = 0;
	// 처음 (row,col)에 들어가는 색깔을 기준으로 시작
	// 처음이 W면 isWhite는 true, B면 isWhite는 false
	if (arr[row][col] == 'W') isWhite = true;
	else isWhite = false;

	// 주어지는 (row,col)에서 시작해서 (row+7,col+7)까지 
	// isWhite 변수를 통해 체킹하면서 카운트
	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8; j++) {

			/*if (isWhite && arr[row + i][col + j] == 'W') {
				isWhite = false;
			}
			else if (!isWhite && arr[row + i][col + j] == 'B') {
				isWhite = true;
			}*/

			// isWhite가 true면서 W가 아닌 경우 and isWhite가 false면서 B가 아닌 경우 
			if (!(isWhite && arr[row + i][col + j] == 'W') && !(!isWhite && arr[row + i][col + j] == 'B'))
				count++;
			// isWhite가 true면 false로  false면 true로 바꿔준다
			if (isWhite) isWhite = false;
			else isWhite = true;
		}

		// 한 행을 다돌고 answer에 count를 더해준다
		answer += count;

		// 현재 행의 마지막과 다음 행의 처음은 같아야 하기 때문에 isWhite를 바꿔준다.
		if (isWhite) isWhite = false;
		else isWhite = true;
	}

	// answer이 32보다 커지면 최솟값은 64-answer이 된다.
	// 두 가지의 경우의 수로 체스판을 만들 수 있기 때문에 가능
	// ex) BW로 시작하는 경우와 WB로 시작하는 경우 (정반대의 경우)
	if (answer > 32)
		answer = 64 - answer;

	return answer;
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	int Min = 32;

	arr = vector<vector<char>>(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("\n%c", &arr[i][j]);
		}
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			// check 함수를 통해 구해진 다시 칠해야 하는 값을 기존값과 비교하여 갱신한다.
			Min = min(Min, check(i, j));
		}
	}

	printf("%d\n", Min);
}
