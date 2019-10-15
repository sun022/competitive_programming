#include <bits/stdc++.h>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    map<string,int> m;
    map<string, int> count;
    vector<deque<pair<int,int>>> A(N);
    vector<int> num_tags(N); // num tags
    vector<bool> horiz(N);
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         A[i][j]=0;
    //     }
    // }

    for(int i=0;i<N;i++){
        char c;
        int M;
        cin >> c >> M;
        horiz[i] = (c == 'H');
        num_tags[i] = M;
        for(int j=0;j<M;j++){
            string s;
            cin >> s;
            if(m.count(s) == 0){
                m[s] = i;
            }
            else {
                {
                    auto it = A[i].begin();
                    while(it!=A[i].end() && it->first != m[s]) it++;
                    if(it == A[i].end())
                        A[i].push_back({m[s],1});
                    else
                        it->second++;
                }
                {
                    auto it = A[m[s]].begin();
                    while(it!=A[m[s]].end() && it->first != i) it++;
                    if(it == A[m[s]].end())
                        A[m[s]].push_back({i,1});
                    else
                        it->second++;
                }
                
                // if(A[m[s]].size() == 0 || A[m[s]].back().first != i)
                //     A[m[s]].push_back({i,1});                
                // else
                //     A[m[s]].back().second++;
                
                //A[m[s]].push_back(i);
                // if(m[s] == 1 || i == 1){
                //      cout << "both " << m[s] << " and " << i << " have tag " << s << endl;
                // }
            }
            count[s]++;
            if(count[s] > 2) {
                cout << "WARNING: count[" << s << "]=" << count[s] << endl;
                exit(0);
            }
        }
    }

    // cout << "!" << endl;
    // for(int i=0;i<10;i++){
    //     cout << i << " " << num_tags[i] << endl;
    //     for(auto x: A[i])
    //         cout << x.first << "(" << x.second << ") ";
    //     cout << endl;
    // }

    cerr << "begin preprocess" << endl;
    for(int i=0;i<N;i++){
        // cout << i << " " << num_tags[i] << endl;
        for(auto &x: A[i]){
            x.second = min(x.second, min(num_tags[i] - x.second, num_tags[x.first] - x.second));
            if(x.second <= 0)
                cerr << "!!" << endl;
            if(x.second != 3)
                cerr << x.second << endl;
            //cout << x.first << "(" << x.second << ") ";
        }
        //cout << endl;
        sort(A[i].begin(), A[i].end(), [](auto a, auto b){return a.first < b.first;});
    }
    // exit(0);
    cerr << "begin greedy" << endl;
    // GREED
    int64_t score = 0;
    vector<bool> used(N, false);
    int num_used = 0;
    int next_start = 0;
    int x = 0;

    vector<int> soln;
    while(true) {
        used[x] = true;
        num_used++;
        soln.push_back(x);
        // if(num_used == 20) break;

        // remove x from A[i] for each i
        for(auto it = A[x].begin();it!=A[x].end();it++) {
            int removed = 0;
            for(auto it1 = A[it->first].begin(); it1 != A[it->first].end();){
                if(it1->first == x){
                    it1 = A[it->first].erase(it1);
                    removed++;
                }
                else it1++;
                
            }
            if(removed != 1)
                cerr << "?" << endl;
        }

        int best = -1;
        int best_val = INT_MAX;
        for(auto p : A[x]){
            if(A[p.first].size() < best_val){
                best = p.first;
                best_val = A[p.first].size();
            }
        }
        
        A[x].clear();
        if(best == -1){
            while(next_start != N && used[next_start])
                next_start++;
            if(next_start == N)
                break;
            x = next_start;
        }
        else {
            int y = best;
            score += 3;
            x = y;
        }
    }
    cerr << "USED:" << num_used << endl;
    cerr << "SCORE:" << score << endl;



    cout << soln.size() << endl;
    for(auto x:soln){
        cout << x << endl;
    }

    // for(auto p : m){
    //     if(count[p.second] >= 2)
    //     cout << p.second << "\t" << p.first << "\t" << count[p.second] << endl;
    // }

    return 0;
}