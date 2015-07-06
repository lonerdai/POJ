#include <iostream>
using namespace std;    
int x,y,m,n,L;

int poss()
{
	int x1=x,y1=y;
	for(int i=1;i<L;i++)
	{
		x=(x+m)%L;
		y=(y+n)%L;
		if(x==y)
		return i;
		if(x==x1&&y==y1)
		break;
	}
	return 0;
}

int main()
{
	cin>>x>>y>>m>>n>>L;
	int result=poss();
	if(result==0)
	cout<<"Impossible";
	else
	cout<<result;
    return 0;
}