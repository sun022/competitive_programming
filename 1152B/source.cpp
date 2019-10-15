#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> X(20); // least sig bit first
    for(int i=0;i<20;i++){
        X[i] = N&1;
        N /= 2;
    }

    int t=0;
    vector<int> r;
    while(true){
        int i = 19;
        while(i!=-1 && X[i] == 0) i--;
        
        //for(int j=i;j>=0;j--)
        //    cout << X[j];        
        //cout << endl;

        while(i!=-1 && X[i] == 1) i--;
        if(i == -1) break; // finished

        if(t%2 == 0){
            // flip this bit (and everything below)
            r.push_back(i+1);
            for(;i>=0;i--)
                X[i] = 1-X[i];
        }
        else {
            int i=0;
            while(X[i] == 1){
                X[i] = 0;
                i++;
            }
            X[i] = 1;
        }

        t++;
    }
    cout << t << endl;
    for(auto x : r){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}