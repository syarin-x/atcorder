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
  string s;
  ll q;
  cin >> s >> q;

  bool rev_flg = false;
  deque<char> deq;

  rep(i,sz(s))
  {
    deq.push_back(s[i]);
  }

  rep(i,q)
  {
    ll t; cin >> t;

    if(t == 1)
    {
      rev_flg = !rev_flg;
    }
    else if(t == 2)
    {
      ll f;
      char c;
      cin >> f >> c;

      if( (f == 1 && !rev_flg) || (f == 2 && rev_flg) )
      {
        deq.push_front(c);
      }
      else
      {
        deq.push_back(c);
      }
    }   
  }

  ll num = deq.size();

  if(!rev_flg)
  {
    rep(i,num)
    {
      cout << deq.front();
      deq.pop_front();
    }
  }
  else
  {
    rep(i,num)
    {
      cout << deq.back();
      deq.pop_back();
    }
  }
  

  cout << endl;
  
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
