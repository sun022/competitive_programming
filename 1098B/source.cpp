#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N >> M;
    cin >> N >> M;
    vector<string> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<vec> count(N, 

    vector<vector<vector<bool>>> dp_poss(N, vector<vector<bool>>(4, vector<bool>(4,0)));
    vector<vector<vector<int>>> dp_cost(N, vector<vector<int>>(4, vector<int>(4,0)));

    for(int c1=0;c1<4;c1++)
        for(int c2=0;c2<4;c2++)
            dp_poss[0][c1][c2] = (c1 != c2);
    
    for(int i=0;i<N;i++){
        

    }

    return 0;
}