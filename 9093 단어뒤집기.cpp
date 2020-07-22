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
		string tmp;
		getline(cin, tmp);
		for (int j = 0; j < tmp.length(); j++)
		{
			if (tmp[j] != ' ')
			{
				push(tmp[j]);
			}

			else
			{

				while (top != -1)
				{
					cout << pop();
				}
				cout << ' ';
			}
		}
		while (top != -1)
		{
			cout << pop();
		}
		cout << '\n';

	}

}