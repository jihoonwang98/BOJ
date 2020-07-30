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

int N, M;
vector<int> adj[2000];
int visited[2000];
int exist = 0;

void traverse(int n, int cnt) {
	if (exist) return;

	if (cnt == 5) {
		exist = 1;
		return;
	}

	visited[n] = 1;

	for (int adj : adj[n]) {
		if (!visited[adj]) {
			traverse(adj, cnt + 1);
		}
	}
	visited[n] = 0;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (exist) break;
		traverse(i, 1);
	}
	if (exist) cout << 1;
	else cout << 0;

}