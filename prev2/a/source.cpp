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

    int m = -1;
    for(int i=0;i<N;i++)
        m = max(m, A[i]);
    
    int longest=0;
    for(int i=0;i<N;i++) {
        int size = 0;
        while(i<N && A[i] == m){
            size++;
            i++;
        }
        longest = max(size, longest);        
    }
    cout << longest << endl;

    return 0;
}