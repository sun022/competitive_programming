#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, M;
    cin >> N >> K >> M;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());

    vector<int64_t> S(N+1); // s[n] = sum of strongest n
    S[0] = 0;
    for(int i=0;i<N;i++)
        S[i+1] = S[i] + A[i];

    // sack n heros
    long double best = 0;
    for(int n=0; n <= min(N-1, M);n++){
        int64_t sum = S[N-n];
        int64_t actions = M - n;
        int64_t heros = N - n;
        int64_t extra = min(actions, heros*K);
        best = max(best, (long double)(sum + extra)/heros);
    }
    cout << setprecision (15) << best << endl;

    return 0;
}