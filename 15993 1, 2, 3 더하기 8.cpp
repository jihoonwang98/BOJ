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

int memo[NUM + 5][2];

// f(n,0)-> ���� n�� 1,2,3�� ������ ��Ÿ���� ����� �� (��, ¦�� �� ���)
// f(n,1)-> ���� n�� 1,2,3�� ������ ��Ÿ���� ����� �� (��, Ȧ�� �� ���)

int f(int n, int m) {
	if (memo[n][m] != -1) return memo[n][m];


	if (m == 0) {
		int res = 0;
		for (int i = 1; i <= 3; i++) {
			res = (res % MOD + f(n - i, 1) % MOD) % MOD;
		}
		return memo[n][m] = res;
	}

	else if (m == 1) {
		int res = 0;
		for (int i = 1; i <= 3; i++) {
			res = (res % MOD + f(n - i, 0) % MOD) % MOD;
		}
		return memo[n][m] = res;
	}
}


int main() {
	int T;
	cin >> T;

	for (int i = 0; i <= NUM; i++) {
		memo[i][0] = memo[i][1] = -1;
	}

	memo[1][0] = 0;
	memo[1][1] = 1;
	memo[2][0] = 1;
	memo[2][1] = 1;
	memo[3][0] = 2;
	memo[3][1] = 2;


	while (T--) {
		int n;
		cin >> n;
		cout << f(n, 1) << ' ' << f(n, 0) << '\n';
	}

}