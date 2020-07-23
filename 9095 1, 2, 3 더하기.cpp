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
#define NUM 11

using namespace std;

int f[NUM + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;

	for (int i = 4; i <= 12; i++) {
		f[i] = f[i - 1] + f[i - 2] + f[i - 3];
	}

	for (int i = 1; i <= T; i++) {
		int tmp;
		cin >> tmp;
		cout << f[tmp] << '\n';
	}
}