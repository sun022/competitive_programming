#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
int N;

void f(int i, int j, int k){
    if(i < 0 || i >= N) return;
    if(j < 0 || j >= N) return;
    if(A[i][j] == 0) return;
    if(A[i][j] == k) return;
    A[i][j] = k;
    f(i-1,j, k);
    f(i+1,j, k);
    f(i,j+1, k);
    f(i,j-1, k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int r1,c1;
    int r2,c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    r1--;c1--;r2--;c2--;

    A = vector<vector<int>>(N, vector<int>(N, 0));
    for(int i=0;i<N;i++){ // row
        string s;
        cin >> s;
        for(int j=0;j<N;j++){ // col
            char c = s[j];
            if(c == '0')
                A[i][j] = 1;
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    f(r1, c1, 2);
    f(r2, c2, 3);

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if(A[r1][c1] == A[r2][c2]){
        cout << "0" << endl;
        return 0;
    }

    vector<pair<int, int>> X,Y;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[r1][c1] == A[i][j])
                X.push_back({i, j});
            else if(A[r2][c2] == A[i][j])
                Y.push_back({i, j});
        }
    }

    int best = INT_MAX;
    for(const auto &p1 : X){
        for(const auto &p2 : Y){
            best = min(best,
                abs(p1.first-p2.first)*abs(p1.first-p2.first)
                + abs(p1.second-p2.second)*abs(p1.second-p2.second)
            );
        }
    }
    cout << best << endl;

    return 0;
}