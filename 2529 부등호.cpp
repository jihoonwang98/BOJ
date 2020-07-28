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
const long long int INF = (unsigned long long int)(-1) >> 1;

using namespace std;

int N;
int K;
int res[10];
int flag[10];
char inequal[10];

long long int maxRes = -1;
long long int minRes = INF;

string maxStr;
string minStr;

int inequalRes(int a, int b, char inequal) {
	int res;

	switch (inequal) {
	case '<':
		res = a < b;
		break;

	case '>':
		res = a > b;
		break;
	}

	return res;
}

int satisfied() {
	int sat = 1;
	for (int i = 1; i <= K; i++) {
		if (!inequalRes(res[i - 1], res[i], inequal[i])) {
			sat = 0;
			break;
		}
	}

	return sat;
}

void f(int curr) {
	if (curr == N) {
		if (satisfied()) {
			/*cout << res[0] << ' ';
			for (int i = 1; i <= K; i++) {
				cout << inequal[i] << ' ' << res[i] << ' ';
			}
			cout << '\n';*/

			string tmp = "";
			for (int i = 0; i <= K; i++) tmp += (char)(res[i] + '0');

			long long int x = stoll(tmp);
			if (maxRes < x) {
				maxRes = x;
				maxStr = tmp;
			}
			if (minRes > x) {
				minRes = x;
				minStr = tmp;
			}
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			res[curr] = i;
			f(curr + 1);
			flag[i] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	N = K + 1;
	for (int i = 1; i <= K; i++) cin >> inequal[i];
	f(0);
	cout << maxStr << '\n' << minStr;
}