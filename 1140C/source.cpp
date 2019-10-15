#include <bits/stdc++.h>

using namespace std;

struct Song {
    int t,b;
    Song(int t,int b):t(t),b(b){};
    Song(){};
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<Song> X(N);
    for(int i=0;i<N;i++){
        int t,b;
        cin >> t >> b;
        X[i] = Song(t,b);
    }

    sort(X.begin(), X.end(), [](auto i,auto j){return i.t > j.t || (i.t == j.t && i.b > j.b);});

    // cout << "X:" << endl;
    // for(int i=0;i<N;i++)
    //     cout << X[i].t << "\t" << X[i].b << endl;
    // cout << endl;

    int c=0;
    auto cmp = [](Song x, Song y) { return x.b > y.b || (x.b == y.b && x.t > y.t);};
    std::priority_queue<Song, vector<Song>, decltype(cmp)> q(cmp);
    
    int64_t cur_time = 0;
    while(q.size() != K){
        cur_time += X[c].t;
        q.push(X[c]);
        c++;
    }
    
    int64_t best = 0;
    while(q.size() != 0){
        auto x = q.top();
        int min_beauty = x.b;
        //cout << "score: " << min_beauty*cur_time << " = " << min_beauty << " * " << cur_time << endl;
        best = max(best, min_beauty*cur_time);

        // rm
        q.pop();
        cur_time -= x.t;
        //cout << x.t << "\t" << x.b << endl;

        // add
        if(c != N){
            q.push(X[c]);
            cur_time += X[c].t;
            c++;
        }
    }
    cout << best << endl;

    return 0;
}