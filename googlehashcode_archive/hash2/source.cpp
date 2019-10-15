#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N;
    cin >> N;

    map<string,int> m;
    map<string, int> count;

    vector<vector<int>> tags(N);

    for(int i=0;i<N;i++){
        char c;
        int M;
        cin >> c >> M;
        for(int j=0;j<M;j++){
            string s;
            cin >> s;

            if(m.count(s) == 0){
                int tmp = m.size();
                m[s] = tmp;
            }

            tags[i].push_back(m[s]);
        }
    }

    vector<int> z(N);
    iota(z.begin(), z.end(),0);

    int full_score = 0;
    vector<int> score((N/2)-1); // score[0] is score from 01 to 23
    for(int i=0;i<score.size();i++){
        // cout << i << endl;
        set<int> A,B;
        for(auto x : tags[2*i])
            A.insert(x);
        for(auto x : tags[2*i + 1])
            A.insert(x);
        for(auto x : tags[2*i + 2])
            B.insert(x);        
        for(auto x : tags[2*i + 3])
            B.insert(x);
        
        vector<int> v(min(A.size(), B.size()));
        std::set_intersection (A.begin(), A.end(), B.begin(), B.end(), v.begin());

        score[i] = min(v.size(), min(A.size() - v.size(), B.size() - v.size()));
        full_score += score[i];
    }
    cout << "init_score:" << full_score << endl;
    
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0,score.size()-1);

    while(false){
        int a = dist(gen);
        int b = dist(gen);
        if(a == b) continue;
        
        // calculate score of swapping
    }

    return 0;
}