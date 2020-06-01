// include
// ------------------------------------------------
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// func
// ------------------------------------------------
int CalcSumOfDigit(int n);      // 各桁の和を計算する。
int getDigit(int n);            // 数字の桁数を取得する。
string upper(string str);       // 英字を大文字に変換する。
string lower(string str);       // 英字を小文字に変換する。

// class
// ------------------------------------------------
class Combi
{
  public:
    Combi();
    long long Combination(long long n, long long k);
    long long nPk_modp(long long n, long long k, long long p);
  private:
    vector<vector<long long>> memo;
    long long n_num;
    long long k_num;
    void Resize(long long n, long long k);
};

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
typedef vector<long> vll;
// code
// ------------------------------------------------
int main() {

    ll n;
    cin >> n;

    map<ll,ll> a,b;

    rep(i,n)
    {
        ll buf;
        cin  >> buf;
        if(i % 2 == 0)
            a[buf]++;
        else
            b[buf]++;
    }

    vector<pair<ll,ll>> p,q;

    for(auto it: a) p.emplace_back(it);
    for(auto it: b) q.emplace_back(it);
    

    auto comp = [](auto a,auto b){
        return a.second > b.second;
    };

    sort(all(p),comp);
    sort(all(q),comp);

    ll f,s;
    f = p[0].second;
    s = q[0].second;

    if(p[0].first == q[0].first)
    {
        if(p[0].second > q[0].second)
        {
            if(sz(q) != 1)
                s = q[1].second;
            else
                s = 0;                   
        }
        else if(p[0].second > q[0].second)
        {
            if(sz(p) != 1)
                f = p[1].second;
            else
                f = 0;            
        }
        else
        {
            bool flg = false;
            for(ll i = 0; i < min(sz(q),sz(p)); ++i)
            {
                if(q[i].second != p[i].second)
                {
                    flg = true;
                    f = p[0].second;
                    s = max(p[i].second, q[i].second);
                    break;
                }
            }
            if(!flg)
            {
                if(sz(q) != 1)
                    s = q[1].second;
                else
                    s = 0;                
            }
        }
    }

    ll ans = n - f - s;
    
    cout << ans << endl;


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


Combi::Combi(){
  n_num = -1;
  k_num = -1;
};
ll Combi::Combination(ll n, ll k)
{
  Resize(n,k);

  ll ret;
  if(memo[n][k] != 0)
  {
    ret = memo[n][k];
  }
  else if(n == k || k == 0)
  {
    memo[n][k] = 1;
    ret = 1;
  }
  else
  {
    ret = Combination(n - 1, k - 1) + Combination(n - 1, k);
    memo[n][k] = ret;
  }
  return ret;
}

void Combi::Resize(ll n, ll k)
{
  if(n_num <= n || k_num <= k)
  {
    n_num = (n + 1) * 2;
    k_num = (k + 1) * 2;
    memo.resize(n_num);
    for(auto itr = memo.begin(); itr != memo.end(); ++itr)
    {
      itr->resize(k_num);
    }
  }
}

long long Combi::nPk_modp(long long n, long long k, long long p)
{
  ll ans = 1;
  for(long long i = k; i <= n; i++)
  {
    ans = (ans * i) % p;
  }

  return ans;
};
