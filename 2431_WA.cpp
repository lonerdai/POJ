#include<iostream>
#include<queue>
#define Max_N 10005
using namespace std;

//输入
int L,P,N;
int A[Max_N],B[Max_N];

void solve()
{
	// 为了写起来方便,我们把终点也认为是加油站
	A[N]=L;
	B[N]=0;
	N++;

	//维护加油站的优先队列
	priority_queue <int> que;

	//ans:加油次数, pos:现在所在位置 , tank: 油箱中汽油的量
	int ans = 0, pos = 0,tank = P;

	for(int i=0;i<N;i++)
	{
		//接下去要行进的距离
		int d=A[i]-pos;
		while(tank<d)
		{
			if(que.empty())
			{
				puts("-1");
				return;
			}
			tank+=que.top();
			que.pop();
			ans++;
		}

		tank-=d;
		pos=A[i];
		que.push(B[i]);
	}
	printf("%d\n",ans);
}

int main()
{

	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&A[i],&B[i]);
	}
	scanf("%d%d",&L,&P);
	
	solve();

	return 0;
}