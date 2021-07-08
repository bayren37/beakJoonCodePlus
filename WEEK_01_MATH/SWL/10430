#include <stdio.h>
#include <map>

using namespace std;

int main(void) {
	// map 자료구조 사용 (key값을 char, value값을 int로 받음)
	map<char, int> Map;
	// A, B, C를 아스키코드로 key값에 입력하고 value 값은 사용자 입력을 받음
	for (int i = 0; i < 3; i++) {
		// 아스키코드 (65, A) (66, B) (67, C) ... (90, Z)
		scanf("%d", &Map[65 + i]);
	}
	// map 자료구조는 고유값인 Key를 통해 value에 접근 가능
	printf("%d\n%d\n%d\n%d\n", (Map['A'] + Map['B']) % Map['C'],
		((Map['A'] % Map['C']) + (Map['B'] % Map['C'])) % Map['C'],
		(Map['A'] * Map['B']) % Map['C'],
		((Map['A'] % Map['C']) * (Map['B'] % Map['C'])) % Map['C']
	);
}
