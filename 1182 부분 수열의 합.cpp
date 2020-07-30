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

int arr[21];
int flag[21];

int N, S;
int res;

void f(int curr) {
	if (curr == N + 1) {
		int cnt = 0;
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (flag[i]) {
				cnt++;
				sum += arr[i];
			}
		}
		if (cnt == 0) return;


		if (sum == S) {
			res++;
		}
		return;
	}

	flag[curr] = 1;
	f(curr + 1);

	flag[curr] = 0;
	f(curr + 1);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	f(1);

	cout << res;

}