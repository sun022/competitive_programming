#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    // find minimum
    sort(A.begin(), A.end());
    int sum = 0;
    for(int i=0;i<A.size();i++)
        sum += A[i];
    int min = A[0];

    int best = 0;
    for(int i=1;i < A.size();i++){
        for(int x = 1; x<= 100; x++){
            if(A[i] % x == 0){
                int net = (-min + min*x) + (-A[i] + A[i]/x);
                best = std::min(best, net);
            }
        }

    }
    cout << sum + best << endl;

    return 0;
}