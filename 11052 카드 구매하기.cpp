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
		int max = -1;
		for (int j = 0; j <= i - 1; j++) {
			int tmp = f[j] + p[i - j];
			if (tmp > max) max = tmp;
		}
		f[i] = max;
	}

	cout << f[N];

}