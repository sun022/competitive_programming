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

    vector<int> count(200001);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            count[A[i]+A[j]]++;
        }
    }

    int ret = 0;
    for(int i=0;i<count.size(); i++){
        ret = max(ret, count[i]);
        //if(count[i] != 0)
        //    cout << i << ":" << count[i] << endl;

    }

    cout << ret << endl;

    return 0;
}