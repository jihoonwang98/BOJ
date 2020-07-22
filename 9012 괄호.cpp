#include <iostream>
#include <string>
#include <algorithm>
#define SIZE 200000
using namespace std;

char stack[SIZE];
int top = -1;

void push(char c)
{
	stack[++top] = c;
}

char pop()
{
	if (top == -1) return ' ';
	return stack[top--];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	cin.get();

	for (int i = 1; i <= T; i++)
	{
		top = -1;
		int chk = 0;
		string tmp;
		getline(cin, tmp);

		for (int j = 0; j < tmp.length(); j++)
		{
			if (tmp[j] == '(')
			{
				push('(');
			}

			else
			{
				if (top != -1) pop();
				else
				{
					chk = 1;
					break;
				}
			}
		}

		if (top != -1) chk = 1;



		if (chk) cout << "NO\n";
		else cout << "YES\n";
	}

}
