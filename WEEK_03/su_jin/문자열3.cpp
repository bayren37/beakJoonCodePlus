/*

//백준_문자열_1264번

#include<iostream>
#include<string>

using namespace std;
int main() {
	char s[256]; //한 줄 최대 255글자
	int cnt = 0;
	while (1) {
		cin.getline(s, 256);
		//입력의 끝의 한줄에 #만 입력받을 때 입력종료
		if (s[0] == '#') { return 0; }

		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == 'a' || s[i] == 'A') { cnt++; }
			if (s[i] == 'e' || s[i] == 'E') { cnt++; }
			if (s[i] == 'i' || s[i] == 'I') { cnt++; }
			if (s[i] == 'o' || s[i] == 'O') { cnt++; }
			if (s[i] == 'u' || s[i] == 'U') { cnt++; }
		}
		cout << cnt << "\n";
		cnt = 0;
	}
}
*/