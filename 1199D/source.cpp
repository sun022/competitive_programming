#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> last_receipt(N, 0);
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<tuple<int,int,int>> e;
    int Q; cin >> Q;
    for(int q=1;q<=Q;q++){
        int type; cin >> type;
        if(type == 1){
            int p,x; cin >> p >> x; p--;
            e.push_back({1,p,x});
        }
        else if(type == 2){
            int x; cin >> x;
            e.push_back({2,x,-1});
        }
    }
    reverse(e.begin(),e.end());

    vector<int> B(N, -1);
    // now iterate backwards through time, keeping track of the highest payout in [t, END]
    int highest_payout = 0;
    for(auto [type, a, b] : e){
        if(type == 2){
            highest_payout = max(highest_payout, a);
            continue;
        }        
        if(B[a] == -1)
            B[a] = max(highest_payout, b);        
    }

    for(int i=0;i<N;i++){
        if(B[i] == -1)
            B[i] = max(highest_payout, A[i]);
    }

    for(int i=0;i<N;i++)
        cout << B[i] << " ";
    cout << endl;

    return 0;
}