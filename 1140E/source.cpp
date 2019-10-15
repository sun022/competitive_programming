#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353;
int K, mod_inv_K;

// finds gcd d > 0 and x,y such that a*x + b*y = d
int64_t xGCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
 
	int64_t x1, y1, gcd = xGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

int64_t get_inverse(int k, int MOD){
    int64_t x, y;
    xGCD(k, MOD, x, y);
    if(x < 0) x+= MOD;
    return x;
}

int pow_mod(int64_t n, int k){ // n,k <= INT32_MAX
    n %= MOD;
    int64_t ret = 1;
    while(k!=0){
        if(k&1){
            ret = (ret*n) % MOD;
        }
        k /= 2;
        n = (n*n) % MOD;
    }
    if(ret < 0) ret += MOD;
    return ret;
}

int solve(vector<int> &X){
    if(X.size() == 0) return 1;
    if(X.size() == 1) return X[0] != -1 ? 1 : K;
    int a=0;
    int64_t ret=1;
    while(a!=X.size()-1){
        int b=a+1;
        while(!(b==X.size()-1 || X[b] != -1)) b++;
        //cout << a << "-> "<<  b << endl;
        if(X[a] == -1 && X[b] == -1) {
            //cout << "1." << endl;
            //ret += K*(K-1)^(b-a);
            ret *= (int64_t)K * pow_mod(K-1, b-a) % MOD;
            ret %= MOD;
        }
        if((X[a] == -1 && X[b] != -1) || (X[a] != -1 && X[b] == -1)){
            //cout << "2." << endl;
            //ret += (K-1)^(b-a);
            ret *= pow_mod(K-1, b-a);
            ret %= MOD;
        }
        if(X[a] != -1 && X[b] != -1){
            //cout << "3." << endl;
            //ret += (1 - (1-K)^(b-a))/k;
            int add = (int64_t)(1 - pow_mod(1-K, b-a)) * mod_inv_K % MOD;
            if(X[a] == X[b]) add -= 1;
            if((b-a) % 2 == 0)
                add *= -1;
            ret *= add;
            ret %= MOD;
        }

        a=b;
    }
    ret%=MOD;
    if(ret < 0) ret += MOD;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N >> K;
    mod_inv_K = get_inverse(K, MOD);
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> X,Y;
    for(int i=0; i<N; i+=2)
        X.push_back(A[i]);
    for(int i=1; i<N; i+=2)
        Y.push_back(A[i]);

    // for(int i=0;i<X.size();i++)
    //      cout << X[i] << " ";
    //  cout << endl;
    int a = solve(X);
    // cout << a << endl;
    // cout << endl;

    //  for(int i=0;i<Y.size();i++)
    //      cout << Y[i] << " ";
    //  cout << endl;
    int b = solve(Y);
    // cout << b << endl;

    int ans = (int64_t)a*b%MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;

    return 0;
}