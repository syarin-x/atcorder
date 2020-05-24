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
    map<ll,ll> m;

    rep(i,n)
    {
        ll buf;
        cin >> buf;
        m[buf]++;
    }

    bool ans = false;
    if(sz(m) > 3)
    {
        ans = false;
    }
    else
    {
        if(sz(m) == 1)
        {
            if(m.begin()->first == 0)
                ans = true;
        }
        else
        {
            if(n % 3 == 0)
            {
                if(sz(m) == 2)
                {
                    ll f_v = m.begin()->first;
                    ll f_n = m.begin()->second;

                    if(f_v == 0 && f_n == n / 3)
                        ans = true;
                }
                else if(sz(m) == 3)
                {
                    vll v(3),num(3);
                    ll j = 0;
                    for(auto itr = m.begin(); itr != m.end(); ++itr)
                    {
                        v[j] = itr->first;
                        num[j] = itr->second;
                        ++j;
                    }

                    if((num[0] == num[1] && num[1] == num[2] && num[2] == num[0])
                        && (((v[0] ^ v[1]) ^ v[2]) == 0))
                    {
                        ans = true;
                    }    
                }
            }
        }

    }

    if(ans) cout << "Yes" << endl;
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
