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
#define MOD 1000000000
const int INF = (unsigned)(-1) >> 1;

using namespace std;

typedef long long int ll;

int N, K;

int memo[202][202];

int f(int n, int k) {
	if (memo[n][k]) return memo[n][k];
	if (k == 1) {
		memo[n][k] = 1;
		return memo[n][k];
	}
	int res = 0;
	for (int i = 0; i <= n; i++) {
		res = (res % MOD + f(i, k - 1) % MOD) % MOD;
	}

	return memo[n][k] = res;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	cout << f(N, K);

}