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

using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}

	if (a % b == 0) return b;
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	int gcdAB = gcd(A, B);
	int a = A / gcdAB;
	int b = B / gcdAB;

	cout << gcdAB << '\n' << a * b * gcdAB;
}