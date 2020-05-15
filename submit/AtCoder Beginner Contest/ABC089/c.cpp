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
  ll n;
  cin >> n;
  map<char,ll> m;

  rep(i,n)
  {
    string buf;
    cin >> buf;

    switch (buf[0])
    {
      case 'M':
      case 'A':
      case 'R':
      case 'C':
      case 'H':
        m[buf[0]]++;
        break;
      default:
        break;
    }
  }

  ll num = sz(m);
  if(num < 3)
  {
    cout << 0 << endl;
    return 0;
  }
  vll a;

  for(auto it: m)
  {
    a.push_back(it.second);
  }

  ll ans = 0;
  for(ll bit = 0; bit < (1 << num); ++bit)
  {
    ll cnt = 0;
    ll ans_once = 1;
    for(ll i = 0; i < num; ++i)
    {
      if(bit & (1 << i))
      {
        cnt++;
        ans_once *= a[i];
      }
    }

    if(cnt != 3) continue;

    ans += ans_once;
  }

  cout << ans << endl;


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
