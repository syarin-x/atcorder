#include <iostream>

using namespace std;

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
    long long u,v;
    extGCD(val, modulus, u, v);
    return (u + modulus) % modulus;
}


class NoC {
private:
    bool m_init;
    long long Modulus;
    std::vector<long long> fact, inv, fact_inv;
    void nCK_modP_realloc(long long n);

public:
    NoC(long long MOD);
    ~NoC();
    long long nCk_modP(long n, long k);
};

NoC::NoC(long long MOD)
    : m_init(false),
    Modulus(MOD) {
}

int main(void){
    long long i,mod;
    cin >> i >> mod;

    cout << inverse(i, mod) << endl;
    
}

long long NoC::nCk_modP(long long n, long long k){
    long long fact_num = (long long)fact.size();

    if(fact_num < n)
        nCK_modP_realloc(n);
    
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % Modulus) % Modulus;
}

long long NoC::nCk_modP_realloc(long long n){
    long long lhs = (long long)fact.size();
    
    for(long long i = lhs; i <= n; i++){
        
    }
}