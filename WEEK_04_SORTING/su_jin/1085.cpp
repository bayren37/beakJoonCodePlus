
//직사각형에서 탈출
#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	int x, y, w, h;
	int arr[4];
	scanf("%d %d %d %d", &x, &y, &w, &h);
	//h-y : 위쪽, y: 아래쪽, w-x:오른쪽, x: 왼쪽
	arr[0] = h-y; arr[1] = y; arr[2] = w-x; arr[3] = x;
	sort(arr, arr + 4);
	printf("%d", arr[0]);
}
