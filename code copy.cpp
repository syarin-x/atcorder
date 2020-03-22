// include
// ------------------------------------------------
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

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
int main() {

  string s;
  string div[] = {"dream","dreamer","erase","eraser"};

  cin >> s;
  reverse(s.begin(),s.end());

  rep(i,4)
  {
    reverse(div[i].begin(),div[i].end());
  }

  bool cc = true;
  for(int i = 0; i < s.size();)
  {
    bool c = false;
    rep(j,4)
    {
      if(
          s.substr(0,div[j].size()) == div[j]
        )
        {
          i += div[j].size();
          c = true;
 //         break;
        }
    }
    if(!c)
    {
      cc = false;
      break;
    }

  }

  if(cc) cout << "YES" << endl;
  else cout  << "NO" << endl;

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
