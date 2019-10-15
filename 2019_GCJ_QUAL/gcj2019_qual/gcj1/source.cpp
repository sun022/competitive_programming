#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        cin >> N;
        int A=0,B=0;
        int pow = 1;
        while(N!=0){
            int d = N%10; N/=10;
            if(d==4){
                A += 3*pow;
                B += 1*pow;
            }
            else {
                A += d*pow;
            }

            pow*=10;
        }
        cout << "Case #" << t << ": " << A << " " << B << endl;
    }

    return 0;
}