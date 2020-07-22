#include <iostream>
#include <string>
#include <algorithm>
#define SIZE 200000
using namespace std;

int N;

int stack[SIZE];
int top = -1;

void push(int x)
{
	stack[++top] = x;
}

int pop()
{
	if (top == -1)
	{
		return -1;
	}

	return stack[top--];
}

int count()
{
	return top + 1;
}

int empty()
{
	if (top == -1) return 1;
	else return 0;
}

int topStack()
{
	if (top == -1) return -1;
	return stack[top];
}


void input()
{
	cin >> N;
	cin.get();
	for (int i = 1; i <= N; i++)
	{

		string tmp;
		int tmp2;

		getline(cin, tmp);

		switch (tmp[0])
		{
		case 't':
			tmp2 = topStack();
			cout << tmp2 << '\n';
			break;
		case 's':
			cout << count() << '\n';
			break;
		case 'e':
			cout << empty() << '\n';
			break;
		}

		if (tmp[0] == 'p' && tmp[1] == 'u')
		{
			string sub = tmp.substr(5);
			int t = stoi(sub);
			push(t);
		}
		else if (tmp[0] == 'p')
		{
			int tmp3 = pop();
			cout << tmp3 << '\n';
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
}
