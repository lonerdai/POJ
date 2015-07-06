#include <iostream>
using namespace std;
int main()
{
	int n=0;
	float sum;
	float len=0;
	while(cin>>len)
	{
		if(len==0.00)
		break;
		sum=0;
		int i=2;
		for(;len>sum;i++)
		{
			sum += (float)1/i;
		}
		cout<<i-2<<" card(s)"<<endl;
	}
    
    return 0;
}