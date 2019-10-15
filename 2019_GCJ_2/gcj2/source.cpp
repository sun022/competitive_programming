#include <bits/stdc++.h>

using namespace std;

// sim time
int sim_day;

int get_sim_day(){
    sim_day++;
    return sim_day;
}

void apply_sim(vector<vector<int>> &vase_contents, int v, int p){
    // cout << "apply_sim(" << v << "," << p << ")" << endl;
    // cout << "? " << vase_contents.size() << " " << vase_contents[v].size() << endl;
    // cout << vase_contents[v].size() << " vase_contents[" << v << "]:";
    // for(auto x :vase_contents[v]){
    //     cout << x << " ";
    // }
    // cout << endl;
    if(p != 0){
        vase_contents[v].push_back(p);
    }
    if(sim_day != 100){
        int rand_vase = (rand()%20) + 1;
        vase_contents[rand_vase].push_back(sim_day);
    }
}

int sim_get_size(vector<vector<int>> &vase_contents, int v){
    return vase_contents[v].size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    int wins=0;
    for(int t=1;t<=T;t++){
        vector<double> guess(21, 0);
        vector<int> self_count(21, 0);
        vector<int> hundo_count(21, 0);
        
        sim_day = 0; // SIM
        vector<vector<int>> vase_contents(21); // SIM
        for(int x = 1; x <= 100; x++){
            // int day; cin >> day;
            int day = get_sim_day();
            // if(day == -1) return -1;

            int vase; int p;
            const int DAY_X = 50;
            const int DAY_Y = 80;
            if(day <= DAY_X){
                vase = 1 + ((day-1)%10); // destroy 1-10
                p = 100 - self_count[vase];
            }
            else if(day >= DAY_X + 1 && day <= DAY_X + 10){
                // examine all
                vase = 10+day-DAY_X;
                p = 0;
            }
            else if(day >= DAY_Y + 1 && day <= DAY_Y + 10){ // double check 11-20
                // examine all
                vase = 10+day-DAY_Y;
                p = 0;
            }
            else {
                vector<int> z(20);
                iota(z.begin(), z.end(), 1);
                sort(z.begin(), z.end(), [&guess](int i,int j){return guess[i] < guess[j];});
                
                int target_vase_index=0;
                while(hundo_count[z[target_vase_index]] > 1)
                    target_vase_index++;
                int target_vase = z[target_vase_index];
                int threat_vase = target_vase_index == 0 ? z[1] : z[0];
                
                if(day == 100 && hundo_count[target_vase] == 0){
                    vase = target_vase;
                    p = 100;
                }
                else {
                    vase = threat_vase;
                    p = 100;
                }
            }
             
            cout << vase << " " << p << endl;
            apply_sim(vase_contents, vase, p);

            if(p == 0){
                // int N; cin >> N;
                // for(int i=0;i<N;i++){ int y; cin >> y; }
                int N = sim_get_size(vase_contents, vase);

                guess[vase] = N;
            }
            else {
                guess[vase] += 1;
                self_count[vase] += 1;
                if(p == 100)
                    hundo_count[vase] += 1;
            }

            if(day != 100){
                for(int v=1;v<=20;v++){
                    guess[v] += 1.0/20;
                }
            }
        }

        // show contents:
        int total=0;
        for(int v=1;v<=20;v++){
            cout << v << "(" << vase_contents[v].size() << ")" << "\t" << guess[v] << endl;
            total += vase_contents[v].size();
        }
        cout << total << endl;

        vector<int> z(20);
        iota(z.begin(), z.end(), 1);
        sort(z.begin(), z.end(), [&vase_contents](int i,int j){return vase_contents[i].size() < vase_contents[j].size();});
        bool win =false;
        if(vase_contents[z[0]].size() < vase_contents[z[1]].size()){
            cout << "uniq winner:" << endl;
            cout <<"contents: ";
            int num_100=0;
            for(auto x : vase_contents[z[0]]){
                if(x==100)
                    num_100++;
                cout << x << " ";
            }
            cout << endl;
            if(num_100 == 1) win = true;
        }
        cout << "WIN:" << (win ? "YES" : "NO" )<< endl;
        if(win) wins++;
    }
    cout << wins << " wins out " << T << endl;

    return 0;
}