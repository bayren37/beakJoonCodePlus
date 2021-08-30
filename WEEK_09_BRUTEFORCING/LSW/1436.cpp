// 영화감독 숌

#include <cstdio>
#include <string>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int count = 1, num = 666;

	// 666부터 시작해서 count가 N이 될때까지 반복
	while (count != N) {
		num++;
		// int인 num을 string으로 바꾸고 666이 들어가는지 체크
		// std::string::npos는 string.find() 함수가 찾으려는게 없으면 반환하는 값
		if (to_string(num).find("666") != std::string::npos) {
			count++;
		}
	}
	printf("%d\n", num);
}
