#include <bits/stdc++.h>

using namespace std;

int64_t sqrt(int64_t x){
    return (int64_t)sqrt((long double)x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, K;
    cin >> N >> K;
    
    int64_t a = 1;
    int64_t b = 3;
    int64_t c = -2*N - 2*K;

    int64_t root = sqrt(b*b - 4*a*c);
    int64_t x1 = (-b + root)/(2*a);

    cout << (N-x1) << endl;
    return 0;
}