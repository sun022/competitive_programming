#include <bits/stdc++.h>

using namespace std;

int64_t p(int x){
    if(x == 0) return 1;
    return (x%10)*p(x/10);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A;
    while(N!=0){
        int d = N%10; N/=10;
        A.push_back(d);
    }

    int64_t ret = 1;
    for(int s = 0;s<=A.size();s++) {
        int64_t prod = 1;
        int x=0;
        int n=0;
        int pow=1;
        for(int i=0;i<A.size();i++){
            
            int d = (i < s) ? 9 : A[i];
            if(i == s) {
                if(x > n && d != 0){
                    d--;
                }
            }
            n = n + pow*A[i];
            x = x + pow*d;
            prod *= d;

            pow*=10;
        }
        if(x <= n){
            int64_t pr = p(x);
            //cout << x << "\t" << p(x) << endl;
            ret = max(pr, ret);
        }
    }

    cout << ret << endl;

    return 0;
}