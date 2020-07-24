#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define SIZE 1005
using namespace std;

int A[SIZE];
int dp[SIZE];
int dp2[SIZE];

int arr[SIZE];
int arridx = 0;

void filldp(int n)
{
	int chk = 0;
	int minVal = 0;
	int idx = 0;

	for (int i = 1; i <= n - 1; i++)
	{
		if (A[n] > A[i])
		{
			if (minVal < dp[i])
			{
				chk = 1;
				minVal = dp[i];
				idx = i;
			}
		}
	}

	if (chk)
	{
		dp2[n] = idx;
		dp[n] = minVal + 1;
	}

	else
	{
		dp[n] = 1;
		dp2[n] = -1;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	dp[1] = 1;
	dp2[1] = -1;
	for (int i = 2; i <= N; i++)
	{
		filldp(i);
	}

	int max = 0;
	int maxidx = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
			maxidx = i;
		}
	}

	cout << max << '\n';


	int curr = maxidx;
	int f_curr = dp2[curr];
	while (f_curr != -1)
	{
		arr[arridx++] = curr;
		curr = f_curr;
		f_curr = dp2[f_curr];
	}

	arr[arridx++] = curr;

	for (int i = arridx - 1; i >= 0; i--)
	{
		cout << A[arr[i]] << ' ';
	}

}
