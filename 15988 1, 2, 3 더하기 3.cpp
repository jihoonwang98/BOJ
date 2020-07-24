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
#define NUM 1000000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int t;

int memo[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		memo[i] = ((memo[i - 1] % MOD + memo[i - 2] % MOD) % MOD + memo[i - 3] % MOD) % MOD;
	}
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << memo[n] << '\n';
	}
}