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
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  string s;cin >> s;
  a--;
  b--;
  c--;
  d--;

  bool flg_cont = false;  //連続
  bool flg_chg = c > d;
  bool flg_tri = false;

  // 2連続いわのばしょがあるかチェック
  ll cnt_rock = 0;
  for(ll i = a; i <= max(c,d); ++i)
  {
    if(s[i] == '#')
    {
      cnt_rock++;
    }
    else
    {
      cnt_rock = 0;
    }
    
    if(cnt_rock == 2)
    {
      flg_cont = true;
      break;
    }
  }

  // 3連続の場所があるかチェック
  ll cnt_agola = 0;
  for(ll i = b-1; i <= d + 1; ++i)
  {
    if(s[i] == '.')
    {
      cnt_agola++;
    }
    else
    {
      cnt_agola = 0;
    }

    if(cnt_agola > 2)
    {
      flg_tri = true;
      break;
    }
  }

  bool ans = false;
  if(!flg_chg)
  {
    ans = true;
  }
  else
  {
    if(flg_tri)
    {
      ans = true;
    }
  }

  if(flg_cont) ans = false;

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  

  

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
