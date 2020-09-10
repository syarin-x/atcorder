#include <cstdint>

template <long long Modulus> class modint {
    public:
        long long val;
        modint(long long v = 0) : val(v % Modulus){
            if(val < 0) val += Modulus;
        }

        // =付きの演算子に処理を任せる
        modint operator + (const modint& rhs) { return modint(*this) += rhs; }
        modint operator - (const modint& rhs) { return modint(*this) -= rhs; }
        modint operator * (const modint& rhs) { return modint(*this) *= rhs; }
        modint operator / (const modint& rhs) { return modint(*this) /= rhs; }

        modint operator = (const long long& rhs) {
            val = rhs;
            val = val % Modulus;
            cout << "a" << endl;
            return modint(*this);
        }

        modint& operator += (const modint& rhs) {
            // まず足してみて、Modulusを超えてくるようなら引く
            val += rhs.val;
            if(val >= Modulus) val -= Modulus;
            return *this;
        }

        modint& operator -= (const modint& rhs){
            // 負になっちゃったら足す
            val -= rhs.val;
            if( val < 0 ) val += Modulus;
            return *this;
        }

        modint& operator *= (const modint& rhs){
            // modintな時点でvalは %Modulus しているのでこれでよい。
            val = val * rhs.val % Modulus;
            return *this;
        }

        modint& operator /= (const modint& rhs){
            return *this *= inv(rhs);
        }

        // ! TODO: inverseを作っておく
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

        modint& inv(const modint& rhs){
            ll u,v;
            extGCD(a.val, Modulus, u, v);
            return modint(u);
        }
        

        bool operator == (const modint& rhs){
            return this->val == rhs.val;
        }

        bool operator != (const modint& rhs){
            return this->val != rhs.val;
        }

        // TODO: iostreamをつくっておく？

}