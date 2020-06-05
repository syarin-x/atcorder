#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	string tap;
  int flg = 0;
    cin >> tap;
 
  for(int i = 0;i < tap.length();i++)
  {
  	if(i % 2 )
    {
      if(tap[i] == 'R')
        flg = 1;
    }
      else
      {
        if(tap[i] == 'L')
          flg = 1;
      }
  }
  
  if(flg)
    cout << "No";
  else
    cout << "Yes";
  
  return 0;
}
