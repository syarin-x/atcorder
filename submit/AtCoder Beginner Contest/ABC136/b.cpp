#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
 
  int n,b,m,i,j;
  cin >> n;
  for(i = 1;i <= 6;i++)
  {
  	if(pow(10,i) > n)
      break;
  }
  
  switch(i)
  {
    case 1:
      m = n;
      break;
    case 2:
      m = 9;
      break;
    case 3:
      m = 9 + n - 100 + 1;
      break;
    case 4:
      m = 9 + 900;
      break;
    case 5:
      m = 9 + 900 + n - 10000 + 1;
      break;
    case 6:
      m = 9 + 900 + 90000;
      break;
  }
  cout << m;
  return 0;
}
