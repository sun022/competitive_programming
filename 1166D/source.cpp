#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    for(int q=1;q<=Q;q++) {
        int64_t a,b,m;
        cin >> a >> b >> m;
        
        if(a == b){
            cout << "1 " << a << endl;
            continue;
        }

        int64_t pow=1;
        bool solved=false;
        for(int k=2;k<=50;k++){
            vector<int64_t> r_arr;
            r_arr.push_back(a);
            int64_t start = a*pow + pow;
            int64_t rem = b - start;
            if(rem < 0) break;
            // cout << "k=" << k << " " << start << " " << rem << endl;

            // now reduce pow to 1 and subtract big as element as possible (greedy)
            for(int64_t pow2 = pow/2; pow2 >= 1; pow2/=2) {
                // cout << pow2 << endl;
                int64_t r = min(rem/pow2, m-1);
                r_arr.push_back(r+1);
                rem -= r*pow2;
            }

            if(rem <= m-1){
                r_arr.push_back(rem+1);
                // cout << "!" << " ";
                // for(auto x : r_arr)
                //     cout << x << " ";
                // cout << endl;

                cout << k << " ";
                int64_t x_sum=0;
                for(int j = 1; j <= k; j++){
                    int64_t x_j = x_sum + r_arr[j-1];
                    cout << x_j << " ";
                    x_sum += x_j;
                }
                cout << endl;
                solved = true;
                break;
            }

            pow*=2;
        }
        if(!solved){
            cout << "-1" << endl;
        }
    }

    return 0;
}