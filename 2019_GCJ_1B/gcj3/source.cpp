#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int N,K;
        cin >> N >> K;
        vector<int> A(N), B(N);

        for(int i=0;i<N;i++) cin >> A[i];
        for(int i=0;i<N;i++) cin >> B[i];

        int64_t ret=0;
        // index for bestA[i][j] is interval i to j incl.
        vector<vector<int>> bestA(N, vector<int>(N)); 
        vector<vector<int>> bestB(N, vector<int>(N));
        for(int i=0;i<N;i++){            
            for(int j=i;j<N;j++){
                if(i==j){
                    bestA[i][i] = A[i];
                    bestB[i][i] = B[i];
                }
                else {
                    bestA[i][j] = max(bestA[i][j-1], A[j]);
                    bestB[i][j] = max(bestB[i][j-1], B[j]);
                }
                //cout << i << "," << j << ":" << bestA[i][j] << endl;
                if(abs(bestA[i][j] - bestB[i][j]) <= K)
                    ret++;
            }
        }
        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;
}