#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
int N,M,D;
vector<int> state;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> D;
    A = vector<vector<int>>(N);
    state = vector<int>(N,0);

    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y; x--; y--;
        A[x].push_back(y);
        A[y].push_back(x);
    }

    // int root = 0;
    // for(int i=0;i<N;i++){
    //     if(A[i].size() > A[root].size())
    //         root = i;
    // }
    
    deque<int> q;
    vector<int> comp(N, -1);

    int num_comp = 0;
    vector<vector<int>> hmm;

    // create forest, of G\{0}
    state[0] = 1;
    for(int root = 1; root != N; root++) {
        hmm.emplace_back();
        if(state[root] == 1) continue;
        state[root] = 1;
        comp[root] = num_comp;
        q.push_back(root);
        while(!q.empty()) {
            int x = q.front(); q.pop_front();
            for(auto y: A[x]){
                if(y == 0) hmm[comp[x]].push_back(x);
                if(state[y] != 0) continue;
                // cout << x+1 << " " << y+1 << endl;
                state[y] = 1;
                comp[y] = num_comp;
                q.push_back(y);
            }
        }
        num_comp++;
    }

    // cout << "components: " << num_comp << endl;

    if(D < num_comp || A[0].size() < D) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    deque<int> q1;
    vector<int> state1(N, 0);
    // otherwise author D edges from 1, making sure each component recieves an edge
    state1[0] = 1;
    for(int c=0;c!=num_comp; c++){
        cout << "1 " << hmm[c][0]+1 << endl;
        q1.push_back(hmm[c][0]);
        state1[hmm[c][0]] = 1;
    }
    for(int c=0; q1.size() != D && c!=num_comp; c++) {
        for(int i=1; q1.size() != D && i != hmm[c].size(); i++){
            cout << "1 " << hmm[c][i]+1 << endl;
            q1.push_back(hmm[c][i]);
            state1[hmm[c][i]] = 1;
        }
    }

    while(!q1.empty()) {
        int x = q1.front(); q1.pop_front();
        for(auto y: A[x]){
            if(state1[y] != 0) continue;
            cout << x+1 << " " << y+1 << endl;
            state1[y] = 1;
            q1.push_back(y);
        }
    }

    return 0;
}