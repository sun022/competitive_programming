#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<int> par;
vector<int> dist;
vector<int> num_viable;
vector<bool> viable;

void dfs(int x, int tar){
    num_viable[x] = 0;
    if(dist[x] != tar)
        viable[x] = false;
    if(viable[x])
        num_viable[x]++;        
    
    for(auto y:v[x]){
        if(y == par[x]) continue;
        par[y] = x;
        dist[y] = dist[x] + 1;
        dfs(y, tar);
        num_viable[x] += num_viable[y];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int N;
    cin >> N;
    v = vector<vector<int>>(N);
    par = vector<int>(N);
    num_viable = vector<int>(N, 0);
    dist = vector<int>(N);
    viable = vector<bool>(N, true);

    for(int i=0;i<N-1;i++){
        int x,y;
        cin >> x >> y; x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout << "d 1" << endl;
    //int ret; cin >> ret;
    int ret = 2;

    int root = 0;
    par[root] = -1;
    dist[root] = 0;
    dfs(root, ret);

    while(true){      
        bool change=false;
        for(auto y : v[root]){
            if(y == par[root]) continue;
            if(num_viable[y] == num_viable[root]){
                root = y;
                cerr << "new root " << y << endl;
                change=true;
                break;
            }
        }
        if(!change) break;
    }

    int best=0;
    int bestIndex;
    for(int i=0;i<N;i++) {
        // dist from here -> num_viable[i] or num_viable[root] - num_viable[i]
        // ie remove at least min(num_viable[root] - num_viable[i], num_viable[i])
        if(num_viable[i] == 0) continue;
        int x = min(num_viable[root] - num_viable[i], num_viable[i]);
        cerr << i << " " << num_viable[i] << " "<< x << endl;
        if(x > best){
            bestIndex = i;
            best = x;
        }
    }

    int value = INT_MAX;
    for(auto y : v[root]){
        if(y == par[root]) continue;
        if(num_viable[y] == 0) continue;
        value = min(value, num_viable[root] - num_viable[y]);
    }

    cout << "val:" << value << endl;

    if(value > best){
        cout << "s " << root << endl;
        int ret; cin >> ret;
    }
    else {
        cout << "d " << bestIndex+1 << endl;
        int ret; cin >> ret;
        ret += 
        dfs(root, ret);
    }


    return 0;
}