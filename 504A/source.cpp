#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> d(N), s(N);
    for(int i=0;i<N;i++)
        cin >> d[i] >> s[i];

    vector<pair<int,int>> edges;

    // mantain a list of vertices on 1 edge
    queue<int> q;
    for(int i=0;i<N;i++)
        if(d[i] == 1)
            q.push(i);

    while(!q.empty()){
        int x = q.front(); q.pop();
        if(d[x] != 1){
            continue;
        }

        int y = s[x];
        edges.push_back({x,y});
        d[y]--;
        s[y] ^= x;
        d[x]--;
        d[x] ^= y;

        if(d[y] == 1) q.push(y);
    }

    cout << edges.size() << endl;
    for(auto [x,y] : edges){
        cout << x << " " << y << endl;
    }

    return 0;
}