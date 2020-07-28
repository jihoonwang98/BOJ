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
const long long int LINF = (unsigned long long int)(-1) >> 1;
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N;
int res[21];
int done = 0;
char inequal[21][21];
string str;

char c(int i) {
	if (i > 0) return '+';
	else if (i == 0) return '0';
	else return '-';
}

void f(int curr) {
	if (done) return;
	if (curr == N) {
		for (int i = 0; i < N; i++) {
			cout << res[i] << ' ';
		}
		done = 1;
		return;
	}

	for (int i = 0; i < 21; i++) {
		res[curr] = i - 10;
		int no = 0;
		for (int j = 0; j <= curr; j++) {

			int subSum = 0;
			for (int k = j; k <= curr; k++) {
				subSum += res[k];
			}
			char C = c(subSum);
			if (inequal[j][curr] != C) {
				no = 1;
				break;
			}

		}

		if (!no) f(curr + 1);
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> str;

	int stridx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			inequal[i][j] = str[stridx++];
		}
	}

	f(0);
}