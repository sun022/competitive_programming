#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> M(N, vector<int>(N,0));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> M[i][j];
    
    int64_t x = (int64_t)M[0][1]*M[0][2]/M[1][2]; // a[0]^2
    x = sqrt(x);

    for(int i=0;i<N;i++){
        if(i == 0){
            cout << x << " ";
        }
        else {
            cout << M[0][i]/x << " ";
        }

    }
    cout << endl;


    return 0;
}