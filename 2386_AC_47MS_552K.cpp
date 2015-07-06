#include<iostream>
using namespace std;
#define MAX_N 105
#define MAX_M 105
//输入
int N, M;
char field[MAX_N][MAX_M];

void dfs(int x, int y)
{
	field[x][y] = '.';
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			int nx = x + dx, ny = y + dy;
			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')dfs(nx, ny);
		}
	}
	return;
}
void solve()
{
	int res = 0;
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
		{
		if (field[i][j] == 'W')
		{
			dfs(i, j);
			res++;
		}
		}
	printf("%d\n",res);
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			cin >> field[i][j];

	solve();
	return 0;
}