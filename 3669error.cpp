#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 100000000;
const int MAX_NUM = 305;
const int M=50005;

//输入
int maze[MAX_NUM][MAX_NUM];
bool visted[MAX_NUM][MAX_NUM];		//0表示能停留，1表示不能停留
int n;//流星的数目
int last = 0;//流星最晚坠落的时间

typedef struct pointTime
{
	int x;
	int y;
	int t;
}p;

p myPoints[M];

//几个方向的移动分量
const int direction[5][2] = 
{
	{1,0},
	{0,1},
	{-1,0},
	{0,-1},
	{0,0},
};

int bfs()
{
	memset(visted,0,sizeof(visted));
	queue<p> que;
	p current;
	current.x=0;
	current.y=0;
	current.t=0;
	que.push(current);

	while(que.size())
	{
		p pp = que.front();
		que.pop();
		
		for(int j=0;j<4;++j)
		{
			current = pp;
			current.x += direction[j][0];
			current.y += direction[j][1];
			++current.t;

			if(current.x>=0 && current.y>=0 && current.x<=300 && current.y<=300 && maze[current.x][current.y]>current.t && !visted[current.x][current.y])
			{
				visted[current.x][current.y] = true;
				if(maze[current.x][current.y]>last)
				{
					return current.t;
				}
				que.push(current);
			}

		}
	}
	return -1;
}

int main()
{
	memset(maze,0x7f,sizeof(maze));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>myPoints[i].x>>myPoints[i].y>>myPoints[i].t;
		int a = myPoints[i].x,b=myPoints[i].y;
		for(int j=0;j<5;j++)
		{
			int nx = a+direction[j][0];
			int ny = b+direction[j][1];
			if(nx>=0&&ny>=0&&maze[nx][ny]>myPoints[i].t)
			{
				maze[nx][ny] = myPoints[i].t;
				last = myPoints[i].t>last? myPoints[i].t : last;
			}
		}
		
	}

	if(maze[0][0]==0)
		printf("%d",-1);
	else
		printf("%d",bfs());

	return 0;
}