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

int N;
int arr[1005];
int dp_inc[1005];
int dp_dec[1005];

void fill_inc(int n) {
	int flag = 0;
	int max = -1;
	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] < arr[n]) {
			flag = 1;
			if (max < dp_inc[i]) max = dp_inc[i];
		}
	}

	if (flag) {
		dp_inc[n] = max + 1;
	}
	else dp_inc[n] = 1;
}

void fill_dec(int n) {
	int flag = 0;
	int max = -1;
	for (int i = N; i >= n + 1; i--) {
		if (arr[i] < arr[n]) {
			flag = 1;
			if (max < dp_dec[i]) max = dp_dec[i];
		}
	}

	if (flag) {
		dp_dec[n] = max + 1;
	}
	else dp_dec[n] = 1;
}

int main() {
	cin >> N;

	for (int i = 1;i <= N; i++) cin >> arr[i];
	dp_inc[1] = 1;
	dp_dec[N] = 1;


	for (int i = 2; i <= N; i++) fill_inc(i);
	for (int i = N - 1; i >= 1; i--) fill_dec(i);

	int res = -1;
	for (int i = 1; i <= N; i++) {
		if (dp_inc[i] + dp_dec[i] > res) res = dp_inc[i] + dp_dec[i];
	}
	res--;
	cout << res;
}