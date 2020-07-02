#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  int a;
  string s;
  
  cin >> a;
  cin >> s;
  if (a >= 3200)
    cout << s;
  else
    cout << "red";
}
