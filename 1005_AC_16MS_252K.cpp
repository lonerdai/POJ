#include <iostream>
using namespace std;
int main()
{                                
	int n,i=0,z;
	float x,y;
	double PI=3.1415926;
	cin>>n;
	for(;i<n;i++)
	{
		cin>>x>>y;
		z=(x*x+y*y)*PI/100+1;
		cout<<"Property "<<i+1<<": This property will begin eroding in year "<<z<<"."<<endl;
	}
    cout<<"END OF OUTPUT.";
    return 0;
}