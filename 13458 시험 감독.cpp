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

int N;
int arr[1000001];
int B, C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> B >> C;

	long long int res = 0;

	for (int i = 1; i <= N; i++) {
		arr[i] -= B;
		if (arr[i] < 0) arr[i] = 0;
	}
	res += N;

	for (int i = 1; i <= N; i++) {
		res += arr[i] / C;
		if (arr[i] % C != 0) {
			res += 1;
		}
	}


	cout << res;
}