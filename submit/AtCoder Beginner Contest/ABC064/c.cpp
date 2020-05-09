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
long long getDigit(long long n);      // 数字の桁数を取得する。
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
#define LCM(a,b)      ((a)/GCD((a),(b))*(b))
#define kiriage(a,b)  ((a)+(b)-1)/(b)

const int INF = 1e9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

// code
// ------------------------------------------------
int main()
{

  ll n;cin >> n;
  map<string,ll> m;

  rep(i,n)
  {
    ll buf;
    cin >> buf;

    if(buf <= 399)
    {
      m["Ash"]++;
    }
    else if(buf <= 799)
    {
      m["Brown"]++;
    }
    else if(buf <= 1199)
    {
      m["Green"]++;
    }
    else if(buf <= 1599)
    {
      m["Sky"]++;
    }
    else if(buf <= 1999)
    {
      m["Blue"]++;
    }
    else if(buf <= 2399)
    {
      m["Yellow"]++;
    }
    else if(buf <= 2799)
    {
      m["Orange"]++;
    }
    else if(buf <= 3199)
    {
      m["Red"]++;
    }
    else
    {
      m["Rainbow"]++;
    }
  }

  ll le = sz(m);

  ll hi = le;

  if(m["Rainbow"] > 0)
  {
    ll r = m["Rainbow"];
    hi = hi - 1 + r;
    le--;
    if(le == 0)le++;
  }

  cout << le << " " << hi << endl;

  return 0;
}
// funcの実体
// ------------------------------------------------
ll getDigit(ll n)
{
  int i = 1;
  while(1)
  {
    n = n / 10;
    if(n == 0)
      break;
    i++;
  }
  return i;
}
ll CalcSumOfDigit(ll n)
{
  ll s = 0;
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
