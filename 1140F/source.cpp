#include <bits/stdc++.h>

using namespace std;

const int N = 300000;

vector<set<int>> edges;
vector<int> comp;
vector<vector<int>> c;
vector<vector<int>> c1;

void dfs(int x, int label){
    if(comp[x] != -1) return;
    comp[x] = label;
    if(x < N)   c[label].push_back(x);
    else        c1[label].push_back(x);
    for(auto y : edges[x])
        dfs(y, label);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    edges = vector<set<int>>(2*N);
    comp = vector<int>(2*N, -1);
    int Q;
    cin >> Q;

    for(int q=1;q<=Q;q++){
        int x,y;
        cin >> x >> y;
        x += -1;
        y += N - 1;
        bool exists = edges[x].count(y);
        if(!exists){
            //cout << "adding edge " << x << "(" << comp[x] <<  "), " << y-N << "(" << comp[y] <<  ")" << endl;
            if(comp[x] == -1 && comp[y] == -1){
                int label = c.size();
                comp[x] = label;
                comp[y] = label;
                c.push_back({x});
                c1.push_back({y});
            }
            else if(comp[x] == -1){
                comp[x] = comp[y];
                c[comp[y]].push_back(x);
            }
            else if(comp[y] == -1){
                comp[y] = comp[x];
                c1[comp[x]].push_back(y);
            }
            else if(comp[x] != comp[y]) {
                // merge c[x] into c[y]
                if(c[comp[x]].size() + c1[comp[x]].size() > c[comp[y]].size() + c1[comp[y]].size())
                    swap(x,y);

                int comp_x = comp[x];
                for(auto z : c[comp_x]){
                    comp[z] = comp[y];
                    c[comp[y]].push_back(z);
                }
                c[comp_x].clear();
                for(auto z : c1[comp_x]){
                    comp[z] = comp[y];
                    c1[comp[y]].push_back(z);
                }
                c1[comp_x].clear();
            } else {
                // already same comp
            }

            edges[x].insert(y);
            edges[y].insert(x);
        }
        else {
            //cout << "removing edge " << x << "(" << comp[x] <<  "), " << y-N << "(" << comp[y] <<  ")" << endl;
            edges[x].erase(y);
            edges[y].erase(x);

            // update component via dfs
            int com = comp[x];
            for(auto z : c[com])
                comp[z] = -1;
            for(auto z : c1[com])
                comp[z] = -1;
            c[com].clear();
            c1[com].clear();

            int label = c.size();
            c.push_back({});
            c1.push_back({});
            dfs(x, label);
            if(comp[y] == -1){
                int label1 = c.size();
                c.push_back({});
                c1.push_back({});
                dfs(y, label1);
            }
        }
        int64_t size=0;   
        for(int i=0;i<c.size();i++){
            size += c[i].size()*c1[i].size();
        }
        cout << size << " ";
    }
    cout << endl;

    return 0;
}