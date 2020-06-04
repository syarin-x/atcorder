#include <iostream>
using namespace std;
int main(void)
{
  int a,b,c;
  int d;
  cin >> a >> b >> c;
  
  d = a - b;
  if (c > d)
    c = c-d;
  else
    c = 0;
  
  cout << c;
  return 0;
  
}
