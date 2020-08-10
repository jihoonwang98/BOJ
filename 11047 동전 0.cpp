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

typedef pair<int, int> p;

int N, K;
int price[11];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}

	int res = 0;
	for (int i = N; i >= 1; i--) {
		while (price[i] <= K) {
			K -= price[i];
			res++;
		}
	}

	cout << res;


}