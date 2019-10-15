#include <bits/stdc++.h>

using namespace std;

class IT {
    vector<int> h;
    int size;
    
    void add_helper(int i, int val, int L, int R, int ind){
        // cout << "add_helper(" << i << "," << val << "," << L << "," << R << "," << ind << ")" << endl;
        if(!(L <= i && i < R)) return;
        h[ind] += val;

        if(L+1 == R) return;
        int M = L+(R-L)/2;
        add_helper(i, val, L, M , 2*ind + 1);
        add_helper(i, val, M, R, 2*ind + 2);
    }
    
    int sum_interval_helper(int i, int j, int L, int R, int ind){
        if(!(L < j && i < R)) return 0; // no intersection
        if(i <= L && R <= j) return h[ind]; // full contain
        int M = L+(R-L)/2;
        return sum_interval_helper(i, j, L, M, 2*ind + 1)
            + sum_interval_helper(i, j, M, R, 2*ind + 2);
    } 
public:
    IT(int size):size(size){
        h = vector<int>(4*size,0);
    }
    void add(int i, int val){
        return add_helper(i, val, 0, size, 0);
    }
    int sum_interval(int i, int j){
        if(!(i < j)) return 0;
        return sum_interval_helper(i, j, 0, size, 0);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    set<int> x_uniq;
    set<int> y_uniq;
    vector<pair<int,int>> p;
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        p.push_back({y,x});
        x_uniq.insert(x);
        y_uniq.insert(y);
    }
    
    map<int,int> x_map;
    map<int,int> y_map;
    int X=0, Y=0;
    for(auto x : x_uniq) x_map[x] = X++;
    for(auto y : y_uniq) y_map[y] = Y++;

    for(auto &[y,x] : p){
        x = x_map[x];
        y = y_map[y];
    }

    sort(p.begin(), p.end(), [](auto p1, auto p2){return p1.first>p2.first || (p1.first == p2.first && p1.second < p2.second);});

    int64_t total = 0;
    IT hit(X);
    vector<bool> status(X, false);
    for(int i=0;i<N;){
        int cur_y = p[i].first;
        vector<int> cur_x;
        while(i!=N && p[i].first == cur_y){
            cur_x.push_back(p[i].second);
            i++;
        }
        cur_x.push_back(X);

        // cout << "Y:" << cur_y << endl;
        int start = 0;
        for(auto x: cur_x){
            int64_t count = hit.sum_interval(start, x);
            total -= count * (count + 1) / 2;
            start = x+1;
        }

        for(auto x: cur_x){
            if(x == X) continue;
            if(!status[x]){
                status[x] = true;
                hit.add(x, 1);
            }
        }

        int64_t all_hits = hit.sum_interval(0, X);
        total += all_hits * (all_hits + 1) / 2;
    }
    cout << total << endl;

    return 0;
}