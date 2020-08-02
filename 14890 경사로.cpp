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
#include <functional>
#define NUM 200000
#define MOD 10007
#define MAX_V 100000

using namespace std;

typedef long long int ll;
const int INF = (unsigned)-1 >> 1;

typedef pair<int, int> p;

int N, L;

int map[101][101];
int arr[101];

int chk() {
	int flag[101] = { 0 };
	int f = arr[1];
	int allSame = 1;
	for (int i = 2; i <= N; i++) {
		if (f != arr[i]) {
			allSame = 0;
			break;
		}
	}
	if (allSame) return 1;


	for (int i = 1; i <= N - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			if (abs(arr[i] - arr[i + 1]) >= 2) {
				return 0;
			}

			else if (abs(arr[i] - arr[i + 1]) == 1) {
				if (arr[i] > arr[i + 1]) {

					int x = arr[i + 1];

					for (int j = i + 1; j <= i + L; j++) {
						if (j >= N + 1) return 0;
						if (arr[j] != x) return 0;
						if (flag[j]) return 0;
						flag[j] = 1;
					}
				}

				else if (arr[i] < arr[i + 1]) {
					int x = arr[i];

					for (int j = i; j >= i - L + 1; j--) {
						if (j <= 0) return 0;
						if (arr[j] != x) return 0;
						if (flag[j]) return 0;
						flag[j] = 1;
					}
				}

			}
		}
	}

	return 1;
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			arr[j] = map[i][j];
		}

		if (chk()) {
			res++;
		}

		for (int j = 1; j <= N; j++) {
			arr[j] = map[j][i];
		}
		if (chk()) {
			res++;
		}
	}

	cout << res;


}