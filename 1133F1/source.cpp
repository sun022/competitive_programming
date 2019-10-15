#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
int N,M;
vector<int> state;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    A = vector<vector<int>>(N);
    state = vector<int>(N,0);

    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y; x--; y--;
        A[x].push_back(y);
        A[y].push_back(x);
    }

    int root = 0;
    for(int i=0;i<N;i++){
        if(A[i].size() > A[root].size())
            root = i;
    }
    
    deque<int> q;

    // bfs from root
    q.push_back(root);
    state[root] = 1;

    while(!q.empty()) {
        int x = q.front(); q.pop_front();
        for(auto y: A[x]){
            if(state[y] != 0) continue;
            cout << x+1 << " " << y+1 << endl;
            state[y] = 1;
            q.push_back(y);
        }
    }

    return 0;
}