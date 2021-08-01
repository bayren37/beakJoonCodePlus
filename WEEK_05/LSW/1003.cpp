#include <cstdio>
#include <vector>

using namespace std;

// pair를 매번 작성하는게 불편해서 별명 개념의 typedef를 선언
typedef pair<int, int> type;

// 메모이제이션을 위해 pair 배열을 선언
type arr[41] = { type(0,0), };

// pair를 연산하기 위해서 first, second를 더해준 pair값을 반환하는 함수 선언
type type_plus(type a, type b) {
	type result;
	result.first = a.first + b.first;
	result.second = a.second + b.second;
	return result;
}

// pair를 반환하는 피보나치 함수를 작성
type fibo(int N) {
	// 0일때 pair<int,int> (1,0) 반환
	if (N == 0) return type(1, 0);
	// 1일때 pair<int,int> (0,1) 반환
	else if (N == 1) return type(0, 1);
	/*arr를 선언할때 pair<int, int>(0, 0)로 초기화했기 때문에 0, 0이 아니라면
	기억되어 있는 값을 불러옴*/ 
	if (arr[N] != type(0, 0)) return arr[N];
	// N-1의 pair값과 N-2의 pair값을 더한값을 N에 집어넣음
	return arr[N] = type_plus(fibo(N - 1), fibo(N - 2));
}

int main(void) {
	int T, N;
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &N);
		type answer = fibo(N);
		printf("%d %d\n", answer.first, answer.second);
	}
}
