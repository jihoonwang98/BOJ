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
#define NUM 100000
#define MOD 9901

using namespace std;

typedef long long int ll;

int N;
int memo[NUM + 5][3];


// m == 0 ÀÌ¸é ¸¶Áö¸· µÎ Ä­´Ù ºö, 
// m == 1 ÀÌ¸é ¿ÞÂÊ Ä­ »çÀÚ
// m == 2 ÀÌ¸é ¿À¸¥ÂÊ Ä­ »çÀÚ
int f(int n, int m) {
	if (memo[n][m]) return memo[n][m];

	if (m == 0) {
		return memo[n][m] = (((f(n - 1, 0) % MOD) + (f(n - 1, 1) % MOD)) % MOD + f(n - 1, 2) % MOD) % MOD;
	}

	else if (m == 1) {
		return memo[n][m] = (f(n - 1, 0) % MOD + f(n - 1, 2) % MOD) % MOD;
	}

	else if (m == 2) {
		return memo[n][m] = (f(n - 1, 0) % MOD + f(n - 1, 1) % MOD) % MOD;
	}
}


int main() {

	memo[1][0] = memo[1][1] = memo[1][2] = 1;

	cin >> N;
	int res = 0;
	for (int i = 0; i < 3; i++) {
		res = (res % MOD + f(N, i) % MOD) % MOD;
	}
	cout << res;

}