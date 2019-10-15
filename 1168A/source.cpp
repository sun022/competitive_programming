#include <bits/stdc++.h>

using namespace std;

int N,M;

bool f(const vector<int> &A, int x){
    int prev=0;
    int A_i;
    for(int i=0;i<N;i++){
        // from A[i] to A[i] + x
        if(A[i] + x >= M) { // then always possible (set to M-1)
            if((A[i] + x) - M < prev) { // wrap around doesn't help
                A_i = max(A[i], prev);
            }
            else {
                A_i = prev; // ideal
            }
        }
        else {
            if(A[i] + x < prev)
                return false;
            A_i = max(A[i], prev);
        }

        prev = A_i;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    

    for(int i=0;i<M;i++){
        bool x = f(A, i);
        
    }

    // find the min x, st f(x) = true

    // binary search
    int a = 0;
    int b = M-1; // possible
    
    while(a != b){
        int m = (a+b)/2;
        bool f_m = f(A, m);
        // cout << m << ":" << (f_m ? "TRUE":"FALSE" )<< endl;
        if(f_m)
            b = m;
        else
            a = m + 1;        
    }
    cout << a << endl;

    return 0;
}