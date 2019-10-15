#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> group(M);
    for(int m=0;m<M;m++){
        int k;
        cin >> k;
        group[m] = vector<int>(k);
        for(int i=0;i<k;i++){
            cin >> group[m][i];
            group[m][i]--;
        }
    }

    // iterate through the friendships, operating a 'merge' when nescessary
    vector<int> L(N);
    iota(L.begin(), L.end(), 0);

    vector<vector<int>> members;
    for(int i=0;i<N;i++)
        members.push_back(vector<int>(1, i));

    for(int m=0;m<M;m++){
        for(int i=1;i<group[m].size();i++){
            // merge group[m][0] and group[m][i]
            int x = group[m][0];
            int y = group[m][i];

            int Lx = L[x];
            int Ly = L[y];
            if(Lx == Ly) continue;

            // merge Lx into Ly
            if(members[Lx].size() > members[Ly].size()){
                swap(x,y);
                swap(Lx,Ly);
            }
            for(auto z : members[Lx]){
                members[Ly].push_back(z);
                L[z] = Ly;
            }
            members[Lx].clear();
        }
    }

    for(int i=0;i<N;i++){
        cout << members[L[i]].size() << " ";
    }
    cout << endl;

    return 0;
}