#include<iostream>
using namespace std;
#define MAX_N 2010
int N;
char S[MAX_N];

void  solve()
{
	int a = 0, b = N - 1,count=0;
	while (a <= b)
	{
		bool left = false;
		for (int i = 0; a + i<b; i++)
		{
			if (S[a + i]<S[b - i])
			{
				left = true;
				break;
			}
			else if (S[a + i]>S[b - i])
			{
				left = false;
				break;
			}
		}
		if ((count>3) && (count % 80 == 0))
		{
			puts("");
		}
		if (left)putchar(S[a++]);
		else putchar(S[b--]);
		count++;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	solve();
	return 0;
}