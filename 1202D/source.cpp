#include <bits/stdc++.h>

using namespace std;

void f(){
    int64_t N; cin >> N;

    int64_t k = 100000 - 10000; // 90k
    int64_t kc2 = k*(k-1)/2;
    
    string t;
    while(k >= 2){
        while(N >= kc2){
            N -= kc2;
            t += '1';
        }
        if(t != "") t += '3';
        k--;
        kc2 = k*(k-1)/2;
    }
    // k=1 here
    t += "37";

    cout << t << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
        f();

    return 0;
}