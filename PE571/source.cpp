#include <bits/stdc++.h>

using namespace std;

int main(){    
    int B = 12;
    // cycle permutations of {0, 1, 2, ... N-1}

    vector<int> x(B);
    iota(x.begin(), x.end(), 0);

    int64_t sum = 0;
    int count = 0;
    do {
        if(x[0] == 0) continue;
        // for(int i=0;i<N;i++)
        //     cout << x[i];
        // cout << endl;

        int64_t X=0;
        for(int d : x)
            X = B*X + d;
        // cout << X << endl;

        int b=B-1;
        for(;b>=2;b--){
            vector<int> hit(b, false);
            int64_t X1 = X;
            while(X1 != 0){
                hit[X1 % b] = true;
                X1 /= b;
            }
            bool hit_all = accumulate(hit.begin(), hit.end(), true, [](bool x, bool y){return x&&y;});
            if(!hit_all) break;
        }
        if(b == 1){
            cout << X << endl;
            sum += X;
            count++;
        }

        
    } while(count!=10 && next_permutation(x.begin(), x.end()));
    cout << "sum:\t" << sum  << endl;

    return 0;
}