#include <bits/stdc++.h>

using namespace std;

bool isPrime(int N){
    for(int n=2;n<N;n++)
        if(N%n == 0)
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int M = N;
    while(!isPrime(M)) M++;

    cout << M << endl;
    for(int i = 0;i<N;i++){
        cout << i+1 << " " << (i+1)%N + 1 << endl;
    }

    int req = M-N;
    for(int i=0; req!=0; i++){
        if(i % 4 == 0 || i % 4 == 1){
            cout << i+1 << " " << (i+2)%N + 1 << endl;
            req--;
        }
    }


    return 0;
}