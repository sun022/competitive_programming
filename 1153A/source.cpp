#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, T;
    cin >> N >> T;
    
    int best_wait=INT_MAX;
    int best_index;
    for(int i=1;i<=N;i++){
        int s,d;
        cin >> s >> d;

        int w;
        if(s >= T){
            w = s-T;
        }
        else {
            w = (s-T)%d;
            if(w <0) w+=d;
        }
        // cout << i << "\t" << w << endl;
        if(w < best_wait){
            best_wait = w;
            best_index = i;
        }
    }

    cout << best_index << endl;

    return 0;
}