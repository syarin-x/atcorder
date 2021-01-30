#include<iostream>
#include<vector>

using namespace std;

template< typename T>
class NoC {
    vector<T> _fact, _fact_inv, _inv;
        /*
            _fact       : i の階乗
            _fact_inv   : _factの逆元
            _inv        : i の逆元
        */
    NoC(int s) : _fact(s + 1), _fact_inv(sz + 1, 1) , _inv(sz + 1, 1) {
        _fact[0] = _fact_inv[s] = _inv[0] = 1;

        for(int i = 1; i <= sz; ++i){
            _fact[i] = _fact[i - 1] * i;
            _fact_inv[i] /= _fact[i];
            T temp_i = i;
            _inv[i] /= temp_i;
        }
    }

    inline T fact(int k) const { return _fact[k]; }
    inline T fact_inv(int k) const { return _fact_inv[k]; }
    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const {
        if( r < 0 || n < r ) return 0;
        return fact(n) * fact_inv(n - r);
    }

    T C(int n, int r) const {
        if( r < 0 || n < r ) return 0;
        return fact(n) * fact_inv(n - r) * inv(r);
    }

    T H(int n, int r) const {
        if(n < 0 || r < 0) return 0;
        return fact(n + r - 1) * fact_inv(r) * fact_inv(n - 1);
    }
}

inf main(void){

    


}