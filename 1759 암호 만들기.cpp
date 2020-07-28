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

int L, C;
int alpha[26];

int moeum[26];
int moeumidx = 0;
int jaeum[26];
int jaeumidx = 0;
int flagmo[26];
int flagja[26];
vector<string> res;


void ja(int curr, int cnt, int c) {
	if (cnt == c) {
		int tmp[26] = { 0 };
		for (int i = 0; i < moeumidx; i++) {
			if (flagmo[i]) {
				tmp[moeum[i]] = 1;
			}
		}
		for (int i = 0; i < jaeumidx; i++) {
			if (flagja[i]) {
				tmp[jaeum[i]] = 1;
			}
		}

		string ret = "";
		for (int i = 0; i < 26; i++) {
			if (tmp[i]) ret += (char)(i + 'a');
		}
		res.push_back(ret);
		return;
	}
	if (curr >= jaeumidx) return;

	flagja[curr] = 1;
	ja(curr + 1, cnt + 1, c);

	flagja[curr] = 0;
	ja(curr + 1, cnt, c);
}


void mo(int curr, int cnt, int c) {
	if (cnt == c) {

		ja(0, 0, L - c);
		return;
	}
	if (curr >= moeumidx) return;

	flagmo[curr] = 1;
	mo(curr + 1, cnt + 1, c);

	flagmo[curr] = 0;
	mo(curr + 1, cnt, c);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	for (int i = 1; i <= C; i++) {
		char c;
		cin >> c;
		alpha[c - 'a'] = 1;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i]) {
			if ('a' + i == 'a' || 'a' + i == 'e' || 'a' + i == 'i' || 'a' + i == 'o' || 'a' + i == 'u') {
				moeum[moeumidx++] = i;
			}
			else jaeum[jaeumidx++] = i;
		}
	}

	for (int i = 1; i <= L - 2; i++) {
		mo(0, 0, i);
		for (int k = 0; k < 26; k++) {
			flagmo[k] = flagja[k] = 0;
		}
	}

	sort(res.begin(), res.end());
	for (string s : res) cout << s << '\n';

}