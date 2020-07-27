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
int res[10];
int flag[10];

void f(int curr) {

	if (curr == N) {
		for (int i = 0; i < N; i++) cout << res[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
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

	cin >> N;
	f(0);

}