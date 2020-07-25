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
#define NUM 10000
#define MOD 1000000000

using namespace std;

typedef long long int ll;

ll memo[NUM + 5][4];

// k -> ¸¶Áö¸·À¸·Î µ¡¼ÀÇÑ ¼ö
ll p(int n, int k) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	if (memo[n][k]) return memo[n][k];
	if (k == 1) return memo[n][k] = 1;


	ll res = 0;

	for (int i = k; i >= 1; i--) {
		res += p(n - i, i);
	}

	return memo[n][k] = res;
}



int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		cout << p(n, 3) << '\n';
	}

}