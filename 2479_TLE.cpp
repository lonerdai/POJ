#include <iostream>  
using namespace std;  
  
#define N -500000001  
  
int returnmax(int a, int b)  
{  
    return a>b? a: b;  
}  
  
int main()  
{  
    int caseNum;  
    cin >> caseNum;  
    while(caseNum--)  
    {  
        int max=N;  
        int n;  
        cin >> n;  
        int *a = new int[n];  
        int *start = new int[n];  
        int *all = new int[n];  
        int nstart;  
        int nall;  
        for(int i = 0; i < n; i++)  
        {  
            cin>>a[i];
            if(i>0)  
            {  
                start[i]=returnmax(a[i],start[i-1]+a[i]);					//start[i]保存a[i]前一定包含a[i]的子数组的最大和
                all[i]=returnmax(all[i-1],start[i]);						//all[i]保存a[i]前的子数组的最大和
            }  
            else  
            {  
                start[i]=a[i];  
                all[i]=a[i];  
            }  
        }  
        for(int i=n-1;i>0;i--)  
        {  
            if(i==n-1)  
            {  
                nstart=a[i];  
                nall=a[i];  
                max=returnmax(max,nall+all[i-1]);							
            }  
            else  
            {  
                nstart=returnmax(a[i],nstart+a[i]);					// 从尾至a[i]包含a[i]的子数组最大值
                nall=returnmax(nall, nstart);						//从尾至a[i]所有子数组的最大值
                max=returnmax(max,nall+all[i-1]);  
            }  
        }  
		cout<<max<<endl;
        delete [] a;  
        delete [] start;  
        delete [] all;  
    }  
}  