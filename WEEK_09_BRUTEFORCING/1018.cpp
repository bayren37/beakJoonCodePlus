#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//체스판 다시 칠하기
int arr[55][55]; //보기편하게 0,1로 치환한 배열
int board1[8][8], board2[8][8]; 
int ans; //최소값, min저장

//정답의 체스판 예제 2가지 경우
//board1은 1행1열이 0(White)로 시작되는 체스판 
//board2는 1행1열이 1(Black)으로 시작되는 체스판


void compare(int a, int b) {
	int count1 = 0, count2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board1[i][j] != arr[a + i][b + j]) { count1++; }
			if (board2[i][j] != arr[a + i][b + j]) { count2++; }

		}
	}
	ans = min(count1, count2);
}
 
int main() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //시간초과안걸리기 위해
	int N, M;
	string s;
	
	cin >> N >> M;
	//white->0, black->1
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'B') { arr[i][j] == 1; }
			else arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//board1은 0부터 시작~
			if ((i + j) % 2 == 0) { board1[i][j] == 0; }
			else board1[i][j] == 1;
			//board2는 1부터 시작~
			if ((i + j) % 2 == 1) { board2[i][j] == 1; }
			else board2[i][j] == 0;
		}
	}
	for (int i = 0; i + 8 < N; i++) {
		for (int j = 0; i + 8 < M; j++) { //부등호
			compare(i, j); // 함수호출
		}
	}

	cout << ans;
	return 0;
}




