#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  int n,i;
  double b;
  double sum = 0;
  double p = 1;
  vector<int> v;
  
  cin >> n;
  
  for(i = 0;i < n;i++)
  {
    cin >> b;
    v.push_back(b);
  }
  
  for(i = 0; i < n ; i++)
  {
    p = p * v[i];
  }
  for (i = 0;i < n ; i++)
	
  {
    sum += (p / v[i]);
  }
  
  cout << p / sum;
}
