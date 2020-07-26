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
#define MOD 10007

using namespace std;

typedef long long int ll;


int memo[33];

int f(int n) {
	if (memo[n]) return memo[n];

	int ret = 2;
	for (int i = 2; i <= n - 4; i += 2) {
		ret += f(i) * 2;
	}
	ret += f(n - 2) * 3;

	return memo[n] = ret;
}

int main() {
	int N;
	cin >> N;
	if (N % 2 == 1) {
		cout << 0;
		return 0;
	}

	memo[2] = 3;
	memo[4] = 11;
	cout << f(N);
}