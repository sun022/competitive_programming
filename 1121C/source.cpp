#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> tester(K, -1);
    vector<int> tester_prog(K, 0);
    vector<int> status(N, 0);
    int queue = 0;
    int completed = 0;

    int t=0;
    while(true){
        for(int k=0;k<K;k++){
            if(tester[k] == -1 && queue != N){
                // cout << "starting soln" << queue << "(" << t << ")" << endl;
                tester[k] = queue;
                tester_prog[k]=0;
                queue++;

                int percent = round((double)100*completed/N);
                // cout << completed << "/" << N << "\t" << percent << "%" << endl;
            }
        }
        int percent = round((double)100*completed/N);
        for(int k=0;k<K;k++){
            if(tester[k] >= 0){
                // 
                if(percent == tester_prog[k]+1){
                    // cout << "soln" << tester[k] << " interesting" << endl;
                    // cout << "tester " << k << " running on " << tester[k] << "-" << tester_prog[k]+1 << endl;
                    status[tester[k]]=1;
                }

                if(tester[k] == 2 && tester_prog[k]+1 == 25){
                    // cout << "tester " << k << " running on " << tester[k] << "-" << tester_prog[k]+1 << endl;
                }

                tester_prog[k]++;
                if(tester_prog[k] == A[tester[k]]){
                    tester[k] = -1;
                    completed++;
                }
            }
        }
        if(completed == N)
            break;
        t++;
    }

    int ret=0;
    for(auto x : status){
        if(x)
            ret++;
    }
    cout << ret << endl;

    return 0;
}