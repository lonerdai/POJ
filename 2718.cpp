#include <iostream>
#include <string>
#include <algorithm>
#include<bitset>
using namespace std;

int main()
{

	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string all;
		getline(cin, all);
		all.erase(remove(all.begin(), all.end(), ' '), all.end());
		//remove移除所有的为' '的字符，并将指针移动到末尾
		int result = 0x3F3F3F3F;
		int length = all.size();
		int cut = length/ 2;
		int permute = 1<<all.size();
		do
		{
			bitset<10>used = bitset<10>(permute);
			if(used.count() != cut)
				continue;
			string s1,s2;
			for(int i=0;i<length;i++)
			{
				if(used[i])
					s1+=all[i];
				else 
					s2+=all[i];
			}
			
			do
			{
				int a1 = atoi(s1.c_str());
				do
				{
					int a2 = atoi(s2.c_str());
					if(abs(a1-a2)<result)
						result = abs(a1-a2);
				}while(next_permutation(s2.begin(),s2.end()));
			}while(next_permutation(s1.begin(),s1.end()));


		} while (--permute);

		cout << result << endl;
	}
	return 0;
}