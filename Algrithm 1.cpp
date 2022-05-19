#include<iostream>
using namespace std;
#define max 500
int a[max][max];
int bt(int m,int *attack)//m is the total blood , n refer to attack of each servant
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (attack[i-1] < j)
			{
				if (a[i - 1][j] < attack[i-1] + a[i - 1][j - attack[i-1]])
				{
					a[i][j] = attack[i-1] + a[i - 1][j - attack[i-1]];
				}
				else
				{
					a[i][j] = a[i - 1][j];
				}
			}
			else
			{
				a[i][j] = a[i - 1][j];
			}
		}
	}
	return a[7][m];
}
int main()
{
	int m, blood,ndo;
	
	int attack[7];
	cout << "请输入总血量";
	cin >> blood;
	int i = 7, j = blood;
	cout << "输入每个随从的攻击力" << endl;
	for (int i = 0; i < 7; i++)
	{
		cin >> attack[i];
	}
	m = bt(blood,attack);
	if (blood - m == 0)
	{
		cout << "可以破1血冰";
	}
	else
		cout << "可以破" << blood-m << "血冰"<<endl;
	cout << "随从的攻击顺序为:"<<endl;
	while (i >= 1)
	{
		if (a[i - 1][j] < attack[i - 1] + a[i - 1][j - attack[i - 1]])
		{
			cout << "选择第" << i << "个随从攻击"<<endl;
		}
		else
			ndo = i;
		i = i - 1;
	}
	cout << "最后选择第" << ndo << "个随从攻击"<<endl;
}