#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++)
        cin >> A[i] >> B[i];

    vector<int> desc;
    vector<int> asc;
    for(int i=0;i<N;i++){
        if(A[i] < B[i]) asc.push_back(i);
        else desc.push_back(i);        
    }

    sort(asc.begin(), asc.end(), [&B](int i,int j){return B[i] > B[j];});
    sort(desc.begin(), desc.end(), [&B](int i,int j){return B[i] < B[j];});

    if(asc.size() > desc.size()){
        cout << asc.size() << endl;
        for(auto x : asc)
            cout << x+1 << " ";
        cout << endl;
    }
    else {
        cout << desc.size() << endl;
        for(auto x : desc)
            cout << x+1 << " ";
        cout << endl;
    }

    return 0;
}