#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> D(N);
    for(int i=0;i<N;i++)
        cin >> D[i];

    vector<int> z(N);
    iota(z.begin(), z.end(), 0);
    sort(z.begin(), z.end(), [&D](int i, int j){return D[i]>D[j];});

    vector<int> depth(3*N, -1); // give me node at depth i
    

    

    vector<int> label(2*N, -1);
    vector<int> par(2*N);
    // keep first n nodes 'reserved' for path start points
    for(int i=0;i<N;i++){
        depth[i] = i;
        par[i] = i-1;
    }

    for(int i=0;i<N;i++){
        label[i] = 2*z[i];
        int d = D[z[i]]; // 1 to N

        int y = depth[d+i-1]; // par for new node
        par[N+i] = y;
        label[N+i] = 2*z[i] + 1;

        if(depth[d+i] == -1)
            depth[d+i] = N+i;
    }

    for(int i=1;i<2*N;i++)
        cout << label[i]+1 << " " << label[par[i]]+1 << endl;

    return 0;
}