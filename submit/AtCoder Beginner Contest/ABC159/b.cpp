// include
// ------------------------------------------------
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// func
// ------------------------------------------------
int CalcSumOfDigit(int n);      // 各桁の和を計算する。

// define
// ------------------------------------------------
#define all(a)        (a).begin(),(a).end()
#define pb            push_back
#define sz(a)         int((a).size())
#define rep(i,n)      for(int(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(int(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())

// code
// ------------------------------------------------
bool isKaibun(string ss)
{
  string sr = ss;
  reverse(all(sr));
  if (ss == sr) return true;
  else return false;
}

int main() {

  string s;
  cin >> s;

  bool is = false;
  if(isKaibun(s))
  {
    string a = s.substr(0, (sz(s) - 1 )/ 2);
    if(isKaibun(a))
    {
      string b = s.substr((sz(s) + 3) / 2 - 1, sz(s) - 1);
      if(isKaibun(b))
      {
        is = true;
      } 
    }
  }

  if(is) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}

// funcの実体
// ------------------------------------------------
int CalcSumOfDigit(int n)
{
  int s = 0;
  while(n)
  {
    s += n % 10;
    n = n / 10;
  }
  return s;
}
