#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;

void f(int t){
    int N; cin >> N;
    vector<int> A(N), B(N);
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }

    for(int a = 1; a<=MAX;a++){
        for(int b=1; b<=MAX;b++){
            bool success=true;
            for(int i=0;i<N-1;i++){
                int64_t one = A[i]*a + B[i]*b;
                int64_t two = A[i+1]*a + B[i+1]*b;
                if(!(two > one)){
                    success = false;
                    break;
                }
            }
            if(success){
                cout << "Case #" << t << ": " << a << " " << b << endl;
                return;
            }
        }
    }
    cout << "Case #" << t << ": IMPOSSIBLE" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int t=1;t<=T;t++){
        f(t);
    }

    return 0;
}