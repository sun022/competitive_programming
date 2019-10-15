#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
vector<vector<pair<int,int>>> fac(5000); // fac[i] = factorization of 1m + i
vector<int> phi(5000);


int64_t extended_gcd(int64_t a, int64_t b, int64_t &r, int64_t &s){
    // cout << "extended_gcd(" << a << "," << b <<")" << endl;
    if(b > a) return extended_gcd(b, a, s, r);
    
    if(b == 0){
        r = 1;
        s = 0;
        return a;
    }

    // a = p*b + q
    // q = p*b - a
    int64_t p = a / b;
    int64_t q = a % b;

    int64_t r1,s1;
    int64_t d = extended_gcd(b, q, r1, s1);
    r = s1;
    s = r1 - p*s1;
    if(a*r + b*s != d) cerr << "gcd error" << endl;
    return d;
}

int64_t f(int n, int m){
    unordered_map<int,pair<int,int>> mp;
    for(auto [p, pow] : fac[n-1000000]){
        int N = 1;
        for(int k = 1; k <= pow; k++)
            N *= p;
        
        mp[p] = {phi[n-1000000]%N, N};
    }
    for(auto [p, pow] : fac[m-1000000]){
        int N = 1;
        for(int k = 1; k <= pow; k++)
            N *= p;
        
        int X = phi[m-1000000]%N;
        if(mp.count(p)){
            auto [_X, _N] = mp[p];
            // {m%N, N}
            if(!(N >= _N)){ // make new condition the stronger one
                swap(N, _N);
                swap(X, _X);
            }
            if(X % _N != _X) // check stronger against weaker
                return 0;            
        }
        mp[p] = {X, N};
    }

    int64_t x = 0;
    int64_t mod = 1;
    for(auto [p, pr] : mp){
        auto [A, N] = pr;

        int64_t r,s;
        int64_t d = extended_gcd(mod, N, r, s);
        if(d != 1) cerr << "d:" << d << endl;
        int64_t x1 = ((__int128)x*s*N + (__int128)A*r*mod) % (mod * N);
        // x1 %= mod*N;
        if(x1<0) x1+= mod*N;

        // check satisfies both constraints
        if(x1 % mod != x || x1 % N != A){
            cerr << "CR error" << endl;
            cerr << x << "(" << mod << ") " << A << "(" << N << ") = " << x1 << endl;
            cerr << "r:" << r << " s:" << s << endl;
            exit(0);
        }
        
        x = x1;
        mod = mod*N;
    }
    return x;
}

vector<pair<int,int>> factorization(int N){
    int i = 0;
    vector<pair<int,int>> ret;
    while(N != 1){
        const int p = prime[i];
        if(p * p > N){
            ret.push_back({N, 1});
            break;
        }
        if(N % p == 0){
            int pow = 0;
            do {
                N /= p; pow++;
            } while(N % p == 0);
            ret.push_back({p, pow});
        }
        i++;
    }
    return ret;
}

int phi_from_fac(int N, vector<pair<int,int>> fac){
    for(auto [p, pow] : fac){
        N /= p;
        N *= p - 1;
    }
    return N;
}

void print_fac(vector<pair<int,int>> fac){
    string s;
    for(int i = 0; i != fac.size(); i++){
        auto [p, pow] = fac[i];
        if(i != 0) s += " * ";
        s += to_string(p);
        if(pow != 1)
            s += "^" + to_string(pow);
    }
    cout << s << endl;
}

int main(){
    // calculate primes up to N via sieve
    int pN = pow(10,7);
    vector<bool> primeBool(pN+1, true);
    primeBool[0] = primeBool[1] = false;
    for(int n = 2; n <= pN; n++){
        if(!primeBool[n]) continue;
        for(int k = 2*n; k <= pN; k += n)
            primeBool[k] = false;
        prime.push_back(n);
    }

    // factorize 1,000,000 to 1,004,999
    

    for(int i=0;i<5000;i++){
        fac[i] = factorization(1000000+i);
        // print_fac(fac[i]);

        phi[i] = phi_from_fac(1000000+i, fac[i]);
    }

    int64_t sum = 0;
    for(int n = 0; n < 5000; n++){
        for(int m = n + 1; m < 5000; m++){
            sum += f(1000000+n, 1000000+m);
        }
    }
            cout << sum << endl;


    return 0;
}