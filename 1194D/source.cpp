#include <bits/stdc++.h>

using namespace std;

// return true if p1 win
bool f(){
    int N,K;
    cin >> N >> K;

    // 012345
    // LWWLWW
    if(K % 3 != 0) {
        N %= 3;
        if(N == 0)
            return false;
        return true;        
    }

    // otherwise repeating period is of length (K+1)

    // 0123456 789
    // LWWLWWW LWW

    N %= K+1;
    if(N == K) return true;
    N %= 3;
    if(N == 0)
        return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int t=1;t<=T;t++){
        cout << (f() ? "Alice" : "Bob") << endl;
    }

    return 0;
}