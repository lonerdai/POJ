#include<iostream>
using namespace std;
int main()
{ 
	int p,e,i,days,d,t=1;
	 while(cin>>p>>e>>i>>d,p!=-1&&e!=-1&&i!=-1&&d!=-1)
	 {  
	 	for(days=1;days<=21252;days++)
	 	{   
	 		if((days+d-p)%23==0&&(days+d-e)%28==0&&(days+d-i)%33==0)
	 		{    
	 			cout<<"Case "<<t++<<": the next triple peak occurs in "<<days<<" days."<<endl;    
	 			break;   
	 		}  
	 	} 
	 } 
	 return 0;
}