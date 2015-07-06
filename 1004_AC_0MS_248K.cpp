#include <iostream>
using namespace std;
int main()
{
	double each,sum=0,mean;
	int i=0;
	for(;i<12;i++){
    cin>>each;
    sum+=each;
	}
	mean=sum/12;
	cout<<"$"<<mean;
    return 0;
}