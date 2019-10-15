#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> v, v_inc;

vector<int> state;
vector<int> t_in;
vector<int> t_out;

int num_comp = 0;
vector<int> comp;

vector<int> comp_state;
vector<int> comp_size;

void dfs(int x, int c){
    comp[x] = c;
    comp_size[c]++;
    for(auto y : v[x])
        if(comp[y] == -1)
            dfs(y, c);
    for(auto y : v_inc[x])
        if(comp[y] == -1)
            dfs(y, c);       
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    
    v = vector<vector<int>>(N);
    v_inc = vector<vector<int>>(N);
    state = vector<int>(N, 0);
    
    comp = vector<int>(N, -1);

    for(int i=0;i<M;i++){
        int x,y; cin >> x >> y; x--; y--;
        v[x].push_back(y);
        v_inc[y].push_back(x);
    }

    for(int r=0;r<N;r++){
        if(comp[r] == -1){
            // comp_state.push_back(
            comp_size.push_back(0);
            comp_state.push_back(0);
            dfs(r, num_comp);
            num_comp++;
        }
    }

    // cout << num_comp << endl;

    stack<tuple<int,int, bool>> s;
    for(int r=0;r<N;r++){
        if(state[r] != 0) continue;

        vector<int> comp_hit;
        bool cycle = false;

        s.push({-1, r, 0});
        while(!s.empty()){
            auto [prev, x, dir] = s.top(); s.pop();
            
            if(dir == 0){
                //cout << prev << " -> " << x << endl;
                s.push({prev, x, 1});

                if(state[x] == 2){
                    comp_hit.push_back(comp[x]);
                }
                if(state[x] == 1){ // loop
                    // cout << "!" << endl;
                    cycle = true;
                }
                if(state[x] == 0){
                    state[x] = 1;
                    for(auto y : v[x]){
                        s.push({x, y, 0});
                    }
                }
            }
            if(dir == 1){
                //cout << prev << " -> " << x << "\t*" << endl;
                state[x] = 2;
            }
        }
        if(cycle)
            comp_state[comp[r]] = 1;
    }

    int ans = N;
    for(auto x : comp_state)
        if(!x)
            ans--;
        
    cout << ans << endl;
    
    return 0;
}