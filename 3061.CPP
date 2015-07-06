#include<iostream>
using namespace std;
#define MAX_N 100000
int n,s;
int a[MAX_N];
int sum[MAX_N];

void solve()
{
	//计算sum
	for(int i=0;i<n;i++)
	{
		sum[i+1] = sum[i]+a[i];
	}
	if(sum[n]<s)
	{
		printf("0\n");
		return;
	}
	int res=n;
	for(int i=0;sum[i]+s<=sum[n];i++)
	{
		
	}
}

int main()
{
	return 0;
}