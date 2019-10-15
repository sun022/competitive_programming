#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N); // A[i] is vector of presents at i
    // where present is labeled with its destination

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b; a--; b--;
        A[a].push_back(b>=a ? b-a : N+b-a);
    }

    int maxLen = 0;
    for(int i=0;i<N;i++){
        sort(A[i].begin(), A[i].end(), greater<int>());
        // for(auto x : A[i])
        //     cout << x << " ";
        // cout << endl;
        maxLen = max(maxLen, (int)A[i].size());
    }

    int skip = maxLen - 2;
    if(skip < 0) skip = 0;
    // cout << "SKIP:" << skip << endl;

    for(int s=0;s<N;s++){
        int t = skip*N;
        vector<int> prog(N, 0);
        vector<int> cur(N,0);
        int fin = 0;
        for(int i=0;i<N;i++){
            int skipped = min(skip, (int)A[i].size());
            prog[i] = skipped;
            fin += skipped;
        }

        int x = s;
        while(true){
            if(prog[x] != A[x].size()){
                int dest = x + A[x][prog[x]];
                if (dest >= N) dest-=N;
                cur[dest]++;
                prog[x]++;
            }
            fin += cur[x];
            cur[x] = 0;
            if(fin == M)
                break;
            x++;
            if(x >= N) x-=N;
            t++;
        }
        cout << t << " ";
    }

    return 0;
}