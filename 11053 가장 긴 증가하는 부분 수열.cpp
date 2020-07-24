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

int N;
int arr[NUM + 5];
int dp[NUM + 5];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)  cin >> arr[i];
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		int flag = 0;
		int max = -1;
		for (int j = 1; j <= i - 1; j++) {
			if (arr[j] < arr[i]) {
				flag = 1;
				if (max < dp[j]) max = dp[j];
			}
			if (flag) dp[i] = max + 1;
			else dp[i] = 1;
		}

	}

	int res = -1;

	for (int i = 1; i <= N; i++) {
		if (res < dp[i]) res = dp[i];
	}

	cout << res;

}