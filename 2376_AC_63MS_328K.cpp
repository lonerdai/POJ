#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX_N = 25005;

struct p { int first; int second; };

int start=1;
int result=0;
int N,T;
p Cows[MAX_N];


bool lessThan(const p a,const p b)
{
	return a.first<b.first;
}


int solve()
{
	int count=0;
	int end = 0;
	int start ;
	int index =0;
	while(end<T)
	{
		start = end+1;
		for(int i= index;i<N;i++)
		{
			if(Cows[i].first <= start)
			{
				if(Cows[i].second>=start)
				{
					end = max(Cows[i].second,end);
				}
			}else{
				index = i;
				break;
			}
		}
		if(start>end)
		{
			return -1;
		}else{
			count++;
		}
	}
	return count;
}



int main()
{

	scanf("%d%d",&N,&T);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&Cows[i].first,&Cows[i].second);
	}
	sort(Cows,Cows+N,lessThan);

	printf("%d",solve());

	return 0;
}