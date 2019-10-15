#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64_t> S(N);
    for(int i=0;i<N;i++)
        cin >> S[i];
    
    sort(S.begin(), S.end());

    vector<int64_t> I(N-1);
    for(int i=0;i<N-1;i++)
        I[i] = S[i+1]-S[i];
    sort(I.begin(), I.end());

    // for(int i=0;i<N-1;i++){
    //     cout << I[i] << endl;
    // }

    vector<int64_t> I_sum(N,0); // I_sum[x] = sum of first x
    for(int i=1;i<N;i++){
        I_sum[i] = I_sum[i-1] + I[i-1];
    }

    int Q;
    cin >> Q;
    for(int q=1;q<=Q;q++){
        int64_t l,r;
        cin >> l >> r;
        int64_t d = r-l+1;
        // for intervals <d, they take their interval val
        // for intervals >=d, they reduced to d

        auto it = lower_bound(I.begin(), I.end(), d);
        // num <d IS (it - I.begin())
        int less_than = it - I.begin();
        //cout << less_than << " less than " << d << endl;
        // implies (N-1-less_than) >=d 
        int greater_than = N - less_than; // greater_than_OR_EQUAL

        int64_t ans = I_sum[less_than] + greater_than*d;
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}