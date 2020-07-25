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
#define MOD 1000000009

using namespace std;

typedef long long int ll;

ll memo[NUM + 5];

// n을 1, 2, 3의 합으로 나타내는 방법의 수
ll f(int n) {
	if (n < 0) return 0;
	if (memo[n]) return memo[n];

	return memo[n] = ((f(n - 1) % MOD + f(n - 2) % MOD) % MOD + f(n - 3) % MOD) % MOD;
}



int main() {
	int T;
	cin >> T;

	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;

	while (T--) {
		int n;
		cin >> n;
		ll res = 0;
		for (int i = 1; i <= 3; i++) {
			if ((n - i) % 2 == 0) {
				res = (res % MOD + f((n - i) / 2) % MOD) % MOD;
			}
		}
		if (n % 2 == 0) {
			res = (res % MOD + f(n / 2) % MOD) % MOD;
		}
		cout << res << '\n';
	}

}