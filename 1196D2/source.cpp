#include <bits/stdc++.h>

using namespace std;

void f(){
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    int ret = 0;
    vector<int> count(3, 0); 
    // count[0] for RBG
    // count[1] for BGR
    // count[2] for GRB

    // mainting rolling interval count of hits
    for(int i=0;i<N;i++){
        if(s[i] == 'R')
            count[i%3]++;
        if(s[i] == 'B')
            count[(i+1)%3]++;
        if(s[i] == 'G')
            count[(i+2)%3]++;
        if(i >= K){ 
            int rem = i - K;
            if(s[rem] == 'R')
            count[rem%3]--;
            if(s[rem] == 'B')
                count[(rem+1)%3]--;
            if(s[rem] == 'G')
                count[(rem+2)%3]--;
        }
        if(i >= K - 1){ // full interval
            ret = max(count[0], ret);
            ret = max(count[1], ret);
            ret = max(count[2], ret);
        }
    }
    cout << K-ret << endl;    
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