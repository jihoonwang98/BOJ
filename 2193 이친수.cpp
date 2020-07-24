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

using namespace std;

typedef long long int ll;

ll memo[100][2];

ll f(int n, int l) {
	if (memo[n][l] != -1) return memo[n][l];

	if (l == 0) return memo[n][l] = f(n - 1, 0) + f(n - 1, 1);
	else if (l == 1) return memo[n][l] = f(n - 1, 0);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			memo[i][j] = -1;
		}
	}

	memo[1][0] = 0;
	memo[1][1] = 1;
	memo[2][0] = 1;
	memo[2][1] = 0;
	cout << f(N, 0) + f(N, 1);

}