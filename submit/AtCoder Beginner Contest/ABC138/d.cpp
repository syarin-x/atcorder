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
vector<pair<long long,long long>> prime_factorize(long long p); // 素因数分解

// class
// ------------------------------------------------
class Combi {
  public:
    Combi();
    long long Combination(long long n, long long k);
    long long nPk_modp(long long n, long long k, long long p);
  private:
    map<long long, map<long long, long long>> memo;
    long long n_num;
    long long k_num;
};

// define
// ------------------------------------------------
#define all(a)        (a).begin(),(a).end()
#define rall(a)       (a).rbegin(),(a).rend()
#define sz(a)         int((a).size())
#define rep(i,n)      for(long long(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(long long(i)=0;(i)<=(n);(i)++)
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
void dfs(vector<vll> &Graph, vll &ope, vll &val, vector<bool> &seen, ll cur, ll pos){

    if(seen[pos]){
        return;
    }

    seen[pos] = true;

    cur += ope[pos];
    val[pos] += cur;

    for(auto it : Graph[pos]){
        dfs(Graph ,ope, val, seen, cur, it);
    }

    cur -= ope[pos];
}
int main() {

    ll n,q;
    cin >> n >> q;

    vector<vll> Graph(n);

    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;

        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }

    vll ope(n,0);
    vll val(n,0);
    vector<bool> seen(n,false);

    rep(i,q){
        ll p,x;
        cin >> p >> x;
        p--;
        ope[p] += x;
    }

    ll cur = 0;
    dfs(Graph,ope,val,seen,cur,0);

    rep(i,n){
        if(i==0){
            cout << val[i];
        } else {
            cout << " " << val[i];
        }
    }

    cout << "\n";

    return 0;
}
// funcの実体
// ------------------------------------------------
int getDigit(int n) {
  int i = 1;
  while(1) {
    n = n / 10;
    if(n == 1)
      break;
    i++;
  }
  return i;
}
int CalcSumOfDigit(int n) {
  int s = 0;
  while(n) {
    s += n % 10;
    n = n / 10;
  }
  return s;
}

string upper(string str) {
  for(auto itr = str.begin();itr != str.end() ; itr++) {
    if(97 <= *itr && *itr <= 122) {
      *itr = *itr - 32;
    }
  }
  return str;
}

string lower(string str) {
  for(auto itr = str.begin();itr != str.end() ; itr++) {
    if(65 <= *itr && *itr <= 90) {
      *itr = *itr + 32;
    }
  }
  return str;
}


Combi::Combi() {
  n_num = -1;
  k_num = -1;
};

ll Combi::Combination(ll n, ll k) {

  ll ret;
  if(memo[n][k] != 0) {
    ret = memo[n][k];
  } else if(n == k || k == 0) {
    memo[n][k] = 1;
    ret = 1;
  } else {
    ret = Combination(n - 1, k - 1) + Combination(n - 1, k);
    memo[n][k] = ret;
  }
  return ret;
}

long long Combi::nPk_modp(long long n, long long k, long long p) {
  ll ans = 1;
  for(long long i = k; i <= n; i++) {
    ans = (ans * i) % p;
  }

  return ans;
};

vector<pair<long long,long long>> prime_factorize(long long p) {
    vector<pair<long long,long long>> ret;

    for(long long x = 2; x * x <= p; ++x) {
        if(p % x != 0) continue;
        long long num = 0;
        while(p % x == 0) {
            num++;
            p /= x;
        }
        ret.push_back(make_pair(x,num));
    }

    if(p != 1) ret.push_back(make_pair(p, 1));
    
    return ret;
}