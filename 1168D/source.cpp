#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K;
    cin >> K;
    int N = 1 << K;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> out1(N,0);
    vector<int> out2(N,0);
    for(int c=0;c<K;c++){ // consider only bit c
        
        for(int i=0;i<N;i++){
            bool b = (A[i] >> c)&1;
            bool X = next[b];
            bool Y = X^b;
            out1[i] += X << c;
            out2[i] += Y << c;
            next[b] = !next[b];
        }
        if(next[0] == 1 || next[1] == 1){
            cout << "Fou" << endl;
            return 0;
        }
    }

    cout << "Shi" << endl;
    for(int i=0;i<N;i++)
        cout << out1[i] << " ";
    cout << endl;
    for(int i=0;i<N;i++)
        cout << out2[i] << " ";
    cout << endl;

    return 0;
}