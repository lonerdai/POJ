#include<iostream>
using namespace std;

int n;											//n is the number of the number of marbles
static int time = 0;							// time is the time of the test example that is given
int a[6];										
int sum;										//total value of the marbles
int halfSum;
int marble[20001];

bool dfs(int i,int sum)							//sum 代表当前第i个数加完得到的值
{
	//printf("d");
	if (i == n)return sum == halfSum;
	if (dfs(i + 1, sum))return true;
	if ((dfs(i + 1, sum + marble[i]))&&sum+marble[i]<=halfSum)return true; 
	return false;
}
int main()
{
	while (cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5])
	{
		int count = 0;
		sum = 0;
		n = 0;
		for (int i = 5; i >=0; i--)
		{
			if (a[i] != 0)
			{
				n += a[i];
				sum += a[i] * (i + 1);
				for (int j = 0; j < a[i]; j++)
					marble[count++] = i + 1;
			}
			
		}
			

		if (sum == 0)
			break;
		if (sum % 2 == 1)
		{
			cout << "Collection #" << ++time << ':'<<endl<<"Can't be divided."<<endl<<endl;
			continue;
		}
		halfSum = sum / 2;
		if (dfs(0,0))
			cout << "Collection #" << ++time << ':' << endl << "Can be divided." << endl<<endl;
		else
			cout << "Collection #" << ++time << ':' << endl << "Can't be divided." << endl<<endl;
			

	}
	return 0;
}