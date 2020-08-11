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

#define MAX_V 100000
#define MOD 1000000009
const long long int LINF = (unsigned long long int)(-1) >> 1;
const int INF = (unsigned)(-1) >> 1;

using namespace std;
int N;
vector<string> words;
int alpha[11];
int alphaidx = 1;
int alphaTmp[26];
int flag[11];
int result[11];
int weight[26];

long long int final_res = -1;

void f(int curr) {
	if (curr == alphaidx) {
		/*for (int i = 1; i <= alphaidx - 1; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';*/

		for (int i = 1; i <= alphaidx - 1; i++) {
			weight[result[i]] = 10 - i;
		}

		long long int res = 0;

		for (int i = 0; i < N; i++) {
			int tmp = 0;
			int w = 1;
			for (int j = words[i].size() - 1; j >= 0; j--) {
				tmp += w * weight[words[i][j] - 'A'];
				w *= 10;
			}
			res += tmp;
		}

		if (res > final_res) final_res = res;
		return;
	}

	for (int i = 1; i <= alphaidx - 1; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			result[curr] = alpha[i];
			f(curr + 1);
			flag[i] = 0;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	words.resize(N);

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		words[i] = tmp;

		for (char& c : tmp) {
			alphaTmp[c - 'A'] = 1;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphaTmp[i]) {
			alpha[alphaidx++] = i;
		}
	}


	f(1);
	cout << final_res;
}