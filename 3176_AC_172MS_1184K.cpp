#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX_N = 351;
int N;
int a[MAX_N][MAX_N];
int res[MAX_N][MAX_N];

int solve()
{
	int maxNum=0;
	res[0][0] = a[0][0];
	for(int i=1;i<N;i++)
	{
		res[i][0]=res[i-1][0]+a[i][0];
	}

	for(int i =1;i<N;i++)
		for(int j=1;j<N;j++)
		{
			res[i][j] = max(res[i-1][j-1],res[i-1][j])+a[i][j];
		}

	for(int i=0;i<N;i++)
	{
		maxNum = max(maxNum,res[N-1][i]);
	}
	return maxNum;
}



int main()
{
	memset(a,0,sizeof(a));
	memset(res,0,sizeof(res));
	cin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			cin>>a[i][j];
		}
	}

	cout<<solve();

	return 0;
}