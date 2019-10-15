#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());

    deque<int> x;

    for(int i=0;i<N;i++){
        if(i%2==0)
            x.push_back(A[i]);
        else
            x.push_front(A[i]);       
    }
    for(auto y : x){
        cout << y << " ";
    }
    cout << endl;
    return 0;
}