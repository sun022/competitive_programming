#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Z;
    cin >> N >> Z;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    vector<int> firstMatch(N, -1); // forward
    int j=0;
    for(int i=0;i<N;i++){
        while(j!=N && A[j] - A[i] < Z) j++;
        if(j==N) break;
        firstMatch[i] = j;
    }

    int m = INT_MAX;
    int i;
    for(i=0;i<N/2;i++){
        if(firstMatch[i] == -1) break;
        if(i+1 > m) break;

        m = min(m, N - firstMatch[i] + i);
        //cout << firstMatch[i] << " " << m << endl;
        //cout << N - firstMatch[i] + i << endl;
    }
    cout << i << endl;

    return 0;
}