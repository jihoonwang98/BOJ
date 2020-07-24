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
const int INF = (unsigned)(-1) >> 1;

using namespace std;

typedef long long int ll;

int N;
int memo[NUM + 5];

int k(int n) {
	int k = 1;
	for (; k * k <= n; k++);
	k--;
	return k;
}

int f(int n) {
	if (n == 0) return 0;
	if (memo[n]) return memo[n];

	int K = k(n);

	int res = INF;
	for (int i = 1; i <= K; i++) {
		if (n - i * i < 0) {
			cout << "";
		}
		res = min(res, f(n - i * i));
	}
	res += 1;
	return memo[n] = res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout << f(N);
}