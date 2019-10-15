#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, K, N, S;
    cin >> M >> K >> N >> S;

    vector<vector<int>> flower(500001);
    vector<int> A(M);
    for(int i=0;i<M;i++){
        cin >> A[i];
        flower[A[i]].push_back(i);
    }

    map<int,int> schem;
    vector<int> B(S);
    for(int i=0;i<S;i++){
        cin >> B[i];
        schem[B[i]]++;
    }

    // for(int x = 0; x < M; x += K){
    //     cout << "X:" << x << endl;
    //     // find how far forward we must go (FROM X) before obtaining all pieces in schematic
    //     for(auto p : schem){
    //         int f = p.first;
    //         int num = p.second;

    //         // look for flower f from x onwards
    //         cout << "looking for  flower " << f << " x" << num << " from " << x << " onwards "<< endl;
    //         for(auto t : flower[f]){
    //             cout << t << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    vector<int> block_score(M/K, 0);
    for(auto p : schem){
        int f = p.first;
        int num = p.second;
        int block = 0;
        //cout << "flower " << f << " x" << num << endl;
        deque<int> f_t;
        for(auto t : flower[f]){
            f_t.push_back(t);
            if(f_t.size() > num) {
                f_t.pop_front();
            }
            if(f_t.size() == num){
                int front_t = f_t.front();
                while(block*K <= front_t){
                    // cout << "block " << block << " costs at least " << (t-block*K) << endl;
                    block_score[block] = max(block_score[block], 1+t-block*K);
                    block++;
                }
            }
        }
        while(block < M/K){
            block_score[block] = INT_MAX;
            block++;
        }
    }

    int min_max = INT_MAX;
    int best_block = -1;
    for(int block=0;block<M/K;block++){
        if(block_score[block] < min_max){
            min_max = block_score[block];
            best_block = block;
        }
    }

    // cout << "min_max:" << min_max << endl;
    // cout << "best_block" << best_block << endl;
    if(min_max - K <= 0){
        cout << "0" << endl;
    }
    else if(min_max - K <= M - N*K){
        cout << min_max - K << endl;
        int del = min_max - K;
        // start from `best_block` and delete all that isn't 'good'

        for(int i=best_block*K; del != 0;i++){
            //cout << "A[" << i << "]=" << A[i] << endl;
            //cout << A[i] << "=" << schem[A[i]] << endl;
            if(schem[A[i]] > 0){
                schem[A[i]]--;
            }
            else {
                // cout << i << " (" << A[i] << ") ";
                cout << i+1 << " ";
                del--;
            }
        }
        cout << endl;
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}