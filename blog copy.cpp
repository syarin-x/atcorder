#include <bits/stdc++.h>

using namespace std;

#define rep(i,n)      for(long long(i)=0;(i)<(n);(i)++)

int main(){

    long h,w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i,h) cin >> s[i];

    map<long,long> m;
    rep(i,h) rep(j,w) m[s[i][j]]++;

    //even - even
    if( h % 2 == 0 && w % 2 == 0){
        // すべて4の倍数か？
        for(auto it : m){
            if(it.second % 4 != 0){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    } else if( (h * w) % 2 == 1 ){
        // odd - odd
        long a = h * w;
        long b = h + w - 1;
        bool o = false;

        for(auto it : m){
            long cur = it.second;
            long sh = cur - cur % 4;
            long mm = cur % 4;
        }
    } else if((h * w) % 2 == 0) {

    }


    long cur = 0;

    // 1st 4
    for(auto& it : m){
        cur += it.second - it.second % 4;
        it.second -= it.second % 4;
    }


    // h is odd
    if(h & 0x01 && !(w & 0x01)){
        long pool = w;

        // 2nd 2
        pool = min(pool, h * w - cur);

        for(auto& it : m){
            if(it.second & 0x01){
                cout << "No" << endl;
                return 0;
            }

            pool -= it.second - it.second % 2;
            if(pool < 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }



    cout << "Yes" << endl;
}
