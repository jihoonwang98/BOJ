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
int flag[10];


void f(int curr, int cnt) {
	if (cnt == M) {
		for (int i = 1; i <= N; i++) {
			if (flag[i]) cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	if (curr == N + 1) return;

	flag[curr] = 1;
	f(curr + 1, cnt + 1);

	flag[curr] = 0;
	f(curr + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	f(1, 0);
}