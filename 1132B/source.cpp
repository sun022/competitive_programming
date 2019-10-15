#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t sum=0;
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
    }

    int M;
    cin >> M;
    vector<int> Q(M);
    for(int i=0;i<M;i++)
        cin >> Q[i];

    sort(A.begin(), A.end(), greater<int>());

    for(int i=0;i<M;i++){
        cout << sum - A[Q[i]-1] << endl;
    }    

    return 0;
}