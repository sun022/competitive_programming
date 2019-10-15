#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(2*N);
    for(int i=0;i< N;i++){
        cin >> A[2*i + 1] >> A[2*i];
    }

    vector<int> in(2*N);
    iota(in.begin(), in.end(), 0);

    sort(in.begin(), in.end(), [&A](int i1, int i2){return A[i1] < A[i2] || (A[i1] == A[i2] && i1%2 > i2%2);}); // closures first    

    unordered_map<int, int64_t> dp_N(2*N); // no. nested subsets of meeting the value below
    unordered_map<int, int64_t> dp_V(2*N); // minimal air for dolls fitting within a space of A[i]

    dp_V[0] = 0;
    dp_N[0] = 1;

    int prev = 0;
    for(auto x : in){
        int Ax = A[x];        
        if(x%2 == 0 && prev != A[x]){ // open
            dp_V[A[x]] = dp_V[prev] + A[x] - prev;
            dp_N[A[x]] = dp_N[prev];
        }
        else if(x%2 == 1){ // close
            if(dp_V[prev] + A[x] - prev < dp_V[A[x-1]]){
                dp_V[A[x]] = dp_V[prev] + A[x] - prev;
                dp_N[A[x]] = dp_N[prev];
            }
            else if (dp_V[prev] + A[x] - prev > dp_V[A[x-1]]){
                dp_V[A[x]] = dp_V[A[x-1]];
                dp_N[A[x]] = dp_N[A[x-1]];
            }
            else { // same
                dp_V[A[x]] = dp_V[A[x-1]];
                dp_N[A[x]] = dp_N[prev] + dp_N[A[x-1]];
            }
        }
        dp_N[A[x]] %= MOD;
        //cout << "dp_V[" << A[x] << "] = " <<  dp_V[A[x]] << endl;
        //cout << "dp_N[" << A[x] << "] = " <<  dp_N[A[x]] << endl;
        prev = Ax;
    }

    
    int last_start = 0;
    for(int i=0;i< N;i++){
        last_start = max(last_start, A[2*i]);
    }

    int64_t min_air = LLONG_MAX;
    int64_t sum = 0;
    for(int i=0;i<N;i++){
        // consider maximal intervals (maybe non-unique)
        if(!(A[2*i + 1] > last_start)) continue;

        min_air = min(min_air, dp_V[A[2*i + 1]]);
    }

    for(int i=0;i<N;i++){
        if(!(A[2*i + 1] > last_start)) continue;
        if(dp_V[A[2*i]] == min_air){
            sum += dp_N[A[2*i]];
            sum %= MOD;
        }    
    }

    cout << sum << endl;

    return 0;
}