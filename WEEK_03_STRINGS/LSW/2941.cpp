#include <bits/stdc++.h>

using namespace std;

int main() {
	int count = 0;
	char x[100];
	scanf("%s", &x);
	for (int i = 0; i < strlen(x); i++) {
		if (i <= strlen(x) - 1) {
			if (x[i + 1] == 'j') {
				if (x[i] == 'l' || x[i] == 'n') {
					count++;
					i += 1;
				}
				else {
					count += 2;
					i += 1;
				}
			}
			else if (x[i + 1] == '-') {
				if (x[i] == 'c' || x[i] == 'd') {
					count++;
					i += 1;
				}
				else {
					count += 2;
					i += 1;
				}
			}
			else if (x[i + 1] == '=') {
				if (x[i] == 'c' || x[i] == 's') {
					count++;
					i += 1;
				}
				else if (x[i] == 'z') {
					if (i >= 1 && x[i - 1] == 'd') {
						i += 1;
					}
					else {
						count++;
						i += 1;
					}
				}
			}
			else {
				count++;
			}
		}
		else count++;
	}

	cout << count << '\n';

	return 0;
}
