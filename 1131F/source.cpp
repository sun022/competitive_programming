#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for(int i=0;i<N-1;i++){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    vector<int> z(N);
    vector<deque<int>> block(N);
    for(int i=0;i<N;i++)
        block[i].insert(block[i].end(), i);
    iota(z.begin(), z.end(), 0);

    for(int i=0;i<N-1;i++){
        // merge z[x[i]], z[y[i]]
        int a = x[i];
        int b = y[i];
        // if(z[a] == z[b]) continue;
        if(z[a] > z[b]) swap(a,b);
        
        // merge z[b] into z[a]
        int zb = z[b];
        for(auto w : block[zb]){
            block[z[a]].push_back(w);
            z[w] = z[a];
        }
        block[zb].clear();
    }

    for(auto x : block[0]) {
        cout << (x+1) << " ";
    }
    cout << endl;

    return 0;
}