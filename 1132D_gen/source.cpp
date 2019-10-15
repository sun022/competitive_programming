#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N=200000;
    cout << N << " " << N << endl;
    for(int i=0;i<N;i++)
        cout << 100000000000ll << " ";
    for(int i=0;i<N/4;i++)
        cout << 5000000000ll + i << " ";
    for(int i=0;i<N/4;i++)
        cout << 3300000000ll + i << " ";
    for(int i=0;i<N/4;i++)
        cout << 2500000000ll + i << " ";
    for(int i=0;i<N/4;i++)
        cout << 4400000000ll + i << " ";
    cout << endl;
    return 0;
}