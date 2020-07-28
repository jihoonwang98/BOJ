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
int time[16];
int price[16];
int dp[30];

//dp[n] -> n일에 끝나는 상담을 할때 최대 수익
void fill(int curr) {
	if (curr == 1) {
		if (time[1] != 1) dp[1] = 0;
		else dp[1] = price[1];
	}

	int maxVal = 0;
	for (int i = 1; i <= curr - 1; i++) {
		if (maxVal < dp[i]) maxVal = dp[i];
	}

	dp[curr + time[curr] - 1] = max(dp[curr + time[curr] - 1], maxVal + price[curr]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> time[i] >> price[i];
	for (int i = 1; i <= N; i++) fill(i);

	int res = -1;
	for (int i = 1; i <= N; i++)
		if (res < dp[i])
			res = dp[i];

	cout << res;

}