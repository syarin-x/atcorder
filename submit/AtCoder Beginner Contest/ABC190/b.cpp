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
vector<pair<char, long long>> runLengthEncoding(string s);      // ランレングス圧縮
long long grid_bfs(vector<string> &m, long long s_r, long long s_c, long long g_r ,long long g_c ,char block); // gridのbfs
bool is_prime(const unsigned n);
long long extGCD(long long a,long long b, long long &x,long long &y);
long long inverse(long long val, long long modulus);

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

class UnionFind {
        vector<int> par;
    public:
        UnionFind(int n);
        bool issame(int x, int y);
        void unite(int x, int y);
        int root(int x);
        int size(int x);
        void debug_print();
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
typedef vector<long long> vll;


#include <cstdint>

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <long long Modulus> class modint {
    public:
        long long val;
        modint(long long v = 0) : val(v % Modulus){
            if(val < 0) val += Modulus;
        }

        // =付きの演算子に処理を任せる
        constexpr modint operator + (const modint& rhs) { return modint(*this) += rhs; }
        constexpr modint operator - (const modint& rhs) { return modint(*this) -= rhs; }
        constexpr modint operator * (const modint& rhs) { return modint(*this) *= rhs; }
        constexpr modint operator / (const modint& rhs) { return modint(*this) /= rhs; }

        constexpr modint operator = (const long long& rhs) {
            val = rhs;
            val = val % Modulus;
            return modint(*this);
        }

        constexpr modint& operator += (const modint& rhs) {
            // まず足してみて、Modulusを超えてくるようなら引く
            val += rhs.val;
            if(val >= Modulus) val -= Modulus;
            return *this;
        }

        constexpr modint& operator -= (const modint& rhs){
            // 負になっちゃったら足す
            val -= rhs.val;
            if( val < 0 ) val += Modulus;
            return *this;
        }

        constexpr modint& operator *= (const modint& rhs){
            // modintな時点でvalは %Modulus しているのでこれでよい。
            val = val * rhs.val % Modulus;
            return *this;
        }

        constexpr modint& operator /= (const modint& rhs){
            return *this *= inv(rhs);
        }

        constexpr modint inv(const modint& rhs){
            ll u,v;
            extGCD(rhs.val, Modulus, u, v);
            return modint(u);
        }

        friend constexpr modint modpow(const modint& rhs, long long n){
            if(n == 0) return 1;
            auto t = modpow(rhs, n / 2);
            t = t * t;
            if(n & 1) t = t * rhs;
            return t;
        }        

        constexpr bool operator == (const modint& rhs){
            return this->val == rhs.val;
        }

        constexpr bool operator != (const modint& rhs){
            return this->val != rhs.val;
        }

        // TODO: iostreamをつくっておく？

};

using mint = modint<1000000007>;
template< typename T>
class NoC {
    vector<T> _fact, _fact_inv, _inv;
        /*
            _fact       : i の階乗
            _fact_inv   : _factの逆元
            _inv        : i の逆元
        */

    inline T fact(int k) const { return _fact[k]; }
    inline T fact_inv(int k) const { return _fact_inv[k]; }
    inline T inv(int k) const { return _inv[k]; }

    public:
    NoC(int s) : _fact(s + 1), _fact_inv(s + 1, 1) , _inv(s + 1, 1) {
        _fact[0] = _fact_inv[s] = _inv[0] = 1;

        for(int i = 1; i <= s; ++i){
            _fact[i] = _fact[i - 1] * i;
            _fact_inv[i] /= _fact[i];
            T temp_i = i;
            _inv[i] /= temp_i;
        }
    }

    T P(int n, int r) const {
        if( r < 0 || n < r ) return 0;
        return fact(n) * fact_inv(n - r);
    }

    T C(int n, int r) const {
        if( r < 0 || n < r ) return 0;
        return fact(n) * fact_inv(n - r) * fact_inv(r);
    }

    T H(int n, int r) const {
        if(n < 0 || r < 0) return 0;
        return (n == 0 ? 1 : fact(n + r - 1) * fact_inv(r) * fact_inv(n - 1));
    }
};

template<typename T>
class SparseTable {
    T** table;
    int* logtable;
public:
    SparseTable(vector<T>& vec) {
        int maxlength = 0;
        while ((1 << (maxlength + 1)) <= vec.size())maxlength++;
        table = new T * [maxlength + 1];
        logtable = new int[vec.size() + 1];
        rep(i, maxlength + 1) {
            table[i] = new T[vec.size()];
            rep(j, vec.size() - (1 << i) + 1) {
                if (i)table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
                else table[i][j] = vec[j];
            }
        }
        for (int i = 2; i <= vec.size(); i++) {
            logtable[i] = logtable[i >> 1] + 1;
        }
    }
    T query(int l, int r) {
        assert(l < r);
        int length = r - l;
        return min(table[logtable[length]][l], table[logtable[length]][r - (1 << logtable[length])]);
    }
};

// code
// ------------------------------------------------
int main() {

    ll n,s,d;
    cin >> n >> s >> d;

    rep(i,n){
        ll x, y;
        cin >> x >> y;
        if(x < s && d < y){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}

// funcの実体
// ------------------------------------------------
int getDigit(int n) {
  int i = 1;
  while(1) {
    n = n / 10;
    if(n == 0)
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

vector<pair<char, long long>> runLengthEncoding(string s){
    vector<pair<char, long long>> ret;
    
    for(long long i = 0; i < s.length(); i++){
        char cur = s[i];
        long long cnt = 1;

        for(long long j = i + 1; j < s.length(); j++){
            if(cur != s[j]) break;
            
            cnt++;
        }

        ret.emplace_back(make_pair(cur,cnt));

        i += cnt - 1;
    }

    return ret;
}

// bfsをしてgoalまでの距離を調べる
long long grid_bfs(vector<string> &m, long long s_r, long long s_c, long long g_r ,long long g_c ,char block = '#'){

    // 訪問済み管理テーブルを作る
    long long r = sz(m);
    long long c = sz(m[0]);
    vector<vector<long long>> dist(r,vector<long long>(c,-1));

    // queueを使ってbfsをする。
    queue<pair<long long, long long>>   q;
    long long grid_dict[][2] = {
        { 1  , 0  }, // up
        { -1 , 0  }, // down
        { 0  , 1  } , // right
        { 0  , -1 }  // left
    };

    q.push(make_pair(s_r, s_c));
    dist[s_r][s_c] = 0;


    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        rep(i,4){
            long long ver = cur.first + grid_dict[i][0];
            long long hor = cur.second + grid_dict[i][1];

            // mapの範囲内で、壁じゃなくて、訪問済じゃない場合は、
            // 距離を記録して訪問予定リストに追加する
            if(( 0 <= ver && ver < r)
                && ( 0 <= hor && hor < c)
                && ( m[ver][hor] != block )
                && ( dist[ver][hor] == -1 )
            ){
                dist[ver][hor] = dist[cur.first][cur.second] + 1;
                q.push(make_pair(ver,hor));
            }
        }
    }

    return dist[g_r][g_c];
}

bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された

    if(n % 2 == 0 || n % 3 == 0) return false;
    // n は 2 と 3 のいずれの倍数でもないことが保証された
    // これより n は (6の倍数)-1 か (6の倍数)+1 である

    // 6の倍数前後の数を使って試し割りをする
    for(unsigned i = 5; i * i <= n; i += 6) {
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }

    return true;
}

// 拡張ユークリッドの控除法
long long extGCD(long long a,long long b, long long &x,long long &y){
    if(b == 0){
        x = 1;
        y = 0;
        return 0;
    }

    long long d = extGCD(b, a % b, y, x);
    y -= a/b * x;
    return d;
}

long long inverse(long long val, long long modulus){
    ll u,v;
    extGCD(val, modulus, u, v);
    return u;
}

// ------------------------------------------------------------------------------
// union find tree
// ------------------------------------------------------------------------------
UnionFind::UnionFind(int N) : par(N, -1) {
    // rep(i,N) par[i] = i;
}

int UnionFind::root(int x){
    int rx = par[x];
    if(rx < 0) return x;

    return par[x] = root(rx);
}

void UnionFind::unite(int x, int y){
    int rx = root(x);
    int ry = root(y);

    if(rx == ry) return;

    if(rx < ry){
        par[rx] += par[ry];
        par[ry] = rx;
    } else {
        par[ry] += par[rx];
        par[rx] = ry;
    }

    return;
}

bool UnionFind::issame(int x, int y){
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
}

int UnionFind::size(int x){
    int rx = root(x);
    return -par[rx];
}

void UnionFind::debug_print(){
    rep(i,par.size()){
        cout << par[i] << endl;
    }
}

