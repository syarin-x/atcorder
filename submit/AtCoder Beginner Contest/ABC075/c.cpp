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
ll ans;
vector<vector<pair<ll,bool>>> Graph(50);
vector<bool> seen(50,false);

void dfs(ll pos)
{
  seen[pos] = true;
  rep(i,sz(Graph[pos]))
  {
    if(Graph[pos][i].second && seen[Graph[pos][i].first] == false)
    {
      dfs(Graph[pos][i].first);
    }
  }

  return;

}
int main()
{
  ll n,m;
  cin >> n >> m;

  // グラフを作る
  rep(i,m)
  {
    ll a,b;cin >> a >> b;
    a--; b--;
    pair<ll,bool> buf;
    buf.first = b;
    buf.second = true;

    Graph[a].push_back(buf);
    buf.first = a;
    Graph[b].push_back(buf);
  }

  ll ans = 0;
  rep(i,n)
  {
    rep(j,sz(Graph[i]))
    {

      rep(k,n)
      rep(l,sz(Graph[k]))
      {
        Graph[k][l].second = true;
      }

      rep(k,50) seen[k] = false;

      Graph[i][j].second = false;
      dfs(0);

      rep(k,n)
      {
        if(seen[k] == false)
        {
          ans++;
          break;
        }
      }
      Graph[i][j].second = true;
    }
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
