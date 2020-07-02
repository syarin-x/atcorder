#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  int i,n,b;
  vector<double> v;
  cin >> n;
  
  for(i = 0; i < n; i++)
  {
    cin >> b;
    v.push_back(b);
  }
  sort(v.begin(),v.end());
  
  for(i = 0; i < n - 2; i++)
  {
    v[i + 1] = (v [i] + v[i + 1]) / 2.0;
  }
  
  cout << (v [i] + v[i + 1]) / 2.0;
}
