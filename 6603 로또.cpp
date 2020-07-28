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
#define NUM 10000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;
int K;
int S[20];
int flag[20];

void f(int curr, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < K; i++) {
			if (flag[i]) {
				cout << S[i] << ' ';
			}
		}
		cout << '\n';
		return;
	}
	if (curr >= K) return;

	flag[curr] = 1;
	f(curr + 1, cnt + 1);

	flag[curr] = 0;
	f(curr + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> K;
		if (K == 0) break;

		for (int i = 0; i < K; i++) cin >> S[i];
		f(0, 0);
		cout << '\n';
	}

}