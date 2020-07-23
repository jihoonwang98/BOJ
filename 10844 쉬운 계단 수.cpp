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
#define MOD 1000000000

using namespace std;

int f[105][10];


int main() {
	for (int i = 1; i <= 9; i++) f[1][i] = 1;

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				f[i][j] = f[i - 1][1];
			}

			else if (j == 9) {
				f[i][j] = f[i - 1][8];
			}
			else {
				f[i][j] = (f[i - 1][j - 1] % MOD + f[i - 1][j + 1] % MOD) % MOD;
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res = (res % MOD + f[N][i] % MOD) % MOD;
	}
	cout << res;

}