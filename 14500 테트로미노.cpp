#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX 100010
#define NUM 1000000000

using namespace std;
int N, M;
int cost[505][505];
int sumMax;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> cost[i][j];

	//case1 : ��ٶ��� 1*4 ���

		//1-1 : ���� ��� 4*1
	for (int i = 1; i <= N - 3; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int sum = 0;

			for (int k = 0; k < 4; k++)
			{
				sum += cost[i + k][j];
			}

			if (sumMax < sum) sumMax = sum;
		}
	}


	//1-2 : ���� ��� 1*4
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M - 3; j++)
		{
			int sum = 0;

			for (int k = 0; k < 4; k++)
			{
				sum += cost[i][j + k];
			}

			if (sumMax < sum) sumMax = sum;
		}
	}



	//case2 : ���簢�� 2*2 ���

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= M - 1; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i][j + 1];
			sum += cost[i + 1][j + 1];

			if (sumMax < sum) sumMax = sum;

		}
	}



	//case3 : ������ ���


		//3-1 : 1���� ������ �Ʒ�
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= M - 1; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 2][j];
			sum += cost[i + 2][j + 1];

			if (sumMax < sum) sumMax = sum;

		}
	}




	//3-2 : 1���� ������ ��
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= M - 1; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i][j + 1];
			sum += cost[i + 1][j];
			sum += cost[i + 2][j];

			if (sumMax < sum) sumMax = sum;

		}
	}


	//3-3 : 1���� ���� �Ʒ�
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 2][j];
			sum += cost[i + 2][j - 1];

			if (sumMax < sum) sumMax = sum;

		}
	}


	//3-4 : 1���� ���� ��
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i][j - 1];
			sum += cost[i + 1][j];
			sum += cost[i + 2][j];

			if (sumMax < sum) sumMax = sum;

		}
	}

	//3-5 : ���� y�� ��Ī
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= M - 2; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i][j + 1];
			sum += cost[i][j + 2];
			sum += cost[i + 1][j];

			if (sumMax < sum) sumMax = sum;

		}
	}


	//3-6 : ���� y�� ��Ī
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 3; j <= M; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 1][j - 1];
			sum += cost[i + 1][j - 2];

			if (sumMax < sum) sumMax = sum;

		}
	}




	//3-7 : ��
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= M - 2; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 1][j + 1];
			sum += cost[i + 1][j + 2];

			if (sumMax < sum) sumMax = sum;

		}
	}




	//3-8 : ��
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= M - 2; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i][j + 1];
			sum += cost[i][j + 2];
			sum += cost[i + 1][j + 2];

			if (sumMax < sum) sumMax = sum;

		}
	}






	//case4 : ������ ���


		//4-1
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= M - 1; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 1][j + 1];
			sum += cost[i + 2][j + 1];

			if (sumMax < sum) sumMax = sum;

		}
	}

	//4-2
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 1][j - 1];
			sum += cost[i + 2][j - 1];

			if (sumMax < sum) sumMax = sum;

		}
	}

	//4-3
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 2; j <= M - 1; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i][j + 1];
			sum += cost[i + 1][j];
			sum += cost[i + 1][j - 1];

			if (sumMax < sum) sumMax = sum;

		}
	}

	//4-4
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= M - 2; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i][j + 1];
			sum += cost[i + 1][j + 1];
			sum += cost[i + 1][j + 2];

			if (sumMax < sum) sumMax = sum;

		}
	}





	//case5 : �� ���
		//5-1
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 2; j <= M - 1; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 1][j + 1];
			sum += cost[i + 1][j - 1];

			if (sumMax < sum) sumMax = sum;

		}
	}

	//5-2
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= M - 1; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 1][j + 1];
			sum += cost[i + 2][j];

			if (sumMax < sum) sumMax = sum;

		}
	}


	//5-3
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= M - 2; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i][j + 1];
			sum += cost[i][j + 2];
			sum += cost[i + 1][j + 1];

			if (sumMax < sum) sumMax = sum;

		}
	}

	//5-4
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			int sum = 0;

			sum += cost[i][j];
			sum += cost[i + 1][j];
			sum += cost[i + 2][j];
			sum += cost[i + 1][j - 1];

			if (sumMax < sum) sumMax = sum;

		}
	}

	cout << sumMax;




}

