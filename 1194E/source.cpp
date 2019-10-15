#include <bits/stdc++.h>

using namespace std;

class X {
    vector<int> h;
    const int size = 10001;
    
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
    X(){
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
    vector<tuple<int,int,int, int>> e;


    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(!(x1 < x2)) swap(x1, x2);
        if(!(y1 < y2)) swap(y1, y2);

        if(x1 == x2)
            e.push_back({x1, 0, y1, y2}); // vert       
        else { // horiz
        
            e.push_back({x1, 1, y1, x2}); // line start
            e.push_back({x2, 2, y1, x1}); // line finish
        }
    }

    sort(e.begin(), e.end());

    // for(auto [x, type, y, y1] : e){
    //     if(type == 0) cout << "VERT\t" << x << " [" << y << "," << y1 << "]" << endl;
    //     if(type == 1) cout << "OPEN\t" << x << " " << y << endl;
    //     if(type == 2) cout << "CLOSE\t" << x << " " << y << endl;        
    // }

    int64_t total = 0;
    for(auto [x_o, type_o, y_o, y1_o] : e){
        if(!(type_o == 0)) continue;
        // cout << "OUTER:" << x_o << endl;
        X hit;
        for(auto [x, type, y, o] : e) {
            if(type == 1 || type == 2){
                // only care if it crosses vert line from outer loop
                if(min(x, o) <= x_o && max(x, o) >= x_o && y_o <= y && y <= y1_o) {
                    hit.add(5000+y, (type == 1 ? 1 : -1));
                    //cout << "hit[" << y << "] = " << hit[5000+y] << endl;
                }
            }
            else if(type == 0 && x > x_o) {
                int64_t sum = hit.sum_interval(5000+max(y_o, y), 5000+min(y1_o, o) + 1);
                // cout << "\t" << x << " " << sum << endl;
                total += sum * (sum - 1) / 2;
            }
        }

    }
    cout << total << endl;

    return 0;
}