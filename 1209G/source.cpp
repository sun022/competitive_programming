#include <bits/stdc++.h>

using namespace std;

int K = 200000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i]; A[i]--;
    }

    vector<int> start(K, N); // index of first occ
    vector<int> finish(K, -1); // index of last occ

    vector<int> recol(K);
    iota(recol.begin(), recol.end(),0);

    for(int i=0;i<N;i++){
        start[A[i]] = min(start[A[i]], i);
        finish[A[i]] = max(finish[A[i]], i);
    }


    // for(int i=0;i<200000;i++){
    //     if(start[i] != N)
    //         cout << i << ":\t" << start[i] << " " << finish[i] << endl;
    // }
    vector<pair<int,int>> interval;
    int i=0;
    int s;
    int f;
    while(i != N){    
        s = i;
        f = finish[A[i]];
        //cout << "START" << i << endl;
        // int c = recol[A[i]];

        while(i != f){
            f = max(f, finish[A[i]]);
            i++;
        }
        //cout << "END" << i << endl;
        interval.push_back({s, i});

        i++;
    }

    int diff = 0;
    for(auto [a,b] : interval){
        // find most common in this interval
        map<int,int> count;
        for(int i=a;i<=b;i++){
            if(count.count(A[i]) == 0) count[A[i]] = 0;
            count[A[i]]++;
        }
        int max = 0;
        for(auto [k,v] : count)
            max = std::max(max, v);
        diff += (b-a+1) - max;
    }
    cout << diff << endl;

    return 0;
}