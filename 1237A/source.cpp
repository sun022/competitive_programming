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

    vector<int> B(N);

    int odd_no = 0;
    for(int i=0;i<N;i++){
        if((A[i]+10000) % 2 == 1){ 
            A[i] = (A[i] + 10000)/2 - 5000; // always down
            
            if(odd_no % 2 == 1)
                A[i]++;
        
            odd_no++;
        }
        else
            A[i]/=2;

        cout << A[i] << " ";        
    }
    cout << endl;

    return 0;
}