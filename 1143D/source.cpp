#include <bits/stdc++.h>

using namespace std;

int64_t N, K;
int64_t hcf(int64_t a, int64_t b){
    if(b == 0) return a;
    return hcf(b, a%b);
}

int64_t x = INT64_MAX;
int64_t y = 1;

void f(int a, int b){
    // cout << a << "," << b << endl;
    int l_mod_k = (b-a)%K;
    if(l_mod_k <0) l_mod_k += K;
    //cout << l_mod_k << endl;
    for(int64_t l = l_mod_k; l <= K*N; l+=K){
        if(l == 0) continue;

        int64_t n = K*N / hcf(K*N, l);
        //cout << "L=" << l << "\t" << n << endl;
        // num stops = K*N / hcf(L, K*N)
        x = min(x, n);
        y = max(y, n);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    int A, B;
    cin >> A >> B;

    f(1-A, 1-B);
    f(1+A, 1-B);
    f(1-A, 1+B);

    cout << x << " " << y << endl;
    return 0;
}