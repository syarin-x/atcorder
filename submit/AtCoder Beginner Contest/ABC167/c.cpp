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

  ll n,m,x;
  cin >> n >> m >> x;

  vll c(n);
  vector<vector<ll>>  a(n,vector<ll>(m));

  rep(i,n)
  {
    cin >> c[i];
    rep(j,m)
    {
      cin >> a[i][j];
    }
  }

  ll ans = LLONG_MAX;
  bool OK = false;

  for(ll bit = 0;  bit < (1 << n); bit++)
  {
    ll val = 0;
    vll b(m,0);
    for(ll i = 0; i < n; i++)
    {
      if((bit >> i) & 1)
      {
        val += c[i];
        rep(j,m)
        {
          b[j] += a[i][j];
        }
      }
    }

    bool flg = true;
    rep(i,m)
    {
      if(b[i] < x)
      {
        flg = false;
      }
    }

    if(flg)
    {
      ans = min(ans,val);
      OK = true;
    }

  }

  if(OK) cout << ans << endl;
  else cout << -1 << endl;


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
