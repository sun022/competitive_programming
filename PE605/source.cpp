#include <bits/stdc++.h>

using namespace std;

int main(){
    int64_t N = 100000000+7;
    int64_t K = 10000 + 7;
    // int64_t N = 6;
    // int64_t K = 2;

    int64_t M = 100000000;

    int64_t X = 1;
    for(int i = 1; i <= N; i++)
        X = (X * 2) % M;
    X = (X - 1) % M;
    if(X < 0) X += M;

    int64_t denom = (X * X) % M;
    if(denom < 0) denom += M;

    cout << denom << endl;


    int64_t num = (K-1) * X % M;
    num += N;

    for(int i = 1; i <= N-K; i++){
        num = (num * 2) % M;
    }
    if(num < 0) num += M;

    cout << num << endl;

    int64_t ans = (num * denom) % M;
    if(ans < 0) ans += M;

    cout << ans << endl;

    return 0;
}