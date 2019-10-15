#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> A(M);
    for(int i=0;i<M;i++){
        int s; cin >> s;
        A[i] = vector<int>(s);
        for(int j=0;j<s;j++){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    // for every pair of partions A1+B1 AND A2+B2
    // A1 INTERSECT A2 = NON-EMPTY
    // AND A1 INTERSECT B2 = NON_EMPTY

    // OR...

    // A1 contained in A2

    // SUMMARY
    // A1 INTERSECT A2 NON-EMPTY
    vector<vector<int>> store(N);

    for(int i=0;i<M;i++){
        for(auto x : A[i]){
            store[x].push_back(i);
        }
    }

    vector<vector<bool>> day_pair(M, vector<bool>(M, false));

    for(int i=0;i<N;i++){
        // store[i] contains 50 numbers (max)
        for(int j=0;j<store[i].size();j++){
            for(int k=j; k<store[i].size();k++){
                int s1 = store[i][j];
                int s2 = store[i][k];
                day_pair[s1][s2] = true;
                day_pair[s2][s1] = true;
            }
        }
    }

    bool poss = true;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(!day_pair[i][j]) poss = false;
        }
    }
    cout << (poss ? "":"im") << "possible" << endl;

    return 0;
}