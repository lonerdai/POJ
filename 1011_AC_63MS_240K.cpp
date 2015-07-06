/*从数组中的最大值开始向上算，可能的值为总和的公约数，
逐个求每一个公约数是否恰当（搜索一组组成即从数组中除去），
看最后能否返回成功*/
#include <iostream>
using namespace std;
int n=0;
int sti[100];
bool used[100];

struct poss									//记录木条中可能拼成的长度值及可能值的个数
{
	int n;
	int pos[100];
};

void init();
int max();
poss possible();
void sort();
bool search(int,int,int);

int max()								//寻找数组中最大的木条长度
{
	int m=0;
	for(int i=0;i<n;i++)
		if(m<sti[i])	m=sti[i];
	return m;
}

int total()
{
	int a=0;
	for(int i=0;i<n;i++)
		a+=sti[i];
	return a;
}

poss possible()						//计算一组木条中可能拼成的长度
{
	poss a;
	//int count=total();
	
	a.n=0;
	int m=max();
	int t=total();
	for(int i=m;i<=t;i++)
		if(t%i==0)
			a.pos[a.n++]=i;
	return a;
}

void sort()						//木条的从大到小排序
	{
		int temp;
		for(int i=n-1;i>0;i--)
			for(int j=0;j<i;j++)
				if(sti[j]<sti[j+1])
				{
					temp=sti[j];
					sti[j]=sti[j+1];
					sti[j+1]=temp;
				}
		
	}

bool search(int unused,int left,int x)   //判断找出的x长度是否合适,数组a已经排序,采用深度优先搜索,unused为未使用的数目，left为x里未匹配的大小
	{
		if(unused==0&&left==0)
			return true;
		if(left==0)				//配好当前的棍子长度后，配新棍子
			left=x;
		for(int i=0;i<n;i++)
		{
			if(used[i]==false && sti[i]<=left)
			{
				used[i]=true;
				if(search(unused-1,left-sti[i],x))
					return true;
				used[i]=false;
				if (sti[i] == left || left == x)
					break;
			}
		}
		return false;
		
	}
void test()
{
	//n=6;
	while(cin>>n&&n!=0){
	for(int i=0;i<n;i++)
		cin>>sti[i];
	//sti[0]=2 ;sti[1]=5;sti[2]=3;sti[3]=4;sti[4]=6;sti[5]=7;
	sort();
	
	//cout<<total();
	//cout<<"max is "<<max();
	poss a=possible();
	//for(int i=0;i<a.n;i++)
		//cout<<a.pos[i];
	for(int i=0;i<n;i++)
		used[i]=false;
	for(int i=0;i<a.n;i++)
	{
		if(search(n,0,a.pos[i]))
		{
			cout<<a.pos[i]<<endl;
			break;
		}
	}
	}
}
int main()
{
	test(); 
	//cout<<n;
    return 0;
}
