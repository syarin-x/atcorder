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
string upper(string str);       // 英字を大文字に変換する。
string lower(string str);       // 英字を小文字に変換する。

// define
// ------------------------------------------------
#define all(a)        (a).begin(),(a).end()
#define rall(a)       (a).rbegin(),(a).rend()
#define sz(a)         int((a).size())
#define rep(i,n)      for(int(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(int(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())
#define rvsort(v)     sort(rall((v)))
#define vi            vector<int>
#define GCD(a,b)      __gcd((a),(b))
#define LCM(a,b)      (a)/GCD((a),(b))*(b)
#define kiriage(a,b)  ((a)+(b)-1)/(b)

const int INF = 1e9;

typedef long long ll;
typedef unsigned long long ull;

// code
// ------------------------------------------------
void cntBomb(int* s,int i,int j)
{

}

int main() {

  int h,w;
  cin >> h >> w;

  vector<string> s(h);

  int m[h][w];

  memset(m,0,sizeof(m));

  rep(i,h) cin >> s[i];

  rep(i,h)
  {
    rep(j,w)
    {
      if(s[i][j] == '#')
      {
        for(int a = i - 1;a <= i + 1;a++)
        {
          for(int b = j - 1;b <= j + 1;b++)
          {
            if((0 <= a && a < h) && ( 0 <= b && b < w))
            {
              if(s[a][b] != '#')
              {
                m[a][b]++;
              }
            }
          }
        }
      }
    }
  }

  rep(i,h)
  {
    rep(j,w)
    {
      if(s[i][j] == '#')
      {
        cout << s[i][j];
      }
      else
      {
        cout << m[i][j];
      }
    }
    cout << endl;
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

string upper(string str)
{
  for(auto itr = str.begin();itr != str.end() ; itr++)
  {
    if(97 <= *itr && *itr <= 122)
    {
      *itr = *itr - 32;
    }
  }
  return str;
}

string lower(string str)
{
  for(auto itr = str.begin();itr != str.end() ; itr++)
  {
    if(65 <= *itr && *itr <= 90)
    {
      *itr = *itr + 32;
    }
  }
  return str;
}
