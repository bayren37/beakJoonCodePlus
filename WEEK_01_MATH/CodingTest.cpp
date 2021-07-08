/*
//1008번
#inlcude<iostream>
using namespace std;

int main() {
	int A, B;
	double C;
	cin >> A >> B;
	C = (double)A/(double)B;
	cout.precision(10); //(자릿수)정밀도, 반올림해줘서 정밀도 구함, cout의 precision의 default값은 6이다
	cout.fixed; //소수점 자릿수 정밀도 표!현! 
	cout << C << endl;
	return 0;
}


//10818번
#include<iostream>
using namespace std;

int main() {
	int min=0, max=0;
	int N;
	//N >= 1 && N < 10000;
	cin >> N;
	int num[10000];

	for (int i = 0; i < N; i++) {
		scanf_s("%d",&num[i]);
	}
	for (int i = 0; i < N; i++) {
		printf("%d ",num[i]);
	}
	max = num[0]; //max를 배열 첫 요소로 초기화
	for (int i = 1; i < N - 1; i++) {
		if (max < num[i])
		{
			max = num[i];
		}
	}
	min = num[0]; //min를 배열 첫 요소로 초기화
	for (int i = 1; i < N - 1; i++) {
		if (min > num[i]) {
			min = num[i];
		}
	}
	cout << endl << max << " " << min;
}

//4344번
#include<iostream>
using namespace std;
int main() {
	int C, sum = 0, count = 0;
	float avr, answer;
	cin >> C;
	int num[1000];
	for (int i = 0; i < C; i++) {
		cin >> num[i];
		sum = sum + num[i];
	}
	avr = (float)sum / C;
	printf("평균: %f", avr);

	for (int i = 0; i < C; i++) {
		if (num[i] > avr) {
			count++;
		}
	}

	cout << endl << "평균 넘은 사람 수: " << count<< endl;
	answer = ((float)count / C);
	cout.precision(5);
	cout.fixed;
	cout << answer*100 << "%";
}


//10179번
#include<iostream>
using namespace std;
int main() {
	int C;
	float num[10];
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> num[i];
		num[i] = num[i] * 0.8;
	}
	for (int i = 0; i < C; i++) {
		cout.precision(4);
		cout.fixed;
		cout << "$" << num[i] << endl;
	}
}


//10250번 
//ACM호텔 문제
#include<iostream>
using namespace std;

int main() {
	int C, H, W, N; //케이스, 행, 열, n번째 손님
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> H >> W >> N;
		//호수를 YYXX, YXX를 각 자리수를 x,y,z;
		int x, y;
		x = N % H; //층
		if (x == 0) { x = H; }
		y = int(N / H) + 1;
		cout << x;
		cout << y << endl; //y가 두자리 수가 나와야하는데? 예를 들면 2호가 아닌 02호
	}
}
*/

#include<iostream>
using namespace std;
int main() {
	int N, count;
	//N >= 3 && N <= 5000;
	cin >> N;
	for (int i = 0; i < 1000; i++) {
		if ((N % (5 * i))== 0) { //무게를 5의 배수로 나눈 나머지가 0이라면
			count = i;
		}
		if ((N % (5 * i)) % 3 == 0) { //무게를 5로 나눈 값이 3의 배수라면 
			count = i + ((N - (5 * i)) / 3);
		}
		/*
		if ((N % (3 * i)) == 0) { //무게를 3의 배수로 나눈 나머지가 0이라면
			count = i;
		}
		if ((N % (5 * i)) % 3 == 0) { //무게를 5로 나눈 값이 3의 배수라면 
			count = i + ((N - (5 * i)) / 3);
		}
		*/

		else
		{
			count = -1;
		}
	}
	cout << count << endl;
}





