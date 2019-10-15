#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    int64_t K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    int64_t ret = 0;
    for(int m = 0; m < M; m++){
        int64_t x = 0;
        int tmr = 0;
        for(int i=m;i<N;i++){
            if(tmr == 0){
                x = max((int64_t)0, x) + A[i] - K;
                tmr = M;
            }
            else
                x += A[i];
            tmr--;
            ret = max(x, ret);
        }
    }
    cout << ret << endl;

    return 0;
}