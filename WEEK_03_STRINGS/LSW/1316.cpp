#include <cstdio>
#include <string.h>
#include <algorithm>
#define SIZE 101

using namespace std;

int groupChecker(char* word, int index, int count) {
	for (int i = index + 1; i < strlen(word); i++) {
		if (word[index] == word[i]) {
			if (i - 1 == index && count == 2) {
				count += 1;
				return 0;
			}
			else if (i - 1 == index && count > 2) {
				index += 1;
				count -= 1;
			}
			else {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int N;
	int result = 0;
	scanf("%d", &N);

	while (N--) {
		char word[SIZE];
		scanf("%s", &word);
		for (int i = 0; i < strlen(word)- 1; i++) {
			int cnt = count(&word[0], &word[0]+strlen(word), word[i]);
			if (cnt > 1 && groupChecker(word, i, cnt)) {
				result -= 1;
				break;
			}
		}
		result += 1;
	}

	printf("%d", result);

	return 0;
}
