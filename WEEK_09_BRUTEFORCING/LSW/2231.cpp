#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, tmp, sum, answer;
	scanf("%d", &N);
	
	// N의 생성값을 저장해줄 N크기의 벡터 배열
	vector<int> arr(N+1,0);


	for(int i=1;i<=N;i++) {
		tmp = i;
		// 새로 갱신된 tmp값이 N값을 넘어가기 전까지 계속 반복
		while (true) {
			// sum은 tmp에 각 자리수를 더하기 위한 변수
			// answer은 tmp값이 훼손되지 않게 두는 변수
			sum = tmp, answer = tmp;

			// tmp에 tmp 값인 sum의 각 자리수를 더해준다
			while (sum != 0) {
				tmp += sum % 10;
				sum /= 10;
			}

			// tmp가 N을 넘어가면 while문 탈출
			if (tmp > N) break;

			// arr를 0으로 초기화했기때문에 0값이라면 구한 값을 집어넣고
			// 0이 아니라면 기존값과 새로운 값의 최소값을 집어넣는다
			if (arr[tmp] == 0)
				arr[tmp] = answer;
			else {
				arr[tmp] = min(arr[tmp], answer);
				break;
			}
		}
	}

	// arr[N]을 출력한다. 만약 생성자가 없다면 0으로 초기화했기 때문에 0이 출력된다.
	printf("%d\n", arr[N]);
}
