//분해합
//규칙성을 찾은 후에는 코드짜는데에 쉬웠지만 범위때문에 for문을 7자리까지 모두 돌려야하나? 이런 고민
N = abc + a + b+ c 
N = 100*a + b*10 + c + a+ b+ c = 
#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int a = 0; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				for (int d = 0; d <= 9; d++) {
					for (int e = 0; e <= 9; e++) {
						for (int f = 0; f <= 9; f++) {
							for (int g = 0; g <= 9; g++) {
								while (N == 1000001 * a + 100001 * b + 10001 * c + 1001 * d + 101 * e + 11 * f + 2*g) {
									//if문썼는데 안되서 while문으로 변경함
									cout << 1000000 * a + 100000 * b + 10000*c+1000*d+100*e+10*f+g;
									return 0;

								}
							}
						}
					}
				}
			}
		}
	}

	cout << 0;
}
