#include <bits/stdc++.h>

using namespace std;

int64_t gcd(int64_t a, int64_t b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M, Q;
    cin >> N >> M >> Q;
    
    int64_t d = gcd(N, M);
    for(int q=1;q<=Q;q++){
        int64_t sx,sy,tx,ty;
        cin >> sx >> sy >> tx >> ty;
        sy--; ty--;
        
        int64_t s_sec = (sx == 1 ? sy/(N/d) : sy/(M/d));
        int64_t t_sec = (tx == 1 ? ty/(N/d) : ty/(M/d));
        cout << (s_sec == t_sec ? "YES" : "NO" ) << endl;
    }

    return 0;
}