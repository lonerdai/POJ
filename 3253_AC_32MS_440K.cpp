#include<iostream>
#include<queue>
#define Max_N 20009
using namespace std;


typedef long long ll;
//input
int N,L[Max_N];

void solve()
{
	ll ans=0;
	
	//声明一个从小到大取出数值的优先队列
	priority_queue<int, vector<int>,greater<int> >  que;
	for(int i=0;i<N;i++)
	{
		que.push(L[i]);
	}
	
	//循环到只剩一块木板为止
	while(que.size()>1)
	{
		//取出最短的木板和次短的木板
		int l1,l2;
		l1=que.top();
		que.pop();
		l2=que.top();
		que.pop();
		
		//把两块木板合并
		ans+=l1+l2;
		que.push(l1+l2);
		
	}
	
	printf("%lld\n",ans);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&L[i]);
	}
	solve();
	return 0;
}