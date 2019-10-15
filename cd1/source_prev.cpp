
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

const vector<pair<int,int>> d = {{0,1}, {-1,0}, {0,-1}, {1,0}};

int main() {
    int N, M;
    cin >> M >> N; cin.ignore();
    cerr << M << " " << N << endl;
    vector<string> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i]; cin.ignore();
        cerr << m[i] << endl;
    }
    string side;
    cin >> side; cin.ignore();
    cerr << side << endl;
    bool follow_left = (side == "L");

    int start_i,start_j;
    int start_dir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(m[i][j] != '0' && m[i][j] != '#'){
                if(m[i][j] == '>') start_dir = 0;
                if(m[i][j] == '^') start_dir = 1;
                if(m[i][j] == '<') start_dir = 2;
                if(m[i][j] == 'v') start_dir = 3;
                m[i][j] = '0';
                start_i = i;
                start_j = j;
                cerr << "start " << start_j << "," << start_i << endl;
            }
        }
    }
    
    
    vector<vector<int>> count(N, vector<int>(M, 0));
    int cur_i = start_i;
    int cur_j = start_j;
    int dir = start_dir;
    
    int t=0;
    bool moved = false;
    do {
        // look forward, else turn
        auto [di, dj] = d[dir];
        int ni = cur_i + di; 
        int nj = cur_j + dj;
        // mobius
        bool mob = false;
        if(nj == M) {
            nj = 0; //ni = (N-1) - ni;
            mob = true;
        }
        if(nj == -1) {
            nj = M-1; //ni = (N-1) - ni;
            mob = true;
        }
        if(ni == N){
            ni = 0; nj = (nj + M/2) % M;
        }
        if(ni == -1){
            ni = N-1; nj = (nj + M/2) % M;
        }


        if(ni >= 0 && ni < N && nj >=0 && nj < M && m[ni][nj] == '0'){
            cur_i=ni;
            cur_j=nj;
            moved = true;
            dir = (dir + (follow_left ? 1 : 3)) % 4;
            if(mob){                
                // cerr << "MOB STEP" << endl;
                // follow_left = !follow_left;
            }
            count[ni][nj]++;
            
        }
        else {
            dir = (dir + (follow_left ? 3 : 1)) % 4;
            // cerr << "rot" << dir << endl;
        }
        // cerr << cur_j << "," << cur_i << "\t" << dir << endl;
        
    } while(!(cur_i == start_i && cur_j == start_j && (dir == start_dir || moved)));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(m[i][j] == '#')
                cout << '#';
            else
                cout << count[i][j];                
        }
        cout << endl;
    }
}