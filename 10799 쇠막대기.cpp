#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
#include <deque>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int num = 0;
	int res = 0;
	int len = str.size();

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			num++;
		}
		else {
			if (str[i - 1] == '(') {
				num--;
				res += num;
			}

			else {
				res++;
				num--;
			}
		}
	}
	cout << res;
}
