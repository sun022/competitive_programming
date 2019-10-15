#include <bits/stdc++.h>

using namespace std;

int hcf(int a, int b){
    if(b==0) return a;
    return hcf(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), C(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<N;i++)
        cin >> C[i];

    unordered_map<int, int> m;
    m[0] = 0;

    for(int i=0;i<N;i++){
        unordered_map<int, int> m1 = m;
        for(auto [k, v] : m){
            int d = hcf(A[i], k);
            if(m1.count(d))
                m1[d] = min(m1[d], v + C[i]);
            else
                m1[d] = v + C[i];
        }
        m = m1;
    }

    // for(auto [k, v] : m){
    //     cerr << k << "\t" << v << endl;
    // }
    if(m.count(1)){
        cout << m[1] << endl;
    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}