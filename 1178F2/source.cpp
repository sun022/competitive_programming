#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i]; A[i]--;
    }

    vector<int> min_pos(N, M);
    vector<int> max_pos(N, -1);
    for(int i=0;i<N;i++){
        min_pos[A[i]] = min(min_pos[A[i]], i);
        max_pos[A[i]] = max(max_pos[A[i]], i + 1);
    }
    // for(int c=0;c<N;c++){
    //     cout << c << ":\t" << min_pos[c] << "," << max_pos[c] << endl;
    // }

    vector<int> L_par(N, -1);
    vector<int> R_par(N, -1);
    // need to know maximum interval for colour i
    vector<pair<int,int>> interval(N);

    map<int, int> marker;
    set<int> b;
    b.insert(0);
    b.insert(M);
    marker[0] = -1; marker[M] = -1;
    for(int c=0;c<N;c++){ 
        auto it = b.lower_bound(max_pos[c]);
        int R = *it;
        int L = *(--it);
        cout << c << "\t" << L << "-" << R << endl;
        interval[c] = {L,R};
        int par = max(marker[L], marker[R]);
        if(par != -1 && par == marker[R])
            L_par[par] = c;
        if(par != -1 && par == marker[L])
            R_par[par] = c;

        marker[min_pos[c]] = c;
        marker[max_pos[c]] = c;
        b.insert(max_pos[c]);
        b.insert(min_pos[c]);
    }
    cout << endl;

    for(int c=0;c<N;c++){
        cout << c+1 << "\t" <<  L_par[c]+1 << " " << R_par[c]+1 << endl;
    }
    cout << endl;

    vector<vector<int64_t>> X(N); // X[c][3] is the no of ways to colour interval owned by c with base size 3
    for(int c=N-1;c>=0;c--){

        cout << "C:" << c << endl;
        // need no. of ways to colour L_par[c]'s interval
        vector<int64_t> left = (L_par[c] == -1) ? vector<int64_t>{1} : X[L_par[c]];
        vector<int64_t> right = (R_par[c] == -1) ? vector<int64_t>{1} : X[R_par[c]];
    
        int maxL = left.size()-1;
        int maxR = right.size()-1;
        X[c] = vector<int64_t>(maxL + maxR + 2, 0);
        for(int i=0;i<=maxL;i++){
            for(int j=0;j<=maxR;j++){
                if(left[i] == 0 || right[j] == 0) continue;
                //cout << i << " " << j << "\t" << left[i] << " "<< right[j] << endl;
                // i available on L, j available on R, 1 available on middle
                for(int k=1;k<=i+j+1;k++){
                    X[c][k] += left[i]*right[j];
                    //cout << "X[c][" << k << "]=" <<   X[c][k] << endl;                
                }                
            }
        }
        for(auto x : X[c])
            x %= 998244353;

        for(int i=0;i<X[c].size();i++)
            cout << X[c][i] << " ";
        cout << endl;
    }

    return 0;
}