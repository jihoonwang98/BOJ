#include <iostream>
#include <string>
#include <algorithm>
#define SIZE 200000
using namespace std;

int stack[SIZE];
int sTop = -1;

char printArr[SIZE];
int psTop = -1;



void pushS(char c)
{
	printArr[++psTop] = c;
}

void push(int c)
{
	stack[++sTop] = c;
	pushS('+');
}



int pop()
{
	if (sTop == -1) return -1;

	pushS('-');
	return stack[sTop--];
}


int top()
{
	if (sTop == -1) return -1;
	return stack[sTop];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int curr = 1;
	int chk = 0;

	for (int i = 1; i <= T; i++)
	{

		int tmp;
		cin >> tmp;

		if (top() <= tmp)
		{
			while (top() != tmp)
			{
				push(curr++);

			}

			pop();


		}

		else if (top() > tmp)
		{
			chk = 1;
			cout << "NO\n";
			return 0;

		}



	}

	for (int i = 0; i <= psTop; i++) cout << printArr[i] << '\n';





}