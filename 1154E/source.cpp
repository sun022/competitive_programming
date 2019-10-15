#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        A[i]--;
    }

    vector<int> z(N);
    for(int i=0;i<N;i++){
        z[A[i]] = i;
    }

    vector<int> team(N, -1);
    vector<int> left(N, -1), right(N, -1);
    for(int i=0;i<N;i++){
        left[i] = i-1;
        right[i] = i+1;
    }
    left[0] = -1;
    right[N-1] = -1;

    int pick=1;
    for(int c=N-1;c>=0;c--){
        int top = z[c];
        if(team[top] != -1) continue;
        vector<int> rm;
        // cout << top << endl;
        rm.push_back(top);
        int pl = left[top];        
        for(int k=0;k<K;k++){
            if(pl == -1) break;            
            rm.push_back(pl);

            pl = left[pl];
        }
        pl = right[top];
        for(int k=0;k<K;k++){
            if(pl == -1) break;
            rm.push_back(pl);

            pl = right[pl];
        }

        for(auto x : rm){
            // cout << x << "=" << pick << endl;
            team[x] = pick;
            int l = left[x];
            int r = right[x];
            if(l != -1)
                right[l] = r;
            if(r != -1)
                left[r] = l;
        }
        pick = pick == 1 ? 2 : 1;
    }
    for(auto x : team){
        cout << x;
    }
    cout << endl;

    return 0;
}