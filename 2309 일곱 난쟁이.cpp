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
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int arr[10];
	int sum = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int res[10];
	int residx = 0;

	int flag = 0;

	for (int i = 1; i <= 8; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if ((sum - arr[i] - arr[j]) == 100) {
				for (int k = 1; k <= 9; k++) {
					if (k != i && k != j) {
						res[residx++] = arr[k];
					}
				}
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	sort(res, res + residx);
	for (int i = 0; i < residx; i++) cout << res[i] << '\n';

}