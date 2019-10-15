#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M, K;
    cin >> N >> M >> K;
    K++;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    std::partial_sort(A.begin(), A.begin() + 2, A.end(), std::greater<int64_t>());
    
    int64_t m1 = A[0];
    int64_t m2 = A[1];

    int64_t ans = (int64_t)(M/K)*((K-1)*m1 + m2) + (int64_t)(M%K)*m1;
    cout << ans << endl;

    return 0;
}