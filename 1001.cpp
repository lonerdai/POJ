#include<iostream>
using namespace std;
#define LEN 130
#define len1 8
#include<string>
int main()
{
   string str;
   int n;
   while(cin>>str>>n)
   {
      int i,j,k,L;
   int a[len1],r[LEN];
   for(i=0;i<len1;i++)
       a[i]=0;
   for(i=0;i<LEN;i++)
       r[i]=0;
   j=0;
   for(i=str.size()-1;i>=0;i--)
   {
          if(str[i]=='.'){k=i;continue;}
    else 
    {
     a[j]=(int)(str[i]-'0');
     r[j]=(int)(str[i]-'0');
     j++;
    }
   }
      L=n*(str.size()-(k+1));
     for(i=1;i<n;i++)
  {
            int c[LEN*2];
   for(j=0;j<LEN*2;j++)
               c[j]=0;
           for(k=0;k<len1;k++)
     {
           for(j=0;j<LEN;j++)
           c[k+j]+=r[j]*a[k];
     }
        for(k=0;k<LEN*2;k++)
     {
              if(c[k]>=10)
     {
          c[k+1]+=c[k]/10;
       c[k]%=10;
     }
     }
    for(k=0;k<LEN;k++)
     r[k]=c[k];
  }

    
  for(i=LEN-1;i>=L;i--)
  {
   if(r[i]!=0)
             break;
  }
  for(j=i;j>=L;j--)
   cout<<r[j];
  for(i=0;i<L;i++)
  {
     if(r[i]!=0)break;
  }
  if(i<L)
     cout<<'.';
  for(i=0;i<L;i++)
  {
     if(r[i]!=0)break;
  }
  for(j=L-1;j>=i;j--)
   cout<<r[j];
  cout<<endl;
   }
   return 0;
}