#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, H;
    cin >> N >> H;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> z(N);
    iota(z.begin(), z.end(), 0);
    sort(z.begin(), z.end(), [&A](int i, int j){return A[i]>A[j];});

    for(int k=1;k<=N;k++){
        // try fit first k bottles
        int req=0;
        int count=0;
        for(int i=0;i<N;i++){
            if(z[i]>=k) continue;
            if(count%2 == 0)
                req += A[z[i]];
            count++;
        }
        if(req > H){
            cout << k-1 << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}