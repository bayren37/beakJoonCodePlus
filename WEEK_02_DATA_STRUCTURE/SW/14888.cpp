//연산자 끼워넣기

#include <cstdio>
#include <vector>
#include <algorithm>
#define INT_MIN	-1000000000
#define INT_MAX	1000000000

using namespace std;

char Operator[] = { '+' ,'-','*','/' };

int main(void) {
	int N, x, cnt, Max = INT_MIN, Min = INT_MAX;
	vector<int> arr;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &x);
		arr.push_back(x);
	}
	vector<char> Op;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &cnt);
		while (cnt--) {
			Op.push_back(Operator[i]);
		}
	}
	int size = Op.size();
	sort(Op.begin(), Op.end());
	do {
		int result = arr[0];
		for (int i = 0; i < size; i++) {
			switch (Op[i])
			{
			case '+':
				result += arr[i + 1];
				break;
			case '-':
				result -= arr[i + 1];
				break;
			case '*':
				result *= arr[i + 1];
				break;
			case '/':
				result /= arr[i + 1];
				break;
			default:
				break;
			}
		}
		Min = min(Min, result);
		Max = max(Max, result);
	} while (next_permutation(Op.begin(), Op.end()));
	printf("%d\n%d\n", Max, Min);
}
