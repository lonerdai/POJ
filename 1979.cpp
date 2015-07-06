#include<iostream>
using namespace std;

#define MAX_H 30
//表示瓷砖的行列数
int M,N;

char d[MAX_H][MAX_H];

int startX,startY, res;

//从d[x][y]开始遍历，已经确定d[i][j]是'.' , 
void dfs(int x,int y)
{
	d[x][y]='#';
	res++;
	if(x!=0 && d[x-1][y]=='.')
		dfs(x-1,y);
	if(x<M-1 && d[x+1][y]=='.')
		dfs(x+1,y);
	if(y!=0 && d[x][y-1]=='.')
		dfs(x,y-1);
	if(y<N-1 && d[x][y+1]=='.')
		dfs(x,y+1);


}

void solve()
{
	while(cin>>N>>M && M!=0 && N!=0)
	{
		res=1;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				cin>>d[i][j];
				if(d[i][j]=='@')
				{
					startX=i;
					startY=j;
					d[i][j]='.';
				}
			}
			dfs(startX,startY);
			printf("%d\n",res);
	}
}

int main()
{
	solve();
	return 0;
}