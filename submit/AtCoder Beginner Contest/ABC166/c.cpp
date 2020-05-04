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
/*void dfs(vector<vll> &Graph,vll &h,vector<bool> &seen,ll no,ll &max,ll &cnt)
{
  for(auto itr = Graph[no].begin(); itr != Graph[no].end(); ++itr)
  {
    if(seen[*itr] == true) continue;
    seen[*itr] = true;
    cout << "seen" << *itr << endl;

    if(max == h[*itr])
    {
      cnt++;
      cout << *itr << " aaa" << endl;
    }
    else if(max < h[*itr])
    {
      cnt = 1;
      cout << "Good" << *itr << endl;
      max = h[*itr];
    }
    
    dfs(Graph,h,seen,*itr,max,cnt);
  }
  return;
}*/

int main() {
  
  ll n,m;
  cin >> n >> m;

  vll h(n);
  vector<bool> seen(n);
  rep(i,n) cin >> h[i];

  vector<vll> Graph(n);

  rep(i,m)
  {
    ll a,b;
    cin >> a >> b;
    Graph[a-1].push_back(b-1);
    Graph[b-1].push_back(a-1);
  }

  ll ans = 0;

  rep(i,n)
  {
    ll max = h[i];
    bool flg =true;
    for(auto itr = Graph[i].begin(); itr!= Graph[i].end();itr++)
    {
      if(max <= h[*itr])
      {
        flg = false;
        break;
      }
    }
    if(flg) ans++;
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
