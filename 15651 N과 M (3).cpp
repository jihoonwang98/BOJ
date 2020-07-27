#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <algorithm>
#include <cmath>
#define NUM 1000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N, M;
int res[10];

void f(int curr) {
	if (curr == M) {
		for (int i = 0; i < M; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		res[curr] = i;
		f(curr + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	f(0);
}