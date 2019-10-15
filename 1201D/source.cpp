#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    vector<pair<int,int>> goal;
    for(int i=0;i<K;i++){
        int r,c; cin >> r >> c; r--; c--;
        goal.push_back({r, c});
    }

    vector<int> safe(Q);
    for(int i=0;i<Q;i++){
        cin >> safe[i]; safe[i]--;
        // cerr << "safe:" << safe[i] << endl;
    }
    cerr << "input read" << endl;
    sort(safe.begin(), safe.end());

    vector<int> leftSafe(M, -1);
    vector<int> rightSafe(M, -1);

    int j=0; // need safe
    for(int i=0;i<Q;i++){
        while(j<=safe[i]){
            rightSafe[j] = safe[i];
            j++;
        }
    }
    cerr << "right safe computed" << endl;
    j = M-1;
    for(int i = Q-1; i>=0; i--){
        while(safe[i]<=j){
            leftSafe[j] = safe[i];
            j--;
        }
    }
    cerr << "left safe computed" << endl;
    sort(goal.begin(), goal.end());

    vector<int> pos = {0, 0};
    vector<int64_t> cost = {0, 0};
    for(int g = 0; g<goal.size();){
        int cur_row = goal[g].first;
        // cout << "cur_row:" << cur_row << endl;
        int min_col = INT_MAX;
        int max_col = 0;
        while(g!=goal.size() && goal[g].first == cur_row){
            min_col = min(min_col, goal[g].second);
            max_col = max(max_col, goal[g].second);
            g++;
        }
        // either: go to X then Y
        // or    : go to Y then X
        vector<int> pos_new = {min_col, max_col};
        vector<int64_t> cost_new = {LLONG_MAX, LLONG_MAX};
        for(int a=0;a<2;a++){
            for(int b=0;b<2;b++){
                if(cur_row == 0){ // no need for safe place
                    int64_t c = cost[a] + abs(pos[a] - pos_new[1-b]) + abs(pos_new[1-b] - pos_new[b]);
                    cost_new[b] = min(c, cost_new[b]);
                    continue;
                }
                // use left or right
                if(leftSafe[pos[a]] != -1){
                    int64_t c = cost[a] + abs(pos[a] - leftSafe[pos[a]]) + abs(leftSafe[pos[a]] - pos_new[1-b]) + abs(pos_new[1-b] - pos_new[b]);
                    cost_new[b] = min(c, cost_new[b]);
                }
                if(rightSafe[pos[a]] != -1){
                    int64_t c = cost[a] + abs(pos[a] - rightSafe[pos[a]]) + abs(rightSafe[pos[a]] - pos_new[1-b]) + abs(pos_new[1-b] - pos_new[b]);
                    cost_new[b] = min(c, cost_new[b]);
                }
            }            
        }
        pos = pos_new;
        cost = cost_new;
        // cout << pos[0] << " " << cost[0] << endl;
        // cout << pos[1] << " " << cost[1] << endl;
    }
    cout << min(cost[0], cost[1]) + goal[goal.size()-1].first << endl;

    return 0;
}