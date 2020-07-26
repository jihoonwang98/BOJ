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
#define MOD 10007

using namespace std;

typedef long long int ll;

int memo[NUM + 5][10];



// 길이가 n이고 마지막 수가 m인 오르막 수의 개수
int f(int n, int m) {
	if (memo[n][m]) return memo[n][m];

	int res = 0;
	for (int i = 0; i <= m; i++) {
		res = (res + f(n - 1, i) % MOD) % MOD;
	}

	return memo[n][m] = res;
}


int main() {
	for (int i = 0; i < 10; i++) memo[1][i] = 1;
	int N;
	cin >> N;

	int res = 0;
	for (int i = 0; i < 10; i++) {
		res = (res + f(N, i) % MOD) % MOD;
	}
	cout << res;

}