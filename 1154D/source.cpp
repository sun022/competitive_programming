#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, B, A;
    cin >> N >> B >> A;
    vector<int> S(N);
    for(int i=0;i<N;i++)
        cin >> S[i];

    int A_cap = A;
    int B_cap = B;

    int d=0;
    while(!((A==0 && B==0) || d==N)){
        //cout << A << " " << B << endl;
        // if a transfer would take place (ie lit and not full)
        // then use B, OTHERWISE use A
        int use = -1; // 0 = A, 1 = B
        if(A == 0)
            use = 1;        
        if(B==0)
            use = 0;
        if(A == A_cap)
            use = 0;

        if(use == -1){
            if(S[d])
                use = 1;
            else
                use = 0;
        }

        if(use == 0){ // A
            A--;
        }
        else {
            B--;
            if(S[d] && A!=A_cap)
                A++;
        }
        d++;
    }
    cout << d << endl;

    return 0;
}