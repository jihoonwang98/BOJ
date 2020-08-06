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
vector<vector<p>> adj(100001);
p maxH[100001];
int V;
int maxD[100001];
int visit[100001];



int fmaxH(int curr) {

	visit[curr] = 1;


	vector<p> v;
	for (p& next : adj[curr]) {
		if (!visit[next.second]) {
			v.push_back(make_pair(fmaxH(next.second) + next.first, next.second));
		}
	}

	sort(v.begin(), v.end(), greater<p>());
	if (v.size() >= 2) {
		maxH[curr] = make_pair(v[0].first, v[1].first);
		return v[0].first;
	}
	else if (v.size() == 1) {
		maxH[curr] = make_pair(v[0].first, 0);
		return v[0].first;
	}
	else if (v.size() == 0) {
		maxH[curr] = make_pair(0, 0);
		return 0;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	for (int i = 1; i <= V; i++) {
		int u;
		cin >> u;

		int v, w;
		while (1) {
			cin >> v;
			if (v == -1) {
				break;
			}
			cin >> w;
			adj[u].push_back(make_pair(w, v));
		}
	}

	fmaxH(1);

	for (int i = 1; i <= V; i++) {
		maxD[i] = maxH[i].first + maxH[i].second;
	}

	int res = -1;
	for (int i = 1; i <= V; i++) {
		if (maxD[i] > res) res = maxD[i];
	}

	cout << res;
}