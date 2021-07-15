//집합의 표현

#include <bits/stdc++.h>

using namespace std;

int parent[1000001];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

bool isSameParent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	int b, c;
	bool a;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a) {
			isSameParent(b, c) ? cout << "YES" << '\n' : cout << "NO" << '\n';
		}
		else{
			Union(b, c);
		}
	}

	return 0;
}
