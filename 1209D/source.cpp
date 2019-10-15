#include <bits/stdc++.h>

using namespace std;


int N, K;
vector<vector<int>> v;
vector<int> colour;
vector<int> comp_size;

void dfs(int x, int c){
    colour[x] = c;
    comp_size[c]++;
    for(auto y : v[x]){
        if(colour[y] == -1)
            dfs(y, c);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    v = vector<vector<int>>(N);
    colour = vector<int>(N, -1);

    set<pair<int,int>> s;
    for(int i=0;i<K;i++){ // for each guest
        int x,y;
        cin >> x >> y; x--; y--;
        if(!(x<y)) swap(x,y);

        if(s.count({x,y})) continue;
        s.insert({x,y});

        v[x].push_back(y);
        v[y].push_back(x);
    }

    
    // find connected components where nodes are snacks, edges are guests
    for(int i=0;i<N;i++){
        if(colour[i] != -1) continue;
        comp_size.push_back(0);
        dfs(i, comp_size.size()-1);
    }

    int happy = 0;
    //cout << comp_size.size() << endl;
    for(auto x : comp_size){
        happy += x-1;
        //cout << x << endl;
    }
    cout << K - happy << endl;
    return 0;
}