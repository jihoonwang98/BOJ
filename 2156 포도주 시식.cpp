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
#define NUM 10000
#define MOD 10007

using namespace std;

typedef long long int ll;

int arr[NUM + 5];
int memo[NUM + 5];

int f(int n) {
	if (memo[n] != -1) return memo[n];

	int tmp[3];
	tmp[0] = f(n - 3) + arr[n - 1] + arr[n];
	tmp[1] = f(n - 2) + arr[n];
	tmp[2] = f(n - 1);

	int res = -1;
	for (int i = 0; i < 3; i++) {
		if (res < tmp[i]) res = tmp[i];
	}

	return memo[n] = res;
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) memo[i] = -1;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	memo[1] = arr[1];
	memo[2] = arr[1] + arr[2];
	memo[3] = max(arr[1], arr[2]) + arr[3];
	memo[3] = max(memo[3], arr[1] + arr[2]);

	cout << f(n);
}