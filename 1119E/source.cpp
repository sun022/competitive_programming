#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int64_t> A_sum(N+1,0);
    for(int i=1;i<N+1;i++)
        A_sum[i] = A_sum[i-1] + A[i-1];

    int64_t tot = 0;
    int c=N-1;
    int64_t debt=0;
    while(c >= 0) {
        // if anymore triangles would go over in debt, then stop
        int64_t max_new = (A_sum[c] + A[c] - debt)/3;
        if (max_new <= 0)
            break;

        int64_t max_from_c = A[c]/2;
        if(A[c] >= 2) {
            int64_t k = min(max_new, max_from_c); // garunteed >=1
            tot += k;
            A[c] -= 2*k;
            debt += k;
        }
        else if(A[c] == 1) {
            if(debt > 0){
                debt--;
                A[c]--;
            }
            c--;
        }
        else {
            c--;
        }
    }
    cout << tot << endl;

    return 0;
}