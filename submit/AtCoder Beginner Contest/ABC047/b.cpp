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
#define rvsort(v)     sort(rall((v)))

const int INF = 1e9;

// code
// ------------------------------------------------
int main() {

  int w,h,n;

  cin >> w >> h >> n;

  int m[w][h] = {0};

  rep(i,n)
  {
    int x,y,a;

    cin >> x >> y >> a;

    switch(a)
    {
      case 1:
        for(int j = 0;j < x;j++)
        {
          rep(k,h)
          {
            m[j][k] = 1;
          }
        }
        break;
      case 2:
        for(int j = x; j < w;j++)
        {
          rep(k,h)
          {
            m[j][k] = 1;
          }
        }
        break;
      case 3:
        rep(j,w)
        {
          for(int k = 0; k < y;k++)
          {
            m[j][k] = 1;
          }
        }
        break;
      case 4:
        rep(j,w)
        {
          for(int k = y; k < h; k++)
          {
            m[j][k] = 1;
          }
        }
        break;
      default:
        break;
    }
  }

  int cnt = 0;

  rep(i,w)
  {
    rep(j,h)
    {
      if ( m[i][j] == 0)
        cnt++;
    }
  }

  cout << cnt;

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
