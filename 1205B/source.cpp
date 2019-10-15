#include <bits/stdc++.h>

using namespace std;

const int Z = 64;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64_t> A(N);

    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<vector<int>> x(Z);

    for(int i=0;i<N;i++){
        int a=0;
        int64_t x1 = A[i];
        while(x1 != 0){
            if(x1 & 1)
                x[a].push_back(i);
            x1/=2;
            a++;
        }
    }

    int largest_group = 0;
    for(int a=0;a<Z;a++){
        //if(x[a].size()!=0)
        //    cout << a << " "<< x[a].size() << endl;
        largest_group = max(largest_group, (int)x[a].size());
    }

    if(largest_group >= 3){
        cout << "3" << endl;
        return 0;
    } 

    // otherwise we have <= 60 connected elements and find shortest cycle
    
    // construct graph, (edgelist)

    int sz = 0;
    vector<int> id(N, -1);
    vector<vector<int>> v;
    for(int a=0;a<Z;a++){
        if(x[a].size() != 2) continue;
        int A = x[a][0]; int B = x[a][1];
        if(id[A] == -1){            
            id[A] = sz; sz++; v.emplace_back();
        }
        if(id[B] == -1){            
            id[B] = sz; sz++; v.emplace_back();
        }
        
        // no multiple edge between nodes
        bool present = false;
        for(auto y : v[id[A]])
            if(y == id[B])
                present = true;
        if(present) continue;

        v[id[A]].push_back(id[B]);
        v[id[B]].push_back(id[A]);                
    }

    // for(int i=0;i<sz;i++){
    //     cout << i << ":\t";
    //     for(auto y:v[i])
    //         cout << y;
    //     cout << endl;
    // }

    // remains to find shortest cycle in graph described by v of size sz
    // BFS from EVERY root
    int min_cycle = INT_MAX;
    for(int root = 0; root < sz; root++) {
        // cout << "root:" << root << endl;
        vector<int> state(sz, 0);
        vector<int> depth(sz, -1);
        vector<int> from(sz, -1);
        queue<int> q;
        q.push(root);
        depth[root] = 0;
        state[root] = 1;

        while(!q.empty()){
            int x = q.front(); q.pop();
            int d = depth[x];
            if(state[x] == 2) continue;
            // cout << x << ":" << d << endl;
            state[x] = 2;

            for(auto y : v[x]){
                if(from[x] == y) continue;
                if(state[y] != 0){ // ALREADY REACHED, so CYCLE
                    int len = depth[x] + depth[y] + 1;
                    if(len >= 3)
                        min_cycle = min(min_cycle, len);
                }
                if(state[y] == 0){
                    depth[y] = depth[x] + 1;
                    state[y] = 1;
                    from[y] = x;
                    q.push(y);
                }
            }
        }

    }
    if(min_cycle == INT_MAX)
        min_cycle = -1;
    cout << min_cycle << endl;


    return 0;
}