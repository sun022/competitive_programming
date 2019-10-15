#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, K;
    int M;
    cin >> N >> M >> K;

    vector<int64_t> A(M);
    for(int i=0;i<M;i++){
        cin >> A[i]; A[i]--;
    }

    sort(A.begin(), A.end());

    int op=0;
    int64_t rem = 0;
    for(int i=0;i<M;){
        //cout << A[i] << "-" << rem << " MOD " << K << endl;
        int64_t next = A[i] - rem;
        int64_t block = next / K;
        //cout << "block:" << block << endl;

        int t = 1;
        while(i+t !=M && (A[i+t] - rem) / K == block)
            t++;

        rem += t;
        i += t;
        op++;
        //cout << t << endl;
    }
    cout << op << endl;

    return 0;
}