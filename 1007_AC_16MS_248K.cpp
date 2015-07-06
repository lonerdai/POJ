// Note:Your choice is C++ IDE
#include <iostream>
#include<string>
using namespace std;
struct dna
{
	string str;		//记录DNA序列
	int co;			//记录序列权值
};
int calculate(string);
void func(int,int);

int calculate(string s)
{
	int count =0;
	for(int i=0;i!=s.size()-1;i++)
	for(int j=i+1;j!=s.size();j++)
		if(s[i]>s[j])
		count++;
	return count;
		
}
void  func(int length,int number)
{
	dna *aaa=new dna[number];
	for(int i=0;i<number;i++)
		{
		//cin.getline(aaa[i].str,length);
			cin>>aaa[i].str;
			aaa[i].co=calculate(aaa[i].str);
			//cout<<aaa[i].co<<endl;
		}
	dna temp;
	for(int i=0;i<=number-1;i++)
		for(int j=0;j<=number-i-2;j++)
		{
			if(aaa[j].co>aaa[j+1].co)
			{
					temp.co=aaa[j].co;
					temp.str=aaa[j].str;
					aaa[j].co=aaa[j+1].co;
					aaa[j].str=aaa[j+1].str;
					aaa[j+1].co=temp.co;
					aaa[j+1].str=temp.str;
			}
		}
		for(int i=0;i<=number-1;i++)
			cout<<aaa[i].str<<endl;
}
int main()
{
	int l,n;
	cin>>l>>n;
	func(l,n);
    return 0;
}