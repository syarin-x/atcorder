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
#define pb            push_back
#define sz(a)         int((a).size())
#define rep(i,n)      for(int(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(int(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())
#define rvsort(v)     sort(rall((v)))
#define vi            vector<int>
#define GCD(a,b)      __gcd((a),(b))
#define LCM(a,b)      (a)/GCD((a),(b))*(b)

const int INF = 1e9;

using ull = unsigned long long;
using ll = long long;

// code
// ------------------------------------------------
int main() {

  ll n;
  cin >> n;
  map<ll,ll> m;

  rep(i,n)
  {
    ll b = 0;
    cin >> b;
    m[b]++;
  }
  ll ans = 0;
  for(auto itr = m.begin();itr != m.end();itr++)
  {
    auto a = m.find(itr->first - 1);
    auto b = m.find(itr->first);
    auto c = m.find(itr->first + 1);
    ll p = (a != m.end()) ? a->second : 0;
    ll q = (b != m.end()) ? b->second : 0;
    ll r = (c != m.end()) ? c->second : 0;
    ans = max(ans,p + q + r);
  }


  cout << ans << endl;


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
