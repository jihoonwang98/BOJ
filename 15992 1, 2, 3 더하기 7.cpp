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
#define NUM 1000
#define MOD 1000000009

using namespace std;

typedef long long int ll;

int memo[NUM + 5][NUM + 5];

// n을 1, 2, 3의 합으로 나타내는 방법의 수, 단 사용한 수의 개수가 k개
int f(int n, int k) {
	if (memo[n][k] != -1) return memo[n][k];

	if (n < k) return memo[n][k] = 0;
	if (n == k) return memo[n][k] = 1;
	if (k == 1 && (n > 3)) return memo[n][k] = 0;

	return memo[n][k] = ((f(n - 1, k - 1) % MOD + f(n - 2, k - 1) % MOD) % MOD + f(n - 3, k - 1) % MOD) % MOD;
}



int main() {
	int T;
	cin >> T;

	for (int i = 0; i <= NUM; i++) {
		for (int j = 0;j <= NUM; j++) {
			memo[i][j] = -1;
		}
	}
	memo[1][1] = 1;
	memo[1][2] = 0;
	memo[1][3] = 0;
	memo[2][1] = 1;
	memo[2][2] = 1;
	memo[2][3] = 0;
	memo[3][1] = 1;
	memo[3][2] = 2;
	memo[3][3] = 1;

	while (T--) {
		int n, m;
		cin >> n >> m;
		cout << f(n, m) << '\n';
	}

}