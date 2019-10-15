#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> p(N);
    for(int i=0;i<N;i++)
        cin >> p[i];
        
    vector<int> s(N);
    for(int i=0;i<N;i++)
        cin >> s[i];
        
    vector<int> c(K);
    for(int i=0;i<K;i++){
        cin >> c[i]; c[i]--;
    }

    int ret=0;

    for(int k=0;k<K;k++){
        // strongest in school
        bool strongest = true;
        for(int i=0;i<N;i++){
            if(i == c[k] || s[i] != s[c[k]]) continue;
            if(p[i] > p[c[k]])
                strongest = false;
        }
        if(!strongest)
            ret++;
    }
    cout << ret << endl;

    return 0;
}