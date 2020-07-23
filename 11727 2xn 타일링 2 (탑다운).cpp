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

int fib(int n) {
	if (f[n]) return f[n];

	return f[n] = (fib(n - 1) % 10007 + (2 * fib(n - 2)) % 10007) % 10007;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	f[0] = 0;
	f[1] = 1;
	f[2] = 3;
	cout << fib(N);
}