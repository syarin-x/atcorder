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

  string r,g,b;
  string s;
  cin >> r >> g >> b;

  s = r + g + b;

  int aa = stoi(s);

  if(aa%4) cout << "NO" << endl;
  else cout << "YES" << endl;

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
