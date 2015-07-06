#include <iostream>
using namespace std;

int Get_Haab_Month(char* a);
void Output_Tzolkin_Day(int Tzolkin_Day);

int main()
{

    int n=0,N;
 cin >> N;
    cout << N<<endl;
 int Haab_Day_In, Haab_Year_In;
 char skip;
 char* Haab_Month_In = new char[6];
 while (n++ < N)
 {
  memset(Haab_Month_In, '\0', sizeof(char)*6);
        cin>>Haab_Day_In>>skip>>Haab_Month_In>>Haab_Year_In;

  int Days = 0;
  Days += Haab_Year_In*365;

  int haabm = Get_Haab_Month(Haab_Month_In);  
  Days += haabm * 20 + Haab_Day_In + 1;
      
  int Tzolkin_Yeay = Days / 260;
  Days %= 260;

   if (Days == 0)
    Tzolkin_Yeay --;

  int Tzolkin_Month = Days % 13;
  int Tzolkin_Day = Days % 20 ;

  if (Tzolkin_Month != 0 )
     cout << Tzolkin_Month;
  else 
   cout << 13 ;

  Output_Tzolkin_Day(Tzolkin_Day);
  cout<<Tzolkin_Yeay<<endl;
 }

 delete[] Haab_Month_In;
 return 0;
}

 
int Get_Haab_Month(char* a)
{
 if (strcmp(a, "pop") == 0)
  return 0;
 else if (strcmp(a, "no") == 0)
  return 1;
 else if (strcmp(a, "zip")== 0)
  return 2;
 else if (strcmp(a, "zotz")== 0)
  return 3;
    else if(strcmp(a,"tzec")== 0)
  return 4;
 else if (strcmp(a,"xul")== 0)
  return 5;
 else if (strcmp(a, "yoxkin")== 0)
  return 6;
 else if (strcmp(a, "mol")== 0)
  return 7;
    else if (strcmp(a, "chen")== 0)
  return 8;
 else if (strcmp(a, "yax")== 0)
  return 9;
 else if (strcmp(a, "zac")== 0)
  return 10;
 else if (strcmp(a, "ceh")== 0)
  return 11;
 else if (strcmp(a, "mac")== 0)
  return 12;
 else if (strcmp(a, "kankin")== 0)
  return 13;
 else if (strcmp(a, "muan")== 0)
  return 14;
 else if (strcmp(a, "pax")== 0)
  return 15;
 else if (strcmp(a, "koyab")== 0)
  return 16;
 else if (strcmp(a, "cumhu")== 0)
  return 17;
 else if (strcmp(a, "uayet")== 0)
  return 18;

    return -1;
}
  
void Output_Tzolkin_Day(int Tzolkin_Day)
{
 switch(Tzolkin_Day){
 case 1:
  cout<<" imix ";
  break;
 case 2:
  cout<<" ik ";
  break;
 case 3:
  cout<<" akbal ";
  break;
 case 4:
  cout<<" kan ";
  break;
 case 5:
  cout<<" chicchan ";
  break;
 case 6:
  cout<<" cimi ";
  break;
 case 7:
  cout<<" manik ";
  break;
 case 8:
  cout<<" lamat ";
  break;
 case 9:
  cout<<" muluk ";
  break;
 case 10:
  cout<<" ok ";
  break;
 case 11:
  cout<<" chuen ";
  break;
 case 12:
  cout<<" eb ";
  break;
 case 13:
  cout<<" ben ";
  break;
 case 14:
  cout<<" ix ";
  break;
 case 15:
  cout<<" mem ";
  break;
 case 16:
  cout<<" cib ";
  break;
 case 17:
  cout<<" caban ";
  break;
 case 18:
  cout<<" eznab ";
  break;
 case 19:
  cout<<" canac ";
  break;
 case 0:
  cout<<" ahau ";
  break;
 default:
  break;
 }
}