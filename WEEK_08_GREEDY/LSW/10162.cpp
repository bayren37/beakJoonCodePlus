// 전자레인지

#include <cstdio>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	
	// 5분 1분 10초 버튼 3가지를 초 기준으로 배열을 만듬
	int arr[] = { 300,60,10 };
	// 3가지 버튼의 카운트를 입력받을 배열
	int answer[3];

	// 버튼중의 가장 큰수인 300부터 시작해서 입력받은 T 값을 나눈 몫을 answer 저장
	for (int i = 0; i < 3; i++) {
		answer[i] = T / arr[i];
		T %= arr[i];
	}

	// 삼항연산자로 입력받은 값 T가 0이면 answer 배열 출력, 아니면 -1 출력 
	T == 0 ? printf("%d %d %d\n", answer[0], answer[1], answer[2]) : printf("-1\n");
}
