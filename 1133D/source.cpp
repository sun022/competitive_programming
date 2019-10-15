#include <bits/stdc++.h>

using namespace std;

int hcf(int n1, int n2) {
    if (n2 != 0)
       return hcf(n2, n1 % n2);
    else 
       return n1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<N;i++)
        cin >> B[i];

    int auto_zero = 0;
    map<pair<int,int>, int> count;
    for(int i=0;i<N;i++){
        int a = A[i]; int b = B[i];
        if(a == 0) {
            auto_zero += (b == 0 ? 1 : 0);
            continue;
        }
        int d = hcf(a, b);
        a/=d; b/=d;
        if(a < 0) {
            a = -a; b = -b;
        }
        count[make_pair(a,b)]++;
    }

    int ret = 0;
    for(auto p : count){
        // cout << p.first.first << "," << p.first.second << ":" << p.second << endl;
        ret = max(ret, p.second);
    }

    cout << ret + auto_zero << endl;

    return 0;
}