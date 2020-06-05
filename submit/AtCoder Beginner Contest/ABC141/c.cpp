#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
  int n = 0,k=0,q;
  int i = 0,j = 0;
  cin >> n >> k >> q;
  
  vector<int> p;
 
  for(;i<n;i++)
  {
    p.push_back(0);
  }
  
  for(i = 0;i<q;i++)
  {
    cin >> j ;
    p[j - 1]++;
  }
  
  for(i = 0 ; i < n;i++)
  {
    if(k - q + p[i] <= 0)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  
  return 0;
}
