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
#define NUM 1000005
using namespace std;

int memo[NUM];
const int MAX = ((unsigned)-1 >> 1);

int min2(int a, int b, int c) {
	int min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	return min;
}

int dp(int x) {
	if (memo[x]) return memo[x];
	if (x == 1) return 0;

	int n1, n2, n3;
	n1 = n2 = n3 = MAX;

	if (x % 3 == 0) {
		n1 = dp(x / 3) + 1;
	}

	else if (x % 2 == 0) {
		n2 = dp(x / 2) + 1;
	}

	n3 = dp(x - 1) + 1;

	int res = min2(n1, n2, n3);
	memo[x] = res;
	return memo[x];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cout << dp(N);
}