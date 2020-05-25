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
#define rall(a)       (a).rbegin(),(a).rend()
#define pb            push_back
#define sz(a)         int((a).size())
#define rep(i,n)      for(int(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(int(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())

const int INF = 1e9;


// code
// ------------------------------------------------
int main() {

  int n,m;

  cin >> n >> m;

  // vector<int> a(m);
  // vector<int> b(m);

  vector<int> t(n);
  rep(i,m)
  {
    int b;
    cin >> b;
    t[b-1]++;

    cin >> b;
    t[b-1]++;
  }

  rep(i,n)
  {
    cout << t[i] << endl;
  }


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
