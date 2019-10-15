#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, I;
    cin >> N >> I;

    map<int, int> m;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        m[x]++;
    }

    I*=8;
    I/=N;
    // then no. of unique allowed values is 2^I

    int64_t allowed=1;
    for(int i=1;i<=I;i++){
        allowed*=2;
        if(allowed >= N) break;
    }

    // for(auto [k,v] : m){
    //     cout << k << ":" << v << endl;
    // }


    auto s = m.begin();
    auto t = m.begin();
    int uniq = 0;
    int score = 0;
    int max_score = 0;
    while(true){        
        if(uniq < allowed){
            score += t->second;
            t++;
            uniq++;
        }
        else {
            score -= s->second;
            s++;
            uniq--;
        }
        // cout << score << endl;
        max_score = max(max_score, score);
        if(t == m.end())
            break;
    }
    cout << N-max_score << endl;


    return 0;
}