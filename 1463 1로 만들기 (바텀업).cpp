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
#define NUM 1000000

using namespace std;

int f[NUM + 5];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < NUM; i++) {
		if (3 * i <= NUM) {
			if (f[3 * i] == 0) f[3 * i] = f[i] + 1;
			else f[3 * i] = min(f[3 * i], f[i] + 1);
		}

		if (2 * i <= NUM) {
			if (f[2 * i] == 0) f[2 * i] = f[i] + 1;
			else f[2 * i] = min(f[2 * i], f[i] + 1);
		}

		if (i + 1 <= NUM) {
			if (f[i + 1] == 0) f[i + 1] = f[i] + 1;
			else f[i + 1] = min(f[i + 1], f[i] + 1);
		}
	}

	int N;
	cin >> N;
	cout << f[N];
}