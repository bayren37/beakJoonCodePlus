#include<string>
#include<vector>
#include<iostream>

using namespace std;

void solution(vector<int>numbers, string hand) {

	vector<string>hands(numbers.size());
	int locationL = -1, locationR = -1;
	//처음 위치 초기화


	for (int i = 0; i < numbers.size(); i++)
	{
		//왼쪽 손 기준
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			hands[i] == "L";
			locationL = numbers[i];
		}
		if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			hands[i] == "R";
			locationR = numbers[i];
		}
		if (numbers[i] == 2) {
			int dis;

			if (locationL == 1 || locationL == 4 || locationL == 5) {
				hands[i] = "L";
				locationL = numbers[i];
			}
			//왼쪽 거리가 2인경우
			else if (locationL == 8) {
				if (locationR == 3 || locationR == 6 || locationR == 5) {
					hands[i] = "R";
					locationR = numbers[i];
				}
				else {
					hands[i] = "L";
					locationL = numbers[i];
				}
			}

			//왼쪽 거리가 3인경우
			else if (locationL == 7 || locationL == 0) {
				if (locationR == 9 || locationR == 0) {
					hands[i] = "L";
					locationL = numbers[i];
				}
				else {
					hands[i] = "R";
					locationR = numbers[i];
				}
			}

		}
	

	}
	for (int i = 0; i < numbers.size(); i++) {
		cout << hands[i];
	}
}

int main() {
	solution({ 7,0,8,2,8,3,1,5,7,6,2 }, "left");
	return 0;
}
