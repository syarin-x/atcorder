#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	string tenki;
    cin >> tenki;
  
  if(tenki == "Sunny")
    cout << "Cloudy" << endl;
    if(tenki == "Cloudy")
    cout << "Rainy" << endl;
  if(tenki == "Rainy")
    cout << "Sunny" << endl;
  return 0;
}
