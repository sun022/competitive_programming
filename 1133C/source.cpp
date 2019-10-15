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
    sort(A.begin(), A.end());

    int i=0, j=0;
    int ret = 0;
    while(j != N) {
        if(A[j] - A[i] <= 5){
            ret = max(ret, j-i+1);
            j++;
        } else {
            i++;
        }
    }
    cout << ret << endl;

    return 0;
}