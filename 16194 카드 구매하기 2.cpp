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

using namespace std;

const int MAX = ((unsigned)(-1) >> 1);
int f[NUM + 5];
int p[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];

	f[0] = 0;
	f[1] = p[1];

	for (int i = 2; i <= N; i++) {
		int min = MAX;
		for (int j = 0; j <= i - 1; j++) {
			int tmp = f[j] + p[i - j];
			if (tmp < min) min = tmp;
		}
		f[i] = min;
	}

	cout << f[N];

}