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
int getDigit(int n);            // 数字の桁数を取得する。
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
ll h,w;
vector<string> mp(500);
bool tb[500][500] = {false};

void search(int x,int y)
{
  if( x < 0 || w <= x || y < 0 || h <= y || mp[x][y] == '#') return;
  
  if(tb[x][y] == true) return;

  tb[x][y] = true;

  search(x-1,y);
  search(x+1,y);
  search(x,y-1);
  search(x,y+1);

}
int main() {
  
  cin >> h >> w;

  vector<string> c(h);
  rep(i,h) cin >> c[i];

  pair<ll,ll> start,goal;

  rep(i,500)
  rep(j,500)
  {
    tb[i][j] = false;
  }

  rep(i,h)
  rep(j,w)
  {
    if(mp[i][j] == 's')
    {
      start.first = i;
      start.second = j;
    }
    else if(mp[i][j] == 'g')
    {
      goal.first = i;
      goal.second = j;
    }
  }

  search(start.first,start.second);

  if(tb[goal.first][goal.second]) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}
// funcの実体
// ------------------------------------------------
int getDigit(int n)
{
  int i = 1;
  while(1)
  {
    n = n / 10;
    if(n == 1)
      break;
    i++;
  }
  return i;
}
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
