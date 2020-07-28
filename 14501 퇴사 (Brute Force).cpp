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
#include <cmath>
#define NUM 10000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N;
int flag[16];
int time[16];
int price[16];
int result = -1;


void f(int curr, int res) {
	if (curr >= N + 1) {
		if (result < res) result = res;
		return;
	}
	if (!flag[curr]) {

		int no = 0;
		for (int k = 0; k < time[curr]; k++) {
			if (curr + k > N) {
				no = 1;
				break;
			}
			flag[curr + k] = 1;
		}

		if (!no)	f(curr + time[curr], res + price[curr]);

		if (no) {
			for (int i = N; i >= curr; i--)flag[i] = 0;
		}
		else {
			for (int k = 0; k < time[curr]; k++) {
				flag[curr + k] = 0;
			}
		}
		f(curr + 1, res);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> time[i] >> price[i];

	f(1, 0);
	cout << result;
}