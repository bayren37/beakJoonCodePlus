/*
//공유 문제

//백준_문자열_1652번

#include<iostream>

using namespace std;

string s;
int row_cnt, col_cnt, N, cnt;
char a[101][101];

int main(){
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		cnt = 0; //공백공간 수

		//가로 누울 자리 찾는 loop문
		for (int j = 0; j < s.size(); j++) {
			//행우선순위로 순차적으로 s[j]선언
			a[i][j] = s[j];

			if (a[i][j] == '.') {
				cnt++;
			}
			else {
				//즉 짐이 존재할 때, 
				if (cnt >= 2) {
					//짐과 만나면서 공백자리가 2칸이상일 때,
					col_cnt++; //누울 자리 찾았다 !
					cnt = 0; //공백공간 초기화
				}
			}
		}

		//짐을 만나지 않고 그저 공백이 2칸이상 일 때, 즉 벽을 만났을 때
		if (cnt >= 2) { col_cnt++; }
	}
	//세로 누울 자리 찾는 loop문
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			//열 우선 순위로 순차적 s[j]선언
			if (a[j][i] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) {
					row_cnt++;
					cnt = 0;
				}
			}
		}

		//짐을 만나지 않고 그저 공백이 2칸이상 일 때, 즉 벽을 만났을 때
		if (cnt >= 2) { col_cnt++; }

	}
	
	cout << col_cnt << " " << row_cnt;

}

*/