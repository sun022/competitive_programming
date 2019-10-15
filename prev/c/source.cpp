#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)
        cin >> A[i];

    vector<int> x(N+1);
    x[0] = 0;
    for(int i=1;i<=N;i++)
        x[i] = x[i-1]^A[i];

    // for(int i=0;i<=N;i++)
    //     cout << x[i] << endl;

    vector<int> w(N+1);
    iota(w.begin(), w.end(), 0);

    sort(w.begin(), w.end(), [&x](int i,int j){return x[i] < x[j];});

    int z;
    int even = 0;
    int odd = 0;
    int64_t ans = 0;
    for(int i=0;i<=N;i++) {
        z = x[w[i]];
        if(w[i]%2 ==0)
            even++;
        else
            odd++;
        // if next is different OR end, then calculate for this interval

        if(i==N || x[w[i+1]]!=z) {
            // cout << z << " " << even << " " << odd << endl;
            ans += ((int64_t)odd*(odd-1))/2;
            ans += ((int64_t)even*(even-1))/2;
            even=0;
            odd=0;
        }
    }
    cout << ans << endl;

    return 0;
}