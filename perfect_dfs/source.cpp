#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> v = vector<vector<int>>(N);
    vector<vector<int>> v_inc = vector<vector<int>>(N);
    vector<int> state(N, 0);
    vector<int> t_in(N);
    vector<int> t_out(N);

    for(int i=0;i<M;i++){
        int x,y; cin >> x >> y; x--; y--;
        v[x].push_back(y);
        v_inc[y].push_back(x);
    }


    stack<tuple<int,int, bool>> s;
    int t = 0;
    for(int r=0;r<N;r++) {
        if(state[r] != 0) continue;

        s.push({-1, r, 0});
        while(!s.empty()){
            auto [prev, x, dir] = s.top(); s.pop();
            
            if(dir == 0){
                cout << prev << " -> " << x << endl;
                s.push({prev, x, 1});

                if(state[x] == 2){ } // only possible in directed
                if(state[x] == 1){ } // cycle
                if(state[x] == 0){
                    state[x] = 1;
                    t_in[x] = t++;
                    for(auto y : v[x]){
                        s.push({x, y, 0});
                    }
                }
            }
            if(dir == 1){
                cout << prev << " -> " << x << "\t*" << endl;
                if(state[x] == 1){
                    state[x] = 2;
                    t_out[x] = t++;
                }
                if(state[x] == 2){ }
            }
        }
    }
    
    return 0;
}